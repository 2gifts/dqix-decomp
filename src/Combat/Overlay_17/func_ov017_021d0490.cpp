#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "World/ZoneResourceTree.h"

extern "C" void* func_0202ae18(void);
extern "C" void* func_02012fe4(void);
extern "C" int func_0202c508(void* p);
void* GetData02100044(void);
extern "C" void func_0205e330(void* a, void* b, int c);
int GetField5cb0Value(char* obj);
int GetField5cb4Value(char* obj);
int GetField5cb8Value(char* obj);
struct Battle021d0490;
extern "C" Battle021d0490* _Z20GetField6b0_021b8470Pv(void* obj);

struct Obj_021bd3a4;
extern "C" int _Z29HasFlag3orFlag2And9a_021bd3a4P12Obj_021bd3a4(Obj_021bd3a4* obj);

struct Actor021d0490 {
    unsigned char pad0[0x12];
    unsigned char visible;
    unsigned char pad13[0x16 - 0x13];
    unsigned short id;
    unsigned short field_0x18;
    unsigned short field_0x1a;
    unsigned short field_0x1c;
    unsigned char pad1e[0x52 - 0x1e];
    short field_0x52;
#if defined(jpn)
    unsigned char pad54[0x98 - 0x54];
#else
    unsigned char pad54[0x9c - 0x54];
#endif

    unsigned char busy;
};

struct Zone021d0490 {
    unsigned char pad0[2];
    unsigned char field_0x2;
    unsigned char field_0x3;
};

struct ZoneEntry021d0490 {
    unsigned char pad0[2];
    unsigned short field_0x2;
    unsigned char pad4[0xc - 4];
    int field_0xc;
};

struct Mode021d0490 {
    unsigned char pad0[0xc];
    int type;
};

struct Battle021d0490 {
    unsigned char pad0[0x8e14];
    signed char field_0x8e14;
    unsigned char pad8e15[3];
    Mode021d0490* mode;
};

struct Payload021d0490 {
    unsigned char field_0x0;
    unsigned char field_0x1;
    unsigned char field_0x2;
    unsigned char mode : 2;
    unsigned char : 1;
    unsigned char kind : 2;
    unsigned char visible : 1;
    unsigned short field_0x4;
    unsigned short field_0x6;
    unsigned short field_0x8;
    unsigned short field_0xa;
    unsigned short field_0xc;
    unsigned short field_0xe;
};

struct Packet021d0490 {
    unsigned char tag;
    unsigned char pad[3];
    Payload021d0490 payload;
};

static inline Actor021d0490* GetActor(GameResources* r) { return (Actor021d0490*)r->unknown_ptr_array_371c[6]; }
static inline Zone021d0490* GetZone(GameResources* r) { return (Zone021d0490*)r->unknown_ptr_3718; }
static inline Zone021d0490* GetOther(GameResources* r) { return (Zone021d0490*)r->unknown_ptr_array_3afc[13]; }

// JPN: func_ov017_021d0940
// USA: func_ov017_021d0490
extern "C" ARM void func_ov017_021d0490(int mode) {
    GameState* battle = GameState::GetInstance();
    void* link = func_0202ae18();
    unsigned short* data = (unsigned short*)func_02012fe4();
    GameResources* res = func_ov017_0218b5b0();
    Actor021d0490* actor = GetActor(res);
    Zone021d0490* zone = GetZone(res);
    Zone021d0490* other = GetOther(res);
    void* queue = GetData02100044();
    Packet021d0490 packet;
    packet.tag = 0x97;
    Payload021d0490* p = &packet.payload;

    if (func_0202c508(link) != 0) {
        p->mode = mode;
        p->field_0x0 = GetField5cb0Value((char*)battle);
        p->field_0x1 = GetField5cb4Value((char*)battle);
        p->field_0x2 = GetField5cb8Value((char*)battle);
        p->field_0x4 = *data;
        Battle021d0490* field = _Z20GetField6b0_021b8470Pv(zone);

        if (_Z29HasFlag3orFlag2And9a_021bd3a4P12Obj_021bd3a4((Obj_021bd3a4*)actor) && actor->id != 0 && actor->busy == 0) {
            p->kind = 1;
            p->field_0x8 = actor->id;
            p->field_0xa = actor->field_0x52;
            p->field_0xc = actor->field_0x1a;
            p->field_0xe = actor->field_0x18;
            p->field_0x6 = actor->field_0x1c;
            p->visible = actor->visible;
        } else if ((zone->field_0x3 != 0 || (other->field_0x3 != 0 && zone->field_0x2 != 0)) && field != NULL &&
                   field->field_0x8e14 == 0) {
            ZoneEntry021d0490* entry = (ZoneEntry021d0490*)func_ov017_021b8478(zone);
            p->kind = 0;
            p->field_0x8 = entry->field_0xc;
            p->field_0xa = entry->field_0x2;
        } else if (zone->field_0x3 != 0 && field->mode->type == 0x13) {
            p->kind = 1;
            p->field_0x8 = 0x71e8;
            p->field_0xa = 0xffff;
            p->field_0xc = 0x199;
            p->field_0xe = 0x71e8;
            p->visible = 1;
        } else {
            p->kind = 2;
        }
    }
    func_0205e330(queue, &packet, 0);
}
