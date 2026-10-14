#include <globaldefs.h>

struct ZeroStruct;
void ClearHeaderFields020e1354(unsigned char* p);
void ClearZeroStruct_020e1568(struct ZeroStruct* s);

// USA: func_020e1588
ARM void InitStruct020e1588(unsigned char* p) {
    *(int*)(p + 0x0) = 0;
    *(int*)(p + 0x4) = 0;
    *(int*)(p + 0x8) = 0;
    ClearHeaderFields020e1354(p + 0xc);
    ClearHeaderFields020e1354(p + 0x18);
    ClearZeroStruct_020e1568((struct ZeroStruct*)(p + 0x24));
    *(int*)(p + 0x30) = 0;
    *(int*)(p + 0x34) = 0;
    p[0x39] = 0;
    p[0x38] = 0;
    p[0x3b] = 0;
    p[0x3a] = 0;
    p[0x3c] = 0;
    p[0x3d] = 0;
    p[0x3e] = 0;
    struct FlagsByte3F { unsigned char bit0 : 1; unsigned char bit1 : 1; unsigned char rest : 6; };
    struct FlagsByte3F* f = (struct FlagsByte3F*)(p + 0x3f);
    f->bit0 = 0;
    f->bit1 = 0;
}
