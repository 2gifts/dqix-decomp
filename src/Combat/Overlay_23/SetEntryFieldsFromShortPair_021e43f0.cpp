#include <globaldefs.h>

#if defined(jpn)
#define func_ov023_021e43f0 func_ov023_021e4614
#define FLAG_FIELD_021E43F0 0x56c
#else
#define FLAG_FIELD_021E43F0 0x634
#endif

void ComputeShortPair_021e2bdc(void* a, int unused, short* out1, short* out2);
extern "C" void func_0205ac40(void* obj, void* entry);

// USA: func_ov023_021e43f0  (semantic: SetEntryFieldsFromShortPair_021e43f0)
extern "C" ARM void func_ov023_021e43f0(void* obj) {
    short lo, hi;
    void* entry = *(void**)((char*)obj + 0xcc);
    ComputeShortPair_021e2bdc((char*)obj + 0xd4, 0x1b, &lo, &hi);
    if (*(unsigned short*)((char*)obj + FLAG_FIELD_021E43F0) & 0x800) {
        lo++;
        hi++;
        *(unsigned short*)((char*)obj + FLAG_FIELD_021E43F0) &= ~0x800;
    }
    *(int*)((char*)entry + 0x3c) = lo << 12;
    *(int*)((char*)entry + 0x40) = hi << 12;
    *(unsigned char*)((char*)entry + 0x4a) = 0x79;
    *(unsigned char*)((char*)entry + 0x4e) = 2;
    func_0205ac40(*(void**)((char*)obj + 0xc8), (char*)entry + 0x28);
}
