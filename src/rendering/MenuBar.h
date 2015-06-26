#pragma once

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

class MenuBar
{
public:
	MenuBar(std::vector<std::string>& buttons);
	~MenuBar();
	void Update();
	void Render();
private:
	unsigned int m_buttonCount;
	sf::RenderTexture** m_textures;
};

