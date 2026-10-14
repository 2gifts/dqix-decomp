#include <globaldefs.h>

#if defined(jpn)
enum { kInitialPad = 0x868, kIndexGap = 0x7e, kEnabledGap = 0x5c };
#else
enum { kInitialPad = 0x998, kIndexGap = 0x120, kEnabledGap = 0x5a };
#endif

#include <GameState/GameState.h>
#include <Combat/EntryGetterTypes.h>

struct EntryList_203dce4;
struct Node020406f8;
struct StructAt020473c8;
struct Vec3_020406f8 { unsigned int v[3]; };
struct Vec3copy0202ec84 { unsigned int v[3]; };
union VectorBuffer020675fc {
    Vec3_020406f8 selected;
    Vec3copy0202ec84 copied;
};
struct Owner020675fc {
    unsigned char padding[kInitialPad];
    int active;
    unsigned char padding_0x99c[0xe9c];
    int entryId;
    unsigned char padding_0x183c[kIndexGap];
    unsigned char index;
    unsigned char padding_0x195d[kEnabledGap];
    unsigned char enabled;
};
EntryList_203dce4* GetGlobalPtr021075f4_0203cf4c();
Entry_203dce4* GetEntryUnlessFlag0x8000_0203dce4(EntryList_203dce4*, int);
void* GetField0x3b0Value_020100bc(GameState*);
void SelectVec3FromSources020406f8(Vec3_020406f8*, Node020406f8*);
int ComputeTwoFromVec3_0202ec84(void*, Vec3copy0202ec84*, int*, int*);
void RenderFlaggedIndexedEntry(StructAt020473c8*, int);
extern unsigned char data_020e7e08[];

// USA: func_020675fc
extern "C" ARM void func_020675fc(Owner020675fc* owner) {
    if (!owner->active) return;
    Entry_203dce4* entry = GetEntryUnlessFlag0x8000_0203dce4(GetGlobalPtr021075f4_0203cf4c(), owner->entryId);
    if (entry && owner->enabled) {
        GameResources* resources = func_ov017_0218b5b0();
        void* view = GetField0x3b0Value_020100bc(GameState::GetInstance());
        int x;
        int y;
        Vec3copy0202ec84 copied;
        VectorBuffer020675fc vector;
        SelectVec3FromSources020406f8(&vector.selected, (Node020406f8*)entry);
        copied = vector.copied;
        ComputeTwoFromVec3_0202ec84(view, &copied, &x, &y);
        x -= 12;
        y -= 62;
        int scaledX = x << 12;
        Foo02048004* output = &resources->substruct_array_2b90[data_020e7e08[owner->index]];
        int scaledY = y << 12;
        output->words1c[0] = scaledX;
        output->words1c[1] = scaledY;
        output->words1c[2] = 0;
        RenderFlaggedIndexedEntry((StructAt020473c8*)output, 1);
    }
}
