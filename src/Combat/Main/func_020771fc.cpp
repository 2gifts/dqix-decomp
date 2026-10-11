#include <globaldefs.h>

struct Vec3_020771fc {
    int x;
    int y;
    int z;
};

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
    Vec3_020771fc pos44;
    Vec3_020771fc vec50;
    char pad5c[0xae - 0x5c];
    short fae;
    char padb0[2];
    unsigned short fb2;
    unsigned short fb4;
    char padb6[0x139 - 0xb6];
    unsigned char mode;
    char pad13a[0x154 - 0x13a];
    int f154;
    Vec3_020771fc pos158;
    unsigned short f164;
    char pad166[0x17c - 0x166];
    unsigned char f17c;
};

struct Entry_02028bd0;
struct List_020283c0;
struct U16Field0x6_020375f8;
struct Obj02033b68;
struct BitFlag02033f44;
struct Obj02033834;
struct SearchStruct0202c1a4;
struct Probe_02012fe4 {
    unsigned short key;
    char pad2[0x422];
    int f424;
};

extern "C" void* func_0202ae18(void);
extern "C" int func_0202c508(void* g);
extern "C" int Vector3fix_Distance(Vec3_020771fc* a, Vec3_020771fc* b);
extern "C" void Vector3fix_Subtract(Vec3_020771fc* a, Vec3_020771fc* b, Vec3_020771fc* out);
extern "C" int Vector3fix_Length(Vec3_020771fc* v);
extern "C" void Vector3fix_Normalize(Vec3_020771fc* in, Vec3_020771fc* out);
extern "C" int fix32_Atan2(int y, int x);
extern "C" void _ZN8Vector3iaSERKS_(int* a, int* b);
extern "C" int _ZNK8Object3D10GetField06Ev(U16Field0x6_020375f8* obj);
extern "C" int func_020322c0(void* p, int* s);
extern "C" void func_020794f8(Actor_020771fc* obj, int a, int b);
extern "C" Probe_02012fe4* func_02012fe4(void);
extern "C" int func_02018fbc(Probe_02012fe4* p, Vec3_020771fc* d);
extern "C" void func_ov017_021c9400(int id, int slot, int heading, Vec3_020771fc pos, Vec3_020771fc vec, int last);
int GetSearchStructCurrentArrEntry(SearchStruct0202c1a4* s);
int CheckField0NonZero(int* g);
Entry_02028bd0* GetEntryTableBase(void);
Entry_02028bd0* FindInlineEntryById(Entry_02028bd0* base, int key);
TableEntry_020771fc* FindListEntryById(List_020283c0* list, int key);
extern "C" void _Z24SetByteIfChanged02033b68P11Obj02033b68i(Obj02033b68* obj, int value);
void* GetField0xe4IfFlag0x40(BitFlag02033f44* obj);
extern "C" void _Z18TrySetMode02076cccPvi(void* obj, int mode);
extern "C" void _Z21SetVecYByMode02033834P11Obj02033834i(Obj02033834* obj, int value);

// USA: func_020771fc
extern "C" ARM void func_020771fc(Actor_020771fc* obj) {
    void* g = func_0202ae18();
    Vec3_020771fc a = obj->pos44;
    a.y = 0;
    Vec3_020771fc b = obj->pos158;
    b.y = 0;
    int dist = Vector3fix_Distance(&a, &b);
    _Z24SetByteIfChanged02033b68P11Obj02033b68i((Obj02033b68*)obj, 1);
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
        _Z18TrySetMode02076cccPvi(obj, 1);
        obj->f154 = 0;
        obj->f17c = 1;
        if (CheckField0NonZero((int*)g) != 0) {
            func_020794f8(obj, 0, 1);
        }
        return;
    }
    if (p == 0) {
        Vec3_020771fc c;
        Vector3fix_Subtract(&obj->pos158, &a, &c);
        if (Vector3fix_Length(&c) < 0x1000) {
            moved = 1;
            _Z18TrySetMode02076cccPvi(obj, 1);
        }
        Vector3fix_Normalize(&c, &c);
        _Z21SetVecYByMode02033834P11Obj02033834i((Obj02033834*)obj, fix32_Atan2(c.x, c.z));
    }
    if (dist < 0x1000) {
        Vec3_020771fc d = obj->pos44;
        if (func_0202c508(g) != 0) {
            Entry_02028bd0* table = GetEntryTableBase();
            int id = _ZNK8Object3D10GetField06Ev((U16Field0x6_020375f8*)obj);
            Entry_02028bd0* entry = FindInlineEntryById(table, id);
            if (entry != 0) {
                List_020283c0* list = (List_020283c0*)((char*)entry + 0x18);
                if (list != 0) {
                    TableEntry_020771fc* row = FindListEntryById(list, obj->f164);
                    if (row != 0) {
                        d.y = row->y << 0xc;
                        _ZN8Vector3iaSERKS_((int*)&obj->pos44, (int*)&d);
                    }
                }
            }
            Probe_02012fe4* probe = func_02012fe4();
            unsigned short key = probe->key;
            if (key == _ZNK8Object3D10GetField06Ev((U16Field0x6_020375f8*)obj) && probe->f424 == 0) {
                d.y = func_02018fbc(probe, &d);
                _ZN8Vector3iaSERKS_((int*)&obj->pos44, (int*)&d);
            }
        }
        moved = 1;
        _Z18TrySetMode02076cccPvi(obj, 1);
    }
    if (moved == 0) {
        return;
    }
    if (CheckField0NonZero((int*)g) == 0) {
        return;
    }
    if (GetSearchStructCurrentArrEntry((SearchStruct0202c1a4*)g) != 0) {
        return;
    }
    int id = _ZNK8Object3D10GetField06Ev((U16Field0x6_020375f8*)obj);
    int heading = obj->f2;
    int wanted = obj->f4 - 0x70;
    Vec3_020771fc* pos = &obj->pos44;
    Vec3_020771fc* vec = &obj->vec50;
    int slot = wanted % 0xc;
    if (slot >= 0 && slot < 0xc) {
        func_ov017_021c9400(id, slot, heading, *pos, *vec, -1);
    }
}
