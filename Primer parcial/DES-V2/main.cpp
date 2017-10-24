#include "des.hpp"
#include "archivos.hpp"

using namespace std;
using namespace archivos;
using namespace des;
using namespace bits;

int main (int argc, char* argv[]) {
	if(argc >= 3){
		unsigned int bytesLeidos = 0;
		ifstream* archivoOriginal = new ifstream();
		ofstream* archivoEncriptado = new ofstream();
		vector<uchar*> programaDeLlaves;
		programaDeLlaves = generarProgramaDeLlaves();
		cout << "Se genero el programa de llaves" << endl;
		uchar* textoPlano = new uchar[8];
		uchar* textoCifrado;
		uchar* aux = new uchar();
		vector<uchar*> bytes;
		abrirArchivoLectura(archivoOriginal,argv[1]);
		abrirArchivoEscritura(archivoEncriptado,argv[2]);
		for(unsigned int i = 0 ; i < tamanio/8 ; i++){
			textoPlano = leerBytes(archivoOriginal);
			textoCifrado = iniciarEncriptacionDES(textoPlano, programaDeLlaves);
			for(int j = 0 ; j < 8 ; j++){
				bytes.reserve(1);
				bytes.push_back(new uchar(textoCifrado[j]));
			}
			escribirBytes(archivoEncriptado,bytes,8);
			bytes.clear();
			bytes.resize(0);
			bytesLeidos+=8;
		}
		bytes.resize(0);
		if(bytesLeidos<tamanio){
			unsigned int bytesRestantes = tamanio-bytesLeidos;
			for(int i = 0 ; i < (int)bytesRestantes ; i++){
				archivoOriginal->read((char*)aux,1);
				bytes.reserve(1);
				bytes.push_back(new uchar((*aux)));
			}
			escribirBytes(archivoEncriptado,bytes,(int)bytesRestantes); 
		}
		archivoOriginal->close();
		archivoEncriptado->close();
	}
	else{
		cout << "./a.out nombreArchivoOriginal nombreArchivoEncriptado" << endl;
	}
	return 0;
}
