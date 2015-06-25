#pragma once

#include "Entity.h"
#include <memory>
#include "../rendering/Mesh.h"
#include <glm/glm.hpp>

class PlayerEntity : public Entity
{
public:
	PlayerEntity(float x, float y, std::shared_ptr<Mesh> mesh, std::shared_ptr<Mesh> shadow, glm::vec4& shadowColor, float xSize, float ySize);
	~PlayerEntity();
	void Update(Scene* scene);
	void Render(Scene* scene, glm::mat4& VP);
	void* operator new(size_t size)
	{
		return _aligned_malloc(size, 16);
	};
	void operator delete(void* pointer)
	{
		_aligned_free(pointer);
	};
private:
	std::shared_ptr<Mesh> m_mesh;
	std::shared_ptr<Mesh> m_shadow;
	glm::vec4 m_shadowColor;
	glm::vec2 speed;
};

