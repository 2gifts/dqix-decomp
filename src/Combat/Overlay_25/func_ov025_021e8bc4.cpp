#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "std_library_functions.h"
#include "GameState/GameState.h"

extern "C" void* func_02057924(void);
extern "C" void func_02057f00(void* obj, int value);
void* GetActiveCombatWork_ov000_02160130(void);
extern "C" void* func_ov000_02160f14(void* obj);
void SetField0x3b0Value_020100c4(GameState* battleStruct, int value);
void ClearCombatantSlot_0200fd48(GameState* battleStruct, int id);
struct Container02037364;
struct S1a0;

struct Node021e8bc4 {
    unsigned char type;
    unsigned char priority;
    unsigned short id2;
    unsigned short id4;
    struct Node021e8bc4* next;
};
struct Obj021e8bc4 {
    char pad[0x1d8];
    struct Node021e8bc4* head;
};

// USA: func_ov025_021e8bc4
extern "C" ARM void func_ov025_021e8bc4(struct Obj021e8bc4* obj, int priority) {
    if (!obj->head) return;

    GameState* battle = GameState::GetInstance();
    void* g = func_02057924();
    GetField0x3b0Value_020100bc(battle);

    struct Node021e8bc4* node = obj->head;
    while (node != 0 && priority <= node->priority) {
        switch (node->type) {
        case 0: {
            GameObject* combatant = battle->GetGameObjectByIndex(node->id2);
            if (combatant) {
                char* name = *(char**)((char*)combatant + 0x14);
                char buf[0x28];
                if (name) strcpy(buf, name);
                unsigned char b = *(unsigned char*)((char*)combatant + 0x19);
                unsigned int saved = *(unsigned int*)((char*)combatant + 0x1c);
                ((Object3D*)((struct Container02037364*)combatant))->RemoveAnimationPackageByID(node->id4);
                ((Object3D*)combatant)->MaybeSetRegularAnimation((char const*)buf, b);
                ((Object3D*)((struct S1a0*)combatant))->SetCurrentAnimationTime(saved);
            }
            break;
        }
        case 1:
            func_02057f00(g, node->id4);
            break;
        case 3:
            SetField0x3b0Value_020100c4(battle, (int)func_ov000_02160f14(GetActiveCombatWork_ov000_02160130()));
            break;
        case 4: {
            GameObject* combatant = battle->GetGameObjectByIndex(node->id2);
            if (combatant) {
                ((Object3D*)((unsigned char*)combatant))->Destroy();
                ClearCombatantSlot_0200fd48(battle, node->id2);
            }
            break;
        }
        default:
            break;
        }
        node = node->next;
    }
    obj->head = node;
}
