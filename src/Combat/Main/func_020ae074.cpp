#include <globaldefs.h>
#include "GameState/GameState.h"

struct HeightShiftedObject : Object3D {
    short field_ac_, heading_;
    char padB0[0x150 - 0xb0];
    int heightOffset_;
    char pad154[0x164 - 0x154];
    Vector3fix firstPosition_;
    int firstHeading_;
    Vector3fix secondPosition_;
    int secondHeading_;
};
struct Fields020407b4;
extern "C" void func_02032fdc(HeightShiftedObject*, int, int);
void StoreVec3AtField0x50(unsigned char*, int, int, int);
extern "C" void _Z41SetupObjFieldsAndResetRenderFlags020ae20cPvP14Fields020407b4Pii(void*, Fields020407b4*, int*, int);

// USA: func_020ae074
extern "C" ARM void func_020ae074(HeightShiftedObject* self) {
    GameState* game = GameState::GetInstance();
    Vector3fix position = self->position_;
    position.y += self->heightOffset_;
    self->position_ = position;
    func_02032fdc(self, 1, 0);
    GameObject* object = game->GetGameObjectByIndex(0xcb);
    if (object) {
        self->firstPosition_.y += self->heightOffset_;
        object->obj3D_.position_ = self->firstPosition_;
        StoreVec3AtField0x50((unsigned char*)object, 0, self->firstHeading_, 0);
        object->obj3D_.Draw(true);
        self->firstPosition_.y -= self->heightOffset_;
        self->secondPosition_.y += self->heightOffset_;
        object->obj3D_.position_ = self->secondPosition_;
        StoreVec3AtField0x50((unsigned char*)object, 0, self->secondHeading_, 0);
        object->obj3D_.Draw(true);
        self->secondPosition_.y -= self->heightOffset_;
    }
    GameObject* shadow = game->GetGameObjectByIndex(0xcc);
    Vector3fix shadowPosition = self->position_;
    _Z41SetupObjFieldsAndResetRenderFlags020ae20cPvP14Fields020407b4Pii(self, (Fields020407b4*)shadow, &shadowPosition.x, self->heading_);
    GameObject* secondary = game->GetGameObjectByIndex(0xcd);
    _Z41SetupObjFieldsAndResetRenderFlags020ae20cPvP14Fields020407b4Pii(self, (Fields020407b4*)secondary, &self->firstPosition_.x, self->firstHeading_);
    _Z41SetupObjFieldsAndResetRenderFlags020ae20cPvP14Fields020407b4Pii(self, (Fields020407b4*)secondary, &self->secondPosition_.x, self->secondHeading_);
    position = self->position_;
    position.y -= self->heightOffset_;
    self->position_ = position;
}
