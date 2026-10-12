#include <globaldefs.h>

#if defined(jpn)
enum { kHolderFlagsOffset = 0xc };
#else
enum { kHolderFlagsOffset = 0x1c };
#endif


#if defined(jpn)
#define CheckFlagsOrBits_021e2c34 func_ov025_021e3124
#endif
#include "GameState/GameState.h"

struct List02160094;
struct ListNode02160094;
struct BitFlags02037170;
struct S190;

struct ListNode02160094* GetNodeAtIndex02160094(struct List02160094* list, int index);
extern "C" int _ZNK8Object3D19HasAnimationStoppedEv(struct BitFlags02037170* obj);
extern "C" int _ZNK8Object3D15GetOffset40Bit1Ev(struct S190* obj);
extern int data_ov025_021ef988;

// USA: func_ov025_021e2c34
#if defined(jpn)
extern "C"
#endif
ARM int CheckFlagsOrBits_021e2c34(void* unused, struct List02160094* list) {
    struct ListNode02160094* node = GetNodeAtIndex02160094(list, 0);
    if (!node) return 0;
    int id = *(unsigned short*)((char*)node + 0x20);
    GameState* battle = GameState::GetInstance();
    GameObject* c = battle->GetGameObjectByIndex(id);
    int flags = *(int*)((char*)&data_ov025_021ef988 + kHolderFlagsOffset);
    if (flags & 4) return 0;
    if (_ZNK8Object3D19HasAnimationStoppedEv((struct BitFlags02037170*)c)) return 1;
    return _ZNK8Object3D15GetOffset40Bit1Ev((struct S190*)c) != 0;
}
