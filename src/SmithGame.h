#pragma once

#include <glm\glm.hpp>
#include <memory>
#include "rendering/BasicShader.h"
#include "rendering/ColorShader.h"
#include "rendering/TextureShader.h"
#include "rendering/OrthoRenderingEngine.h"
#include "util/Localization.h"
#include <SFML/Graphics/Font.hpp>
#include "TextureCollection.h"
#include "GameInfo.h"

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
	void SetView(IView* view);
	Scene* CurrentScene;
	std::shared_ptr<IView> CurrentView;
	std::unique_ptr<GameInfo> CurrentGameInfo;
	PlayerEntity* Player;
	Scene* GetMenuScene();
	Scene* GetSmithingScene();
	void DeleteSmithingScene();
	void DeleteMenuScene();
private:
	glm::mat4 m_projection;
	Scene* m_menuScene = 0;
	Scene* m_gameScene = 0;
	std::unique_ptr<OrthoRenderingEngine> m_orthoRender;
	std::unique_ptr<BasicShader> m_basicShaderInstance;
	std::unique_ptr<ColorShader> m_colorShaderInstance;
	std::unique_ptr<TextureCollection> m_textureCollection;
	std::unique_ptr<TextureShader> m_textureShaderInstance;
	std::unique_ptr<sf::Font> m_defaultFont;
	std::unique_ptr<Localization> m_currentLanguage;
};

