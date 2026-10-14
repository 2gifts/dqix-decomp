#include <globaldefs.h>
#include "std_library_functions.h"

struct Bytes02033b88;
void ClearSubstructFlag0x100(unsigned char*);
void ClearStateFlags0203400c(unsigned char*);
void ClearFlagBit(unsigned char* base, int bit);
extern "C" int func_ov000_02159f18(void* unused, unsigned long long bits, unsigned int bit);
void SetByte0xbeShiftPrev(Bytes02033b88* obj, int v);
void SetBits0x40000AndFlag0x2(unsigned char*);
void SetSubstructFlag0x100(unsigned char*);
void ResetCombatantSlot020d7334(unsigned char*, int);
extern "C" void func_020d6f9c(void* param0, int combatantId, int reason);

extern const char data_ov000_021838d8[];

enum CombatReason02162dc4 { REASON_0, REASON_1, REASON_2, REASON_3, REASON_4, REASON_NONE };
enum CombatKind02162dc4 { KIND_NONE, KIND_1, KIND_2, KIND_3, KIND_4, KIND_5 };

struct Combatant02162dc4 {
    char pad0[4];
    short id;
    char pad6[0x14 - 6];
    char* name;
    char pad18[0xc1 - 0x18];
    unsigned char low : 4;
    unsigned char kind : 4;
};

struct Battle02162dc4 {
    char pad0[0x29c];
    void* field29c;
    char pad2a0[0xea4 - 0x2a0];
    unsigned char* slots;
};

inline int CheckStatus(Battle02162dc4* self, unsigned long long mask, unsigned int flags, unsigned int flagBit,
                       unsigned int blockId, unsigned int needId) {
    return !func_ov000_02159f18(self->field29c, mask, blockId) &&
           ((flags & flagBit) || func_ov000_02159f18(self->field29c, mask, needId));
}

inline int IsMonsterSlot(int id) { return (id >= 0xc0 && id <= 0xc7) ? 1 : 0; }

// USA: func_ov000_02162dc4
extern "C" ARM void func_ov000_02162dc4(Battle02162dc4* self, Combatant02162dc4* lead, Combatant02162dc4* actor,
                                        unsigned int flags, int b1d, int b1e, unsigned long long mask,
                                        unsigned char flag) {
    void* status;
    int allow;
    unsigned char* slots;
    int id;
    if (actor == NULL || (slots = self->slots) == NULL) return;
    id = actor->id;
    ClearSubstructFlag0x100((unsigned char*)actor);
    ClearStateFlags0203400c((unsigned char*)actor);
    if (flags & 1) {
        ClearFlagBit(slots, id);
        return;
    }
    status = self->field29c;
    int notify = 1;
    if (mask == 0 || func_ov000_02159f18(status, mask, 0) || func_ov000_02159f18(status, mask, 8) ||
        func_ov000_02159f18(status, mask, 0x1d) || func_ov000_02159f18(status, mask, 0x27)) {
        if (actor->name != NULL && strcmp(actor->name, data_ov000_021838d8) == 0) {
            notify = 0;
        } else if (b1d != 0 && flag == 0) {
            notify = 0;
        }
    }
    CombatKind02162dc4 kind = KIND_NONE;
    CombatReason02162dc4 reason = REASON_NONE;
    if (b1d != 0 && func_ov000_02159f18(status, mask, 0x17)) {
        if (b1d == 4) notify = 0;
    }
    allow = 1;
    if (flag != 0 && func_ov000_02159f18(status, mask, 0xb) &&
        (func_ov000_02159f18(status, mask, 0x17) || func_ov000_02159f18(status, mask, 0x18))) {
        allow = 0;
    }
    if (CheckStatus(self, mask, flags, 8, 0x1a, 0x18) && allow) {
        if (reason == REASON_NONE) reason = REASON_3;
        actor->kind = 0;
        if (notify) SetByte0xbeShiftPrev((Bytes02033b88*)actor, 0);
        SetBits0x40000AndFlag0x2((unsigned char*)actor);
        SetSubstructFlag0x100((unsigned char*)actor);
    }
    if (CheckStatus(self, mask, flags, 0x10, 0x10, 0xe)) {
        if (kind == KIND_NONE) kind = KIND_2;
        if (reason == REASON_NONE) reason = REASON_1;
        SetSubstructFlag0x100((unsigned char*)actor);
        if (IsMonsterSlot(id)) SetBits0x40000AndFlag0x2((unsigned char*)actor);
    } else if (actor->kind == 2) {
        actor->kind = 0;
    }
    if (CheckStatus(self, mask, flags, 0x20, 0x19, 0x17) && allow) {
        if (reason == REASON_NONE) reason = REASON_4;
        actor->kind = kind;
        if (notify) SetByte0xbeShiftPrev((Bytes02033b88*)actor, 0);
    }
    if (CheckStatus(self, mask, flags, 2, 0x11, 0xf)) {
        if (reason == REASON_NONE) reason = REASON_0;
    }
    if (func_ov000_02159f18(status, mask, 0x16)) {
        if (reason == REASON_NONE) reason = REASON_2;
    }
    if (flags & 0x80000) {
        switch (b1d) {
        case 2:
            if (kind == KIND_NONE) kind = KIND_3;
            break;
        case 3:
            if (kind == KIND_NONE) kind = KIND_4;
            break;
        case 4:
            if (kind == KIND_NONE) kind = KIND_5;
            break;
        case 6:
        case 10:
            if (reason == REASON_NONE) reason = REASON_2;
            break;
        }
        if (kind == KIND_NONE) {
            actor->kind = 0;
            if (notify) SetByte0xbeShiftPrev((Bytes02033b88*)actor, 0);
        }
        SetSubstructFlag0x100((unsigned char*)actor);
    } else {
        CombatKind02162dc4 current = (CombatKind02162dc4)actor->kind;
        if ((unsigned int)(current - KIND_3) <= KIND_5 - KIND_3) actor->kind = 0;
    }
    if (reason == REASON_NONE) {
        ResetCombatantSlot020d7334(slots, id);
    } else {
        func_020d6f9c(slots, id, reason);
    }
    if (kind != KIND_NONE) actor->kind = kind;
    if (notify) {
        if (lead == NULL) {
            SetByte0xbeShiftPrev((Bytes02033b88*)actor, 0);
        } else if (lead != actor) {
            SetByte0xbeShiftPrev((Bytes02033b88*)actor, 0);
        }
    }
}
