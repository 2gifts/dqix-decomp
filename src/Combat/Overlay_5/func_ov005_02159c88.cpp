#include <globaldefs.h>
#include "Resource/GameResources.h"

#if defined(jpn)
#define REGION(j,u) (j)
#else
#define REGION(j,u) (u)
#endif

struct MemberScreen {
    char unknown[REGION(0x4f8,0x4fc)];
    int member;
};

extern "C" long labs(long);
struct Dst02157174;
struct Src02157174;
void CopyThreeFields02157174(Dst02157174*, Src02157174*);
struct StructAt020473c8;
void RenderFlaggedIndexedEntry(StructAt020473c8*, int);
extern "C" void func_02047554(void* obj, int val, int param1);
struct Container020dedd0;
void* FindElementByKey020dedd0(Container020dedd0*, int);
MemberScreen* GetField1c_021a193c(int* p);
extern "C" int func_020dd4c4(char a, void* b);
extern "C" void func_ov005_02154d18(void* obj, int a, int b);
extern "C" void func_ov005_02154d34(void* obj, int a, int b);
extern "C" void func_ov005_02154d50(void* obj, int a, int b);
extern "C" void func_ov005_02154d7c(void* obj, int a, int b);

#define G3_MTX_PUSH  (*(volatile int*)0x04000444)
#define G3_MTX_POP   (*(volatile int*)0x04000448)
#define G3_MTX_TRANS (*(volatile int*)0x04000470)

struct Vec3_02159c88 { int x; int y; int z; };

struct Obj02159c88 {
    char pad0[0x1c];
    Vec3_02159c88 pos;
    char pad1[0x80 - 0x28];
    short color;
    short timer;
    char unknown84[4];
};

struct Slot02159c88 {
    short id;
    char pad[6];
    Obj02159c88* obj;
    int x;
    int y;
    int pad2[2];
};

struct Menu02159c88 {
    char pad0[0xdf4];
    void* container;
    char pad1[REGION(0x19ac,0x1a34) - 0xdf8];
    char frame;
    char pad2[0x2c80 - 0x1a35];
    char entry2c80[0x80];
    short color2d00;
    char pad3[0x2d08 - 0x2d02];
    char entry2d08[0x80];
    short color2d88;
    char pad4[0x2d90 - 0x2d8a];
    Slot02159c88 slots[0x18];
    Obj02159c88 slotModels[24];
    Obj02159c88 dragModel;
    short selected;
    char pad9[0x3da8 - 0x3d7a];
    unsigned char flagA8;
    unsigned char flagA9;
    char padA[1];
    unsigned char flagAB;
    char padB[0x3db8 - 0x3dac];
    unsigned char mode;
    char padC[2];
    signed char cursor;
    unsigned char cursor2;
};

// USA: func_ov005_02159c88
extern "C" ARM void func_ov005_02159c88(Menu02159c88* self) {
    for (int n = 0; n < 0x1f; n++) {
        for (int i = 0; i < 0x18; i++) {
            Slot02159c88* s = &self->slots[i];
            int px, py, cx, cz, dx, dy;
            Obj02159c88* o;
            o = s->obj;
            if (i != self->selected && s->id >= 0) {
                cx = o->pos.x;
                px = s->x;
                py = s->y;
                cz = o->pos.y;
                dx = px - cx;
                dy = py - cz;
                if (dx != 0 || dy != 0) {
                    Vec3_02159c88 t;
                    t.x = (int)((float)cx + 0.01f * (float)dx);
                    t.y = (int)((float)cz + 0.01f * (float)dy);
                    t.z = 0;
                    if (labs(px - t.x) < 0x800 && labs(py - t.y) < 0x800) {
                        t.x = px;
                        t.y = py;
                        t.z = 0;
                    }
                    CopyThreeFields02157174((Dst02157174*)o, (Src02157174*)&t);
                }
            }
        }
    }
    for (int k = 0; k < 24; k++) {
        if (self->slotModels[k].timer < 0x1f)
            self->slotModels[k].timer++;
    }
    if (self->selected >= 0 && self->dragModel.timer < 0x1f)
        self->dragModel.timer = self->dragModel.timer + 1;
    if (self->mode == 0) {
        for (int i = 0; i < 8; i++) {
            Slot02159c88* s = &self->slots[i];
            if (i != self->selected && s->id >= 0) {
                Obj02159c88* o = s->obj;
                Vec3_02159c88 v = o->pos;
                v.y = (i * 0x18) << 12;
                CopyThreeFields02157174((Dst02157174*)o, (Src02157174*)&v);
                G3_MTX_PUSH = 0;
                RenderFlaggedIndexedEntry((StructAt020473c8*)o, 1);
                G3_MTX_POP = 1;
                if (self->flagA8 == 0 && self->flagA9 == 0) {
                    int tx = v.x + REGION(0x11000,0x8000);
                    int ty = v.y + REGION(0x10000,0x8000);
                    int tz = v.z + 0x1000;
                    G3_MTX_PUSH = 0;
                    G3_MTX_TRANS = tx;
                    G3_MTX_TRANS = ty;
                    G3_MTX_TRANS = tz;
                    self->color2d88 = 0xf0a;
                    func_02047554(self->entry2d08, 0, 1);
                    G3_MTX_POP = 1;
                }
            }
        }
    } else {
        for (int i = 0; i < 0x18; i++) {
            Slot02159c88* s = &self->slots[i];
            int c = self->cursor;
            if (i == c && c >= 8 && c < 0x18) {
                int px = s->x;
                int py = s->y;
                Vec3_02159c88 p = s->obj->pos;
                G3_MTX_PUSH = 0;
                G3_MTX_TRANS = px;
                G3_MTX_TRANS = py;
                G3_MTX_TRANS = p.z - 0x1000;
                self->color2d00 = 0x25f;
                RenderFlaggedIndexedEntry((StructAt020473c8*)self->entry2c80, 1);
                G3_MTX_POP = 1;
            }
            int id = s->id;
            if (id >= 0) {
                void* elem = FindElementByKey020dedd0((Container020dedd0*)self->container, (short)id);
                if (elem != 0) {
                    Obj02159c88* o = s->obj;
                    GameResources* res = func_ov017_0218b5b0();
                    MemberScreen* holder = GetField1c_021a193c((int*)res->unknown_ptr_array_36fc[3]);
                    if (func_020dd4c4(holder->member, elem) != 0) {
                        int px = s->x;
                        int py = s->y;
                        Vec3_02159c88 p = o->pos;
                        if (i >= 8 && i < 0x18) {
                            G3_MTX_PUSH = 0;
                            G3_MTX_TRANS = px;
                            G3_MTX_TRANS = py;
                            G3_MTX_TRANS = p.z - 0x1000;
                            self->color2d00 = 0x1ce7;
                            RenderFlaggedIndexedEntry((StructAt020473c8*)self->entry2c80, 1);
                            G3_MTX_POP = 1;
                        }
                        o->color = 0x3def;
                    } else {
                        o->color = 0x7fff;
                    }
                }
                if (i != self->selected) {
                    Obj02159c88* o = s->obj;
                    if (i == self->cursor2 || i >= 8) {
                        G3_MTX_PUSH = 0;
                        RenderFlaggedIndexedEntry((StructAt020473c8*)o, 1);
                        G3_MTX_POP = 1;
                        if (i < 8) {
                            if (self->flagA8 == 0 && self->flagA9 == 0) {
                                Vec3_02159c88 v = o->pos;
                                G3_MTX_PUSH = 0;
                                G3_MTX_TRANS = v.x + REGION(0x11000,0x8000);
                                G3_MTX_TRANS = v.y + REGION(0x10000,0x8000);
                                G3_MTX_TRANS = v.z + 0x1000;
                                self->color2d88 = 0xf0a;
                                func_02047554(self->entry2d08, 0, 1);
                                G3_MTX_POP = 1;
                            }
                        }
                    }
                }
            }
        }
    }
    if (self->selected >= 0 && self->flagAB == 0) {
        G3_MTX_PUSH = 0;
        RenderFlaggedIndexedEntry((StructAt020473c8*)&self->dragModel, 1);
        G3_MTX_POP = 1;
        Vec3_02159c88 v = self->dragModel.pos;
        func_ov005_02154d18(&self->frame, v.x, v.y);
        func_ov005_02154d34(&self->frame, v.x, v.y);
        func_ov005_02154d50(&self->frame, 0x18000, 0x18000);
        func_ov005_02154d7c(&self->frame, 0x18000, 0x18000);
        if (self->selected < 8 && self->flagAB == 0) {
            Vec3_02159c88 w = self->dragModel.pos;
            G3_MTX_PUSH = 0;
            G3_MTX_TRANS = w.x + REGION(0x11000,0x8000);
            G3_MTX_TRANS = w.y + REGION(0x10000,0x8000);
            G3_MTX_TRANS = w.z + 0x1000;
            self->color2d88 = 0xf0a;
            func_02047554(self->entry2d08, 0, 1);
            G3_MTX_POP = 1;
        }
    }
}
