#include "rendering/BasicShader.h"
#include "rendering/ColorShader.h"
#include "SFML/Window.hpp"

typedef struct
{
	BasicShader* BasicShaderInstance;
	ColorShader* ColorShaderInstance;
	float DeltaTime;
	float ElapsedTime;
	sf::Window* UsedWindow;
} GlobalFields;

extern GlobalFields Global;