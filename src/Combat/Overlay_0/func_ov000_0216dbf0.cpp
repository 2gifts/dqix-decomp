#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_ov000_0216d370(char* obj, int flagA, int flagB, int flagC);
void SetFlagOrState0216d530(void*, int);
void ApplyVec3Tail_0202e694(void* obj, int* vec);

extern Vector3i data_ov000_02183280;

// USA: func_ov000_0216dbf0
extern "C" ARM void func_ov000_0216dbf0(char* self, int* ids, int count, short flag) {
    func_ov000_0216d370(self, 1, 1, 1);
    *(unsigned char*)(self + 0x220) = 3;

    Vector3i c = data_ov000_02183280;
    Vector3i v;
    v.x = 0x5e38;

    GameState* gs = GameState::GetInstance();

    int dist = 0;
    int rad = 0;
    int hgt = 0x2000;

    if (count == 1) {
        GameObject* o = gs->GetGameObjectByIndex(*ids);
        if (o != 0) {
            SetFlagOrState0216d530(self, *ids);
            rad = o->obj3D_.GetRadius() >> 1;
            hgt = o->obj3D_.GetHeight();
        }
    } else {
        for (int i = 0; i < count; i++, ids++) {
            GameObject* o = gs->GetGameObjectByIndex(*ids);
            if (o != 0) {
                Vector3i pos = o->obj3D_.position_;
                int len = Vector3fix_Length(&pos);
                if (dist < len) {
                    dist = len;
                    rad = o->obj3D_.GetRadius() >> 1;
                }
                if (hgt < o->obj3D_.GetHeight()) {
                    hgt = o->obj3D_.GetHeight();
                }
            }
        }
    }

    c.y = hgt >> 1;
    v.y = 0x1000;
    int a = (int)((((unsigned long long)((long long)(dist + rad) * 0x3000)) + 0x800ULL) >> 12);
    int b = (int)((((unsigned long long)((long long)hgt * 0x3000)) + 0x800ULL) >> 12);

    if (b < a) {
        v.z = a;
    } else {
        v.z = b;
    }

    if (!(flag != 0)) {
        v.y = 0x1000;
        if (v.z < 0x7000) {
            v.z = 0x7000;
        } else if (v.z > 0x10000) {
            v.y = v.y + (v.z - 0x10000) / 2;
        }
    } else {
        c.y = 0xb85;
        v.y = 0x3999;
        if (v.z < 0xe000) {
            v.z = 0xe000;
        }
    }

    *(Vector3i*)(self + 0x10) = c;
    ApplyVec3Tail_0202e694(self, (int*)&v);
    *(int*)(self + 0x238) = 0x1c;
    *(int*)(self + 0x23c) = 0x14;
}
