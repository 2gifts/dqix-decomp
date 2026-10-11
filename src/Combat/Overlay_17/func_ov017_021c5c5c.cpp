#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"

struct ListHead02046b60;

struct Event_021c5c5c {
    char pad0[8];
    unsigned short targetId;
};

struct Node718_021c5c5c {
    char pad0[2];
    unsigned char active;
};

struct NodeB0c_021c5c5c {
    char pad0;
    unsigned char field1;
    char pad2;
    unsigned char field3;
    char pad4[0x64 - 4];
    int field64;
};

struct Ctx_021c5c5c {
#if defined(jpn)
    char pad0[0x34ec];
#else
    char pad0[0x36fc];
#endif
    ListHead02046b60* list;
    char pad3700[0x3718 - 0x3700];
    Node718_021c5c5c* node718;
#if defined(jpn)
    char pad371c[0x38ec - 0x350c];
#else
    char pad371c[0x3b0c - 0x371c];
#endif
    NodeB0c_021c5c5c* nodeB0c;
    char pad3b10[0x42e7 - 0x3b10];
    unsigned char busy;
};

struct Status_021c5c5c {
    unsigned int flags;
};

struct Combatant_021c5c5c {
    Object3D obj3D;
    char padAc[0xc3 - 0xac];
    unsigned char fieldC3;
    char padC4[0x130 - 0xc4];
    Status_021c5c5c* status;
    char pad134[0x17d - 0x134];
    unsigned char flags17d;
#if defined(jpn)
    char pad17e[0x180 - 0x17e];
#else
    char pad17e[0x18c - 0x17e];
#endif
    unsigned int flags18c;
};

extern "C" Event_021c5c5c* func_ov017_021b8478(Node718_021c5c5c* node);
extern "C" Combatant_021c5c5c* _Z32FindCombatantByField16a_021a278cPvi(void* base, int val);
unsigned char GetByte0x26c(char* obj);
int ListContainsId(ListHead02046b60* list, int id);
extern "C" void _Z30SetFlagAndMaybeNotify_021ab010Pvi(void* obj, int flag);
int IsField0Null(void** list);

// JPN: func_ov017_021c610c
// USA: func_ov017_021c5c5c
extern "C" ARM int func_ov017_021c5c5c(int unused, int id) {
    GameState* gs = GameState::GetInstance();
    Ctx_021c5c5c* ctx = (Ctx_021c5c5c*)func_ov017_0218b5b0();
    Combatant_021c5c5c* leader;
    ListHead02046b60* list = ctx->list;
    leader = (Combatant_021c5c5c*)gs->GetUnknownGameObject();
    if (leader == NULL) {
        return 0;
    }
    if (ctx->busy != 0) {
        return 0;
    }
    if (ctx->node718->active != 0) {
        Event_021c5c5c* ev = func_ov017_021b8478(ctx->node718);
        if (ev->targetId == id) {
            return 1;
        }
    }
    if (!(leader->status->flags & 1) && !(leader->flags18c & 1) && (int)leader->fieldC3 > 0) {
        return 0;
    }

    Combatant_021c5c5c* other = _Z32FindCombatantByField16a_021a278cPvi(ctx, id);
    if (other == NULL) {
        return 0;
    }
    unsigned char claimed = other->flags17d & 0x80;
    if (claimed) {
        return 0;
    }
    other->flags17d |= 0x80;

    if (leader->obj3D.GetField06() != other->obj3D.GetField06()) {
        return 0;
    }
    if (GetByte0x26c((char*)leader) != 0) {
        return 0;
    }

    Vector3fix leaderPos = leader->obj3D.position_;
    Vector3fix otherPos = other->obj3D.position_;
    if (fix32abs(leaderPos.y - otherPos.y) > 0x1800) {
        return 0;
    }
    if (Vector3fix_Distance(&otherPos, &leaderPos) > 0xf000) {
        return 0;
    }

    NodeB0c_021c5c5c* node = ctx->nodeB0c;
    if (ListContainsId(list, 0x1a) && node->field64 != 0) {
        return 0;
    }
    if (node->field3 != 0 && node->field1 == 0) {
        _Z30SetFlagAndMaybeNotify_021ab010Pvi(node, 0);
    } else if (!IsField0Null((void**)list)) {
        return 0;
    }
    return 1;
}
