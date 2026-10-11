#if defined(jpn)
#define R(j,u) (j)
#define func_ov005_02155d6c func_ov005_0215735c
#define func_ov005_02159c88 func_ov005_0215b1d4
#define func_ov005_0215a2c8 func_ov005_0215b81c
#define func_ov005_0215a37c func_ov005_0215b8d0
#define func_ov005_0215a3bc func_ov005_0215b910
#define func_ov005_0215a418 func_ov005_0215b96c
#define func_ov005_0215a620 func_ov005_0215bb74
#define func_ov005_0215a720 func_ov005_0215bc6c
#define func_ov005_0215aa44 func_ov005_0215bf64
#define func_ov005_0215ae7c func_ov005_0215c33c
#define func_ov005_0215b0a0 func_ov005_0215c4b4
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct Obj0205d2bc;
void InitEntries0205d2bc(struct Obj0205d2bc* obj);
extern "C" void func_ov005_0215a620(void* obj);
extern "C" void func_0204b088(void* p, int flag);
struct Entry020e2cc4;
void SetFieldsAt0x4And0x8(int* obj, int a, int b);
extern "C" void func_ov005_0215ae7c(void* obj);
struct Outer020e28dc;
int GetInnerFlagBit0020e28dc(struct Outer020e28dc* o);
void SetEntryEnabled020e2cc4(struct Entry020e2cc4* obj, int enabled);
struct SelfState020e2834;
void SetYesNoButtonPalette020e2834(struct SelfState020e2834* self);
extern "C" void func_ov005_02155d6c(void* obj);

// USA: func_ov005_02155108
ARM void RunTurnStartHooks02155108(void* obj) {
    unsigned char* base = (unsigned char*)obj;

    if (*(unsigned char*)(base + 0x3000 + R(0xd3c, 0xdc4)) != 0xff) return;

    InitEntries0205d2bc((struct Obj0205d2bc*)(base + R(0xee0, 0x2e4 + 0xc00)));
    func_ov005_0215a620(obj);

    if (*(int*)(base + 0x3000 + R(0xd44, 0xdcc)) & 0x100) {
        func_0204b088(base + R(0xea0, 0x2a4 + 0xc00), 0);
        *(int*)(base + 0x3000 + R(0xd44, 0xdcc)) &= ~0x100;
    }

    if (*(int*)(base + 0x3000 + R(0xd44, 0xdcc)) & 0x200) {
        func_ov005_0215ae7c(obj);
        *(int*)(base + 0x3000 + R(0xd44, 0xdcc)) &= ~0x200;
    }

    if (*(void**)(base + R(0xe60, 0xe64)) != NULL) {
        unsigned char* r5 = *(unsigned char**)((unsigned char*)(*(void**)(base + R(0xe60, 0xe64))) + 0x10);
        int flag;
        SetFieldsAt0x4And0x8((int*)(r5 + 0x28), 0x1f, 1);
        flag = GetInnerFlagBit0020e28dc((struct Outer020e28dc*)*(void**)(base + R(0xe60, 0xe64)));
        SetEntryEnabled020e2cc4((struct Entry020e2cc4*)(r5 + 0x28), flag);
        SetYesNoButtonPalette020e2834((struct SelfState020e2834*)*(void**)(base + R(0xe60, 0xe64)));
    }

    func_ov005_02155d6c(obj);
}
