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
	bool InteractPressed;
private:
	bool m_prevMousePressed;
	bool m_prevExitPressed;
	bool m_prevInteractPressed;
};

extern Input InputState;

