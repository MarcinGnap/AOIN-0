#include "AdjacencyMatrix.h"
#include <iostream>

void AdjacencyMatrix::allocateMemory()
{
    this->matrix = new float* [this->verticesNumber];

    for (int i = 0; i < this->verticesNumber; ++i)
    {
        this->matrix[i] = new float[this->verticesNumber];

        for (int j = 0; j < this->verticesNumber; ++j)
            this->matrix[i][j] = 0;
    }

}

void AdjacencyMatrix::insertValues(const float* data_)
{
    for (int i = 0, dataCounter = 0; i < this->verticesNumber; ++i)
    {
        for (int j = 0; j < this->verticesNumber; ++j, ++dataCounter)
        {
            this->matrix[i][j] = data_[dataCounter];
        }
    }
}

void AdjacencyMatrix::insertValuesTwoDimension(float** data_)
{
    for (int i = 0; i < this->verticesNumber; ++i)
    {
        for (int j = 0; j < this->verticesNumber; ++j)
        {
            this->matrix[i][j] = data_[i][j];
        }
    }
}

void AdjacencyMatrix::copyValues(float** dataFromOrigin_)
{
    for (int i = 0; i < this->verticesNumber; ++i)
    {
        for (int j = 0; j < this->verticesNumber; ++j)
        {
            this->matrix[i][j] = dataFromOrigin_[i][j];
        }
    }
}

void AdjacencyMatrix::deallocateMemory()
{
    for (int i = 0; i < this->verticesNumber; ++i)
    {
        delete[] this->matrix[i];
    }

    delete[] this->matrix;

    this->matrix = nullptr;
}

AdjacencyMatrix::AdjacencyMatrix(int verticesNumber_, float** data_)
    : verticesNumber(verticesNumber_)
{
    this->allocateMemory();
    this->insertValuesTwoDimension(data_);
}

AdjacencyMatrix::AdjacencyMatrix(const AdjacencyMatrix& origin_)
    : verticesNumber(origin_.verticesNumber)
{
    this->allocateMemory();
    this->copyValues(origin_.matrix);
}

AdjacencyMatrix::~AdjacencyMatrix()
{
    this->deallocateMemory();
}

void AdjacencyMatrix::printMatrix()
{
    for (int i = 0; i < this->verticesNumber; ++i)
    {
        for (int j = 0; j < this->verticesNumber; ++j)
        {
            std::cout << this->matrix[i][j] << " ";
        }

        std::cout << "\n";
    }
}