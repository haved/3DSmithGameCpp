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
private:
	bool m_prevMousePressed;
};

extern Input InputState;

