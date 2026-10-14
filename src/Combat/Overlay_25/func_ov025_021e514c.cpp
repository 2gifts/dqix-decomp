#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"
#include "World/Object3D.h"

struct List02160094;
struct List021600f8;
struct Obj02033874;
struct Vector3i;
struct List02160094* GetNodeAtIndex02160094(struct List02160094* list, int idx);
struct List021600f8* GetNodeAtIndex021600f8(struct List021600f8* list, int idx);
int DispatchByIndex021820bc(void* obj, int unused, int index, int arg);
void* GetField0x3b0Value(GameState* gs);
int GetField0x70(void* obj);
void SetVecYFromValue02033874(struct Obj02033874* obj, int arg);
void StoreVec3AtField0x50(unsigned char* obj, int x, int y, int z);
extern "C" void* __clear(void* dst, int count);

static inline fix32_t FxMul(fix32_t a, fix32_t b) {
    return (int)(((long long)a * b + 0x800) >> 12);
}

struct Case8Local021e514c {
    Vector3fix tmp;
    Vector3fix diff;
    Vector3fix a;
    Vector3fix b;
};

struct Node021e514c_A {
    char pad[0x20];
    unsigned short field20;
};

struct Node021e514c_B {
    char pad[0xe];
    short field0e;
};

struct Self021e514c {
    char pad0[8];
    unsigned char idxA;
    unsigned char mode;
    unsigned char idxB;
    unsigned char flagB;
    int limitLo;
    int limitHi;
    Vector3fix vec;
    unsigned char flag20;
};

struct Obj021e514c {
    unsigned short flags;
    char pad2[0x42];
    Vector3fix position;
    Vector3fix rotation;
};

// USA: func_ov025_021e514c
extern "C" ARM int func_ov025_021e514c(struct Self021e514c* self, struct List02160094* p1, int unused, void* p3) {
    GameState* bs = GameState::GetInstance();
    struct Node021e514c_A* nodeA = (struct Node021e514c_A*)GetNodeAtIndex02160094(p1, 0);
    struct Node021e514c_B* nodeB = (struct Node021e514c_B*)GetNodeAtIndex021600f8((struct List021600f8*)p1, 0);
    int ids[8];
    int count = DispatchByIndex021820bc(p3, (int)p1, self->idxA, (int)ids);
    Vector3fix result;
    __clear(&result, sizeof(result));
    int yaw = 0;
    int dir = 0;
    unsigned char flagA = 0;
    unsigned char flagB = 0;
    int* idp;
    int i;

    if (nodeA) {
        int a;
        if (nodeA->field20 <= 3) a = 1; else a = 0;
        flagA = a;
    }
    if (nodeB) {
        int b = 0;
        if (nodeB->field0e >= 0 && nodeB->field0e <= 3) b = 1;
        flagB = b;
    }

    switch (self->mode) {
    case 1:
        if (flagA) dir = 1; else dir = 2;
        break;
    case 2:
        if (flagB) dir = 1; else dir = 2;
        break;
    case 5:
        if (flagA) dir = 2; else dir = 1;
        break;
    case 6:
        if (flagB) dir = 2; else dir = 1;
        break;
    case 3: {
        void* target = GetField0x3b0Value(bs);
        if (target) {
            Matrix4x3 m = RotationMatrixY(GetField0x70(target));
            Mat4x3_ApplyToVector(&self->vec, &m, &result);
        }
        break;
    }
    case 4:
    case 11: {
        if (nodeA == 0 || nodeB == 0) return 1;
        GameObject* obj = bs->GetGameObjectByIndex(nodeB->field0e);
        if (!obj) return 1;
        Obj021e514c* o = (Obj021e514c*)obj;
        fix32_t radius = obj->obj3D_.GetRadius();
        int rotY = o->rotation.y;
        if (self->mode == 4) self->vec.z = self->vec.z + (radius >> 1);
        else self->vec.z = self->vec.z - (radius >> 1);
        if (self->flagB == 1) {
            fix32_t h = obj->obj3D_.GetHeight() >> 1;
            self->vec.y = h;
            if (self->limitLo < self->vec.y) self->vec.y = self->limitLo;
            else if (self->vec.y < self->limitHi) self->vec.y = self->limitHi;
        }
        Matrix4x3 m = RotationMatrixY(rotY);
        Vector3fix off;
        Mat4x3_ApplyToVector(&self->vec, &m, &off);
        Vector3fix pos = o->position;
        Vector3fix_Add(&off, &pos, &off);
        int angle = fix32ReduceAngle0To2Pi(rotY + 0x3244);
        for (i = 0, idp = ids; i < count; i++, idp++) {
            GameObject* t = bs->GetGameObjectByIndex(*idp);
            if (t) {
                *(Vector3i*)((int*)((char*)t + 0x44)) = *(Vector3i const*)((int*)&off);
                if (((Obj021e514c*)t)->flags & 2) {
                    SetVecYFromValue02033874((struct Obj02033874*)t, angle);
                } else {
                    StoreVec3AtField0x50((unsigned char*)t, 0, angle, 0);
                }
            }
        }
        return 1;
    }
    case 7: {
        int out[12];
        DispatchByIndex021820bc(p3, (int)p1, self->idxB, (int)out);
        GameObject* obj = bs->GetGameObjectByIndex(out[0]);
        if (obj) {
            *(Vector3i*)((int*)&result) = *(Vector3i const*)((int*)((char*)obj + 0x44));
            yaw = ((Obj021e514c*)obj)->rotation.y;
        }
        break;
    }
    case 10: {
        GameObject* obj = bs->GetGameObjectByIndex(nodeA->field20);
        if (obj) {
            *(Vector3i*)((int*)&result) = *(Vector3i const*)((int*)((char*)obj + 0x44));
            result.y = result.y + (obj->obj3D_.GetHeight() >> 1);
            yaw = ((Obj021e514c*)obj)->rotation.y;
        }
        break;
    }
    case 8: {
        int* tgt = (int*)GetField0x3b0Value(bs);
        if (!tgt) return 1;
        Case8Local021e514c L;
        *(Vector3i*)((int*)&L.b) = *(Vector3i const*)(tgt + 4);
        *(Vector3i*)((int*)&L.a) = *(Vector3i const*)(tgt + 1);
        Vector3fix_Subtract(&L.a, &L.b, &L.diff);
        unsigned char axis = self->idxB;
        if (axis != 0 && axis < 4) {
            unsigned char k = axis - 1;
            L.tmp.x = self->vec.x;
            L.tmp.y = self->vec.y;
            L.tmp.z = self->vec.z;
            fix32_t* arr = (fix32_t*)&L.tmp;
            arr[k] = FxMul(arr[k], -0x1000);
            Vector3fix_Normalize(&L.diff, &L.diff);
            Vector3fixMultiplyScalar(&L.diff, arr[k], &L.diff);
            result.x = L.a.x + L.diff.x;
            result.y = L.a.y + L.diff.y;
            result.z = L.a.z + L.diff.z;
        } else {
            result.x = L.b.x + FxMul(L.diff.x, self->vec.x);
            result.y = L.b.y + FxMul(L.diff.y, self->vec.y);
            result.z = L.b.z + FxMul(L.diff.z, self->vec.z);
        }
        break;
    }
    case 9:
        *(Vector3i*)((int*)&result) = *(Vector3i const*)((int*)&self->vec);
        if (self->flag20) yaw = 0x3244;
        break;
    }

    if (dir != 0) {
        result.y = 0;
        result.x = 0;
        switch (dir) {
        case 1:
            yaw = 0x3244;
            result.z = 0x2800;
            break;
        case 2:
            yaw = 0;
            result.z = -0x2800;
            break;
        }
    }
    for (i = 0, idp = ids; i < count; i++, idp++) {
        GameObject* t = bs->GetGameObjectByIndex(*idp);
        if (t) {
            *(Vector3i*)((int*)((char*)t + 0x44)) = *(Vector3i const*)((int*)&result);
            if (((Obj021e514c*)t)->flags & 2) {
                SetVecYFromValue02033874((struct Obj02033874*)t, yaw);
            } else {
                StoreVec3AtField0x50((unsigned char*)t, 0, yaw, 0);
            }
        }
    }
    return 1;
}
