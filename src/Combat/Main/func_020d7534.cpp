#include <globaldefs.h>
#include "GameState/GameState.h"

struct IntField0x68_020377bc;

struct Vector3i;

struct Vec3_020d7534 { int x; int y; int z; };
extern "C" void func_020d74a4(void* base, int index, struct Vec3_020d7534 v);

void AdvanceActorCooldownsAndPosition0205a020(unsigned char* p, int dt);

struct Actor020d7534 {
    char pad0[0x50];
    struct Vec3_020d7534 pos;
    char pad1[0x74];
    int fieldD0;
    char pad2[4];
};

// USA: func_020d7534
extern "C" ARM void func_020d7534(struct Actor020d7534* obj) {
    GameState* battle = GameState::GetInstance();
    unsigned int scaleCount = battle->GetTickCount();
    int i;
    for (i = 0; i < 0xc; i++) {
        unsigned short flags = *(unsigned short*)((char*)obj + 0xa24);
        if (flags & (1 << i)) {
            int id = i;
            if (i > 3) {
                id = i + 0xbc;
            }
            GameObject* combatant = battle->GetGameObjectByIndex(id);
            if (combatant != 0) {
                struct Vec3_020d7534 v = *(struct Vec3_020d7534*)((char*)combatant + 0x84);
                v.y = ((Object3D*)((struct IntField0x68_020377bc*)combatant))->GetHeight();
                func_020d74a4(obj, i, v);

                if (obj[i].fieldD0 == 4) {
                    struct Actor020d7534* actor = &obj[i];
                    int limit = 0x6488;
                    struct Vec3_020d7534 tmp = actor->pos;
                    tmp.y = tmp.y + 0x66 + 0x200;
                    if (tmp.y > limit) {
                        tmp.y = tmp.y - limit;
                    }
                    *(Vector3i*)((int*)&actor->pos) = *(Vector3i const*)((int*)&tmp);
                }
                AdvanceActorCooldownsAndPosition0205a020((unsigned char*)&obj[i], scaleCount);
            }
        }
    }
}
