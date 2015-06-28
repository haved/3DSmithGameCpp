#pragma once

#include "Mesh.h"
#include <glm/glm.hpp>
#include <SFML/Graphics/Texture.hpp>

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
	void DrawColoredTexture(sf::Texture texture, glm::vec4& color, float x, float y, float width, float height);
	void DrawFlippedColoredTexture(sf::Texture texture, glm::vec4& color, float x, float y, float width, float height);
	void DrawColoredTexturePart(sf::Texture texture, glm::vec4& color, float x, float y, float width, float height, glm::vec2& UV, glm::vec2& sampleSize);

	void* operator new(size_t size) { return _aligned_malloc(size, 16); };
	void operator delete(void* p) { _aligned_free(p); };

	Mesh* m_flat;
private:
	float m_orthoWidth;
	float m_orthoHeight;
	glm::mat4 m_orthoProjection;
	glm::mat4 m_allScreen;
};

