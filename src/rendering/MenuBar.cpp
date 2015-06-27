#include "MenuBar.h"
#include "../GlobalFields.h"
#include "../util/Localization.h"

#include <iostream>

#define MENUBAR_barXPos 100
#define MENUBAR_barWidth 240
#define MENUBAR_optionHeight 40
#define MENUBAR_topOption 500

MenuBar::MenuBar(std::vector<std::string>& buttons)
{
	//m_buttons = buttons;
	m_buttonCount = buttons.size();
	m_textures = new sf::RenderTexture*[m_buttonCount];
	sf::Text text;
	text.setFont(*Global.DefaultFont);
	text.setCharacterSize(24);
	text.setColor(sf::Color::White);
	for (unsigned int i = 0; i < m_buttonCount; i++)
	{
		m_textures[i] = new sf::RenderTexture();
		m_textures[i]->create(MENUBAR_barWidth, MENUBAR_optionHeight);
		m_textures[i]->setSmooth(true);
		text.setString(CurrentLanguage->m_map[buttons[i]]);
		text.setPosition((MENUBAR_barWidth-text.getLocalBounds().width)/2, 0);
		m_textures[i]->draw(text);
	}
}

MenuBar::~MenuBar()
{
	for (unsigned int i = 0; i < m_buttonCount; i++)
	{
		delete m_textures[i];
	}
	delete m_textures;
}

void MenuBar::Update()
{

}

void MenuBar::Render()
{
	Global.OrthoRenderingEngine->FillColoredRectangle(glm::vec4(0, 0, 0, 1), MENUBAR_barXPos, 0, MENUBAR_barWidth, Global.OrthoRenderingEngine->GetOrthoHeight());
	for (unsigned int i = 0; i < m_buttonCount; i++)
	{
		Global.OrthoRenderingEngine->DrawFlippedColoredTexture(m_textures[i]->getTexture(), glm::vec4(1,1,1,0.6f), MENUBAR_barXPos, MENUBAR_topOption-(MENUBAR_optionHeight*(float)i), MENUBAR_barWidth, MENUBAR_optionHeight);
	}
}