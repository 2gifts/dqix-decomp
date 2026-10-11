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


extern "C" void* _Z26GetGlobalField0x1c020421a0v(void);
extern "C" void* _Z21GetFieldByKey020e0434P17Container020e0310i(void*, int);
extern "C" void func_ov003_02159250(void*, void*);
extern "C" void func_02043124(void*);
extern "C" void _Z27SetValueAndActivate0209c830P14Struct0209c830t(void*, unsigned short);
extern "C" int _Z25IsAnimationActive0209ca2cPv(void*);

extern unsigned char data_02109bf4;

// USA: func_ov003_0215b0e8
// JPN: func_ov003_0215c528
ARM void UpdateChatResponseState_0215b0e8(void* self) {
    unsigned char* s = (unsigned char*)self;
    GameState::GetInstance();
    unsigned char* g = (unsigned char*)_Z26GetGlobalField0x1c020421a0v();
    unsigned char state = *(unsigned char*)(s + 0x580);

    if (state == 0) {
        if (*(unsigned char*)(s + 0x59d) != 0) return;

        void* val0 = _Z21GetFieldByKey020e0434P17Container020e0310i(s + 0x64, 0x44c);
        if (val0 != 0 && strlen((char*)val0) != 0) {
            *(int*)(g + kRegionValue998_868) = 1;
            void* val1 = _Z21GetFieldByKey020e0434P17Container020e0310i(s + 0x64, 0x44c);
            func_ov003_02159250(self, val1);
        } else {
            func_02043124(g);
        }
        *(unsigned char*)(s + 0x580) = *(unsigned char*)(s + 0x580) + 1;
    }

    if (state == 1) {
        if (*(int*)(g + kRegionValue998_868) != 0) return;
        _Z27SetValueAndActivate0209c830P14Struct0209c830t(&data_02109bf4, 0x3b);
        *(unsigned char*)(s + 0x580) = *(unsigned char*)(s + 0x580) + 1;
    }

    if (state != 2) return;

    if (*(int*)(g + kRegionValue9A0_870) == 3) {
        *(unsigned char*)(g + 0x1000 + kRegionValue9AE_7DE) = 0;
    }
    if (_Z25IsAnimationActive0209ca2cPv(&data_02109bf4) == 0) {
        *(unsigned char*)(s + 0x588) = 1;
        *(unsigned char*)(s + 0x580) = 0;
    }
}
