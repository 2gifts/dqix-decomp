#include <globaldefs.h>

extern "C" {
    void func_ov017_021acdf4(void*, void*);
    void func_ov017_021a1284(void*, void*);
    void func_ov017_0219e384(void*, void*);
    void func_ov017_021bb1a4(void*, void*);
    void func_ov017_021b8e8c(void*, void*);
    void func_ov017_021ab280(void*, void*);
    void func_ov017_021b790c(void*, void*);
    void func_ov017_021a5600(void*, void*);
    void func_ov017_021bf534(void*, void*);
    void func_ov017_021bacd8(void*, void*);
    void func_ov017_021ba998(void*, void*);
    void func_ov003_0217e3b8(void*, void*);
    void func_ov017_021b2ce8(void*, void*);
    void func_ov017_021b2fac(void*, void*);
    void func_ov017_021b58b8(void*, void*);
    void func_ov017_021b6290(void*, void*);
    void func_ov017_021b688c(void*, void*);
    void func_ov003_0217e6b0(void*, void*);
    void func_ov017_021aa41c(void*, void*);
    void func_ov017_021aa59c(void*, void*);
    void func_ov017_021abba8(void*, void*);
    void func_ov017_021ac3b0(void*, void*);
    void func_ov017_021c01a4(void*, void*);
    void func_ov017_021adcb0(void*, void*);
    void func_ov017_021ae85c(void*, void*);
    void func_ov017_021af66c(void*, void*);
    void func_ov017_021b11d8(void*, void*);
    void func_ov017_021c03a4(void*, void*);
    void func_ov017_021c0850(void*, void*);
    void func_ov003_0217ef58(void*, void*);
    void func_ov017_021b1564(void*, void*);
    void func_ov017_021b1e24(void*, void*);
    void func_ov017_021b228c(void*, void*);
    void func_ov017_021c1404(void*, void*);
    void func_ov017_021c17fc(void*, void*);
    void func_ov017_021c16cc(void*, void*);
    void func_ov017_021bdc34(void*, void*);
    void func_ov017_021be0c4(void*, void*);
    void func_ov017_021bec00(void*, void*);
    void func_ov017_021bf014(void*, void*);
    void func_ov004_0216fa3c(void*, void*);
    void func_ov017_021c1af0(void*, void*);
    void func_ov017_021a86d0(void*, void*);
    void func_ov017_021a9454(void*, void*);
    void func_ov017_021a9768(void*, void*);
    void func_ov017_021a9bf8(void*, void*);
    void func_ov017_021aa1ac(void*, void*);
    void func_ov017_021a6648(void*, void*);
    void func_ov017_021a6c2c(void*, void*);
    void func_ov017_021a7378(void*, void*);
    void func_ov017_021a7e14(void*, void*);
    void func_ov017_021c1e6c(void*, void*);
    void func_020d80b0(void*, void*);
    void func_ov017_021c26ac(void*, void*);
    void func_ov017_021c2784(void*, void*);
    void func_ov017_021c2f3c(void*, void*);
    void func_ov017_021c3194(void*, void*);
    void func_020d9870(void*, void*);
    void func_020d9e44(void*, void*);
    void func_020d9b34(void*, void*);
    void func_020e3c94(void*, void*);
    void func_ov017_021be468(void*, void*);
}

struct Obj021b4710;
void CallIndexedFunc_021b4710(Obj021b4710* p);
void RunBattleTeardownSequence_021acce4(void);
struct Obj020dbcc4;
void FlushOv017Section020dbcc4(struct Obj020dbcc4* obj);
void UpdateEncounterState020dac94(void* objIn);
struct Ctx021a7b38;
void RegisterEntryInList_021a7b38(Ctx021a7b38* self);
struct Obj021aef0c;
void DispatchStateAndMaybeInit_021aef0c(Obj021aef0c* self);
struct Entry021b8c84;
void ApplyOrAdvanceListEntry_021b8c84(Entry021b8c84* obj);

// USA: func_ov017_021a3544
// JPN: func_ov017_021a3fb8
extern "C" ARM void func_ov017_021a3544(void* obj, void* node) {
    if (!node) return;

    switch (*(signed char*)node) {
    case 1:
        func_ov017_021acdf4(node, obj);
        break;
    case 2:
        func_ov017_021a1284(node, obj);
        break;
    case 3:
        func_ov017_0219e384(node, obj);
        break;
    case 5:
        func_ov017_021b8e8c(node, obj);
        break;
    case 10:
        func_ov017_021b790c(node, obj);
        break;
    case 12:
        func_ov017_021a5600(node, obj);
        break;
    case 13:
        func_ov017_021bf534(node, obj);
        break;
    case 14:
        ((void (*)(void*, void*))ApplyOrAdvanceListEntry_021b8c84)(node, obj);
        break;
    case 15:
        func_ov017_021bacd8(node, obj);
        break;
    case 16:
        func_ov017_021ba998(node, obj);
        break;
    case 17:
        func_ov003_0217e3b8(node, obj);
        break;
    case 4:
        func_ov017_021bb1a4(node, obj);
        break;
    case 18:
        func_ov017_021b2ce8(node, obj);
        break;
    case 19:
        func_ov017_021b2fac(node, obj);
        break;
    case 20:
        ((void (*)(void*, void*))CallIndexedFunc_021b4710)(node, obj);
        break;
    case 21:
        func_ov017_021b58b8(node, obj);
        break;
    case 22:
        func_ov017_021b6290(node, obj);
        break;
    case 23:
        func_ov017_021b688c(node, obj);
        break;
    case 24:
        func_ov003_0217e6b0(node, obj);
        break;
    case 25:
        func_ov017_021aa41c(node, obj);
        break;
    case 26:
        func_ov017_021aa59c(node, obj);
        break;
    case 6:
        func_ov017_021ab280(node, obj);
        break;
    case 28:
        func_ov017_021abba8(node, obj);
        break;
    case 30:
        func_ov017_021ac3b0(node, obj);
        break;
    case 31:
        ((void (*)(void*, void*))RunBattleTeardownSequence_021acce4)(node, obj);
        break;
    case 32:
        func_ov017_021c01a4(node, obj);
        break;
    case 33:
        func_ov017_021adcb0(node, obj);
        break;
    case 35:
        func_ov017_021ae85c(node, obj);
        break;
    case 37:
        ((void (*)(void*, void*))DispatchStateAndMaybeInit_021aef0c)(node, obj);
        break;
    case 38:
        func_ov017_021af66c(node, obj);
        break;
    case 39:
        func_ov017_021b11d8(node, obj);
        break;
    case 40:
        func_ov017_021c03a4(node, obj);
        break;
    case 41:
        func_ov017_021c0850(node, obj);
        break;
    case 42:
        func_ov003_0217ef58(node, obj);
        break;
    case 43:
        func_ov017_021b1564(node, obj);
        break;
    case 44:
        func_ov017_021b1e24(node, obj);
        break;
    case 45:
        func_ov017_021b228c(node, obj);
        break;
    case 46:
        func_ov017_021c1404(node, obj);
        break;
    case 47:
        func_ov017_021c17fc(node, obj);
        break;
    case 48:
        func_ov017_021c16cc(node, obj);
        break;
    case 50:
        func_ov017_021bdc34(node, obj);
        break;
    case 51:
        func_ov017_021be0c4(node, obj);
        break;
    case 59:
        func_ov017_021a9bf8(node, obj);
        break;
    case 52:
        func_ov017_021bec00(node, obj);
        break;
    case 53:
        func_ov017_021bf014(node, obj);
        break;
    case 54:
        func_ov004_0216fa3c(node, obj);
        break;
    case 55:
        func_ov017_021c1af0(node, obj);
        break;
    case 56:
        func_ov017_021a86d0(node, obj);
        break;
    case 57:
        func_ov017_021a9454(node, obj);
        break;
    case 58:
        func_ov017_021a9768(node, obj);
        break;
    case 60:
        func_ov017_021aa1ac(node, obj);
        break;
    case 61:
        func_ov017_021a6648(node, obj);
        break;
    case 62:
        func_ov017_021a6c2c(node, obj);
        break;
    case 63:
        func_ov017_021a7378(node, obj);
        break;
    case 64:
        ((void (*)(void*, void*))RegisterEntryInList_021a7b38)(node, obj);
        break;
    case 65:
        func_ov017_021a7e14(node, obj);
        break;
    case 66:
        func_ov017_021c1e6c(node, obj);
        break;
    case 67:
        func_020d80b0(node, obj);
        break;
    case 68:
        func_ov017_021c26ac(node, obj);
        break;
    case 69:
        func_ov017_021c2784(node, obj);
        break;
    case 70:
        func_ov017_021c2f3c(node, obj);
        break;
    case 71:
        func_ov017_021c3194(node, obj);
        break;
    case 72:
        func_020d9870(node, obj);
        break;
    case 73:
        func_020d9e44(node, obj);
        break;
    case 74:
        func_020d9b34(node, obj);
        break;
    case 75:
        ((void (*)(void*, void*))UpdateEncounterState020dac94)(node, obj);
        break;
    case 76:
        ((void (*)(void*, void*))FlushOv017Section020dbcc4)(node, obj);
        break;
    case 77:
        func_020e3c94(node, obj);
        break;
    case 78:
        func_ov017_021be468(node, obj);
        break;
    default:
        break;
    }
}
