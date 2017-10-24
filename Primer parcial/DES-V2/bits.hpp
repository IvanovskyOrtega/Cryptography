#ifndef _BITS_HPP_
#define _BITS_HPP_

#include<iostream>

namespace bits{
    typedef unsigned char uchar;
    void inicializarBytes(uchar *bytes, int numBytes);
    void poner0(uchar* byte, int pos);
    void poner1(uchar* byte, int pos);
    void ponerBit(uchar* byte, int bit, int pos);
    int consultarBit(uchar byte, int pos);
    void imprimirByte(uchar byte);
}

#endif
