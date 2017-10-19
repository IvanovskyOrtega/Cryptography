#include "des.hpp"
#include "archivos.hpp"

using namespace std;
using namespace archivos;
using namespace des;

int main (int argc, char* argv[]) {
	bitset<64>* entrada = new (nothrow)bitset<64>();
	bitset<64> entrada2(string("0000000100100011010001010110011110001001101010111100110111101111"));
	cout << "El texto plano a encriptar es: ";
	for(int i = 0 ; i < 64 ; i++){
		(*entrada)[i] = entrada2[i];
	}
	cout << hex << (*entrada).to_ulong() << endl;
	iniciarEncriptacionDES(entrada);
	vector<bitset<64>*> bytesLeidos  = leerArchivo(argv[1]);
	printf("Tamanio: %lu\n",tamanio);
	escribirArchivo(bytesLeidos,"encriptado",tamanio);
	return 0;
	
	/******Aqui se implementara algo para encriptar archivos.*******/

	
}
