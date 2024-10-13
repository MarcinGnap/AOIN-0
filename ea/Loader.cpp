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
	cout << "Opening TSP file...\n";
	ifstream tspFile(fileName, ios::in);
	if (!tspFile.good())
	{
		this->fileName = "Brak pliku";
		cout << "This file does not exist...\n";
		return false;
	}
	if (verticesNumber != 0)
	{
		for (int i = 0; i < verticesNumber; i++)
		{
			delete verticesGraph[i];
		}
		delete verticesGraph;
		verticesGraph = NULL;
		verticesNumber = 0;
	}
	cout << "TSP file opened properly...\n";

	string tempLine;

	while (getline(tspFile, tempLine))
	{
		if (tempLine.find("DIMENSION") != string::npos)
		{
			verticesNumber = stoi(tempLine.substr(tempLine.find(":") + 1));
			break;
		}
	}


	tspFile.close();
	return false;
}
