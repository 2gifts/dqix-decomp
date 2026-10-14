#include <globaldefs.h>
#include "GameState/GameState.h"
#include "System/Matrix.h"

struct SearchStruct0202c1a4;
extern "C" int rand();
extern "C" void* __clear(void*, int);
struct Actor02076ccc;
extern "C" void* func_0202ae18();
int CheckField0NonZero_0202b7d8(int*);
signed char GetSearchStructCurrentArrEntry(SearchStruct0202c1a4*);
int GetFieldAt0x150_02053c6c(unsigned char*);
bool TrySetMode02076ccc(void*, int);
struct Vec3i021c95ec { int x, y, z; };
extern "C" void func_ov017_021c95ec(int, int, int, int, int, Vec3i021c95ec, int, unsigned char, unsigned char);

struct Attributes02078998 {
    char pad0[0xa];
    unsigned short attack;
    unsigned short defense;
};
struct Actor02078998 {
    Object3D obj;
    char padac[0x13b - 0xac];
    unsigned char selectorA;
    unsigned char selectorB;
    char pad13d[3];
    int priority;
    char pad144[8];
    unsigned int counter;
    char pad150[0x166 - 0x150];
    unsigned short combatantId;
    char pad168[8];
    int height;
    short rise;
    char pad176[4];
    unsigned char rising;
    char pad17b[0x184 - 0x17b];
    Attributes02078998* attributes;
};
static inline void SendModeEvent02078998(int id, int nibble, int unused, int mode, Actor02078998* self) {
    Vec3i021c95ec position;
    __clear(&position, sizeof(position));
    func_ov017_021c95ec(id, nibble, unused, mode, self->combatantId, position, 0, 0, 0);
}

// USA: func_02078998
extern "C" ARM void func_02078998(Actor02078998* self) {
    if (self->counter <= 225) {
        Vector3fix position = self->obj.position_;
        int scaledY = self->obj.GetScale().y * 15;
        int scaledHeight = (int)(1.15f * (float)self->obj.GetHeight());
        scaledHeight = FIX32_MULTIPLY(scaledHeight, scaledY);
        position.y = scaledHeight + position.y;
        self->rise += (112 - self->counter * 2) * 3;
        if (self->rise < 0) self->rise = 0;
        position.y += self->rise;
        self->height = position.y;
        self->rising = 1;
    }
    if (self->counter <= 225) return;
    self->rising = 0;
    int* search = (int*)func_0202ae18();
    if (CheckField0NonZero_0202b7d8(search) && GetSearchStructCurrentArrEntry((SearchStruct0202c1a4*)search)) return;
    GameObject* combatant = GetCombatantWithFlag0x100_0200ff1c(GameState::GetInstance(), self->combatantId);
    if (combatant == NULL) return;
    GetFieldAt0x150_02053c6c((unsigned char*)combatant);
    int extraAttack = 0;
    int extraDefense = 0;
    int attack = combatant->baseStats_->primaryStats.attack;
    int defense = combatant->baseStats_->primaryStats.defense;
    if (self->attributes != NULL) {
        extraAttack = self->attributes->attack;
        extraDefense = self->attributes->defense;
    }
    int mode;
    if ((attack + defense > (extraAttack + extraDefense) * 3 || self->priority == -99) && self->priority != 99) {
        switch (self->selectorA) {
        case 0:
            TrySetMode02076ccc((Actor02076ccc*)self, 12);
            mode = 12;
            break;
        case 1:
            TrySetMode02076ccc((Actor02076ccc*)self, 6);
            mode = 6;
            break;
        case 2:
            TrySetMode02076ccc((Actor02076ccc*)self, 7);
            mode = 7;
            break;
        case 3:
            if (rand() % 2) {
                TrySetMode02076ccc((Actor02076ccc*)self, 7);
                mode = 7;
            } else {
                TrySetMode02076ccc((Actor02076ccc*)self, 6);
                mode = 6;
            }
            break;
        }
    } else {
        switch (self->selectorB) {
        case 0:
            TrySetMode02076ccc((Actor02076ccc*)self, 5);
            mode = 5;
            break;
        case 1:
            TrySetMode02076ccc((Actor02076ccc*)self, 4);
            mode = 4;
            break;
        case 2:
            if (rand() % 2) {
                TrySetMode02076ccc((Actor02076ccc*)self, 7);
                mode = 7;
            } else {
                TrySetMode02076ccc((Actor02076ccc*)self, 6);
                mode = 6;
            }
            break;
        }
    }
    if (!CheckField0NonZero_0202b7d8(search) || GetSearchStructCurrentArrEntry((SearchStruct0202c1a4*)search)) return;
    unsigned short id = self->obj.GetField06();
    int unused = self->obj.unknown_2_;
    int nibble = (self->obj.unknown_4_ - 112) % 12;
    if (nibble >= 0 && nibble < 12) {
        SendModeEvent02078998(id, nibble, unused, mode, self);
    }
}
