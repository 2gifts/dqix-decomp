#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct ProfileTitle02186c1c {
    unsigned int header;
    unsigned int age : 9;
    int title : 10;
    unsigned int upper : 13;
};
struct AvailableTitles02186c1c {
    unsigned short count : 5;
    unsigned short other : 11;
};
struct Struct0205de24;
struct Struct_0205c570;
struct TableA68;
struct Obj0205eaa0;
struct Obj021e6e20;
void FindAndLinkMatchingEntry0205de24(Struct0205de24*, unsigned char, unsigned char);
int GetActiveScaledSum0205d794(Struct_0205c570*);
void BuildMessageB_021898bc(char*);
void* FindEntryByKey(TableA68*, int);
void DispatchWithShortB4_0205eaa0(Obj0205eaa0*, int, int);
int TestFlagsAndActiveElement2_021e6e20(Obj021e6e20*);
extern Obj0205eaa0 data_02108760;
extern "C" void func_ov023_021e6e60(void*);
extern "C" int func_ov023_021e7148(void*);
extern "C" void func_ov012_0218bba0(void*, int, int);
extern "C" void func_ov012_02189be8(void*, int);

static inline ProfileTitle02186c1c* GetTitleProfile02186c1c(GameState* game) {
    return (ProfileTitle02186c1c*)((char*)game + 0x543c);
}

// USA: func_ov012_02186c1c
// JPN: func_ov012_02187350
extern "C" ARM void func_ov012_02186c1c(char* editor) {
    if (*(unsigned char*)(editor + 0x1340) == 0) {
        *(unsigned char*)(editor + 0x1368) = 0;
        int title = GetTitleProfile02186c1c(GameState::GetInstance())->title;
        int cursor;
        if (title < 100) cursor = 2;
        else if (title < 200) cursor = 0;
        else if (title < 300) cursor = 1;
        else if (title == 300) cursor = 3;
        else cursor = 0;
        *(int*)(editor + 0x1430) = cursor;
        FindAndLinkMatchingEntry0205de24((Struct0205de24*)(editor + 0x90), 0, 3);
        func_ov023_021e6e60(editor);
        BuildMessageB_021898bc(editor);
        (*(unsigned char*)(editor + 0x1340))++;
        return;
    }
    if (*(unsigned char*)(editor + 0x1340) != 1) return;
    *(unsigned char*)(editor + 0x1368) = 1;
    *(int*)(editor + 0x1430) = GetActiveScaledSum0205d794((Struct_0205c570*)(editor + 0x90));
    if (func_ov023_021e7148(editor)) {
        int rebuild = 1;
        switch (*(int*)(editor + 0x1430)) {
        case 0:
            *(unsigned char*)(editor + 0x1341) = 3;
            *(unsigned char*)(editor + 0x1340) = 0;
            break;
        case 1:
            *(unsigned char*)(editor + 0x1341) = 4;
            *(unsigned char*)(editor + 0x1340) = 0;
            break;
        case 2:
            if (((AvailableTitles02186c1c*)(editor + 0x141c))->count) {
                *(unsigned char*)(editor + 0x1341) = 5;
                *(unsigned char*)(editor + 0x1340) = 0;
            } else rebuild = 0;
            break;
        case 3: {
            GameState* game = GameState::GetInstance();
            const char* text = (const char*)FindEntryByKey((TableA68*)(editor + 0x1314), 109);
            GetTitleProfile02186c1c(game)->title = 300;
            memset(editor + 0x1498, 0, 64);
            memcpy(editor + 0x1498, text, strlen(text));
            func_ov012_0218bba0(editor, 0, -1);
            func_ov012_02189be8(editor, rebuild);
            break;
        }
        }
        if (!rebuild) return;
        DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
    } else {
        if (!TestFlagsAndActiveElement2_021e6e20((Obj021e6e20*)editor)) return;
        func_ov012_02189be8(editor, 1);
    }
}
#else
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
#endif
