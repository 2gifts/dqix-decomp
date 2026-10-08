#include <globaldefs.h>
#include "Util/Random.h"

extern "C" float _ffltu(unsigned int v);
extern "C" float _fmul(float a, float b);
extern "C" float _fadd(float a, float b);
extern "C" unsigned int _ffixu(float v);

struct FieldStruct02048934 {
    char pad0[0x5c];
    unsigned short field5c;
    unsigned short field5e;
};

struct Obj02048934 {
    char pad0[0x188];
    unsigned short field188;
    unsigned short field18a;
};

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_02048934
extern "C" ARM void _Z31SetRandomizedShort0x18802048934PvP19FieldStruct02048934P6Random(void* p, struct FieldStruct02048934* f, struct Random* r) {
    if (f != NULL) {
        unsigned short v = f->field5c;
        ((struct Obj02048934*)p)->field188 = 0.5f + v * NextRandomFloatBetween(r, 0.8f, 1.0f);
        ((struct Obj02048934*)p)->field18a = f->field5e;
    }
}