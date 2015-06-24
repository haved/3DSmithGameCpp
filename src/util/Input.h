#pragma once
class Input
{
public:
	void Update();
	float OrthoMouseX;
	float OrthoMouseY;
	float RelativeMouseX;
	float RelativeMouseY;
};

extern Input InputState;

