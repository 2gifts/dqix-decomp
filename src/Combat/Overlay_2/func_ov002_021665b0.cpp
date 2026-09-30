#include <globaldefs.h>
#include "GameState/GameState.h"

struct Status_021665b0 {
    int flags;
    unsigned short hp;
    short level;
};

struct Base_021665b0 {
    char pad0[0x30];
    unsigned short maxHp;
};

struct Ext_021665b0 {
    char pad0[0x950];
    int kind;
};

struct Unit_021665b0 {
    char pad0[0x130];
    Status_021665b0* status;
    Base_021665b0* base;
    char pad138[0x150 - 0x138];
    Ext_021665b0* ext;
};

struct Field_021665b0 {
    char pad0[0x78];
    unsigned int : 30;
    unsigned int guard : 1;
    unsigned int : 1;
};

struct Elem_021665b0 {
    int unk0;
    int unk4;
    unsigned int power : 8;
    unsigned int : 6;
    unsigned int key : 8;
    unsigned int : 10;
};

struct Pair_021665b0 {
    short value;
    short key;
};

struct Order_021665b0 {
    signed char id;
    signed char count;
};

struct Menu_021665b0 {
    char pad0[0x1bb8];
    int nextA;
    int nextB;
    int nextC;
    char pad1bc4[0x1c20 - 0x1bc4];
    signed char target;
    signed char actor;
    char pad1c22[0x1c26 - 0x1c22];
    short sel26;
    short sel28;
    short sel2a;
    char pad1c2c[0x1c50 - 0x1c2c];
    int count;
    int ids[12];
    char pad1c84[2];
    short maxHp[4];
    short hp[4];
    Pair_021665b0 pairs[5];
    short key;
    signed char turn;
    signed char chosen;
    signed char state;
    signed char result;
    signed char actorIdx;
    unsigned char acted;
    Order_021665b0 order[4];
    signed char revives[4];
    unsigned char dead[4];
};

struct Cmd_021665b0 {
    unsigned short key;
    signed char target;
    signed char unk3;
    signed char actor;
    char pad5[0x3c - 5];
};

struct Slot_021665b0 {
    unsigned short score;
    unsigned short id;
};

extern "C" void _Z22InitStateArray02157ce0Pc(Cmd_021665b0* cmd);
extern "C" char* _Z15GetData02108e10v(void);
extern "C" void func_ov002_0215b814(Menu_021665b0* self);
extern "C" Unit_021665b0* _Z19GetCombatantCheckedP9GameStatei(GameState* gs, int id);
extern "C" Unit_021665b0* _Z25GetCombatantWithFlag0x100P9GameStatei(GameState* gs, int id);
extern "C" Field_021665b0* _Z15GetFieldAt0x150Ph(Unit_021665b0* unit);
extern "C" int _Z18GetBitInArray0x910Phi(Field_021665b0* field, int index);
extern "C" int func_0209ac28(char* obj, Unit_021665b0* unit, int index);
extern "C" Elem_021665b0* _Z24SearchBothTables02079e2cPci(char* data, short key);
extern "C" int _Z32ClampAndCompareThreshold02048448P14Struct02048448i(Unit_021665b0* unit, int value);
extern "C" void __clear(void* dst, int size);
extern "C" void func_ov002_021536e0(char** obj);
extern "C" void* _Z26LookupElementByKey02079ee0Pvi(char* data, int key);
extern "C" short func_ov002_021538e4(char** obj, Elem_021665b0* elem, void* sub, int target);
extern "C" void func_ov002_021594e8(Menu_021665b0* self, int key, int target, int actor);
extern "C" char* _Z26GetGlobalField0x1c020421a0v(void);
extern "C" int _Z25TestFlag0SetAndFlag1ClearPti(unsigned short* flags, int mask);
extern "C" int _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38(char* obj, int key);
extern "C" int func_0205d97c(char* obj);
extern "C" int _Z29CheckFlagOrThreshold_02161b48Pci(Menu_021665b0* self, int flag);
extern "C" void _Z24ReinitController02043204Pc(char* ctl);
extern "C" void _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii(char* obj, int clear, int key);
extern "C" void func_ov016_0218b5c0(int a, int b);
extern "C" void func_ov017_0218b5f8(int a);

extern unsigned short data_02114e30;

// USA: func_ov002_021665b0
extern "C" ARM void func_ov002_021665b0(Menu_021665b0* self) {
    GameState* gs = GameState::GetInstance();
    Cmd_021665b0 cmd;
    Field_021665b0* field;
    Unit_021665b0* unit;
    _Z22InitStateArray02157ce0Pc(&cmd);
    char* data = _Z15GetData02108e10v();
    signed char n = self->count - 1;
    short* maxHp = self->maxHp;
    short* hp = self->hp;
    signed char* revives = self->revives;
    unsigned char* dead = self->dead;
    signed char state = self->state;
    Unit_021665b0* member;

    if (state == 0) {
        unsigned short lost[4];
        int id;
        func_ov002_0215b814(self);
        self->acted = 0;
        self->state = 1;
        self->sel28 = -1;
        self->sel2a = -1;
        for (int i = 0; i < 4; i++) {
            maxHp[i] = 0;
            hp[i] = 0;
            dead[i] = 0;
            revives[i] = 0;
            self->order[i].id = -1;
            lost[i] = 0;
            self->order[i].count = -1;
        }
        memset(self->pairs, -1, sizeof(self->pairs));
        int needed = 0;
        for (int i = 0; i < n; i++) {
            id = self->ids[i];
            unit = _Z19GetCombatantCheckedP9GameStatei(gs, id);
            if (unit == NULL) {
                continue;
            }
            member = _Z25GetCombatantWithFlag0x100P9GameStatei(gs, id);
            if (member == NULL) {
                continue;
            }
            field = _Z15GetFieldAt0x150Ph(member);
            if (field == NULL) {
                continue;
            }
            maxHp[id] = member->base->maxHp;
            hp[id] = member->status->hp;
            lost[id] = maxHp[id] - hp[id];
            if (unit->status->flags & 2) {
                dead[id] = 1;
            }
            if (unit->status->flags & 1) {
                continue;
            }
            for (int k = 0x1a; k < 0x1f; k++) {
                if (_Z18GetBitInArray0x910Phi(field, k) && func_0209ac28((char*)self + 0x2444, member, k)) {
                    if (member->status->level >= 2) {
                        revives[id]++;
                    }
                }
            }
        }
        int found = 0;
        for (int i = 0; i < n; i++) {
            id = self->ids[i];
            if (_Z25GetCombatantWithFlag0x100P9GameStatei(gs, id) == NULL) {
                continue;
            }
            unit = _Z19GetCombatantCheckedP9GameStatei(gs, id);
            if (unit == NULL) {
                continue;
            }
            if (unit->status->flags & 1) {
                continue;
            }
            if (lost[id] != 0) {
                for (int j = 0; j < n; j++) {
                    int other = self->ids[j];
                    if (_Z25GetCombatantWithFlag0x100P9GameStatei(gs, other) != NULL && hp[other] > 0 && revives[other] > 0) {
                        found = 1;
                        break;
                    }
                }
            }
            if (dead[id] != 0) {
                for (int j = 0; j < n; j++) {
                    int other = self->ids[j];
                    Unit_021665b0* member = _Z25GetCombatantWithFlag0x100P9GameStatei(gs, other);
                    if (member == NULL) {
                        continue;
                    }
                    Field_021665b0* field = _Z15GetFieldAt0x150Ph(member);
                    if (field == NULL) {
                        continue;
                    }
                    if (hp[other] <= 0) {
                        continue;
                    }
                    if (!_Z18GetBitInArray0x910Phi(field, 0x20)) {
                        continue;
                    }
                    Unit_021665b0* caster = _Z19GetCombatantCheckedP9GameStatei(gs, other);
                    if (_Z32ClampAndCompareThreshold02048448P14Struct02048448i(caster, (unsigned short)_Z24SearchBothTables02079e2cPci(data, 0x23)->power)) {
                        found = 1;
                        break;
                    }
                }
            }
            if (found) {
                break;
            }
        }
        if (found) {
            needed = 1;
        }
        if (!needed) {
            self->state = 5;
            self->result = 2;
        }
    } else if (state == 1) {
        Slot_021665b0 slots[4];
        Slot_021665b0 spare[4];
        self->state = 2;
        __clear(slots, sizeof(slots));
        __clear(spare, sizeof(spare));
        Slot_021665b0* slot;
        for (int i = 0; i < n; i++) {
            int id = self->ids[i];
            slot = &slots[i];
            slot->id = id;
            Unit_021665b0* unit = _Z19GetCombatantCheckedP9GameStatei(gs, id);
            if (unit == NULL) {
                continue;
            }
            member = _Z25GetCombatantWithFlag0x100P9GameStatei(gs, id);
            if (member == NULL) {
                continue;
            }
            field = _Z15GetFieldAt0x150Ph(member);
            if (field == NULL) {
                continue;
            }
            unsigned char kind = member->ext->kind;
            if (unit->status->flags & 1) {
                continue;
            }
            int skip = 0;
            switch (kind) {
            case 2:
                slot->score += 10;
                break;
            case 10:
                slot->score += 8;
                break;
            case 6:
            case 9:
            case 11:
                slot->score += 5;
                break;
            case 5:
            case 12:
                slot->score += 3;
                break;
            default:
                skip = 1;
                break;
            }
            if (skip) {
                continue;
            }
            if ((unsigned short)field->guard) {
                slot->score += 5;
            }
            slot->score = slot->score + revives[id] * 4;
            if (_Z18GetBitInArray0x910Phi(field, 0x1f)) {
                if (func_0209ac28((char*)self + 0x2444, member, 0x1f)) {
                    slot->score += 200;
                }
            } else if (_Z18GetBitInArray0x910Phi(field, 0x1e)) {
                if (func_0209ac28((char*)self + 0x2444, member, 0x1e)) {
                    slot->score += 100;
                }
            }
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 3; j > i; j--) {
                unsigned short prev = slots[j - 1].score;
                unsigned short cur = slots[j].score;
                if (cur > prev) {
                    unsigned char id = slots[j].id;
                    slots[j].score = prev;
                    slots[j].id = slots[j - 1].id;
                    slots[j - 1].score = cur;
                    slots[j - 1].id = id;
                }
            }
        }
        for (int i = 0; i < 4; i++) {
            if (slots[i].score == 0) {
                break;
            }
            unsigned char id = slots[i].id;
            self->order[i].id = id;
            self->order[i].count = revives[id];
        }
    } else if (state == 2) {
        self->state = 3;
        for (int i = 0; i < 5; i++) {
            self->pairs[i].value = -1;
            self->pairs[i].key = -1;
        }
        _Z22InitStateArray02157ce0Pc(&cmd);
        cmd.actor = self->ids[self->actorIdx];
        cmd.target = self->order[self->turn].id;
        self->target = self->order[self->turn].id;
        int valid = 0;
        if (cmd.target >= 0 && cmd.target <= 3) {
            valid = 1;
        }
        if (!valid) {
            self->state = 2;
            self->turn = self->turn + 1;
            if (n <= self->turn) {
                self->state = 5;
                self->result = 1;
                self->sel28 = -1;
            }
            return;
        }
        Unit_021665b0* member = _Z25GetCombatantWithFlag0x100P9GameStatei(gs, cmd.target);
        if (member->status->flags & 1) {
            self->state = 2;
            self->turn = self->turn + 1;
            if (n <= self->turn) {
                self->state = 5;
                self->result = 2;
                self->sel28 = -1;
            }
            return;
        }
        char* table;
        func_ov002_021536e0(&table);
        table = data;
        int k;
        int i;
        for (i = 0, k = 0x1a; i < 5; i++, k++) {
            self->pairs[i].value = 0;
            self->pairs[i].key = 0;
            if (!_Z18GetBitInArray0x910Phi(_Z15GetFieldAt0x150Ph(member), k)) {
                continue;
            }
            if (!func_0209ac28((char*)self + 0x2444, member, k)) {
                continue;
            }
            if (member->status->level < 2) {
                continue;
            }
            cmd.key = i + 0x1e;
            Elem_021665b0* elem = _Z24SearchBothTables02079e2cPci(data, cmd.key);
            void* sub = _Z26LookupElementByKey02079ee0Pvi(data, elem->key);
            self->pairs[i].value = func_ov002_021538e4(&table, elem, sub, cmd.target);
            self->pairs[i].key = cmd.key;
        }
    } else if (state == 3) {
        self->state = 4;
        self->sel28 = -1;
        self->sel2a = -1;
        self->key = 0x1e;
        short small;
        short large;
        unsigned char done;
        int target;
        int missing;
        int actor = self->ids[self->actorIdx];
        self->actor = actor;
        for (int i = 0; i < n; i++) {
            signed char id = self->ids[i];
            Unit_021665b0* member = _Z25GetCombatantWithFlag0x100P9GameStatei(gs, id);
            if (member != NULL) {
                hp[id] = member->status->hp;
            }
        }
        missing = (unsigned short)(maxHp[actor] - hp[actor]);
        int chosen = 0;
        unsigned char t = 0;
        if (dead[actor] == 1) {
            while (t < n) {
                Unit_021665b0* member = _Z25GetCombatantWithFlag0x100P9GameStatei(gs, self->order[t].id);
                if (member == NULL) {
                    t++;
                    continue;
                }
                Field_021665b0* field = _Z15GetFieldAt0x150Ph(member);
                if (field == NULL) {
                    t++;
                    continue;
                }
                if (_Z19GetCombatantCheckedP9GameStatei(gs, self->order[t].id)->status->flags & 1) {
                    t++;
                    continue;
                }
                if (_Z18GetBitInArray0x910Phi(field, 0x20)) {
                    if (!func_0209ac28((char*)self + 0x2444, member, 0x20)) {
                        t++;
                        continue;
                    }
                    cmd.key = 0x23;
                    Elem_021665b0* elem = _Z24SearchBothTables02079e2cPci(data, cmd.key);
                    Unit_021665b0* caster = _Z19GetCombatantCheckedP9GameStatei(gs, self->order[t].id);
                    if (!_Z32ClampAndCompareThreshold02048448P14Struct02048448i(caster, (unsigned short)elem->power)) {
                        t++;
                        continue;
                    }
                    self->key = cmd.key;
                    chosen = 1;
                    self->acted = 1;
                    break;
                }
                t++;
            }
        }
        if (chosen) {
            self->chosen = t;
            func_ov002_021594e8(self, self->key, self->order[t].id, actor);
            Unit_021665b0* member = _Z25GetCombatantWithFlag0x100P9GameStatei(gs, actor);
            Unit_021665b0* unit = _Z19GetCombatantCheckedP9GameStatei(gs, actor);
            hp[actor] = member->status->hp;
            if (!(unit->status->flags & 2)) {
                dead[actor] = 0;
            }
            self->state = 6;
            return;
        }
        target = self->order[self->turn].id;
        signed char count = self->order[self->turn].count;
        self->target = target;
        Unit_021665b0* unit = _Z19GetCombatantCheckedP9GameStatei(gs, actor);
        if (count == 0) {
            self->turn = self->turn + 1;
            self->state = 2;
            if (n <= self->turn) {
                self->state = 5;
                if (self->acted == 0) {
                    self->result = 2;
                }
            }
            return;
        }
        if (unit->status->flags & 1) {
            self->state = 2;
            self->actorIdx = self->actorIdx + 1;
            if (n <= self->actorIdx) {
                self->state = 5;
                if (self->acted == 0) {
                    self->result = 2;
                }
            }
            return;
        }
        if (dead[actor] == 1 && n <= self->actorIdx) {
            self->state = 5;
            if (self->acted == 0) {
                self->result = 2;
            }
            return;
        }
        if (missing == 0) {
            self->state = 2;
            self->actorIdx = self->actorIdx + 1;
            if (n <= self->actorIdx) {
                self->state = 5;
                if (self->acted == 0) {
                    self->result = 2;
                }
            }
            return;
        }
        Unit_021665b0* healer = _Z25GetCombatantWithFlag0x100P9GameStatei(gs, target);
        if (_Z18GetBitInArray0x910Phi(_Z15GetFieldAt0x150Ph(healer), 0x1e) && self->pairs[4].key > 0) {
            cmd.key = 0x22;
            if (_Z32ClampAndCompareThreshold02048448P14Struct02048448i(healer, (unsigned short)_Z24SearchBothTables02079e2cPci(data, 0x22)->power)) {
                small = self->pairs[0].value;
                short mid = self->pairs[1].value;
                large = self->pairs[2].value;
                short full = self->pairs[4].value;
                int area = self->pairs[3].key;
                signed char overSmall = 0;
                signed char overMid = 0;
                signed char overFull = 0;
                for (unsigned char i = 0; i < n; i++) {
                    signed char id = self->ids[i];
                    short cur = hp[id];
                    if (cur <= 0) {
                        continue;
                    }
                    unsigned short lost = maxHp[id] - cur;
                    if (lost == 0) {
                        continue;
                    }
                    if (lost < mid) {
                        continue;
                    }
                    if (mid >= full) {
                        continue;
                    }
                    if (small < lost) {
                        overSmall++;
                    }
                    if (mid < lost) {
                        overMid++;
                    }
                    if (large <= 0) {
                        continue;
                    }
                    if (lost < full * 2) {
                        overFull++;
                    }
                }
                if (area > 0) {
                    for (unsigned char i = 0; i < n; i++) {
                        signed char id = self->ids[i];
                        short cur = hp[id];
                        if (cur <= 0) {
                            continue;
                        }
                        unsigned short lost = maxHp[id] - cur;
                        if (lost == 0) {
                            continue;
                        }
                        if (full * 6 >= lost) {
                            continue;
                        }
                        overSmall--;
                        overMid--;
                        overFull--;
                    }
                }
                if (overSmall == 4 || overMid >= 4 || overFull >= 4) {
                    self->key = 0x22;
                    chosen = 1;
                }
            }
        }
        if (chosen) {
            func_ov002_021594e8(self, self->key = 0x22, target, 0);
            for (int i = 0; i < n; i++) {
                unsigned char id = self->ids[i];
                Unit_021665b0* member = _Z25GetCombatantWithFlag0x100P9GameStatei(gs, id);
                if (member != NULL) {
                    hp[id] = member->status->hp;
                }
            }
            self->state = 6;
            return;
        }
        if (missing <= self->pairs[0].value) {
            if (!chosen) {
                chosen = 1;
                self->key = self->pairs[0].key;
            }
        }
        if (!chosen) {
            if (missing < self->pairs[1].value) {
                chosen = 1;
                self->key = self->pairs[1].key;
            }
        }
        if (!chosen) {
            if (missing < self->pairs[1].value * 2) {
                chosen = 1;
                self->key = self->pairs[1].key;
            } else if (missing < self->pairs[2].value) {
                chosen = 1;
                self->key = self->pairs[2].key;
            }
        }
        if (!chosen) {
            if (missing < self->pairs[2].value * 3) {
                chosen = 1;
                self->key = self->pairs[2].key;
            } else if (self->pairs[3].key != 0) {
                self->key = self->pairs[3].key;
                chosen = 1;
            }
        }
        if (!chosen && self->pairs[0].key != 0) {
            for (int i = 3; i >= 0; i--) {
                if (self->pairs[i].value != 0) {
                    self->key = self->pairs[i].key;
                    break;
                }
            }
        }
        done = 0;
        while (!done) {
            Elem_021665b0* elem = _Z24SearchBothTables02079e2cPci(data, self->key);
            Unit_021665b0* caster = _Z19GetCombatantCheckedP9GameStatei(gs, target);
            if (caster == NULL || elem == NULL) {
                continue;
            }
            if (_Z32ClampAndCompareThreshold02048448P14Struct02048448i(caster, (unsigned short)elem->power) == 0) {
                self->key--;
                if (self->key < 0x1e) {
                    self->turn++;
                    self->state = 2;
                    if (n <= self->turn) {
                        self->state = 5;
                        self->result = 1;
                        self->sel28 = -1;
                    }
                    done = 1;
                }
            } else {
                done = 1;
            }
        }
    } else if (state == 4) {
        int actor = self->ids[self->actorIdx];
        func_ov002_021594e8(self, self->key, self->order[self->turn].id, actor);
        Unit_021665b0* member = _Z25GetCombatantWithFlag0x100P9GameStatei(gs, actor);
        Unit_021665b0* unit = _Z19GetCombatantCheckedP9GameStatei(gs, actor);
        hp[actor] = member->status->hp;
        if (!(unit->status->flags & 2)) {
            dead[actor] = 0;
        }
        self->acted = 1;
        self->state = 6;
    } else if (state == 5) {
        int changed = 0;
        self->turn = 0;
        self->actorIdx = 0;
        self->sel26 = -1;
        self->nextA = 0x17;
        self->nextB = 0x17;
        self->nextC = changed;
        char* ctl = _Z26GetGlobalField0x1c020421a0v();
        if (self->acted == 0 && self->result == 1) {
            self->result = 2;
        }
        signed char result = self->result;
        if (!(result != 0 && result != 1)) {
            ctl[0x19ca] = 0;
            int pressed = _Z25TestFlag0SetAndFlag1ClearPti(&data_02114e30, 0x601);
            int cancel = (pressed | _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38((char*)self + 0xec8, 0x14)) ? 1 : 0;
            int single = func_0205d97c((char*)self + 0xec8) == 1 ? 1 : 0;
            int flagged = _Z29CheckFlagOrThreshold_02161b48Pci(self, 1);
            int left = _Z25TestFlag0SetAndFlag1ClearPti(&data_02114e30, 0xf0);
            if (single | (flagged | (cancel | (left | _Z25TestFlag0SetAndFlag1ClearPti(&data_02114e30, 0x100))))) {
                _Z24ReinitController02043204Pc(ctl);
                self->nextA = 0x15;
                self->nextB = 0x2b;
                _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii((char*)self + 0xec8, 1, 0x29);
                self->result = 0;
                self->sel28 = -1;
                self->sel2a = -1;
                self->state = 0;
                self->acted = 0;
                changed = 1;
            } else if (_Z25TestFlag0SetAndFlag1ClearPti(&data_02114e30, 0x800)) {
                _Z24ReinitController02043204Pc(ctl);
                self->nextA = 0x2b;
                self->nextB = 0x2b;
                self->result = 0;
                self->sel28 = -1;
                self->sel2a = -1;
                self->state = 0;
                self->acted = 0;
                changed = 1;
            }
        } else if (result == 2) {
            self->sel28 = 0x232b;
            self->nextA = 0x26;
            self->nextB = 0x17;
            self->result = 4;
            changed = 1;
        }
        if (changed) {
            func_ov016_0218b5c0(1, -1);
            func_ov017_0218b5f8(-1);
        }
    } else if (state == 6) {
        self->state = 3;
        signed char idx = self->actorIdx;
        int actor = self->ids[idx];
        if (hp[actor] == maxHp[actor] && dead[actor] == 0) {
            self->actorIdx = idx + 1;
            self->turn = 0;
            self->state = 2;
            if (n <= self->actorIdx) {
                self->state = 5;
            }
        }
    }
}
