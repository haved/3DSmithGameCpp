#pragma once

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

class MenuBar
{
public:
	MenuBar();
	~MenuBar();
	void SetButtons(std::vector<std::string>& buttons);
	void RemoveButtons();
	void Update();
	void Render();
private:
	unsigned int m_buttonCount;
	sf::RenderTexture** m_textures = 0;
};

