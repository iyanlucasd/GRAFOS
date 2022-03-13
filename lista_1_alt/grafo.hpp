#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <iostream>
#include <stdlib.h>
#include <string>
#include <list>
#include "vertice.hpp"

using namespace std;

class grafo
{
protected:
    int id;
    list <vertice> V;
public:
    grafo();
    ~grafo();
};

grafo::grafo()
{
    this->id = 0;
}

grafo::~grafo()
{
}


#endif