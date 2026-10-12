#include <globaldefs.h>
#include "std_library_functions.h"

void SetFlag0x80Reset020489bc(void* obj);
void ClearField0x0_020bc078(int* field);

#if defined(jpn)
#define InitCombatantExtendedFields02052a4c func_02053e28
extern "C" ARM void func_02053e28(void* obj);
enum { kExtendedOffsetDelta = 0xc };
#else
enum { kExtendedOffsetDelta = 0 };
#endif

// USA: func_02052a4c
ARM void InitCombatantExtendedFields02052a4c(void* obj) {
    char* p = (char*)obj;
    SetFlag0x80Reset020489bc(obj);
    *(unsigned short*)p |= 0x100;
    ClearField0x0_020bc078((int*)(p + (0x198 - kExtendedOffsetDelta)));
    *(int*)(p + (0x150 - kExtendedOffsetDelta)) = 0;
    *(int*)(p + (0x154 - kExtendedOffsetDelta)) = 0;
    *(int*)(p + (0x158 - kExtendedOffsetDelta)) = 0;
    memset(p + (0x178 - kExtendedOffsetDelta), 0, 4);
    *(unsigned char*)(p + (0x17c - kExtendedOffsetDelta)) = 0;
    *(unsigned char*)(p + (0x17d - kExtendedOffsetDelta)) = 0;
    *(int*)(p + (0x180 - kExtendedOffsetDelta)) = -1;
    *(unsigned char*)(p + (0x17e - kExtendedOffsetDelta)) = 0;
    *(unsigned char*)(p + (0x17f - kExtendedOffsetDelta)) = 0;
    *(unsigned char*)(p + (0x184 - kExtendedOffsetDelta)) = 0;
    *(int*)(p + (0x190 - kExtendedOffsetDelta)) = 0;
    *(int*)(p + (0x194 - kExtendedOffsetDelta)) = -1;
    *(unsigned char*)(p + (0x185 - kExtendedOffsetDelta)) = 0;
    *(unsigned char*)(p + (0x186 - kExtendedOffsetDelta)) = 0;
    *(int*)(p + (0x188 - kExtendedOffsetDelta)) = 0;
    *(int*)(p + (0x1b4 - kExtendedOffsetDelta)) = 0;
    *(int*)(p + (0x1b8 - kExtendedOffsetDelta)) = 0;
    *(int*)(p + (0x1bc - kExtendedOffsetDelta)) = 0;
    *(int*)(p + (0x18c - kExtendedOffsetDelta)) = 0;
    *(int*)(p + (0x19c - kExtendedOffsetDelta)) = 0;
    *(unsigned short*)(p + (0x1b2 - kExtendedOffsetDelta)) = 0;
    *(unsigned short*)(p + (0x1c0 - kExtendedOffsetDelta)) = 0;
    *(int*)(p + (0x15c - kExtendedOffsetDelta)) = -1;
    *(int*)(p + (0x1c4 - kExtendedOffsetDelta)) = 0;
}
