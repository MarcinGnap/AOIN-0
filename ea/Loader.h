#pragma once
#include <string>

class Loader
{
public:

	std::string fileName;
	int plannedVerticiesNumber;
	int optCost;
	int verticesNumber;
	int* bestPath;
	float** verticesGraph;

	Loader();
	~Loader();

	bool OpenIni();
	bool OpenTSPFile(std::string& FileName);

};
