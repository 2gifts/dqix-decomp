#include <globaldefs.h>
#include "GameState/GameState.h"

int DispatchNodeIfType7_02156e2c(void* a, int key);
void* GetEntryFor_021570a4(void* obj, int index);
void* GetPtrField0x2a04(GameState* battleStruct);
extern "C" void func_ov011_021848a0(void* obj, int val);

struct Struct021707d8_0215c0c0 { char pad[0x8]; unsigned char* ptr; };
extern Struct021707d8_0215c0c0 data_ov004_021707d8;

struct Combined0215c0c0 { unsigned int low7 : 7; unsigned int rest : 25; };
struct Field2a04_0215c0c0 { char pad[0xf6c]; int f0xf6c; };

// USA: func_ov004_0215c0c0  (semantic: TickCounterAndConsumeResource_0215c0c0)
extern "C" ARM int func_ov004_0215c0c0(void* obj) {
    int code = DispatchNodeIfType7_02156e2c(obj, 0x5b);
    if (code < 0) return 0;
    void* entry = GetEntryFor_021570a4(obj, code & 0xff);
    if (!entry) return 0;
    struct Field2a04_0215c0c0* fld = (struct Field2a04_0215c0c0*)GetPtrField0x2a04(GameState::GetInstance());
    struct Combined0215c0c0* c = (struct Combined0215c0c0*)((char*)entry + 4);
    unsigned char rate = data_ov004_021707d8.ptr[0x11];
    unsigned int restVal = c->rest;
    int product1 = rate * restVal;
    c->low7 = c->low7 - rate;
    unsigned char rate2 = data_ov004_021707d8.ptr[0x11];
    unsigned int restVal2 = c->rest;
    int product2 = rate2 * restVal2;
    fld->f0xf6c -= product2;
#if defined(jpn)
    data_ov004_021707d8.ptr[0xa9] = 1;
#else
    data_ov004_021707d8.ptr[0x9d] = 1;
#endif
    if (product1 >= 50000) {
        func_ov011_021848a0(obj, 0x2366);
    } else {
        func_ov011_021848a0(obj, 0x2364);
    }
    return 0;
}
