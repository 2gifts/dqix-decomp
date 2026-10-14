#include <globaldefs.h>

#if defined(jpn)
#define func_ov005_0215a620 func_ov005_0215bb74
#endif

struct Obj0204b8d0;
extern "C" void _Z21DispatchEntry0204b8d0P11Obj0204b8d0jiisssst(struct Obj0204b8d0*, unsigned int, int, int, short, short, short, short, unsigned short);

struct List0204b0e8;
extern "C" void _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv(struct List0204b0e8*, void*);

struct ListNode0215c530
{
    ListNode0215c530* next;
    char pad[4];
    short id;
};

struct Slot0215c530
{
    short item;
    char pad[0x1c - 2];
};

struct Container0215c530
{
    int unk[2];
};

struct Sub0215c530
{
    char pad0[0x1000];
    Container0215c530 container;
    char pad1[0x179c - 0x1000 - sizeof(Container0215c530)];
};

struct EquipmentMenu0215a620
{
    char pad0[0x244];
    Sub0215c530 sub;
    ListNode0215c530* head;
    char pad1[0x2d90 - 0x19e4];
    Slot0215c530 slots[24];
    char pad2[0x3d98 - 0x3030];
    short counts[8];
    char pad3[0x3db8 - 0x3da8];
    unsigned char state;
    unsigned char f3db9;
    char pad4[0x3dbb - 0x3dba];
    signed char selected;
    unsigned char tab;
    signed char page;
    char pad5;
    signed char prevPage;
    char pad6[0x3dcc - 0x3dc0];
    unsigned int dirty;
    char pad7[0x3dd4 - 0x3dd0];
    unsigned char modes[8];
    typedef unsigned char Modes[8];
    Modes& GetModeTable() { return modes; }
};



// USA: func_ov005_0215a620
extern "C" ARM void func_ov005_0215a620(EquipmentMenu0215a620* obj) {
    if ((obj->dirty & 0x800) == 0) return;

    unsigned char state = obj->state;
    if (!(state != 0 && state != 1)) {
        _Z21DispatchEntry0204b8d0P11Obj0204b8d0jiisssst((struct Obj0204b8d0*)((char*)obj + 0x284 + 0xc00), 0, 0x16, 0x16, 0x16, 0x16, 0xa, 2, 0xffff);
    } else {
        unsigned char mode = obj->tab;
        unsigned char* table = obj->GetModeTable();
        unsigned char kind = table[mode];
        unsigned int j = 5;
        if (kind == 1) j = 4;
        else if (kind == 2) j = 2;
        else if (kind == 3) j = 3;
        _Z21DispatchEntry0204b8d0P11Obj0204b8d0jiisssst((struct Obj0204b8d0*)((char*)obj + 0x284 + 0xc00), j, 0, 0, 0x16, 0x16, 0xa, 2, 0xffff);
    }
    _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv((struct List0204b0e8*)((char*)obj + 0x284 + 0xc00), 0);
    obj->dirty &= ~0x800;
}
