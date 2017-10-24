#ifndef _DES_HPP_
#define _DES_HPP_

#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <string>
#include "bits.hpp"
#include <cstdlib>

#define MASTER_KEY "mk.txt"

typedef unsigned char uchar;

namespace des{
    extern int permutacionInicial[64];
    extern int permutacionInicialInversa[64];
    extern int seleccionEBit[48];
    extern int permutacionP[32];
    extern int cajaS1[4][16];
    extern int cajaS2[4][16];
    extern int cajaS3[4][16];
    extern int cajaS4[4][16];
    extern int cajaS5[4][16];
    extern int cajaS6[4][16];
    extern int cajaS7[4][16];
    extern int cajaS8[4][16];
    extern int permutacionPC1[56];
    extern int permutacionPC2[48];
    extern int tablaDeCorrimientos[16];
    extern int binario;
    void error(std::string error);
    int bitPos(int valor);
    int numeroDeByte(int valor);
    uchar* aplicarPermutacionInicial(uchar* textoPlano);
    uchar* aplicarPermutacionInicialInversa(uchar* textoPlano);
    uchar* obtenerLn(uchar* texto);
    uchar* obtenerRn(uchar* texto);
    uchar* concatenarLnRn(uchar* Ln, uchar* Rn);
    uchar* aplicarExpansion(uchar* texto);
    uchar* aplicarXORConLlave(uchar* texto, uchar* llave);
    uchar* obtenerBloques(uchar* texto);
    int obtenerRenglon(uchar bloque);
    int obtenerColumna(uchar bloque);
    int obtenerValorDeCaja(int numeroDeBloque, int renglon, int columna);
    uchar* aplicarCajas(uchar* texto);
    void rellenarTextoDeSalida(uchar* textoDeSalida, int* valoresDeCaja);
    uchar* aplicarPermutacionP(uchar* texto);
    uchar* leerLlaveMaestra();
    bool esHexa(char c);
    int getHexa(char c);
    bool esBinario(char c);
    void leerLlaveBinaria(uchar* llave, std::string cadenaLlave);
    void leerLlaveHexadecimal(uchar* llave, std::string cadenaLlave);
    void leerLlaveASCII(uchar* llave, std::string cadenaLlave);
    uchar* aplicarPermutacionPC1(uchar* texto);
    uchar* obtenerCn(uchar* CnDn);
    uchar* obtenerDn(uchar* CnDn);
    uchar* aplicarCorrimientoCircular(uchar* texto, int numeroDeCorrimientos);
    uchar* aplicarUnCorrimiento(uchar* texto);
    uchar* aplicarDosCorrimientos(uchar* texto);
    uchar* concatenarCnDn(uchar* Cn, uchar* Dn);
    uchar* aplicarPermutacionPC2(uchar* CnDn);
    std::vector<uchar*> generarProgramaDeLlaves();
    uchar* iniciarEncriptacionDES(uchar* textoPlano, std::vector<uchar*> programaDeLlaves);
    void imprimir(uchar* array, int size, std::string cad);
}

#endif
