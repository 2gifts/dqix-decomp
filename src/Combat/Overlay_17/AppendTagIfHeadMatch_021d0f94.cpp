#include <globaldefs.h>

#if defined(jpn)
enum { kHeadListOffset = 0x4ec, kOwnerFieldOffset = 0x920, kMessageObjectOffset = 0x768 };
#else
enum { kHeadListOffset = 0x6fc, kOwnerFieldOffset = 0xb40, kMessageObjectOffset = 0x7e0 };
#endif

struct SearchStruct0202c1a4;
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);
struct HeadNode02046b24;
int GetHeadNodeIdOrMinusOne(struct HeadNode02046b24** obj);
int GetField12_0217f278(int* obj);

extern "C" void func_ov003_02171fe8(void* base, void* a, void* p, int c, unsigned char byte5);

struct ArgB021d0f94 {
    unsigned char pad4[0x4];
    unsigned char byte4;
    unsigned char byte5;
    unsigned char byte6 : 7;
    unsigned char byte7;
};

// USA: func_ov017_021d0f94
ARM void AppendTagIfHeadMatch_021d0f94(void* a, struct ArgB021d0f94* b, int unused, char* c, struct SearchStruct0202c1a4* d) {
    signed char cur = GetSearchStructCurrentArrEntry(d);
    if (b->byte4 != cur) return;

    struct HeadNode02046b24** list = *(struct HeadNode02046b24***)(c + 0x3000 + kHeadListOffset);
    if (GetHeadNodeIdOrMinusOne(list) != 0x2a) return;

    int* field = *(int**)(c + 0x3000 + kOwnerFieldOffset);
    int val = GetField12_0217f278(field);
    if (val == 0) return;

    func_ov003_02171fe8((char*)val + kMessageObjectOffset, a, &b->byte7, b->byte6, b->byte5);
}
