#pragma once
class AdjacencyMatrix
{
    float** matrix = nullptr;

    void allocateMemory();
    void insertValues(const float* data_);
    void copyValues(float** dataFromOrigin_);

    void deallocateMemory();

public:

    const int citiesNumber;

    AdjacencyMatrix(int citiesNumber_, const float* data_);
    AdjacencyMatrix(int citiesNumber_, const float** data_);
    AdjacencyMatrix(const AdjacencyMatrix& origin_);
    ~AdjacencyMatrix();

    float calculateDistance(float firstX, float firstY, float secondX, float secondY);

    float** getMatrix() const
    {
        return this->matrix;
    }

    int getValue(int source_, int destination_) const
    {
        return this->matrix[source_][destination_];
    }

    void printMatrix();
};

