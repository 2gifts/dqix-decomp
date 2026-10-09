#include <globaldefs.h>
#include "GameState/GameState.h"

void* GetData02100044(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct021c90b4 {
    unsigned short a;
    unsigned short b;
    unsigned short slot : 4;
    short mode : 3;
    unsigned short level : 9;
    short d;
    unsigned char e;
    unsigned char f;
    unsigned short g;
    unsigned short h;
};

struct Rec_021c90f8 {
    unsigned short a;
    short b;
    unsigned short c;
    unsigned short d;
    unsigned short e;
    unsigned char f;
};

extern "C" void _Z18CopyStruct021c90b4P14Struct021c90b4S0_(Struct021c90b4* dst, Struct021c90b4* src);
extern "C" void _Z16CopyRec_021c90f8P12Rec_021c90f8S0_(Rec_021c90f8* dst, Rec_021c90f8* src);

struct FieldMonster {
    Object3D obj3D_;
    unsigned char padAc[0xb8 - 0xac];
    unsigned short fieldB8;
    unsigned char padBa[0x130 - 0xba];
    int field130;
    unsigned char pad134[0x164 - 0x134];
    unsigned short field164;
    unsigned short field166;
    unsigned short field168;
    unsigned short field16a;
    unsigned char pad16c[0x17d - 0x16c];
    unsigned char field17d;
};

struct MonsterMsg {
    unsigned char tag;
    unsigned char pad1[3];
    unsigned char kind : 2;
    unsigned char pad5;
    union {
        Struct021c90b4 info;
        Rec_021c90f8 pos;
    } payload;
};

// USA: func_ov017_021c8f3c
extern "C" ARM void func_ov017_021c8f3c(int index, int mode) {
    Struct021c90b4 info;
    Rec_021c90f8 pos;
    struct MonsterMsg msg;

    struct FieldMonster* m = (struct FieldMonster*)GameState::GetInstance()->GetMaybeFieldMonsterByIndex(index);
    if (m == NULL) {
        return;
    }
    info.a = m->field16a;
    info.mode = mode;
    info.b = m->obj3D_.GetField06();
    info.d = m->obj3D_.unknown_2_;
    info.slot = (unsigned short)((index - 0x70) % 12);
    info.level = m->field168;
    info.e = m->field17d;
    info.g = m->fieldB8;
    info.h = m->field164;
    info.f = m->field166;

    pos.a = m->field16a;
    Vector3i* p = &m->obj3D_.position_;
    pos.c = (short)(p->x >> 7);
    pos.d = (short)(p->y >> 7);
    pos.e = (short)(p->z >> 7);
    pos.b = m->obj3D_.rotation_.y;
    pos.f = m->field130;

    void* data = GetData02100044();
    msg.tag = 0x83;
    msg.kind = 0;
    _Z18CopyStruct021c90b4P14Struct021c90b4S0_(&msg.payload.info, &info);
    func_0205e330(data, &msg, 0);

    msg.tag = 0x83;
    msg.kind = 1;
    _Z16CopyRec_021c90f8P12Rec_021c90f8S0_(&msg.payload.pos, &pos);
    func_0205e330(data, &msg, 0);
}
