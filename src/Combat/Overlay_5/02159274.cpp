#include <globaldefs.h>

#if defined(jpn)
#define func_ov005_02159274 func_ov005_0215a78c
enum { kEntryPad = 8, kYesNo = 0xe60, kTextBytes = 0x800, kPanel = 0xee0 };
#define func_ov005_021589f4 func_ov005_02159fd0
#define func_ov005_02159b74 func_ov005_0215b0b8
#define func_ov005_02158b3c func_ov005_0215a110
#define func_ov005_02157b74 func_ov005_0215916c
#else
enum { kEntryPad = 0x90, kYesNo = 0xe64, kTextBytes = 0x960, kPanel = 0xee4 };
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

struct SlotBlock02159274 {
    char unk_0[0xbb];
    signed char slot_;
};

struct Entry02159274 {
    short id;
    signed char state_;
    char pad[0x1c - 3];
};

struct EntryBlock02159274 {
    char unk_0[kEntryPad];
    Entry02159274 entries_[22];
    char unk_2ff8[0x3000 - 0x2ff8];
};

struct MenuTail02159274 {
    char unk_0[0xdaa];
    unsigned char f3daa_;
    char unk_dab[0xdcc - 0xdab];
    unsigned int dirty_;
    unsigned char unk_dd0;
    unsigned char message_;
    char unk_dd2[0xddc - 0xdd2];
    unsigned char step_;
    unsigned char unk_ddd;
    unsigned char unk_dde;
    unsigned char menuState_;
};

struct MenuSlotView02159274 {
    char unk_0[0x3d00 - 0x3000];
    SlotBlock02159274 slotblk_;
    char unk_1[0x3de0 - 0x3dbc];
};

struct MenuViews02159274 {
    union {
        MenuTail02159274 tail_;
        MenuSlotView02159274 slotview_;
    };
};

struct Menu02159274 {
    char unk_0[0xdf4];
    Container020dedd0* items_;
    char unk_df8[0xe10 - 0xdf8];
    char* text_;
    char unk_e14[kYesNo - 0xe14];
    void* yesNo_;
    char unk_e68[0x2d00 - kYesNo - 4];
    EntryBlock02159274 eblk_;
    MenuViews02159274 views_;
};

extern "C" char data_02108760[];

extern "C" int _Z24GetInnerFlagBit0020e28dcP13Outer020e28dc(Outer020e28dc* o);
extern "C" void _Z27UpdateEntryStateAndPositionP11Ctx020e263ci(Ctx020e263c* w, int value);
extern "C" void func_ov005_021589f4(void* self);
extern "C" void func_ov005_02159b74(void* self);
extern "C" int func_ov005_02158b3c(void* object, void* buffer);
extern "C" int _Z26GetField0x15UnlessInactivePa(void* w);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(Obj0205eaa0* obj, int a, int b);
extern "C" void _Z27ResetSelectionState020e25e8P11Obj020e25e8(void* w);
extern "C" int _Z23IsFlag0x2Active020e2984v(void* w);
extern "C" void* _Z24FindElementByKey020dedd0P17Container020dedd0i(Container020dedd0* c, int key);
extern "C" int _Z23GetFlagFromField0x8BitsP14Struct020dd768(Struct020dd768* s);
#if defined(jpn)
extern "C" int _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(StructA0205d5d0* a, int b, int c, int d);
#else
extern "C" int _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(StructA0205d5d0* a, int b, int c, int d, unsigned char e);
#endif
extern "C" void func_ov005_02157b74(void* self, int key, int keep);
extern "C" char* _Z17GetPtrField0x2a04P9GameState(GameState* gs);
extern "C" void _Z33DecrementKeyedStackAmount0207c484P17KeyedList0207c484iii(char* list, int key, int a, int b);
extern "C" void func_ov005_021555c0(void* self);

// USA: func_ov005_02159274
extern "C" ARM void func_ov005_02159274(Menu02159274* self) {
    int sel = GameState::GetInstance()->GetTickCount();
    if (sel == 0)
        sel = 1;

    if (self->yesNo_ != 0 && _Z24GetInnerFlagBit0020e28dcP13Outer020e28dc((Outer020e28dc*)self->yesNo_))
        _Z27UpdateEntryStateAndPositionP11Ctx020e263ci((Ctx020e263c*)self->yesNo_, sel);

    if (self->views_.tail_.step_ == 0) {
        self->views_.tail_.message_ = 8;
        func_ov005_021589f4(self);
        func_ov005_02159b74(self);
        self->views_.tail_.step_++;
        return;
    }
    if (self->views_.tail_.step_ == 1) {
        sel = _Z26GetField0x15UnlessInactivePa(self->yesNo_);
        if (sel >= 0) {
            _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((Obj0205eaa0*)data_02108760, 1, 0);
            _Z27ResetSelectionState020e25e8P11Obj020e25e8(self->yesNo_);
        } else if (_Z23IsFlag0x2Active020e2984v(self->yesNo_)) {
            _Z27ResetSelectionState020e25e8P11Obj020e25e8(self->yesNo_);
            sel = -2;
        }
        if (sel == 0) {
            void* item;
            int notfound;
            int flag;
            item = _Z24FindElementByKey020dedd0P17Container020dedd0i(
                self->items_,
                self->eblk_.entries_[self->views_.slotview_.slotblk_.slot_].id);
            flag = _Z23GetFlagFromField0x8BitsP14Struct020dd768((Struct020dd768*)item);
            if (flag == 1) {
                self->views_.tail_.message_ = 0xa;
                memset(self->text_, 0, kTextBytes);
                func_ov005_02158b3c(self, self->text_);
                if (self->views_.slotview_.slotblk_.slot_ >= 0 && self->views_.slotview_.slotblk_.slot_ < 8) {
                    if (((ItemBits02159274*)((char*)item + 8))->flag18) {
                        self->views_.tail_.message_ = 0xc;
                        memset(self->text_, 0, kTextBytes);
                        func_ov005_02158b3c(self, self->text_);
                        _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(
                            (StructA0205d5d0*)((char*)self + kPanel), 0, (int)self->text_, 1
#if !defined(jpn)
                            , 0
#endif
                        );
                        self->views_.tail_.menuState_ = 4;
                        self->views_.tail_.step_ = 0;
                        return;
                    }
                    func_ov005_02157b74(self, 0xffff, 1);
                } else if (self->views_.slotview_.slotblk_.slot_ >= 8 &&
                       self->views_.slotview_.slotblk_.slot_ < 0x18) {
                    char* list = _Z17GetPtrField0x2a04P9GameState(GameState::GetInstance());
                    int amount = ((ItemBits02159274*)((char*)item + 8))->amount;
                    sel = *(short*)((char*)item + 0x18);
                    _Z33DecrementKeyedStackAmount0207c484P17KeyedList0207c484iii(
                        list + 0x1d4, sel, 1, amount);
                    notfound = 1;
                    func_ov005_021555c0(self);
                    for (int i = 8; i < 0x18; i++) {
                        if (self->eblk_.entries_[i].id == sel) {
                            notfound = 0;
                            break;
                        }
                    }
                    if (notfound) {
                        self->views_.tail_.dirty_ |= 0x40;
                        self->views_.tail_.f3daa_ = 0;
                    }
                }
                _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(
                    (StructA0205d5d0*)((char*)self + kPanel), 0, (int)self->text_, 1
#if !defined(jpn)
                            , 0
#endif
                        );
            } else if (flag == 2) {
                self->views_.tail_.message_ = 9;
                memset(self->text_, 0, kTextBytes);
                func_ov005_02158b3c(self, self->text_);
                _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(
                    (StructA0205d5d0*)((char*)self + kPanel), 0, (int)self->text_, 1
#if !defined(jpn)
                            , 0
#endif
                        );
                self->views_.tail_.step_++;
                return;
            } else if (flag == 4) {
                self->views_.tail_.message_ = 0xb;
                memset(self->text_, 0, kTextBytes);
                func_ov005_02158b3c(self, self->text_);
                _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(
                    (StructA0205d5d0*)((char*)self + kPanel), 0, (int)self->text_, 1
#if !defined(jpn)
                            , 0
#endif
                        );
            }
            self->views_.tail_.menuState_ = 4;
            self->views_.tail_.step_ = 0;
            return;
        }
        if (sel == -2 || sel == 1) {
            self->views_.tail_.menuState_ = 4;
            self->views_.tail_.step_ = 0;
            return;
        }
        return;
    }
    if (self->views_.tail_.step_ == 2) {
        func_ov005_02159b74(self);
        self->views_.tail_.step_++;
        return;
    }
    if (self->views_.tail_.step_ == 3) {
        sel = _Z26GetField0x15UnlessInactivePa(self->yesNo_);
        if (sel >= 0) {
            _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((Obj0205eaa0*)data_02108760, 1, 0);
            _Z27ResetSelectionState020e25e8P11Obj020e25e8(self->yesNo_);
        } else if (_Z23IsFlag0x2Active020e2984v(self->yesNo_)) {
            _Z27ResetSelectionState020e25e8P11Obj020e25e8(self->yesNo_);
            sel = -2;
        }
        if (sel == 0) {
            void* item;
            int notfound;
            self->views_.tail_.message_ = 0xa;
            memset(self->text_, 0, kTextBytes);
            func_ov005_02158b3c(self, self->text_);
            if (self->views_.slotview_.slotblk_.slot_ >= 0 && self->views_.slotview_.slotblk_.slot_ < 8) {
                item = _Z24FindElementByKey020dedd0P17Container020dedd0i(
                    self->items_,
                    self->eblk_.entries_[self->views_.slotview_.slotblk_.slot_].id);
                if (((ItemBits02159274*)((char*)item + 8))->flag18) {
                    self->views_.tail_.message_ = 0xc;
                    memset(self->text_, 0, kTextBytes);
                    func_ov005_02158b3c(self, self->text_);
                    _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(
                        (StructA0205d5d0*)((char*)self + kPanel), 0, (int)self->text_, 1
#if !defined(jpn)
                            , 0
#endif
                        );
                    self->views_.tail_.menuState_ = 4;
                    self->views_.tail_.step_ = 0;
                    return;
                }
                func_ov005_02157b74(self, 0xffff, 1);
            } else if (self->views_.slotview_.slotblk_.slot_ >= 8 && self->views_.slotview_.slotblk_.slot_ < 0x18) {
                char* list = _Z17GetPtrField0x2a04P9GameState(GameState::GetInstance());
                item = _Z24FindElementByKey020dedd0P17Container020dedd0i(
                    self->items_,
                    self->eblk_.entries_[self->views_.slotview_.slotblk_.slot_].id);
                sel = *(short*)((char*)item + 0x18);
                _Z33DecrementKeyedStackAmount0207c484P17KeyedList0207c484iii(
                    list + 0x1d4,
                    sel,
                    1,
                    ((ItemBits02159274*)((char*)item + 8))->amount);
                notfound = 1;
                func_ov005_021555c0(self);
                for (int i = 8; i < 0x18; i++) {
                    if (self->eblk_.entries_[i].id == sel) {
                        notfound = 0;
                        break;
                    }
                }
                if (notfound) {
                    self->views_.tail_.dirty_ |= 0x40;
                    self->views_.tail_.f3daa_ = 0;
                }
            }
            _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(
                (StructA0205d5d0*)((char*)self + kPanel), 0, (int)self->text_, 1
#if !defined(jpn)
                            , 0
#endif
                        );
            self->views_.tail_.menuState_ = 4;
            self->views_.tail_.step_ = 0;
            return;
        }
        if (sel == -2 || sel == 1) {
            self->views_.tail_.menuState_ = 4;
            self->views_.tail_.step_ = 0;
            return;
        }
        return;
    }
}
