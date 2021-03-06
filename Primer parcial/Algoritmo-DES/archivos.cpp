#include "archivos.hpp"  

using namespace std;
using namespace archivos;

namespace archivos{
	size_t tamanio;
}

vector<bitset<64>*> archivos::leerArchivo(string nombre){
	size_t numeroDeBytesLeidos;
	vector<bitset<64>*> binario;
	bitset<64>* bytesLeidos = new (nothrow)bitset<64>();
	try{
		ifstream input(nombre,std::ios::binary|std::ios::ate);
		if(input.is_open()){
			input.seekg(0, ios_base::end);
			numeroDeBytesLeidos = input.tellg();
			tamanio = numeroDeBytesLeidos;
			cout << "Se leyeron " << numeroDeBytesLeidos << " bytes." << endl;
			input.seekg(0, ios::beg);
			while(numeroDeBytesLeidos > 0){
				if(numeroDeBytesLeidos >= 8){
					input.read((char*)bytesLeidos, 8);
					binario.reserve(1);
					binario.push_back(new bitset<64>(*bytesLeidos));
					bytesLeidos->reset();
					numeroDeBytesLeidos -= 8;
				}
				else{
					input.read((char *)bytesLeidos, numeroDeBytesLeidos);
					binario.reserve(1);
					binario.push_back(new bitset<64>(*bytesLeidos));
					numeroDeBytesLeidos -= 8;
					bytesLeidos->reset();
					break;
				}
			}
			input.close();
		}
		else{
			cout << "No se pudo abrir el archivo." << endl;
			return binario;
		}
		return binario;
	
	}
	catch(const std::invalid_argument& ia){
		cerr << "Invalid argument: " << ia.what() << '\n';
		return binario;
	}	
}

void archivos::escribirArchivo(vector<bitset<64>*> bytes, string nombre, int tamanioBytes){
	try{
		int i = 0;
		ofstream archivoEncriptado (nombre, ios::binary);
		if(archivoEncriptado.is_open()){
			while(tamanioBytes > 0){
				if(tamanioBytes >= 8){
					archivoEncriptado.write((const char*)bytes[i], 8);
					tamanioBytes -= 8;
					i++;
				}
				else{
					archivoEncriptado.write((const char*)bytes[i], tamanioBytes);
					tamanioBytes -= 8;
					i++;
					break;
				}
			}
			archivoEncriptado.close();
		}
		else{
			cout << "Error al crear el archivo." << endl;
			return;
		}
	}
	catch(const std::invalid_argument& ia){
		cerr << "Invalid argument: " << ia.what() << '\n';
		return;
	}
}

void archivos::establecerTamanio(int valor){
	archivos::tamanio = valor;
}

int archivos::obtenerTamanio(){
	return archivos::tamanio;
}

