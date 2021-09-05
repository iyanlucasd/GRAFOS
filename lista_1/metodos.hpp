#ifndef METODOS_HPP
#define METODOS_HPP

#include <iostream>
#include <stdlib.h>

using namespace std;

constexpr unsigned int str2int(const char *str, int h = 0)
{
    return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}


#endif