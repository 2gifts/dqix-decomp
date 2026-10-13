#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

#if defined(jpn)
#define _Z19ClearRegion02093980Pc func_020942ac
#endif

struct CopyPayload {
#if defined(jpn)
    char data[0xb];
#else
    char data[0x30];
#endif
};

struct CopyableRecord {
    struct CopyPayload payload;
#if defined(jpn)
    unsigned char byte11;
#endif
    short requestId;
    signed char partySlot;
    unsigned char flags;
};

struct Ctx02094030 {
    struct CopyableRecord records[8];
#if defined(jpn)
    char pad0[0x13b - 0x80];
#else
    char pad0[0x3cb - 0x1a0];
#endif
    signed char count;
    char pad1[0x3cd - 0x3cc];
    unsigned char flags;
};

struct PartyNameCache {
#if defined(jpn)
    unsigned char unknown0[0x413c];
    char names[4][12];
#else
    unsigned char unknown0[0x435c];
    char names[4][48];
#endif
};

extern "C" void _Z19ClearRegion02093980Pc(char* obj);
#if defined(jpn)
extern "C" void func_0209446c(struct CopyableRecord* dst, struct CopyableRecord* src);
#define CopyRecord func_0209446c
#else
void CopyRecord(struct CopyableRecord* dst, struct CopyableRecord* src);
#endif
int ClassifyByTenThousands(int x);
extern "C" void* func_0202ae18(void);
extern "C" int func_0202c540(void* obj);

// USA: func_02094030


extern "C" ARM int func_02094030(struct Ctx02094030* queue, int requestId, int unused2, int slot) {
    GameObject* combatant = GameState::GetInstance()->GetPartyMemberByIndex(slot);
    void* ctx = func_0202ae18();
    PartyNameCache* cachedNames = reinterpret_cast<PartyNameCache*>(func_ov017_0218b5b0());

    if (func_0202c540(ctx) != 0) {
        if (requestId == 10000) return 1;
    }
    if (queue->count >= 8) return 1;

    struct CopyableRecord* request = &queue->records[queue->count];
    _Z19ClearRegion02093980Pc((char*)request);

    if (combatant == 0 || requestId == 3) {
        char* name = cachedNames->names[slot];
        if (name[0] == 0) return 1;
        sprintf(request->payload.data, name);
    } else if (combatant != 0) {
        sprintf(request->payload.data, combatant->baseStats_->unk);
    }

    request->requestId = (short)requestId;
    request->partySlot = (signed char)slot;
    if (queue->count <= 0) {
        queue->flags |= 1;
    }

    unsigned int category = (unsigned int)ClassifyByTenThousands(request->requestId);
    queue->count++;

    int i;
    for (i = queue->count - 1; i >= 2; i--) {
        if (ClassifyByTenThousands(queue->records[i - 1].requestId) <= category) break;
        struct CopyableRecord tmp;
        CopyRecord(&tmp, &queue->records[i]);
        CopyRecord(&queue->records[i], &queue->records[i - 1]);
        CopyRecord(&queue->records[i - 1], &tmp);
    }
    return 0;
}
