#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"

struct List021600f8;
struct ListNode021600f8 {
    char pad0[0xe];
    short combatantIndex;
};

struct CameraTask021e6ff8 {
    char pad0[8];
    unsigned char flags;
    char pad9[3];
    fix32_t angle;
    fix32_t height;
    fix32_t distance;
    int arg18;
    int arg1c;
    int arg20;
    unsigned char mode;
};

int GetField0x3b0Value(GameState* battleStruct);
void* GetActiveCombatWork(void);
unsigned char GetByte_021dcc64_021dcc64(void* obj);
ListNode021600f8* GetNodeAtIndex021600f8(List021600f8* list, int index);
void Call0202eab8AndApply020a0d6c(char* obj, int a, int b, int c, int d);

// USA: func_ov025_021e6ff8
extern "C" ARM int func_ov025_021e6ff8(CameraTask021e6ff8* task, List021600f8* list) {
    GameState* gs = GameState::GetInstance();
    int camera = GetField0x3b0Value(gs);
    void* work = GetActiveCombatWork();
    if (work != NULL) {
        *((unsigned char*)work + 0x6fd5) = 1;
        if (GetByte_021dcc64_021dcc64(work)) {
            return 1;
        }
    }
    Vector3fix v = *(Vector3fix*)(camera + 0x70);
    if (task->flags & 1) {
        if (fix32SignedAngleDistance(v.x, task->angle) > 0) {
            fix32_t a = task->angle;
            while (a < v.x) {
                a += FIX_2PI;
            }
            v.x = a;
        } else {
            fix32_t a = task->angle;
            while (v.x < a) {
                a -= FIX_2PI;
            }
            v.x = a;
        }
    }
    if (task->flags & 2) {
        v.y = task->height;
    }
    if (task->flags & 4) {
        v.z = task->distance;
    }
    if (task->mode == 2) {
        int height = 1;
        ListNode021600f8* node = GetNodeAtIndex021600f8(list, 0);
        if (node != NULL) {
            GameObject* c = gs->GetCombatantByIndex(node->combatantIndex);
            if (c != NULL) {
                height = c->obj3D_.GetHeight();
            }
        }
        float scale = 1.0f;
        if (height >= 0x1800) {
            scale = 1.0f + 0.8f * ((float)height / 4096.0f - 1.5f) / 2.5f;
            if (scale >= 1.8f) {
                scale = 1.8f;
            }
        }
        float y = (float)v.y / 4096.0f;
        float z = (float)v.z / 4096.0f;
        y = y * scale;
        z = z * scale;
        v.y = (int)(4096.0f * y);
        v.z = (int)(4096.0f * z);
    }
    Call0202eab8AndApply020a0d6c((char*)camera, (int)&v, task->arg18, task->arg1c, task->arg20);
    return 1;
}
