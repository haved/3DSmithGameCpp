#include "MenuBar.h"
#include "../GlobalFields.h"

#include <iostream>

MenuBar::MenuBar()
{
	std::cout << "MenuBar()" << std::endl;
}


MenuBar::~MenuBar()
{
	std::cout << "~MenuBar()" << std::endl;
}

#define MENUBAR_barXPos 100
#define MENUBAR_barWidth 240
//float optionHeight = 40;

void MenuBar::Update()
{

}

void MenuBar::Render()
{
	Global.OrthoRenderingEngine->FillColoredRectangle(glm::vec4(0, 0, 0, 1), MENUBAR_barXPos, 0, MENUBAR_barWidth, Global.OrthoRenderingEngine->GetOrthoHeight());
}
