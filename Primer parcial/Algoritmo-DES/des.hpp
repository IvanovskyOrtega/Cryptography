#ifndef _DES_HPP_
#define _DES_HPP_

#include <bitset>
#include <vector>
#include <string>

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
    std::bitset<64>* aplicarPermutacionInicial(std::bitset<64>* textoPlano);
    std::bitset<64>* aplicarPermutacionInicialInversa(std::bitset<64>* textoPlano);
    std::bitset<32>* obtenerLn(std::bitset<64>* texto);
    std::bitset<32>* obtenerRn(std::bitset<64>* texto);
    std::bitset<64>* concatenarLnRn(std::bitset<32>* Ln, std::bitset<32>* Rn);
    std::bitset<48>* aplicarExpansion(std::bitset<32>* texto);
    std::bitset<48>* aplicarXORConLlave(std::bitset<48>* texto, std::bitset<48>* llave);
    std::vector<std::bitset<6>> obtenerBloques(std::bitset<48>* texto);
    std::bitset<2> obtenerRenglon(std::bitset<6> bloque);
    std::bitset<4> obtenerColumna(std::bitset<6> bloque);
    int obtenerValorDeCaja(int numeroDeBloque, int renglon, int columna);
    std::bitset<4> enteroABinario(int valor);
    std::bitset<32>* aplicarCajas(std::bitset<48>* texto);
    std::bitset<32>* aplicarPermutacionP(std::bitset<32>* texto);
    std::bitset<32>* aplicarXORLmRn(std::bitset<32>* Ln, std::bitset<32>*Rn);
    std::bitset<64>* leerLlaveMaestra();
    std::bitset<56>* aplicarPermutacionPC1(std::bitset<64>* llaveMaestra);
    std::bitset<28>* obtenerCn(std::bitset<56>* CnDn);
    std::bitset<28>* obtenerDn(std::bitset<56>* CnDn);
    std::bitset<28>* aplicarCorrimientoCircular(std::bitset<28>* texto, int numeroDeCorrimientos);
    std::bitset<56>* concatenarCnDn(std::bitset<28>* Cn, std::bitset<28>* Dn);
    std::bitset<48>* aplicarPermutacionPC2(std::bitset<56>* CnDn);
    std::vector<std::bitset<48>*> generarProgramaDeLlaves();
    std::bitset<64>* iniciarEncriptacionDES(std::bitset<64>* textoPlano, std::vector<std::bitset<48>*> programaDeLlaves);
    void iniciarDecriptacionDES();
}

#endif
