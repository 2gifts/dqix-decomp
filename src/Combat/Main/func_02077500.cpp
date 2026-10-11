#if defined(jpn)
enum { RegionalOffset = 0x14 };
#else
enum { RegionalOffset = 0x18 };
#endif

#include <globaldefs.h>

struct Entry_02028bd0;
struct List_020283c0;
struct U16Field0x6_020375f8;
struct Struct020372b8;

struct Vec3_02077500 {
    int x;
    int y;
    int z;
};

struct TableEntry_02077500 {
    char pad0[4];
    short x;
    short y;
    short z;
};

struct Actor_02077500 {
    char pad0[2];
    short f2;
    short f4;
    char pad6[0xa8];
    short fae;
    char padb0[2];
    short fb2;
    char padb4[0xa4];
    Vec3_02077500 pos;
    unsigned short entryId;
};

extern Entry_02028bd0* GetEntryTableBase();
extern Entry_02028bd0* FindInlineEntryById(Entry_02028bd0* table, int id);
extern "C" extern int _ZNK8Object3D10GetField06Ev(U16Field0x6_020375f8* obj);
extern "C" extern void _ZN8Object3D24TransitionInheritedAlphaEii(Struct020372b8* obj, int channel, int scale);
extern "C" extern void _ZN8Object3D10EnableFlagEi(unsigned char* obj, unsigned int bits);
extern TableEntry_02077500* FindListEntryById(List_020283c0* list, int id);
extern "C" void func_0202ae18();
extern "C" int func_0202c508();
extern "C" void func_ov017_021c927c(int a, int b, int c, Vec3_02077500 pos, int d, int e, int f);

// USA: func_02077500
// JPN: func_02077500
extern "C" ARM int func_02077500(Actor_02077500* obj) {
    Entry_02028bd0* table = GetEntryTableBase();
    if (table == 0) {
        return 0;
    }
    Entry_02028bd0* entry = FindInlineEntryById(table, _ZNK8Object3D10GetField06Ev((U16Field0x6_020375f8*)obj));
    if (entry == 0) {
        return 0;
    }
    List_020283c0* list = (List_020283c0*)((char*)entry + RegionalOffset);
    if (list == 0) {
        return 0;
    }
    obj->fb2 = 0;
    _ZN8Object3D24TransitionInheritedAlphaEii((Struct020372b8*)obj, 0, 0xfa);
    _ZN8Object3D10EnableFlagEi((unsigned char*)obj, 0x80);
    func_0202ae18();
    if (func_0202c508() != 0) {
        TableEntry_02077500* row = FindListEntryById(list, obj->entryId);
        if (row == 0) {
            return 0;
        }
        obj->pos.x = row->x << 0xc;
        obj->pos.y = row->y << 0xc;
        obj->pos.z = row->z << 0xc;
        int id = _ZNK8Object3D10GetField06Ev((U16Field0x6_020375f8*)obj);
        int wanted = obj->f4 - 0x70;
        int heading = obj->f2;
        Vec3_02077500* pos = &obj->pos;
        int height = obj->fae;
        int slot = wanted % 0xc;
        if (slot >= 0 && slot < 0xc) {
            func_ov017_021c927c(id, slot, heading, *pos, height, 3, -1);
        }
    }
    return 1;
}
