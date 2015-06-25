#include "MainMenuView.h"
#include "GlobalFields.h"
#include "util/Input.h"
#include "SmithGame.h"

MainMenuView::MainMenuView(SmithGame* game)
{
	m_game = game;
	m_bar = new MenuBar();
	UpdateScene = false;
	RenderScene = true;
}

MainMenuView::~MainMenuView()
{
	delete m_bar;
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