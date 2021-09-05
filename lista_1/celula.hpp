#ifndef CELULA_HPP
#define CELULA_HPP

#include <iostream>
#include <stdlib.h>

using namespace std;

class Celula
{
protected:
    string nome;
    int vertice;
    int peso;

public:
    Celula *pointer;
    Celula();
    Celula(int vertice, string nome);
    Celula(int vertice, string nome, int peso);
    ~Celula();

    void printCelula();
    void printCelula(string cmd);
};

Celula::Celula()
{
    nome = "";
    vertice = 0;
    pointer = NULL;
    peso = NULL;
}

Celula::Celula(int vertice, string nome)
{
    this->nome = nome;
    this->vertice = vertice;
    pointer = NULL;
    peso = NULL;
}
Celula::Celula(int vertice, string nome, int peso)
{
    this->nome = nome;
    this->vertice = vertice;
    this->peso = peso;
    pointer = NULL;
}

Celula::~Celula()
{
}

void Celula::printCelula()
{
    if (peso != NULL)
        if (peso > 0)
            cout << "+" << peso << " ";
        else
            cout << peso << " ";
    else
        cout << endl;
}

void Celula::printCelula(string cmd)
{
    switch (str2int(cmd.c_str()))
    {
    case str2int("-d"):
        if (peso != NULL)
            if (peso > 0)
                cout << "+" << 1 << " ";
            else if (peso == 0)
                cout << 0 << " ";
            else
                cout << -1 << " ";
        else
            cout << endl;
        break;
    case str2int("-dp"):
        if (peso != NULL)
            if (peso > 0)
                cout << "+" << peso << " ";
            else
                cout << peso << " ";
        else
            cout << endl;
        break;
    case str2int("-p"):
        cout << abs(peso) << " ";
        break;
    case str2int("-n"):
        if (peso != 0)
            cout << 1 << " ";
        else
            cout << 0 << " ";
        break;

    default:
        break;
    }
}

#endif