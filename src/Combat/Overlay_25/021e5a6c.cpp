// JPN: func_ov025_021e5f5c
#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { WorkFlag = 0x71c5 };
#else
enum { WorkFlag = 0x6fd5 };
#endif

struct Vec3 { int x; int y; int z; };

struct Obj021e5a6c {
    char pad0[8];
    Vec3 pos;            // 0x8
    unsigned char mode;  // 0x14
};

struct List021600f8;
struct ListNode021600f8;

int GetField0x3b0Value(GameState* battleStruct);
extern "C" struct ListNode021600f8* _Z22GetNodeAtIndex021600f8P12List021600f8i(struct List021600f8* list, int index);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);
extern "C" int _ZNK8Object3D9GetHeightEv(void* self);
void* GetActiveCombatWork(void);

// USA: func_ov025_021e5a6c
extern "C" ARM int func_ov025_021e5a6c(struct Obj021e5a6c* obj, struct List021600f8* list) {
    GameState* bs = GameState::GetInstance();
    int f = GetField0x3b0Value(bs);
    unsigned char mode = obj->mode;
    if (mode == 0) {
        if (f != 0) {
            _ZN8Vector3iaSERKS_((int*)(f + 0x10), (int*)&obj->pos);
        }
    } else if (mode == 2) {
        int height = 1;
        struct ListNode021600f8* node = _Z22GetNodeAtIndex021600f8P12List021600f8i(list, 0);
        if (node != 0) {
            GameObject* c = bs->GetCombatantByIndex(*(short*)((char*)node + 0xe));
            if (c != 0) {
                height = _ZNK8Object3D9GetHeightEv(c);
            }
        }
        float scale = 1.0f;
        if (height >= 9420) {
            scale = 1.0f + 0.6f * ((float)height / 4096.0f - 2.3f) / 1.7f;
            if (scale >= 1.6f) {
                scale = 1.6f;
            }
        }
        float posYf = (float)obj->pos.y / 4096.0f;
        float posZf = (float)obj->pos.z / 4096.0f;
        posYf = posYf * scale;
        posZf = posZf * scale;
        obj->pos.y = (int)(4096.0f * posYf);
        obj->pos.z = (int)(4096.0f * posZf);
        if (f != 0) {
            _ZN8Vector3iaSERKS_((int*)(f + 0x10), (int*)&obj->pos);
        }
    } else {
        if (f != 0) {
            Vec3 sum = *(Vec3*)(f + 0x10);
            Vec3 other = obj->pos;
            sum.x = sum.x + other.x;
            sum.y = sum.y + other.y;
            sum.z = sum.z + other.z;
            _ZN8Vector3iaSERKS_((int*)(f + 0x10), (int*)&sum);
        }
    }
    void* work = GetActiveCombatWork();
    if (work != 0) {
        *(unsigned char*)((char*)work + WorkFlag) = 1;
    }
    return 1;
}
