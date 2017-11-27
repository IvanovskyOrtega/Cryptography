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
	extern std::vector<ll*> sumas;
	ll algoritmoDeEuclides(ll r0, ll r1 );
	ll encontrarInverso(ll r0);
	ll potenciar(ll b, ll c, ll n);
	void llToBinary(ll entero, std::vector<bool> *entero_binario);
	void imprimirBinario(ll entero, std::vector<bool> binario);
	bool millerRabin(ll n, ll m, ll k);
	bool esPrimo(ll n, ll iteraciones);
	void menu(char opcion);
	void curvaEliptica(ll a, ll b);
	void verificarK(ll k, ll p, ll x0, ll y0, ll q);
	ll* doblar(ll x0, ll y0, ll x1, ll y1, ll k, ll p);
	ll* sumar(ll numSumas, ll x0, ll y0, ll x1, ll y1, ll k, ll p);
}

#endif
