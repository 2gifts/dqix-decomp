#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

extern "C" void* func_02057924(void);
extern "C" void func_02057f00(void* obj, int value);
void* GetActiveCombatWork(void);
extern "C" void* func_ov000_02160f14(void* obj);
int GetField0x3b0Value(GameState* battleStruct);
void SetField0x3b0Value(GameState* battleStruct, int value);
void ClearCombatantSlot(GameState* battleStruct, int id);
extern "C" void _ZN8Object3D7DestroyEv(unsigned char* obj);
struct Container02037364;
extern "C" void _ZN8Object3D26RemoveAnimationPackageByIDEi(struct Container02037364* obj, int key);
struct S1a0;
extern "C" void _ZN8Object3D23SetCurrentAnimationTimeEi(struct S1a0* obj, unsigned int v);
extern "C" void _ZN8Object3D24MaybeSetRegularAnimationEPKci(void* obj, void* member, int arg3);

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
    GetField0x3b0Value(battle);

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
                _ZN8Object3D26RemoveAnimationPackageByIDEi((struct Container02037364*)combatant, node->id4);
                _ZN8Object3D24MaybeSetRegularAnimationEPKci(combatant, buf, b);
                _ZN8Object3D23SetCurrentAnimationTimeEi((struct S1a0*)combatant, saved);
            }
            break;
        }
        case 1:
            func_02057f00(g, node->id4);
            break;
        case 3:
            SetField0x3b0Value(battle, (int)func_ov000_02160f14(GetActiveCombatWork()));
            break;
        case 4: {
            GameObject* combatant = battle->GetGameObjectByIndex(node->id2);
            if (combatant) {
                _ZN8Object3D7DestroyEv((unsigned char*)combatant);
                ClearCombatantSlot(battle, node->id2);
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
