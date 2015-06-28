#pragma once

#include <string>
#include <SFML/Graphics/Texture.hpp>

class TextureCollection
{
public:
	sf::Texture Box;

	TextureCollection(const std::string& texturePath);
};