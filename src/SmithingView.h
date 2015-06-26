#pragma once

#include "IView.h"

class SmithGame;

class SmithingView : public IView
{
public:
	SmithGame* m_game;
	SmithingView(SmithGame* game);
	~SmithingView();
	glm::vec3 GetEyePos();
	glm::vec3 GetEyeTarget();
	glm::vec3 GetEyeUp();
	void UpdateView();
	void RenderView(glm::mat4& VP);
	void PreViewUsed(std::shared_ptr<IView> prevView){}
	void OnViewUsed(){}
};

