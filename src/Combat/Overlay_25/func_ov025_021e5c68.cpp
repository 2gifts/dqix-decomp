#include <globaldefs.h>
#include "GameState/GameState.h"
#include "GameState/Field3b0.h"

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

void ApplyVec3Tail_0202e694(void* obj, int* vec);
struct List021600f8;
Node021e5c68* GetNodeAtIndex021600f8(List021600f8*, int);
char* GetActiveCombatWork_ov000_02160130();

// USA: func_ov025_021e5c68
extern "C" ARM int func_ov025_021e5c68(CameraStep021e5c68* step, void* list) {
#if defined(jpn)
 enum {regionalOffset0=0x71c5};
#else
 enum {regionalOffset0=0x6fd5};
#endif
    GameState* gs = GameState::GetInstance();
    Camera021e5c68* cam = (Camera021e5c68*)GetField0x3b0Value_020100bc(gs);
    if (step->mode == 0) {
        if (cam != 0) ApplyVec3Tail_0202e694(cam, (int*)&step->offset);
    } else if (step->mode == 2) {
        fix32_t height = 1;
        Node021e5c68* node = GetNodeAtIndex021600f8((List021600f8*)list, 0);
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
        if (cam != 0) ApplyVec3Tail_0202e694(cam, (int*)&step->offset);
    } else {
        if (cam != 0) {
            Vector3fix pos = cam->position;
            Vector3fix off = step->offset;
            pos.x = pos.x + off.x;
            pos.y = pos.y + off.y;
            pos.z = pos.z + off.z;
            ApplyVec3Tail_0202e694(cam, (int*)&pos);
        }
    }
    char* work = GetActiveCombatWork_ov000_02160130();
    if (work != 0) work[regionalOffset0] = 1;
    return 1;
}
