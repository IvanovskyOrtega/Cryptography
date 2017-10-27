#ifndef _ARCHIVOS_HPP_
#define _ARCHIVOS_HPP_
       
#include <vector>
#include <string>
#include <stdexcept>      
#include <fstream>
#include <iostream>
#include "bits.hpp"

namespace archivos{
    typedef uint64_t u64;
    typedef unsigned char uchar;
    extern size_t tamanio;
    void abrirArchivoLectura(std::ifstream* archivo, std::string nombre);
    void abrirArchivoEscritura(std::ofstream* archivo, std::string nombre);
    uchar* leerBytes(std::ifstream* archivo);
    void escribirBytes(std::ofstream* archivo, std::vector<uchar*> bytes, int numeroDeBytes);
    void escribirBytesU64(std::ofstream* archivo, u64* bytes);
    u64 uchar_to_u64(uchar* bytes);
}

#endif
