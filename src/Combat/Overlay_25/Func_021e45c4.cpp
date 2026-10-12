#include <globaldefs.h>

#if defined(jpn)
#define func_ov025_021e45c4 func_ov025_021e4ab4
#endif
#include "GameState/GameState.h"

struct List02160094;
struct ListNode02160094;
struct List021600f8;
struct ListNode021600f8;

struct ListNode02160094* GetNodeAtIndex02160094(struct List02160094* list, int index);
struct ListNode021600f8* GetNodeAtIndex021600f8(struct List021600f8* list, int index);
extern "C" void func_02033920(void* combatant, int arg1, int arg2);

// USA: func_ov025_021e45c4  (semantic: Func_021e45c4)
extern "C" ARM int func_ov025_021e45c4(void* unused, void* list) {
    struct ListNode02160094* a = GetNodeAtIndex02160094((struct List02160094*)list, 0);
    struct ListNode021600f8* b = GetNodeAtIndex021600f8((struct List021600f8*)list, 0);
    if (a == 0 || b == 0) return 1;
    GameState* bs = GameState::GetInstance();
    GameObject* c = bs->GetCombatantByIndex(*(unsigned short*)((char*)a + 0x20));
    if (c != 0) {
        func_02033920(c, *(short*)((char*)b + 0xe), 0);
    }
    return 1;
}
