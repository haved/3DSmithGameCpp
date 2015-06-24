#include "BasicShader.h"

BasicShader* BasicShaderInstance;

BasicShader::BasicShader()
{
	m_shader = new Shader("../SmithGame3D/res/shaders/BasicVS.glslvs", "../SmithGame3D/res/shaders/BasicFS.glslfs");
	modelspaceId = m_shader->GetUniformLocation("modelspaceMatrix");
	MVPId = m_shader->GetUniformLocation("MVP");
	colorId = m_shader->GetUniformLocation("color");
	BasicShaderInstance = this;
	SetModelspaceMatrix(glm::mat4());
}

BasicShader::~BasicShader()
{
	delete m_shader;
}

void BasicShader::SetModelspaceMatrix(glm::mat4& modelspace)
{
	glUniformMatrix4fv(modelspaceId, 1, GL_FALSE, &modelspace[0][0]);
}

void BasicShader::SetMVP(glm::mat4& MVP)
{
	glUniformMatrix4fv(MVPId, 1, GL_FALSE, &MVP[0][0]);
}

void BasicShader::SetColor(glm::vec4& color)
{
	glUniform4f(colorId, color.x, color.y, color.z, color.w);
}

void BasicShader::ResetColor()
{
	glUniform4f(colorId, 1, 1, 1, 1);
}

void BasicShader::Bind()
{
	glUseProgram(m_shader->ProgramID);
}
