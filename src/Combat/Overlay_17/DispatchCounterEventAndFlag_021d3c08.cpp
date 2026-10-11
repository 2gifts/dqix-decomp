// JPN: func_ov017_021d4058
#include <globaldefs.h>

#if defined(jpn)
enum { kRegionalFieldOffset = 0xc };
#else
enum { kRegionalFieldOffset = 0x26c };
#endif

extern "C" int func_0202c508(void* obj);
struct SearchStruct0202c1a4;
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);
void EnqueueEventTag184_021d3bbc(int a, int b, int c, int d);

struct EvtStruct021d3c08 {
    unsigned char pad0[4];
    unsigned char mode;
    signed char idx;
    unsigned char field6;
    unsigned char field7;
};

struct TableEntry021d3c08 {
    unsigned char pad0[8];
    unsigned int counter:7;
    unsigned int rest:25;
    unsigned char pad1[0x1c];
};

struct TableEntryAt8_021d3c08 {
    unsigned int counter:7;
    unsigned int rest:25;
    unsigned char pad0[0x24];
};

// USA: func_ov017_021d3c08  (semantic: DispatchCounterEventAndFlag_021d3c08)
extern "C" ARM void func_ov017_021d3c08(int p0, struct EvtStruct021d3c08* evt, int table, int unused, struct SearchStruct0202c1a4* search) {
    struct TableEntry021d3c08* arr = (struct TableEntry021d3c08*)((char*)table + kRegionalFieldOffset + 0x5c00);
    if (evt->mode == 3 && func_0202c508(search)) {
        if (evt->field6 <= arr[evt->field7].counter) {
            EnqueueEventTag184_021d3bbc(evt->field7, evt->field6, 1, p0);
            struct TableEntryAt8_021d3c08* arr8 = (struct TableEntryAt8_021d3c08*)((char*)arr + 8);
            arr8[evt->field7].counter = arr8[evt->field7].counter - evt->field6;
            return;
        }
        EnqueueEventTag184_021d3bbc(evt->field7, evt->field6, 2, p0);
        return;
    }
    if (evt->mode == 1) {
        if (evt->idx == GetSearchStructCurrentArrEntry(search)) {
            unsigned short* flagp = (unsigned short*)((char*)arr + 0x100 + 0xc);
            *flagp = (*flagp & ~0xe000) | 0x2000;
            return;
        }
        struct TableEntryAt8_021d3c08* arr8 = (struct TableEntryAt8_021d3c08*)((char*)arr + 8);
        arr8[evt->field7].counter = arr8[evt->field7].counter - evt->field6;
        return;
    }
    if (evt->mode == 2) {
        if (evt->idx == GetSearchStructCurrentArrEntry(search)) {
            unsigned short* flagp = (unsigned short*)((char*)arr + 0x100 + 0xc);
            *flagp = (*flagp & ~0xe000) | 0x4000;
        }
    }
}
