#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { kRegionValue1043_FBF = 0xfbf };
enum { kRegionValue89C_818 = 0x818 };
enum { kRegionValue100E_F8A = 0xf8a };
enum { kRegionValue103A_FB6 = 0xfb6 };
#else
enum { kRegionValue1043_FBF = 0x1043 };
enum { kRegionValue89C_818 = 0x89c };
enum { kRegionValue100E_F8A = 0x100e };
enum { kRegionValue103A_FB6 = 0x103a };
#endif


int GetFieldAt0x150(unsigned char* obj);
short FindMappedMemberId02080468(void* obj, int id);

// USA: func_ov003_0217a220
// JPN: func_ov003_02179050
ARM void ComputeMappedOffset_0217a220(unsigned char* obj) {
    short result = -1;
    GameState* bs = GameState::GetInstance();
    GameObject* c = bs->GetPartyMemberByIndex(*(signed char*)(obj + kRegionValue1043_FBF));
    if (c != NULL) {
        unsigned char* base = (unsigned char*)GetFieldAt0x150((unsigned char*)c);
        short id = FindMappedMemberId02080468(*(void**)(obj + kRegionValue89C_818), 0x15);
        short diff = *(short*)(obj + kRegionValue100E_F8A) - id;
        result = *(short*)(base + diff * 2 + 0x400 + 0x54);
    }
    *(short*)(obj + kRegionValue103A_FB6) = result;
}
