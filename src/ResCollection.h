#pragma once

#include <string>
#include <memory>
#include "rendering/Mesh.h"
#include <SFML/Graphics/Texture.hpp>

class ResCollection
{
public:
	sf::Texture Box_t;
	std::unique_ptr<Mesh> Ingot_m;

	ResCollection(const std::string& texturePath, const std::string& meshPath);
};