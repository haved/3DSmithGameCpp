#include "SmithingView.h"
#include "SmithGame.h"
#include "entity/PlayerEntity.h"
#include "util/Input.h"
#include <memory>
#include "PauseView.h"

#include <iostream>

SmithingView::SmithingView(SmithGame* game)
{
	std::cout << "SmithingView()" << std::endl;
	m_game = game;
	UpdateScene = true;
	RenderScene = true;
}

SmithingView::~SmithingView()
{
	std::cout << "~SmithingView()" << std::endl;
}

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
	if (InputState.ExitPressed)
		m_game->SetView(std::make_shared<PauseView>(m_game));
}

void SmithingView::RenderView(glm::mat4& VP)
{

}
