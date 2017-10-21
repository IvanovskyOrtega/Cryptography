#ifndef _DES_HPP_
#define _DES_HPP_

#include <bitset>
#include <vector>
#include <string>
#include "bits.hpp"

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
}

#endif
