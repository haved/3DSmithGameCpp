#pragma once

#include <glm/glm.hpp>
#include "InteractiveEntity.h"

class Scene;

class Entity
{
public:
	Entity();
	virtual ~Entity();
	virtual void Update(Scene* scene) = 0;
	virtual void Render(Scene* scene, glm::mat4& VP) = 0;
	glm::vec3 pos = glm::vec3(0, 0, 0);
	glm::vec3 rot = glm::vec3(0, 0, 0);
protected:
	glm::mat4 modelspace = glm::mat4();
	void UpdateModelspace();
	void MoveAsSolid(Scene* scene, float xMove, float yMove);
public:
	bool isSolid(){ return solid; };
	float GetX1(){ return pos.x - solidXSize; }
	float GetX2(){ return pos.x + solidXSize; }
	float GetY1(){ return pos.y - solidYSize; }
	float GetY2(){ return pos.y + solidYSize; }
	InteractiveEntity* interactive = 0;
protected:
	bool solid=false;
	float solidXSize=0;
	float solidYSize=0;
};

