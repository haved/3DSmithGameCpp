#pragma once

#include <glm\glm.hpp>
#include <memory>
#include "rendering/BasicShader.h"

class Scene;
class IView;

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
private:
	glm::mat4 projection;
	Scene* menuScene;
	Scene* gameScene;
	std::unique_ptr<BasicShader> basicShaderInstance;
};

