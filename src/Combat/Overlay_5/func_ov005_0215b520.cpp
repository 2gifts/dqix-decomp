#include <globaldefs.h>
#include "Resource/GameResources.h"
#include "Graphics/Vector.h"

#if defined(jpn)
#define REGION(j,u) (j)
#define data_ov005_0215cbec data_ov005_0215dfcc
#define data_ov005_0215cbdc data_ov005_0215dfbc
#else
#define REGION(j,u) (u)
#endif

struct MemberScreen {
    char unknown[REGION(0x4f8,0x4fc)];
    int member;
};

void IssueCommand0x19(int cmd);

struct BackgroundResourceEntry;
struct Obj0204b8d0 {
    char unknown0[0x10];
    BackgroundResourceEntry* entries;
    unsigned short* destination;
    char unknown18[5];
    unsigned char count;
};
extern "C" void _Z21DispatchEntry0204b8d0P11Obj0204b8d0jiisssst(struct Obj0204b8d0*, unsigned int, int, int, short, short, short, short, unsigned short);
struct Obj0204b010;
extern "C" void _Z19ClearBuffer0204b010P11Obj0204b010Pv(struct Obj0204b010* obj, void* p);
extern "C" void func_0204b04c(void* p, int flag);
extern "C" void func_02047554(void* obj, int val, int param1);
extern "C" void func_ov005_0215792c(void* obj, unsigned char mode);
extern "C" void func_ov005_021579ec(void* obj, unsigned int a, unsigned char b);
extern "C" void func_ov005_02154d34(void* obj, int a, int b);
extern "C" void func_ov005_02154d7c(void* obj, int a, int b);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" MemberScreen* _Z19GetField1c_021a193cPi(int* p);
extern "C" void* _Z25GetCombatantWithFlag0x100P9GameStatei(void* gs, int id);
extern "C" short* _Z19GetField150Ptr0x488P22Field150Holder02052e14(void* holder);

extern const unsigned char data_ov005_0215cbec[];
extern const unsigned char data_ov005_0215cbdc[];

#define G3_MTX_PUSH  (*(volatile int*)0x04000444)
#define G3_MTX_POP   (*(volatile int*)0x04000448)
#define G3_MTX_SCALE (*(volatile int*)0x0400046c)
#define G3_MTX_TRANS (*(volatile int*)0x04000470)

struct Entry0215b520 {
    char data[0x88];
};

struct Container020dedd0;
struct Element020de650;
struct Obj021dcae0 {
    char pad0[0x48];
    Container020dedd0* field48;
    Element020de650* field4c;
    char pad50[REGION(0x680,0x704)];
    int field754;
    char pad758[0x18];
    short field770;
    unsigned short field772;
    unsigned short flags;
    unsigned char field776;
};
struct EquipmentSlot {
    short item;
    signed char count;
    unsigned char equipped;
    void* vramState;
    Entry0215b520* model;
    int x, y, offset;
    short loadedItem;
};
extern "C" void func_ov023_021dcba4(void*, short);

struct Scene0215b520 {
    char pad0[REGION(0xea0,0xea4)];
    Obj0204b8d0 list;
    char beforeInfo[0x1244 - 0xec4];
    Obj021dcae0 infoWindow;
    char beforeMotion[REGION(0x19ac - 0x1240,0x1a34 - 0x1244) - sizeof(Obj021dcae0)];
    char motion[0x3c];
    Entry0215b520 models[36];
    EquipmentSlot slots[24];
    Entry0215b520 slotModels[24];
    Entry0215b520 dragModel;
    short dragged;
    char beforeMode[0x3db8 - 0x3d7a];
    unsigned char mode;     // 0x3db8
    char pad4;
    unsigned char state;    // 0x3dba
    signed char modeB;    // 0x3dbb
    unsigned char cursor;   // 0x3dbc
    char pad5[0x3dcc - 0x3dbd];
    unsigned int flags;     // 0x3dcc
    char pad6[0x3de2 - 0x3dd0];
    short level;            // 0x3de2
    int step;               // 0x3de4
    int accum;              // 0x3de8
    int phase;              // 0x3dec
};

// USA: func_ov005_0215b520
extern "C" ARM void func_ov005_0215b520(Scene0215b520* self) {
    unsigned char state = self->state;
    if (state == 0 && self->phase == 0) {
        func_ov005_0215792c(self, 1);
        self->flags |= 0x100;
        void* gs = _ZN9GameState11GetInstanceEv();
        GameResources* res = func_ov017_0218b5b0();
        MemberScreen* holder = _Z19GetField1c_021a193cPi((int*)res->unknown_ptr_array_36fc[3]);
        short* tbl = _Z19GetField150Ptr0x488P22Field150Holder02052e14(
            _Z25GetCombatantWithFlag0x100P9GameStatei(gs, holder->member));
        self->accum += self->step;
        if (self->accum >= 3) {
            self->accum -= 3;
            self->level += 0x29;
            if (self->level >= 0x7b) {
                self->level = 0x7b;
                self->phase = 1;
            }
        }
        if (self->mode == 1) {
            for (int i = 0; i < 8; i++) {
                int sel = 0;
                if (i == self->cursor) sel = 1;
                int k = sel * 11;
                int y = (i * 0x18) << 12;
                G3_MTX_PUSH = 0;
                G3_MTX_TRANS = (self->level + 0x7f) << 12;
                G3_MTX_TRANS = y;
                G3_MTX_TRANS = -0x200000;
                func_02047554(&self->models[k + 4], 0, 1);
                G3_MTX_POP = 1;
                G3_MTX_PUSH = 0;
                G3_MTX_TRANS = (self->level + 0x100) << 12;
                G3_MTX_TRANS = y;
                G3_MTX_TRANS = -0x200000;
                Matrix4x3 rot;
                rot = RotationMatrixY(0x3244);
                IssueCommand0x19((int)&rot);
                func_02047554(&self->models[k + 4], 0, 1);
                G3_MTX_POP = 1;
                G3_MTX_PUSH = 0;
                G3_MTX_TRANS = (self->level + 0x70) << 12;
                G3_MTX_TRANS = y;
                G3_MTX_TRANS = -0x200000;
                G3_MTX_SCALE = 0x14000;
                G3_MTX_SCALE = 0x1000;
                G3_MTX_SCALE = 0x1000;
                func_02047554(&self->models[k + 5], 0, 1);
                G3_MTX_POP = 1;
                Entry0215b520* e = &self->models[k + 7 + i];
                if (tbl[data_ov005_0215cbec[i]] > 0) {
                    e = &self->models[k + 6];
                }
                G3_MTX_PUSH = 0;
                G3_MTX_TRANS = (self->level + 0x85) << 12;
                G3_MTX_TRANS = y;
                G3_MTX_TRANS = -0x1ff000;
                func_02047554(e, 0, 1);
                G3_MTX_POP = 1;
            }
        }
        if (self->phase == 1) {
            self->state++;
            self->level = 0;
            self->accum = 0;
            self->phase = 0;
        }
    } else if (state == 1 && self->phase == 0) {
        self->flags |= 0x100;
        self->accum += self->step;
        if (self->accum >= 3) {
            self->accum -= 3;
            self->level += 6;
            if (self->level >= 0x10) {
                self->level = 0x10;
                self->phase = 1;
            }
        }
        _Z19ClearBuffer0204b010P11Obj0204b010Pv((struct Obj0204b010*)&self->list, 0);
        _Z21DispatchEntry0204b8d0P11Obj0204b8d0jiisssst(&self->list, 0, 0, 0, 0x20 - self->level, 0, 0x10, 0x16, 0xffff);
        unsigned char cursor = self->cursor;
        short y = cursor * 2 + 0xf;
        _Z21DispatchEntry0204b8d0P11Obj0204b8d0jiisssst(&self->list, (unsigned char)(cursor + 1), 0, 0, y + 0x10 - self->level, 0, 4, 3, 0xffff);
        func_0204b04c(&self->list, 0);
        if (self->phase == 1) {
            self->state++;
            self->level = 0;
            self->accum = 0;
        }
    } else if (state == 2 && self->phase == 1) {
        func_ov005_0215792c(self, 3);
        self->flags |= 0x100;
        func_ov005_021579ec(self, self->mode, self->modeB);
        func_ov005_02154d34(self->motion, 0x85000, 0x17000);
        func_ov005_02154d7c(self->motion, 0x76000, 0x16000);
        self->flags |= 0x800;
    } else if (state == 0 && self->phase == 1) {
        self->flags |= 0x800;
        func_ov005_0215792c(self, 1);
        self->flags |= 0x100;
        self->accum += self->step;
        if (self->accum >= 3) {
            self->accum -= 3;
            self->level += 6;
            if (self->level >= 0x10) {
                self->level = 0x10;
                self->phase = 2;
            }
        }
        _Z19ClearBuffer0204b010P11Obj0204b010Pv((struct Obj0204b010*)&self->list, 0);
        _Z21DispatchEntry0204b8d0P11Obj0204b8d0jiisssst(&self->list, 0, 0, 0, self->level + 0x10, 0, 0x10, 0x16, 0xffff);
        unsigned char cursor = self->cursor;
        short y = cursor * 2 + 0xf;
        _Z21DispatchEntry0204b8d0P11Obj0204b8d0jiisssst(&self->list, (unsigned char)(cursor + 1), 0, 0, y + self->level, 0, 4, 3, 0xffff);
        func_0204b04c(&self->list, 0);
        if (self->phase == 2) {
            self->state++;
            self->level = 0;
            self->accum = 0;
        }
    } else if (state == 1 && self->phase == 2) {
        void* gs = _ZN9GameState11GetInstanceEv();
        GameResources* res = func_ov017_0218b5b0();
        MemberScreen* holder = _Z19GetField1c_021a193cPi((int*)res->unknown_ptr_array_36fc[3]);
        short* tbl = _Z19GetField150Ptr0x488P22Field150Holder02052e14(
            _Z25GetCombatantWithFlag0x100P9GameStatei(gs, holder->member));
        self->accum += self->step;
        if (self->accum >= 3) {
            self->accum -= 3;
            self->level += 0x29;
            if (self->level >= 0x7b) {
                self->level = 0x7b;
                self->phase = 1;
            }
        }
        if (self->mode == 1) {
            for (int i = 0; i < 8; i++) {
                int sel = 0;
                if (i == self->cursor) sel = 1;
                int k = sel * 11;
                int y = (i * 0x18) << 12;
                G3_MTX_PUSH = 0;
                G3_MTX_TRANS = (0xfa - self->level) << 12;
                G3_MTX_TRANS = y;
                G3_MTX_TRANS = -0x200000;
                func_02047554(&self->models[k + 4], 0, 1);
                G3_MTX_POP = 1;
                G3_MTX_PUSH = 0;
                G3_MTX_TRANS = (0x17b - self->level) << 12;
                G3_MTX_TRANS = y;
                G3_MTX_TRANS = -0x200000;
                Matrix4x3 rot;
                rot = RotationMatrixY(0x3244);
                IssueCommand0x19((int)&rot);
                func_02047554(&self->models[k + 4], 0, 1);
                G3_MTX_POP = 1;
                G3_MTX_PUSH = 0;
                G3_MTX_TRANS = (0xeb - self->level) << 12;
                G3_MTX_TRANS = y;
                G3_MTX_TRANS = -0x200000;
                G3_MTX_SCALE = 0x14000;
                G3_MTX_SCALE = 0x1000;
                G3_MTX_SCALE = 0x1000;
                func_02047554(&self->models[k + 5], 0, 1);
                G3_MTX_POP = 1;
                Entry0215b520* e = &self->models[k + 7 + i];
                if (tbl[data_ov005_0215cbdc[i]] > 0) {
                    e = &self->models[k + 6];
                }
                G3_MTX_PUSH = 0;
                G3_MTX_TRANS = (0x100 - self->level) << 12;
                G3_MTX_TRANS = y;
                G3_MTX_TRANS = -0x1ff000;
                func_02047554(e, 0, 1);
                G3_MTX_POP = 1;
            }
        }
        if (self->phase == 1) {
            self->state = 0;
            self->level = 0;
            self->accum = 0;
            self->phase = 0;
            func_ov005_0215792c(self, 0);
            self->flags |= 0x100;
        }
    }
#if defined(jpn)
    _Z19GetField1c_021a193cPi((int*)func_ov017_0218b5b0()->unknown_ptr_array_36fc[3]);
    short item = self->slots[self->modeB].item;
    self->infoWindow.flags |= 0x80;
    func_ov023_021dcba4(&self->infoWindow, item);
#endif

}
