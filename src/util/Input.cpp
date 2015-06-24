#include "Input.h"
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "../GlobalFields.h"

Input InputState;

void Input::Update()
{
	sf::Vector2i pos = sf::Mouse::getPosition(*Global.UsedWindow);
	OrthoMouseX = (float)pos.x;
	OrthoMouseY = (float)pos.y;
	RelativeMouseX = ((float)pos.x / Global.UsedWindow->getSize().x * 2 - 1);
	RelativeMouseY = ((float)pos.y / Global.UsedWindow->getSize().y * 2 - 1);
}
