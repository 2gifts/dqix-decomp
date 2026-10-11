// JPN: func_ov017_021a0738
#if defined(jpn)
enum { RegionOffset6fc = 0x4ec, RegionOffset734 = 0x524, RegionOffset6d0 = 0x4c0, RegionOffset10a = 0x106 };
#else
enum { RegionOffset6fc = 0x6fc, RegionOffset734 = 0x734, RegionOffset6d0 = 0x6d0, RegionOffset10a = 0x10a };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_02012fe4(void);
void* GetField0x3f8Address(GameState* battleStruct);

struct Obj02071488 {
    char pad0[0x46];
    short f46;
    char pad46[0x68 - 0x48];
};
struct Obj02071488* RunScriptByValueRange02071574(unsigned int value, struct Obj02071488* obj);

extern "C" void* func_0205ec34(void);
int TestBitInByteArray(int unused, unsigned char* arr, int index);

extern "C" void func_ov017_021baedc(void* self, int flag);

struct SetFlagStruct;
void SetFlag0x9c6(struct SetFlagStruct* p, int value);

struct TailList020469b4;
struct TailNode020469b4;
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);

void SetField108_021bd398(void* obj);

int Dispatch020649f4(void* a, void* b);
extern "C" void func_0206f81c(void* p);

struct Entry021baedc {
    char pad0[2];
    unsigned char f2;
    unsigned char f3;
    char pad4[8 - 4];
    unsigned short f8;
    char pad10[RegionOffset10a - 0xa];
    unsigned char f10a;
};

struct DispatchLocal0219fc88 {
    char pad0[0xc];
    int f0xc;
    char pad1[0x34 - 0x10];
};

// USA: func_ov017_0219fc88  (semantic: RunScriptAndRegisterEntryNode_0219fc88)
extern "C" ARM int func_ov017_0219fc88(void* unusedSelf, int scriptId) {
    GameState* battle = GameState::GetInstance();
    unsigned short* g = (unsigned short*)func_02012fe4();
    void* ctx;
    int success;
    void* self = func_ov017_0218b5b0();
    struct TailList020469b4* list = *(struct TailList020469b4**)((char*)self + 0x3000 + RegionOffset6fc);
    ctx = GetField0x3f8Address(battle);

    struct Obj02071488 objBuf;
    success = 0;

    if (RunScriptByValueRange02071574((unsigned short)scriptId, &objBuf) != NULL) {
        void* work = func_0205ec34();
        if (TestBitInByteArray((int)work, (unsigned char*)work + 0x8c, objBuf.f46 + 0x38e) == 0) {
            struct Entry021baedc* entry = *(struct Entry021baedc**)((char*)self + 0x3000 + RegionOffset734);

            if (entry->f2 != 0) {
                entry->f8 = scriptId;
            } else if (entry->f3 == 0) {
                func_ov017_021baedc(entry, 1);
                entry->f8 = scriptId;
                SetFlag0x9c6(*(struct SetFlagStruct**)((char*)self + 0x3000 + RegionOffset6d0), 1);
                AppendNodeToTail(list, (struct TailNode020469b4*)entry);
            }

            SetField108_021bd398(entry);

            if (*((unsigned char*)ctx + 0xd) != 0) entry->f10a = 1;
            success = 1;
        }
    }

    if (!success) {
        void* work2 = func_0205ec34();
        struct DispatchLocal0219fc88 d;
        d.f0xc = *g;
        if (Dispatch020649f4(work2, &d)) {
            func_0206f81c(&d);
        }
    }

    return success;
}
