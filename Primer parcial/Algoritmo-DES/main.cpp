#include "des.hpp"
#include "archivos.hpp"

using namespace std;
using namespace archivos;
using namespace des;

int main (int argc, char* argv[]) {
	if(argc >= 3){
		cout << "Archivo a encriptar: " << argv[1] << endl;
		vector<bitset<64>*> bytesLeidos  = leerArchivo(argv[1]);
		if(bytesLeidos.size() > 0){
			vector<bitset<64>*> encriptado;
			bitset<64>* aux;
			printf("Tamanio del archivo: %lu\n",tamanio);
			for(int i = 0 ; i < (int)bytesLeidos.size()-1 ; i++){
				aux = iniciarEncriptacionDES(bytesLeidos[i]);
				encriptado.reserve(1);
				encriptado.push_back(new bitset<64>(*aux));
				aux->reset();
				cout << hex << (*aux).to_ulong() << endl;
			}
			encriptado.reserve(1);
			encriptado.push_back(bytesLeidos[bytesLeidos.size()-1]);
			escribirArchivo(encriptado,argv[2],tamanio);
		}
	}
	else{
		cout << "./a.out nombreArchivoOriginal nombreArchivoEncriptado" << endl;
	}
	return 0;
}
