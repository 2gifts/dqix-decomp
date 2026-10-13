#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/LightingManager.h"
#include "World/Object3D.h"

#if defined(jpn)
#define _Z27FindNodeByField0x2c0201b754Pvi func_0201b4cc
#endif

struct WorldObjectPositionView {
    Object3D object;
    unsigned char unknownAc[0x144 - 0xac];
    Vector3i secondaryPosition;
};
struct SavedObjectNode {
    unsigned char unknown0[8];
    Vector3i position;
    unsigned char unknown14[0x20 - 0x14];
    short angle;
};
struct Obj0201b600;
struct Struct02013380;
struct Obj02033874;
struct PointerField32c_ffc0;

struct Ctx020a72ac {
    unsigned short key;
#if defined(jpn)
    char pad0[0x27c4 - 2];
#else
    char pad0[0x2784 - 2];
#endif
    short field2784;
    unsigned short field2786;
    unsigned char flag2788;
};

extern "C" void* func_0202ae18();
extern "C" int func_0202c540(void* base);
void SetVec3At0x0020a6aa4(Vector3i* obj, int x, int y, int z);
void* GetPointerAt0x32c(struct PointerField32c_ffc0* p);
struct Obj0201b600* FindElemByKeys(struct Obj0201b600* p, int a, short b);
void SetFlag0x40AndToggle0x4(struct Struct02013380* p, int a, int b);
extern "C" void _Z25ApplyElementFlags0201b8c8P11Obj0201b600iii(struct Obj0201b600* p, int a, int b, int c);
extern "C" void* _Z27FindNodeByField0x2c0201b754Pvi(void* p, int v);
extern "C" void _Z24SetVecYFromValue02033874P11Obj02033874i(struct Obj02033874* p, int v);

// USA: func_020a72ac
extern "C" ARM void func_020a72ac(struct Ctx020a72ac* p) {
    GameState* gs = GameState::GetInstance();
    func_ov017_0218b5b0();
    void* base = func_0202ae18();
    LightingManager::GetInstance();
    Object3D* obj = static_cast<Object3D*>(GetPointerAt0x32c((struct PointerField32c_ffc0*)gs));
    GameObject* actor = gs->GetUnknownGameObject();
    gs->GetPartyMemberByIndex(0);

    if (p->flag2788 == 0) {
        if (p->field2786 == p->key) {
            if (p->key == 0x76c) {
                struct Obj0201b600* e = FindElemByKeys((struct Obj0201b600*)p, 0, 4);
                if (e) SetFlag0x40AndToggle0x4((struct Struct02013380*)e, 0, 1);
                e = FindElemByKeys((struct Obj0201b600*)p, 0, 0x28);
                if (e) SetFlag0x40AndToggle0x4((struct Struct02013380*)e, 0, 1);
            } else if (obj) {
                obj->MakeVisible();
                SavedObjectNode* node = static_cast<SavedObjectNode*>(_Z27FindNodeByField0x2c0201b754Pvi(p, p->field2784));
                if (node) {
                    obj->position_ = node->position;
                    reinterpret_cast<WorldObjectPositionView*>(obj)->secondaryPosition = node->position;
                    _Z24SetVecYFromValue02033874P11Obj02033874i((struct Obj02033874*)obj, node->angle);
                }
            }
        } else {
            if (p->key == 0x170c) {
                _Z25ApplyElementFlags0201b8c8P11Obj0201b600iii((struct Obj0201b600*)p, 0, 1, 0);
            } else if (p->key == 0x2774 || p->key == 0x2710) {
                if (obj) obj->MakeVisible();
            } else if (obj) {
                obj->MakeHidden();
            }
        }
    } else {
        if (p->field2786 == p->key) {
            if (obj) obj->MakeHidden();
        } else if (p->key == 0x170c) {
            _Z25ApplyElementFlags0201b8c8P11Obj0201b600iii((struct Obj0201b600*)p, 1, 0, 1);
            Vector3i local = actor->obj3D_.position_;
            if (local.z >= 0x6000 && local.x >= -0x8333 && local.x <= -0x5ccc) {
                SetVec3At0x0020a6aa4(&local, -0x7000, 0x2e1, 0x5e66);
                actor->obj3D_.position_ = local;
            }
        } else if (p->key == 0x76c) {
            struct Obj0201b600* e = FindElemByKeys((struct Obj0201b600*)p, 0, 4);
            if (e) SetFlag0x40AndToggle0x4((struct Struct02013380*)e, 0, 0);
            e = FindElemByKeys((struct Obj0201b600*)p, 0, 0x28);
            if (e) SetFlag0x40AndToggle0x4((struct Struct02013380*)e, 0, 0);
        } else if (p->key == 0x2774) {
            if (obj) obj->MakeVisible();
        } else if (func_0202c540(base) && p->key == 0x2710) {
            if (obj) obj->MakeVisible();
        } else if (obj) {
            obj->MakeHidden();
        }
    }
}
