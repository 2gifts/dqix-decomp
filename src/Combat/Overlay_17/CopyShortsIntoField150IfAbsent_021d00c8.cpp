#include <globaldefs.h>
#include "GameState/GameState.h"

void* GetPtrField0x2a04(GameState* battleStruct);
GameObject* GetCombatantWithFlag0x100(GameState* battleStruct, int combatantId);
int GetFieldAt0x150(unsigned char* obj);

struct Obj_021d00c8 {
    int id;
    unsigned char idx;
    unsigned char count;
    short arr[6];
};

// USA: func_ov017_021d00c8
ARM void CopyShortsIntoField150IfAbsent_021d00c8(int unused0, char* p1raw, GameState* bs) {
    struct Obj_021d00c8* p1 = (struct Obj_021d00c8*)(p1raw + 4);
    int id = p1->id;
    unsigned char* list = (unsigned char*)GetPtrField0x2a04(bs);
    int i;
    for (i = 0; i < list[0xf7c]; i++) {
        unsigned char* row = list + i;
        if (id == row[0xf78]) return;
    }

    GameObject* c = GetCombatantWithFlag0x100(bs, id);
    if (!c) return;
    int field150 = GetFieldAt0x150((unsigned char*)c);
    if (!field150) return;

    char* dst = (char*)field150 + 0x454;
    unsigned char idx = p1->idx;
    unsigned char cnt = p1->count;
    for (int j = 0; j < cnt; j++) {
        *(short*)(dst + (idx + j) * 2) = p1->arr[j];
    }
}
