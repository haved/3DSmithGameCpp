#pragma once

#include <glm/glm.hpp>

class Scene
{
public:
	Scene();
	~Scene();
	void Update();
	void Render(glm::mat4& VP);
};

