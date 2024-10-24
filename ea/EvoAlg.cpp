#include "EvoAlg.h"
#include <math.h>
#include <random>


std::vector<int> EvoAlg::shuffleChromosome(const std::vector<int>& vertices_)
{
	std::vector<int> chromosome = vertices_;
	for (int i = 0; i < chromosome.size(); ++i)
	{
		auto firstIndex = getRandomInt(0, chromosome.size() - 1);
		auto secondIndex = getRandomInt(0, chromosome.size() - 1);

		std::swap(chromosome[firstIndex], chromosome[secondIndex]);
	}
	return chromosome;
}

int EvoAlg::getRandomInt(int min_, int max_)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(min_, max_);
	return dist(gen);
}

void EvoAlg::generateFirstPopulation(const AdjacencyMatrix& matrix_)
{
	std::vector<int> vertices;
	for (int i = 0; i < this->verticesNumber; ++i)
	{
		if (i == this->verticesNumber) {
			continue;
		}
		vertices.push_back(i);
	}
	for (int i = 0; i < populationSize; ++i)
	{
		std::vector<int> chromosome = shuffleChromosome(vertices);

		Specimen specimen(chromosome);
		specimen.calculateFitness(matrix_, this->sourceVertice);

		this->population.push_back(specimen);
	}
}

Path* EvoAlg::solveTSP(const AdjacencyMatrix& matrix_, int sourceCity_)
{
	// dokoñczyæ
	return nullptr;
}

Path* EvoAlg::solveTSP(std::string fileName_, std::string& writter_, const AdjacencyMatrix& matrix_, int sourceVertice_)
{
	double algorithmTime{ 0.0 };

	this->sourceVertice = sourceVertice_;
	this->verticesNumber = matrix_.verticesNumber;
	this->bestOneTenthCrossovers = static_cast<int>(0.1 * populationSize);

	std::sort(population.begin(), population.end());
	this->bestSpecimen = this->population[0];

	// dokoñczyæ

	return nullptr;
}