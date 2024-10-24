#pragma once

#include <iostream>

class AdjacencyMatrix
{

    float** matrix = nullptr;

    void allocateMemory();
    void insertValues(const float* data_);
    void insertValuesTwoDimension(float** data_);
    void copyValues(float** dataFromOrigin_);

    void deallocateMemory();

public:

    const int verticesNumber;

    AdjacencyMatrix(int verticesNumber_, float** data_);
    AdjacencyMatrix(const AdjacencyMatrix& origin_);
    ~AdjacencyMatrix();

    float** getMatrix() const
    {
        return this->matrix;
    }

    float getValue(int source_, int destination_) const
    {
        return this->matrix[source_][destination_];
    }

    void printMatrix();
};