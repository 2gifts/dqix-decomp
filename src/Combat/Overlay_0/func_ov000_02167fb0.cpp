#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/FormationPosition.h"

extern "C" int func_ov000_02153e40(void* obj, short* buf, int max, int start);
extern "C" void _Z24StoreThreeFields02167b54Piiii(int* obj, int a, int b, int c);
int GetSubstructByte0x1c(unsigned char* obj);
void SetSubstructByte0x1c(unsigned char* obj, unsigned char value);
void SetSubstructFields0x10And0x18ClearFlag0x1(unsigned char* obj, int* src);
void SetSubstructField0x14ClearFlag0x1(unsigned char* obj, int* src);

struct Words3_02167fb0 { int v[3]; };
extern struct Words3_02167fb0 data_ov000_021830d8;
extern int data_ov000_02183198[16];
extern int data_ov000_021831d8[16];

struct Battle02167fb0 {
    char pad0[0x29c];
    void* combatants;
};

// USA: func_ov000_02167fb0
extern "C" ARM void func_ov000_02167fb0(struct Battle02167fb0* battle, GameObject* target) {
    if (target == NULL) {
        return;
    }
    GameState* gs = GameState::GetInstance();
    short ids[0x10];
    int count = func_ov000_02153e40(battle->combatants, ids, 0x10, 0);
    int rotation[3];
    int* cells;
    int isParty = (target->obj3D_.unknown_4_ >= 0 && target->obj3D_.unknown_4_ <= 3) ? 1 : 0;
    if (isParty) {
        cells = data_ov000_02183198;
        _Z24StoreThreeFields02167b54Piiii(rotation, 0, 0x3244, 0);
    } else {
        int isGuest = (target->obj3D_.unknown_4_ >= 0xc0 && target->obj3D_.unknown_4_ <= 0xc7) ? 1 : 0;
        if (!isGuest) {
            return;
        }
        cells = data_ov000_021831d8;
        _Z24StoreThreeFields02167b54Piiii(rotation, 0, 0, 0);
    }
    for (int i = 0; i < 0x10; i++) {
        int cell = cells[i];
        int taken = 0;
        for (int j = 0; j < count; j++) {
            GameObject* c = gs->GetCombatantByIndex(ids[j]);
            if (c != NULL && cell == GetSubstructByte0x1c((unsigned char*)c)) {
                taken = 1;
                break;
            }
        }
        if (!taken) {
            struct Vec2_0216f74c pos = func_ov000_0216f74c(&cell);
            SetSubstructByte0x1c((unsigned char*)target, cell & 0xff);
            struct Words3_02167fb0 position = data_ov000_021830d8;
            position.v[0] = pos.x;
            position.v[2] = pos.y;
            SetSubstructFields0x10And0x18ClearFlag0x1((unsigned char*)target, position.v);
            SetSubstructField0x14ClearFlag0x1((unsigned char*)target, rotation);
            return;
        }
    }
}
