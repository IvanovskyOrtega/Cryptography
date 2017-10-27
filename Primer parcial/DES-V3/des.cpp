#include "des.hpp"

using namespace std;
using namespace des;
using namespace bits;

/**
    Las matrices definidas aqui, son las matrices
    de permutacion propuestas en el algoritmo DES.
**/
namespace des{
    u64 binario;
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
    u32 cajaS1[4][16] = 
    {
        14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7,
        0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8,
        4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0,
        15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13
    };
    u32 cajaS2[4][16] = 
    {
        15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10,
        3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5,
        0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15,
        13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9
    };
    u32 cajaS3[4][16] = 
    {
        10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8,
        13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1,
        13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7,
        1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12
    };
    u32 cajaS4[4][16] = 
    {
        7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15,
        13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9,
        10,6,9,0,12,11,7,13,13,1,3,14,5,2,8,4,
        3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14
    };
    u32 cajaS5[4][16] = 
    {
        2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9,
        14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6,
        4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14,
        11,8,15,7,1,14,2,13,6,15,0,9,10,4,5,3
    };
    u32 cajaS6[4][16] = 
    {
        12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11,
        10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8,
        9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6,
        4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13
    };
    u32 cajaS7[4][16] = 
    {
        4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1,
        13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6,
        1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2,
        6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12
    };
    u32 cajaS8[4][16] = 
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
    int bitPos[64] = {
        63,62,61,60,59,58,57,56,
        55,54,53,52,51,50,49,48,
        47,46,45,44,43,42,41,40,
        39,38,37,36,35,34,33,32,
        31,30,29,28,27,26,25,24,
        23,22,21,20,19,18,17,16,
        15,14,13,12,11,10, 9, 8,
         7, 6, 5, 4, 3, 2, 1, 0
    };
}


void des::error(std::string error);

void des::aplicarPermutacionInicial(u64* textoPlano){
    u64 aux = *textoPlano;
    for(int i = 0 ; i < 64 ; i++){
        if(consultarBit(aux,bitPos[permutacionInicial[i]-1]))
            poner1(textoPlano,63-i);
        else
            poner0(textoPlano,63-i); 
    }
}

void des::aplicarPermutacionInicialInversa(u64* textoPlano){
    u64 aux = *textoPlano;
    for(int i = 0 ; i < 64 ; i++){
        if(consultarBit(aux,bitPos[permutacionInicialInversa[i]-1]))
            poner1(textoPlano,63-i);
        else
            poner0(textoPlano,63-i); 
    }
}
u32 des::obtenerLn(u64 texto){
    u32 Ln = 0;
    Ln = (texto>>32)^Ln;
    return Ln;
}

u32 des::obtenerRn(u64 texto){
    u32 Ln = 0;
    Ln = ((texto<<32)>>32)^Ln;
    return Ln;
}

u64 des::concatenarLnRn(u32 Ln, u32 Rn){
    u64 LnRn = 0;
    u64 aux1 = (u64)Ln;
    u64 aux2 = (u64)Rn;
    LnRn = (aux1<<32)^(aux2);
    return LnRn;
}

u64 des::aplicarExpansion(u32 texto){
    u64 expansion = 0;
    for(int i = 0 ; i < 48 ; i++){
        if(consultarBit(texto,bitPos[seleccionEBit[i]+31]))
            poner1(&expansion,47-i);
        else
            poner0(&expansion,47-i); 
    }
    return expansion;
}

void des::aplicarXORConLlave(u64* texto, u64 llave){
    (*texto) = (*texto)^llave;
}

uchar* des::obtenerBloques(u64 texto){
    uchar* bloques = new uchar[8];
    bloques[0] = texto>>42;
    bloques[1] = (texto<<22)>>58;
    bloques[2] = (texto<<28)>>58;
    bloques[3] = (texto<<34)>>58;
    bloques[4] = (texto<<40)>>58;
    bloques[5] = (texto<<46)>>58;
    bloques[6] = (texto<<52)>>58;
    bloques[7] = (texto<<58)>>58;
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

u32 des::obtenerValorDeCaja(int numeroDeBloque, int renglon, int columna){
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

u32 des::aplicarCajas(u64 texto){
    int renglon;
    int columna;
    u32* valoresDeCaja = new u32[8];
    uchar* bloques = obtenerBloques(texto);
    u32 textoDeSalida = 0x00000000;
    for(int i = 0 ; i < 8 ; i++){
        //cout << "Analizando bloque " << i << ": " << bloques[i] << endl;
        renglon = obtenerRenglon(bloques[i]);
        columna = obtenerColumna(bloques[i]);
        //cout << "Renglon: " << renglon << " " << posRenglon << ", Columna: "<< columna << " " << posColumna << endl;
        valoresDeCaja[i] = obtenerValorDeCaja(i,renglon,columna);
        //cout << "Valor de caja: "<< valorDeCaja << endl;
    }
    //cout << "Cajas: " << (*textoDeSalida) << endl;
    rellenarTextoDeSalida(&textoDeSalida,valoresDeCaja);
    return textoDeSalida;
}

void des::rellenarTextoDeSalida(u32* textoDeSalida, u32* valoresDeCaja){
    (*textoDeSalida) ^= (valoresDeCaja[0]<<28)^(valoresDeCaja[1]<<24);
    (*textoDeSalida) ^= (valoresDeCaja[2]<<20)^(valoresDeCaja[3]<<16);
    (*textoDeSalida) ^= (valoresDeCaja[4]<<12)^(valoresDeCaja[5]<<8);
    (*textoDeSalida) ^= (valoresDeCaja[6]<<4)^(valoresDeCaja[7]);
}

void des::aplicarPermutacionP(u32* texto){
    u32 aux = (*texto);
    for(int i = 0 ; i < 32 ; i++){
        if(consultarBit(aux,bitPos[permutacionP[i]+31]))
            poner1((u64*)texto,31-i);
        else
            poner0((u64*)texto,31-i); 
    }
}

u64 des::leerLlaveMaestra(){
    string cadenaLlave;
    u64 llaveMaestra = 0;
    ifstream llave(MASTER_KEY);
    if(llave.is_open()){
        getline(llave,cadenaLlave);
        llave.close();
        int tamanioLlave = cadenaLlave.size();
        if(tamanioLlave == 64){
            leerLlaveBinaria(&llaveMaestra,cadenaLlave);
        }
        else if(tamanioLlave == 16){
            leerLlaveHexadecimal(&llaveMaestra,cadenaLlave);
        }
        else if(tamanioLlave == 8){
            leerLlaveASCII(&llaveMaestra,cadenaLlave);
        }
        else{
            error("Formato de llave invalido");
        }
        return llaveMaestra;
    }
    else{
        error("No se pudo leer el archivo");
        exit(0);
    }
}

void des::error(string error){
    cout << "Error: " << error << endl;
}

bool des::esHexa(char c){
    switch(c){
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case 'a':
        case 'b':
        case 'c':
        case 'd':
        case 'e':
        case 'f':  
            return true;
        default:
            return false;
    }
}

bool des::esBinario(char c){
    if(c == '0'){
        binario = 0;
        return true;
    }
    else if(c == '1'){
        binario = 1;
        return true;
    }
    return false;
}

void des::leerLlaveBinaria(u64* llave, string cadenaLlave){
    int k = 0;
    for(int i = 63 ; i >= 0 ; i--){
        if(esBinario(cadenaLlave[k])){
            (*llave) = (*llave)^(binario<<i);
            k++;
        }
        else{
            error("Formato de Llave binaria invalido");
            exit(0);
        } 
    }
}

u64 des::getHexa(char c){
    switch(c){
        case '0': return 0;
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        case 'a': return 10;
        case 'b': return 11;
        case 'c': return 12;
        case 'd': return 13;
        case 'e': return 14;
        case 'f': return 15;
        default: return -1;
    }
}

void des::leerLlaveHexadecimal(u64* llave, string cadenaLlave){
    for(int i = 0 ; i < 16 ; i++){
        if(!esHexa(cadenaLlave[i])){
            error("Formato de llave hexadecimal invalido");
            exit(0);
        }
    }
    (*llave) ^= (getHexa(cadenaLlave[0])<<60)^(getHexa(cadenaLlave[1])<<56);
    (*llave) ^= (getHexa(cadenaLlave[2])<<52)^(getHexa(cadenaLlave[3])<<48);
    (*llave) ^= (getHexa(cadenaLlave[4])<<44)^(getHexa(cadenaLlave[5])<<40);
    (*llave) ^= (getHexa(cadenaLlave[6])<<36)^(getHexa(cadenaLlave[7])<<32);
    (*llave) ^= (getHexa(cadenaLlave[8])<<28)^(getHexa(cadenaLlave[9])<<24);
    (*llave) ^= (getHexa(cadenaLlave[10])<<20)^(getHexa(cadenaLlave[11])<<16);
    (*llave) ^= (getHexa(cadenaLlave[12])<<12)^(getHexa(cadenaLlave[13])<<8);
    (*llave) ^= (getHexa(cadenaLlave[14])<<4)^(getHexa(cadenaLlave[15]));
}

void des::leerLlaveASCII(u64* llave, string cadenaLlave){
    (*llave) ^= (u64)cadenaLlave[0]<<56;
    (*llave) ^= (u64)cadenaLlave[1]<<48;
    (*llave) ^= (u64)cadenaLlave[2]<<40;
    (*llave) ^= (u64)cadenaLlave[3]<<32;
    (*llave) ^= (u64)cadenaLlave[4]<<24;
    (*llave) ^= (u64)cadenaLlave[5]<<16;
    (*llave) ^= (u64)cadenaLlave[6]<<8;
    (*llave) ^= (u64)cadenaLlave[7];
}

u64 des::aplicarPermutacionPC1(u64 texto){
    u64 aux = 0; 
    for(int i = 0 ; i < 56 ; i++){
        if(consultarBit(texto,bitPos[permutacionPC1[i]-1]))
            poner1(&aux,55-i);
        else
            poner0(&aux,55-i); 
    }
    return aux;
}

u32 des::obtenerCn(u64 CnDn){
    return (u32)(CnDn>>28);
}

u32 des::obtenerDn(u64 CnDn){
    return (u32)((CnDn<<36)>>36);
}
void des::aplicarCorrimientoCircular(u32* texto, int numeroDeCorrimientos){
    (*texto) = (*texto) << numeroDeCorrimientos | (*texto) >> (28-numeroDeCorrimientos);
    if(numeroDeCorrimientos == 1){
        poner0((u64*)texto,28);
    }
    else{
        poner0((u64*)texto,28);
        poner0((u64*)texto,29);
    }
}
u64 des::concatenarCnDn(u32 Cn, u32 Dn){
    u64 cn = Cn;
    u64 dn = Dn;
    return (cn<<28)^(dn);
}
u64 des::aplicarPermutacionPC2(u64 CnDn){
    u64 aux = 0; 
    for(int i = 0 ; i < 48 ; i++){
        if(consultarBit(CnDn,bitPos[permutacionPC2[i]+7]))
            poner1(&aux,47-i);
        else
            poner0(&aux,47-i); 
    }
    return aux;
}

void des::imprimir64(u64 array, string cad){
    cout << cad << " ";
    imprimiru64(array);
    cout << endl;
}


void des::imprimir32(u32 array, string cad){
    cout << cad << " ";
    imprimiru32(array);
    cout << endl;
}

std::vector<u64*> des::generarProgramaDeLlaves(){
    vector<u64*> programaDeLlaves;
    u64 llaveMaestra = 0;
    u64 CnDn = 0;
    u64 llave = 0;
    u32 Cn = 0;
    u32 Dn = 0;
    llaveMaestra = leerLlaveMaestra();
    cout << "Se ha leido la llave" << endl;
    imprimir64(llaveMaestra,"MK:   ");
    CnDn = aplicarPermutacionPC1(llaveMaestra);
    Cn = obtenerCn(CnDn);   
    Dn = obtenerDn(CnDn);
    programaDeLlaves.reserve(16);
    for(int i = 0 ; i < 16 ; i++){
        aplicarCorrimientoCircular(&Cn,tablaDeCorrimientos[i]);
        aplicarCorrimientoCircular(&Dn,tablaDeCorrimientos[i]);
        CnDn = concatenarCnDn(Cn,Dn);
        llave = aplicarPermutacionPC2(CnDn);
        programaDeLlaves.push_back(new u64(llave));
    }
    return programaDeLlaves;
}
u64 des::iniciarEncriptacionDES(u64 textoPlano, std::vector<u64*> programaDeLlaves){
    u32 Ln;
    u32 Rn;
    u32 RnAux;
    u64 LnRn;
    u64 aux;
    aplicarPermutacionInicial(&textoPlano);
    //cout << "Inicia la encriptacion..." << endl;
    Ln = obtenerLn(textoPlano);
    Rn = obtenerRn(textoPlano);
    for(int i = 0 ; i < 16 ; i++){
        aux = aplicarExpansion(Rn);
        aplicarXORConLlave(&aux,(*programaDeLlaves[i]));
        RnAux = aplicarCajas(aux);
        aplicarPermutacionP(&RnAux);
        RnAux = Ln^RnAux;
        Ln = Rn;
        Rn = RnAux;
    }
    LnRn = concatenarLnRn(Rn,Ln);
    aplicarPermutacionInicialInversa(&LnRn);
    //cout << "Termino la encriptacion..." << endl;
    //cout << "El texto encriptado es:" << endl;
    //imprimiru64(LnRn);
    //cout << endl;
    cout << dec; // Regresamos la impresion a decimal*/
    return LnRn;
}
