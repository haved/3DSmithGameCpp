#include "SmithGame.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Engine.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Scene.h"
#include "SmithingView.h"
#include "entity/MeshEntity.h"
#include "entity/PlayerEntity.h"
#include "entity/BellowEntity.h"

#define PI 3.1415f
const std::string RES_PATH = "../SmithGame3D/res/";

SmithGame::SmithGame() {}

void SmithGame::Init()
{
	std::cout << "SmithGame.Init()" << std::endl;
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);

	m_menuScene = new Scene();
	CurrentScene = GetGameScene();
	delete m_gameScene;
	m_gameScene = 0;
	CurrentScene = GetGameScene();
	CurrentView = std::make_unique<SmithingView>(this);
	m_basicShaderInstance = std::make_unique<BasicShader>(RES_PATH + "shaders/");
	std::cout << "SmithGame.Init() Finished!" << std::endl;
}

SmithGame::~SmithGame()
{
	std::cout << "~SmithGame()" << std::endl;
	if (m_gameScene)
		delete m_gameScene;
	if (m_menuScene)
		delete m_menuScene;
}

Scene* SmithGame::GetGameScene()
{
	if (m_gameScene)
		return m_gameScene;
	m_gameScene = new Scene();

	m_gameScene->AddEntity(new MeshEntity(std::make_shared<Mesh>(RES_PATH + "mesh/floor.ply"), 0, 0, 0));
	m_gameScene->AddEntity(new MeshEntity(std::make_shared<Mesh>(RES_PATH + "mesh/hatchHole.ply"), -1, 0, 0));
	Player = new PlayerEntity(4, 0, std::make_shared<Mesh>(RES_PATH + "mesh/player.ply"), 4, 3);
	m_gameScene->AddEntity(Player);
	std::shared_ptr<Mesh> wall = std::make_shared<Mesh>(RES_PATH + "mesh/wall.ply");
	m_gameScene->AddEntity(new MeshEntity(wall, 0, 10, 0, -0.2f, 0, 0, 30, 1));
	m_gameScene->AddEntity(new MeshEntity(wall, 0, -10, 0, -0.2f, 0, PI, 30, 1));
	m_gameScene->AddEntity(new MeshEntity(wall, 15, 0, 0, -0.2f, 0, -PI / 2, 1, 20));
	m_gameScene->AddEntity(new MeshEntity(wall, -15, 0, 0, -0.2f, 0, PI / 2, 1, 20));
	m_gameScene->AddEntity(new MeshEntity(std::make_shared<Mesh>(RES_PATH + "mesh/anvil.ply"), -15+9, 8.7f, 0, 8, 3)); //The height is 3f
	m_gameScene->AddEntity(new MeshEntity(std::make_shared<Mesh>(RES_PATH + "mesh/coalStripTable.ply"), -12, 6.5f, 0, 3, 6)); //The height is 3.5f
	m_gameScene->AddEntity(new MeshEntity(std::make_shared<Mesh>(RES_PATH + "mesh/castingTable.ply"), -11.5f, -1, 0, 6.25f, 3.3f));
	m_gameScene->AddEntity(new MeshEntity(std::make_shared<Mesh>(RES_PATH + "mesh/foundry.ply"), -11.5f, -6.5f, 0, 7, 7));
	m_gameScene->AddEntity(new BellowEntity(std::make_shared<Mesh>(RES_PATH + "mesh/bellow.ply"), -5, -8.5f, 0, glm::translate(glm::mat4(), glm::vec3(-3, 0, 1.28f)), 6, 3));
	m_gameScene->AddEntity(new MeshEntity(std::make_shared<Mesh>(RES_PATH + "mesh/coalTableSmall.ply"), 1, -8.5f, 0, 6, 3));
	m_gameScene->AddEntity(new MeshEntity(std::make_shared<Mesh>(RES_PATH + "mesh/table.ply"), 11.5f, -8, 0, 7, 4));
	m_gameScene->AddEntity(new MeshEntity(std::make_shared<Mesh>(RES_PATH + "mesh/mailboxBox.ply"), 12.5f, 9.5f, 2.4f, 3, 2));

	return m_gameScene;
}

void SmithGame::Resize(int width, int height)
{
	glViewport(0, 0, width, height);
	m_projection = glm::perspective(3.1415f / 180 * 40, (float)width / height, 0.1f, 50.0f);
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
	VP = m_projection * glm::lookAt(CurrentView->GetEyePos(), CurrentView->GetEyeTarget(), CurrentView->GetEyeUp());
	if (CurrentView->RenderScene)
	{
		CurrentScene->Render(VP);
	}
	CurrentView->RenderView(VP);
}

int main()
{
	{
		Engine engine(1600, 900, "Smith Game 3D"); //It really looks like a scope :D
		{
			SmithGame game;
			engine.Run(&game);
		}
	}

	std::string line;
	std::getline(std::cin, line);
}