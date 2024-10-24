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

void EvoAlg::crossover(std::vector<Specimen>& newPopulation_)
{
	newPopulation_.push_back(this->bestSpecimen);
	for (int i = 1; i < bestOneTenthCrossovers + 1; ++i)
	{
		auto randomPropability = getRandomDouble(0.0, 1.0); 

		if (randomPropability > crossoverProbability)
		{
			newPopulation_.push_back(this->population[i]);
			continue;
		}
		auto chromosome1 = this->bestSpecimen.getChromosome();
		auto chromosome2 = this->population[i].getChromosome();

		executeCrossover(chromosome1, chromosome2);

		newPopulation_.push_back(Specimen(chromosome1));
		newPopulation_.push_back(Specimen(chromosome2));
	}
}

void EvoAlg::executeCrossover(std::vector<int>& chromosome1_, std::vector<int>& chromosome2_)
{
	switch (crossoverType)
	{
	case 'p': {
		// pmx crossover
		break;
	}
	case 'o':{
		// ox crossover
		break;
	}
	}
}

void EvoAlg::mutate(std::vector<Specimen>& newPopulation_)
{
	for (int i = 0; i < populationSize; ++i)
	{
		auto randomPropability = getRandomDouble(0.0, 1.0);

		if (randomPropability > mutationProbability)
			continue;

		newPopulation_[i].mutate(mutationType);
	}
}

int EvoAlg::getRandomInt(int min_, int max_)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(min_, max_);
	return dist(gen);
}

double EvoAlg::getRandomDouble(double min_, double max_)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<double> dist(min_, max_);

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

void EvoAlg::generateNewPopulation(std::vector<Specimen>& newPopulation_)
{
	crossover(newPopulation_);
	mutate(newPopulation_);
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

	while ((algorithmTime / 1000.0) < stopTime)
	{
		timer.start();
		std::vector<Specimen> newPopulation;
		generateNewPopulation(newPopulation);
	}
	// dokoñczyæ

	return nullptr;
}