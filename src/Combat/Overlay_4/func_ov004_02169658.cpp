#include <globaldefs.h>
#include "GameState/GameState.h"
#if defined(jpn)
#define func_ov023_021f6524 func_ov004_02168f08
#define _Z23GetNodeIfType8_02168a6cPvi func_ov004_02168f70
#define _Z24GetNodeIfType15_02168a38Pvi func_ov004_02168f3c
#define _Z26ClearNodeMaskById_021f6600Pvii func_ov004_02168ed8
#define _Z29DispatchNodeIfState6_021f6680Pvi func_ov004_02168fa4
#define _Z24GetNodeIfType11_02168ad4Pvi func_ov004_0216900c
#define func_ov004_02169b4c func_ov004_0216a044
#endif


struct Grid021f9b30;
struct Triple02169658 { int a, b, c; };

class Node02169658 {
public:
    char pad04[0x8];
    unsigned char flags;
    char pad0d[0x13];
    void* f20;

    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void Apply(struct Triple02169658* t);
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
    virtual void SetVisible(int v);
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
};

struct Ctx02169658 {
    #if defined(jpn)
 char pad[0x18];
#else
 char pad[0x198];
#endif
    unsigned char f198;
};

struct Scene02169658 {
    char pad[0x1be];
    short f1be;
};

unsigned char* GetFieldAt0x150(unsigned char* obj);
extern "C" Node02169658* func_ov023_021f6524(void* ctx, int value);
extern "C" Node02169658* _Z23GetNodeIfType8_02168a6cPvi(void* a, int id);
extern "C" Node02169658* _Z24GetNodeIfType15_02168a38Pvi(void* a, int id);
extern "C" Node02169658* _Z24GetNodeIfType11_02168ad4Pvi(void* a, int id);
extern "C" int _Z26SetCellIfInBounds_021f9b30P12Grid021f9b30sjj(struct Grid021f9b30* self, unsigned short val, unsigned int x, unsigned int y);
extern "C" void _Z26ClearNodeMaskById_021f6600Pvii(void* obj, int id, int mask);
extern "C" void func_ov023_021f9ba8(void* obj, int v);
#if defined(jpn)
extern "C" void* func_ov004_02168fa4(void*, int);
extern "C" void func_ov023_021f809c(void*, void*);
#else
extern "C" int _Z29DispatchNodeIfState6_021f6680Pvi(void* obj, int id);
#endif
extern "C" void func_ov004_02169b4c(void* obj);

extern struct Triple02169658 data_ov004_021700e0;
extern struct Ctx02169658* data_ov004_02171030;

// USA: func_ov004_02169658
extern "C" ARM int func_ov004_02169658(struct Scene02169658* scene) {
    unsigned char* base = GetFieldAt0x150((unsigned char*)GameState::GetInstance()->GetUnknownGameObject()) + 0x3c;
    Node02169658* grid = func_ov023_021f6524(scene, 0x64);
    int i;
    for (i = 0; i < 8; i++) {
        Node02169658* a = _Z23GetNodeIfType8_02168a6cPvi(scene, i + 0xc8);
        Node02169658* b = _Z23GetNodeIfType8_02168a6cPvi(scene, i + 0xd8);
        Node02169658* c = _Z24GetNodeIfType15_02168a38Pvi(scene, i + 0xd0);
        Node02169658* d = _Z24GetNodeIfType15_02168a38Pvi(scene, i + 0xe0);
        if (i == 0) {
            a->f20 = base;
            a->flags &= ~8;
            _Z26SetCellIfInBounds_021f9b30P12Grid021f9b30sjj((struct Grid021f9b30*)grid, (unsigned short)(i + 0xc8), (unsigned short)i, 0);
            a->SetVisible(0);
        } else {
            a->flags |= 8;
            _Z26SetCellIfInBounds_021f9b30P12Grid021f9b30sjj((struct Grid021f9b30*)grid, 0, (unsigned short)i, 0);
            a->SetVisible(0);
        }
        b->flags |= 8;
        c->flags |= 8;
        d->flags |= 8;
    }
    _Z26ClearNodeMaskById_021f6600Pvii(scene, 2, 8);
    func_ov023_021f9ba8(grid, 0);
    _Z26ClearNodeMaskById_021f6600Pvii(scene, 0x14, 4);
#if defined(jpn)
    void* selected = func_ov004_02168fa4(scene, 0x14);
    if (selected) func_ov023_021f809c(selected, scene);
#else
    _Z29DispatchNodeIfState6_021f6680Pvi(scene, 0x14);
#endif
    grid->Refresh(0);
    Node02169658* first = _Z23GetNodeIfType8_02168a6cPvi(scene, 0xc8);
    first->v44(0);
    first->v7c(0);
    Node02169658* n = _Z24GetNodeIfType11_02168ad4Pvi(scene, 2);
    struct Triple02169658 t = data_ov004_021700e0;
    n->Apply(&t);
    data_ov004_02171030->f198 = 1;
    func_ov004_02169b4c(scene);
    scene->f1be = 0;
    return 0;
}
