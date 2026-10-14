#include <globaldefs.h>

#if defined(jpn)
enum { kRegionalFieldOffset = 0x8c };
#else
enum { kRegionalFieldOffset = 0x6c };
#endif
#include "GameState/GameState.h"

struct Struct020a2928;
struct S_a28e0;

void* GetPointerFromArray0x3c_0201e838(unsigned char* obj, unsigned int index);
int GetFieldIfFlag4_020100f8(char* obj);
int CheckField0x245Bit0x2Set_020a2cc4(unsigned char* obj);
void SetOrClearField0x245Bit0x2_020a2cd8(unsigned char* obj, int flag);
void CopySubstateAndSetFlag4_020a2908(unsigned char* obj, struct Struct020a2928* src);
void CopySubstateAndSetFlag4_020a296c(unsigned char* obj, struct Struct020a2928* src);
void ClearFlagAt0x240_020a28d0(unsigned char* obj);
void SetFlagAt0x240_020a28c4(unsigned char* obj);
void ResetField270Block_020a28e0(struct S_a28e0* p);
void ClearFlag0x4At0x245_020a298c(unsigned char* obj);

extern "C" void* func_02012fe4(void);

struct PendingNode_021982ac {
    char pad00[0x2c];
    unsigned char kind : 7;
    unsigned char applied : 1;
    char pad2d[3];
    unsigned char substate[0x2c];
    unsigned char extra[0x14];
    struct PendingNode_021982ac* next;
};

struct Anchor_021982ac {
    unsigned int w[3];
};

extern "C" int func_02094b9c(struct PendingNode_021982ac* node, struct Anchor_021982ac* anchor);
void BlankFunction020a28dc(void* obj, int kind, void* substate, void* extra);

// USA: func_ov017_021982ac
extern "C" ARM void func_ov017_021982ac(void) {
    GameState* battle = GameState::GetInstance();
    void* ctx = func_02012fe4();
    GameObject* combatant = battle->GetUnknownGameObject();
    struct Anchor_021982ac anchor = *(struct Anchor_021982ac*)((char*)combatant + 0x44);
    struct PendingNode_021982ac* node;
    unsigned char* state;
    int applied;

    node = (struct PendingNode_021982ac*)GetPointerFromArray0x3c_0201e838((unsigned char*)ctx + kRegionalFieldOffset, 4);
    state = (unsigned char*)GetFieldIfFlag4_020100f8((char*)battle);
    if (state == 0) {
        return;
    }

    applied = 0;
    while (node != 0) {
        if (func_02094b9c(node, &anchor)) {
            int kind = node->kind;
            if (kind == 4) {
                if (CheckField0x245Bit0x2Set_020a2cc4(state)) {
                    SetOrClearField0x245Bit0x2_020a2cd8(state, 0);
                }
                CopySubstateAndSetFlag4_020a2908(state, (struct Struct020a2928*)node->substate);
                applied = 1;
            } else if (kind == 5) {
                CopySubstateAndSetFlag4_020a296c(state, (struct Struct020a2928*)node->substate);
                applied = 1;
            } else {
                BlankFunction020a28dc(state, kind, node->substate, node->extra);
            }
            if (!node->applied) {
                ClearFlagAt0x240_020a28d0(state);
            }
            break;
        }
        node = node->next;
    }

    if (node == 0) {
        SetFlagAt0x240_020a28c4(state);
        ResetField270Block_020a28e0((struct S_a28e0*)state);
    }
    if (!applied) {
        ClearFlag0x4At0x245_020a298c(state);
    }
}
