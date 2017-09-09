#ifndef _DES_HPP_
#define _DES_HPP_

namespace des{
   extern int permutacionInicial[8][8];
   extern int permutacionInicialInversa[8][8];
   extern int seleccionEBit[8][6];
   extern int permutacionP[8][4];
   std::bitset<64>* aplicarPermutacionInicial(std::bitset<64>* textoPlano);
   std::bitset<32>* obtenerLn(std::bitset<64>* texto);
   std::bitset<32>* obtenerRn(std::bitset<64>* texto);
   std::bitset<64>* concatenarLnRn(std::bitset<32>* Ln, std::bitset<32>* Rn);
   std::bitset<48>* aplicarExpansion(std::bitset<32>* texto);
   std::bitset<48>* aplicarXORConLlave(std::bitset<48>* texto, std::bitset<48>* llave);
   std::bitset<32>* aplicarCajas(std::bitset<48>* texto);
   std::bitset<32>* aplicarPermutacionP(std::bitset<32>* texto);
   std::bitset<32>* aplicarXORLnRn(std::bitset<32>* Ln, std::bitset<32>*Rn);
   std::bitset<64>* leerLlaveMaestra();
   std::bitset<56>* aplicarPermutacionPC1(std::bitset<64>* llaveMaestra);
   std::bitset<28>* obtenerCn(std::bitset<56>* llave);
   std::bitset<28>* obtenerDn(std::bitset<56>* llave);
   std::bitset<28>* aplicarCorrimientoCircular(std::bitset<56>* texto);
   std::bitset<56>* concatenarCnDn(std::bitset<28>* Ln, std::bitset<28>* Rn);
   std::bitset<48>* aplicarPermutacionPC2(std::bitset<56>* CnDn);
}

#endif
