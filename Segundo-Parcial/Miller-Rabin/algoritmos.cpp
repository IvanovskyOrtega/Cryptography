#include "algoritmos.hpp"

using namespace algoritmos;
using namespace std;

namespace algoritmos{
    vector<int> Qn;
}

bool algoritmos::esPrimo(int n, int iteraciones) {
	if (n <= 1 || n == 4) {
		return false;
	}
	if (n <= 3) {
		return true;
	}
	int k = 0;
	int m = n - 1;
	while (m % 2 == 0) {
		k++;
		m /= 2;
	}
	for (int i = 0; i < iteraciones; i++) {
		if (millerRabin(n,m,k) == false) {
			return false;
		}
	}
	return true;
}

bool algoritmos::millerRabin(int n, int m, int k){
    int b;
    int a;
	a = 2 + rand() % (n - 4);
	b = potenciar(a,m,n);
	if (b == 1 || b == (n-1)) {
		return true;
	}
	for (int i = 0; i < k; i++) {
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

int algoritmos::potenciar(int b, int c, int n){
	int l;
	int z = 1;
    vector<bool> c_binario;
    intToBinary(c, &c_binario);
    //imprimirBinario(c,c_binario);
	l = c_binario.size();
	for (int i = l - 1 ; i >= 0 ; i--) {
		z = (z*z) % n;
		if (c_binario[i]) {
			z = (b*z) % n;
		}
	}
	return z;
}

void algoritmos::intToBinary(int entero, vector<bool> *entero_binario){
    int tamanio = 0;
    int i = 1;
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

 void algoritmos::imprimirBinario(int entero, vector<bool> binario){
	cout << "El binario de " << entero << " es: ";
    for(int i = (int)binario.size()-1 ; i >= 0 ; i--){
        cout << binario[i];
    }
    cout << endl;
 }

int algoritmos::algoritmoDeEuclides(int r0, int r1){
    int q;
    int rn = 1;
    while(rn != 0){
        q = r0/ r1;
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

int algoritmos::encontrarInverso(int r0){
    int j = Qn.size();
    int t0 = 0;
    int t1 = 1;
    int tn;
	if (j == 0) {
		return r0 + 1;
	}
    for(int i = 0 ; i < j ; i++){
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

