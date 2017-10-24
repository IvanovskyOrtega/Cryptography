#include "bits.hpp"

using namespace std;
using namespace bits;

void bits::poner1(u64 *byte, int pos){
    if(!consultarBit((*byte),pos)){
        (*byte) ^= (1<<pos);
    }
}

void bits::poner0(u64 *byte, int pos){
    if(consultarBit((*byte),pos)){
        (*byte) ^= (1<<pos);
    }
}

void bits::ponerBit(u64* byte, int bit, int pos){
    if(bit){
        poner1(byte,pos);
    }
    else{
        poner0(byte,pos);
    }
}

int bits::consultarBit(u64 byte, int pos){
    u64 a = 1; 
    if((byte)&(a<<pos)){
        return 1;
    }
    return 0;
}

void bits::imprimiru64(u64 byte){
    cout << "|";
    for(int i = 63 ; i >= 0 ; i--){
        cout << consultarBit(byte,i);
    }
}
