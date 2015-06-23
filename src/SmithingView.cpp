#include "SmithingView.h"
#include "SmithGame.h"

SmithingView::SmithingView(SmithGame* game)
{
	SmithingView::m_game = game;
	IView::UpdateScene = false;
	IView::RenderScene = true;
}

SmithingView::~SmithingView(){}

glm::vec3 SmithingView::GetEyePos()
{
	return glm::vec3(0, 0, 40);
}

glm::vec3 SmithingView::GetEyeTarget()
{
	return glm::vec3(0, 0, 0);
}

glm::vec3 UP = glm::vec3(0, 1, 0);
glm::vec3 SmithingView::GetEyeUp()
{
	return UP;
}

void SmithingView::UpdateView()
{

}

void SmithingView::RenderView(glm::mat4& VP)
{

}
