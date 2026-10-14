#include <globaldefs.h>
#include "GameState/GameState.h"

struct Element020de650 { unsigned int v[8]; };
struct Container020dedd0 {
    unsigned short count;
    unsigned char pad[10];
    struct Element020de650* base;
    unsigned char pad2[4];
    unsigned char useBinarySearch;
};
struct Slots0208386c { unsigned char pad[0x454]; short slots[8]; };
struct KeyMap020a0a08 { short* keys; signed char* vals; short count; };

struct Element020de650* FindElementByKey020dedd0(struct Container020dedd0* c, int key);
int TryDecrementAndAdjustField_020dddcc(void* obj);
void* GetPtrField0x2a04_02010828(GameState* battleStruct);
int DecrementKeyValue020a0a08(struct KeyMap020a0a08* map, int key, int amount);
extern "C" int func_020ddcbc(int n, int idx, struct Container020dedd0* container, int unused4);
GameObject* GetCombatantWithFlag0x100_0200ff1c(GameState* battleStruct, int combatantId);
int GetFieldAt0x150_02053c6c(unsigned char* obj);
void RemoveSlotShiftDown0208386c(struct Slots0208386c* s, int idx);

// USA: func_ov002_0215a7b4  (semantic: ApplyElementRemovalOrDecrement_0215a7b4)
extern "C" ARM void func_ov002_0215a7b4(char* self, int type, int key, int extra, unsigned char flag) {
    GameState* battle = GameState::GetInstance();
    if (type == 4) {
        if (flag != 0) {
            struct Element020de650* elem = FindElementByKey020dedd0((struct Container020dedd0*)(self + 0x7ec), key);
            if (elem != 0) {
                TryDecrementAndAdjustField_020dddcc(elem);
            }
        } else {
            void* p2a04 = GetPtrField0x2a04_02010828(battle);
            DecrementKeyValue020a0a08((struct KeyMap020a0a08*)p2a04, key, 1);
        }
        *(unsigned char*)(self + 0x2478) = 1;
        return;
    }
    if (flag != 0) {
        func_020ddcbc(type, extra, (struct Container020dedd0*)(self + 0x7ec), 0);
    } else {
        GameObject* combatant = GetCombatantWithFlag0x100_0200ff1c(battle, type);
        if (combatant == 0) return;
        {
            int field150 = GetFieldAt0x150_02053c6c((unsigned char*)combatant);
            RemoveSlotShiftDown0208386c((struct Slots0208386c*)field150, (signed char)extra);
        }
    }
    *(unsigned char*)(self + 0x2478) = 1;
}
