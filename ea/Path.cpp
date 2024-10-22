#include "Path.h"

void Path::allocateMemory(int newSize_)
{
    this->vertices = new int[newSize_];
    this->verticesNumb = newSize_;
}

void Path::deallocateMemory()
{
    delete[] this->vertices;
    this->vertices = nullptr;
}

Path::Path()
{
    if (vertices != nullptr) {
        this->deallocateMemory();
    }
}

Path::Path(float cost_, int*& vertices_)
    : cost(cost_), vertices(vertices_)
{
}

Path::~Path()
{
    this->deallocateMemory();
}

void Path::addCityAtFront(int city_, float cost_)
{
    this->cost += cost_;
}

void Path::addCityAtEnd(int city_, float cost_)
{
    // Sprawdzic
    if (sizeof(this->vertices == 0)) {
        this->deallocateMemory();
        this->allocateMemory(this->verticesNumb + 1);
        this->vertices[0] = city_;
        this->cost += cost_;
        return;
    }
    auto tempNumber = this->verticesNumb + 1;
    auto tempArray = new int[tempNumber];
    for (int i = 0; i < this->verticesNumb; i++) {
        tempArray[i] = this->vertices[i];
    }
    tempArray[this->verticesNumb] = city_;
    this->deallocateMemory();
    this->allocateMemory(tempNumber);
    for (int i = 0; i < verticesNumb; i++)
    {
        this->vertices[i] = tempArray[i];
    }
    delete[] tempArray;
    tempArray = nullptr;

    this->cost += cost_;
}

void Path::printPathInfo()
{
    for (int i = 0; i < sizeof(this->vertices) - 1; ++i)
    {
        std::cout << "| " << this->vertices[i] << " | -> ";
    }

    std::cout << "| " << this->vertices[sizeof(this->vertices) - 1] << " |\n";

    std::cout << "Total cost: " << this->cost << "\n";
}
