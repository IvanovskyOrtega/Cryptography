#ifndef _ALGORITMOS_HPP_
#define _ALGORITMOS_HPP_

#include <vector>
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

typedef unsigned long long ull;
typedef long long ll;

namespace algoritmos{
	extern std::vector<ll> Qn;
	ll algoritmoDeEuclides(ll r0, ll r1 );
	ll encontrarInverso(ll r0);
	ll potenciar(ll b, ll c, ll n);
	void llToBinary(ll entero, std::vector<bool> *entero_binario);
	void imprimirBinario(ll entero, std::vector<bool> binario);
	bool millerRabin(ll n, ll m, ll k);
	bool esPrimo(ll n, ll iteraciones);
	void menu(char opcion);
}

#endif
