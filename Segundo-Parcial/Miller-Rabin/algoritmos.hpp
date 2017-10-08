#ifndef _ALGORITMOS_HPP_
#define _ALGORITMOS_HPP_

#include <vector>
#include <iostream>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <locale>
#include <ctime>
#include <cstdlib>

typedef unsigned long long int ull;

namespace algoritmos{
    extern std::vector<int> Qn;
    int algoritmoDeEuclides(int r0, int r1 );
    int encontrarInverso(int r0);
    int potenciar(int b, int c, int n);
    void intToBinary(int entero, std::vector<bool> *entero_binario);
    void imprimirBinario(int entero, std::vector<bool> binario);
    bool millerRabin(int n, int m, int k);
	bool esPrimo(int n, int iteraciones);
}

#endif