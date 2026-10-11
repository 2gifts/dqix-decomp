#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Resource/Brightness.h>

extern unsigned char data_02114e54;

struct MenuTail {
    char pad[0x4fc];
    int index;
};

struct Res3000 {
    char pad[0x708];
    int* ptr708;
};

struct Obj0205eaa0;
extern Obj0205eaa0 data_02108760;

struct Src02157174;
struct Dst02157174;
extern "C" void _Z23CopyThreeFields02157174P11Dst02157174P11Src02157174(Dst02157174*, Src02157174*);

extern "C" void _Z22SelectCoordsByFlag0x24PhPiS0_(unsigned char*, int*, int*);

struct Struct_0205bb84;
extern "C" int _Z24ComputeScaledSum0205bb84P15Struct_0205bb84(Struct_0205bb84*);
extern "C" int func_0205bf58(void*, int);
extern "C" int _Z25CheckFlag30Or401_02157190v(void*);
extern "C" char* _Z19GetField1c_021a193cPi(int*);
extern "C" void _Z28DispatchByIdxAndCond021551fcPchi(char*, int, int);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(Obj0205eaa0*, int, int);
extern "C" void func_ov005_021555c0(void*);
extern "C" void func_ov005_0215792c(void*, unsigned char);
extern "C" unsigned char func_ov005_021586c4(void*, int, int);

struct EquipmentSlot {
    short item_;
    signed char count_;
    unsigned char equipped_;
    void* vramState_;
    void* model_;
    int x_;
    int y_;
    int offset_;
    short loadedItem_;
};

struct Triplet {
    int a;
    int b;
    int c;
};

struct Menu {
    char pad0[0xd90];
    char pad1[0x19f4 - 0xd90];
    char scale_[0x2d90 - 0x19f4];
    char pad2[0x3d78 - 0x2d90];
    short count_;
    char pad3[0x3daa - 0x3d7a];
    unsigned char f3daa_;
    char pad4[0x3db8 - 0x3dab];
    unsigned char f3db8_;
    char pad5[0x3dba - 0x3db9];
    unsigned char f3dba_;
    unsigned char f3dbb_;
    unsigned char kind_;
    signed char page_;
    unsigned char unk3dbe_;
    unsigned char f3dbf_;
    char pad7[0x3dcc - 0x3dc0];
    unsigned int flags_;
    char pad8[0x3dfc - 0x3dd0];
    unsigned char pages_[8];
};

// USA: func_ov005_0215b2bc
extern "C" ARM void func_ov005_0215b2bc(Menu* self) {
    if (self->f3dba_ == 0) {
        if (!IsBrightnessTransitionActive(func_ov017_0218b5b0())) {
            self->f3dba_++;
        }
    } else if (self->f3dba_ == 1) {
        int found = 0;
        int flag2 = 0;
        unsigned char sel = 255;
        int hasCoords = 0;
        int bx;
        int by;
        if ((&data_02114e54)[0x55] != 0) {
            hasCoords = 1;
            _Z22SelectCoordsByFlag0x24PhPiS0_(&data_02114e54, &bx, &by);
            sel = func_ov005_021586c4(self, bx, by);
            if (sel != 255) {
                found = hasCoords;
                flag2 = found;
            } else if (bx > 0x80) {
                for (int i = found; i < 8; i++) {
                    int row = i * 0x18;
                    int hi = row + 0x18;
                    if (by > row && by < hi) {
                        found = 1;
                        flag2 = found;
                        sel = i;
                        break;
                    }
                }
            }
        }
        if (hasCoords == 0) {
            found = 1;
            unsigned int tick = GameState::GetInstance()->GetTickCount();
            func_0205bf58((char*)self + 0x19f4, tick ? tick : found);
            sel = _Z24ComputeScaledSum0205bb84P15Struct_0205bb84((Struct_0205bb84*)&self->scale_[0]);
            if (_Z25CheckFlag30Or401_02157190v(self)) flag2 = 1;
        }
        if (found != 0 && self->kind_ != sel) {
            self->unk3dbe_ = self->kind_;
            self->f3dbf_ = self->page_;
            self->pages_[self->kind_] = self->page_;
            self->kind_ = sel;
            self->page_ = self->pages_[sel & 0xff];
        }
        self->f3dbb_ = self->kind_;
        MenuTail* hold = (MenuTail*)_Z19GetField1c_021a193cPi(((Res3000*)((char*)(long)func_ov017_0218b5b0() + 0x3000))->ptr708);
        _Z28DispatchByIdxAndCond021551fcPchi((char*)self, hold->index, 0);
        if (flag2 == 0) return;
        _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, 1, 0);
        func_ov005_021555c0(self);
        self->flags_ |= 0x40;
        self->f3daa_ = 0;
        func_ov005_0215792c(self, 1);
        EquipmentSlot* slots;
        int j = 0;
        for (; j < 8; j++) {
            slots = (EquipmentSlot*)((char*)self + 0x2d90);
            EquipmentSlot* s = &slots[j];
            if (j == self->count_) continue;
            if (s->item_ < 0) continue;
            Src02157174* m = (Src02157174*)s->model_;
            Triplet t = *(Triplet*)((char*)m + 0x1c);
            t.b = 0x17000;
            _Z23CopyThreeFields02157174P11Dst02157174P11Src02157174((Dst02157174*)m, (Src02157174*)&t);
        }
    }
}