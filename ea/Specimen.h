#pragma once
#include <vector>
#include "AdjacencyMatrix.h"


class Specimen
{
public:

    Specimen() = default;
    explicit Specimen(std::vector<int>& chromosome_);
    ~Specimen() = default;

    Specimen& operator=(const Specimen& other_)
    {
        this->chromosome = other_.chromosome;
        this->fitness = other_.fitness;

        return *this;
    }

    void killSpecimen();

    void calculateFitness(const AdjacencyMatrix& matrix_, int source_);
    void mutate(char mutationType_);
    static int getRandomInt(int min_, int max_);

    bool operator<(const Specimen& other_)
    {
        return this->fitness < other_.fitness;
    }

    int getFitness() const
    {
        return this->fitness;
    }

    std::vector<int> getChromosome() const
    {
        return chromosome;
    }

private:

    std::vector<int> chromosome;
    int fitness{ INT_MAX };

};

