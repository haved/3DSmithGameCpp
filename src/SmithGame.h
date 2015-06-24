#pragma once

#include <glm\glm.hpp>
#include <memory>
#include "rendering/BasicShader.h"

class Scene;
class IView;
class PlayerEntity;

class SmithGame
{
public:
	SmithGame();
	virtual ~SmithGame();
	void Init();
	void Resize(int width, int height);
	void Update();
	void Render();
	Scene* CurrentScene;
	std::shared_ptr<IView> CurrentView;
	PlayerEntity* Player;
	Scene* GetMenuScene();
	Scene* GetGameScene();
private:
	glm::mat4 m_projection;
	Scene* m_menuScene = 0;
	Scene* m_gameScene = 0;
	std::unique_ptr<BasicShader> m_basicShaderInstance;
};

