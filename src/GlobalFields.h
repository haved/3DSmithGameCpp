#pragma once

#include "rendering/BasicShader.h"
#include "rendering/ColorShader.h"
#include "rendering/OrthoRenderingEngine.h"

#include "SFML/Window.hpp"

typedef struct
{
	BasicShader* BasicShaderInstance;
	ColorShader* ColorShaderInstance;
	OrthoRenderingEngine* OrthoRenderingEngine;
	float DeltaTime;
	float ElapsedTime;
	sf::Window* UsedWindow;
} GlobalFields;

extern GlobalFields Global;