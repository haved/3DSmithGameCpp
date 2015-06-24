#include "Entity.h"
#include <glm/gtc/matrix_transform.hpp>
#include "../Scene.h"
#include <iostream>

Entity::Entity()
{
}

Entity::~Entity(){}

const glm::vec3 unitX(1, 0, 0);
const glm::vec3 unitY(0, 1, 0);
const glm::vec3 unitZ(0, 0, 1);
void Entity::UpdateModelspace()
{
	modelspace = glm::mat4();
	modelspace = glm::translate(modelspace, pos);
	if (rot.z != 0)
		modelspace = glm::rotate(modelspace, rot.z, unitZ);
	if (rot.y != 0)
		modelspace = glm::rotate(modelspace, rot.y, unitY);
	if (rot.x != 0)
		modelspace = glm::rotate(modelspace, rot.x, unitX);
}

void Entity::MoveAsSolid(Scene* scene, float xMove, float yMove)
{
	for (uint32_t i = 0; i < scene->entities.size(); i++)
	{
		if (scene->entities[i]->isSolid())
		{
			Entity* e = scene->entities[i].get();
			if (e == this)
				continue;

			if (((GetX1() + xMove) < e->GetX2()) & (GetX2() > e->GetX1()) & (GetY1() < e->GetY2()) & (GetY2() > e->GetY1()))
				xMove = e->GetX2() - GetX1() + 0.01f;
			if ((GetY1() + yMove < e->GetY2()) & (GetY2() > e->GetY1()) & (GetX1() < e->GetX2()) & (GetX2() > e->GetX1()))
				yMove = e->GetY2() - GetY1() + 0.01f;
			if ((GetX2() + xMove > e->GetX1()) & (GetX1() < e->GetX2()) & (GetY1() < e->GetY2()) & (GetY2() > e->GetY1()))
				xMove = e->GetX1() - GetX2() - 0.01f;
			if ((GetY2() + yMove > e->GetY1()) & (GetY1() < e->GetY2()) & (GetX1() < e->GetX2()) & (GetX2() > e->GetX1()))
				yMove = e->GetY1() - GetY2() - 0.01f;
		}
	}

	pos.x += xMove;
	pos.y += yMove;
	UpdateModelspace();
}