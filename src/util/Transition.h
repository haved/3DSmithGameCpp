#pragma once

#include <glm/glm.hpp>
#include "../IView.h"

class Transition
{
public:

	Transition(){}
	~Transition(){}
	void SetStart(IView* prevView)
	{
		m_prevEye = prevView->GetEyePos();
		m_prevTarget = prevView->GetEyeTarget();
		m_prevUp = prevView->GetEyeUp();
		SetTransition(0);
	}
	void SetTransition(float transition)
	{
		m_transition = transition;
		m_smothTransition = glm::pow(-glm::cos(transition*3.1415f) / 2 + 0.5f, 1.4f);
	}
	void UpdateTransition(float speed)
	{
		if (m_transition < 1.0f)
		{
			m_transition += speed;
			SetTransition(glm::min(1.0f, m_transition));
		}
	}
	bool IsDone()
	{
		return m_transition >= 1.0f;
	}
	glm::vec3 GetEyePos(glm::vec3& newEyePos)
	{
		return m_smothTransition < 1.0f ? (newEyePos * m_smothTransition + m_prevEye * (1 - m_smothTransition)) : newEyePos;
	}
	glm::vec3 GetEyeTarget(glm::vec3& newEyeTagret)
	{
		return m_smothTransition < 1.0f ? (newEyeTagret * m_smothTransition + m_prevTarget * (1 - m_smothTransition)) : newEyeTagret;
	}
	glm::vec3 GetEyeUp(glm::vec3& newEyeUp)
	{
		return m_smothTransition < 1.0f ? (newEyeUp * m_smothTransition + m_prevUp * (1 - m_smothTransition)) : newEyeUp;
	}
private:
	glm::vec3 m_prevEye, m_prevTarget, m_prevUp;
	float m_transition = 1;
	float m_smothTransition = 1;
};

