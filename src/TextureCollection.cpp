#include "TextureCollection.h"
#include "GlobalFields.h"

TextureCollection::TextureCollection(const std::string& texturePath)
{
	Box.loadFromFile(texturePath + "button.png");
	Box.setRepeated(true);
	Box.setSmooth(true);
	Global.TextureCollection = this;
}