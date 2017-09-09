#ifndef _DES_HPP_
#define _DES_HPP_

namespace des{
   
    extern int permutacionInicial[64];
    extern int permutacionInicialInversa[64];
    extern int seleccionEBit[48];
    extern int permutacionP[32];
    extern int cajas[8][4][16];
    extern int permutacionPC1[56];
    extern int permutacionPC2[48];
    std::bitset<64>* aplicarPermutacionInicial(std::bitset<64>* textoPlano);
    std::bitset<32>* obtenerLn(std::bitset<64>* texto);
    std::bitset<32>* obtenerRn(std::bitset<64>* texto);
    std::bitset<64>* concatenarLnRn(std::bitset<32>* Ln, std::bitset<32>* Rn);
    std::bitset<48>* aplicarExpansion(std::bitset<32>* texto);
    std::bitset<48>* aplicarXORConLlave(std::bitset<48>* texto, std::bitset<48>* llave);
    std::bitset<32>* aplicarCajas(std::bitset<48>* texto);
    std::bitset<32>* aplicarPermutacionP(std::bitset<48>* texto);
    std::bitset<32>* aplicarXORLmRn(std::bitset<32>* Ln, std::bitset<32>*Rn);
    std::bitset<64>* leerLlaveMaestra();
    std::bitset<56>* aplicarPermutacionPC1(std::bitset<64>* llaveMaestra);
    std::bitset<28>* obtenerCn(std::bitset<56>* llave);
    std::bitset<28>* obtenerDn(std::bitset<56>* llave);
    std::bitset<28>* aplicarCorrimientoCircular(std::bitset<28>* texto, int numeroDeCorrimientos);
    std::bitset<56>* concatenarCnDn(std::bitset<28>* Cn, std::bitset<28>* Dn);
    std::bitset<48>* aplicarPermutacionPC2(std::bitset<56>* CnDn);
}

#endif
