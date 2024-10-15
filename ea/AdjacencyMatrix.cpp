#include "AdjacencyMatrix.h"
#include <iostream>

void AdjacencyMatrix::allocateMemory()
{
    this->matrix = new float* [this->citiesNumber];

    for (int i = 0; i < this->citiesNumber; ++i)
    {
        this->matrix[i] = new float[this->citiesNumber];

        for (int j = 0; j < this->citiesNumber; ++j)
            this->matrix[i][j] = 0;
    }

}

void AdjacencyMatrix::insertValues(const float* data_)
{
    for (int i = 0, dataCounter = 0; i < this->citiesNumber; ++i)
    {
        for (int j = 0; j < this->citiesNumber; ++j, ++dataCounter)
        {
            this->matrix[i][j] = data_[dataCounter];
        }
    }
}

void AdjacencyMatrix::copyValues(float** dataFromOrigin_)
{
    for (int i = 0; i < this->citiesNumber; ++i)
    {
        for (int j = 0; j < this->citiesNumber; ++j)
        {
            this->matrix[i][j] = dataFromOrigin_[i][j];
        }
    }
}

void AdjacencyMatrix::deallocateMemory()
{
    for (int i = 0; i < this->citiesNumber; ++i)
    {
        delete[] this->matrix[i];
    }

    delete[] this->matrix;

    this->matrix = nullptr;
}

AdjacencyMatrix::AdjacencyMatrix(int citiesNumber_, const float* data_)
    : citiesNumber(citiesNumber_)
{
    this->allocateMemory();
    this->insertValues(data_);
}

AdjacencyMatrix::AdjacencyMatrix(int citiesNumber_, const float** data_)
    : citiesNumber(citiesNumber_)
{
    // tutaj wpisywanie obliczonych distance do nowej struktury z3ebyu mozna bylo insert zrobis
    //float tempData = new float*;
    for (size_t i = 0; i < citiesNumber_; i++)
    {
        for (size_t ii = 0; ii < citiesNumber_; ii++) {
            calculateDistance(data_[i][0], data_[i][1], data_[ii][0], data_[ii][1]);
        }
    }

    this->allocateMemory();
    //this->insertValues(data_);
}

AdjacencyMatrix::AdjacencyMatrix(const AdjacencyMatrix& origin_)
    : citiesNumber(origin_.citiesNumber)
{
    this->allocateMemory();
    this->copyValues(origin_.matrix);
}

AdjacencyMatrix::~AdjacencyMatrix()
{
    this->deallocateMemory();
}

float AdjacencyMatrix::calculateDistance(float firstX, float firstY, float secondX, float secondY)
{
    float fullDistance, xDistance, yDistance;
    xDistance = secondX - firstX;
    yDistance = secondY - firstY;
    xDistance = xDistance * xDistance;
    yDistance = yDistance * yDistance;
    fullDistance = xDistance + yDistance;
    fullDistance = sqrt(fullDistance);
    return fullDistance;
}

void AdjacencyMatrix::printMatrix()
{
    for (int i = 0; i < this->citiesNumber; ++i)
    {
        for (int j = 0; j < this->citiesNumber; ++j)
        {
            std::cout << this->matrix[i][j] << " ";
        }

        std::cout << "\n";
    }
}