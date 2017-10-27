#include "des.hpp"
#include "archivos.hpp"
#include "tiempo.hpp"

using namespace std;
using namespace archivos;
using namespace des;
using namespace tiempo;
using namespace bits;

int main (int argc, char* argv[]) {
	if(argc >= 3){
		double usertime1,systime1,walltime1,usertime2,systime2,walltime2;
		unsigned int bytesLeidos = 0;
		ifstream* archivoOriginal = new ifstream();
		ofstream* archivoEncriptado = new ofstream();
		vector<u64*> programaDeLlaves;
		uswtime(&usertime1,&systime1,&walltime1);
		programaDeLlaves = generarProgramaDeLlaves();
		cout << "Se genero el programa de llaves" << endl;
		u64 textoPlano;
		uchar* textoPlanoAux = new uchar[8];
		u64* textoCifrado = new u64();
		uchar* aux = new uchar();
		vector<uchar*> bytes;
		abrirArchivoLectura(archivoOriginal,argv[1]);
		abrirArchivoEscritura(archivoEncriptado,argv[2]);
		for(unsigned int i = 0 ; i < tamanio/8 ; i++){
			textoPlanoAux = leerBytes(archivoOriginal);
			textoPlano = uchar_to_u64(textoPlanoAux);
			(*textoCifrado) = iniciarEncriptacionDES(textoPlano, programaDeLlaves);
			escribirBytesU64(archivoEncriptado,textoCifrado);
			bytesLeidos+=8;
 		}
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
		uswtime(&usertime2,&systime2,&walltime2);
		printf("TR: %.10e\n",walltime2-walltime1);
	}
	else{
		cout << "./a.out nombreArchivoOriginal nombreArchivoEncriptado" << endl;
	}
	return 0;
}
