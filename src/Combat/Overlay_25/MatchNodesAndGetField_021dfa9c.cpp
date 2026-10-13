#include <globaldefs.h>
#include "GameState/GameState.h"

void* GetSlotPtr02160f20(void* obj);
int GetIntFieldFromOffset5000_02160f9c(void* obj);
struct List02160094;
struct ListNode02160094;
struct ListNode02160094* GetNodeAtIndex02160094(struct List02160094* list, int index);
struct List021600f8;
struct ListNode021600f8;
struct ListNode021600f8* GetNodeAtIndex021600f8(struct List021600f8* list, int index);
int CheckSubstructFlag0x80(unsigned char* obj);
extern "C" short func_ov000_0215ffa0(void* obj);
int GetField0Result02169aa4(void* obj, int type, void* out, int flag);

// USA: func_ov025_021dfa9c  (semantic: MatchNodesAndGetField_021dfa9c)
extern "C" ARM int func_ov025_021dfa9c(void* obj, void* base) {
    GameState* battle = GameState::GetInstance();
    void* slot = GetSlotPtr02160f20(obj);
    int count = GetIntFieldFromOffset5000_02160f9c(obj);
    struct ListNode02160094* node = GetNodeAtIndex02160094((struct List02160094*)slot, 0);
    int flagVal;
    GameObject* combatant;
    char* target;
    struct ListNode02160094* node2;
    struct ListNode021600f8* nodeA;
    struct ListNode021600f8* nodeB;
    int localBuf[2];
    int result;

    if (node == NULL) goto fail;
    flagVal = *(unsigned short*)slot;
    combatant = battle->GetCombatantByIndex(*(unsigned short*)((char*)node + 0x20));
    if (combatant == NULL) goto fail;
    if (count <= 0) goto fail;
    if (flagVal != 1) goto fail;
    if (!CheckSubstructFlag0x80((unsigned char*)combatant)) goto fail;

    target = (char*)base + 0x21c + 0x8000 + (count - 1) * 0x28;
    if (target == NULL) goto fail;

    node2 = GetNodeAtIndex02160094((struct List02160094*)target, 0);
    if (node2 == NULL) goto fail;
    if (*(unsigned short*)((char*)node2 + 0x20) != *(unsigned short*)((char*)node + 0x20)) goto fail;

    nodeA = GetNodeAtIndex021600f8((struct List021600f8*)slot, 0);
    nodeB = GetNodeAtIndex021600f8((struct List021600f8*)target, 0);
    if (nodeA == NULL || nodeB == NULL) goto fail;
    if (*(short*)((char*)nodeA + 0xe) != *(short*)((char*)nodeB + 0xe)) goto fail;
    if (*(unsigned short*)target != 1) goto fail;

    if (*(short*)((char*)nodeB + 0xe) != func_ov000_0215ffa0(nodeB)) goto fail;

    result = GetField0Result02169aa4(combatant, flagVal, &localBuf[0], 2);
    if (result >= 2) return localBuf[1];

fail:
    return 0;
}
