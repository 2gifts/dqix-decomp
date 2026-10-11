#include <globaldefs.h>
#include <std_library_functions.h>
#include "GameState/GameState.h"

struct SearchStruct0202c1a4;
struct BitArrayObj0205e854;

struct SlotPair_021b0288 {
    unsigned char combatant;
    unsigned char slot;
};

struct SlotState_021b0288 {
    char unk0[0x4];
    signed char* command;
    char unk8[0x1];
    unsigned char mode;
    unsigned char result;
    char unkB[0x10];
    unsigned char slots[4];
    char unk1F[0x24];
    unsigned char order[4];
    unsigned char orderCount;
};

extern "C" SearchStruct0202c1a4* func_0202ae18(void);
unsigned char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);
GameObject* GetCombatantWithFlag0x1000(GameState* battleStruct, int combatantId);
void SetField0x2d0(void* obj, unsigned char value);
extern "C" void func_ov017_021c32b0(SlotPair_021b0288* pairs, int count);
void SetField0x3acValue(GameState* gs, int value);
extern "C" void func_ov017_02191108(void* unused, int c, int d, int e, int flag);
extern "C" void func_ov017_021b0a7c(SlotState_021b0288* obj);
extern "C" void func_ov017_021d0b30(int a, int b, int c);
void* GetData02100044(void);
void* FillBitArray0x1524WithFF(struct BitArrayObj0205e854* obj);

// JPN: func_ov017_021b0920
// USA: func_ov017_021b0288
extern "C" ARM int func_ov017_021b0288(SlotState_021b0288* obj) {
    if (obj->slots[0] != 0) {
        if (obj->mode == 2) {
            GameObject* combatant;
            int j;
            int i;
            int count;
            GameResources* resources;
            SearchStruct0202c1a4* search;
            GameState* battle;
            unsigned char slots[4];
            SlotPair_021b0288 pairs[4];
            battle = GameState::GetInstance();
            search = func_0202ae18();
            resources = func_ov017_0218b5b0();
            count = 0;
            pairs[count].combatant = 0;
            pairs[count].slot = GetSearchStructCurrentArrEntry(search);
            count++;
            memcpy(slots, obj->slots, 4);
            for (i = 3; i >= 1; i--) {
                combatant = GetCombatantWithFlag0x1000(battle, i);
                if (combatant == 0) continue;
                for (j = 3; j >= 1; j--) {
                    if (slots[j] == 3) {
                        pairs[count].combatant = i;
                        pairs[count].slot = j;
                        SetField0x2d0(combatant, GetSearchStructCurrentArrEntry(search));
                        slots[j] = 0;
                        count++;
                        break;
                    }
                }
            }
            func_ov017_021c32b0(pairs, count);
            obj->orderCount = count;
            for (int k = 0; k < count; k++) {
                obj->order[k] = pairs[k].slot;
            }
            SetField0x3acValue(battle, GetSearchStructCurrentArrEntry(search));
            int flag = 1;
            if (obj->command != 0 && *obj->command == 10) flag = 0;
            func_ov017_02191108(resources, 1, flag, 1, 1);
        }
        func_ov017_021b0a7c(obj);
        func_ov017_021d0b30(2, 0, 0);
        if (obj->mode != 2) return 0xb;
        FillBitArray0x1524WithFF((BitArrayObj0205e854*)GetData02100044());
        return 6;
    }
    return obj->result;
}
