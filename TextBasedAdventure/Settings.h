#pragma once
#include <iostream>
#include <string>
#include <fstream>
#define SETTINGS_PATH "data/settings.txt"

using namespace std;

class Settings
{
public:
	ifstream settingsFile;
	string GetSetting(std::string setting); // Return the value for a setting

	int typewriterSpeed; // need to declare all settings
	bool typewriterOnByDefault;
	Settings(string filepath);
	~Settings() 
	{
		settingsFile.close();
	}
};