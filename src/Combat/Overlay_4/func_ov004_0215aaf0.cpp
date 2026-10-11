#include <globaldefs.h>
#include "GameState/GameState.h"


struct Struct021707d8_0215aaf0 { char pad[8]; unsigned char* ptr; };
extern Struct021707d8_0215aaf0 data_ov004_021707d8;

struct Container020dedd0;
extern "C" struct Container020dedd0* func_ov004_02156fd4(void* obj, int key);

int DispatchNodeIfType7_02156e2c(void* a, int key);

struct Stat02156ed0_0215aaf0 { char pad[0x5c]; short field5c; };
extern "C" Stat02156ed0_0215aaf0* func_ov004_02156ed0(void* obj, int key);

int HasFlag101_021571d8(int a);

void* GetPointerFromArray0xbd0(unsigned char* obj, unsigned int index);
void* GetPointerAt0xbf0(void* base, unsigned int index);

struct Bits2_0215aaf0 { unsigned int low12 : 12; unsigned int field2 : 2; unsigned int rest : 18; };
struct Element020de650 { char pad[8]; Bits2_0215aaf0 bits; };
struct Element020de650* FindElementByKey020dedd0(struct Container020dedd0* c, int key);

extern "C" void func_ov011_021848a0(void* obj, int val);

extern "C" int func_ov004_02157128(void* obj);
GameObject* GetCombatantWithFlag0x100(GameState* battleStruct, int combatantId);
int GetFieldAt0x150(unsigned char* obj);

int EvalOrDispatch020de194(void* s);

// USA: func_ov004_0215aaf0
// JPN: func_ov004_0215baf8
extern "C" ARM int func_ov004_0215aaf0(void* obj) {
    GameState* bs = GameState::GetInstance();
    struct Container020dedd0* node = func_ov004_02156fd4(obj, 5);
    unsigned char* ptr2a04 = (unsigned char*)GetPtrField0x2a04(bs);
    if (!ptr2a04) return 0;

    int idx = DispatchNodeIfType7_02156e2c(obj, 0x63);
    if (idx < 0) return 0;

    Stat02156ed0_0215aaf0* stat = func_ov004_02156ed0(obj, 0x63);
    int r5 = idx + stat->field5c * 8;

    struct Element020de650* elem;

    if (HasFlag101_021571d8((int)obj)) {
        unsigned char* keyArr = (unsigned char*)GetPointerFromArray0xbd0(ptr2a04 + 0x1d4, *(unsigned int*)(data_ov004_021707d8.ptr + 0x74));
        unsigned char* byteArr = (unsigned char*)GetPointerAt0xbf0(ptr2a04 + 0x1d4, *(unsigned int*)(data_ov004_021707d8.ptr + 0x74));
        elem = FindElementByKey020dedd0(node, ((short*)keyArr)[r5]);
        if (elem->bits.field2 == 0) {
            func_ov011_021848a0(obj, 0x3a1);
            return 0;
        }
        *(short*)(data_ov004_021707d8.ptr + 0x6c) = ((short*)keyArr)[r5];
        data_ov004_021707d8.ptr[0x6f] = *(signed char*)(byteArr + r5);
    } else {
        int flagVal = func_ov004_02157128(obj);
        if (flagVal == -1) {
            elem = FindElementByKey020dedd0(node, *(short*)(ptr2a04 + r5 * 2 + 0xc));
            if (elem->bits.field2 == 0) {
                func_ov011_021848a0(obj, 0x3a1);
                return 0;
            }
            *(short*)(data_ov004_021707d8.ptr + 0x6c) = ((short*)(ptr2a04 + 0xc))[r5];
            unsigned char* p100 = ptr2a04 + r5 + 0x100;
            data_ov004_021707d8.ptr[0x6f] = *(signed char*)(p100 + 0x3c);
        } else {
            GameObject* combatant = GetCombatantWithFlag0x100(bs, flagVal);
            if (!combatant) return 0;
            int field150 = GetFieldAt0x150((unsigned char*)combatant);
            elem = FindElementByKey020dedd0(node, ((short*)((char*)field150 + 0x400 + 0x54))[idx]);
            if (elem->bits.field2 == 0) {
                func_ov011_021848a0(obj, 0x3a1);
                return 0;
            }
            *(short*)(data_ov004_021707d8.ptr + 0x6c) = ((short*)((char*)field150 + 0x400 + 0x54))[idx];
            data_ov004_021707d8.ptr[0x6f] = 1;
        }
        data_ov004_021707d8.ptr[0x70] = (unsigned char)flagVal;
    }

    int evalResult = EvalOrDispatch020de194(elem);
    int scaled = (int)((float)(unsigned int)evalResult * 0.75f);
    *(int*)(data_ov004_021707d8.ptr + 0x78) = scaled;
    data_ov004_021707d8.ptr[0x6e] = 1;
    func_ov011_021848a0(obj, 0x6c);
    return 0;
}
