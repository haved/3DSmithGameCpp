#include "Entity.h"
#include <glm/gtc/matrix_transform.hpp>

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