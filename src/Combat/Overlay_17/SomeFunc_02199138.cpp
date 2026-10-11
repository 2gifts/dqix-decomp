#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_02012fe4(void);
extern "C" void* func_0205ec34(void);
int LookupAndForEachNode020649b0(void* a, int mode, void* c);
extern "C" void func_0206f81c(void* p);
extern "C" void func_ov017_021b57fc(void* obj);
struct TailList020469b4;
struct TailNode020469b4;
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);

struct LocalC02199138 {
    char pad0[0xc];
    int f0xc;
    char pad1[0x24 - 0x10];
    int f0x24;
    char pad2[0x34 - 0x28];
};

// JPN: func_ov017_02199ce8
// USA: func_ov017_02199138  (semantic: SomeFunc_02199138)
extern "C" ARM void func_ov017_02199138(char* self) {
#if defined(jpn)
 enum {regionalOffset0=0x8dc, regionalOffset1=0x4ac, regionalOffset2=0x3400, regionalOffset3=0xa6, regionalOffset4=0x4ec};
#else
 enum {regionalOffset0=0xafc, regionalOffset1=0x6bc, regionalOffset2=0x3600, regionalOffset3=0xb6, regionalOffset4=0x6fc};
#endif
    GameState* bs = GameState::GetInstance();
    GameObject* combatant = bs->GetUnknownGameObject();
    unsigned short* h = (unsigned short*)func_02012fe4();
    if (*((unsigned char*)(*(void**)(self + 0x3000 + regionalOffset0)) + 2) != 0) {
        return;
    }
    void* r = func_0205ec34();
    struct LocalC02199138 c;
    c.f0xc = *h;
    c.f0x24 = *(unsigned short*)(*(void**)(self + 0x3000 + regionalOffset1));
    if (LookupAndForEachNode020649b0(r, 0x17, &c)) {
        func_0206f81c(&c);
        return;
    }
    func_ov017_021b57fc(*(void**)(self + 0x3000 + regionalOffset0));
    *(int*)((char*)(*(void**)(self + 0x3000 + regionalOffset0)) + 0x1c) = (int)combatant;
    *(unsigned short*)((char*)(*(void**)(self + 0x3000 + regionalOffset0)) + 0x10) =
        *(unsigned short*)(self + regionalOffset2 + regionalOffset3);
    AppendNodeToTail((struct TailList020469b4*)(*(void**)(self + 0x3000 + regionalOffset4)),
                      (struct TailNode020469b4*)(*(void**)(self + 0x3000 + regionalOffset0)));
}
