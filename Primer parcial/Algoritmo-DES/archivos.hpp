#ifndef _ARCHIVOS_HPP_
#define _ARCHIVOS_HPP_

#include <bitset>         
#include <string>
#include <stdexcept>      
#include <fstream>
#include <iostream>

namespace archivos{
    extern int tamanio;
    const int MAX_SIZE = 2147483647; // 2 megabytes maximo
    std::bitset<MAX_SIZE>* leerArchivo(std::string nombre);
    void escribirArchivo(std::bitset<MAX_SIZE>* bits, std::string nombre, int tamanioBits);
    void establecerTamanio(int valor);
    int obtenerTamanio();
}

#endif