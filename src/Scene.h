#pragma once

#include <glm/glm.hpp>
#include "rendering/Mesh.h"

class Scene
{
public:
	Scene();
	~Scene();
	void Update();
	void Render(glm::mat4& VP);
	Mesh* m;
	Mesh* m2;
};

