#pragma once

#include "../entity/Entity.h"
#include <glm/glm.hpp>
#include <memory>
#include <SFML/Graphics/Texture.hpp>
#include "Mesh.h"

class TextureFloor : public Entity
{
public:
	TextureFloor(std::shared_ptr<sf::Texture> texture, glm::vec2& sampleSize, float width, float length, float yPos);
	~TextureFloor();
	void Update(Scene* scene) {}
	void Render(Scene* scene, glm::mat4& VP);

	void* operator new(size_t size){ return _aligned_malloc(size, 16); };
	void operator delete(void* p) { _aligned_free(p); };

private:
	std::shared_ptr<sf::Texture> m_texture;
	glm::vec2 m_sampleSize;
	glm::vec4 m_color;
};

