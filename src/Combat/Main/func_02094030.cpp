#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct CopyPayload {
    char data[0x30];
};

struct CopyableRecord {
    struct CopyPayload payload;
    short f30;
    signed char f32;
    unsigned char f33;
};

struct Ctx02094030 {
    struct CopyableRecord records[8];
    char pad0[0x3cb - 0x1a0];
    signed char count;
    char pad1[0x3cd - 0x3cc];
    unsigned char flags;
};

extern "C" void _Z19ClearRegion02093980Pc(char* obj);
void CopyRecord(struct CopyableRecord* dst, struct CopyableRecord* src);
int ClassifyByTenThousands(int x);
extern "C" void* func_0202ae18(void);
extern "C" int func_0202c540(void* obj);

// USA: func_02094030
extern "C" ARM int func_02094030(struct Ctx02094030* obj, int value, int unused2, int slot) {
    GameObject* combatant = GameState::GetInstance()->GetPartyMemberByIndex(slot);
    void* ctx = func_0202ae18();
    char* base = (char*)func_ov017_0218b5b0();

    if (func_0202c540(ctx) != 0) {
        if (value == 10000) return 1;
    }
    if (obj->count >= 8) return 1;

    struct CopyableRecord* rec = &obj->records[obj->count];
    _Z19ClearRegion02093980Pc((char*)rec);

    if (combatant == 0 || value == 3) {
        char* src = base + 0x435c + slot * 0x30;
        if (src[0] == 0) return 1;
        sprintf((char*)rec, src);
    } else if (combatant != 0) {
        sprintf((char*)rec, (const char*)combatant->baseStats_);
    }

    rec->f30 = (short)value;
    rec->f32 = (signed char)slot;
    if (obj->count <= 0) {
        obj->flags |= 1;
    }

    unsigned int rank = (unsigned int)ClassifyByTenThousands(rec->f30);
    obj->count = obj->count + 1;

    int i;
    for (i = obj->count - 1; i >= 2; i--) {
        if (ClassifyByTenThousands(obj->records[i - 1].f30) <= rank) break;
        struct CopyableRecord tmp;
        CopyRecord(&tmp, &obj->records[i]);
        CopyRecord(&obj->records[i], &obj->records[i - 1]);
        CopyRecord(&obj->records[i - 1], &tmp);
    }
    return 0;
}
