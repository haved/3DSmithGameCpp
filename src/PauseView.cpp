#include "PauseView.h"
#include "MainMenuView.h"
#include "GlobalFields.h"
#include "util/Input.h"

#include <iostream>

PauseView::PauseView(SmithGame* game)
{
	std::cout << "PauseView()" << std::endl;
	m_game = game;
	m_bar = new MenuBar();
	UpdateScene = false;
	RenderScene = true;
}

PauseView::~PauseView()
{
	std::cout << "~PauseView()" << std::endl;
	delete m_bar;
}

void PauseView::UpdateView()
{
	m_bar->Update();
	if (InputState.ExitPressed)
		m_game->SetView(m_prevView);
	else if (InputState.MousePressed)
	{
		m_game->DeleteSmithingScene();
		m_game->CurrentScene = m_game->GetMenuScene();
		m_game->SetView(std::make_shared<MainMenuView>(m_game));
	}
}

glm::vec4 PAUSEVIEW_gradient(0,0,0,0.7f);
void PauseView::RenderView(glm::mat4& VP)
{
	Global.OrthoRenderingEngine->FillScreenWithColor(PAUSEVIEW_gradient);
	m_bar->Render();
}
