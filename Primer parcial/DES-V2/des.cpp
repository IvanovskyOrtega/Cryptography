#include <iostream>
#include <fstream>
#include "des.hpp"

using namespace std;
using namespace des;
using namespace bits;

/**
    Las matrices definidas aqui, son las matrices
    de permutacion propuestas en el algoritmo DES.
**/
namespace des{
    int permutacionInicial[64] = {
        58, 50, 42, 34, 26, 18, 10, 2,
        60, 52, 44, 36, 28, 20, 12, 4,
        62, 54, 46, 38, 30, 22, 14, 6,
        64, 56, 48, 40, 32, 24, 16, 8,
        57, 49, 41, 33, 25, 17,  9, 1,
        59, 51, 43, 35, 27, 19, 11, 3,
        61, 53, 45, 37, 29, 21, 13, 5,
        63, 55, 47, 39, 31, 23, 15, 7
    };
    
    int permutacionInicialInversa[64] = {
        40, 8,  48, 16, 56, 24, 64, 32,
        39, 7,  47, 15, 55, 23, 63, 31,
        38, 6,  46, 14, 54, 22, 62, 30,
        37, 5,  45, 13, 53, 21, 61, 29,
        36, 4,  44, 12, 52, 20, 60, 28,
        35, 3,  43, 11, 51, 19, 59, 27,
        34, 2,  42, 10, 50, 18, 58, 26,
        33, 1,  41,  9, 49, 17, 57, 25
    };
    
    int seleccionEBit[48] = {
        32,  1,  2,  3,  4,  5,
         4,  5,  6,  7,  8,  9,
         8,  9, 10, 11, 12, 13,
        12, 13, 14, 15, 16, 17,
        16, 17, 18, 19, 20, 21,
        20, 21, 22, 23, 24, 25,
        24, 25, 26, 27, 28, 29,
        28, 29, 30, 31, 32,  1
    };
    
    int permutacionP[32] = {
        16,  7, 20, 21,
        29, 12, 28, 17,
         1, 15, 23, 26,
         5, 18, 31, 10,
         2,  8, 24, 14,
        32, 27,  3,  9,
        19, 13, 30,  6,
        22, 11,  4, 25
    };
    int cajaS1[4][16] = 
    {
        14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7,
        0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8,
        4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0,
        15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13
    };
    int cajaS2[4][16] = 
    {
        15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10,
        3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5,
        0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15,
        13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9
    };
    int cajaS3[4][16] = 
    {
        10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8,
        13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1,
        13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7,
        1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12
    };
    int cajaS4[4][16] = 
    {
        7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15,
        13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9,
        10,6,9,0,12,11,7,13,13,1,3,14,5,2,8,4,
        3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14
    };
    int cajaS5[4][16] = 
    {
        2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9,
        14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6,
        4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14,
        11,8,15,7,1,14,2,13,6,15,0,9,10,4,5,3
    };
    int cajaS6[4][16] = 
    {
        12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11,
        10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8,
        9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6,
        4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13
    };
    int cajaS7[4][16] = 
    {
        4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1,
        13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6,
        1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2,
        6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12
    };
    int cajaS8[4][16] = 
    {
        13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7,
        1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2,
        7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8,
        2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11
    };
    int permutacionPC1[56] = {
        57, 49, 41, 33, 25, 17,  9,
         1, 58, 50, 42, 34, 26, 18,
        10,  2, 59, 51, 43, 35, 27,
        19, 11,  3, 60, 52, 44, 36,
        63, 55, 47, 39, 31, 23, 15,
         7, 62, 54, 46, 38, 30, 22,
        14,  6, 61, 53, 45, 37, 29,
        21, 13, 5 , 28, 20, 12,  4
    };
    int permutacionPC2[48] = {
        14, 17, 11, 24,  1,  5,
         3, 28, 15,  6, 21, 10,
        23, 19, 12,  4, 26,  8,
        16,  7, 27, 20, 13,  2,
        41, 52, 31, 37, 47, 55,
        30, 40, 51, 45, 33, 48,
        44, 49, 39, 56, 34, 53,
        46, 42, 50, 36, 29, 32
    };
    int tablaDeCorrimientos[16] = {
        1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1
    };
}

uchar* des::aplicarPermutacionInicial(uchar* textoPlano){
    uchar* textoPlanoAuxiliar = new uchar[8];
    inicializarBytes(textoPlanoAuxiliar,8);
    int k = 0;
    int bit;
    for(int i = 0 ; i < 8 ; i++){
        for(int j = 7 ; j >= 0 ; j--){
            bit = permutacionInicial[k];
            if(consultarBit(textoPlano[numeroDeByte(bit)],bitPos(bit)))
                poner1(&textoPlanoAuxiliar[i],j);
            else
                poner0(&textoPlanoAuxiliar[i],j); 
            k++; 
        }
    }
    return textoPlanoAuxiliar;
}

int des::numeroDeByte(int valor){
    if(valor >= 1 && valor <=8){
        return 0;
    }
    else if(valor >= 9 && valor <=16){
        return 1;
    }
    else if(valor >= 17 && valor <=24){
        return 2;
    }
    else if(valor >= 25 && valor <=32){
        return 3;
    }
    else if(valor >= 33 && valor <=40){
        return 4;
    }
    else if(valor >= 41 && valor <=48){
        return 5;
    }
    else if(valor >= 49 && valor <=56){
        return 6;
    }
    else if(valor >= 57 && valor <=64){
        return 7;
    }
    return -1;
}

int des::bitPos(int valor){
    switch(valor){
        case 1:
        case 9:
        case 17:
        case 25:
        case 33:
        case 41:
        case 49:
        case 57:
            return 7;
        case 2:
        case 10:
        case 18:
        case 26:
        case 34:
        case 42:
        case 50:
        case 58:
            return 6; 
        case 3:
        case 11:
        case 19:
        case 27:
        case 35:
        case 43:
        case 51:
        case 59:
            return 5;
        case 4:
        case 12:
        case 20:
        case 28:
        case 36:
        case 44:
        case 52:
        case 60:
            return 4;
        case 5:
        case 13:
        case 21:
        case 29:
        case 37:
        case 45:
        case 53:
        case 61:
            return 3;
        case 6:
        case 14:
        case 22:
        case 30:
        case 38:
        case 46:
        case 54:
        case 62:
            return 2;
        case 7:
        case 15:
        case 23:
        case 31:
        case 39:
        case 47:
        case 55:
        case 63:
            return 1;
        case 8:
        case 16:
        case 24:
        case 32:
        case 40:
        case 48:
        case 56:
        case 64:
            return 0;
        default:
            return -1;
    }
}

uchar* des::aplicarPermutacionInicialInversa(uchar* textoPlano){
    uchar* textoPlanoAuxiliar = new uchar[8];
    inicializarBytes(textoPlanoAuxiliar,8);
    int k = 0;
    int bit;
    for(int i = 0 ; i < 8 ; i++){
        for(int j = 7 ; j >= 0 ; j--){
            bit = permutacionInicialInversa[k];
            if(consultarBit(textoPlano[numeroDeByte(bit)],bitPos(bit)))
                poner1(&textoPlanoAuxiliar[i],j);
            else
                poner0(&textoPlanoAuxiliar[i],j); 
            k++; 
        }
    }
    return textoPlanoAuxiliar;
}

uchar* des::obtenerLn(uchar* texto){
    uchar* Ln = new uchar[4];
    for(int i = 0; i < 4 ; i++){
        Ln[i] = texto[i];
    }
    return Ln;
}

uchar* des::obtenerRn(uchar* texto){
    uchar* Rn = new uchar[4];
    for(int i = 4; i < 8 ; i++){
        Rn[i-4] = texto[i];
    }
    return Rn;
}

uchar* des::concatenarLnRn(uchar* Ln, uchar* Rn){
    uchar* LnRn = new uchar[8];
    for(int i = 0; i < 4 ; i++){
        Rn[i] = Ln[i];
    }
    for(int i = 4; i < 8 ; i++){
        Rn[i] = Rn[i-4];
    }
    return LnRn;
}

uchar* des::aplicarExpansion(uchar* texto){
    uchar* expansion = new uchar[6];
    inicializarBytes(expansion,6);
    int k = 0;
    int bit;
    for(int i = 0 ; i < 6 ; i++){
        for(int j = 7 ; j >= 0 ; j--){
            bit = seleccionEBit[k];
            if(consultarBit(texto[numeroDeByte(bit)],bitPos(bit)))
                poner1(&expansion[i],j);
            else
                poner0(&expansion[i],j); 
            k++; 
        }
    }
    return expansion;
}

uchar* des::aplicarXORConLlave(uchar* texto, uchar* llave){
    uchar* resultado = new uchar[6];
    for(int i = 0 ; i < 6 ; i++){
         resultado[i] = texto[i]^llave[i];
    }
    return resultado;
}

uchar* des::obtenerBloques(uchar* texto){
    //00110101|11100111|10010101|11110000|00111100|01110010
    //001101|011110|011110|010101|111100|000011|110001|110010
    uchar* bloques = new uchar[8];
    bloques[0] = texto[0]>>2;
    bloques[1] = (texto[0]<<4)^(texto[1]>>4);
    poner0(&bloques[1],7);
    poner0(&bloques[1],6);
    bloques[2] = (texto[1]<<2)^(texto[1]>>6);
    poner0(&bloques[2],7);
    poner0(&bloques[2],6);
    bloques[3] = texto[3];
    poner0(&bloques[3],7);
    poner0(&bloques[3],6);
    bloques[4] = texto[4]>>2;
    bloques[5] = (texto[3]<<4)^(texto[4]>>4);
    poner0(&bloques[5],7);
    poner0(&bloques[5],6);
    bloques[6] = (texto[4]<<2)^(texto[5]>>6);
    poner0(&bloques[6],7);
    poner0(&bloques[6],6);
    bloques[7] = texto[5];
    poner0(&bloques[7],7);
    poner0(&bloques[7],6);
    return bloques;
}

int des::obtenerRenglon(uchar bloque){
    int a = (consultarBit(bloque,5))<<1;
    int b = (consultarBit(bloque,0));
    return a^b;
}

int des::obtenerColumna(uchar bloque){
    int a = (consultarBit(bloque,4))<<3;
    int b = (consultarBit(bloque,3))<<2;
    int c = (consultarBit(bloque,2))<<1;
    int d = (consultarBit(bloque,1));
    return a^b^c^d;
}

int des::obtenerValorDeCaja(int numeroDeBloque, int renglon, int columna){
    switch(numeroDeBloque){
        case 0:
            return cajaS1[renglon][columna];
        case 1:
            return cajaS2[renglon][columna];
        case 2:
            return cajaS3[renglon][columna];
        case 3:
            return cajaS4[renglon][columna];
        case 4:
            return cajaS5[renglon][columna];
        case 5:
            return cajaS6[renglon][columna];
        case 6:
            return cajaS7[renglon][columna];
        case 7:
            return cajaS8[renglon][columna];
        default:
            return -1;
    }
    return -1;
}

uchar* des::aplicarCajas(uchar* texto){
    int renglon;
    int columna;
    int* valoresDeCaja = new int[8];
    uchar* bloques = obtenerBloques(texto);
    uchar* textoDeSalida = new uchar[4];
    inicializarBytes(textoDeSalida,4);
    for(int i = 0 ; i < 8 ; i++){
        //cout << "Analizando bloque " << i << ": " << bloques[i] << endl;
        renglon = obtenerRenglon(bloques[i]);
        columna = obtenerColumna(bloques[i]);
        //cout << "Renglon: " << renglon << " " << posRenglon << ", Columna: "<< columna << " " << posColumna << endl;
        valoresDeCaja[i] = obtenerValorDeCaja(i,renglon,columna);
        //cout << "Valor de caja: "<< valorDeCaja << endl;
    }
    //cout << "Cajas: " << (*textoDeSalida) << endl;
    return textoDeSalida;
}