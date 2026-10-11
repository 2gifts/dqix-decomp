#include <globaldefs.h>

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" void* func_ov017_021b8468(void* obj);
void* GetField6b0_021b8470(void* obj);
void ProcessSlot_02162b90(void* self, int unused1, int c, int unused3, int compareVal, signed char idx6, signed char p2);

struct EventHdr021c6b04 {
    unsigned char pad0[8];
    unsigned short field8;
};

struct LocalEvt021c6b04 {
    unsigned char pad0[4];
    unsigned short field4;
    unsigned short field6;
    unsigned char field8;
    unsigned char field9;
    signed char fieldA;
    signed char fieldB;
};

// JPN: func_ov017_021c6fb4
// USA: func_ov017_021c6b04  (semantic: ApplyEventTagToSlot_021c6b04)
extern "C" ARM void func_ov017_021c6b04(int unused0, LocalEvt021c6b04* evt, int unused2, unsigned char* base) {
#if defined(jpn)
 enum {regionalOffset0=0x508};
#else
 enum {regionalOffset0=0x718};
#endif
    void* table = *(void**)(base + 0x3000 + regionalOffset0);
    EventHdr021c6b04* a = (EventHdr021c6b04*)func_ov017_021b8478(table);
    if (!a) return;
    void* b = func_ov017_021b8468(table);
    if (!b) return;
    void* work = GetField6b0_021b8470(table);
    if (!work) return;
    if (a->field8 != evt->field4) return;
    ProcessSlot_02162b90(b, *(short*)&evt->field4, evt->field6, evt->field8, evt->field9, evt->fieldA, evt->fieldB);
}
