#include "SmithingView.h"
#include "SmithGame.h"
#include "entity/PlayerEntity.h"

SmithingView::SmithingView(SmithGame* game)
{
	m_game = game;
	UpdateScene = true;
	RenderScene = true;
}

SmithingView::~SmithingView(){}

glm::vec3 SmithingView::GetEyePos()
{
	return glm::vec3(m_game->Player->pos.x, m_game->Player->pos.y - 10, 40);
}

glm::vec3 SmithingView::GetEyeTarget()
{
	return glm::vec3(m_game->Player->pos.x, m_game->Player->pos.y, 1.73f);
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
