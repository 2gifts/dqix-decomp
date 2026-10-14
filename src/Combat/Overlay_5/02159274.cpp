#include "Combat/TryApplyElemFields.h"
#include <globaldefs.h>

#if defined(jpn)
enum { kYesNo = 0xe60, kTextBytes = 0x800, kPanel = 0xee0 };
#define func_ov005_02157b74 func_ov005_0215916c
#else
enum { kYesNo = 0xe64, kTextBytes = 0x960, kPanel = 0xee4 };
#endif

#include <std_library_functions.h>
#include <GameState/GameState.h>

struct Outer020e28dc;
struct Ctx020e263c;
struct Obj0205eaa0;
struct StructA0205d5d0;
struct Container020dedd0;
struct Struct020dd768;

struct ItemBits02159274 {
    unsigned int amount : 4;
    unsigned int pad0 : 14;
    unsigned int flag18 : 1;
    unsigned int pad1 : 13;
};

struct EquipmentSlot02159274 {
    short id;
    signed char count;
    unsigned char equipped;
    void* vramState;
    void* model;
    int x;
    int y;
    int offset;
    short loadedItem;
};

struct Menu02159274 {
    char unknown0[0xdf4];
    Container020dedd0* items_;
    char unknownDf8[0xe10 - 0xdf8];
    char* text_;
    char unknownE14[kYesNo - 0xe14];
    void* yesNo_;
#if defined(jpn)
    char unknownAfterYesNo[0x2d08 - kYesNo - 4];
#else
    char unknownAfterYesNo[0x2d90 - kYesNo - 4];
#endif
    EquipmentSlot02159274 slots[24];
    char unknownAfterSlots[0x3daa - 0x3030];
    unsigned char f3daa_;
    char unknownDab[0x3dbb - 0x3dab];
    signed char selectedSlot;
    char unknownDbc[0x3dcc - 0x3dbc];
    unsigned int dirty_;
    unsigned char unknownDd0;
    unsigned char message_;
    char unknownDd2[0x3ddc - 0x3dd2];
    unsigned char step_;
    unsigned char unknownDdd;
    unsigned char unknownDde;
    unsigned char menuState_;
};

extern "C" char data_02108760[];

int GetInnerFlagBit0020e28dc(Outer020e28dc* o);
void UpdateEntryStateAndPosition(Ctx020e263c* w, int value);
extern "C" void func_ov005_021589f4(void* self);
extern "C" void func_ov005_02159b74(void* self);
extern "C" int func_ov005_02158b3c(void* object, void* buffer);
int GetField0x15UnlessInactive(signed char*);
void DispatchWithShortB4_0205eaa0(Obj0205eaa0* obj, int a, int b);
struct Obj020e25e8;
void ResetSelectionState020e25e8(Obj020e25e8*);
int IsFlag0x2Active020e2984(struct Outer020e28dc* window);
void* FindElementByKey020dedd0(Container020dedd0* c, int key);
int GetFlagFromField0x8Bits(Struct020dd768* s);
extern "C" void func_ov005_02157b74(void* self, int key, int keep);
extern "C" char* _Z17GetPtrField0x2a04P9GameState(GameState* gs);
struct KeyedList0207c484;
void DecrementKeyedStackAmount0207c484(KeyedList0207c484*, int, int, int);
extern "C" void func_ov005_021555c0(void* self);

// USA: func_ov005_02159274
extern "C" ARM void func_ov005_02159274(Menu02159274* self) {
    int sel = GameState::GetInstance()->GetTickCount();
    if (sel == 0)
        sel = 1;

    if (self->yesNo_ != 0 && GetInnerFlagBit0020e28dc((Outer020e28dc*)self->yesNo_))
        UpdateEntryStateAndPosition((Ctx020e263c*)self->yesNo_, sel);

    if (self->step_ == 0) {
        self->message_ = 8;
        func_ov005_021589f4(self);
        func_ov005_02159b74(self);
        self->step_++;
        return;
    }
    if (self->step_ == 1) {
        sel = GetField0x15UnlessInactive((signed char*)self->yesNo_);
        if (sel >= 0) {
            DispatchWithShortB4_0205eaa0((Obj0205eaa0*)data_02108760, 1, 0);
            ResetSelectionState020e25e8((Obj020e25e8*)self->yesNo_);
        } else if (IsFlag0x2Active020e2984((struct Outer020e28dc*)self->yesNo_)) {
            ResetSelectionState020e25e8((Obj020e25e8*)self->yesNo_);
            sel = -2;
        }
        if (sel == 0) {
            void* item;
            int notfound;
            int flag;
            item = FindElementByKey020dedd0(
                self->items_,
                self->slots[self->selectedSlot].id);
            flag = GetFlagFromField0x8Bits((Struct020dd768*)item);
            if (flag == 1) {
                self->message_ = 0xa;
                memset(self->text_, 0, kTextBytes);
                func_ov005_02158b3c(self, self->text_);
                if (self->selectedSlot >= 0 && self->selectedSlot < 8) {
                    if (((ItemBits02159274*)((char*)item + 8))->flag18) {
                        self->message_ = 0xc;
                        memset(self->text_, 0, kTextBytes);
                        func_ov005_02158b3c(self, self->text_);
                        TryApplyElemFields0205d5d0(
                            (StructA0205d5d0*)((char*)self + kPanel), 0, (int)self->text_, 1
#if !defined(jpn)
                            , 0
#endif
                        );
                        self->menuState_ = 4;
                        self->step_ = 0;
                        return;
                    }
                    func_ov005_02157b74(self, 0xffff, 1);
                } else if (self->selectedSlot >= 8 &&
                       self->selectedSlot < 0x18) {
                    char* list = _Z17GetPtrField0x2a04P9GameState(GameState::GetInstance());
                    int amount = ((ItemBits02159274*)((char*)item + 8))->amount;
                    sel = *(short*)((char*)item + 0x18);
                    DecrementKeyedStackAmount0207c484((KeyedList0207c484*)(list + 0x1d4), sel, 1, amount);
                    notfound = 1;
                    func_ov005_021555c0(self);
                    for (int i = 8; i < 0x18; i++) {
                        if (self->slots[i].id == sel) {
                            notfound = 0;
                            break;
                        }
                    }
                    if (notfound) {
                        self->dirty_ |= 0x40;
                        self->f3daa_ = 0;
                    }
                }
                TryApplyElemFields0205d5d0(
                    (StructA0205d5d0*)((char*)self + kPanel), 0, (int)self->text_, 1
#if !defined(jpn)
                            , 0
#endif
                        );
            } else if (flag == 2) {
                self->message_ = 9;
                memset(self->text_, 0, kTextBytes);
                func_ov005_02158b3c(self, self->text_);
                TryApplyElemFields0205d5d0(
                    (StructA0205d5d0*)((char*)self + kPanel), 0, (int)self->text_, 1
#if !defined(jpn)
                            , 0
#endif
                        );
                self->step_++;
                return;
            } else if (flag == 4) {
                self->message_ = 0xb;
                memset(self->text_, 0, kTextBytes);
                func_ov005_02158b3c(self, self->text_);
                TryApplyElemFields0205d5d0(
                    (StructA0205d5d0*)((char*)self + kPanel), 0, (int)self->text_, 1
#if !defined(jpn)
                            , 0
#endif
                        );
            }
            self->menuState_ = 4;
            self->step_ = 0;
            return;
        }
        if (sel == -2 || sel == 1) {
            self->menuState_ = 4;
            self->step_ = 0;
            return;
        }
        return;
    }
    if (self->step_ == 2) {
        func_ov005_02159b74(self);
        self->step_++;
        return;
    }
    if (self->step_ == 3) {
        sel = GetField0x15UnlessInactive((signed char*)self->yesNo_);
        if (sel >= 0) {
            DispatchWithShortB4_0205eaa0((Obj0205eaa0*)data_02108760, 1, 0);
            ResetSelectionState020e25e8((Obj020e25e8*)self->yesNo_);
        } else if (IsFlag0x2Active020e2984((struct Outer020e28dc*)self->yesNo_)) {
            ResetSelectionState020e25e8((Obj020e25e8*)self->yesNo_);
            sel = -2;
        }
        if (sel == 0) {
            void* item;
            int notfound;
            self->message_ = 0xa;
            memset(self->text_, 0, kTextBytes);
            func_ov005_02158b3c(self, self->text_);
            if (self->selectedSlot >= 0 && self->selectedSlot < 8) {
                item = FindElementByKey020dedd0(
                    self->items_,
                    self->slots[self->selectedSlot].id);
                if (((ItemBits02159274*)((char*)item + 8))->flag18) {
                    self->message_ = 0xc;
                    memset(self->text_, 0, kTextBytes);
                    func_ov005_02158b3c(self, self->text_);
                    TryApplyElemFields0205d5d0(
                        (StructA0205d5d0*)((char*)self + kPanel), 0, (int)self->text_, 1
#if !defined(jpn)
                            , 0
#endif
                        );
                    self->menuState_ = 4;
                    self->step_ = 0;
                    return;
                }
                func_ov005_02157b74(self, 0xffff, 1);
            } else if (self->selectedSlot >= 8 && self->selectedSlot < 0x18) {
                char* list = _Z17GetPtrField0x2a04P9GameState(GameState::GetInstance());
                item = FindElementByKey020dedd0(
                    self->items_,
                    self->slots[self->selectedSlot].id);
                sel = *(short*)((char*)item + 0x18);
                DecrementKeyedStackAmount0207c484((KeyedList0207c484*)(list + 0x1d4), sel, 1, ((ItemBits02159274*)((char*)item + 8))->amount);
                notfound = 1;
                func_ov005_021555c0(self);
                for (int i = 8; i < 0x18; i++) {
                    if (self->slots[i].id == sel) {
                        notfound = 0;
                        break;
                    }
                }
                if (notfound) {
                    self->dirty_ |= 0x40;
                    self->f3daa_ = 0;
                }
            }
            TryApplyElemFields0205d5d0(
                (StructA0205d5d0*)((char*)self + kPanel), 0, (int)self->text_, 1
#if !defined(jpn)
                            , 0
#endif
                        );
            self->menuState_ = 4;
            self->step_ = 0;
            return;
        }
        if (sel == -2 || sel == 1) {
            self->menuState_ = 4;
            self->step_ = 0;
            return;
        }
        return;
    }
}
