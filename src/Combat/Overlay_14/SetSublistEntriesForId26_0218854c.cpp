#include <globaldefs.h>

#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif

#if defined(jpn)
#define func_ov014_0218854c func_ov014_0218942c
#endif

struct StatusOwner02081164;

void SetEntryHalfword0xe(void* obj, int id, int value);
void SetSublistEntryField14LowBits_02080798(void* obj, int id, int value);
void SetEntryFlag0x2ByShortId(struct StatusOwner02081164* obj, int id, int value);
void SetEntryLowNibbleAndElement02080c68(void* obj, int id, int value);
extern "C" void func_020813ec(void* obj, int key);

// USA: func_ov014_0218854c  (semantic: SetSublistEntriesForId26_0218854c)
extern "C" ARM void func_ov014_0218854c(void* self) {
    int flag = (*((unsigned char*)self + 0x17e) & 8) ? 1 : 0;
    short val = 0x1b + flag;
    SetEntryHalfword0xe(*(void**)((char*)self + 0xc0), 0x1a, val);
#if !defined(jpn)
    SetSublistEntryField14LowBits_02080798(*(void**)((char*)self + 0xc0), 0x1a, 1);
#endif
    SetEntryFlag0x2ByShortId(*(struct StatusOwner02081164**)((char*)self + 0xc0), 4, 1);
    SetEntryLowNibbleAndElement02080c68(*(void**)((char*)self + 0xc0), 4, 1);
    func_020813ec(*(void**)((char*)self + 0xc0), 4);
}
