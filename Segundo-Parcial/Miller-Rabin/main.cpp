#include "algoritmos.hpp"

using namespace std;
using namespace algoritmos;

int main(int argc, char **argv){
	cout << "Primeros numeros primos menores a 100" << endl;
	for (int i = 1; i < 100; i++) {
		if (esPrimo(i, 4)) {
			cout << i << " ";
		}
	}
	cout << endl;
    return 0;
}