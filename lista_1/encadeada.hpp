#ifndef ENCADEADA_HPP
#define ENCADEADA_HPP

#include <iostream>
#include <stdlib.h>
#include "lista.hpp"
#include "celula.hpp"

using namespace std;

template <class U>
class CelulaEncadeada
{

public:
    string nome;
    int vertice;
    CelulaEncadeada *pointer;
    lista<U> foo;
    CelulaEncadeada();
    CelulaEncadeada(int vertice, string nome, lista<U> foo);
    ~CelulaEncadeada();

    void printCelula();
    void printCelula(string cmd);
};

template <class U>
CelulaEncadeada<U>::CelulaEncadeada()
{
    nome = "";
    vertice = 0;
    pointer = NULL;
}

template <class U>
CelulaEncadeada<U>::CelulaEncadeada(int vertice, string nome, lista<U> foo)
{
    this->nome = nome;
    this->vertice = vertice;
    pointer = NULL;
    this->foo = foo;
}

template <class U>
CelulaEncadeada<U>::~CelulaEncadeada()
{
}

template <class U>
void CelulaEncadeada<U>::printCelula()
{

    cout << "vertice " << vertice<< "\t";
    foo.printLista();
}

template <class U>
void CelulaEncadeada<U>::printCelula(string cmd)
{
    cout << "vertice " << vertice<< "\t";
    cout <<"[ ";
    foo.printLista(cmd);
    cout <<"] " << endl;
}

#endif