#pragma once

#include <glm/glm.hpp>

class UtilFields
{
public:
	glm::vec3 ZERO3 = glm::vec3(0.0f,0.0f,0.0f);
	glm::vec3 UnitX = glm::vec3(1.0f, 0.0f, 0.0f);
	glm::vec3 UnitY = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 UnitZ = glm::vec3(0.0f, 0.0f, 1.0f);
	glm::vec4 ZERO4 =  glm::vec4(0.0f, 0.0f, 0.0f, 0.0f);
	glm::vec4 WHITE = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	glm::vec4 BLACK = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
};

extern UtilFields uFields;