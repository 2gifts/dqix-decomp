#include <globaldefs.h>

#if defined(jpn)
enum { backgroundOffset = 0xe80, itemCountsOffset = 0x3d10, tileX = 24, tileWidth = 8 };
#else
enum { backgroundOffset = 0xe84, itemCountsOffset = 0x3d98, tileX = 22, tileWidth = 10 };
#endif

struct BackgroundResourceEntry;
struct Obj0204b8d0 {
    char unknown0[0x10];
    BackgroundResourceEntry* entries;
    unsigned short* destination;
    char unknown18[5];
    unsigned char count;
};
void DispatchEntry0204b8d0(struct Obj0204b8d0*, unsigned int, int, int, short, short, short, short, unsigned short);

struct List0204b0e8;
void FlushAndDispatchList0204b0e8(struct List0204b0e8*, void*);

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
    char pad0[backgroundOffset - 0x244];
    Obj0204b8d0 backgrounds[3];
    char beforeContainer[0x1000 - (backgroundOffset - 0x244) - sizeof(Obj0204b8d0) * 3];
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
    char pad2[itemCountsOffset - 0x3030];
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
        DispatchEntry0204b8d0(&obj->sub.backgrounds[0], 0, tileX, 22, tileX, 22, tileWidth, 2, 0xffff);
    } else {
        unsigned char mode = obj->tab;
        unsigned char* table = obj->GetModeTable();
        unsigned char kind = table[mode];
        unsigned int j = 5;
        if (kind == 1) j = 4;
        else if (kind == 2) j = 2;
        else if (kind == 3) j = 3;
        DispatchEntry0204b8d0(&obj->sub.backgrounds[0], j, 0, 0, tileX, 22, tileWidth, 2, 0xffff);
    }
    FlushAndDispatchList0204b0e8((List0204b0e8*)&obj->sub.backgrounds[0], 0);
    obj->dirty &= ~0x800;
}
