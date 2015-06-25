#include "MainMenuView.h"
#include "GlobalFields.h"

MainMenuView::MainMenuView(SmithGame* game)
{
	m_game = game;
	UpdateScene = false;
	RenderScene = true;
}

MainMenuView::~MainMenuView()
{

}

void MainMenuView::UpdateView()
{

}

glm::vec4 color(0, 0, 0, 0.7f);
float barXPos = 100;
float barWidth = 240;
//float optionHeight = 40;
void MainMenuView::RenderView(glm::mat4& VP)
{
	Global.OrthoRenderingEngine->FillScreenWithColor(color);
	Global.OrthoRenderingEngine->FillColoredRectangle(glm::vec4(0, 0, 0, 1), barXPos, 0, barWidth, Global.OrthoRenderingEngine->GetOrthoHeight());
}