#include "Scene.h"
#include "rendering/BasicShader.h"
#include <GL/glew.h>
#include <iostream>

Scene::Scene()
{
	Vertex vertices[4] = { Vertex(-15, -10, 0), Vertex(15, -10, 0),
		Vertex(15, 10, 0), Vertex(-15, 10, 0) };
	uint32_t indices[6] = { 0, 1, 2, 0, 2, 3 };
	m = new Mesh(vertices, 4, indices, 6);
}

Scene::~Scene()
{
	delete m;
}

void Scene::Update()
{

}

extern BasicShader* BasicShaderInstance;

void Scene::Render(glm::mat4& VP)
{
	BasicShaderInstance->Bind();
	BasicShaderInstance->SetMVP(VP);
	BasicShaderInstance->ResetColor();
	m->Draw();
}