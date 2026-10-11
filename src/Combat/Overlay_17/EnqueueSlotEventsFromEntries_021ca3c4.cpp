// JPN: func_ov017_021ca874
#if defined(jpn)
enum { RegionOffset718 = 0x508 };
#else
enum { RegionOffset718 = 0x718 };
#endif

#include <globaldefs.h>

extern "C" void* func_ov017_0218b5b0(void);
extern "C" void* func_ov017_021b8478(void* obj);
void* GetData02100044(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Slot021ca3c4 {
    unsigned short field0;
    unsigned short field2;
    unsigned char pad4[0x10];
    unsigned int field14;
    unsigned int field18;
    unsigned char padTail[0xa4 - 0x1c];
};

struct Combatants021ca3c4 {
    unsigned char pad0[8];
    unsigned short field8;
    unsigned char pad1[0x158 - 0xa];
    Slot021ca3c4 slots[8];
};

struct Entry021ca3c4 {
    unsigned char pad0[2];
    unsigned char slotIdx[8];
    unsigned char innerCount : 4;
    unsigned char pad3 : 4;
    unsigned char pad4[0x18 - 0xb];
};

struct Header021ca3c4 {
    unsigned char field0;
    unsigned char pad0 : 4;
    unsigned char outerCount : 2;
    unsigned char pad1 : 2;
    unsigned char pad2[2];
    Entry021ca3c4 entries[4];
};

struct Payload021ca3c4 {
    unsigned short field4;
    unsigned short field6;
    unsigned short field8;
    unsigned short fielda;
    unsigned int fieldc;
    unsigned int field10;
};

struct LocalEvt021ca3c4 {
    unsigned char tag;
    unsigned char pad0[3];
    Payload021ca3c4 payload;
};

// USA: func_ov017_021ca3c4  (semantic: EnqueueSlotEventsFromEntries_021ca3c4)
extern "C" ARM void func_ov017_021ca3c4(Header021ca3c4* obj) {
    unsigned char* ov = (unsigned char*)func_ov017_0218b5b0();
    void* h = *(void**)(ov + 0x3000 + RegionOffset718);
    Combatants021ca3c4* c = (Combatants021ca3c4*)func_ov017_021b8478(h);
    void* p = GetData02100044();

    for (int i = 0; i < obj->outerCount; i++) {
        Entry021ca3c4* e = &obj->entries[i];
        LocalEvt021ca3c4 buf;
        for (int j = 0; j < e->innerCount; j++) {
            unsigned char v = e->slotIdx[j];
            if (v >= 8) continue;
            Slot021ca3c4* s = &c->slots[v];
            Payload021ca3c4* pl = &buf.payload;

            buf.tag = 0x5c;
            pl->field4 = c->field8;
            pl->field6 = e->slotIdx[j] + 0xc0;
            pl->field8 = s->field0;
            pl->fielda = s->field2;
            pl->fieldc = s->field14;
            pl->field10 = s->field18;
            func_0205e330(p, &buf, 0);
        }
    }
}
