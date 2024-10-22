#pragma once
#include <iostream>

class Path
{
	float cost{ 0 };
	int* vertices;
    int verticesNumb;

	void allocateMemory(int newSize_);
	void deallocateMemory();

public:

	Path();
	Path(float cost_, int*& vertices_);
	~Path();

    void addCityAtFront(int city_, float cost_ = 0);
    void addCityAtEnd(int city_, float cost_ = 0);
    void printPathInfo();

    void setCost(size_t cost_)
    {
        this->cost = cost_;
    }

    size_t getCost()
    {
        return this->cost;
    }

    int*& getCities()
    {
        return this->vertices;
    }

};

