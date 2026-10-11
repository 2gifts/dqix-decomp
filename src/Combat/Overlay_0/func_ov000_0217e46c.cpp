#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x1f00
#define REGION_OFFSET_1 0xaa
#define REGION_OFFSET_2 0xf98
#define REGION_OFFSET_3 0xfa0
#define REGION_OFFSET_4 0xa0
#else
#define REGION_OFFSET_0 0x1d00
#define REGION_OFFSET_1 0x72
#define REGION_OFFSET_2 0xd60
#define REGION_OFFSET_3 0xd68
#define REGION_OFFSET_4 0x68
#endif

#include "std_library_functions.h"

int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);
extern "C" void func_ov000_02180404(void* obj);
extern "C" void func_ov000_02174b14(void* obj);
extern "C" void func_ov000_0217a8f4(void* obj);

struct Cont0205d1e0;
struct Cont0205d274;
struct Obj0205d2bc;
struct Entry_0205d6a0;
void ClearBuffers0204b010OverList0x98(struct Cont0205d1e0*);
void CallFunc0204b04cOverList0x98(struct Cont0205d274*);
void InitEntries0205d2bc(struct Obj0205d2bc*);
void ResetEntryList0205d6a0(struct Entry_0205d6a0*, int);

extern unsigned short data_02114e30;
extern unsigned char data_02114e54;

// USA: func_ov000_0217e46c  (semantic: InitCombatEncounterState_0217e46c)
extern "C" ARM void func_ov000_0217e46c(char* obj) {
    if (TestFlag0SetAndFlag1Clear(&data_02114e30, 0x802) == 0) {
        if (*(&data_02114e54 + 0x55) == 0) {
            return;
        }
    }

    func_ov000_02180404(obj);
    func_ov000_02174b14(obj);
    func_ov000_0217a8f4(obj);

    *(int*)(obj + 0x920) = 0x100;
    *(int*)(obj + 0x92c) = 8;
    *(int*)(obj + 0x924) = 0x100;
    *(int*)(obj + 0x928) = 0x100;

    *(unsigned short*)(obj + REGION_OFFSET_0 + REGION_OFFSET_1) &= ~0x38;
    func_ov000_02174b14(obj);

    memset(obj + REGION_OFFSET_2 + 0x1000, 0, 8);
    *(unsigned char*)(obj + 0x1000 + REGION_OFFSET_3) = 0;
    signed char sel = *(signed char*)(obj + REGION_OFFSET_0 + REGION_OFFSET_4);
    *(unsigned char*)(obj + sel + 0x1000 + REGION_OFFSET_2) = 1;

    ClearBuffers0204b010OverList0x98((struct Cont0205d1e0*)(obj + 0x188));
    CallFunc0204b04cOverList0x98((struct Cont0205d274*)(obj + 0x188));
    InitEntries0205d2bc((struct Obj0205d2bc*)(obj + 0x188));
    ResetEntryList0205d6a0((struct Entry_0205d6a0*)(obj + 0x188), 1);

    *(unsigned short*)(obj + REGION_OFFSET_0 + REGION_OFFSET_1) |= 0x2;
}
