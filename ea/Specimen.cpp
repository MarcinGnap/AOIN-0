#include <random>
#include "Specimen.h"

Specimen::Specimen(std::vector<int>& chromosome_)
    : chromosome(chromosome_)
{

}

void Specimen::killSpecimen()
{
    this->chromosome.clear();
    this->fitness = INT_MAX;
}

void Specimen::calculateFitness(const AdjacencyMatrix& matrix_, int source_)
{
    this->fitness = matrix_.getValue(source_, chromosome[0]);
    for (int i = 0; i < this->chromosome.size() - 1; ++i)
    {
        this->fitness += matrix_.getValue(this->chromosome[i], this->chromosome[i + 1]);
    }
    this->fitness += matrix_.getValue(this->chromosome[this->chromosome.size() - 1], source_);
}

void Specimen::mutate(char mutationType_)
{
    int firstIndex{ 0 }, secondIndex{ 0 };

    while (firstIndex == secondIndex)
    {
        firstIndex = getRandomInt(0, this->chromosome.size() - 1);
        secondIndex = getRandomInt(0, this->chromosome.size() - 1);
    }

    if (firstIndex > secondIndex) {
        std::swap(firstIndex, secondIndex);
    }

    switch (mutationType_)
    {
        case 's':{
            std::swap(this->chromosome[firstIndex], this->chromosome[secondIndex]);
            break;
        }
        case 'i':{
            auto tempChromosome = this->chromosome[secondIndex];
            for (int i = secondIndex; i > firstIndex; --i)
            {
                this->chromosome[i] = this->chromosome[i - 1];
            }
            this->chromosome[firstIndex] = tempChromosome;
            break;
        }
        default: {
            break;
        }
    }
}

int Specimen::getRandomInt(int min_, int max_)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(min_, max_);
    return dist(gen);
}

