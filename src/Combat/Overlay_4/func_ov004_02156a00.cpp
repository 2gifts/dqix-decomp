#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct Data021707c8 { void* f0; void* f4; void* f8; void* fc; };
extern Data021707c8 data_ov004_021707c8;
extern int data_02108760;

struct FooA1698;
extern "C" void _Z24InitAndBuildList020a1698P8FooA1698Pv(struct FooA1698*, void*);
extern "C" void func_020a1614(void* a, int b);
extern "C" void* func_ov011_021845f8(void* a, int b);
extern "C" void* func_ov011_021849c8(void* obj);
extern "C" void* func_ov023_021f6880(void* obj, int a);
extern "C" int func_ov023_021f6f10(void* self);
extern "C" short func_ov023_021f9bc8(void* node);
extern "C" void* func_ov023_021fa598(void* obj);
extern "C" void func_ov023_021f809c(void* obj, void* a);
extern "C" void func_ov004_021561b0(void* a);
extern "C" void __clear(void* dst, int len);
extern "C" ARM int _Z23LoadBattleBlock020ac460Pv(void* dst);
struct Obj021f9bdc;
extern "C" void _Z22DivModField26_021f9bdcP11Obj021f9bdci(struct Obj021f9bdc*, int);
struct Obj0205eaa0;
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(struct Obj0205eaa0*, int, int);
struct TableA68;
void* FindEntryByKey(struct TableA68*, int);

struct Entry02156a00 { unsigned int id : 9; char pad[4]; struct Entry02156a00* next; };
struct Head02156a00 { char pad0[8]; struct Entry02156a00* head; char pad1[4]; unsigned char kind; };
struct Node02156a00 { char pad[0x5c]; short f5c; short f5e; };
struct Prot2_02156a00 { char pad[0x49c]; unsigned char f49c : 1; };
struct Prot02156a00 { char pad[0x150]; struct Prot2_02156a00* f150; };
struct Node66_02156a00 { char pad[0x20]; void* f20; };
struct Node34_02156a00 { char pad[0x104]; short f104; short f106; };

// USA: func_ov004_02156a00
extern "C" ARM int func_ov004_02156a00(void* a1) {
    int bitmap[15];

    func_ov011_021845f8(a1, 4);
    void* obj = func_ov011_021849c8(a1);
    short f5e;
    struct Node02156a00* node = (struct Node02156a00*)func_ov023_021f6880(obj, 3);
    if (node == 0) {
        return 0;
    }
    if (func_ov023_021f6f10(node) != 7) {
        return 0;
    }

    short off = node->f5c * 12;
    f5e = node->f5e;
    int idx = func_ov023_021f9bc8(node) + off;
    short v7 = ((short*)data_ov004_021707c8.f8)[idx];

    struct Prot02156a00* prot = (struct Prot02156a00*)GameState::GetInstance()->GetProtagonist();
    if (((struct Head02156a00*)data_ov004_021707c8.fc)->kind == 0 || ((struct Head02156a00*)data_ov004_021707c8.fc)->kind == 1) {
        _Z24InitAndBuildList020a1698P8FooA1698Pv((struct FooA1698*)data_ov004_021707c8.fc, (void*)(unsigned int)prot->f150->f49c);
    } else if (((struct Head02156a00*)data_ov004_021707c8.fc)->kind == 2) {
        func_020a1614(data_ov004_021707c8.fc, ((struct Head02156a00*)data_ov004_021707c8.fc)->kind);
    }

    memset(data_ov004_021707c8.f4, 0, 0x3c0);
    __clear(bitmap, 0x3c);
    _Z23LoadBattleBlock020ac460Pv(bitmap);

    int count = 0;
    for (struct Entry02156a00* e = ((struct Head02156a00*)data_ov004_021707c8.fc)->head; e != 0; e = e->next) {
        int n = e->id;
        if (bitmap[n / 32] & (1 << (n % 32))) {
            ((short*)data_ov004_021707c8.f4)[count++] = (short)n;
        }
    }

    memcpy(data_ov004_021707c8.f8, data_ov004_021707c8.f4, 0x3c0);
    int sb = 0;
    for (int i = 0; i < 0x1e0; i++) {
        if (v7 == ((short*)data_ov004_021707c8.f8)[i]) {
            sb = i;
            break;
        }
    }

    node->f5c = (short)(sb / 12);
    node->f5e = f5e;
    _Z22DivModField26_021f9bdcP11Obj021f9bdci((struct Obj021f9bdc*)node, (unsigned short)(sb % 12));

    _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((struct Obj0205eaa0*)&data_02108760, 1, 0);

    void* node_a = func_ov023_021f6880(obj, 0xa);
    if (node_a == 0) {
        return 0;
    }
    if (func_ov023_021f6f10(node_a) != 4) {
        return 0;
    }
    void* list = func_ov023_021fa598(node_a);

    void* node_b = func_ov023_021f6880(obj, 0x66);
    if (node_b == 0) {
        return 0;
    }
    if (func_ov023_021f6f10(node_b) != 8) {
        return 0;
    }
    ((struct Node66_02156a00*)node_b)->f20 = FindEntryByKey((struct TableA68*)list, (short)(((struct Head02156a00*)data_ov004_021707c8.fc)->kind + 0x3e7));

    void* node_c = func_ov023_021f6880(obj, 0x34);
    if (node_c == 0) {
        return 0;
    }
    if (func_ov023_021f6f10(node_c) != 6) {
        return 0;
    }
    ((struct Node34_02156a00*)node_c)->f104 = 0;
    ((struct Node34_02156a00*)node_c)->f106 = 1;
    func_ov023_021f809c(node_c, a1);
    func_ov004_021561b0(a1);
    return 0;
}
