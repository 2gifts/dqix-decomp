#include <globaldefs.h>
#if defined(jpn)
enum { flagsOffset = 0x1faa };
#else
enum { flagsOffset = 0x1d72 };
#endif

struct Cont0205d1e0;
struct Cont0205d274;
struct Obj0205d2bc;
struct Entry_0205d6a0;

void ClearBuffers0204b010OverList0x98(struct Cont0205d1e0*);
void CallFunc0204b04cOverList0x98(struct Cont0205d274*);
void InitEntries0205d2bc(struct Obj0205d2bc*);
void ResetEntryList0205d6a0(struct Entry_0205d6a0*, int);
extern "C" void func_ov000_02174b14(void* obj);

struct Entry0218048c {
    char pad0[0x24];
    unsigned char flags0x24;
    char pad1[0x4c - 0x25];
    int field0x4c;
#if defined(jpn)
    char pad2[0x488 - 0x50];
#else
    char pad2[0x448 - 0x50];
#endif
};

// USA: func_ov000_0218048c  (semantic: ResetCombatState_0218048c)
extern "C" ARM void func_ov000_0218048c(char* obj) {
    int idx;
    ClearBuffers0204b010OverList0x98((struct Cont0205d1e0*)(obj + 0x188));
    CallFunc0204b04cOverList0x98((struct Cont0205d274*)(obj + 0x188));
    InitEntries0205d2bc((struct Obj0205d2bc*)(obj + 0x188));
    ResetEntryList0205d6a0((struct Entry_0205d6a0*)(obj + 0x188), 1);
    for (idx = 0; idx < 4; idx++) {
        signed char e = *(signed char*)(obj + idx + 0x6c);
        struct Entry0218048c* entry = (struct Entry0218048c*)(obj + 0x958) + e;
        if (entry->flags0x24 & 0x2) {
            entry->flags0x24 |= 0x4;
            *(int*)(obj + 0x17c) = entry->field0x4c;
        }
    }
    *(unsigned short*)(obj + flagsOffset) &= ~0x8;
    *(int*)(obj + 0x914) = 0;
    *(int*)(obj + 0x910) = 0;
    func_ov000_02174b14(obj);
}
