#include "PauseView.h"
#include "MainMenuView.h"
#include "GlobalFields.h"
#include "util/Input.h"

#include <iostream>
#include <vector>
#include <string>

PauseView::PauseView(SmithGame* game)
{
	m_game = game;
	m_bar = new MenuBar();
	UpdateScene = false;
	RenderScene = true;
}

PauseView::~PauseView()
{
	delete m_bar;
	//m_bar = 0;
}

void PauseView::OnViewUsed()
{
	std::vector<std::string> buttons;
	buttons.push_back("Back to main menu");
	buttons.push_back("Exit");
	m_bar->SetButtons(buttons);
}

void PauseView::OnViewNotUsed()
{
	m_bar->RemoveButtons();
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
