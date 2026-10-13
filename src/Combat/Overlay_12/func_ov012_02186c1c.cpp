#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct Struct0205de24 {
    char padding0[0x98];
    void* sourceEntries;
    void* targetEntries;
    char paddingA0[0x12];
    unsigned char entryCount;
    unsigned char paddingB3;
    unsigned char activeEntry;
};
struct Struct_0205c570;
struct EntryA68 { short key; void* value; };
struct TableA68 { EntryA68* entries; short count; };
struct Obj0205eaa0;
struct Obj021e6e20;
struct ProfileTitle {
    char padding0[4];
    unsigned int unknown4 : 9;
    int title : 10;
    unsigned int unknownUpper : 13;
};
struct ProfileRegion {
    char padding[0x569c];
    ProfileTitle profile;
};
struct ProfileEditor {
    char padding0[0xac];
    Struct0205de24 entries;
    char padding164[0x133c - 0x164];
    TableA68 strings;
    char padding1344[0x1370 - 0x1344];
    unsigned char step;
    unsigned char state;
    char padding1372[0x13a0 - 0x1372];
    unsigned char active;
    char padding13a1[0x13c4 - 0x13a1];
    unsigned short availableCount : 5;
    unsigned short unknown13c4 : 11;
    char padding13c6[0x13d8 - 0x13c6];
    int cursor;
    char padding13dc[0x1440 - 0x13dc];
    char titleText[0x40];
};

static inline ProfileTitle* GetTitleProfile(GameState* game) {
    ProfileRegion* region = (ProfileRegion*)game;
    return &region->profile;
}
extern "C" void _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh(Struct0205de24*, unsigned char, unsigned char);
extern "C" int _Z26GetActiveScaledSum0205d794P15Struct_0205c570(Struct_0205c570*);
extern "C" void _Z22BuildMessageB_021898bcPc(char*);
void* FindEntryByKey(TableA68*, int);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(Obj0205eaa0*, int, int);
extern "C" int _Z35TestFlagsAndActiveElement2_021e6e20P11Obj021e6e20(Obj021e6e20*);
extern Obj0205eaa0 data_02108760;
extern "C" void func_ov023_021e6e60(ProfileEditor*);
extern "C" int func_ov023_021e6de4(ProfileEditor*);
extern "C" void func_ov012_0218adac(ProfileEditor*, int, int, int);
extern "C" void func_ov012_0218930c(ProfileEditor*, int);

// USA: func_ov012_02186c1c
extern "C" ARM void func_ov012_02186c1c(ProfileEditor* self) {
    if (self->step == 0) {
        self->active = 0;
        int title = GetTitleProfile(GameState::GetInstance())->title;
        int cursor;
        if (title < 100) cursor = 2;
        else if (title < 200) cursor = 0;
        else if (title == 300) cursor = 3;
        else if (title < 300) cursor = 1;
        else {
            cursor = 0;
            switch (title) {
            case 310:
                cursor = 0;
                break;
            }
        }
        self->cursor = cursor;
        _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh(&self->entries, 0, 3);
        func_ov023_021e6e60(self);
        _Z22BuildMessageB_021898bcPc((char*)self);
        self->step++;
        return;
    }
    if (self->step != 1) return;
    self->active = 1;
    self->cursor = _Z26GetActiveScaledSum0205d794P15Struct_0205c570((Struct_0205c570*)&self->entries);
    if (func_ov023_021e6de4(self)) {
        int rebuild = 1;
        switch (self->cursor) {
        case 0:
            self->state = 3;
            self->step = 0;
            break;
        case 1:
            self->state = 4;
            self->step = 0;
            break;
        case 2:
            if (self->availableCount) {
                self->state = 5;
                self->step = 0;
            } else rebuild = 0;
            break;
        case 3: {
            GameState* game = GameState::GetInstance();
            const char* text = (const char*)FindEntryByKey(&self->strings, 0x6d);
            GetTitleProfile(game)->title = 300;
            memset(self->titleText, 0, sizeof(self->titleText));
            int length = strlen(text);
            memcpy(self->titleText, text, length);
            func_ov012_0218adac(self, 0, -1, 0);
            func_ov012_0218930c(self, rebuild);
            break;
        }
        }
        if (!rebuild) return;
        _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, 1, 0);
    } else {
        if (!_Z35TestFlagsAndActiveElement2_021e6e20P11Obj021e6e20((Obj021e6e20*)self)) return;
        func_ov012_0218930c(self, 1);
    }
}
