#include <globaldefs.h>
#include "GameState/GameState.h"

struct SearchStruct;
struct Element0202bad4;
struct ElementArray0202bad4;

extern "C" void* func_0202ae18(void);
extern "C" void func_0202b0f4(void* ptr);
extern "C" void func_0202c288(void* ptr);
extern "C" unsigned short _Z32GetEntryField0x4OrFieldA0202bc8cP12SearchStruct(struct SearchStruct* obj);
extern "C" int _Z13GetConstant10v(void* search);
struct Element0202bad4* GetElementAt0x10Stride0xc0(struct ElementArray0202bad4* base, int index);
void SetSearchFlagBitAt0xc(struct SearchStruct* obj, int value);

struct Obj02171640 {
    unsigned char state;
    char pad1[3];
    unsigned int timer;
    char pad8[0x199 - 8];
    signed char selected;
};

// USA: func_ov003_02171640
extern "C" ARM void func_ov003_02171640(struct Obj02171640* obj) {
    GameState* battle = GameState::GetInstance();
    void* search = func_0202ae18();
    unsigned int dt = battle->GetEffectiveDeltaTime();

    if (dt < obj->timer) {
        obj->timer -= dt;
        unsigned short mask = _Z32GetEntryField0x4OrFieldA0202bc8cP12SearchStruct((struct SearchStruct*)search);
        int count = _Z13GetConstant10v(search);
        for (int i = 1; i < count; i++) {
            if (mask & (1 << i)) {
                GetElementAt0x10Stride0xc0((struct ElementArray0202bad4*)search, i);
                obj->selected = i;
                SetSearchFlagBitAt0xc((struct SearchStruct*)search, (unsigned char)i);
                func_0202c288(search);
                obj->state = 2;
                return;
            }
        }
    } else {
        obj->timer = 0;
        func_0202b0f4(search);
        obj->state = 4;
    }
}
