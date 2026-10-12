#if defined(jpn)
#define func_ov013_0218678c func_ov013_02187ab8
#define func_ov013_02186c64 func_ov013_02187f78
#endif

#include <globaldefs.h>

#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif

int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);
int CheckByteSetAndByteClear(unsigned char* obj);
void InvalidateBattlerField0x18(unsigned char* obj);

struct Obj0205dee8;
void SetFieldB0AndUpdate0205dee8(struct Obj0205dee8* obj, int val);

struct Entry_0205d6a0;
void ResetEntryList0205d6a0(struct Entry_0205d6a0* a, int flag);

extern "C" void func_ov013_02186c64(void* obj, int a, int b);
extern "C" void func_ov013_02185cc0(void* obj);

extern unsigned short data_02114e30;
extern char data_02114e54;

// USA: func_ov013_0218678c  (semantic: RefreshTagAndReinit0218678c)
extern "C" ARM void func_ov013_0218678c(void* obj) {
    unsigned char* o = (unsigned char*)obj;
    o[LOW_REGION(0x644, 0x6bc)] &= ~1;
    o[LOW_REGION(0x5c6, 0x63a)] = 0;

    if (o[LOW_REGION(0x5c9, 0x63d)] != o[LOW_REGION(0x5c8, 0x63c)]) return;

    if (!TestFlag0SetAndFlag1Clear(&data_02114e30, 0x613) && !CheckByteSetAndByteClear((unsigned char*)&data_02114e54)) {
        return;
    }

    o[LOW_REGION(0x5c8, 0x63c)] = 1;
    InvalidateBattlerField0x18((unsigned char*)&data_02114e30);
    SetFieldB0AndUpdate0205dee8((struct Obj0205dee8*)(o + LOW_REGION(0x34, 0x38)), 2);
    ResetEntryList0205d6a0((struct Entry_0205d6a0*)(o + LOW_REGION(0x34, 0x38)), 0);
    o[LOW_REGION(0x5c5, 0x639)] = 0;
    o[LOW_REGION(0x644, 0x6bc)] &= ~1;
    func_ov013_02186c64(obj, 0, 0);
    func_ov013_02185cc0(obj);
}
