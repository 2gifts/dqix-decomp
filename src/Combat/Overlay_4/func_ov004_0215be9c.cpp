#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct021707d8_0215be9c { char pad[8]; unsigned char* ptr; };
extern Struct021707d8_0215be9c data_ov004_021707d8;

struct Stat0215be9c { char pad[0x5c]; short cur; short max; };

extern "C" Stat0215be9c* func_ov004_02156ed0(void* obj, int key);
extern "C" int _Z19HasFlag101_021571d8i(int flag);
extern "C" int _Z28DispatchNodeIfType7_02156e2cPvi(void* node, int type);
void* GetPointerFromArray0xbd0(unsigned char* arr, unsigned int idx);
void* GetFieldAt0x150(unsigned char* p);
extern "C" signed char func_ov004_02157128(void* obj);
extern "C" int _Z24CheckThenNotify_02157088v(void* obj, int key);
extern "C" void func_ov023_021dcae0(void* obj, short v);

// USA: func_ov004_0215be9c
extern "C" ARM int func_ov004_0215be9c(int obj) {
    GameState* gs = GameState::GetInstance();
    unsigned char* p = (unsigned char*)GetPtrField0x2a04(gs);
    if (p == 0) {
        return 0;
    }
    Stat0215be9c* stat = func_ov004_02156ed0((void*)obj, 0x63);
    int idx = stat->cur << 3;
    unsigned char* node;
    if (_Z19HasFlag101_021571d8i(obj)) {
        int id = _Z28DispatchNodeIfType7_02156e2cPvi((void*)obj, 0x65);
        if (id < 0) {
            return 0;
        }
        node = (unsigned char*)GetPointerFromArray0xbd0(p + 0x1d4, *(data_ov004_021707d8.ptr + id + 0x7c));
    } else {
        signed char flag = func_ov004_02157128((void*)obj);
        if (flag >= 0) {
            void* found = GetCombatantWithFlag0x100(gs, flag);
            if (found == 0) {
                return 0;
            }
            unsigned char* field = (unsigned char*)GetFieldAt0x150((unsigned char*)found) + 0x54;
            node = field + 0x400;
            idx = 0;
        } else {
            node = p + 0xc;
        }
    }
    int notified = _Z24CheckThenNotify_02157088v((void*)obj, 7);
    int id2 = _Z28DispatchNodeIfType7_02156e2cPvi((void*)obj, 0x63);
    if (notified != 0) {
        func_ov023_021dcae0((void*)notified, ((short*)node)[idx + id2]);
    }
    return 0;
}
