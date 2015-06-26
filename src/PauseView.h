#pragma once

#include "SmithGame.h"
#include "rendering/MenuBar.h"
#include "IView.h"
#include <glm/glm.hpp>

class PauseView : public IView
{
public:
	PauseView(SmithGame* game);
	~PauseView();
	void UpdateView();
	void RenderView(glm::mat4& VP);
	void PreViewUsed(std::shared_ptr<IView> prevView) { m_prevView = prevView; }
	void OnViewUsed();
	glm::vec3 GetEyePos() { return m_prevView->GetEyePos(); }
	glm::vec3 GetEyeTarget(){ return m_prevView->GetEyeTarget(); }
	glm::vec3 GetEyeUp(){ return m_prevView->GetEyeUp(); }
private:
	SmithGame* m_game;
	MenuBar* m_bar = 0;
	std::shared_ptr<IView> m_prevView;
};

