#include <globaldefs.h>
#include "GameState/GameState.h"

struct Holder_375cc;
struct Node_375cc;
extern "C" Node_375cc* _ZN8Object3D26GetAnimationPackageByIndexEi(Holder_375cc* holder, int index);

struct List_020347b4;
struct Entry_020347b4;
extern "C" Entry_020347b4* _ZN4BCFG18GetAnimationRecordEi(List_020347b4* list, int index);

struct Sub0204a054 {
    char pad[0x58];
    unsigned char field_58;
    unsigned char field_59;
    unsigned char field_5a;
    unsigned char field_5b;
    unsigned short field_5c;
};

struct Obj0204a054 {
    char pad[0x13c];
    struct Sub0204a054* field_13c;
};

// USA: func_0204a054
ARM void ApplyCountdownOrDispatch0204a054(struct Obj0204a054* obj) {
    GameState* battleStruct;
    struct Sub0204a054* entry;
    int threshold;
    unsigned short v;
    battleStruct = GameState::GetInstance();
    entry = obj->field_13c;
    if (entry->field_5c == 0) return;
    threshold = battleStruct->GetEffectiveDeltaTime();
    v = entry->field_5c;
    if ((unsigned int)threshold < v) {
        entry->field_5c = v - threshold;
        return;
    }
    {
        Node_375cc* node = _ZN8Object3D26GetAnimationPackageByIndexEi((Holder_375cc*)obj, entry->field_58);
        if (node != NULL) {
            Entry_020347b4* member = _ZN4BCFG18GetAnimationRecordEi((List_020347b4*)((char*)node + 4), entry->field_59);
            if (member != NULL) {
                ((Object3D*)obj)->MaybeSetRegularAnimation((char const*)member, entry->field_5a);
            }
        }
    }
    entry->field_5c = 0;
}
