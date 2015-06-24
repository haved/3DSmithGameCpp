#include "Engine.h"
#include "SmithGame.h"
#include "rendering/Mesh.h"
#include "GlobalFields.h"

#include <iostream>
#include <GL/glew.h>

Engine::Engine(int width, int height, const std::string& name)
{
	std::cout << "Engine()" << std::endl;

	sf::ContextSettings settings;
	settings.depthBits = 24;
	settings.stencilBits = 8;
	settings.antialiasingLevel = 8;
	settings.majorVersion = 3;
	settings.minorVersion = 0;

	m_window = new sf::Window(sf::VideoMode(width, height), name, sf::Style::Default, settings);
	m_window->setVerticalSyncEnabled(true);
	if (glewInit() != GLEW_OK)
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

	glClearColor(0, 0.5f, 1, 1);

	sf::Clock clock;

	bool running = true;
	while (running)
	{
		DeltaTime = clock.restart().asSeconds();
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
		CountFPS();
	}
}

void Engine::CountFPS()
{
	frames++;
	timePassed += DeltaTime;
	if (timePassed > 2)
	{
		std::cout << "FPS: " << frames / timePassed * 2 << std::endl;
		timePassed = 0;
		frames = 0;
	}
}