#pragma once

#include "Mesh.h"
#include <glm/glm.hpp>

class OrthoRenderingEngine
{
public:
	OrthoRenderingEngine();
	~OrthoRenderingEngine();
	void OnResize(int width, int height);
	float GetOrthoWidth() { return m_orthoWidth; }
	float GetOrthoHeight() { return m_orthoHeight; }

	void FillScreenWithColor(glm::vec4& color);
	void FillColoredRectangle(glm::vec4& color, float x, float y, float width, float height);
private:
	Mesh* m_flat;
	float m_orthoWidth;
	float m_orthoHeight;
	glm::mat4 m_orthoProjection;
	glm::mat4 m_allScreen;
};
