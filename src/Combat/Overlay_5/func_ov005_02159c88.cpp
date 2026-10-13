#include <globaldefs.h>

extern "C" int labs(int);
extern "C" void _Z23CopyThreeFields02157174P11Dst02157174P11Src02157174(void* dst, void* src);
extern "C" void _Z25RenderFlaggedIndexedEntryP16StructAt020473c8i(void* entry, int flag);
extern "C" void func_02047554(void* obj, int val, int param1);
extern "C" void* _Z24FindElementByKey020dedd0P17Container020dedd0i(void* container, short key);
extern "C" char* func_ov017_0218b5b0();
extern "C" char* _Z19GetField1c_021a193cPi(void* p);
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
};

struct Slot02159c88 {
    short id;
    char pad[6];
    Obj02159c88* obj;
    int x;
    int y;
    int pad2[2];
};

struct Timer02159c88 { short t; char pad[0x86]; };

struct Menu02159c88 {
    char pad0[0xdf4];
    void* container;
    char pad1[0x1a34 - 0xdf8];
    char frame;
    char pad2[0x2c80 - 0x1a35];
    char entry2c80[0x80];
    short color2d00;
    char pad3[0x2d08 - 0x2d02];
    char entry2d08[0x80];
    short color2d88;
    char pad4[0x2d90 - 0x2d8a];
    Slot02159c88 slots[0x18];
    char pad5[0x30b2 - (0x2d90 + 0x18 * 0x1c)];
    char pad6[0x3cf0 - 0x30b2];
    char entry3cf0[0x1c];
    Vec3_02159c88 vec;
    char pad7[0x3d72 - 0x3d18];
    short counter;
    char pad8[4];
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
                    _Z23CopyThreeFields02157174P11Dst02157174P11Src02157174(o, &t);
                }
            }
        }
    }
    int k = 0;
    while (k < 0x18) {
        int off = k * 0x88;
        short tv = *(short*)((char*)self + 0x30b2 + off);
        k++;
        if (tv < 0x1f)
            *(short*)((char*)self + 0x30b2 + off) = tv + 1;
    }
    if (self->selected >= 0 && self->counter < 0x1f)
        self->counter = self->counter + 1;
    if (self->mode == 0) {
        for (int i = 0; i < 8; i++) {
            Slot02159c88* s = &self->slots[i];
            if (i != self->selected && s->id >= 0) {
                Obj02159c88* o = s->obj;
                Vec3_02159c88 v = o->pos;
                v.y = (i * 0x18) << 12;
                _Z23CopyThreeFields02157174P11Dst02157174P11Src02157174(o, &v);
                G3_MTX_PUSH = 0;
                _Z25RenderFlaggedIndexedEntryP16StructAt020473c8i(o, 1);
                G3_MTX_POP = 1;
                if (self->flagA8 == 0 && self->flagA9 == 0) {
                    int tx = v.x + 0x8000;
                    int ty = v.y + 0x8000;
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
                _Z25RenderFlaggedIndexedEntryP16StructAt020473c8i(self->entry2c80, 1);
                G3_MTX_POP = 1;
            }
            int id = s->id;
            if (id >= 0) {
                void* elem = _Z24FindElementByKey020dedd0P17Container020dedd0i(self->container, id);
                if (elem != 0) {
                    Obj02159c88* o = s->obj;
                    char* res = func_ov017_0218b5b0();
                    char* holder = _Z19GetField1c_021a193cPi(*(void**)(res + 0x3708));
                    if (func_020dd4c4(*(int*)(holder + 0x4fc), elem) != 0) {
                        int px = s->x;
                        int py = s->y;
                        Vec3_02159c88 p = o->pos;
                        if (i >= 8 && i < 0x18) {
                            G3_MTX_PUSH = 0;
                            G3_MTX_TRANS = px;
                            G3_MTX_TRANS = py;
                            G3_MTX_TRANS = p.z - 0x1000;
                            self->color2d00 = 0x1ce7;
                            _Z25RenderFlaggedIndexedEntryP16StructAt020473c8i(self->entry2c80, 1);
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
                        _Z25RenderFlaggedIndexedEntryP16StructAt020473c8i(o, 1);
                        G3_MTX_POP = 1;
                        if (i < 8) {
                            if (self->flagA8 == 0 && self->flagA9 == 0) {
                                Vec3_02159c88 v = o->pos;
                                G3_MTX_PUSH = 0;
                                G3_MTX_TRANS = v.x + 0x8000;
                                G3_MTX_TRANS = v.y + 0x8000;
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
        _Z25RenderFlaggedIndexedEntryP16StructAt020473c8i(self->entry3cf0, 1);
        G3_MTX_POP = 1;
        Vec3_02159c88 v = self->vec;
        func_ov005_02154d18(&self->frame, v.x, v.y);
        func_ov005_02154d34(&self->frame, v.x, v.y);
        func_ov005_02154d50(&self->frame, 0x18000, 0x18000);
        func_ov005_02154d7c(&self->frame, 0x18000, 0x18000);
        if (self->selected < 8 && self->flagAB == 0) {
            Vec3_02159c88 w = self->vec;
            G3_MTX_PUSH = 0;
            G3_MTX_TRANS = w.x + 0x8000;
            G3_MTX_TRANS = w.y + 0x8000;
            G3_MTX_TRANS = w.z + 0x1000;
            self->color2d88 = 0xf0a;
            func_02047554(self->entry2d08, 0, 1);
            G3_MTX_POP = 1;
        }
    }
}
