#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_ov000_0216733c(struct BattleScene021663a0* scene);
extern "C" void func_ov000_02166540(struct BattleScene021663a0* scene, int id, int kind, int group);
extern "C" void func_0203232c(int* ids, int count);
GameObject* GetCombatantWithFlag0x400(GameState* battleStruct, int combatantId);
int CheckSubstructFlag0x80(unsigned char* obj);

struct EnemyGroup021663a0 {
    unsigned short kind;
    unsigned char ids[8];
    unsigned char count : 4;
    unsigned char rest : 4;
    char pad_b[0x18 - 0xb];
};

struct Formation021663a0 {
    unsigned char field_0x0;
    unsigned char lo : 4;
    unsigned char groupCount : 2;
    unsigned char hi : 2;
    char pad_2[2];
    struct EnemyGroup021663a0 groups[3];
};

struct BattleData021663a0 {
    char pad_0[0x81b0];
    struct Formation021663a0 formation;
    char pad_81fc[0x8de0 - 0x81b0 - sizeof(struct Formation021663a0)];
    int slots[8];
};

struct BattleConfig021663a0 {
    char pad_0[0x2c];
    int field_0x2c;
};

struct BattleScene021663a0 {
    char pad_0[0x29c];
    struct BattleData021663a0* data;
    struct BattleConfig021663a0* config;
};

// USA: func_ov000_021663a0
extern "C" ARM void func_ov000_021663a0(struct BattleScene021663a0* scene) {
    GameState* gs = GameState::GetInstance();
    func_ov017_0218b5b0();
    struct Formation021663a0* formation = &scene->data->formation;
    int count = 0;
    func_ov000_0216733c(scene);
    unsigned char saved[8];
    int ids[8];
    if (scene->config->field_0x2c != 0) {
        unsigned char* p = saved;
        for (int i = 0; i < 8; i++) {
            *p = scene->data->slots[i];
            p++;
        }
    }
    for (int g = 0; g < formation->groupCount; g++) {
        struct EnemyGroup021663a0* group = &formation->groups[g];
        for (int j = 0; j < group->count; j++) {
            int id = group->ids[j] + 0xc0;
            func_ov000_02166540(scene, id, group->kind, g);
            ids[count++] = id;
        }
    }
    if (scene->config->field_0x2c != 0) {
        unsigned char* p = saved;
        for (int i = 0; i < 8; i++) {
            scene->data->slots[i] = *p;
            p++;
        }
    }
    func_0203232c(ids, count);
    for (int i = 0; i < count; i++) {
        GameObject* c = GetCombatantWithFlag0x400(gs, ids[i]);
        if (c != 0 && scene->config->field_0x2c == 0 && !CheckSubstructFlag0x80((unsigned char*)c)) {
            c->obj3D_.SetInheritedAlpha(0);
            ((unsigned char*)c)[0x183] = 0x10 / count * i + 5;
        }
    }
}
