#include <globaldefs.h>
#include "Resource/GameResources.h"

struct GameState;

enum EquipmentItemId
{
    NoEquipmentItem = -1,
    MaxStoredEquipmentItemId = 0x7fff
};

struct ItemDef0215c530
{
    unsigned int a : 7;
    unsigned int b : 4;
    unsigned int pad0 : 18;
    unsigned int d : 1;
    unsigned int e : 2;
    unsigned int c : 12;
    unsigned int pad1 : 15;
    unsigned int f : 1;
    unsigned int g : 1;
    unsigned int h : 1;
    unsigned int pad2 : 2;
    char pad3[0x20 - 8];
};

struct Item0215c530
{
    ItemDef0215c530* def;
    int f4;
    unsigned int equipType : 4;
    unsigned int pad0 : 28;
    char pad1[0x18 - 0xc];
    short id;
    char pad2[0x20 - 0x1a];
};

struct Entry0215c530
{
    short id;
    unsigned short equipType : 4;
    unsigned short pad0 : 12;
    unsigned int a : 7;
    unsigned int b : 4;
    unsigned int c : 12;
    unsigned int d : 1;
    unsigned int e : 2;
    unsigned int f : 1;
    unsigned int g : 1;
    unsigned int h : 1;
    unsigned int pad1 : 3;
};

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

struct Container020dedd0;
struct Element020de650;
struct Obj021dcae0 {
    char pad0[0x48];
    Container020dedd0* field48;
    Element020de650* field4c;
#if defined(jpn)
    char pad50[0x680];
#else
    char pad50[0x704];
#endif
    int field754;
    char pad758[0x18];
    short field770;
    unsigned short field772;
    unsigned short field774;
    unsigned char field776;
};

struct EntryList021db08c {
    Entry0215c530* entries;
    unsigned short unknown4;
    unsigned short count;
};

struct Menu0215c530
{
#if defined(jpn)
    char pad0[0x1240];
#else
    char pad0[0x1244];
#endif
    Obj021dcae0 container;
#if defined(jpn)
    char beforeHead[0x1958 - 0x1240 - sizeof(Obj021dcae0)];
#else
    char beforeHead[0x19e0 - 0x1244 - sizeof(Obj021dcae0)];
#endif
    ListNode0215c530* head;
    char pad1[8];
    EntryList021db08c entryList;
    char cursor[0x2d90 - 0x19f4];
    Slot0215c530 slots[24];
    char pad2[0x3d98 - 0x3030];
    short counts[8];
    char pad3[2];
    unsigned char pageStep;
    char pad3b[0x3db9 - 0x3dab];
    unsigned char lastState;
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
};

struct Member0215c530
{
#if defined(jpn)
    char pad[0x4f8];
#else
    char pad[0x4fc];
#endif
    int member;
};

struct StructDE1D4;
struct Obj0205eaa0;

extern "C" GameState* _ZN9GameState11GetInstanceEv();
unsigned char* GetPtrField0x2a04(GameState*);
short* GetPointerFromArray0xbd0(unsigned char*, unsigned int);
signed char* GetPointerAt0xbf0(void*, unsigned int);
void Compact0207c51c(unsigned char*, int);
void ClearElements_021e1518(void*);
void BuildChain_021e1b5c(void*, int, int, int);
void BuildChain_021e1b0c(void*, int, int, int);
Member0215c530* GetField1c_021a193c(int*);
void InitStruct020de1d4(StructDE1D4*);
extern "C" void* memset(void*, int, unsigned int);
extern "C" void* memcpy(void*, const void*, unsigned int);
Entry0215c530* FindEntryById_021db08c(void*, int);
extern "C" int func_020dd4c4(int, Item0215c530*);
extern "C" void func_ov005_021579ec(Menu0215c530*, unsigned int, unsigned char);
extern "C" void func_0205bb04(void*, int);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(void*, int, int);
extern "C" void func_ov005_021555c0(Menu0215c530*);
extern "C" void func_ov023_021dcae0(Obj021dcae0*, int);
extern "C" void func_ov005_0215792c(Menu0215c530*, unsigned char);

#if defined(jpn)
#define data_ov005_0215cd08 data_ov005_0215e0e8
#define data_ov005_0215cd00 data_ov005_0215e0e0
#endif
extern unsigned char data_ov005_0215cd08[];
extern unsigned char data_ov005_0215cd00[];
extern char data_02108760[];

// USA: func_ov005_0215c530
extern "C" ARM void func_ov005_0215c530(Menu0215c530* self)
{
    unsigned char* bag = GetPtrField0x2a04(_ZN9GameState11GetInstanceEv());
    int count = self->counts[self->tab];
    short* ids = GetPointerFromArray0xbd0(bag + 0x1d4, data_ov005_0215cd08[self->tab]);
    signed char* amounts = GetPointerAt0xbf0(bag + 0x1d4, data_ov005_0215cd08[self->tab]);
    Compact0207c51c(bag + 0x1d4, data_ov005_0215cd00[self->tab]);

    int rebuild = 0;
    int reorder = 0;
    if (self->modes[self->tab] == 0 || self->modes[self->tab] == 1)
    {
        ClearElements_021e1518(&self->head);
        BuildChain_021e1b5c(&self->head, -1, data_ov005_0215cd00[self->tab], -1);
        rebuild = 1;
    }
    else if (self->modes[self->tab] == 3)
    {
        ClearElements_021e1518(&self->head);
        BuildChain_021e1b0c(&self->head, -1, data_ov005_0215cd00[self->tab], -1);
        rebuild = 1;
    }
    else if (self->modes[self->tab] == 2)
    {
        reorder = 1;
        rebuild = 1;
    }

    if (rebuild)
    {
        int target = self->slots[self->selected].item;
        short outIds[0x110];
        unsigned char outAmounts[0x110];
        for (int i = 0; i < 0x110; i++)
        {
            outIds[i] = NoEquipmentItem;
            outAmounts[i] = 0;
        }
        if (!reorder)
        {
            ListNode0215c530* node = self->head;
            int n = 0;
            while (node)
            {
                for (int i = 0; i < count; i++)
                {
                    if (node->id == ids[i])
                    {
                        outIds[n] = ids[i];
                        outAmounts[n] = amounts[i];
                        n++;
                        node = node->next;
                        break;
                    }
                    if (i == count - 1)
                        node = node->next;
                }
            }
        }
        else
        {
            signed char member = GetField1c_021a193c((int*)func_ov017_0218b5b0()->unknown_ptr_array_36fc[3])->member;
            Item0215c530 item;
            ItemDef0215c530 def;
            InitStruct020de1d4((StructDE1D4*)&item);
            memset(&def, 0, 0x20);
            item.def = &def;
            int n = 0;
            int rejected = 0;
            for (int i = 0; i < count; i++)
            {
                short id = ids[i];
                if (id > 0)
                {
                    InitStruct020de1d4((StructDE1D4*)&item);
                    memset(&def, 0, 0x20);
                    Entry0215c530* entry;
                    item.def = &def;
                    entry = FindEntryById_021db08c(&self->entryList, id);
                    if (entry)
                    {
                        item.id = entry->id;
                        item.equipType = entry->equipType;
                        def.a = entry->a;
                        def.b = entry->b;
                        def.c = entry->c;
                        def.d = entry->d;
                        def.e = entry->e;
                        def.f = entry->f;
                        def.g = entry->g;
                        def.h = entry->h;
                    }
                    if (func_020dd4c4(member, &item))
                    {
                        rejected++;
                    }
                    else
                    {
                        outIds[n] = ids[i];
                        outAmounts[n] = amounts[i];
                        n++;
                        ids[i] = NoEquipmentItem;
                        amounts[i] = 0;
                    }
                }
            }
            Compact0207c51c(bag + 0x1d4, data_ov005_0215cd00[self->tab]);
            memcpy(outIds + n, ids, rejected * 2);
            memcpy(outAmounts + n, amounts, rejected);
        }
        memcpy(ids, outIds, count * 2);
        memcpy(amounts, outAmounts, count);

        int sel = self->selected;
        if (sel >= 8 && sel < 0x18)
        {
            int idx = -1;
            for (int i = 0; i < count; i++)
            {
                if (target == ids[i])
                {
                    idx = (short)i;
                    break;
                }
            }
            if (idx >= 0)
            {
                self->prevPage = self->page;
                self->page = idx / 16;
                int old = self->selected;
                self->selected = idx % 16 + 8;
                if (old != self->selected)
                {
                    func_ov005_021579ec(self, 4, (unsigned char)self->selected);
                    func_0205bb04(self->cursor, self->selected - 8);
                }
            }
        }
        _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(data_02108760, 1, 0);
    }

    if (self->modes[self->tab] == 0 || self->modes[self->tab] == 1)
    {
        self->modes[self->tab] = 3;
        self->dirty |= 0x800;
    }
    else if (self->modes[self->tab] == 3)
    {
        self->modes[self->tab] = 2;
        self->dirty |= 0x800;
    }
    else if (self->modes[self->tab] == 2)
    {
        self->modes[self->tab] = 1;
        self->dirty |= 0x800;
    }
    func_ov005_021555c0(self);
    EquipmentItemId item = (EquipmentItemId)self->slots[self->selected].item;
    func_ov023_021dcae0(&self->container, item);
    self->dirty |= 0x40;
    self->pageStep = 0;
    func_ov005_0215792c(self, self->lastState);
}
