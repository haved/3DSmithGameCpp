#pragma once

#include <glm/glm.hpp>
#include <memory>

class IView
{
public:
	bool UpdateScene=true;
	bool RenderScene=true;
	virtual glm::vec3 GetEyePos()=0;
	virtual glm::vec3 GetEyeTarget()=0;
	virtual glm::vec3 GetEyeUp()=0;
	virtual void UpdateView()=0;
	virtual void RenderView(glm::mat4& VP)=0;
	virtual void OnViewUsed(std::shared_ptr<IView> prevView)=0;
};

