#include "ResCollection.h"
#include "GlobalFields.h"

ResCollection::ResCollection(const std::string& texturePath, const std::string& meshPath)
{
	Box_t.loadFromFile(texturePath + "button.png");
	Box_t.setRepeated(true);
	Box_t.setSmooth(true);

	Ingot_m = std::make_unique<Mesh>(meshPath + "ingot.ply");

	Global.ResCollection = this;
}