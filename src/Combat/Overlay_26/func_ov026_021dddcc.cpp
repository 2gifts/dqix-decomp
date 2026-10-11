#if defined(jpn)
#define data_ov026_021de7fa data_ov026_021ded16
#define data_ov026_021de802 data_ov026_021ded1e
#define data_ov026_021de812 data_ov026_021ded2e
#define data_ov026_021de822 data_ov026_021ded3e
#define data_ov026_021def00 data_ov026_021df660
#define func_ov000_02171ffc func_ov000_02173834
#endif
#include <globaldefs.h>

struct GameState;
struct BattleState;
struct Container_021dae60;
struct StructAt020473c8;

struct Pos3 {
    int v[3];
};

struct Ids4 {
    short v[4];
};

struct Ids8 {
    short v[8];
};

struct SlotWork {
    char pad0[0x10];
    signed char cmds[8];
    signed char cursor;
    char pad19[0x3];
    signed char kind;
    signed char target;
    char pad1e[0x10];
    signed char owner;
};

struct Combatant {
    char pad0[0x4];
    short id;
    char pad6[0x3e];
    Pos3 pos;
};

struct IconSprite {
    char pad0[0x80];
    unsigned short icon;
    char pad82[0x6];
};

struct BattleWork {
    #if defined(jpn)
    char pad0[0x218];
#else
    char pad0[0x29c];
#endif
    BattleState* battle;
    char pad2a0[0xc08];
    int mode;
    int state;
    #if defined(jpn)
    char padeb0[0x28f0];
#else
    char padeb0[0x28b0];
#endif
    char list[0x17c];
    int activeSlot;
    #if defined(jpn)
    char pad38e0[0x1f54];
#else
    char pad38e0[0x1d20];
#endif
    IconSprite icons[2];
    char pad5710[0x2002];
    signed char phase;
};

struct Wave {
    float value;
    float angle;
};

extern "C" {
GameState* _ZN9GameState11GetInstanceEv();
Combatant* _ZN9GameState21GetPartyMemberByIndexEi(GameState* gs, int index);
unsigned char* _Z15GetFieldAt0x150Ph(unsigned char* obj);
char* _Z15GetData02109dccv();
SlotWork* _Z21FindSlotById_021dae60P18Container_021dae60i(Container_021dae60* list, int id);
int _Z29HasAnyFlags_021719f8_021719f8Pi(int* obj);
int _Z25GetClampedArrayField0xd1cPci(char* base, int index);
int _Z25GetClampedArrayField0xd3cPci(char* base, int index);
Combatant* _Z25GetCombatantWithFlag0x400P9GameStatei(GameState* gs, int id);
void* _Z18GetField0x3b0ValueP9GameState(GameState* gs);
int _ZNK8Object3D9GetHeightEv(Combatant* obj);
int _Z27ComputeTwoFromVec3_0202ec84PvP16Vec3copy0202ec84PiS2_(void* obj, Pos3* src, int* out1, int* out2);
void _Z25RenderFlaggedIndexedEntryP16StructAt020473c8i(IconSprite* obj, int param1);
void Vector3fix_Add(const Pos3* a, const Pos3* b, Pos3* out);
void Vector3fix_Normalize(const Pos3* in, Pos3* out);
int func_ov000_0217fd60(void* list, int id);
int func_ov000_0215e9fc(BattleState* battle, short* out, int max, int flag);
int func_ov000_0215eb1c(BattleState* battle, short* out, int max, int flag);
int func_ov000_02153e78(BattleState* battle, short* out, int max, int group, int flag);
int func_ov000_02171ffc(SlotWork* slot);
double func_0200c578(float x);
double func_02009424(double x);
void __clear(void* dst, int size);
}

extern Ids4 data_ov026_021de7fa;
extern Ids8 data_ov026_021de802;
extern Ids8 data_ov026_021de812;
extern Ids8 data_ov026_021de822;
extern Wave data_ov026_021def00;

#define IN_RANGE(x) (((x) >= 0 && (x) <= 3) ? 1 : 0)

static inline void G3_PushMtx() {
    *(volatile int*)0x04000444 = 0;
}

static inline void G3_PopMtx(int n) {
    *(volatile int*)0x04000448 = n;
}

static inline void G3_Translate(int x, int y, int z) {
    *(volatile int*)0x04000470 = x;
    *(volatile int*)0x04000470 = y;
    *(volatile int*)0x04000470 = z;
}

// USA: func_ov026_021dddcc
extern "C" ARM void func_ov026_021dddcc(BattleWork* self) {
    Ids8 enemies;
    short cnt[8];
    short offs[8];
    unsigned short icons[4];
    Ids4 ids;
    short counts[4];
    GameState* gs = _ZN9GameState11GetInstanceEv();
    BattleState* battle = self->battle;
    char* data;
    signed char m;
    int n;
    int nEnemies;
    int i;
    int k;
    int t;

    if (self->mode != 7 || self->state != 4) {
        return;
    }
    if (func_ov000_0217fd60(self->list, -1) == 0) {
        return;
    }
    if (self->phase != 0) {
        return;
    }

    __clear(icons, sizeof(icons));
    data = _Z15GetData02109dccv();
    for (m = 0; m < 4; m++) {
        Combatant* c = _ZN9GameState21GetPartyMemberByIndexEi(gs, m);
        if (c != 0) {
            unsigned char* f = _Z15GetFieldAt0x150Ph((unsigned char*)c);
            if (f != 0) {
                icons[m] = *(unsigned short*)(data + f[0x56a] * 0x20 + 0x1e);
            }
        }
    }

    ids = data_ov026_021de7fa;
    n = func_ov000_0215e9fc(battle, ids.v, 4, 0);
    enemies = data_ov026_021de802;
    nEnemies = func_ov000_0215eb1c(battle, enemies.v, 8, 1);
    __clear(counts, sizeof(counts));
    __clear(cnt, sizeof(cnt));
    __clear(offs, sizeof(offs));

    for (i = 0; i < n; i++) {
        int id = ids.v[i];
        SlotWork* slot = _Z21FindSlotById_021dae60P18Container_021dae60i((Container_021dae60*)self->list, id);
        int owned;
        int group;
        int target;
        if (slot == 0) continue;
        if (_Z29HasAnyFlags_021719f8_021719f8Pi((int*)slot) != 0) continue;
        if (slot->kind == 6) continue;
        owned = 0;
        if (slot->owner >= 0) {
            owned = slot->owner <= 3;
        }
        if (owned) continue;
        if (slot->cmds[slot->cursor] != 0xe && slot->cmds[slot->cursor] != 0x64) continue;
        target = slot->target;
        if (target < 0) continue;
        group = _Z25GetClampedArrayField0xd1cPci(self->list, target);
        target = _Z25GetClampedArrayField0xd3cPci(self->list, target);
        switch (func_ov000_02171ffc(slot)) {
        case 3:
            counts[i] = nEnemies;
            if (id != self->activeSlot) {
                int j;
                for (j = 0; j < nEnemies; j++) {
                    int e = enemies.v[j] - 0xc0;
                    if (e >= 0 && e < 8) {
                        cnt[e]++;
                    }
                }
            }
            break;
        case 4: {
            Ids8 list;
            list = data_ov026_021de812;
            counts[i] = func_ov000_02153e78(battle, list.v, 8, group, 1);
            if (id != self->activeSlot) {
                int j;
                for (j = 0; j < counts[i]; j++) {
                    int e = list.v[j] - 0xc0;
                    if (e >= 0 && e < 8) {
                        cnt[e]++;
                    }
                }
            }
            break;
        }
        case 2:
            if (IN_RANGE(target)) continue;
            counts[i] = 1;
            if (id != self->activeSlot) {
                int e = target - 0xc0;
                if (e >= 0 && e < 8) {
                    cnt[e]++;
                }
            }
            break;
        }
    }

    for (k = 0; k < 8; k++) {
        offs[k] = cnt[k] * -5;
    }

    data_ov026_021def00.angle += 0.1f;
    if (6.28f < data_ov026_021def00.angle) {
        data_ov026_021def00.angle -= 6.28f;
    }
    {
        float angle = data_ov026_021def00.angle;
        if (6.28f < angle) {
            angle -= 6.28f;
        }
        data_ov026_021def00.value = func_02009424(func_0200c578(angle));
    }

    for (t = 0; t < n; t++) {
        unsigned char grouped;
        int id = ids.v[t];
        grouped = 0;
        SlotWork* slot = _Z21FindSlotById_021dae60P18Container_021dae60i((Container_021dae60*)self->list, id);
        int owned;
        int target;
        int group;
        int mode;
        short count;
        int j;
        if (slot == 0) continue;
        if (_Z29HasAnyFlags_021719f8_021719f8Pi((int*)slot) != 0) continue;
        if (slot->kind == 6) continue;
        owned = 0;
        if (slot->owner >= 0) {
            owned = slot->owner <= 3;
        }
        if (owned) continue;
        if (slot->cmds[slot->cursor] != 0xe && slot->cmds[slot->cursor] != 0x64) continue;
        target = slot->target;
        if (target < 0) continue;
        group = _Z25GetClampedArrayField0xd1cPci(self->list, target);
        target = _Z25GetClampedArrayField0xd3cPci(self->list, target);
        mode = func_ov000_02171ffc(slot);
        Ids8 targets;
        targets = data_ov026_021de822;
        count = 0;
        switch (mode) {
        case 3:
            count = func_ov000_0215eb1c(battle, targets.v, 8, 1);
            if (count == 0) continue;
            break;
        case 4:
            grouped = 1;
            count = func_ov000_02153e78(battle, targets.v, 8, group, grouped);
            if (count == 0) continue;
            break;
        case 2:
            if (IN_RANGE(target)) continue;
            targets.v[0] = target;
            count = 1;
            break;
        }
        for (j = 0; j < count; j++) {
            Combatant* c = _Z25GetCombatantWithFlag0x400P9GameStatei(gs, targets.v[j]);
            int e;
            if (c == 0) continue;
            e = c->id - 0xc0;
            if (e < 0) continue;
            if (e >= 8) continue;
            if (id == self->activeSlot) {
                Pos3 dir;
                Pos3 shake;
                Pos3 pos;
                int x, y;
                int dy;
                void* view;
                IconSprite* spr;
                dir.v[1] = 1;
                dir.v[0] = 1;
                dir.v[2] = 0;
                Vector3fix_Normalize(&dir, &shake);
                shake.v[0] = (float)shake.v[0] * (0.2f * data_ov026_021def00.value);
                shake.v[1] = (float)shake.v[1] * (0.2f * data_ov026_021def00.value);
                view = _Z18GetField0x3b0ValueP9GameState(gs);
                pos = c->pos;
                pos.v[1] += _ZNK8Object3D9GetHeightEv(c);
                Vector3fix_Add(&pos, &shake, &pos);
                _Z27ComputeTwoFromVec3_0202ec84PvP16Vec3copy0202ec84PiS2_(view, &pos, &x, &y);
                dy = 0x18;
                if (grouped != 0) {
                    if (target == targets.v[j]) {
                        dy = 0x20;
                    }
                }
                spr = &self->icons[0];
                spr->icon = icons[id];
                G3_PushMtx();
                G3_Translate((x + offs[e]) << 12, (y + 3 - dy) << 12, 0x1000);
                _Z25RenderFlaggedIndexedEntryP16StructAt020473c8i(spr, 1);
                G3_PopMtx(1);
            } else {
                Pos3 dir;
                Pos3 shake;
                Pos3 pos;
                int x, y;
                void* view;
                IconSprite* spr;
                dir.v[1] = 1;
                dir.v[2] = 0;
                dir.v[0] = 0;
                Vector3fix_Normalize(&dir, &shake);
                shake.v[0] = 0;
                shake.v[1] = 0;
                view = _Z18GetField0x3b0ValueP9GameState(gs);
                pos = c->pos;
                pos.v[1] += _ZNK8Object3D9GetHeightEv(c);
                Vector3fix_Add(&pos, &shake, &pos);
                _Z27ComputeTwoFromVec3_0202ec84PvP16Vec3copy0202ec84PiS2_(view, &pos, &x, &y);
                spr = &self->icons[1];
                spr->icon = icons[id];
                G3_PushMtx();
                G3_Translate((x + offs[e]) << 12, (y - 0x18) << 12, 0);
                _Z25RenderFlaggedIndexedEntryP16StructAt020473c8i(spr, 1);
                G3_PopMtx(1);
            }
            offs[e] += 10;
        }
    }
}
