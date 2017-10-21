#include "des.hpp"
#include "archivos.hpp"

using namespace std;
using namespace archivos;
using namespace des;
using namespace bits;

int main (int argc, char* argv[]) {
	if(argc >= 3){
		uchar* a = new uchar[8];
		a[0] = 1;
		a[1] = 35;
		a[2] = 69;
		a[3] = 103;
		a[4] = 137;
		a[5] = 171;
		a[6] = 205;
		a[7] = 239;
		for(int i = 0; i < 8; i++){
			imprimirByte(a[i]);
		}
		cout << endl;
		a = aplicarPermutacionInicial(a);
		for(int i = 0; i < 8; i++){
			imprimirByte(a[i]);
		}
		cout << endl;
		int c = 64+32+8;
		uchar u = c;
		imprimirByte(u);
		cout << endl;
		u = u>>2;
		imprimirByte(u);
		uchar x = 49;
		cout << endl;
		cout << obtenerColumna(x) << endl;
		/*cout << "Archivo a encriptar: " << argv[1] << endl;
		vector<unsigned char*> a = leerBytes(argv[1]);
		escribirBytes(a,argv[2]);
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
		}*/
	}
	else{
		cout << "./a.out nombreArchivoOriginal nombreArchivoEncriptado" << endl;
	}
	return 0;
}
