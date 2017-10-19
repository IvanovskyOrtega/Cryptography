#include <iostream>
#include <fstream>
#include "des.hpp"

using namespace std;
using namespace des;

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

/**
    Esta funcion aplica la matriz de permutacion inicial al texto plano
    a encriptar.
    Recibe:
        bitset<64>* textoPlano : El texto plano a encriptar
    Regresa:
        bitset<64>* textoAuxiliar : El texto plano permutado.
    Nota: En un bitset el primer elemento no es el bit mas significativo
        (bit mas a la izquierda), por lo que en la mayoria de las funciones 
        de este programa manejan los elementos a la inversa a como uno lo 
        razonaria de forma natural. 
        Ejemplo:
            Si definimos un bitset<5> miBitset("01101") 
            miBitset[0] = 1, y no 0 como se pensaria.
            Asi entonces:
                miBitset[1] = 0
                miBitset[2] = 1
                miBitset[3] = 1
                miBitset[4] = 0
        Esto aplica para el resto de las funciones.
**/
bitset<64>* des::aplicarPermutacionInicial(bitset<64>* textoPlano){
    bitset<64>* textoPlanoAuxiliar = new (nothrow)bitset<64>();
    for(int i = 0 ; i < 64 ; i++){
        /**
            En este caso la matriz permutacionInicial tiene valores del
            1-64, pero recordando el orden de los bitsets, se hace 64 menos
            el valor obtenido de la matriz para obtener el bit en la posicion
            que se desea. (Aplica para las demas matrices).
        **/
        (*textoPlanoAuxiliar)[63-i] = (*textoPlano)[64-permutacionInicial[i]];
    }
    //cout << "IP: " << (*textoPlanoAuxiliar) << endl;
    return textoPlanoAuxiliar;
}

/**
    Esta matriz aplica la permutacion inicial inversa al texto plano
    que ha pasado despues de las 16 rondas definidas en el algoritmo 
    DES.
    Recibe:
        bitset<64>* textoPlano : El texto plano despues de 16 rondas
    Regresa:
        bitset<64>* textoAuxiliar : El texto plano permutado.
**/
bitset<64>* des::aplicarPermutacionInicialInversa(bitset<64>* textoPlano){
    bitset<64>* textoPlanoAuxiliar = new (nothrow)bitset<64>();
    for(int i = 0 ; i < 64 ; i++){
        (*textoPlanoAuxiliar)[63-i] = (*textoPlano)[64-permutacionInicialInversa[i]];
    }
    //cout << "IP-Inversa: " << (*textoPlanoAuxiliar) << endl;
    return textoPlanoAuxiliar;
}

/**
    Esta funcion obtiene la parte izquierda (L) de 32 bits del texto 
    plano procesado en las 16 rondas.
    Recibe:
        bitset<64>* texto : El texto 
    Regresa:
        bitset<32>* Ln : Parte izquierda (32 bits)
**/
bitset<32>* des::obtenerLn(bitset<64>* texto){
    bitset<32>* Ln = new (nothrow)bitset<32>();
    for(int i = 0; i < 32 ; i++){
        (*Ln)[i] = (*texto)[32+i];
    }
    //cout << "Ln: " << (*Ln) << endl;
    return Ln;
}


/**
    Esta funcion obtiene la parte derecha (R) de 32 bits del texto 
    plano procesado en las 16 rondas.
    Recibe:
        bitset<64>* texto : El texto 
    Regresa:
        bitset<32>* Ln : Parte derecha (32 bits)
**/
bitset<32>* des::obtenerRn(bitset<64>* texto){
    bitset<32>* Rn = new (nothrow)bitset<32>();
    for(int i = 0; i < 32 ; i++){
        (*Rn)[i] = (*texto)[i];
    }
    //cout << "Rn: " << (*Rn) << endl;
    return Rn;

}

/**
    Esta funcion concatena las partes izquierda y derecha, procesadas
    en las 16 rondas del algoritmo.
    Recibe:
        bitset<32>* Ln : Parte izquierda (32 bits)
        bitset<32>* Rn : Parte derecha (32 bits)
    Regresa:
        bitset<64>* LnRn : bitsets concatenados (64 bits)
**/
bitset<64>* des::concatenarLnRn(bitset<32>* Ln, bitset<32>* Rn){
    bitset<64>* LnRn = new (nothrow)bitset<64>();
    for(int i = 0; i < 32 ; i++){
        (*LnRn)[i] = (*Rn)[i];
    }
    for(int i = 32; i < 64 ; i++){
        (*LnRn)[i] = (*Ln)[i-32];
    }
    //cout << "LnRn: " << (*LnRn) << endl;
    return LnRn;
}

/**
    Esta funcion aplica la matriz de Expansion E-Bit a una cadena 
    de 32 bits (Dentro del algoritmo es a Rn a quien procesa).
    Recibe:
        bitset<32>* texto : Cadena a Expandir (32 bits)
    Regresa:
        bitset<48>* textoExpandido : Cadena expandida (48 bits)
**/
bitset<48>* des::aplicarExpansion(bitset<32>* texto){
    bitset<48>* textoExpandido = new (nothrow)bitset<48>();
    for(int i = 0 ; i < 48 ; i++){
        (*textoExpandido)[47-i] = (*texto)[32-seleccionEBit[i]];
    }
    //cout << "E(Rn): " << (*textoExpandido) << endl;
    return textoExpandido;
}

/**
    Esta funcion aplica la operacion XOR entre una cadena expandida
    (Rn, dentro del algoritmo) y una llave kn (generada en el programa
    de llaves).
    Recibe:
        bitset<48>* texto : Texto Expandido (48 bits)
        bitset<48>* llave : Llave del programa (32 bits)
    Regresa:
        bitset<48>* bitsetAuxiliar : Resultado de aplicar la XOR (48 bits)
**/
bitset<48>* des::aplicarXORConLlave(bitset<48>* texto, bitset<48>* llave){
    bitset<48>* bitsetAuxiliar = new (nothrow) bitset<48>();
    (*bitsetAuxiliar) = (*texto)^(*llave);
    //cout << "E(Rn) XOR Llave: " << (*bitsetAuxiliar) << endl;
    return bitsetAuxiliar;
}

/**
    Esta funcion obtiene los bloques a procesar en las cajas definidas
    en el algoritmo DES a partir del resultado de la XOR entre el texto
    expandido y la llave del programa.
    Recibe:
        bitset<48>* texto : Resultado de la XOR(texto,llave) (48 bits)
    Regresa:
        vector<bitset<6>> bloques : Vector de bloques de 6 bits (8 bloques)
**/
vector<bitset<6>> des::obtenerBloques(bitset<48>* texto){
    vector<bitset<6>> bloques;
    bitset<6> bloque;
    for(int i = 0 ; i < 48 ; i+=6){
        bloque[0] = (*texto)[42-i];
        bloque[1] = (*texto)[43-i];
        bloque[2] = (*texto)[44-i];
        bloque[3] = (*texto)[45-i];
        bloque[4] = (*texto)[46-i];
        bloque[5] = (*texto)[47-i];
        bloques.reserve(1);
        bloques.push_back(bloque);
        //cout << "Bloque " << (i/6) << ": " << bloque << endl; 
    }
    return bloques;
}

/**
    Esta funcion obtiene 2 bits de un bloque que definen la posicion
    del renglon de alguna de las matrices de cajas.
    Recibe:
        bitset<6> bloque : bloque de 6 bits 
    Regresa:
        bitset<2> renglon : bits que definen la posicion del renglon
**/
bitset<2> des::obtenerRenglon(bitset<6> bloque){
    bitset<2> renglon;
    renglon[0] = bloque[0];
    renglon[1] = bloque[5];
    return renglon;
}

/**
    Esta funcion obtiene 4 bits de un bloque que definen la posicion
    de la columna de alguna de las matrices de cajas.
    Recibe:
        bitset<6> bloque : bloque de 6 bits 
    Regresa:
        bitset<4> columna : bits que definen la posicion de la columna
**/
bitset<4> des::obtenerColumna(bitset<6> bloque){
    bitset<4> columna;
    columna[0] = bloque[1];
    columna[1] = bloque[2];
    columna[2] = bloque[3];
    columna[3] = bloque[4];
    return columna;
}

/**
    Esta funcion obtiene el valor de una matriz de caja.
    Recibe:
        int numeroDeBloque : El numero bloque de bits procesado en la
                             funcion de cajas (0-7).
        int renglon : El reglon de la matriz
        int columna : La columna de la matriz 
    Regresa:
        El valor consultado en la matriz de caja (0-15).
**/
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

/**
    Esta funcion convierte un valor entero a su representacion
    binaria. Dentro del algoritmo, se usar para convertir el valor
    obtenido de las cajas (0-15) en un binario de 4 bits (0000-1111).
    Recibe:
        int valor : Un entero (0-15)
    Regresa:
        bitset<4> binario : bitset equivalente al entero (4 bits)
**/
bitset<4> des::enteroABinario(int valor){
    bitset<4> binario(valor);
    return binario;
}

/**
    Esta funcion aplica las cajas a el resultado de la operacion
    XOR(textoExpandido,llaveDelPrograma).
    Recibe:
        bitset<48>* texto : El texto resultado de la XOR (48 bits)
    Regresa:
        bitset<32>* textoDeSalida : El texto obtenido de aplicar cajas (32 bits)
**/
bitset<32>* des::aplicarCajas(bitset<48>* texto){
    vector<bitset<6>> bloques = obtenerBloques(texto);
    bitset<32>* textoDeSalida = new (nothrow)bitset<32>();
    bitset<2> renglon;
    bitset<4> columna;
    bitset<4> bloqueCajeado;
    int posRenglon;
    int posColumna;
    int bit = 31;
    for(int i = 0 ; i < 8 ; i++){
        //cout << "Analizando bloque " << i << ": " << bloques[i] << endl;
        renglon = obtenerRenglon(bloques[i]);
        columna = obtenerColumna(bloques[i]);
        posRenglon = (int)renglon.to_ulong();
        posColumna = (int)columna.to_ulong();
        //cout << "Renglon: " << renglon << " " << posRenglon << ", Columna: "<< columna << " " << posColumna << endl;
        bloqueCajeado = enteroABinario(obtenerValorDeCaja(i,posRenglon,posColumna));
        //cout << "Bloque cajeado: "<< bloqueCajeado << endl;
        for(int j = 3 ; j >= 0 ; j--){
            (*textoDeSalida)[bit] = bloqueCajeado[j];
            bit--;
        }
    }
    //cout << "Cajas: " << (*textoDeSalida) << endl;
    return textoDeSalida;
}

/**
    Esta funcion aplica la matriz de permutacion P al texto obtenido 
    tras aplicar las cajas.
    Recibe:
        bitset<32>* texto : El texto obtenido de aplicar cajas
    Regresa:
        bitset<32>* bitsetAuxiliar : El texto permutado
**/
bitset<32>* des::aplicarPermutacionP(bitset<32>* texto){
    bitset<32>* bitsetAuxiliar = new (nothrow) bitset<32>();
    for(int i = 0 ; i < 32 ; i++){
        (*bitsetAuxiliar)[31-i] = (*texto)[32-permutacionP[i]];
    }
    return bitsetAuxiliar;
}

/**
    Esta funcion aplica la operacion XOR a dos bitsets de 32 bits.
    Recibe:
        bitset<32>* Ln : Ln procesado en las 16 rondas del algoritmo
        bitset<32>* Rn : El resultado de aplicar la matriz P al texto
                         de salida obtenido en cajas.
    Regresa:
        bitset<32>* bitsetAuxiliar : Ln XOR Rn
**/
bitset<32>* des::aplicarXORLmRn(bitset<32>* Ln, bitset<32>*Rn){
    bitset<32>* bitsetAuxiliar = new (nothrow) bitset<32>();
    (*bitsetAuxiliar) = (*Ln)^(*Rn);
    return bitsetAuxiliar;
}

/**
    Esta funcion lee una llave maestra contenida en un archivo txt
    de nombre "llave.txt".
    Recibe:
        sin argumentos...
    Regresa:
        bitset<64>* llaveMaestra : Llave maestra de 64 bits
**/
bitset<64>* des::leerLlaveMaestra(){
    bitset<64>* llaveMaestra = new (nothrow)bitset<64>();
    string cadenaLlave;
    ifstream llave("llave.txt");
    if(llave.is_open()){
        getline(llave,cadenaLlave);
        llave.close();
        if(cadenaLlave.size()==64){
            for(int i = 63 ; i >= 0 ; i--){
                if(cadenaLlave[63-i] == '1'){
                    (*llaveMaestra)[i] = 1;
                }
                else{
                    (*llaveMaestra)[i] = 0;
                }
            }
            return llaveMaestra;
        }
        else{
            cout << "El tamanio de la llave no es de 64 bits." << endl;
            return llaveMaestra;
        }
    }
    else{
        cout << "No se pudo leer el archivo." << endl;
        return llaveMaestra;
    }
}

/**
    Esta funcion aplica la matriz de permutacion PC1 a la llave maestra.
    Recibe:
        bitset<64>* llaveMaestra : La llave maestra (64 bits)
    Regresa:
        bitset<56>* bitsetAuxiliar : La llave permutada
**/
bitset<56>* des::aplicarPermutacionPC1(bitset<64>* llaveMaestra){
    bitset<56>* bitsetAuxiliar = new (nothrow)bitset<56>();
    for(int i = 0 ; i < 56 ; i++){
        (*bitsetAuxiliar)[55-i] = (*llaveMaestra)[64-permutacionPC1[i]];
    }
    //cout << "PC1: " << (*bitsetAuxiliar) << endl;
    return bitsetAuxiliar;
}

/**
    Esta funcion obtiene la parte izquierda de la cadena de bits
    CnDn.
    Recibe:
        bitset<56>* CnDn : bitset de 56 bits
    Regresa:
        bitset<28>* Cn : Parte izquierda de CnDn
**/
bitset<28>* des::obtenerCn(bitset<56>* CnDn){
    bitset<28>* Cn = new (nothrow)bitset<28>();
    for(int i = 0 ; i < 28 ; i++){
        (*Cn)[i] = (*CnDn)[28+i];
    }
    //cout << "Cn: " << (*Cn) << endl;
    return Cn;
}

/**
    Esta funcion obtiene la parte derecha de la cadena de bits
    CnDn.
    Recibe:
        bitset<56>* CnDn : bitset de 56 bits
    Regresa:
        bitset<28>* Dn : Parte derecha de CnDn
**/
bitset<28>* des::obtenerDn(bitset<56>* CnDn){
    bitset<28>* Dn = new (nothrow)bitset<28>();
    for(int i = 0 ; i < 28 ; i++){
        (*Dn)[i] = (*CnDn)[i];
    }
    //cout << "Dn: " << (*Dn) << endl;
    return Dn;
}

/**
    Esta funcion aplica corrimientos circulares a una cadena de bits
    definida en un bitset.
    Recibe:
        bitset<28>* texto : La cadena de bits (28 bits) 
        int numeroDeCorrimientos : Cantidad de corrimientos a realizar
    Regresa:
        bitset<28>* texto : El texto despues de aplicarle los corrimientos
**/
bitset<28>* des::aplicarCorrimientoCircular(bitset<28>* texto, int numeroDeCorrimientos){
    (*texto) = (*texto) << numeroDeCorrimientos | (*texto) >> (28-numeroDeCorrimientos);
    //cout << numeroDeCorrimientos <<" corrimientos: " << (*texto) << endl;
    return texto;
}

/**
    Esta funcion concatena las partes izquierda (Cn) y derecha (Dn)
    Recibe:
        bitset<28>* Cn : Parte izquierda (28 bits)
        bitset<28>* Dn : Parte derecha (28 bits)
    Regresa:
        bitset<56>* CnDn : bitsets concatenados (56 bits)
**/
bitset<56>* des::concatenarCnDn(bitset<28>* Cn, bitset<28>* Dn){
    bitset<56>* CnDn = new (nothrow)bitset<56>();
    for(int i = 0; i < 28 ; i++){
        (*CnDn)[i] = (*Dn)[i];
    }
    for(int i = 28; i < 56 ; i++){
        (*CnDn)[i] = (*Cn)[i-28];
    }
    return CnDn;
}

/**
    Esta funcion aplica la matriz de permutacion PC1 a la cadena
    de bits CnDn.
    Recibe:
        bitset<56>* CnDn : Cadena de bits CnDn (56 bits)
    Regresa:
        bitset<48>* llaveDelPrograma : Una de las llaves del Programa (48 bits)
**/
bitset<48>* des::aplicarPermutacionPC2(bitset<56>* CnDn){
    bitset<48>* llaveDelPrograma = new (nothrow)bitset<48>();
    for(int i = 0 ; i < 48 ; i++){
        (*llaveDelPrograma)[47-i] = (*CnDn)[56-permutacionPC2[i]];
    }
    return llaveDelPrograma;
}

/**
    Esta funcion genera el programa de llaves.
    Recibe:
        sin argumentos...
    Regresa:
        vector<bitset<48>*> programaDeLlaves : El programa de llaves
**/
vector<bitset<48>*> des::generarProgramaDeLlaves(){
    vector<bitset<48>*> programaDeLlaves;
    bitset<64>* llaveMaestra = new (nothrow)bitset<64>();
    bitset<56>* CnDn = new (nothrow)bitset<56>();
    bitset<48>* llave = new (nothrow)bitset<48>();
    bitset<28>* Cn = new (nothrow)bitset<28>();
    bitset<28>* Dn = new (nothrow)bitset<28>();
    llaveMaestra = leerLlaveMaestra();
    cout << "Se ha leido la llave: ";
    //cout << (*llaveMaestra) << endl;
    cout << hex << (*llaveMaestra).to_ulong() << endl;
    CnDn = aplicarPermutacionPC1(llaveMaestra);
    Cn = obtenerCn(CnDn);
    Dn = obtenerDn(CnDn);
    for(int i = 0 ; i < 16 ; i++){
        Cn = aplicarCorrimientoCircular(Cn,tablaDeCorrimientos[i]);
        Dn = aplicarCorrimientoCircular(Dn,tablaDeCorrimientos[i]);
        CnDn = concatenarCnDn(Cn,Dn);
        llave = aplicarPermutacionPC2(CnDn);
        programaDeLlaves.reserve(1);
        programaDeLlaves.push_back(llave);
        //cout << dec <<  "K" << i << ": " << (*llave) << endl; 
    }
    return programaDeLlaves;
}

/**
    Esta funcion encripta texto plano usando el algoritmo DES.
    Recibe: 
        bitset<64>* textoPlano : Texto plano a encriptar.
    Regresa:
        bitset<64>* LnRn : Texto encriptado.
**/
bitset<64>* des::iniciarEncriptacionDES(bitset<64>* textoPlano){
    vector<bitset<48>*> programaDeLlaves;
    bitset<32>* Ln = new (nothrow)bitset<32>();
    bitset<32>* Rn = new (nothrow)bitset<32>();
    bitset<32>* RnAux = new (nothrow)bitset<32>();
    bitset<64>* LnRn = new (nothrow)bitset<64>();
    bitset<48>* bitsetAuxiliar = new (nothrow)bitset<48>();
    cout << "Se generara el programa de llaves." << endl;
    programaDeLlaves = generarProgramaDeLlaves();
    cout << "Se genero el programa de llaves." << endl;
    textoPlano = aplicarPermutacionInicial(textoPlano);
    cout << "Inicia la encriptacion..." << endl;
    Ln = obtenerLn(textoPlano);
    Rn = obtenerRn(textoPlano);
    for(int i = 0 ; i < 16 ; i++){
        bitsetAuxiliar = aplicarExpansion(Rn);
        bitsetAuxiliar = aplicarXORConLlave(bitsetAuxiliar,programaDeLlaves[i]);
        RnAux = aplicarCajas(bitsetAuxiliar);
        RnAux = aplicarPermutacionP(RnAux);
        RnAux = aplicarXORLmRn(Ln,RnAux);
        Ln = Rn;
        Rn = RnAux;
    }
    LnRn = concatenarLnRn(Rn,Ln);
    LnRn = aplicarPermutacionInicialInversa(LnRn);
    cout << "Termino la encriptacion..." << endl;
    cout << "El texto encriptado es:" << endl;
    cout << hex << (*LnRn).to_ulong() << endl;
    cout << dec; // Regresamos la impresion a decimal
    return LnRn;
}
