#include <globaldefs.h>

#if defined(jpn)
enum { slotFieldOffset = 0x34ec, otherFieldOffset = 0x508 };
#else
enum { slotFieldOffset = 0x36fc, otherFieldOffset = 0x718 };
#endif
#include "GameState/GameState.h"

struct PointerField32c_ffc0;
void* GetPointerAt0x32c(struct PointerField32c_ffc0* obj);
struct HeadNode02046b24;
int GetHeadNodeIdOrMinusOne(struct HeadNode02046b24** obj);
struct S02046b1c;
int GetField0x0List02046b1c(struct S02046b1c* p);
struct Obj020a7eb8;
void OffsetPositionYAndDispatch(struct Obj020a7eb8* obj);
int IsField600B4Zero_021b8b54(void* obj);
extern "C" void* func_02057924(void* obj);
extern "C" void func_02057ab8(void* g, int arg);

struct Struct020a66a4 {
    char pad0[slotFieldOffset];
    void* fieldslotFieldOffset;
};

struct Sub3000_020a66a4 {
    char pad0[otherFieldOffset];
    void* fieldotherFieldOffset;
};

// USA: func_020a66a4  (semantic: DispatchIfHeadEligible020a66a4)
extern "C" ARM void func_020a66a4(struct Struct020a66a4* a0) {
    void* p;
    void* field;
    int headId;
    void* g;
    void* other;
    GameState* battle = GameState::GetInstance();
    field = a0->fieldslotFieldOffset;
    p = GetPointerAt0x32c((struct PointerField32c_ffc0*)battle);
    headId = GetHeadNodeIdOrMinusOne((struct HeadNode02046b24**)field);
    GetField0x0List02046b1c((struct S02046b1c*)field);
    struct Sub3000_020a66a4* sub = (struct Sub3000_020a66a4*)((char*)a0 + 0x3000);
    other = sub->fieldotherFieldOffset;
    g = func_02057924(sub);
    if (p == NULL) return;
    if (headId == 0xa && *((unsigned char*)other + 3) != 0) {
        if (IsField600B4Zero_021b8b54(other)) return;
    }
    OffsetPositionYAndDispatch((struct Obj020a7eb8*)p);
    func_02057ab8(g, 0xc9);
}
