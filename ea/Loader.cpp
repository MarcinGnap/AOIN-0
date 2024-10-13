#include "Loader.h"
#include <iostream>
#include <fstream>

using namespace std;

Loader::Loader()
{
}

Loader::~Loader()
{
	if (verticesNumber != 0)
	{
		for (int i = 0; i < verticesNumber; i++) {
			delete verticesGraph[i];
		}
		delete verticesGraph;
		verticesGraph = NULL;
		verticesNumber = 0;
	}
}

bool Loader::OpenIni()
{
	cout << "Opening .ini file...\n";
	ifstream iniFile("config.ini", std::ios::in);
	if (iniFile.good())
	{
		iniFile >> fileName;
		iniFile >> plannedVerticiesNumber;
		iniFile >> optCost;

		iniFile.close();
		cout << ".ini file opened properly.\n";
		return true;
	}
	cout << ".ini file failed to open.\n";
	return false;
}

bool Loader::OpenTSPFile(std::string& FileName)
{
	return false;
}
