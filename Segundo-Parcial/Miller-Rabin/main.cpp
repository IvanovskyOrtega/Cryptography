#include "algoritmos.hpp"

using namespace std;
using namespace algoritmos;

int main(int argc, char **argv){
	char opcion, opcion2 = 's';
	while(opcion2 != 'n'){
		cout << "1) Euclides" << endl;
		cout << "2) Potenciacion modular" << endl;
		cout << "3) Miller-Rabin" << endl;
		cout << "4) Curva eliptica" << endl;
		cout << "5) Doblar" << endl;
		cout << "Ingrese opcion:" << endl;
		cin >> opcion;
		menu(opcion);
		cout << endl;
		cout << "Desea continuar? (s/n)" << endl;
		cin >> opcion2;
	}
    return 0;
}
