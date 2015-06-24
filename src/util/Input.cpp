#include "Input.h"
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "../GlobalFields.h"

Input InputState;

sf::Keyboard::Key UP_KEY = sf::Keyboard::W;
sf::Keyboard::Key DOWN_KEY = sf::Keyboard::S;
sf::Keyboard::Key LEFT_KEY = sf::Keyboard::A;
sf::Keyboard::Key RIGHT_KEY = sf::Keyboard::D;

void Input::Update()
{
	sf::Vector2i pos = sf::Mouse::getPosition(*Global.UsedWindow);
	OrthoMouseX = (float)pos.x;
	OrthoMouseY = (float)pos.y;
	RelativeMouseX = ((float)pos.x / Global.UsedWindow->getSize().x * 2 - 1);
	RelativeMouseY = ((float)pos.y / Global.UsedWindow->getSize().y * 2 - 1);
	UpKeyDown = sf::Keyboard::isKeyPressed(UP_KEY);
	DownKeyDown = sf::Keyboard::isKeyPressed(DOWN_KEY);
	LeftKeyDown = sf::Keyboard::isKeyPressed(LEFT_KEY);
	RightKeyDown = sf::Keyboard::isKeyPressed(RIGHT_KEY);
}
