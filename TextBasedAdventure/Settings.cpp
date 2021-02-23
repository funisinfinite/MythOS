#include "Settings.h"

std::string Settings::GetSetting(std::string setting)
{
    string currentLine;
    for (int i = 0; i < 100; ++i) // arbitrary 100
    {
        getline(settingsFile, currentLine);
        if (currentLine.length() >= setting.length() && currentLine.substr(0, setting.length()) == setting) // if we are at the right line
            return currentLine.substr(currentLine.find(':') + 1, currentLine.length()); // return everything after colon
    }
    cout << "could not find setting " + setting + ". Does settings.txt exist?";
}

Settings::Settings(string filepath)
{
	settingsFile = ifstream(filepath);
	try {
		typewriterWait = stoi(GetSetting("typewriter wait"));
	}
	catch (exception e) {
		cout << "check that typewriter wait in settings.txt is an integer";
	}
	typewriterOnByDefault = GetSetting("typewriter on by default") == "true";
}