#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"
#include "std_library_functions.h"

struct InitStruct02078484Struct {
    char name[0x10];
    unsigned char f10;
    unsigned char flags11;
    short f12;
    short objectId;
    short f16;
    short f18;
    short f1a;
    short f1c;
    short pad1e;
    Vector3fix velocity;
    Vector3fix position;
    Vector3fix rotation;
    Vector3fix scale;
};

struct List02160094;
struct List021600f8;

struct Node02160094 {
    char pad0[0x20];
    unsigned short id;
};

struct Node021600f8 {
    char pad0[0xe];
    short targetId;
};

struct Reset021e3158 { int a; int b; int c; int d; int e; int f; };

struct Global021ef988 {
    char pad0[0x20];
    int state;
    int objectId;
};

struct Param021e4624 {
    char pad0[8];
    const char* name;
    unsigned short effectId;
    short distance;
};

extern "C" Node02160094* _Z22GetNodeAtIndex02160094P12List02160094i(List02160094* list, int index);
extern "C" Node021600f8* _Z22GetNodeAtIndex021600f8P12List021600f8i(List021600f8* list, int index);
extern "C" void _Z20ResetStruct_021e3158P13Reset021e3158(struct Reset021e3158* p);
extern "C" void _Z18InitStruct02078484P24InitStruct02078484Struct(struct InitStruct02078484Struct* p);
extern "C" int _Z26FindNodeAndProcess02057fb4Pvii(void* list, int id, struct InitStruct02078484Struct* req);
extern "C" void _Z35ClearCombatantSlotIfValidId02057db8ii(void* list, int id);
extern "C" void* func_02057924(void);

extern struct Reset021e3158 data_ov025_021ef9a8;
extern struct Global021ef988 data_ov025_021ef988;

// USA: func_ov025_021e4624
extern "C" ARM int func_ov025_021e4624(struct Param021e4624* p, void* slot) {
    GameState* gs = GameState::GetInstance();
    void* list = func_02057924();
    Node02160094* srcNode = _Z22GetNodeAtIndex02160094P12List02160094i((List02160094*)slot, 0);
    Node021600f8* dstNode = _Z22GetNodeAtIndex021600f8P12List021600f8i((List021600f8*)slot, 0);
    int srcId = srcNode->id;
    int dstId = dstNode->targetId;
    GameObject* src = gs->GetGameObjectByIndex(srcId);
    GameObject* dst = gs->GetGameObjectByIndex(dstId);
    if (src == NULL || dst == NULL) {
        _Z20ResetStruct_021e3158P13Reset021e3158(&data_ov025_021ef9a8);
        return 1;
    }

    if (data_ov025_021ef988.state == 0) {
        struct InitStruct02078484Struct req;
        _Z18InitStruct02078484P24InitStruct02078484Struct(&req);
        Vector3fix from = src->obj3D_.position_;
        Vector3fix to = dst->obj3D_.position_;
        Vector3fix dir;
        Vector3fix_Subtract(&to, &from, &dir);
        dir.y = 0;
        Vector3fix_Normalize(&dir, &dir);
        Vector3fixMultiplyScalar(&dir, p->distance, &req.velocity);
        req.position = src->obj3D_.position_;
        req.rotation = src->obj3D_.rotation_;
        req.scale = src->obj3D_.GetScale();
        req.position.y += src->obj3D_.GetHeight() / 2;
        if (p->name != NULL) {
            strcpy(req.name, p->name);
        }
        data_ov025_021ef988.objectId = _Z26FindNodeAndProcess02057fb4Pvii(list, p->effectId, &req);
        data_ov025_021ef988.state++;
        return 0;
    }

    if (data_ov025_021ef988.state == 1) {
        GameObject* effect = gs->GetGameObjectByIndex(data_ov025_021ef988.objectId);
        if (effect == NULL) {
            _Z20ResetStruct_021e3158P13Reset021e3158(&data_ov025_021ef9a8);
            return 1;
        }
        Vector3fix a = dst->obj3D_.position_;
        Vector3fix b = effect->obj3D_.position_;
        fix32_t dist = Vector3fix_Distance(&a, &b);
        fix32_t range = (src->obj3D_.GetHeight() + dst->obj3D_.GetHeight()) / 2;
        if (range < p->distance * 2) {
            range = p->distance * 2;
        }
        if (dist >= range) {
            return 0;
        }
        _Z35ClearCombatantSlotIfValidId02057db8ii(list, data_ov025_021ef988.objectId);
        _Z20ResetStruct_021e3158P13Reset021e3158(&data_ov025_021ef9a8);
        return 1;
    }

    _Z20ResetStruct_021e3158P13Reset021e3158(&data_ov025_021ef9a8);
    return 1;
}
