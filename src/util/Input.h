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
};

extern Input InputState;

