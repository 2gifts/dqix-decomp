#include <globaldefs.h>
#include "World/Object3D.h"

#if defined(jpn)
enum { EntryListOffset = 0x14 };
#else
enum { EntryListOffset = 0x18 };
#endif

struct TableEntry_020771fc {
    char pad0[4];
    short x;
    short y;
    short z;
};

struct Actor_020771fc {
    char pad0[2];
    short f2;
    short f4;
    char pad6[0x3e];
    Vector3i pos44;
    Vector3i vec50;
    char pad5c[0xae - 0x5c];
    short fae;
    char padb0[2];
    unsigned short fb2;
    unsigned short fb4;
    char padb6[0x139 - 0xb6];
    unsigned char mode;
    char pad13a[0x154 - 0x13a];
    int f154;
    Vector3i pos158;
    unsigned short f164;
    char pad166[0x17c - 0x166];
    unsigned char f17c;
};

struct Entry_02028bd0;
struct List_020283c0;
struct Obj02033b68;
struct BitFlag02033f44;
struct Obj02033834;
struct SearchStruct0202c1a4;
struct Probe_02012fe4 {
    unsigned short key;
#if defined(jpn)
    char pad2[0x442];
#else
    char pad2[0x422];
#endif
    int f424;
};

extern "C" void* func_0202ae18(void);
extern "C" int func_0202c508(void* g);
extern "C" int func_020322c0(void* p, int* s);
extern "C" void func_020794f8(Actor_020771fc* obj, int a, int b);
extern "C" Probe_02012fe4* func_02012fe4(void);
extern "C" int func_02018fbc(Probe_02012fe4* p, Vector3i* d);
extern "C" void func_ov017_021c9400(int id, int slot, int heading, Vector3i pos, Vector3i vec, int last);
int GetSearchStructCurrentArrEntry(SearchStruct0202c1a4* s);
int CheckField0NonZero_0202b7d8(int* g);
Entry_02028bd0* GetEntryTableBase_02027ca4(void);
Entry_02028bd0* FindInlineEntryById(Entry_02028bd0* base, int key);
TableEntry_020771fc* FindListEntryById(List_020283c0* list, int key);
void SetByteIfChanged02033b68(Obj02033b68* obj, int value);
void* GetField0xe4IfFlag0x40(BitFlag02033f44* obj);
void TrySetMode02076ccc(void* obj, int mode);
void SetVecYByMode02033834(Obj02033834* obj, int value);

// USA: func_020771fc
extern "C" ARM void func_020771fc(Actor_020771fc* obj) {
    void* g = func_0202ae18();
    Vector3i a = obj->pos44;
    a.y = 0;
    Vector3i b = obj->pos158;
    b.y = 0;
    int dist = Vector3fix_Distance(&a, &b);
    SetByteIfChanged02033b68((Obj02033b68*)obj, 1);
    switch (obj->mode) {
    case 0:
        obj->fb4 = 0;
        obj->fb2 = 0;
        break;
    case 1:
        obj->fb4 = 0x9a;
        obj->fb2 = 0x9a;
        break;
    case 2:
        obj->fb4 = 0xe6;
        obj->fb2 = 0xe6;
        break;
    case 3:
        obj->fb4 = 0x1c2;
        obj->fb2 = 0x1c2;
        break;
    }
    int moved = 0;
    void* p = GetField0xe4IfFlag0x40((BitFlag02033f44*)obj);
    int found = 0;
    if (p != 0) {
        int s = obj->fae;
        if (func_020322c0(p, &s) < 0x199) {
            found = 1;
        }
    }
    if (found != 0) {
        TrySetMode02076ccc(obj, 1);
        obj->f154 = 0;
        obj->f17c = 1;
        if (CheckField0NonZero_0202b7d8((int*)g) != 0) {
            func_020794f8(obj, 0, 1);
        }
        return;
    }
    if (p == 0) {
        Vector3i c;
        Vector3fix_Subtract(&obj->pos158, &a, &c);
        if (Vector3fix_Length(&c) < 0x1000) {
            moved = 1;
            TrySetMode02076ccc(obj, 1);
        }
        Vector3fix_Normalize(&c, &c);
        SetVecYByMode02033834((Obj02033834*)obj, fix32_Atan2(c.x, c.z));
    }
    if (dist < 0x1000) {
        Vector3i d = obj->pos44;
        if (func_0202c508(g) != 0) {
            Entry_02028bd0* table = GetEntryTableBase_02027ca4();
            int id = ((Object3D*)obj)->GetField06();
            Entry_02028bd0* entry = FindInlineEntryById(table, id);
            if (entry != 0) {
                List_020283c0* list = (List_020283c0*)((char*)entry + EntryListOffset);
                if (list != 0) {
                    TableEntry_020771fc* row = FindListEntryById(list, obj->f164);
                    if (row != 0) {
                        d.y = row->y << 0xc;
                        obj->pos44 = d;
                    }
                }
            }
            Probe_02012fe4* probe = func_02012fe4();
            unsigned short key = probe->key;
            if (key == ((Object3D*)obj)->GetField06() && probe->f424 == 0) {
                d.y = func_02018fbc(probe, &d);
                obj->pos44 = d;
            }
        }
        moved = 1;
        TrySetMode02076ccc(obj, 1);
    }
    if (moved == 0) {
        return;
    }
    if (CheckField0NonZero_0202b7d8((int*)g) == 0) {
        return;
    }
    if (GetSearchStructCurrentArrEntry((SearchStruct0202c1a4*)g) != 0) {
        return;
    }
    int id = ((Object3D*)obj)->GetField06();
    int heading = obj->f2;
    int wanted = obj->f4 - 0x70;
    Vector3i* pos = &obj->pos44;
    Vector3i* vec = &obj->vec50;
    int slot = wanted % 0xc;
    if (slot >= 0 && slot < 0xc) {
        func_ov017_021c9400(id, slot, heading, *pos, *vec, -1);
    }
}
