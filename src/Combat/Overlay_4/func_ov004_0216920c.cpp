#include <globaldefs.h>

struct Grid0216920c;

class Node0216920c {
public:
    char pad04[0x8];
    unsigned char flags;
    char pad0d[0x13];
    void* f20;
    char pad24[0x19];
    unsigned char f3d;
    char pad3e[0x1e];
    short f5c;
    short f5e;

    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44(int v);
    virtual void v48();
    virtual void Show(int v);
    virtual void v50();
    virtual void Refresh(int v);
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c(int v);
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void SetValue(int v);
};

struct Entry0216920c {
    char unknown00[6];
    char name[11];
    unsigned char f11;
    unsigned short value : 14;
    unsigned short active : 1;
    char pad14[0x2c - 0x14];
};

struct Table0216920c {
    unsigned char count;
    char pad01[3];
    struct Entry0216920c entries[16];
};

struct Slot0216920c { char pad[0x30]; };

struct Ctx0216920c {
#if defined(jpn)
    char pad00[0x10];
#else
    struct Slot0216920c slots[8];
    char pad180[0x10];
#endif
    struct Table0216920c* table;
    char pad194[4];
    unsigned char f198;
};

struct Scene0216920c {
    char pad[0x1b4];
    int f1b4;
    unsigned int f1b8;
    char pad1bc[2];
    short f1be;
};

extern "C" Node0216920c* func_ov023_021f6524(void* ctx, int value);
extern "C" void _Z26ClearNodeMaskById_021f6600Pvii(void*, int, int);
extern "C" Node0216920c* _Z23GetNodeIfType8_02168a6cPvi(void* a, int id);
extern "C" Node0216920c* _Z24GetNodeIfType15_02168a38Pvi(void* a, int id);
extern "C" void func_02042764(void*, void*, int);
extern "C" int _Z26SetCellIfInBounds_021f9b30P12Grid021f9b30sjj(struct Grid0216920c* self, unsigned short val, unsigned int x, unsigned int y);
extern "C" void func_ov023_021f65d4(void*, int, int);
extern "C" void _Z26SetByteAtOffset60_021f9da0Pvh(void*, unsigned char);
extern "C" void func_ov004_02169b4c(void*);
extern "C" void _Z21DispatchNode_021f6630iiss(int, int, short, short);

extern struct Ctx0216920c* data_ov004_02171030;

#if defined(jpn)
extern "C" Node0216920c* func_ov004_02168f08(void*, int);
extern "C" void func_ov004_02168ed8(void*, int, int);
extern "C" void func_ov004_02168eac(void*, int, int);
extern "C" void func_ov004_0216a044(void*);
struct Dispatch0216920c {
    char pad00[0x104];
    short page;
    short column;
};
extern "C" Dispatch0216920c* func_ov004_02168fa4(void*, int);
extern "C" void func_ov023_021f809c(void*, void*);
#define func_ov023_021f6524 func_ov004_02168f08
#define _Z26ClearNodeMaskById_021f6600Pvii func_ov004_02168ed8
#define func_ov023_021f65d4 func_ov004_02168eac
#define func_ov004_02169b4c func_ov004_0216a044
#endif

// USA: func_ov004_0216920c
extern "C" ARM int func_ov004_0216920c(struct Scene0216920c* scene) {
    struct Table0216920c* table = data_ov004_02171030->table;
    if (!table) return 0;
    Node0216920c* node = func_ov023_021f6524(scene, 0x64);
    short page = node->f5c;
    int hidden = 0;
    short col = node->f5e;
    _Z26ClearNodeMaskById_021f6600Pvii(scene, 2, 8);
    int i;
    for (i = 0; i < 8; i++) {
        Node0216920c* a = _Z23GetNodeIfType8_02168a6cPvi(scene, i + 0xc8);
        Node0216920c* b = _Z23GetNodeIfType8_02168a6cPvi(scene, i + 0xd8);
        Node0216920c* c = _Z24GetNodeIfType15_02168a38Pvi(scene, i + 0xd0);
        Node0216920c* d = _Z24GetNodeIfType15_02168a38Pvi(scene, i + 0xe0);
        struct Entry0216920c* e = &table->entries[page * 8 + i];
        if (e->active) {
#if defined(jpn)
            a->f20 = e->name;
#else
            struct Slot0216920c* slot = &data_ov004_02171030->slots[i];
            func_02042764(e->name, slot, 1);
            a->f20 = slot;
#endif
            c->SetValue(e->value);
            d->SetValue(e->f11);
            d->f3d = 1;
            a->flags &= ~8;
            b->flags &= ~8;
            c->flags &= ~8;
            d->flags &= ~8;
            _Z26SetCellIfInBounds_021f9b30P12Grid021f9b30sjj((struct Grid0216920c*)node, (unsigned short)(i + 0xc8), (unsigned short)i, 0);
            a->Show(3);
        } else {
            a->flags |= 8;
            b->flags |= 8;
            c->flags |= 8;
            d->flags |= 8;
            _Z26SetCellIfInBounds_021f9b30P12Grid021f9b30sjj((struct Grid0216920c*)node, 0, (unsigned short)i, 0);
            a->Show(3);
            hidden++;
        }
    }
    if (hidden == 8) {
        func_ov023_021f65d4(scene, 2, 8);
        _Z26SetByteAtOffset60_021f9da0Pvh(node, 0);
    }
    func_ov023_021f65d4(scene, 0x14, 4);
    data_ov004_02171030->f198 = 0;
    func_ov004_02169b4c(scene);
    node->Refresh(3);
    Node0216920c* first = _Z23GetNodeIfType8_02168a6cPvi(scene, 0xc8);
    first->v44(0xd);
    first->v7c(0xd);
#if defined(jpn)
    Dispatch0216920c* dispatch = func_ov004_02168fa4(scene, 0x14);
    if (dispatch) {
        dispatch->page = page;
        dispatch->column = col;
        func_ov023_021f809c(dispatch, scene);
    }
#else
    _Z21DispatchNode_021f6630iiss((int)scene, 0x14, page, col);
#endif
    if (scene->f1b4 != 0 && scene->f1b8 > 0xf) {
        scene->f1be = 0xf;
    }
    return 0;
}
