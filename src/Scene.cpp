#include "Scene.h"
#include "rendering/BasicShader.h"
#include <GL/glew.h>
#include <iostream>

Scene::Scene()
{
	std::cout << "Scene()" << std::endl;
}

Scene::~Scene()
{
	std::cout << "~Scene()" << std::endl;
}

void Scene::AddEntity(Entity* entity)
{
	entities.push_back(std::unique_ptr<Entity>(entity));
}

void Scene::Update()
{
	for (uint32_t i = 0; i < entities.size(); i++)
	{
		if (entities[i].get())
			entities[i]->Update(this);
	}
}

void Scene::Render(glm::mat4& VP)
{
	for (uint32_t i = 0; i < entities.size(); i++)
	{
		if (entities[i].get())
			entities[i]->Render(this, VP);
	}
}