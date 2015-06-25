#pragma once
class Input
{
public:
	void Update();
	float OrthoMouseX;
	float OrthoMouseY;
	float RelativeMouseX;
	float RelativeMouseY;
	bool UpKeyDown;
	bool DownKeyDown;
	bool LeftKeyDown;
	bool RightKeyDown;
	bool MousePressed;
	bool ExitPressed;
private:
	bool m_prevMousePressed;
	bool m_prevExitPressed;
};

extern Input InputState;

