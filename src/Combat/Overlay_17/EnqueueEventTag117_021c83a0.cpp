#include <globaldefs.h>
#include "Resource/GameResources.h"

extern "C" GameResources* func_ov017_0218b5b0(void);
extern "C" void* func_ov017_021b8478(void* obj);
void* GetField6b0_021b8470(void* obj);
void* GetData02100044(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Ret021c83a0 {
    unsigned char pad0[5];
    unsigned char field5;
    unsigned char pad1[2];
    unsigned short field8;
};

struct Tail021c83a0 {
    unsigned short field4;
    unsigned char field6;
    unsigned char pad;
    unsigned int field8;
};

struct LocalEvt021c83a0 {
    unsigned char tag;
    unsigned char pad[3];
    Tail021c83a0 tail;
    unsigned char pad2[8];
};

// JPN: func_ov017_021c8850
// USA: func_ov017_021c83a0  (semantic: EnqueueEventTag117_021c83a0)
extern "C" ARM void func_ov017_021c83a0(void) {
#if defined(jpn)
 enum {regionalOffset0=0x508};
#else
 enum {regionalOffset0=0x718};
#endif
    GameResources* ov = func_ov017_0218b5b0();
    void* h = *(void**)((char*)ov + 0x3000 + regionalOffset0);
    Ret021c83a0* r = (Ret021c83a0*)func_ov017_021b8478(h);
    void* work = GetField6b0_021b8470(h);
    void* p = GetData02100044();

    LocalEvt021c83a0 buf;
    buf.tag = 0x75;
    Tail021c83a0* t = &buf.tail;
    t->field4 = r->field8;
    t->field8 = *(unsigned int*)((char*)work + 0x8000 + 0xe20);
    t->field6 = r->field5;
    func_0205e330(p, &buf, 0);
}
