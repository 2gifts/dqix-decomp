#include <globaldefs.h>
#include "GameState/GameState.h"

struct Obj02061bd8;

struct CombatantStatus02161ab8 {
    unsigned int flags;
    unsigned short hp;
};

struct CombatantParty02161ab8 {
    unsigned char pad[0x56b];
    unsigned char unk_56b : 4;
    unsigned char rank : 4;
};

struct Combatant02161ab8 {
    unsigned short flags;
    short pad_2;
    short level;
    char pad_6[0x130 - 0x6];
    CombatantStatus02161ab8* status;
    #if defined(jpn)
    char pad_134[0x144 - 0x134];
#else
    char pad_134[0x150 - 0x134];
#endif
    CombatantParty02161ab8* party;
};

struct Entry02161ab8 {
    unsigned char subKind : 4;
    unsigned char kind : 4;
    unsigned char id;
    short combatantId;
    char pad_4[0x34 - 0x4];
    Entry02161ab8* next;
};

struct Work02161ab8 {
    #if defined(jpn)
    char pad[0xcc];
#else
    char pad[0xd0];
#endif
    Entry02161ab8* head;
};

extern "C" int func_ov017_021d60f4(void* arg);
extern "C" void func_ov017_021d6134(void* arg, int value);
GameObject* GetCombatantWithFlag0x1000(GameState* battleStruct, int combatantId);
int CheckField0x56bLowNibble(Obj02061bd8* obj);

static inline int GetHP(CombatantStatus02161ab8* status) { return status->hp; }

// USA: func_ov001_02161ab8
extern "C" ARM int func_ov001_02161ab8(char* self, int count) {
    GameState* gs = GameState::GetInstance();
    Work02161ab8* work = (Work02161ab8*)func_ov017_0218b5b0()->unknown_ptr_array_371c[6];
    int id = func_ov017_021d60f4(self);
    Entry02161ab8* e;
    for (e = work->head; e != NULL; e = e->next) {
        if (e->id == id) break;
    }
    if (e == NULL) {
        func_ov017_021d6134(self + 8, -1);
        func_ov017_021d6134(self + 0x10, 2);
        return 1;
    }
    int state;
    int kind;
    int combatantId;
    combatantId = -1;
    kind = e->kind;
    if (kind == 0) {
        func_ov017_021d6134(self + 8, kind);
        func_ov017_021d6134(self + 0x10, 0);
        return 1;
    }
    if (e->subKind == 10) {
        Combatant02161ab8* c = (Combatant02161ab8*)GetCombatantWithFlag0x1000(gs, 0xce);
        if (c != NULL) {
            state = 0;
        } else {
            int i;
            for (i = 0; i < 4; i++) {
                c = (Combatant02161ab8*)GetCombatantWithFlag0x1000(gs, i);
                if (c != NULL && CheckField0x56bLowNibble((Obj02061bd8*)c)) break;
            }
            if (i == 4) {
                func_ov017_021d6134(self + 8, kind);
                func_ov017_021d6134(self + 0x10, 2);
                return 1;
            }
            state = GetHP(c->status) <= 0 ? 1 : 0;
        }
    } else {
        Combatant02161ab8* c = (Combatant02161ab8*)GetCombatantWithFlag0x100(gs, e->combatantId);
        if (c == NULL) return 0;
        combatantId = e->combatantId;
        CombatantParty02161ab8* party = c->party;
        int hasRank;
        if (party != NULL) {
            hasRank = party->rank != 0;
        } else {
            hasRank = 0;
        }
        if (hasRank) {
            kind = (party != NULL ? party->rank : 0) + 7;
        } else if (!(c->flags & 0x1000) && c->level > 0 && c->level < 4) {
            kind = 14;
        }
        if (c != NULL) {
            CombatantStatus02161ab8* status = c->status;
            if (GetHP(status) <= 0 && (status->flags & 1)) {
                state = 1;
            } else {
                state = 0;
            }
        } else {
            state = 2;
        }
    }
    func_ov017_021d6134(self + 8, kind);
    func_ov017_021d6134(self + 0x10, state);
    if (count > 3) {
        func_ov017_021d6134(self + 0x18, combatantId);
    }
    return 1;
}
