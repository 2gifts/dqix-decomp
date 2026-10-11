#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { kRegionValue998_868 = 0x868 };
enum { kRegionValue9A0_870 = 0x870 };
#else
enum { kRegionValue998_868 = 0x998 };
enum { kRegionValue9A0_870 = 0x9a0 };
#endif


extern "C" void* _Z26GetGlobalField0x1c020421a0v(void);
extern "C" int _ZNK9GameState21IsMorningDayOrEveningEv(void*);
extern "C" void* _Z21GetFieldByKey020e0434P17Container020e0310i(void*, int);
extern "C" void _Z20AppendString02042058PcPKc(char*, const char*);
extern "C" void _Z17SetElementFieldC2P15Struct_0205d81cii(void*, int, int);
extern "C" void func_ov003_02159250(void*, void*);
extern "C" void func_ov003_0215b478(void*);
extern "C" void func_ov003_0215b8a0(void*);
extern "C" void func_ov003_0215b5c4(void*);

// USA: func_ov003_02159b20
// JPN: func_ov003_0215afa0
ARM void UpdateHandshakeState_02159b20(void* self) {
    unsigned char* s = (unsigned char*)self;
    unsigned char* g = (unsigned char*)_Z26GetGlobalField0x1c020421a0v();
    unsigned char state = *(unsigned char*)(s + 0x580);

    if (state == 0) {
        if (*(unsigned char*)(s + 0x59d) != 0) return;

        int isSet = _ZNK9GameState21IsMorningDayOrEveningEv((void*)GameState::GetInstance());
        int key = 0x3e8;
        if (!isSet) key += 1;
        void* val = _Z21GetFieldByKey020e0434P17Container020e0310i(s + 0x64, key);
        _Z20AppendString02042058PcPKc(*(char**)(s + 0x7c), (const char*)val);

        *(int*)(g + kRegionValue998_868) = 1;
        func_ov003_02159250(self, *(void**)(s + 0x7c));

        *(unsigned char*)(s + 0x580) = *(unsigned char*)(s + 0x580) + 1;
    }

    if (!(state == 1 && *(unsigned char*)(s + 0x59d) == 0 && *(int*)(g + kRegionValue9A0_870) == 3)) return;

    func_ov003_0215b478(self);
    func_ov003_0215b8a0(self);
    func_ov003_0215b5c4(self);

    _Z17SetElementFieldC2P15Struct_0205d81cii(s + 0xf4, 0, 0);
    _Z17SetElementFieldC2P15Struct_0205d81cii(s + 0xf4, 1, 0);
    _Z17SetElementFieldC2P15Struct_0205d81cii(s + 0xf4, 2, 0);

    *(unsigned char*)(s + 0x588) = 2;
    *(unsigned char*)(s + 0x580) = 0;
}
