#include "MainMenuView.h"
#include "GlobalFields.h"
#include "util/Input.h"
#include "SmithGame.h"

#include <iostream>
#include <vector>
#include <string>

MainMenuView::MainMenuView(SmithGame* game)
{
	std::cout << "MainMenuView()" << std::endl;
	m_game = game;
	m_bar = new MenuBar();
	UpdateScene = false;
	RenderScene = true;
}

MainMenuView::~MainMenuView()
{
	std::cout << "~MainMenuView()" << std::endl;
	delete m_bar;
}

void MainMenuView::OnViewUsed()
{
	std::vector<std::string> buttons;
	buttons.push_back("ui.button.newgame");
	buttons.push_back("ui.button.exit");
	m_bar->SetButtons(buttons);
}

void MainMenuView::OnViewNotUsed()
{
	m_bar->RemoveButtons();
}

void MainMenuView::UpdateView()
{
	m_bar->Update();
	if (InputState.MousePressed)
		m_game->NewGame();
}

glm::vec4 MAINMENU_gradient(0, 0, 0, 0.7f);
void MainMenuView::RenderView(glm::mat4& VP)
{
	Global.OrthoRenderingEngine->FillScreenWithColor(MAINMENU_gradient);
	m_bar->Render();
}