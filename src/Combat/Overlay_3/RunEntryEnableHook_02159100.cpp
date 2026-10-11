#include <globaldefs.h>



struct Obj0205d2bc;
void InitEntries0205d2bc(struct Obj0205d2bc* obj);
void SetFieldsAt0x4And0x8(int* obj, int a, int b);
struct Outer020e28dc;
int GetInnerFlagBit0020e28dc(struct Outer020e28dc* o);
struct Entry020e2cc4;
void SetEntryEnabled020e2cc4(struct Entry020e2cc4* obj, int enabled);
struct SelfState020e2834;
void SetYesNoButtonPalette020e2834(struct SelfState020e2834* self);

// USA: func_ov003_02159100  (semantic: RunEntryEnableHook_02159100)
// JPN: func_ov003_0215a5ec
extern "C" ARM void func_ov003_02159100(void* obj) {
    unsigned char* base = (unsigned char*)obj;

    if (*(signed char*)(base + 0x588) == 0) return;
    if (*(unsigned char*)(base + 0x587) != 0) return;

    InitEntries0205d2bc((struct Obj0205d2bc*)(base + 0xf4));

    if (*(void**)(base + 0x570) == NULL) return;

    unsigned char* r4 = *(unsigned char**)((char*)(*(void**)(base + 0x570)) + 0x10);
    int flag;
    SetFieldsAt0x4And0x8((int*)(r4 + 0x28), 0x11, 1);
    flag = GetInnerFlagBit0020e28dc((struct Outer020e28dc*)*(void**)(base + 0x570));
    SetEntryEnabled020e2cc4((struct Entry020e2cc4*)(r4 + 0x28), flag);
    SetYesNoButtonPalette020e2834((struct SelfState020e2834*)*(void**)(base + 0x570));
}
