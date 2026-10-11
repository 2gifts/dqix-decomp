#include <globaldefs.h>

#if defined(jpn)
enum { slotFieldOffset = 0x34ec };
#else
enum { slotFieldOffset = 0x36fc };
#endif
#include "GameState/GameState.h"

extern "C" void func_020ae074(void* a);
struct PointerField330_ffd0;
void* GetPointerAt0x330(struct PointerField330_ffd0* obj);
struct HeadNode02046b24;
int GetHeadNodeIdOrMinusOne(struct HeadNode02046b24** obj);
struct S02046b1c;
int GetField0x0List02046b1c(struct S02046b1c* p);

struct Struct020aca30 { char pad[slotFieldOffset]; void* fieldslotFieldOffset; };

// USA: func_020aca30
ARM void ProcessSlotEntry020aca30(struct Struct020aca30* a0) {
    GameState* battle = GameState::GetInstance();
    void* p;
    void* field = a0->fieldslotFieldOffset;
    p = GetPointerAt0x330((struct PointerField330_ffd0*)battle);
    int headId = GetHeadNodeIdOrMinusOne((struct HeadNode02046b24**)field);
    int f0 = GetField0x0List02046b1c((struct S02046b1c*)field);
    if (p == NULL) return;
    if (headId == 0xa) {
        if (*((unsigned char*)f0 + 3) != 0) return;
    }
    func_020ae074(p);
}
