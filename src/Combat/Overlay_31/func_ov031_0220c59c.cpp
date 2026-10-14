#include <globaldefs.h>
#include "System/Memory.h"
#include <std_library_functions.h>

extern "C" void func_ov031_0220bf5c(unsigned short*, unsigned short*, int);
extern "C" void func_ov031_0220be38(unsigned short*, unsigned short*, unsigned short*, int);
extern "C" void func_ov031_0220bb7c(unsigned short*, unsigned short*, unsigned short*, int);
extern "C" void func_ov031_0220bcbc(unsigned short*, unsigned short*, unsigned short*, int);
int CompareShortArraysDesc_0220bdcc(unsigned short*, unsigned short*, int);

// USA: func_ov031_0220c59c
extern "C" ARM void func_ov031_0220c59c(unsigned short* value, unsigned short* backup,
    unsigned short* factor, int count, int shift, unsigned short* modulus,
    unsigned short* reductionFactor, unsigned short* factorProduct, unsigned short* modulusProduct) {
    int bytes = count * 2;
    VectorizedInvertedMemcpy(value, backup, bytes);
    if (factor == (unsigned short*)1) func_ov031_0220bf5c(value, backup, count);
    else if (factor) func_ov031_0220be38(value, backup, factor, count);
    func_ov031_0220be38(factorProduct, value, reductionFactor, shift);
    int remainingBytes = (count - shift) * 2;
    VectorizedMemset(factorProduct + shift, 0, remainingBytes);
    func_ov031_0220be38(modulusProduct, factorProduct, modulus, count);
    func_ov031_0220bb7c(value, value, modulusProduct, count);
    memmove(value, value + shift, remainingBytes);
    VectorizedMemset(value + count - shift, 0, shift * 2);
    int comparison = CompareShortArraysDesc_0220bdcc(value, modulus, count);
    switch (comparison) {
    case 0:
        VectorizedMemset(value, 0, bytes);
        break;
    case 1:
        func_ov031_0220bcbc(value, value, modulus, count);
        break;
    }
}
