#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { kRegionValue72C_628 = 0x628 };
enum { kRegionValue720_61C = 0x61c };
enum { kRegionValue71C_618 = 0x618 };
enum { kRegionValue2AE_28A = 0x28a };
#else
enum { kRegionValue72C_628 = 0x72c };
enum { kRegionValue720_61C = 0x720 };
enum { kRegionValue71C_618 = 0x71c };
enum { kRegionValue2AE_28A = 0x2ae };
#endif


extern "C" void* func_0202ae18(void);
void* GetData02100044(void);

struct SearchStruct;
extern int TestFlagBitAt0xe(struct SearchStruct* obj, int value);

struct CheckField0AndGlobalHalfStruct0202c508;
extern "C" int func_0202c508(struct CheckField0AndGlobalHalfStruct0202c508* obj);

extern void EnqueueEventTag173_021d1810(unsigned short a, unsigned short b, unsigned char c);
extern int* GetGlobal02109030(void);
extern "C" void func_02094030(int* a, unsigned short b, short c, unsigned char d);
extern void RemoveSearchEntry0202c21c(struct SearchStruct* obj, int value);

extern "C" void func_0202b0f4(void* p);
extern "C" void func_ov003_02171e1c(void*, void*);
extern int CheckSlotsAllFree0205e488(void* obj);

// USA: func_ov003_02171764
// JPN: func_ov003_02170ab0
extern "C" ARM void func_ov003_02171764(char* self) {
    GameState* battle = GameState::GetInstance();
    struct SearchStruct* search = (struct SearchStruct*)func_0202ae18();
    void* dataPtr = GetData02100044();

    if (TestFlagBitAt0xe(search, *(unsigned char*)(self + 0x199)) != 0) {
        if (func_0202c508((struct CheckField0AndGlobalHalfStruct0202c508*)search) != 0) {
            ((void(*)(unsigned short, short, unsigned char))EnqueueEventTag173_021d1810)(4, -1, 0);
            int* g = GetGlobal02109030();
            func_02094030(g, 4, -1, 0);
        }
        RemoveSearchEntry0202c21c(search, *(unsigned char*)(self + 0x199));
    }

    int fieldVal = battle->GetEffectiveDeltaTime();
    *(int*)(self + kRegionValue72C_628) = fieldVal;
    if ((unsigned int)fieldVal > 0xbb8) {
        func_0202b0f4(search);
        self[0] = 4;
        return;
    }

    if (*(int*)(self + kRegionValue720_61C) != 0 && *(int*)(self + kRegionValue71C_618) != 0) {
        func_ov003_02171e1c(self, self + kRegionValue2AE_28A);
        func_0202b0f4(search);
        self[0] = 4;
    }

    if (CheckSlotsAllFree0205e488(dataPtr) != 0) {
        *(int*)(self + kRegionValue720_61C) = 1;
    }
}
