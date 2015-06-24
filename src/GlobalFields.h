#include "rendering\BasicShader.h"
#include "SFML/Window.hpp"

typedef struct
{
	BasicShader* BasicShaderInstance;
	float DeltaTime;
	float ElapsedTime;
	sf::Window* UsedWindow;
} GlobalFields;

extern GlobalFields Global;