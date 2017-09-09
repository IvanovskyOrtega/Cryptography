#include "archivos.hpp"  

using namespace std;
using namespace archivos;

namespace archivos{
	int tamanio;
}
bitset<MAX_SIZE>* archivos::leerArchivo(string nombre){
	int numeroDeBitsLeidos;
	bitset<MAX_SIZE>* bitsLeidos = new (nothrow)bitset<MAX_SIZE>();
	try{
        	ifstream input(nombre,ios::binary);
		input.seekg(0, ios::end);
		numeroDeBitsLeidos = input.tellg();
		tamanio = numeroDeBitsLeidos;
		cout << "Se leyeron " << tamanio << " bits." << endl;
		input.seekg(0, ios::beg);
        	input.read((char*)bitsLeidos, numeroDeBitsLeidos);
        	input.close();
		return bitsLeidos;
	
	}
	catch(const std::invalid_argument& ia){
		cerr << "Invalid argument: " << ia.what() << '\n';
		return bitsLeidos;
	}	
}

void archivos::escribirArchivo(bitset<MAX_SIZE>* bits, string nombre, int tamanioBits){
	try{
		ofstream archivoEncriptado (nombre, ios::binary);
        	archivoEncriptado.write((const char*)bits, tamanioBits);
        	archivoEncriptado.close();
	}
	catch(const std::invalid_argument& ia){
		cerr << "Invalid argument: " << ia.what() << '\n';
	}
}

void archivos::establecerTamanio(int valor){
	archivos::tamanio = valor;
}

int archivos::obtenerTamanio(){
	return archivos::tamanio;
}
