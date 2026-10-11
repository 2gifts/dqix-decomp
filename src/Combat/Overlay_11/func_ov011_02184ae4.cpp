#if defined(jpn)
#define R(j,u) (j)
#define _Z27ScaleStatsIfType12_021f6f10Pv _Z27CheckAnyBuffBelow2_021f5c80P16Wrapper_021f5c80iiPiPs
#define _Z40InitTenAllocatorsAndClearFields_021e4e8cPv func_ov023_021e5080
#define data_ov023_021ff5b4 data_ov023_021fe83c
#define func_ov023_021fc518 func_ov023_021fb810
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

int GetGlobalField0x1c020421a0();
extern "C" int func_020457e0(char* obj);
extern "C" void* func_ov011_02184a40(void* obj, unsigned int idx);

struct Node02184ae4 {
    char pad[0xc0];
    unsigned short f_c0;
    unsigned short f_c2;
    unsigned short f_c4;
    unsigned short f_c6;
};

#define SUB(o) ((struct Node02184ae4*)((char*)(o) + 0x100))

// USA: func_ov011_02184ae4
extern "C" ARM void func_ov011_02184ae4(void* obj) {
    if (SUB(obj)->f_c4 == 0 && SUB(obj)->f_c6 == 0 && SUB(obj)->f_c0 == 0 && SUB(obj)->f_c2 == 0) return;

    char* g = (char*)GetGlobalField0x1c020421a0();
    if (*(int*)(g + R(0x868, 0x998)) != 0) return;

    int v = func_020457e0(g);
    switch (v) {
    case 0: {
        unsigned short f = SUB(obj)->f_c4;
        if (f != 0) {
            *(unsigned int*)((char*)obj + 0x10c) = f;
            SUB(obj)->f_c4 = 0;
            SUB(obj)->f_c6 = 0;
        }
        if (SUB(obj)->f_c0 == 0) return;
        func_ov011_02184a40(obj, SUB(obj)->f_c0);
        SUB(obj)->f_c0 = 0;
        SUB(obj)->f_c2 = 0;
        return;
    }
    case 1: {
        unsigned short f = SUB(obj)->f_c6;
        if (f != 0) {
            *(unsigned int*)((char*)obj + 0x10c) = f;
            SUB(obj)->f_c4 = 0;
            SUB(obj)->f_c6 = 0;
        }
        if (SUB(obj)->f_c2 == 0) return;
        func_ov011_02184a40(obj, SUB(obj)->f_c2);
        SUB(obj)->f_c0 = 0;
        SUB(obj)->f_c2 = 0;
        return;
    }
    }
}
