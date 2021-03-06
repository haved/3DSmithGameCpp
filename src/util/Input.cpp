#include "Input.h"
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "../GlobalFields.h"
#include <SFML/Window/Window.hpp>

Input InputState;

sf::Keyboard::Key UP_KEY = sf::Keyboard::W;
sf::Keyboard::Key DOWN_KEY = sf::Keyboard::S;
sf::Keyboard::Key LEFT_KEY = sf::Keyboard::A;
sf::Keyboard::Key RIGHT_KEY = sf::Keyboard::D;
sf::Keyboard::Key EXIT_KEY = sf::Keyboard::Escape;
sf::Keyboard::Key INTERACT_KEY = sf::Keyboard::E;

void Input::Update()
{
	if (!Global.UsedWindow->hasFocus())
		return;
	sf::Vector2i pos = sf::Mouse::getPosition(*Global.UsedWindow);
	OrthoMouseX = (float)pos.x;
	OrthoMouseY = (float)pos.y;
	RelativeMouseX = ((float)pos.x / Global.UsedWindow->getSize().x * 2 - 1);
	RelativeMouseY = ((float)pos.y / Global.UsedWindow->getSize().y * 2 - 1);
	UpKeyDown = sf::Keyboard::isKeyPressed(UP_KEY);
	DownKeyDown = sf::Keyboard::isKeyPressed(DOWN_KEY);
	LeftKeyDown = sf::Keyboard::isKeyPressed(LEFT_KEY);
	RightKeyDown = sf::Keyboard::isKeyPressed(RIGHT_KEY);
	MousePressed = sf::Mouse::isButtonPressed(sf::Mouse::Left)&&(!m_prevMousePressed&(RelativeMouseX>-1)&(RelativeMouseX<1)&(RelativeMouseY>-1)&(RelativeMouseY<1));
	m_prevMousePressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);
	ExitPressed = sf::Keyboard::isKeyPressed(EXIT_KEY) & !m_prevExitPressed;
	m_prevExitPressed = sf::Keyboard::isKeyPressed(EXIT_KEY);
	InteractPressed = sf::Keyboard::isKeyPressed(INTERACT_KEY) & !m_prevInteractPressed;
	m_prevInteractPressed = sf::Keyboard::isKeyPressed(INTERACT_KEY);
}
