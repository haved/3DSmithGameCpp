#include "Engine.h"
#include "SmithGame.h"

#include <iostream>
#include <GL/glew.h>

Engine::Engine(int width, int height, const std::string& name)
{
	std::cout << "Engine()" << std::endl;
	m_window = new sf::Window(sf::VideoMode(width, height), name);
	m_window->setVerticalSyncEnabled(true);
	if (glewInit() == GL_FALSE)
		std::cout << "Filed to initialize glew. This WILL end badly!" << std::endl;
}

Engine::~Engine()
{
	std::cout << "~Engine()" << std::endl;
	m_window->close();
}

void Engine::Run(SmithGame* game)
{
	std::cout << "Engine.Run()" << std::endl;
	game->Init();
	{
		sf::Vector2u size = m_window->getSize();
		game->Resize(size.x, size.y);
	}

	bool running = true;
	while (running)
	{
		sf::Event event;
		while (m_window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				running = false;
			}
			else if (event.type == sf::Event::Resized)
			{
				game->Resize(event.size.width, event.size.height);
			}
		}
		game->Update();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		game->Render();
		m_window->display();
	}
}