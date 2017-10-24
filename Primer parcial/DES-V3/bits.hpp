#ifndef _BITS_HPP_
#define _BITS_HPP_

#include<iostream>
#include<cstdint>

namespace bits{
    typedef uint64_t u64;
    typedef uint32_t u32;
    void poner0(u64* byte, int pos);
    void poner1(u64* byte, int pos);
    void ponerBit(u64* byte, int bit, int pos);
    int consultarBit(u64 byte, int pos);
    void imprimiru64(u64 byte);
}

#endif
