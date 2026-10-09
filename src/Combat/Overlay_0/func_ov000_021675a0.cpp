#include <globaldefs.h>
#include "GameState/GameState.h"

struct Vec3_021675a0 {
    int x;
    int y;
    int z;
};

struct Scene021675a0 {
    char pad[0x284];
    char* world;
    char pad2[0xc00 - 0x288];
    char camera[0x230];
};

struct Owner021675a0 {
    char pad[0x18];
    struct Scene021675a0 scene;
};

extern "C" int func_ov000_0215e9fc(char* world, short* buf, int max, int start);
int ClassifyField0x81fe(char* base);
void SetSubstructFields4And0xcClearFlag0x2(unsigned char* obj, int* src);
void SetSubstructField0x8ClearFlag0x2(unsigned char* obj, int* src);
extern "C" void _Z23SetIntField552_0216f708Pvi(void* obj, int val);
extern "C" void _Z23SetIntField556_0216f710Pvi(void* obj, int val);

extern int data_ov000_02183158[][4];
extern struct Vec3_021675a0 data_ov000_021830e4;
extern struct Vec3_021675a0 data_ov000_021830b4;

// USA: func_ov000_021675a0
extern "C" ARM void func_ov000_021675a0(struct Owner021675a0* owner) {
    char* world;
    char* camera;
    int count;
    int x;
    int i;
    int width;
    GameState* gs = GameState::GetInstance();
    func_ov017_0218b5b0();
    short ids[4];
    world = owner->scene.world;
    camera = owner->scene.camera;
    count = func_ov000_0215e9fc(world, ids, 4, 0);
    if (ClassifyField0x81fe(world)) count = 1;

    width = (count - 1) * 0x1800;
    x = width / 2;
    for (i = 0; i < count; i++) {
        GameObject* c = gs->GetCombatantByIndex(ids[i]);
        if (c != NULL) {
            struct Vec3_021675a0 pos = data_ov000_021830e4;
            struct Vec3_021675a0 rot = data_ov000_021830b4;
            pos.x = x;
            rot.y = data_ov000_02183158[count - 1][i];
            SetSubstructFields4And0xcClearFlag0x2((unsigned char*)c, (int*)&pos);
            SetSubstructField0x8ClearFlag0x2((unsigned char*)c, (int*)&rot);
        }
        x -= 0x1800;
    }
    _Z23SetIntField552_0216f708Pvi(camera, width + 0x1000);
    _Z23SetIntField556_0216f710Pvi(camera, 0x1800);
}
