#pragma once

#include <glm\glm.hpp>
#include <memory>
#include "rendering/BasicShader.h"
#include "rendering/ColorShader.h"
#include "rendering/TextureShader.h"
#include "rendering/OrthoRenderingEngine.h"
#include <SFML/Graphics/Font.hpp>

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
	void NewGame();
	void SetView(std::shared_ptr<IView> newView);
	Scene* CurrentScene;
	std::shared_ptr<IView> CurrentView;
	PlayerEntity* Player;
	Scene* GetMenuScene();
	Scene* GetSmithingScene();
	void DeleteSmithingScene();
	void DeleteMenuScene();
private:
	glm::mat4 m_projection;
	Scene* m_menuScene = 0;
	Scene* m_gameScene = 0;
	OrthoRenderingEngine* m_orthoRender;
	BasicShader* m_basicShaderInstance;
	ColorShader* m_colorShaderInstance;
	TextureShader* m_textureShaderInstance;
	sf::Font* m_defaultFont;
};

