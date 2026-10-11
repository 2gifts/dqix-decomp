#include <globaldefs.h>
#include "GameState/GameState.h"

int GetField0x3acValue(GameState* battleStruct);
extern "C" void func_ov017_021a7c94(unsigned char* obj, int id, int arg2);
struct FieldStruct021a85d4;
extern "C" void _Z33SetFieldndMaybe_021a85d4_021a85d4P19FieldStruct021a85d4i(struct FieldStruct021a85d4* obj, int val);
extern "C" void _Z27CallIfGlobalPtrSet_021a5a28v(void* obj, int mode);
extern "C" int _Z32GetByteAtOffset7289OrFF_021a5a48v(void* obj);

struct Evt021d01e4 {
    unsigned char pad0[4];
    unsigned char kind;
    signed char idA;
    signed char idB;
    unsigned char pad7;
    short arg;
};

struct Work021d01e4 {
#if defined(jpn)
    unsigned char pad0[0x350c];
#else
    unsigned char pad0[0x371c];
#endif
    void* field371c;
#if defined(jpn)
    unsigned char pad3720[0x397c - 0x3510];
#else
    unsigned char pad3720[0x3b9c - 0x3720];
#endif
    struct FieldStruct021a85d4* field3b9c;
};

// JPN: func_ov017_021d0694
// USA: func_ov017_021d01e4
extern "C" ARM void func_ov017_021d01e4(int unused0, struct Evt021d01e4* evt, GameState* bs, struct Work021d01e4* work) {
    GetField0x3acValue(bs);
    unsigned char* list = (unsigned char*)GetPtrField0x2a04(bs);
    unsigned char* ids = list + 0xf78;
    unsigned char count = list[0xf7c];
    int idA = evt->idA;
    int idB = evt->idB;
    int arg = evt->arg;
    int foundA = 0;
    int foundB = 0;
    for (int i = 0; i < count; i++) {
        unsigned char id = ids[i];
        if (id == idA) {
            foundA = 1;
        }
        if (id == idB) {
            foundB = 1;
        }
    }

    struct FieldStruct021a85d4* field = work->field3b9c;
    void* p = work->field371c;
    switch (evt->kind) {
    case 0:
        break;
    case 1:
        if (foundB) {
            func_ov017_021a7c94((unsigned char*)work, idA, arg);
        }
        break;
    case 2:
        if (foundB) {
            _Z33SetFieldndMaybe_021a85d4_021a85d4P19FieldStruct021a85d4i(field, 6);
        }
        break;
    case 3:
        if (foundB) {
            _Z33SetFieldndMaybe_021a85d4_021a85d4P19FieldStruct021a85d4i(field, 5);
        }
        break;
    case 4:
        if (foundA) {
            _Z27CallIfGlobalPtrSet_021a5a28v(p, 2);
        }
        break;
    case 5:
        if (foundA) {
            _Z27CallIfGlobalPtrSet_021a5a28v(p, 6);
        }
        break;
    case 6:
        if (foundA) {
            if (_Z32GetByteAtOffset7289OrFF_021a5a48v(p) != 4) {
                _Z27CallIfGlobalPtrSet_021a5a28v(p, 8);
            }
        }
        break;
    case 7:
        if (foundA) {
            _Z27CallIfGlobalPtrSet_021a5a28v(p, 5);
        }
        break;
    case 8:
        if (foundA) {
            _Z27CallIfGlobalPtrSet_021a5a28v(p, 7);
        }
        break;
    }
}
