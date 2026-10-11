#include <globaldefs.h>
#include "System/Matrix.h"

struct Actor021c96c0 {
    unsigned char pad0[0x44];
    Vector3i pos;
    unsigned char pad50[0x130 - 0x50];
    int state;
    unsigned char pad134[0x154 - 0x134];
    int field_154;
    unsigned char pad158[0x166 - 0x158];
    short field_166;
    unsigned char pad168[0x17b - 0x168];
    unsigned char field_17b;
    unsigned char field_17c;
};

struct Lookup021c96c0 {
    int field_0;
    int field_4;
    Actor021c96c0* actor;
};

struct Player021c96c0 {
    unsigned short id;
#if defined(jpn)
    unsigned char pad2[0x444 - 2];
#else
    unsigned char pad2[0x424 - 2];
#endif
    int field_424;
};

struct Evt021c96c0 {
    unsigned char tag;
    unsigned char pad1[3];
    unsigned short id;
    unsigned char kind : 6;
    unsigned char flag6 : 1;
    unsigned char flag7 : 1;
    unsigned char lowNibble : 4;
    signed char highNibble : 4;
    short field8;
    short fieldA;
    int fieldC;
    int field10;
};

struct BitFlag02033f44;

extern "C" Player021c96c0* func_02012fe4(void);
extern "C" int func_ov017_021d446c(void* key, Lookup021c96c0* out, int kind);
extern "C" int func_0202c540(void* search);
extern "C" int func_02018fbc(Player021c96c0* player, Vector3i* v);
int* GetField0xe4IfFlag0x40(BitFlag02033f44* obj);
struct Obj02033834;
extern "C" void _Z21SetVecYByMode02033834P11Obj02033834i(Obj02033834* obj, int arg);
extern "C" void _Z18TrySetMode02076cccPvi(void*, int);

// JPN: func_ov017_021c9b70
// USA: func_ov017_021c96c0
extern "C" ARM void func_ov017_021c96c0(int unused0, Evt021c96c0* evt, int unused2, int unused3, void* search) {
    Player021c96c0* player = func_02012fe4();
    Lookup021c96c0 found;
    if (!func_ov017_021d446c(&evt->id, &found, evt->kind)) return;

    if (evt->kind == 10) {
        found.actor->field_166 = evt->highNibble;
    }

    if (evt->kind == 1) {
        Vector3i v;
        v.x = evt->fieldC;
        v.y = evt->fieldA << 4;
        v.z = evt->field10;
        short angle = evt->field8;
        int f6 = evt->flag6 ? 1 : 0;
        int f7 = evt->flag7 ? 1 : 0;

        if (!(evt->id == player->id && found.actor->state == 1) && !(v.x == 0 && v.y == 0 && v.z == 0)) {
            if (func_0202c540(search)) {
                if (GetField0xe4IfFlag0x40((BitFlag02033f44*)found.actor) == 0) {
                    found.actor->pos = v;
                } else {
                    const Vector3i& src = v;
                    found.actor->pos = src;
                }
            } else {
                found.actor->pos = v;
            }
        }

        if (evt->id == player->id && player->field_424 == 0 && found.actor->state != 1 &&
            !(v.x == 0 && v.y == 0 && v.z == 0)) {
            if (GetField0xe4IfFlag0x40((BitFlag02033f44*)found.actor)) {
                v = found.actor->pos;
            }
            v.y = func_02018fbc(player, &v);
            found.actor->pos = v;
        }

        if (angle != 0) {
            _Z21SetVecYByMode02033834P11Obj02033834i((Obj02033834*)found.actor, angle);
        }
        if (f6) {
            found.actor->field_17b = 1;
        }
        if (f7) {
            found.actor->field_17c = 1;
        }
        if (found.actor->state == 4 || found.actor->state == 5 || found.actor->state == 6) {
            found.actor->field_154 = 0;
        }
    }

    _Z18TrySetMode02076cccPvi(found.actor, evt->kind);
}
