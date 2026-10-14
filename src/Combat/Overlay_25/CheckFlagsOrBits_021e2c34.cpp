#include <globaldefs.h>

#if defined(jpn)
enum { kHolderFlagsOffset = 0xc };
#else
enum { kHolderFlagsOffset = 0x1c };
#endif

#include "GameState/GameState.h"

struct List02160094;
struct ListNode02160094;
struct BitFlags02037170;
struct S190;

struct ListNode02160094* GetNodeAtIndex02160094(struct List02160094* list, int index);
extern int data_ov025_021ef988;

// USA: func_ov025_021e2c34
ARM int CheckFlagsOrBits_021e2c34(void* unused, struct List02160094* list) {
    struct ListNode02160094* node = GetNodeAtIndex02160094(list, 0);
    if (!node) return 0;
    int id = *(unsigned short*)((char*)node + 0x20);
    GameState* battle = GameState::GetInstance();
    GameObject* c = battle->GetGameObjectByIndex(id);
    int flags = *(int*)((char*)&data_ov025_021ef988 + kHolderFlagsOffset);
    if (flags & 4) return 0;
    if (((Object3D*)((struct BitFlags02037170*)c))->HasAnimationStopped()) return 1;
    return ((Object3D*)((struct S190*)c))->GetOffset40Bit1() != 0;
}
