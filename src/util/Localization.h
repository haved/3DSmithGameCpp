#pragma once

#include <string>
#include <map>

class Localization
{
public:
	Localization();
	~Localization();
	void LoadLanguage(const std::string& filePath);
	std::map<std::string, std::string> m_map;
private:
	unsigned int FindSplit(const std::string& line);
};

extern Localization* CurrentLanguage;

