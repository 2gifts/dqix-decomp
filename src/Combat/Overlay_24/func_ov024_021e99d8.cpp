#include <globaldefs.h>
#include "GameState/GameState.h"

struct PackedRange_021e99d8 {
    unsigned int lo : 10;
    unsigned int hi : 10;
    unsigned int rest : 12;
};

struct TableEntry_021e99d8 {
    char pad0[0x20];
    struct PackedRange_021e99d8 range;
};

struct Action_021e99d8 {
    unsigned int pad0;
    unsigned int id : 12;
    unsigned int rest4 : 20;
    char pad8[0x10 - 0x8];
    unsigned int flags10;
    char pad14[0x20 - 0x14];
    struct PackedRange_021e99d8 range;
};

struct Actor_021e99d8 {
    char pad0[0x20];
    short id;
};

struct Command_021e99d8 {
    char pad0[2];
    short command;
    char pad4[0xb - 0x4];
    unsigned char bit0 : 1;
    unsigned char redirected : 1;
    unsigned char rest : 6;
    char padc[0x10 - 0xc];
    struct Actor_021e99d8* actor;
};

struct Ctx_021e99d8 {
    char pad0[0x14];
    int count14;
};

struct Combatant_021e99d8 {
    char pad0[0x150];
    unsigned char* field150;
};

char* GetData02108e10();
void* SearchBothTables02079e2c(char* p, int key);
unsigned short SelectByIndexRange0to3_021da644(int idx, int a, int b);
int TestBit2At0x2f4(unsigned char* p);

static inline int IsPartyMember(int id) {
    return id >= 0 && id <= 3;
}

// USA: func_ov024_021e99d8
extern "C" ARM int func_ov024_021e99d8(struct Ctx_021e99d8* ctx, struct Command_021e99d8* cmd,
                                       struct Action_021e99d8* action) {
    int id = cmd->actor->id;
    if ((action->flags10 & 0x2000000) && ctx->count14 <= 0) {
        if (IsPartyMember(id)) {
            cmd->redirected = 1;
            return 0x1ef;
        }
    }
    if (action->id == 0x1f8) {
        struct TableEntry_021e99d8* entry =
            (struct TableEntry_021e99d8*)SearchBothTables02079e2c(GetData02108e10(), cmd->command);
        if (!entry) {
            return 0;
        }
        if ((unsigned short)cmd->command == 0x1c || (unsigned short)cmd->command == 0x247) {
            return 0x2e;
        }
        return SelectByIndexRange0to3_021da644(id, entry->range.lo, entry->range.hi);
    }
    int result = SelectByIndexRange0to3_021da644(id, action->range.lo, action->range.hi);
    if (result == 1 && IsPartyMember(id)) {
        struct Combatant_021e99d8* c =
            (struct Combatant_021e99d8*)GetCombatantWithFlag0x100(GameState::GetInstance(), id);
        if (c && (action->flags10 & 0x100000)) {
            if (TestBit2At0x2f4(c->field150)) {
                return 0x10;
            }
        }
    }
    return result;
}
