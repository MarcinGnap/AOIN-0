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

	void deleteGraph();
	void printGraph();
	bool createRandomGraph(int generatedVertices, int maxValue);

	bool openIni();
	bool openTSPFile(std::string& FileName);

};
