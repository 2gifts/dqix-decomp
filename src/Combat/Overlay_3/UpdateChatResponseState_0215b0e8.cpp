#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

#if defined(jpn)
enum { kRegionValue998_868 = 0x868 };
enum { kRegionValue9A0_870 = 0x870 };
enum { kRegionValue9AE_7DE = 0x7de };
#else
enum { kRegionValue998_868 = 0x998 };
enum { kRegionValue9A0_870 = 0x9a0 };
enum { kRegionValue9AE_7DE = 0x9ae };
#endif

void* GetGlobalField0x1c020421a0(void);
struct Container020e0310;
void* GetFieldByKey020e0434(Container020e0310*, int);
extern "C" void func_ov003_02159250(void*, void*);
extern "C" void func_02043124(void*);
struct Struct0209c830;
void SetValueAndActivate0209c830(Struct0209c830*, unsigned short);
int IsAnimationActive0209ca2c(void*);

extern unsigned char data_02109bf4;

// USA: func_ov003_0215b0e8
ARM void UpdateChatResponseState_0215b0e8(void* self) {
    unsigned char* s = (unsigned char*)self;
    GameState::GetInstance();
    unsigned char* g = (unsigned char*)GetGlobalField0x1c020421a0();
    unsigned char state = *(unsigned char*)(s + 0x580);

    if (state == 0) {
        if (*(unsigned char*)(s + 0x59d) != 0) return;

        void* val0 = GetFieldByKey020e0434((Container020e0310*)(s + 0x64), 0x44c);
        if (val0 != 0 && strlen((char*)val0) != 0) {
            *(int*)(g + kRegionValue998_868) = 1;
            void* val1 = GetFieldByKey020e0434((Container020e0310*)(s + 0x64), 0x44c);
            func_ov003_02159250(self, val1);
        } else {
            func_02043124(g);
        }
        *(unsigned char*)(s + 0x580) = *(unsigned char*)(s + 0x580) + 1;
    }

    if (state == 1) {
        if (*(int*)(g + kRegionValue998_868) != 0) return;
        SetValueAndActivate0209c830((Struct0209c830*)&data_02109bf4, 0x3b);
        *(unsigned char*)(s + 0x580) = *(unsigned char*)(s + 0x580) + 1;
    }

    if (state != 2) return;

    if (*(int*)(g + kRegionValue9A0_870) == 3) {
        *(unsigned char*)(g + 0x1000 + kRegionValue9AE_7DE) = 0;
    }
    if (IsAnimationActive0209ca2c(&data_02109bf4) == 0) {
        *(unsigned char*)(s + 0x588) = 1;
        *(unsigned char*)(s + 0x580) = 0;
    }
}
