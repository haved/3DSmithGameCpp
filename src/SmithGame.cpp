#include "SmithGame.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Engine.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Scene.h"
#include "SmithingView.h"

SmithGame::SmithGame() {}

void SmithGame::Init()
{
	std::cout << "SmithGame.Init()" << std::endl;
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);

	gameScene = new Scene();
	menuScene = new Scene();
	CurrentScene = gameScene;
	CurrentView = std::make_shared<SmithingView>(this);
	basicShaderInstance = std::make_unique<BasicShader>();
}

SmithGame::~SmithGame()
{
	std::cout << "~SmithGame()" << std::endl;
	delete gameScene;
	delete menuScene;
}

void SmithGame::Resize(int width, int height)
{
	glViewport(0, 0, width, height);
	SmithGame::projection = glm::perspective(3.1415f / 180 * 40, (float)width / height, 0.1f, 60.0f);
}

void SmithGame::Update()
{
	if (CurrentView->UpdateScene)
	{
		CurrentScene->Update();
	}
	CurrentView->UpdateView();
}

glm::mat4 VP;
void SmithGame::Render()
{
	VP = projection * glm::lookAt(CurrentView->GetEyePos(), CurrentView->GetEyeTarget(), CurrentView->GetEyeUp());
	if (CurrentView->RenderScene)
	{
		basicShaderInstance->Bind();
		basicShaderInstance->SetMVP(VP);
		CurrentScene->Render(VP);
	}
	CurrentView->RenderView(VP);
}

int main()
{
	Engine engine(1600, 900, "Smith Game 3D");
	{
		SmithGame game;
		engine.Run(&game);
	}
}