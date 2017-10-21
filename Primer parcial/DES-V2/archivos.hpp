#ifndef _ARCHIVOS_HPP_
#define _ARCHIVOS_HPP_

#include <bitset>         
#include <vector>
#include <string>
#include <stdexcept>      
#include <fstream>
#include <iostream>
#include "bits.hpp"

namespace archivos{
    typedef unsigned char uchar;
    extern size_t tamanio;
    std::vector<std::bitset<64>*> leerArchivo(std::string nombre);
    std::vector<uchar*> leerBytes(std::string nombre);
    void escribirArchivo(std::vector<std::bitset<64>*> bytes, std::string nombre, int tamanioBytes);
    void escribirBytes(std::vector<uchar*> bytes, std::string nombre);
    void establecerTamanio(int valor);
    int obtenerTamanio();
}

#endif