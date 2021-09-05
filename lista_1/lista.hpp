#ifndef LISTA_HPP
#define LISTA_HPP

#include <iostream>
#include <stdlib.h>
#include "metodos.hpp"

using namespace std;
template <typename T>

class lista
{
protected:
    int tam;
    T *newCelula();
    T *newCelula(int vertice, string nome);

public:
    T *first;
    T *last;

    lista();
    ~lista();

    void printLista();
    void printLista(string cmd);
    void inserirInicio(T *temp);
    void inserirFinal(T *temp);
    void inserirAt(int pos, T *temp);
    int removeAt(int pos);
    int removeInicio();
    int removeFim();
};

template <typename T>
lista<T>::lista()
{
    first = last = newCelula();
    tam = 0;
}

template <typename T>
lista<T>::~lista()
{
}

template <typename T>
T *lista<T>::newCelula()
{
    T *foo = new T();
    return foo;
}

template <typename T>
void lista<T>::printLista()
{
    T *temp = first->pointer;
    cout << "[ ";
    for (int i = 0; i < tam; i++)
    {
        temp->printCelula();
        temp = temp->pointer;
    }
    cout << " ]" << endl;
}

template <typename T>
void lista<T>::printLista(string cmd)
{
    T *temp = first->pointer;

        for (int i = 0; i < tam; i++)
        {
            temp->printCelula(cmd);
            temp = temp->pointer;
        }

}

template <typename T>
void lista<T>::inserirInicio(T *temp)
{
    temp->pointer = first;
    first = temp;

    tam++;
}

template <typename T>
void lista<T>::inserirFinal(T *temp)
{
    last->pointer = temp;
    last = last->pointer;

    tam++;
}

template <typename T>
void lista<T>::inserirAt(int pos, T *temp)
{
    if (pos < 0 || pos > tam)
        printf("Erro ao tentar inserir na posicao (%d/ tamanho = %d) invalida!", pos, tam);
    else if (pos == 0)
        inserirInicio(temp);
    else if (pos == tam)
    {
        inserirFinal(temp);
    }
    else
    {

        T *ant = first;
        for (int i = 0; i < pos - 1; i++)
        {
            ant = ant->pointer;
        }

        temp->pointer = ant->pointer;
        ant->pointer = temp;
        tam++;
    }
}

template <typename T>
int lista<T>::removeAt(int pos)
{
    if (tam == 0)
    {
        printf("\nA lista esta vazia!\n");
        return -1;
    }
    else if (pos < 0 || pos > tam - 1)
    {
        printf("Erro ao tentar remover item da posicao (%d/ tamanho = %d) invalida!", pos, tam);
        return -1;
    }
    else
    {
        T *ant = first;
        for (int i = 0; i < pos - 1; i++)
            ant = ant->pointer;
        T *temp = ant->pointer;
        int vertice = temp->vertice;
        ant->pointer = temp->pointer;
        free(temp);
        if (pos == tam - 1)
            last = ant;
        tam--;
        return vertice;
    }
}
template <typename T>
int lista<T>::removeInicio()
{
    return removeAt(0);
}
template <typename T>
int lista<T>::removeFim()
{
    return removeAt(tam - 1);
}

#endif