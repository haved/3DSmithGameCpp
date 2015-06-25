#include "OrthoRenderingEngine.h"
#include <glm/gtc/matrix_transform.hpp>
#include "../GlobalFields.h"

OrthoRenderingEngine::OrthoRenderingEngine()
{
	Vertex vertices[4] = { Vertex(0, 0, 0, 0, 1, 0, 1, 1, 1),
		Vertex(1, 0, 0, 1, 1, 0, 1, 1, 1),
		Vertex(1, 1, 0, 1, 0, 0, 1, 1, 1),
		Vertex(0, 1, 0, 0, 0, 0, 1, 1, 1) };
	GLuint indices[6] = { 0, 1, 2, 0, 2, 3 };

	m_allScreen = glm::translate(m_allScreen, glm::vec3(-1, -1, 0));
	m_allScreen = glm::scale(m_allScreen, glm::vec3(2, 2, 1));

	m_flat = new Mesh(vertices, 4, indices, 6);
	Global.OrthoRenderingEngine = this;
}


OrthoRenderingEngine::~OrthoRenderingEngine()
{
	delete m_flat;
}

void OrthoRenderingEngine::OnResize(int width, int height)
{
	m_orthoWidth = (float)width;
	m_orthoHeight = (float)height;
	m_orthoProjection = glm::ortho(0, width, 0, height);
}


void OrthoRenderingEngine::FillScreenWithColor(glm::vec4& color)
{
	Global.ColorShaderInstance->Bind();
	Global.ColorShaderInstance->SetColor(color);
	Global.ColorShaderInstance->SetMVP(m_allScreen);
	m_flat->Draw();
}

void OrthoRenderingEngine::FillColoredRectangle(glm::vec4& color, float x, float y, float width, float height)
{
	Global.ColorShaderInstance->Bind();
	Global.ColorShaderInstance->SetColor(color);
	glm::mat4 m;
	m = glm::translate(m, glm::vec3(x / m_orthoWidth * 2 - 1, y / m_orthoHeight * 2 - 1, 0));
	m = glm::scale(m, glm::vec3(width/m_orthoWidth*2, height/m_orthoHeight*2, 1));
	Global.ColorShaderInstance->SetMVP(m);
	m_flat->Draw();
}