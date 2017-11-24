#include "algoritmos.hpp"

using namespace algoritmos;
using namespace std;

namespace algoritmos{
    vector<ll> Qn;
}

void algoritmos::menu(char opcion){
	ll posiblePrimo, iteraciones;
	ll r0, r1, res, potencia;
	switch(opcion){
		case '1':
			cout << "Ingresa r0: ";
			cin >> r0;
			cout << "Ingresa r1: ";
			cin >> r1;
			res = algoritmoDeEuclides(r0,r1);
			if(res == 1){
				char op;
				cout << "encontrar inverso? (s/n)" << endl;
				cin >> op;
				if(op == 's' || op == 'S'){
					ll inverso = encontrarInverso(r0);
					cout << "El inverso es: " << inverso << endl;
				}
				else{
					Qn.clear();
				}
			}
			else{
				Qn.clear();
				cout << "No tiene inverso" << endl;
			}
			break;
		case '2':
			ll b,c,n;
			cout << "Ingresa b: ";
			cin >> b;
			cout << "Ingresa c: ";
			cin >> c;
			cout << "Ingresa n: ";
			cin >> n;
			potencia = potenciar(b,c,n);
			cout << "Resultado: " << potencia << endl;
			break;
		case '3':
			cout << "Ingresa un numero n: ";
			cin >> posiblePrimo;
			cout << "Ingresa el numero de iteraciones del algoritmo: ";
			cin >> iteraciones;
			if(esPrimo(posiblePrimo,iteraciones)){
				cout << posiblePrimo << " es primo" << endl;
			}
			else{
				cout << posiblePrimo << " no es primo" << endl;
			}
			break;
		default:
			cout << "Opcion invalida" << endl;
	}
}

bool algoritmos::esPrimo(ll n, ll iteraciones) {
	if (n <= 1 || n == 4) {
		return false;
	}
	if (n <= 3) {
		return true;
	}
	ll k = 0;
	ll m = n - 1;
	while (m % 2 == 0) {
		k++;
		m /= 2;
	}
	for (ll i = 0; i < iteraciones; i++) {
		if (millerRabin(n,m,k) == false) {
			return false;
		}
	}
	return true;
}

bool algoritmos::millerRabin(ll n, ll m, ll k){
    ll b;
    ll a;
	a = 2 + rand() % (n - 4);
	b = potenciar(a,m,n);
	if (b == 1 || b == (n-1)) {
		return true;
	}
	for (ll i = 0; i < k; i++) {
		b = potenciar(b, 2, n);
		if (b == (n - 1)) {
			return true;
		}
		else if(b == 1){
			return false;
		}
	}
    return false;
}

ll algoritmos::potenciar(ll b, ll c, ll n){
	ll l;
	ull z = 1;
    vector<bool> c_binario;
    llToBinary(c, &c_binario);
    //imprimirBinario(c,c_binario);
	l = c_binario.size();
	for (ll i = l - 1 ; i >= 0 ; i--) {
		z = (z*z) % n;
		if (c_binario[i]) {
			z = (b*z) % n;
		}
	}
	return (ll)z;
}

void algoritmos::llToBinary(ll entero, vector<bool> *entero_binario){
    ll tamanio = 0;
    ll i = 1;
    while (i<entero){
        tamanio++;
        i*=2;
    }
    entero_binario->reserve(tamanio);
    tamanio--;
    while(entero>0){
        if(entero & 1)
            entero_binario->push_back(true);
        else
            entero_binario->push_back(false);
        entero>>=1;
        tamanio--;
    }
 }

 void algoritmos::imprimirBinario(ll entero, vector<bool> binario){
	cout << "El binario de " << entero << " es: ";
    for(ll i = (ll)binario.size()-1 ; i >= 0 ; i--){
        cout << binario[i];
    }
    cout << endl;
 }

ll algoritmos::algoritmoDeEuclides(ll r0, ll r1){
    ll q;
    ll rn = 1;
    while(rn != 0){
        q = r0/r1;
        rn = r0 % r1;
        if(rn != 0){
            cout << r0 << " = (" << q << ")*" << r1 << " + " << rn << endl;
            Qn.reserve(1);
            Qn.push_back(q);
        }
        else{
            cout << r0 << " = (" << q << ")*" << r1 << endl;
        } 
        r0 = r1;
        r1 = rn;
    }
    return r0;
}

ll algoritmos::encontrarInverso(ll r0){
    ll j = Qn.size();
    ll t0 = 0;
    ll t1 = 1;
    ll tn;
	if (j == 0) {
		return r0 + 1;
	}
    for(ll i = 0 ; i < j ; i++){
        tn = (t0 - Qn[i]*t1);
        if(tn < 0){
            if(abs(tn) > r0){
                tn = abs(tn) % r0;
                tn = r0 - abs(tn);
            }
            else{
                tn = r0 - abs(tn);
            }
        }
        else if(tn > 0){
            tn = tn % r0;
        }
        else{
            cout << "0" << endl;
        }
        t0 = t1;
        t1 = tn;
        cout << "t" << i+2 << ": " << tn << endl;
    }
    return tn;
}
