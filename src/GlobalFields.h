#pragma once

#include "rendering/BasicShader.h"
#include "rendering/ColorShader.h"
#include "rendering/TextureShader.h"
#include "rendering/OrthoRenderingEngine.h"
#include "ResCollection.h"

#include "SFML/Graphics/Font.hpp"

typedef struct
{
	BasicShader* BasicShaderInstance;
	ColorShader* ColorShaderInstance;
	TextureShader* TextureShaderInstance;
	OrthoRenderingEngine* OrthoRenderingEngine;
	ResCollection* ResCollection;
	float DeltaTime;
	float ElapsedTime;
	sf::Window* UsedWindow;
	sf::Font* DefaultFont;
} GlobalFields;

extern GlobalFields Global;