#pragma once

#include <glm/glm.hpp>
#include "rendering/Mesh.h"
#include <vector>
#include <memory>
#include "entity/Entity.h"

class Scene
{
public:
	Scene();
	~Scene();
	void Update();
	void Render(glm::mat4& VP);
	std::vector<std::unique_ptr<Entity>> entities;
	void AddEntity(Entity* entity);
};

