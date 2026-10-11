#include <globaldefs.h>
#include "GameState/GameState.h"

struct Info02011930;
unsigned char GetAndConsumeNameEntries02011930(void* obj, struct Info02011930* info, void* name1, void* name2);
extern "C" void func_ov011_021848a0(void* obj, int val);
unsigned char GetByte0x646d(void* obj);

// USA: func_ov004_021658b0
ARM int ConsumeNameEntriesAndNotify_021658b0(void* a) {
#if defined(jpn)
    enum { fieldOffset = 0x1ee };
#else
    enum { fieldOffset = 0x46e };
#endif
    void* bs = GameState::GetInstance();
    unsigned char r = GetAndConsumeNameEntries02011930(bs, NULL, NULL, NULL);
    if (r != 0) {
        func_ov011_021848a0(a, 0x64);
        char* bs2 = (char*)GameState::GetInstance();
        bs2[0x6000 + fieldOffset] = 1;
        GetByte0x646d(bs);
    } else {
        func_ov011_021848a0(a, 0x65);
    }
    return 0;
}
