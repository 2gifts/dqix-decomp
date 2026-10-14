#include <globaldefs.h>
#include "GameState/GameState.h"
#include "System/Matrix.h"

struct List02169b04;
struct Node02169b54;
struct List02160094;
struct GatherObj02163a7c;

struct Node02169b04 {
    char pad0[8];
    unsigned short kind;
};

struct Actor021db8d8 {
    char pad0[0x20];
    unsigned short id;
};

struct Target021db8d8 {
    char pad0[0xe];
    short id;
};

struct Slot021db8d8 {
    char pad0[0x10];
    struct Actor021db8d8* actor;
    struct Target021db8d8* target;
};

struct Flags021db8d8 {
    unsigned char b0 : 2;
    unsigned char pending : 1;
    unsigned char b3 : 5;
};

struct Sub021db8d8 {
    char pad0[0xc00];
    char camera[0xe7c - 0xc00];
    struct Slot021db8d8* slot;
};

struct Work021db8d8 {
    char pad0[0x29c];
    void* battle;
    char pad2a0[0x2a8 - 0x2a0];
    struct List02169b04* keys;
    char pad2ac[0x46c - 0x2ac];
    unsigned int flags46c;
    char pad470[0x876 - 0x470];
    unsigned short timer876;
    char pad878[0xeac - 0x878];
    int stateeac;
    char padeb0[0x55d8 - 0xeb0];
    int mode55d8;
    char pad55dc[0x5951 - 0x55dc];
    struct Flags021db8d8 flags5951;
};

struct Slot021db8d8* GetSlotPtr02160f20(void*);
void* GetSlotPtr02160f60(void*);
unsigned int GetSubstructByte0x34_02049444(unsigned char*);
int GetSubstructByte0x1e_020493ec(unsigned char*);
int GetSubstructByte0x1d_020493c8(unsigned char*);
void SetSubstructByte0x1e_020493dc(unsigned char*, unsigned char);
void SetSubstructByte0x1c_02049390(unsigned char*, unsigned char);
struct Node02169b04* FindNodeByKey02169b04(struct List02169b04*, int);
struct Node02169b04* FindNode02169b54(struct Node02169b54*, int);
struct Actor021db8d8* GetNodeAtIndex02160094(struct List02160094*, int);
void RunFlagPassAndSetMode02167dd8_02167dd8(unsigned char*);
void ApplyField41ToGatheredCombatants02163a7c(struct GatherObj02163a7c*);
extern "C" int func_ov025_021dfa9c(void* obj, void* battle);
extern "C" void func_ov000_021626a0(void* obj, int a, int b);
extern "C" int func_ov000_02153e40(void* battle, short* ids, int max, int start);
extern "C" void func_02048cf0(GameObject* obj, int isTarget);
extern "C" void func_ov000_0216e678(void* camera, int first, int second, int suppress, int active);
extern "C" void func_ov000_0216d464(void* camera);
extern "C" void func_02048e2c(GameObject* obj);
extern "C" void func_ov025_021dc220(void* obj);
extern "C" void func_ov025_021eb7fc(void* obj);

// USA: func_ov025_021db8d8
extern "C" ARM void func_ov025_021db8d8(struct Work021db8d8* self) {
    int dist;
    struct Node02169b04* a;
    GameState* game;
    void* battle;
    int actorId;
    int ok;
    struct Node02169b04* b;
    int near;
    GameState* game1;
    int count2;
    int row;
    int pos;
    GameState* game2;
    struct List02169b04* keys;
    game = GameState::GetInstance();
    battle = self->battle;
    struct Sub021db8d8* sub = (struct Sub021db8d8*)((char*)self + 0x18);
    struct Slot021db8d8* slot = GetSlotPtr02160f20(self);
    actorId = -1;
    if (slot->actor) {
        actorId = slot->actor->id;
    }
    GameObject* actor = game->GetCombatantByIndex(actorId);
    int targetId = -1;
    if (slot->target) {
        targetId = slot->target->id;
    }
    int retreat = 0;
    if (actor && GetSubstructByte0x34_02049444((unsigned char*)actor)) {
        retreat = 1;
    }
    int skip = 0;
    keys = self->keys;
    if (keys) {
        struct Node02169b04* node = FindNodeByKey02169b04(keys, 0xc);
        ok = 1;
        a = FindNodeByKey02169b04(keys, 0x3d);
        b = FindNodeByKey02169b04(keys, 7);
        if (node && ((a && node == FindNode02169b54((struct Node02169b54*)a, 0xc)) ||
                     (b && node == FindNode02169b54((struct Node02169b54*)b, 0xc)))) {
            ok = 0;
        }
        if (ok) {
            if (node && node->kind != 0xa) {
                skip = 1;
            } else if (FindNodeByKey02169b04(keys, 0x20)) {
                skip = 1;
            } else if (FindNodeByKey02169b04(keys, 0x22)) {
                skip = 1;
            }
        }
    }
    if (func_ov025_021dfa9c(self, self->battle)) {
        retreat = 0;
        skip = 1;
    }
    int started = 0;
    if (retreat || !skip) {
        func_ov000_021626a0(self, 4, 1);
        near = 0;
        GameObject* target = game->GetCombatantByIndex(targetId);
        if (target && GetSubstructByte0x1e_020493ec((unsigned char*)target) != 0xff) {
            void* list = GetSlotPtr02160f60(self);
            if (list) {
                struct Actor021db8d8* first = GetNodeAtIndex02160094((struct List02160094*)list, 0);
                if (first && first->id == targetId) {
                    near = 1;
                }
            }
        }
        if (actor && target) {
            Vector3fix from = actor->obj3D_.position_;
            Vector3fix to = target->obj3D_.position_;
            dist = Vector3fix_Distance(&from, &to);
            if (dist < (actor->obj3D_.GetRadius() + target->obj3D_.GetRadius()) >> 1) {
                near = 1;
            }
        }
        if (self->mode55d8 != 0) {
            game1 = GameState::GetInstance();
            short ids[12];
            int count = func_ov000_02153e40(battle, ids, 12, 0);
            int any;
            for (int i = 0; i < count; i++) {
                GameObject* c = game1->GetCombatantByIndex(ids[i]);
                if (c && GetSubstructByte0x34_02049444((unsigned char*)c) >= 5) {
                    any = 1;
                    goto checked;
                }
            }
            any = 0;
        checked:
            if (!any && !near) {
                goto quiet;
            }
        }
        {
            int i;
            game2 = GameState::GetInstance();
            int id = -1;
            if (slot->actor) {
                id = slot->actor->id;
            }
            GameObject* obj = game2->GetCombatantByIndex(id);
            int tid = -1;
            if (slot->target) {
                tid = slot->target->id;
            }
            row = pos = 0xff;
            if (obj) {
                pos = GetSubstructByte0x1e_020493ec((unsigned char*)obj);
                row = GetSubstructByte0x1d_020493c8((unsigned char*)obj);
            }
            short ids[12];
            count2 = func_ov000_02153e40(battle, ids, 12, 0);
            for (i = 0; i < count2; i++) {
                GameObject* c = game2->GetCombatantByIndex(ids[i]);
                if (c) {
                    func_02048cf0(c, tid == ids[i]);
                }
            }
            if (obj) {
                SetSubstructByte0x1e_020493dc((unsigned char*)obj, pos);
                if (pos != 0xff && row != 0xff) {
                    SetSubstructByte0x1c_02049390((unsigned char*)obj, row);
                }
            }
            RunFlagPassAndSetMode02167dd8_02167dd8((unsigned char*)self);
            sub->slot = slot;
            func_ov000_0216e678(sub->camera, actorId, targetId, 0, 1);
            ApplyField41ToGatheredCombatants02163a7c((struct GatherObj02163a7c*)self);
            self->flags5951.pending = 0;
            retreat = 0;
            if (skip) {
                self->timer876 = 0x1f4;
            }
            goto shown;
        }
    quiet:
        sub->slot = slot;
        func_ov000_0216e678(sub->camera, actorId, targetId, 0, 0);
        RunFlagPassAndSetMode02167dd8_02167dd8((unsigned char*)self);
    shown:
        started = 1;
        func_ov000_0216d464(sub->camera);
    }
    if (self->flags5951.pending && skip) {
        self->flags46c |= 0x40;
    }
    if (retreat || (self->flags5951.pending && !skip)) {
        int i;
        int count;
        GameState* game3 = GameState::GetInstance();
        short ids[12];
        count = func_ov000_02153e40(battle, ids, 12, 0);
        for (i = 0; i < count; i++) {
            GameObject* c = game3->GetCombatantByIndex(ids[i]);
            if (c) {
                func_02048e2c(c);
            }
        }
        if (retreat) {
            self->stateeac = 2;
        } else {
            func_ov025_021dc220(self);
        }
    } else {
        func_ov025_021dc220(self);
    }
    if (started) {
        func_ov025_021eb7fc(&self->keys);
    }
}
