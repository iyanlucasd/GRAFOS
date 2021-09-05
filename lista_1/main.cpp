#include <iostream>
#include "lista.hpp"
#include "celula.hpp"
#include "encadeada.hpp"

using namespace std;


int main(int, char**) {
    lista<Celula> foo;
    lista<Celula> bar;

    lista<CelulaEncadeada<Celula>> pit;

    foo.inserirFinal(new Celula(1, "Del", 1));
    foo.inserirFinal(new Celula(2, "Dudu", -4));
    foo.inserirFinal(new Celula(3, "iyan", 3));
    foo.inserirFinal(new Celula(4, "jorge", 5));
    foo.inserirFinal(new Celula(5, "pit", -1) );

    bar.inserirFinal(new Celula(1, "Del", 1));
    bar.inserirFinal(new Celula(2, "Dudu", -4));
    bar.inserirFinal(new Celula(3, "iyan", 3));
    bar.inserirFinal(new Celula(4, "jorge", 5));
    bar.inserirFinal(new Celula(5, "pit", -1) );

    pit.inserirFinal(new CelulaEncadeada<Celula>(1, "lista 1", foo));
    pit.inserirFinal(new CelulaEncadeada<Celula>(2, "lista 2", bar));
    pit.printLista("-d");
    pit.printLista("-p");
    pit.printLista("-dp");
    pit.printLista("-n");

}
