// JPN: func_ov017_02198e5c
#include <globaldefs.h>

#if defined(jpn)
enum { kRegionalFieldOffset = 0x8c };
#else
enum { kRegionalFieldOffset = 0x6c };
#endif
#include "GameState/GameState.h"

struct Struct020a2928;
struct S_a28e0;

void* GetPointerFromArray0x3c(unsigned char* obj, unsigned int index);
int GetFieldIfFlag4(char* obj);
int CheckField0x245Bit0x2Set(unsigned char* obj);
void SetOrClearField0x245Bit0x2(unsigned char* obj, int flag);
extern "C" void _Z32CopySubstateAndSetFlag4_020a2908PhP14Struct020a2928(unsigned char* obj, struct Struct020a2928* src);
extern "C" void _Z32CopySubstateAndSetFlag4_020a296cPhP14Struct020a2928(unsigned char* obj, struct Struct020a2928* src);
void ClearFlagAt0x240(unsigned char* obj);
void SetFlagAt0x240(unsigned char* obj);
void ResetField270Block(struct S_a28e0* p);
void ClearFlag0x4At0x245(unsigned char* obj);

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
extern "C" void _Z21BlankFunction020a28dcv(unsigned char* obj, int kind, void* substate, void* extra);

// USA: func_ov017_021982ac
extern "C" ARM void func_ov017_021982ac(void) {
    GameState* battle = GameState::GetInstance();
    void* ctx = func_02012fe4();
    GameObject* combatant = battle->GetUnknownGameObject();
    struct Anchor_021982ac anchor = *(struct Anchor_021982ac*)((char*)combatant + 0x44);
    struct PendingNode_021982ac* node;
    unsigned char* state;
    int applied;

    node = (struct PendingNode_021982ac*)GetPointerFromArray0x3c((unsigned char*)ctx + kRegionalFieldOffset, 4);
    state = (unsigned char*)GetFieldIfFlag4((char*)battle);
    if (state == 0) {
        return;
    }

    applied = 0;
    while (node != 0) {
        if (func_02094b9c(node, &anchor)) {
            int kind = node->kind;
            if (kind == 4) {
                if (CheckField0x245Bit0x2Set(state)) {
                    SetOrClearField0x245Bit0x2(state, 0);
                }
                _Z32CopySubstateAndSetFlag4_020a2908PhP14Struct020a2928(state, (struct Struct020a2928*)node->substate);
                applied = 1;
            } else if (kind == 5) {
                _Z32CopySubstateAndSetFlag4_020a296cPhP14Struct020a2928(state, (struct Struct020a2928*)node->substate);
                applied = 1;
            } else {
                _Z21BlankFunction020a28dcv(state, kind, node->substate, node->extra);
            }
            if (!node->applied) {
                ClearFlagAt0x240(state);
            }
            break;
        }
        node = node->next;
    }

    if (node == 0) {
        SetFlagAt0x240(state);
        ResetField270Block((struct S_a28e0*)state);
    }
    if (!applied) {
        ClearFlag0x4At0x245(state);
    }
}
