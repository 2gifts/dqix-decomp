#include <globaldefs.h>

#if defined(jpn)
enum { slotFieldOffset = 0x34ec };
#else
enum { slotFieldOffset = 0x36fc };
#endif
#include "GameState/GameState.h"

extern "C" void* func_02012fe4(GameState* battleStruct);
struct PointerField330_ffd0;
void* GetPointerAt0x330(struct PointerField330_ffd0* obj);
struct HeadNode02046b24;
int GetHeadNodeIdOrMinusOne(struct HeadNode02046b24** obj);
struct S02046b1c;
int GetField0x0List02046b1c(struct S02046b1c* p);
extern "C" int _Z28IsBrightnessTransitionActiveP13GameResources(int* obj);
extern "C" void func_020ad61c(void* p);
extern "C" void func_ov017_02193dc4(void* p);

struct Struct020ac9ac { char pad[slotFieldOffset]; void* fieldslotFieldOffset; };

// USA: func_020ac9ac  (semantic: ProcessSlotEntry020ac9ac)
extern "C" ARM void func_020ac9ac(struct Struct020ac9ac* a0) {
    GameState* battle = GameState::GetInstance();
    void* p;
    int headId;
    void* field = a0->fieldslotFieldOffset;
    func_02012fe4(battle);
    p = GetPointerAt0x330((struct PointerField330_ffd0*)battle);
    headId = GetHeadNodeIdOrMinusOne((struct HeadNode02046b24**)field);
    int f0 = GetField0x0List02046b1c((struct S02046b1c*)field);
    if (p == NULL) return;
    if (headId == 0xa) {
        if (*((unsigned char*)f0 + 3) != 0) return;
    }
    if (headId == 3) {
        if (_Z28IsBrightnessTransitionActiveP13GameResources((int*)a0) == 0) return;
    }
    func_020ad61c(p);
    func_ov017_02193dc4(p);
}
