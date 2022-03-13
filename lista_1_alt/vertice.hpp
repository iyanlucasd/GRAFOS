#ifndef VERTICE_HPP
#define VERTICE_HPP

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class vertice
{
protected:
    int id;
    int size;
    int *arestas;
    string rotulo;

public:
    vertice(int id, int size);
    vertice(int id, int size, string rotulo);
    ~vertice();
    int getId();
    void insert(int pos, int val);
    void remove(int pos);
    void print();
};

vertice::vertice(int id, int size)
{
    this->id = id;
    this->size = size;
    this->arestas = new int[size];
    this->rotulo = "";
    for (int i = 0; i < size; i++)
    {
        this->arestas[i] = 0;
    }
}

vertice::vertice(int id, int size, string rotulo)
{
    this->id = id;
    this->size = size;
    this->arestas = new int[size];
    this->rotulo = rotulo;
    for (int i = 0; i < size; i++)
    {
        this->arestas[i] = 0;
    }
}

int vertice::getId(){
    return this->id;
}
void vertice::insert(int key, int val){
    this->arestas[key] = val;
}
void vertice::remove(int key){
    this->arestas[key] = 0;
}

void vertice::print(){
    cout << "[\t";
    for (int i = 0; i < size; i++)
    {
        cout << this->arestas[i] + "\t";
    }
    cout << "]" << endl;
}


vertice::~vertice()
{
}

#endif