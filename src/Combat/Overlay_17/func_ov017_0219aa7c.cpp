#include <globaldefs.h>
#include "GameState/GameState.h"

struct Vec3_020406f8 { int x, y, z; };
struct Vec3copy0202ec84 { int x, y, z; };
struct Node020406f8;
struct S02040538;
struct NodeHeight0219aa7c { unsigned char padding_0[0x60]; int height; };
struct EntryList_203dce4;
struct Vec3Target0203a46c;
struct ChainRoot;
struct LookupBase;
struct FocusSprite0219aa7c { unsigned char fields[0x88]; };
struct FocusState0219aa7c {
    unsigned char padding_0[0x2b90];
    FocusSprite0219aa7c sprites[20];
    unsigned char padding_3630[0x36b4 - 0x3630];
    unsigned char kind;
    unsigned char index;
    unsigned short id;
    unsigned char padding_36b8[0x36fc - 0x36b8];
    void** list;
    unsigned char padding_3700[0x42e4 - 0x3700];
    unsigned char field_42e4;
    unsigned char padding_42e5;
    unsigned char field_42e6;
};
typedef void (FocusState0219aa7c::*FocusAction0219aa7c)();
struct FocusActions0219aa7c { FocusAction0219aa7c entries[15]; };
extern const FocusActions0219aa7c data_ov017_021d64f4;
extern const FocusAction0219aa7c data_020e6d5c;
struct FocusBounds0219aa7c {
    unsigned char padding_0[0x38];
    int x;
    int y;
    unsigned char padding_40[4];
    unsigned int index;
    unsigned char padding_48[12];
    unsigned char enabled;
};
extern FocusBounds0219aa7c data_02114e54;
extern unsigned short data_02114e30[];
void* GetField0x3b0Value(GameState*);
int CheckSubstructByte0x7cPositive(signed char*);
EntryList_203dce4* GetGlobalPtr021075f4();
Node020406f8* GetEntryUnlessFlag0x8000(EntryList_203dce4*, int);
extern "C" void _Z29SelectVec3FromSources020406f8P13Vec3_020406f8P12Node020406f8(Vec3_020406f8*, Node020406f8*);
extern "C" NodeHeight0219aa7c* _Z19GetField0xc02040538P9S02040538(S02040538*);
extern "C" void _Z27ComputeTwoFromVec3_0202ec84PvP16Vec3copy0202ec84PiS2_(void*, Vec3copy0202ec84*, int*, int*);
void SetVec3At0x1c(Vec3Target0203a46c*, int, int, int);
int IsField0Null(void**);
int GetChainedTableByte(ChainRoot*);
int GetLinkedFlagByte(LookupBase*);
int TestFlag0SetAndFlag1Clear(unsigned short*, int);
extern "C" void __clear(void*, unsigned int);

// USA: func_ov017_0219aa7c
extern "C" ARM void func_ov017_0219aa7c(FocusState0219aa7c* self) {
    GameState* game = GameState::GetInstance();
    void* camera = GetField0x3b0Value(game);
    GameObject* object = game->GetUnknownGameObject();
    if (object == 0 || CheckSubstructByte0x7cPositive((signed char*)object) || self->index == 18) return;
    FocusSprite0219aa7c* sprite = &self->sprites[self->index];
    Vector3fix position;
    __clear(&position, 12);
    int x = 0;
    int y = 0;
    self->field_42e6 = 0;
    int fallback = 1;
    if (self->kind == 0) {
        Node020406f8* node = GetEntryUnlessFlag0x8000(GetGlobalPtr021075f4(), self->id);
        if (node != 0) {
            Vec3_020406f8 source;
            _Z29SelectVec3FromSources020406f8P13Vec3_020406f8P12Node020406f8(&source, node);
            position = *(Vector3fix*)&source;
            position.y += 0x1800;
            NodeHeight0219aa7c* height = _Z19GetField0xc02040538P9S02040538((S02040538*)node);
            if (height != 0) position.y += height->height;
            fallback = 0;
        }
    } else if (self->kind == 10 || self->kind == 13) {
        GameObject* member = game->GetPartyMemberByIndex(self->id);
        if (member != 0) {
            position = member->obj3D_.position_;
            position.y += 0x1800;
            fallback = 0;
        }
    } else if (self->kind == 9) {
        GameObject* member = game->GetMaybeFieldMonsterByIndex(self->id);
        if (member != 0) {
            position = member->obj3D_.position_;
            position.y += member->obj3D_.GetHeight();
            fallback = 0;
        }
    }
    if (fallback) {
        position = object->obj3D_.position_;
        position.y += object->obj3D_.GetHeight();
    }
    _Z27ComputeTwoFromVec3_0202ec84PvP16Vec3copy0202ec84PiS2_(camera, (Vec3copy0202ec84*)&position, &x, &y);
    x -= 12;
    y -= 24;
    SetVec3At0x1c((Vec3Target0203a46c*)sprite, x << 12, y << 12, 0);
    if (!IsField0Null(self->list)) return;
    int dispatch = 0;
    if (data_02114e54.enabled && data_02114e54.index < 10) {
        int width = GetChainedTableByte((ChainRoot*)sprite);
        int height = GetLinkedFlagByte((LookupBase*)sprite);
        int limit_x = data_02114e54.x;
        int limit_y = data_02114e54.y;
        if (x < limit_x && y < limit_y && limit_x < x + width && limit_y < y + height) dispatch = 1;
    }
    if (TestFlag0SetAndFlag1Clear(data_02114e30, 1)) dispatch = 1;
    if (dispatch) {
        FocusActions0219aa7c actions = data_ov017_021d64f4;
        actions.entries[3] = data_020e6d5c;
        if (actions.entries[self->kind] != 0) {
            (self->*actions.entries[self->kind])();
            self->field_42e4 = 0;
        }
    }
}
