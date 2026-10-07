#include <globaldefs.h>
#include "std_library_functions.h"

struct PackedTriple02083cbc {
    unsigned int fieldA : 10;
    unsigned int fieldB : 10;
    unsigned int fieldC : 10;
    unsigned int reserved : 2;
};

struct PackedSource02083cbc {
    unsigned char unknown[8];
    PackedTriple02083cbc triples[3];
};

struct PackedDestination02083cbc {
    unsigned char unknown[0x91c];
    PackedTriple02083cbc triples[3];
    unsigned char gap[0xc];
    unsigned char tail[0x16];
};

// Copy the nine packed fields, preserving each destination word's upper two bits.
// The optional tail replaces the default byte value 100 in all 22 positions.
// USA: func_02083cbc
extern "C" ARM void func_02083cbc(void* dst, void* src, void* tail) {
    ((PackedDestination02083cbc*)dst)->triples[0].fieldA = ((PackedSource02083cbc*)src)->triples[0].fieldA;
    ((PackedDestination02083cbc*)dst)->triples[0].fieldB = ((PackedSource02083cbc*)src)->triples[0].fieldB;
    ((PackedDestination02083cbc*)dst)->triples[0].fieldC = ((PackedSource02083cbc*)src)->triples[0].fieldC;
    ((PackedDestination02083cbc*)dst)->triples[1].fieldA = ((PackedSource02083cbc*)src)->triples[1].fieldA;
    ((PackedDestination02083cbc*)dst)->triples[1].fieldB = ((PackedSource02083cbc*)src)->triples[1].fieldB;
    ((PackedDestination02083cbc*)dst)->triples[1].fieldC = ((PackedSource02083cbc*)src)->triples[1].fieldC;
    ((PackedDestination02083cbc*)dst)->triples[2].fieldA = ((PackedSource02083cbc*)src)->triples[2].fieldA;
    ((PackedDestination02083cbc*)dst)->triples[2].fieldB = ((PackedSource02083cbc*)src)->triples[2].fieldB;
    ((PackedDestination02083cbc*)dst)->triples[2].fieldC = ((PackedSource02083cbc*)src)->triples[2].fieldC;
    memset(((PackedDestination02083cbc*)dst)->tail, 100, 0x16);
    if (tail != NULL) {
        for (int i = 0; i < 0x16; i++) {
            ((PackedDestination02083cbc*)dst)->tail[i] = ((unsigned char*)tail)[i];
        }
    }
}
