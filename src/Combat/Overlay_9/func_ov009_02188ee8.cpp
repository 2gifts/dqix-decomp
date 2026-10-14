#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/CharacterCreationUI.h"

struct Struct_0205bef8;
struct Struct_0205ba68;
struct Struct_0205bb84;
struct Node0205bacc;
struct Obj0205eaa0;
void Init0205bef8(Struct_0205bef8*);
void SetupPointerTable0205ba68(Struct_0205ba68*, int, int, int);
void SetField0AndPropagate0205bacc(Node0205bacc*, int);
int GetField0_0205bafc(void*);
int ComputeScaledSum0205bb84(Struct_0205bb84*);
void DispatchWithShortB4_0205eaa0(Obj0205eaa0*, int, int);
void SelectCoordsByFlag0x24(unsigned char*, int*, int*);
int TestFlag0SetAndFlag1Clear(unsigned short*, int);
int GetFieldByKey020e0434(Container020e0310*, int);
extern "C" int func_02001aec(const void*, const void*, unsigned int);
extern "C" int func_ov009_0218a8b4(CharacterCreationUI*, int, int);
extern "C" int func_ov009_0218aab0(CharacterCreationUI*, unsigned char);
extern "C" void func_ov009_0218ad0c(void*);
extern "C" void func_ov009_0218b200(CharacterCreationUI*, int);
extern "C" void func_ov009_0218b850(CharacterCreationUI*);
extern "C" void func_0205bb04(CreationNavigation*, int);
extern "C" int func_0205bf58(CreationNavigation*, unsigned int);
extern "C" void func_ov009_02188c2c(CharacterCreationUI*);
extern "C" void func_ov009_02188e70(CharacterCreationUI*, int);
extern "C" void func_ov009_02188944(CharacterCreationUI*, int);
extern "C" int func_ov009_02188b14(CharacterCreationUI*, int, int);

struct TouchState {
    char unknown0[0x24];
    unsigned short pressure;
    char unknown26[0x2e];
    unsigned char repeating, pressed;
    char unknown56[9];
    unsigned char held;
};
struct PartyMemberAppearance {
    short models[10];
    unsigned char female : 1;
    unsigned char eyeColor : 3;
    unsigned char skinColor : 4;
    unsigned char hairColor : 4;
    unsigned char unused : 4;
    short field16, width, height;
};
struct PartyMemberData { char unknown0[0x488]; PartyMemberAppearance appearance; };
extern TouchState data_02114e54;
extern Obj0205eaa0 data_02108760;
extern unsigned short data_02114e30;

#define RESET_NAVIGATION(columns, rows, total, selected) \
    CreationNavigation* navigation = &self->navigation; \
    Init0205bef8((Struct_0205bef8*)navigation); \
    SetupPointerTable0205ba68((Struct_0205ba68*)navigation, columns, rows, 1); \
    SetField0AndPropagate0205bacc((Node0205bacc*)navigation, total); \
    navigation->field4 = 1; \
    func_0205bb04(navigation, selected); \
    navigation->flags3d = 0

#define TAB_CURSOR(selected) \
    self->cursorX = ((selected) << 4) + 0x78; \
    self->cursorY = 8; \
    self->cursorWidth = 16; \
    self->cursorHeight = 16

static inline unsigned char GetEyeColor(CharacterCreationUI* self) { return self->eyeColor[self->sex]; }
static inline unsigned char GetSkinColor(CharacterCreationUI* self) { return self->skinColor[self->sex]; }
static inline unsigned char GetHairColor(CharacterCreationUI* self) { return self->hairColor[self->sex]; }

extern "C" ARM int func_ov009_02188ee8(CharacterCreationUI* self)
{
    self->flags &= ~0x20;
    self->flags &= ~0x40;
    int result = -1;
    int choice = -1;
    int x, y;
    SelectCoordsByFlag0x24((unsigned char*)&data_02114e54, &x, &y);
    int touched = 0;
    if (data_02114e54.pressed) {
        touched = 1;
        choice = func_ov009_0218a8b4(self, x, y);
        self->touchedChoice = choice;
        if ((unsigned int)(choice + 3) <= 1) {
            if (choice == -2) self->flags |= 0x20;
            else if (choice == -3) self->flags |= 0x40;
            result = choice;
            DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
        } else if (choice >= 101 && choice <= 108) {
            result = choice;
            if (choice - 100 <= self->furthestState[self->sex] && choice - 100 != self->state)
                DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
        } else if (choice >= 0) {
            func_0205bb04(&self->navigation, choice);
            if (self->state == 8) {
                func_ov009_0218aab0(self, (unsigned char)choice);
                if (self->flags & 0x200000) {
                    self->flags &= ~0x200000;
                    result = -2;
                }
                self->flags |= 0x100;
            }
            self->lastCursorX = self->cursorX;
            self->lastCursorY = self->cursorY;
        }
    } else if (data_02114e54.held && data_02114e54.pressure) touched = 1;
    else if (data_02114e54.repeating) touched = 1;
    if (!touched) {
        unsigned int ticks = GameState::GetInstance()->GetTickCount();
        if (!ticks) ticks = 1;
        int previous = self->navigation.row;
        if (func_0205bf58(&self->navigation, ticks))
            choice = ComputeScaledSum0205bb84((Struct_0205bb84*)&self->navigation);
        if (self->state == 8) {
            int rows = self->navigation.rows;
            int count = GetField0_0205bafc(&self->navigation);
            if (rows == 1 && count == 8) {
                if (choice >= self->furthestState[self->sex]) {
                    func_0205bb04(&self->navigation, self->furthestState[self->sex] - 1);
                    choice = self->furthestState[self->sex] - 1;
                }
                if (TestFlag0SetAndFlag1Clear(&data_02114e30, 0x80)) {
                    RESET_NAVIGATION(11, 6, 66, self->keyboardChoice);
                    func_0205bb04(&self->navigation, self->navigation.column);
                    self->keyboardChoice = ComputeScaledSum0205bb84((Struct_0205bb84*)&self->navigation);
                    self->flags |= 0x2000;
                    func_ov009_02188e70(self, ComputeScaledSum0205bb84((Struct_0205bb84*)&self->navigation));
                    return -1;
                }
                if (choice >= 0) { TAB_CURSOR(choice); }
                if (TestFlag0SetAndFlag1Clear(&data_02114e30, 1)) {
                    result = ComputeScaledSum0205bb84((Struct_0205bb84*)&self->navigation) + 101;
                    if (result - 100 <= self->furthestState[self->sex] && result - 100 != self->state)
                        DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
                } else if (TestFlag0SetAndFlag1Clear(&data_02114e30, 2)) {
                    if (func_02001aec(self->names[self->sex], (const void*)GetFieldByKey020e0434(&self->texts, 0x4272), 10) == 0)
                        result = -3;
                    else {
                        func_ov009_0218b200(self, 0);
                        self->flags |= 0x8100;
                    }
                }
                return result;
            } else if (rows == 6) {
                if (TestFlag0SetAndFlag1Clear(&data_02114e30, 0x40) && previous == 0) {
                    RESET_NAVIGATION(8, 1, 8, self->state - 1);
                    navigation->flags3c = 0;
                    TAB_CURSOR(self->state - 1);
                    self->flags |= 0x2000;
                    return -1;
                }
                if (TestFlag0SetAndFlag1Clear(&data_02114e30, 8)) {
                    func_ov009_0218ad0c(self);
                } else if (TestFlag0SetAndFlag1Clear(&data_02114e30, 4)) {
                    func_ov009_0218b850(self);
                    self->flags |= 0x8100;
                } else if (TestFlag0SetAndFlag1Clear(&data_02114e30, 1)) {
                    if (func_ov009_0218aab0(self, self->keyboardChoice) && self->nameFlags[self->sex] == 5) {
                        choice = 65;
                        func_0205bb04(&self->navigation, choice);
                    }
                    if (!(self->flags & 0x200000)) self->flags |= 0xa100;
                    else {
                        func_ov009_0218ad0c(self);
                        self->flags &= ~0x200000;
                    }
                } else if (TestFlag0SetAndFlag1Clear(&data_02114e30, 2)) {
                    if (func_02001aec(self->names[self->sex], (const void*)GetFieldByKey020e0434(&self->texts, 0x4272), 10) == 0)
                        result = -3;
                    else {
                        func_ov009_0218b200(self, 0);
                        self->flags |= 0x8100;
                    }
                }
            }
        } else if (self->state != 8) {
            int rows = self->navigation.rows;
            int count = GetField0_0205bafc(&self->navigation);
            if (rows == 1 && count == 8) {
                if (choice >= self->furthestState[self->sex]) {
                    func_0205bb04(&self->navigation, self->furthestState[self->sex] - 1);
                    choice = self->furthestState[self->sex] - 1;
                }
                if (TestFlag0SetAndFlag1Clear(&data_02114e30, 0x80)) {
                    func_ov009_02188c2c(self);
                    self->flags |= 0x2000;
                    func_ov009_02188e70(self, ComputeScaledSum0205bb84((Struct_0205bb84*)&self->navigation));
                    return -1;
                }
                if (choice >= 0) { TAB_CURSOR(choice); }
                if (TestFlag0SetAndFlag1Clear(&data_02114e30, 1)) {
                    result = ComputeScaledSum0205bb84((Struct_0205bb84*)&self->navigation) + 101;
                    if (result - 100 <= self->furthestState[self->sex] && result - 100 != self->state)
                        DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
                } else if (TestFlag0SetAndFlag1Clear(&data_02114e30, 2)) result = -3;
                return result;
            }
            if (TestFlag0SetAndFlag1Clear(&data_02114e30, 0x40) && previous == 0) {
                RESET_NAVIGATION(8, 1, 8, self->state - 1);
                navigation->flags3c = 0;
                TAB_CURSOR(self->state - 1);
                self->flags |= 0x2000;
                return -1;
            }
            if (TestFlag0SetAndFlag1Clear(&data_02114e30, 1)) {
                result = -2;
                DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
            } else if (TestFlag0SetAndFlag1Clear(&data_02114e30, 2)) result = -3;
        }
    }
    self->flags &= ~0x10;
    if (choice >= 0 && !(choice >= 101 && choice <= 108)) {
        switch (self->state) {
        case 1: if (self->sex != choice) self->flags |= 0x10; self->sex = choice; break;
        case 2: if (self->bodyType[self->sex] != choice) self->flags |= 0x10; self->bodyType[self->sex] = choice; break;
        case 3: if (self->hairStyle[self->sex] != choice) self->flags |= 0x10; self->hairStyle[self->sex] = choice; break;
        case 4: if (self->hairColor[self->sex] != choice) self->flags |= 0x10; self->hairColor[self->sex] = choice; break;
        case 5: if (self->faceStyle[self->sex] != choice) self->flags |= 0x10; self->faceStyle[self->sex] = choice; break;
        case 6: if (self->eyeColor[self->sex] != choice) self->flags |= 0x10; self->eyeColor[self->sex] = choice; break;
        case 7: if (self->skinColor[self->sex] != choice) self->flags |= 0x10; self->skinColor[self->sex] = choice; break;
        case 8: if (self->keyboardChoice != choice) self->flags |= 0x10; self->keyboardChoice = choice; break;
        }
    }
    if (self->flags & 0x10) {
        if (self->state != 8 || !touched) DispatchWithShortB4_0205eaa0(&data_02108760, 2, 0);
        func_ov009_02188944(self, choice);
        if (self->state == 1) {
            PartyMemberAppearance* appearance = &((PartyMemberData*)self->characterData)->appearance;
            self->flags |= 0x60000;
            unsigned char eyeColor = GetEyeColor(self);
            appearance->eyeColor = eyeColor;
            unsigned char skinColor = GetSkinColor(self);
            appearance->skinColor = skinColor;
            unsigned char hairColor = GetHairColor(self);
            appearance->hairColor = hairColor;
            appearance->models[2] = func_ov009_02188b14(self, 5, self->faceStyle[self->sex]) + 0x233c;
            appearance->models[3] = func_ov009_02188b14(self, 3, self->hairStyle[self->sex]) + 0x2328;
        }
        if (!touched) func_ov009_02188e70(self, choice);
        self->flags |= 0x6100;
    }
    return result;
}
#undef RESET_NAVIGATION
#undef TAB_CURSOR

#else
#include <globaldefs.h>
#include <GameState/GameState.h>

struct Struct_0205bef8;
struct Struct_0205ba68;
struct Struct_0205bb84;
struct Node0205bacc;
struct Obj0205eaa0;
void Init0205bef8(Struct_0205bef8*);
void SetupPointerTable0205ba68(Struct_0205ba68*, int, int, int);
void SetField0AndPropagate0205bacc(Node0205bacc*, int);
int GetField0_0205bafc(void*);
int ComputeScaledSum0205bb84(Struct_0205bb84*);
void DispatchWithShortB4_0205eaa0(Obj0205eaa0*, int, int);
void SelectCoordsByFlag0x24(unsigned char*, int*, int*);
int TestFlag0SetAndFlag1Clear(unsigned short*, int);

struct TouchState {
    char pad0[0x24];
    unsigned short pressure;
    char pad26[0x2e];
    unsigned char repeating;
    unsigned char pressed;
    char pad56[9];
    unsigned char held;
};
struct Navigation {
    int field0, field4, field8, rows, field10, field14, field18, selection;
    char pad20[0x18];
    unsigned short count;
    char pad3a[2];
    unsigned char field3c, field3d;
    char pad3e[2];
};
struct ChoiceList { void* entries; char pad4[0x14]; int selection; unsigned short counter; };
struct PartyMemberAppearance {
    short models[10];
    unsigned char female : 1;
    unsigned char eyeColor : 3;
    unsigned char skinColor : 4;
    unsigned char hairColor : 4;
    unsigned char unused : 4;
    short field16, width, height;
};
struct PartyMemberData { char pad0[0x488]; PartyMemberAppearance appearance; };
struct CharacterControls { char pad0[0x800]; Navigation navigation; };
struct CharacterCreation {
    char pad0[0xbc];
    void* savedEntries;
    ChoiceList* list;
    char padc4[0x3ec - 0xc4];
    CharacterControls controls;
    char grid[0x20];
    short cursorX, cursorY, cursorWidth, cursorHeight, lastX, lastY;
    signed char state;
    char padc59[0xd88 - 0xc59];
    PartyMemberData* member;
    int touchedChoice;
    char padd90[0xc];
    unsigned int flags;
    signed char maxSteps[3];
    unsigned char gender;
    unsigned char body[2], face[2], skin[2], eyes[2], hair[2], hairColor[2];
    char paddb0[5];
    unsigned char blocked;
};
extern TouchState data_02114e54;
extern Obj0205eaa0 data_02108760;
extern unsigned short data_02114e30;
extern "C" int func_ov009_02189854(CharacterCreation*, int, int);
extern "C" void func_0205bb04(Navigation*, int);
extern "C" int func_0205bf58(Navigation*, unsigned int);
extern "C" void func_ov009_02188c2c(CharacterCreation*);
extern "C" void func_ov009_02188e70(CharacterCreation*, int);
extern "C" void func_ov009_02188944(CharacterCreation*, int);
extern "C" int func_ov009_02188b14(CharacterCreation*, int, int);

#define RESET_NAVIGATION(columns, rows, total, selected) \
    CharacterControls* controls = &self->controls; \
    Init0205bef8((Struct_0205bef8*)&controls->navigation); \
    SetupPointerTable0205ba68((Struct_0205ba68*)&controls->navigation, columns, rows, 1); \
    SetField0AndPropagate0205bacc((Node0205bacc*)&controls->navigation, total); \
    controls->navigation.field4 = 1; \
    func_0205bb04(&controls->navigation, selected); \
    controls->navigation.field3d = 0

#define TAB_CURSOR(selected) \
    self->cursorX = ((selected) << 4) + 0x78; \
    self->cursorY = 8; \
    self->cursorWidth = 16; \
    self->cursorHeight = 16

static inline unsigned char GetEyeColor(CharacterCreation* self) { return self->eyes[self->gender]; }
static inline unsigned char GetSkinColor(CharacterCreation* self) { return self->skin[self->gender]; }
static inline unsigned char GetHairColor(CharacterCreation* self) { return self->hairColor[self->gender]; }

// USA: func_ov009_02188ee8
extern "C" ARM int func_ov009_02188ee8(CharacterCreation* self) {
    self->flags &= ~0x60;
    int result = -1;
    int choice = -1;
    int x, y;
    SelectCoordsByFlag0x24((unsigned char*)&data_02114e54, &x, &y);
    int touched = 0;
    if (data_02114e54.pressed) {
        touched = 1;
        choice = func_ov009_02189854(self, x, y);
        self->touchedChoice = choice;
        if ((unsigned int)(choice + 3) <= 1) {
            if (choice == -2) self->flags |= 0x20;
            else if (choice == -3) self->flags |= 0x40;
            result = choice;
            DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
        } else if (choice >= 101 && choice <= 108) {
            result = choice;
            if (choice - 100 <= self->maxSteps[self->gender] && choice - 100 != self->state)
                DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
        } else if (choice >= 0) {
            func_0205bb04(&self->controls.navigation, choice);
            if (self->state == 8) {
                if (self->flags & 0x200000) {
                    self->flags &= ~0x200000;
                    result = -2;
                }
                self->flags |= 0x100;
            }
            self->lastX = self->cursorX;
            self->lastY = self->cursorY;
        }
    } else if (data_02114e54.held && data_02114e54.pressure) touched = 1;
    else if (data_02114e54.repeating) touched = 1;
    if (!touched) {
        unsigned int ticks = GameState::GetInstance()->GetTickCount();
        if (!ticks) ticks = 1;
        int previous = self->controls.navigation.selection;
        if (func_0205bf58(&self->controls.navigation, ticks)) choice = ComputeScaledSum0205bb84((Struct_0205bb84*)&self->controls.navigation);
        if (self->state == 8) {
            int rows = self->controls.navigation.rows;
            int count = GetField0_0205bafc(&self->controls.navigation);
            if (rows == 1 && count == 8) {
                if (choice >= self->maxSteps[self->gender]) {
                    func_0205bb04(&self->controls.navigation, self->maxSteps[self->gender] - 1);
                    choice = self->maxSteps[self->gender] - 1;
                }
                if (TestFlag0SetAndFlag1Clear(&data_02114e30, 0x80)) {
                    RESET_NAVIGATION(11, 6, 66, 0);
                    self->flags |= 0x2000;
                    if (self->savedEntries) self->list->entries = self->savedEntries;
                    self->list->selection = 0;
                    self->list->counter = 0;
                    return -1;
                }
                if (choice >= 0) { TAB_CURSOR(choice); }
                if (TestFlag0SetAndFlag1Clear(&data_02114e30, 1)) {
                    result = ComputeScaledSum0205bb84((Struct_0205bb84*)&self->controls.navigation) + 101;
                    if (result - 100 <= self->maxSteps[self->gender] && result - 100 != self->state)
                        DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
                }
                return result;
            }
            if (!self->blocked && TestFlag0SetAndFlag1Clear(&data_02114e30, 0x40)) {
                self->savedEntries = self->list->entries;
                self->list->entries = 0;
                RESET_NAVIGATION(8, 1, 8, self->state - 1);
                controls->navigation.field3c = 0;
                TAB_CURSOR(self->state - 1);
            }
        } else if (self->state != 8) {
            int rows = self->controls.navigation.rows;
            int count = GetField0_0205bafc(&self->controls.navigation);
            if (rows == 1 && count == 8) {
                if (choice >= self->maxSteps[self->gender]) {
                    func_0205bb04(&self->controls.navigation, self->maxSteps[self->gender] - 1);
                    choice = self->maxSteps[self->gender] - 1;
                }
                if (TestFlag0SetAndFlag1Clear(&data_02114e30, 0x80)) {
                    func_ov009_02188c2c(self);
                    self->flags |= 0x2000;
                    func_ov009_02188e70(self, ComputeScaledSum0205bb84((Struct_0205bb84*)&self->controls.navigation));
                    return -1;
                }
                if (choice >= 0) { TAB_CURSOR(choice); }
                if (TestFlag0SetAndFlag1Clear(&data_02114e30, 1)) {
                    result = ComputeScaledSum0205bb84((Struct_0205bb84*)&self->controls.navigation) + 101;
                    if (result - 100 <= self->maxSteps[self->gender] && result - 100 != self->state)
                        DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
                } else if (TestFlag0SetAndFlag1Clear(&data_02114e30, 2)) result = -3;
                if (result == 108) SetupPointerTable0205ba68((Struct_0205ba68*)&self->controls.navigation, 11, 6, 0);
                return result;
            }
            if (TestFlag0SetAndFlag1Clear(&data_02114e30, 0x40) && previous == 0) {
                RESET_NAVIGATION(8, 1, 8, self->state - 1);
                controls->navigation.field3c = 0;
                TAB_CURSOR(self->state - 1);
                self->flags |= 0x2000;
                return -1;
            }
            if (TestFlag0SetAndFlag1Clear(&data_02114e30, 1)) {
                result = -2;
                DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
            } else if (TestFlag0SetAndFlag1Clear(&data_02114e30, 2)) result = -3;
        }
    }
    self->flags &= ~0x10;
    if (choice >= 0 && !(choice >= 101 && choice <= 108)) {
        unsigned char* genderValue = &self->gender;
        switch (self->state) {
        case 8: break;
        case 1: { if (*genderValue != choice) self->flags |= 0x10; *genderValue = choice; break; }
        case 2: { unsigned char* values = self->body; int gender = self->gender; unsigned char prior = values[gender]; if (prior != choice) self->flags |= 0x10; values[gender] = choice; break; }
        case 3: { unsigned char* values = self->hair; int gender = self->gender; unsigned char prior = values[gender]; if (prior != choice) self->flags |= 0x10; values[gender] = choice; break; }
        case 4: { unsigned char* values = self->hairColor; int gender = self->gender; unsigned char prior = values[gender]; if (prior != choice) self->flags |= 0x10; values[gender] = choice; break; }
        case 5: { unsigned char* values = self->face; int gender = self->gender; unsigned char prior = values[gender]; if (prior != choice) self->flags |= 0x10; values[gender] = choice; break; }
        case 6: { unsigned char* values = self->eyes; int gender = self->gender; unsigned char prior = values[gender]; if (prior != choice) self->flags |= 0x10; values[gender] = choice; break; }
        case 7: { unsigned char* values = self->skin; int gender = self->gender; unsigned char prior = values[gender]; if (prior != choice) self->flags |= 0x10; values[gender] = choice; break; }
        }
    }
    if (self->flags & 0x10) {
        if (self->state != 8 || !touched) DispatchWithShortB4_0205eaa0(&data_02108760, 2, 0);
        func_ov009_02188944(self, choice);
        if (self->state == 1) {
            PartyMemberAppearance* appearance = &self->member->appearance;
            self->flags |= 0x60000;
            unsigned char eyeColor = GetEyeColor(self);
            appearance->eyeColor = eyeColor;
            unsigned char skinColor = GetSkinColor(self);
            appearance->skinColor = skinColor;
            unsigned char hairColor = GetHairColor(self);
            appearance->hairColor = hairColor;
            appearance->models[2] = func_ov009_02188b14(self, 5, self->face[self->gender]) + 0x233c;
            appearance->models[3] = func_ov009_02188b14(self, 3, self->hair[self->gender]) + 0x2328;
        }
        if (!touched) func_ov009_02188e70(self, choice);
        self->flags |= 0x6100;
    }
    if (result == 108 && result - 100 <= self->maxSteps[self->gender] && result - 100 != self->state)
        SetupPointerTable0205ba68((Struct_0205ba68*)&self->controls.navigation, 11, 6, 0);
    return result;
}

#endif
