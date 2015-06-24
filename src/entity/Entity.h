#pragma once

#include <glm/glm.hpp>

class Scene;

class Entity
{
public:
	Entity();
	virtual ~Entity();
	virtual void Update(Scene* scene) = 0;
	virtual void Render(Scene* scene, glm::mat4& VP) = 0;
	glm::vec3 pos;
	glm::vec3 rot;
protected:
	glm::mat4 modelspace;
	void UpdateModelspace();
};

