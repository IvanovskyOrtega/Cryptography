#include "archivos.hpp"  

using namespace std;
using namespace bits;
using namespace archivos;

namespace archivos{
	size_t tamanio;
}

void archivos::abrirArchivoLectura(ifstream* archivo, string nombre){
	try{
		archivo->open(nombre, ios::binary);
		if(archivo->is_open()){
			cout << "Archivo original se abrio correctamente" << endl;
			archivo->seekg(0, ios::end);
			tamanio = archivo->tellg();
			cout << "Se leyeron " << tamanio << " bytes." << endl;
			archivo->seekg(0, ios::beg);
		}
		else{
			cout << "Error al abrir " << nombre <<  endl;
			exit(0);
		}
	}catch(const std::invalid_argument& ia){
		cerr << "Invalid argument: " << ia.what() << '\n';
		exit(0);
	}
}

void archivos::abrirArchivoEscritura(ofstream* archivo, string nombre){
	try{
		archivo->open(nombre, std::ios::binary|std::ios::ate);
		if(archivo->is_open()){
			cout << "Archivo de salida se abrio correctamente" << endl;
		}
		else{
			cout << "Error al abrir " << nombre <<  endl;
			exit(0);
		}
	}catch(const std::invalid_argument& ia){
		cerr << "Invalid argument: " << ia.what() << '\n';
		exit(0);
	}
}

uchar* archivos::leerBytes(ifstream* archivo){
	int i = 0;
	uchar* aux = new uchar();
	uchar * buffer = new uchar[8];
	try{
		if(archivo->good()){
			while(i < 8){
					archivo->read((char *)aux, 1);
					buffer[i] = (*aux);
					i++;
					return buffer;
			}
		}
		else{
			cout << "Error durante la lectura" << endl;
			exit(0);
		}
	}catch(const std::invalid_argument& ia){
		cerr << "Invalid argument: " << ia.what() << '\n';
		return buffer;
	}
	return buffer;
}

void archivos::escribirBytes(ofstream* archivo, vector<uchar*> bytes, int numeroDeBytes){
	int i = 0;
	try{
		if(archivo->good()){
			while(i < numeroDeBytes){
				archivo->write((const char*)bytes[i], 1);
				i++;
			}
		}
		else{
			cout << "Error durante la escritura" << endl;
			exit(0);
		}
	}catch(const std::invalid_argument& ia){
		cerr << "Invalid argument: " << ia.what() << '\n';
		exit(0);
	}
}

void archivos::escribirBytesU64(ofstream* archivo, u64* bytes){
	try{
		if(archivo->good()){
			archivo->write((const char*)bytes, 8);
		}
		else{
			cout << "Error durante la escritura" << endl;
			exit(0);
		}
	}catch(const std::invalid_argument& ia){
		cerr << "Invalid argument: " << ia.what() << '\n';
		exit(0);
	}
}

u64 archivos::uchar_to_u64(uchar* bytes){
	u64 textoPlano = 0x0000000000000000;
	textoPlano ^= (u64)bytes[0]<<56;
	textoPlano ^= (u64)bytes[1]<<48;
	textoPlano ^= (u64)bytes[2]<<40;
	textoPlano ^= (u64)bytes[3]<<32;
	textoPlano ^= (u64)bytes[4]<<24;
	textoPlano ^= (u64)bytes[5]<<16;
	textoPlano ^= (u64)bytes[6]<<8;
	textoPlano ^= (u64)bytes[7];
	return textoPlano;
}
