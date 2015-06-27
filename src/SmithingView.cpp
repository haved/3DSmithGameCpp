#include "SmithingView.h"
#include "SmithGame.h"
#include "entity/PlayerEntity.h"
#include "GlobalFields.h"
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

void SmithingView::OnViewChanging(std::shared_ptr<IView> prevView)
{
	if (prevView.get() != 0)
		m_transition.SetStart(prevView.get());
}

glm::vec3 SmithingView::GetEyePos()
{
	return m_transition.GetEyePos(glm::vec3(m_game->Player->pos.x, m_game->Player->pos.y - 10, 40));
}

glm::vec3 SmithingView::GetEyeTarget()
{
	return m_transition.GetEyeTarget(glm::vec3(m_game->Player->pos.x, m_game->Player->pos.y, 1.73f));
}

glm::vec3 UP = glm::vec3(0, 1, 0);
glm::vec3 SmithingView::GetEyeUp()
{
	return m_transition.GetEyeUp(UP);
}

void SmithingView::UpdateView()
{
	m_transition.UpdateTransition(Global.DeltaTime * 2);

	if (InputState.ExitPressed)
		m_game->SetView(std::make_shared<PauseView>(m_game));
}

void SmithingView::RenderView(glm::mat4& VP)
{

}
