#include <globaldefs.h>
#include "GameState/GameState.h"

struct Camera021e5c68 {
    char pad0[0x70];
    Vector3fix position;
};

struct CameraStep021e5c68 {
    char pad0[8];
    Vector3fix offset;
    unsigned char mode;
};

struct Node021e5c68 {
    char pad0[0xe];
    short combatant;
};

Camera021e5c68* GetField0x3b0Value(GameState* gs);
void ApplyVec3Tail(void* obj, int* vec);
extern "C" Node021e5c68* _Z22GetNodeAtIndex021600f8P12List021600f8i(void* list, int idx);
extern "C" char* _Z19GetActiveCombatWorkv();

// USA: func_ov025_021e5c68
extern "C" ARM int func_ov025_021e5c68(CameraStep021e5c68* step, void* list) {
    GameState* gs = GameState::GetInstance();
    Camera021e5c68* cam = GetField0x3b0Value(gs);
    if (step->mode == 0) {
        if (cam != 0) ApplyVec3Tail(cam, (int*)&step->offset);
    } else if (step->mode == 2) {
        fix32_t height = 1;
        Node021e5c68* node = _Z22GetNodeAtIndex021600f8P12List021600f8i(list, 0);
        if (node != 0) {
            GameObject* c = gs->GetCombatantByIndex(node->combatant);
            if (c != 0) height = c->obj3D_.GetHeight();
        }
        float scale = 1.0f;
        if (height >= 0x24cc) {
            scale = 1.0f + ((height / 4096.0f - 2.3f) * 0.6f) / 1.7f;
            if (scale >= 1.6f) scale = 1.6f;
        }
        step->offset.z = (int)(4096.0f * ((step->offset.z / 4096.0f) * scale));
        if (cam != 0) ApplyVec3Tail(cam, (int*)&step->offset);
    } else {
        if (cam != 0) {
            Vector3fix pos = cam->position;
            Vector3fix off = step->offset;
            pos.x = pos.x + off.x;
            pos.y = pos.y + off.y;
            pos.z = pos.z + off.z;
            ApplyVec3Tail(cam, (int*)&pos);
        }
    }
    char* work = _Z19GetActiveCombatWorkv();
    if (work != 0) work[0x6fd5] = 1;
    return 1;
}
