#include <globaldefs.h>
#include "GameState/GameState.h"

struct Vec3_020406f8 { int x, y, z; };
struct Vec3copy0202ec84 { int x, y, z; };
struct Node020406f8;
struct S02040538;

struct EntryList_203dce4;
struct Vec3Target0203a46c;
struct ChainRoot;
struct LookupBase;
struct InteractionSelection { unsigned char kind, index; unsigned short id; };
#if defined(jpn)
enum { SpriteOffset = 0x2980 };
#define data_ov017_021d64f4 data_ov017_021d6944
#else
enum { SpriteOffset = 0x2b90 };
#endif
typedef void (GameResources::*FocusAction0219aa7c)();
struct FocusActions0219aa7c { FocusAction0219aa7c entries[15]; };
extern const FocusActions0219aa7c data_ov017_021d64f4;
extern const FocusAction0219aa7c data_020e6d5c;
extern unsigned char data_02114e54[];
extern unsigned short data_02114e30[];
void* GetField0x3b0Value(GameState*);
int CheckSubstructByte0x7cPositive(signed char*);
EntryList_203dce4* GetGlobalPtr021075f4();
Node020406f8* GetEntryUnlessFlag0x8000(EntryList_203dce4*, int);
void SelectVec3FromSources020406f8(Vec3_020406f8*, Node020406f8*);
void* GetField0xc02040538(S02040538*);
void ComputeTwoFromVec3_0202ec84(void*, Vec3copy0202ec84*, int*, int*);
void SetVec3At0x1c(Vec3Target0203a46c*, int, int, int);
int IsField0Null(void**);
int GetChainedTableByte(ChainRoot*);
unsigned char GetLinkedFlagByte(LookupBase*);
int TestFlag0SetAndFlag1Clear(unsigned short*, int);
extern "C" void __clear(void*, unsigned int);

// USA: func_ov017_0219aa7c
extern "C" ARM void func_ov017_0219aa7c(GameResources* self) {
    GameState* game = GameState::GetInstance();
    void* camera = GetField0x3b0Value(game);
    GameObject* object = game->GetUnknownGameObject();
    if (object == 0 || CheckSubstructByte0x7cPositive((signed char*)object) || ((InteractionSelection*)self->interactionSelection)->index == 18) return;
    Foo02048004* sprite = reinterpret_cast<Foo02048004*>(reinterpret_cast<char*>(self) + SpriteOffset + ((InteractionSelection*)self->interactionSelection)->index * sizeof(Foo02048004));
    Vector3fix position;
    __clear(&position, 12);
    int x = 0;
    int y = 0;
    self->unknown_42e3[3] = 0;
    int fallback = 1;
    if (((InteractionSelection*)self->interactionSelection)->kind == 0) {
        Node020406f8* node = GetEntryUnlessFlag0x8000(GetGlobalPtr021075f4(), ((InteractionSelection*)self->interactionSelection)->id);
        if (node != 0) {
            Vec3_020406f8 source;
            SelectVec3FromSources020406f8(&source, node);
            position = *(Vector3fix*)&source;
            position.y += 0x1800;
            void* height = GetField0xc02040538((S02040538*)node);
            if (height != 0) position.y += *reinterpret_cast<int*>(static_cast<char*>(height) + 0x60);
            fallback = 0;
        }
    } else if (((InteractionSelection*)self->interactionSelection)->kind == 10 || ((InteractionSelection*)self->interactionSelection)->kind == 13) {
        GameObject* member = game->GetPartyMemberByIndex(((InteractionSelection*)self->interactionSelection)->id);
        if (member != 0) {
            position = member->obj3D_.position_;
            position.y += 0x1800;
            fallback = 0;
        }
    } else if (((InteractionSelection*)self->interactionSelection)->kind == 9) {
        GameObject* member = game->GetMaybeFieldMonsterByIndex(((InteractionSelection*)self->interactionSelection)->id);
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
    ComputeTwoFromVec3_0202ec84(camera, (Vec3copy0202ec84*)&position, &x, &y);
    x -= 12;
    y -= 24;
    SetVec3At0x1c((Vec3Target0203a46c*)sprite, x << 12, y << 12, 0);
    if (!IsField0Null(static_cast<void**>(self->unknown_ptr_array_36fc[0]))) return;
    int dispatch = 0;
    if (data_02114e54[0x54] && *reinterpret_cast<unsigned int*>(data_02114e54 + 0x44) < 10) {
        int width = GetChainedTableByte((ChainRoot*)sprite);
        int height = GetLinkedFlagByte((LookupBase*)sprite);
        int limit_x = *reinterpret_cast<int*>(data_02114e54 + 0x38);
        int limit_y = *reinterpret_cast<int*>(data_02114e54 + 0x3c);
        if (x < limit_x && y < limit_y && limit_x < x + width && limit_y < y + height) dispatch = 1;
    }
    if (TestFlag0SetAndFlag1Clear(data_02114e30, 1)) dispatch = 1;
    if (dispatch) {
        FocusActions0219aa7c actions = data_ov017_021d64f4;
        actions.entries[3] = data_020e6d5c;
        if (actions.entries[((InteractionSelection*)self->interactionSelection)->kind] != 0) {
            (self->*actions.entries[((InteractionSelection*)self->interactionSelection)->kind])();
            self->unknown_42e3[1] = 0;
        }
    }
}
