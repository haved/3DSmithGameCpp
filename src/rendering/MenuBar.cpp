#include "MenuBar.h"
#include "../GlobalFields.h"

MenuBar::MenuBar()
{
}


MenuBar::~MenuBar()
{
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
