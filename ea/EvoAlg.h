#pragma once
//#include<algorithm>
#include<vector>
#include <algorithm>
#include"Path.h"
#include"AdjacencyMatrix.h"
#include "Specimen.h"

class EvoAlg
{
public:

	EvoAlg() = default;;

    Path* solveTSP(const AdjacencyMatrix& matrix_, int sourceCity_ = 0);
    Path* solveTSP(std::string fileName_, std::string& writter_, const AdjacencyMatrix& matrix_, int sourceCity_ = 0);

    static void setStopTime(double stopTime_)
    {
        stopTime = stopTime_;
    }

    static void setPopulationSize(int size_)
    {
        populationSize = size_;
    }

    static void setMutationType(char type_)
    {
        mutationType = type_;
    }

    static void setCrossoverType(char type_)
    {
        crossoverType = type_;
    }

    static void setMutationProbability(double probability_)
    {
        mutationProbability = probability_;
    }

    static void setCrossoverProbability(double probability_)
    {
        crossoverProbability = probability_;
    }


private:

    int sourceVertice{ 0 };
    int verticesNumber{ 0 };

    static double mutationProbability;
    static double crossoverProbability;
    static int populationSize;
    static double stopTime;

    static char mutationType; // s = swap, i = insert
    static char crossoverType; // o = ox, p = pmx


    Specimen bestSpecimen;
    int bestOneTenthCrossovers{ 0 };
    std::vector<Specimen> population;

    void generateFirstPopulation(const AdjacencyMatrix& matrix_);
    std::vector<int> shuffleChromosome(const std::vector<int>& vertices_);
    static int getRandomInt(int min_, int max_);

};

