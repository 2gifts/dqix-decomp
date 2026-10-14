#include "Resource/ActionDataTables.h"
#include <globaldefs.h>
#include <GameState/GameState.h>

struct ActorNode021dc324 { char pad0[0x20]; unsigned short id; };
struct TargetNode021dc324 { char pad0[0xe]; short id; char pad10[0x10]; TargetNode021dc324* next; };
struct Slot021dc324 { unsigned short id; char pad2[0xe]; ActorNode021dc324* actor; TargetNode021dc324* target; };
struct Skill021dc324 {
    int field0;
    unsigned int id:12, flags4:20;
    char pad8[12]; unsigned int flags14:28, kind:4;
};
struct Body021dc324 { char pad0[0xc00]; char checkTask[0x260]; unsigned char active; };
struct Display021dc324 { char pad0[0x5ce]; short delay; char pad5d0[0xe78 - 0x2a8 - 0x5d0]; };
struct ObjectRegion021dc324 { char pad0[0x5800]; Object3D object; };
struct BattleEffectWork021dc324 {
    union {
        struct { char pad0[0x18]; Body021dc324 body; };
        struct { char pad0c[0x154]; ObjectRegion021dc324 objectRegion; };
        struct {
            char pad0b[0x29c]; char* battle; char pad2a0[8]; Display021dc324 display;
            unsigned char active; char padE79[0x33]; int state;
            char padEb0[0x5954 - 0xeb0]; Object3D object1;
            Object3D object2; char pad5aac[4]; char task[0x5c3a - 0x5ab0]; unsigned char ready;
        };
    };
};
struct Global021dc324 { int field0; int active; };
struct Timer021dc324 { unsigned char flag; char pad1; unsigned short remaining; };
extern Global021dc324 data_ov025_021ef404;
extern "C" Timer021dc324 _ZZ16GetTimer021ef974vE1s;
Slot021dc324* GetSlotPtr02160f20(void*);
int GetByte2105_021ea46c(void*);
int GetByteField0x261Or1(void*);
Skill021dc324* SearchBothTables02079e2c(char*, int);
int IsMatchingID02163690(int);
int ClassifyField0x81fe(char*);
extern "C" void func_ov025_021df5e4(void*, int, int);
extern "C" int func_ov025_021df9f4(GameObject*);
int CheckSubstructFlag0x10(unsigned char*);
extern "C" void _Z20SetSubstructByte0x6cPhh(unsigned char*, int);
extern "C" void func_02033920(GameObject*, int, int);
extern "C" void func_ov025_021ea474(void*);
extern "C" void func_ov025_021eb6fc(void*, int);

// USA: func_ov025_021dc324
extern "C" ARM void func_ov025_021dc324(BattleEffectWork021dc324* self) {
    GameState* game = GameState::GetInstance();
    char* battle = self->battle;
    Body021dc324* body;
    Slot021dc324* slot = GetSlotPtr02160f20(self);
    body = &self->body;
    if (!GetByte2105_021ea46c(&self->display)) return;
    ActionDataTables* data = GetData02108e10();
    ObjectRegion021dc324* objectRegion = &self->objectRegion;
    if (data_ov025_021ef404.active) {
        if (!GetByteField0x261Or1(body->checkTask)) return;
        objectRegion->object.MakeHidden();
        self->object2.MakeHidden();
        int special = 0;
        Skill021dc324* skill = SearchBothTables02079e2c((char*)data, (short)slot->id);
        if (IsMatchingID02163690(slot->id)) special = 1;
        else if (skill) {
            if (skill->kind == 2) special = 1;
            if (skill->id == 0xae) special = 1;
        }
        if (special && slot->actor && slot->target) {
            int allow;
            int actor = slot->actor->id;
            int target = slot->target->id;
            allow = 1;
            if (ClassifyField0x81fe(battle)) {
                if (actor == 0) allow = 0;
            }
            if (!body->active) allow = 0;
            if (allow) {
                func_ov025_021df5e4(self->task, actor, target);
            }
            GameObject* combatant = game->GetCombatantByIndex(target);
            if (func_ov025_021df9f4(combatant)) {
                if (skill->id == 0xae && CheckSubstructFlag0x10((unsigned char*)combatant)) return;
                if (_ZZ16GetTimer021ef974vE1s.flag) _Z20SetSubstructByte0x6cPhh((unsigned char*)combatant, actor);
                else func_02033920(combatant, actor, 1);
            }
        }
        if (!self->ready) self->state = 3;
        func_ov025_021ea474(&self->display);
        data_ov025_021ef404.active = 0;
        _ZZ16GetTimer021ef974vE1s.remaining = 0;
    } else {
        unsigned int elapsed = game->GetEffectiveDeltaTime();
        if (_ZZ16GetTimer021ef974vE1s.remaining < elapsed) {
            TargetNode021dc324* target;
            GameState* readyGame = GameState::GetInstance();
            target = slot->target;
            int ready;
            while (target) {
                GameObject* combatant = readyGame->GetCombatantByIndex(target->id);
                if (combatant && CheckSubstructFlag0x10((unsigned char*)combatant)) { ready = 0; goto readinessDone; }
                target = target->next;
            }
            ready = 1;
        readinessDone:
            if (ready) self->state = 3;
        } else _ZZ16GetTimer021ef974vE1s.remaining -= elapsed;
    }
    if (slot->id == 0xdb) { self->display.delay = 750; return; }
    func_ov025_021eb6fc(&self->display, 0);
}
