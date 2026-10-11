// JPN: func_ov017_021b0f8c
#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { Field718 = 0x508, Field700 = 0x4f0 };
#else
enum { Field718 = 0x718, Field700 = 0x700 };
#endif

extern "C" void* func_ov017_021b8468(void* obj);
extern "C" void func_ov000_021682ec(void* p);
extern "C" void func_ov017_021d0b30(int a, int b, int c);
extern "C" void func_ov017_021b0bc0(void* obj);
int CheckCombatantsAndBit4_021b0b4c(void);
int IsField0Null(void** obj);

struct Ctx021b08f4 {
    char pad0[0x9];
    unsigned char byte9;
    char pad1[0x26 - 0xa];
    unsigned char byte26;
    unsigned char byte27;
    char pad2[0x2c - 0x28];
    unsigned char byte2c;
    char pad3[0x34 - 0x2d];
    int field34;
};

// USA: func_ov017_021b08f4  (semantic: UpdateSlotFlagsAndGetByteA_021b08f4)
extern "C" ARM unsigned char func_ov017_021b08f4(Ctx021b08f4* obj) {
    GameState::GetInstance();
    int ctx = ((int)func_ov017_0218b5b0());
    char* base = (char*)ctx + 0x3000;
    void* p718 = *(void**)(base + Field718);
    void* p700 = *(void**)(base + Field700);
    if (*((unsigned char*)p718 + 0x2) != 0) {
        void* f6ac = func_ov017_021b8468(p718);
        if (f6ac != 0) {
            func_ov000_021682ec(f6ac);
        }
    }

    if (obj->byte9 == 0) {
        if (obj->byte26 == 0) {
            func_ov017_021d0b30(5, 0, 0);
            if (((int (*)(void*))CheckCombatantsAndBit4_021b0b4c)(obj) != 0) {
                obj->byte26 = obj->byte26 + 1;
            } else {
                obj->byte26 = 2;
            }
        } else if (obj->byte26 == 1) {
            if (IsField0Null((void**)p700) != 0) {
                obj->byte26 = obj->byte26 + 1;
            }
        } else if (obj->byte26 == 2) {
            if ((obj->byte27 & 0x10) != 0) {
                func_ov017_021b0bc0(obj);
                func_ov017_021d0b30(7, 0, 0);
                obj->byte26 = obj->byte26 + 1;
            }
        }
    } else {
        if (obj->byte26 == 0) {
            if (obj->field34 != 0) {
                if (((int (*)(void*))CheckCombatantsAndBit4_021b0b4c)(obj) != 0) {
                    obj->byte26 = obj->byte26 + 1;
                } else {
                    func_ov017_021d0b30(6, 0, 0);
                    obj->byte26 = 2;
                }
            }
        } else if (obj->byte26 == 1) {
            if (IsField0Null((void**)p700) != 0) {
                func_ov017_021d0b30(6, 0, 0);
                obj->byte26 = obj->byte26 + 1;
            }
        } else if (obj->byte26 == 2 && obj->byte2c == 2) {
            func_ov017_021b0bc0(obj);
        }
    }

    return *((unsigned char*)obj + 0xa);
}
