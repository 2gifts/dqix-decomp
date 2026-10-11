#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { kRegionValue1012_F8E = 0xf8e };
enum { kRegionValue100E_F8A = 0xf8a };
enum { kRegionValue1014_F90 = 0xf90 };
#else
enum { kRegionValue1012_F8E = 0x1012 };
enum { kRegionValue100E_F8A = 0x100e };
enum { kRegionValue1014_F90 = 0x1014 };
#endif


unsigned char GetTableByte0207ca94(int index);
int FindNthPositiveShort0207c6b8(unsigned char* obj, unsigned int index, int target);

// USA: func_ov003_02175f20  (semantic: FindTableEntry_02175f20)
// JPN: func_ov003_02174f38
extern "C" ARM int func_ov003_02175f20(void* obj) {
    GameState* bs = GameState::GetInstance();
    void* p = GetPtrField0x2a04(bs);
    short v1 = *(short*)((char*)obj + kRegionValue1012_F8E);
    int idx = (short)(v1 - 286);
    unsigned char cnt = GetTableByte0207ca94(idx);
    short v3 = *(short*)((char*)obj + kRegionValue100E_F8A);
    short v2 = *(short*)((char*)obj + kRegionValue1014_F90);
    unsigned char* argPtr = (unsigned char*)p + 0x1d4;
    short idx2 = (short)(v3 - 295);
    idx2 = v2 * 5 + idx2;
    return FindNthPositiveShort0207c6b8(argPtr, cnt, idx2);
}
