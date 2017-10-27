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

namespace des{
    typedef unsigned char uchar;
    typedef uint64_t u64;
    typedef uint32_t u32;
    extern int permutacionInicial[64];
    extern int permutacionInicialInversa[64];
    extern int seleccionEBit[48];
    extern int permutacionP[32];
    extern u32 cajaS1[4][16];
    extern u32 cajaS2[4][16];
    extern u32 cajaS3[4][16];
    extern u32 cajaS4[4][16];
    extern u32 cajaS5[4][16];
    extern u32 cajaS6[4][16];
    extern u32 cajaS7[4][16];
    extern u32 cajaS8[4][16];
    extern int permutacionPC1[56];
    extern int permutacionPC2[48];
    extern int tablaDeCorrimientos[16];
    extern int bitPos[64];
    extern u64 binario;
    void error(std::string error);
    void aplicarPermutacionInicial(u64* textoPlano);
    void aplicarPermutacionInicialInversa(u64* textoPlano);
    u32 obtenerLn(u64 texto);
    u32 obtenerRn(u64 texto);
    u64 concatenarLnRn(u32 Ln, u32 Rn);
    u64 aplicarExpansion(u32 texto);
    void aplicarXORConLlave(u64* texto, u64 llave);
    uchar* obtenerBloques(u64 texto);
    int obtenerRenglon(uchar bloque);
    int obtenerColumna(uchar bloque);
    u32 obtenerValorDeCaja(int numeroDeBloque, int renglon, int columna);
    void rellenarTextoDeSalida(u32* textoDeSalida, u32* valoresDeCaja);
    u32 aplicarCajas(u64 texto);
    void aplicarPermutacionP(u32* texto);
    u64 leerLlaveMaestra();
    bool esHexa(char c);
    u64 getHexa(char c);
    bool esBinario(char c);
    void leerLlaveBinaria(u64* llave, std::string cadenaLlave);
    void leerLlaveHexadecimal(u64* llave, std::string cadenaLlave);
    void leerLlaveASCII(u64* llave, std::string cadenaLlave);
    u64 aplicarPermutacionPC1(u64 texto);
    u32 obtenerCn(u64 CnDn);
    u32 obtenerDn(u64 CnDn);
    void aplicarCorrimientoCircular(u32* texto, int numeroDeCorrimientos);
    u64 concatenarCnDn(u32 Cn, u32 Dn);
    u64 aplicarPermutacionPC2(u64 CnDn);
    std::vector<u64*> generarProgramaDeLlaves();
    u64 iniciarEncriptacionDES(u64 textoPlano, std::vector<u64*> programaDeLlaves);
    void imprimir64(u64 array, std::string cad);
    void imprimir32(u32 array, std::string cad);
}

#endif
