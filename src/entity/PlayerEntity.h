#pragma once

#include "Entity.h"
#include <memory>
#include "../rendering/Mesh.h"

class PlayerEntity : public Entity
{
public:
	PlayerEntity(float x, float y, std::shared_ptr<Mesh> mesh);
	~PlayerEntity();
	void Update(Scene* scene);
	void Render(Scene* scene, glm::mat4& VP);
private:
	std::shared_ptr<Mesh> m_mesh;
};

