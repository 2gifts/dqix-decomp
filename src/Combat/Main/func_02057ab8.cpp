#include <globaldefs.h>

#include "System/Matrix.h"
#include "GameState/GameState.h"
#include "Graphics/NSBXX/GeometryFifo.h"
#include "Graphics/NSBXX/RenderConfig.h"
#include "World/Object3D.h"

extern "C" void* _Z17GetModel3DContextP7Model3D(void* mdl);
extern "C" Matrix4x3 _Z15RotationMatrixYi(int angle);
extern "C" void _Z18Vector3fixMultiplyPK8Vector3iS1_PS_(const Vector3fix* a, const Vector3fix* b, Vector3fix* out);
extern "C" void func_02059f54(void* elem, int idx);

struct Other02057ab8 {
    char pad0[0xc4];
    Vector3fix f_c4;
    Vector3fix f_d0;
    Vector3fix f_dc;
    Matrix4x3 f_e8;
};

struct Elem02057ab8 {
    char pad0[4];
    struct Other02057ab8* other;
    char pad1[0x44 - 0x8];
    Vector3fix pos;
    Vector3fix dir;
    char pad2[0xac - 0x5c];
    int f_ac;
    short f_b0;
    short f_b2;
    short f_b4;
    char pad3[0xd4 - 0xb6];
};

struct Container02057ab8 {
    char hdr[8];
    struct Elem02057ab8 elems[16];
};

extern "C" ARM void func_02057ab8(struct Container02057ab8* c, int id);

// USA: func_02057ab8
extern "C" ARM void func_02057ab8(struct Container02057ab8* c, int id) {
    GameState* gs = GameState::GetInstance();
    int i;
    if (id < 0) {
        return;
    }
    for (i = 0; i < 16; i++) {
        struct Elem02057ab8* e = &c->elems[i];
        if (id != e->f_b2) continue;
        if (e->f_b0 > 0) continue;
        void* obj = gs->GetGameObjectByIndex(e->f_b2);
        if (obj == 0) {
            e->f_b2 = -1;
            continue;
        }
        void* mdl = *(void**)((char*)obj + 8);
        if (mdl == 0) {
            e->f_b2 = -1;
            continue;
        }
        ModelRenderContext* ctx = (ModelRenderContext*)_Z17GetModel3DContextP7Model3D(mdl);
        if (ctx == 0) {
            e->f_b2 = -1;
            continue;
        }

        Matrix4x3 m;
        Mat4x3_WriteIdentity(&m);
        Vector3fix pos = *(Vector3fix*)((char*)obj + 0x44);
        Vector3fix dir = *(Vector3fix*)((char*)obj + 0x50);
        Vector3fix scale = ((Object3D*)obj)->GetScale();
        int flag = 0;
        if (e->f_b4 > -1) {
            if (GetModelBonePositionAndDirectionMatrices(ctx, (Matrix4x3*)flag, (Matrix3x3*)flag, (unsigned int)e->f_b4)) {
                const Matrix4x3* invView = RenderConfig::GetInverseViewMatrix();
                GetCurrentPositionAndDirectionMatrices(&m, (Matrix3x3*)flag);
                Mat4x3_Multiply(&m, invView, &m);
                flag = 1;
            }
        }
        if (e->f_ac == 0) {
            Vector3fix sp = e->pos;
            Vector3fix sd = e->dir;
            Vector3fix ss = ((Object3D*)e)->GetScale();
            Matrix4x3 rot2;
            Vector3fix tv;
            rot2 = _Z15RotationMatrixYi(dir.y);
            Mat4x3_ApplyToVector(&sp, &rot2, &tv);
            Vector3fix_Add(&pos, &tv, &pos);
            _Z18Vector3fixMultiplyPK8Vector3iS1_PS_(&scale, &ss, &scale);
            e->pos = pos;
            e->dir = dir;
            ((Object3D*)e)->SetScale(&scale);
            func_02059f54(e, i + 0xd0);
            func_02057ab8(c, i + 0xd0);
            e->pos = sp;
            e->dir = sd;
            ((Object3D*)e)->SetScale(&ss);
        } else if (e->f_ac == 1) {
            struct Other02057ab8* o = e->other;
            if (o != 0) {
                if (flag == 0) {
                    o->f_c4 = pos;
                    o->f_d0 = dir;
                    o->f_dc = scale;
                } else {
                    pos.x = m.translation.x;
                    pos.y = m.translation.y;
                    pos.z = m.translation.z;
                    Mat4x3_ApplyScale(&m, &m, 0xf627, 0xf627, 0xf627);
                    m.translation.x = pos.x;
                    m.translation.y = pos.y;
                    m.translation.z = pos.z;
                    o->f_e8 = m;
                }
            }
            func_02059f54(e, i + 0xd0);
            func_02057ab8(c, i + 0xd0);
        }
    }
}