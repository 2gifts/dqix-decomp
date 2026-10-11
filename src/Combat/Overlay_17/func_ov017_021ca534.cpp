#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov017_021b8478(void* obj);
void* GetData02100044(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Slot021ca534 {
    unsigned char pad0[4];
    unsigned short field4;
    unsigned short field6;
    unsigned short field8;
    unsigned short fielda;
    unsigned char padc[0x22 - 0xc];
    unsigned short bitsA : 2;
    unsigned short bitsB : 4;
    unsigned short bitsC : 3;
    unsigned short bitsD : 3;
    unsigned short bitsE : 2;
    unsigned short bitsPad : 2;
    unsigned char field24;
    unsigned char field25;
    unsigned char padTail[0xa4 - 0x26];
};

struct Combatants021ca534 {
    unsigned char pad0[8];
    unsigned short field8;
    unsigned char pad1[0x158 - 0xa];
    Slot021ca534 slots[8];
};

struct Entry021ca534 {
    unsigned char pad0[2];
    unsigned char slotIdx[8];
    unsigned char innerCount : 4;
    unsigned char pad3 : 4;
    unsigned char pad4[0x18 - 0xb];
};

struct Header021ca534 {
    unsigned char field0;
    unsigned char pad0 : 4;
    unsigned char outerCount : 2;
    unsigned char pad1 : 2;
    unsigned char pad2[2];
    Entry021ca534 entries[4];
};

struct Payload021ca534 {
    unsigned short field4;
    unsigned short field6;
    unsigned short bitsA : 2;
    unsigned short bitsB : 4;
    unsigned short bitsC : 3;
    unsigned short bitsD : 3;
    unsigned short bitsE : 2;
    unsigned short bitsPad : 2;
    unsigned char fielda;
    unsigned char fieldb;
    unsigned short fieldc;
    unsigned short fielde;
    unsigned short field10;
    unsigned short field12;
};

struct LocalEvt021ca534 {
    unsigned char tag;
    unsigned char pad0[3];
    Payload021ca534 payload;
};

// JPN: func_ov017_021ca9e4
// USA: func_ov017_021ca534
extern "C" ARM void func_ov017_021ca534(Header021ca534* obj) {
#if defined(jpn)
 enum { regionalOffset = 0x508 };
#else
 enum { regionalOffset = 0x718 };
#endif
    GameState::GetInstance();
    unsigned char* ov = (unsigned char*)func_ov017_0218b5b0();
    void* h = *(void**)(ov + 0x3000 + regionalOffset);
    Combatants021ca534* c = (Combatants021ca534*)func_ov017_021b8478(h);
    void* p = GetData02100044();

    for (int i = 0; i < obj->outerCount; i++) {
        Entry021ca534* e = &obj->entries[i];
        LocalEvt021ca534 buf;
        for (int j = 0; j < e->innerCount; j++) {
            unsigned char v = e->slotIdx[j];
            if (v >= 8) continue;
            Slot021ca534* s = &c->slots[v];
            Payload021ca534* pl = &buf.payload;

            buf.tag = 0x5d;
            pl->field4 = c->field8;
            pl->field6 = e->slotIdx[j] + 0xc0;
            pl->bitsA = (unsigned char)s->bitsA;
            pl->bitsB = (unsigned char)s->bitsB;
            pl->bitsC = (unsigned char)s->bitsC;
            pl->bitsD = (unsigned char)s->bitsD;
            pl->bitsE = (unsigned char)s->bitsE;
            pl->fielda = s->field24;
            pl->fieldb = s->field25;
            pl->fieldc = s->field4;
            pl->fielde = s->field6;
            pl->field10 = s->field8;
            pl->field12 = s->fielda;
            func_0205e330(p, &buf, 0);
        }
    }
}
