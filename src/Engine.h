#pragma once

#include <SFML/Window.hpp>
#include <string>

class SmithGame;

class Engine
{
public:
	Engine(int width, int height, const std::string& name);
	~Engine();
	void Run(SmithGame* game);
protected:
	sf::Window* m_window;
};