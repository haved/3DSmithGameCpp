#include "Localization.h"
#include <iostream>
#include <fstream>

Localization* CurrentLanguage;

Localization::Localization()
{
	CurrentLanguage = this;
}


Localization::~Localization()
{

}

void Localization::LoadLanguage(const std::string& filePath)
{
	m_map.clear();

	std::ifstream file;
	file.open((filePath).c_str());

	std::string line;

	if (file.is_open())
	{
		while (file.good())
		{
			std::getline(file, line);
			unsigned int split = FindSplit(line);
			std::string key = line.substr(0, split);
			m_map[key] = line.substr(split+3, line.length());
		}
	}
	else
	{
		std::cerr << "Unable to load localization file: " << filePath << std::endl;
	}
}

unsigned int Localization::FindSplit(const std::string& line)
{
	unsigned int i;
	for (i = 0; i < line.length()-3; i++)
	{
		if (line.compare(i, 3, "===")==0)
			break;
	}
	return i;
}