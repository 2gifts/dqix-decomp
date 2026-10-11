#include <globaldefs.h>

struct Vec3 {
    int x;
    int y;
    int z;
};

struct Entry_02028bd0;
struct List_020283c0;
struct Obj02033834;
struct Obj02033b68;
struct SearchStruct0202c1a4;
struct U16Field0x6_020375f8;

struct Row02076fdc {
    unsigned char type;
    char pad1[3];
    short x;
    short y;
    short z;
};

struct Actor02076fdc {
    char pad0[2];
    short f2;
    short f4;
    char pad6[0x44 - 0x6];
    struct Vec3 f44;
    struct Vec3 f50;
    char pad5c[0xb2 - 0x5c];
    unsigned short fb2;
    unsigned short fb4;
    char padb6[0x134 - 0xb6];
    int f134;
    char pad138[1];
    unsigned char f139;
    char pad13a[0x158 - 0x13a];
    struct Vec3 f158;
    unsigned short f164;
    char pad166[0x17d - 0x166];
    unsigned char f17d;
};

extern struct Entry_02028bd0* GetEntryTableBase();
extern struct Entry_02028bd0* FindInlineEntryById(struct Entry_02028bd0* table, int key);
extern struct Row02076fdc* FindListEntryById(struct List_020283c0* list, int key);

extern "C" unsigned short _ZNK8Object3D10GetField06Ev(struct U16Field0x6_020375f8* obj);
extern "C" void Vector3fix_Subtract(struct Vec3* a, struct Vec3* b, struct Vec3* out);
extern "C" int Vector3fix_Length(int* v);
extern "C" void Vector3fix_Normalize(struct Vec3* a, struct Vec3* b);
extern "C" int fix32_Atan2(int x, int z);
extern "C" void _Z21SetVecYByMode02033834P11Obj02033834i(struct Obj02033834* obj, int angle);
extern "C" void _Z24SetByteIfChanged02033b68P11Obj02033b68i(struct Obj02033b68* obj, int value);
extern "C" void _ZN8Object3D11DisableFlagEi(unsigned char* obj, unsigned int mask);
extern "C" void _ZN8Object3D10EnableFlagEi(unsigned char* obj, unsigned int mask);
extern "C" void* func_0202ae18(void);
int CheckField0NonZero(int* obj);
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);
extern "C" int _s32_div_f(int a, int b);
extern "C" void func_ov017_021c9168(int id, int slot, int heading, int type,
        struct Vec3 a, struct Vec3 b, int dir);

// USA: func_02076fdc
extern "C" ARM int func_02076fdc(struct Actor02076fdc* self) {
    struct Entry_02028bd0* table = GetEntryTableBase();
    struct Entry_02028bd0* entry =
        FindInlineEntryById(table, _ZNK8Object3D10GetField06Ev((struct U16Field0x6_020375f8*)self));
    if (entry == 0) {
        return 0;
    }
    struct List_020283c0* list = (struct List_020283c0*)((char*)entry + 0x18);
    if (list == 0) {
        return 0;
    }
    struct Row02076fdc* row = FindListEntryById(list, self->f164);
    if (row == 0) {
        return 0;
    }
    self->f158.x = row->x << 0xc;
    self->f158.y = row->y << 0xc;
    self->f158.z = row->z << 0xc;
    struct Vec3 diff;
    Vector3fix_Subtract(&self->f158, &self->f44, &diff);
    if (Vector3fix_Length((int*)&diff) < 0x1000) {
        return 0;
    }
    Vector3fix_Normalize(&diff, &diff);
    _Z21SetVecYByMode02033834P11Obj02033834i((struct Obj02033834*)self, fix32_Atan2(diff.x, diff.z));
    self->f17d |= 0x40;
    switch (self->f139) {
    case 0:
        self->fb4 = 0;
        self->fb2 = 0;
        break;
    case 1:
        self->fb4 = 0x9a;
        self->fb2 = 0x9a;
        break;
    case 2:
        self->fb4 = 0xe6;
        self->fb2 = 0xe6;
        break;
    case 3:
        self->fb4 = 0x1c2;
        self->fb2 = 0x1c2;
        break;
    }
    _Z24SetByteIfChanged02033b68P11Obj02033b68i((struct Obj02033b68*)self, 1);
    if (self->f134 == 4 || self->f134 == 5 || self->f134 == 6) {
        _ZN8Object3D11DisableFlagEi((unsigned char*)self, 0x80);
    } else {
        _ZN8Object3D10EnableFlagEi((unsigned char*)self, 0x80);
    }
    void* g = func_0202ae18();
    if (CheckField0NonZero((int*)g)) {
        if (GetSearchStructCurrentArrEntry((struct SearchStruct0202c1a4*)g) == 0) {
            int id = _ZNK8Object3D10GetField06Ev((struct U16Field0x6_020375f8*)self);
            int wanted = self->f4;
            wanted -= 0x70;
            int heading = self->f2;
            struct Vec3 a = self->f44;
            struct Vec3 b = self->f50;
            int slot = wanted % 0xc;
            if (slot >= 0 && slot < 0xc) {
                func_ov017_021c9168(id, slot, heading, row->type, a, b, -1);
            }
        }
    }
    return 1;
}
