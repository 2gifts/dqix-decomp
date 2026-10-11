#include <globaldefs.h>

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" int func_ov017_021b8468(void* obj);
extern "C" void* _Z20GetField6b0_021b8470Pv(void* obj);

struct Ret021c8e70 {
    unsigned char pad0[8];
    unsigned short field8;
};

struct SrcBody021c8e70 {
    unsigned short id;
    unsigned char pad2[6];
    unsigned char values[3];
    unsigned char count;
};

struct Src021c8e70 {
    unsigned char pad0[4];
    SrcBody021c8e70 body;
};

struct SlotEntry021c8e70 {
    unsigned char pad0[0xa];
    unsigned char low : 4;
    unsigned char value : 4;
    unsigned char padB[0x18 - 0xb];
};

struct SlotTable021c8e70 {
    unsigned char field0;
    unsigned char total : 4;
    unsigned char high : 4;
    unsigned char pad2[2];
    SlotEntry021c8e70 entries[1];
};

struct Owner021c8e70 {
    unsigned char pad0[0x81b0];
    SlotTable021c8e70 table;
};

// JPN: func_ov017_021c9320
// USA: func_ov017_021c8e70
extern "C" ARM void func_ov017_021c8e70(int unused0, Src021c8e70* src, int unused2, unsigned char* obj) {
#if defined(jpn)
 enum {regionalOffset=0x508};
#else
 enum {regionalOffset=0x718};
#endif
    SrcBody021c8e70* body;
    int total;
    int i;
    SlotTable021c8e70* table;
    void* h = *(void**)(obj + 0x3000 + regionalOffset);
    Ret021c8e70* r = (Ret021c8e70*)func_ov017_021b8478(h);
    if (!r) return;
    if (!func_ov017_021b8468(h)) return;
    Owner021c8e70* owner = (Owner021c8e70*)_Z20GetField6b0_021b8470Pv(h);
    if (!owner) return;
    if (r->field8 != src->body.id) return;
    table = &owner->table;
    body = &src->body;
    total = 0;
    for (i = 0; i < body->count; i++) {
        SlotEntry021c8e70* e = &table->entries[i];
        e->value = body->values[i];
        total += e->value;
    }
    table->total = (unsigned char)total;
}
