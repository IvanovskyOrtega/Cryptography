#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

void imprimirCadena(char *PT);
void generarCadenaAleatoria(char **PT);
void permutacionInicial(char **PT, char **IPPT);

int main(int argc, char *argv[]){
    char *PT; /** Texto plano **/
    char *IPPT; /** Permutación inicial **/
    PT = (char *)malloc(sizeof(char)*64);
    IPPT = (char *)malloc(sizeof(char)*64);
    cout << "Se generara la cadena de bits aleatoria." << endl;
    generarCadenaAleatoria(&PT);
    cout << "Se genero la cadena:" << endl;
    imprimirCadena(PT);
    cout << "Se aplicara la permutacion inicial." << endl;
    permutacionInicial(&PT, &IPPT);
    cout << "La nueva cadena es:" << endl;
    imprimirCadena(IPPT);
    return 0;
}
/**
    Esta función genera una cadena aleatoria de bits.
**/
void generarCadenaAleatoria(char **PT){
    srand(clock());
    for(int i = 0 ; i < 64 ; i++){
        if(rand()%10 > 5){
            (*PT)[i] = '0';
        }else{
            (*PT)[i] = '1';
        }
    }
    cout << "Hola" << endl;
}

/**
    Esta función imprime la cadena de bits.
**/
void imprimirCadena(char *PT){
    for(int i = 0 ; i < 64 ; i++){
        cout << PT[i];
    }
    cout << endl;
}

/**
    Esta función aplica la permutación inicial del algoritmo DES
    a nuestra cadena de bits o texto plano.
**/
void permutacionInicial(char **PT, char **IPPT){
    int i,j,k,x=0;
    /** Se llenan los primeros 4 bytes **/
    for(i = 57 ; i < 64 ; i+=2){
        k = i - 56;
        for(j = i; j >= k ; j-=8){
            (*IPPT)[x] = (*PT)[j];
            x++;
        }
    }
    /** Se llenan los 4 bytes restantes **/
    for(i = 56 ; i < 63 ; i+=2){
        k = i - 56;
        for(j = i; j >= k ; j-=8){
            (*IPPT)[x] = (*PT)[j];
            x++;
        }
    }
}
