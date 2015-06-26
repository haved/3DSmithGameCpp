#pragma once

#include "IView.h"
#include <glm/glm.hpp>
#include "rendering/MenuBar.h"

class SmithGame;

class MainMenuView : public IView
{
public:
	MainMenuView(SmithGame* game);
	~MainMenuView();
	void UpdateView();
	void RenderView(glm::mat4& VP);
	void PreViewUsed(std::shared_ptr<IView> prevView){}
	void OnViewUsed();
	glm::vec3 GetEyePos() { return m_eye; }
	glm::vec3 GetEyeTarget(){ return m_target; }
	glm::vec3 GetEyeUp(){ return m_up; }
private:
	SmithGame* m_game;
	MenuBar* m_bar = 0;
	glm::vec3 m_eye = glm::vec3(1, -3, 6);
	glm::vec3 m_target = glm::vec3(1, 7, 0);
	glm::vec3 m_up = glm::vec3(0, 1, 0);
};

