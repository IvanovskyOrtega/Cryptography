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
			vector<bitset<48>*> programaDeLlaves;
			vector<bitset<64>*> encriptado;
			bitset<64>* aux;
			printf("Tamanio del archivo: %lu\n",tamanio);
			cout << "Se generara el programa de llaves." << endl;
			programaDeLlaves = generarProgramaDeLlaves();
			cout << "Se genero el programa de llaves." << endl;
			cout << "Inicia la encriptacion del archivo..." << endl;
			for(int i = 0 ; i < (int)bytesLeidos.size()-1 ; i++){
				aux = iniciarEncriptacionDES(bytesLeidos[i], programaDeLlaves);
				encriptado.reserve(1);
				encriptado.push_back(new bitset<64>(*aux));
				aux->reset();
			}
			encriptado.reserve(1);
			encriptado.push_back(bytesLeidos[bytesLeidos.size()-1]);
			escribirArchivo(encriptado,argv[2],tamanio);
			cout << "Termina la encriptacion del archivo..." << endl;
		}
	}
	else{
		cout << "./a.out nombreArchivoOriginal nombreArchivoEncriptado" << endl;
	}
	return 0;
}
