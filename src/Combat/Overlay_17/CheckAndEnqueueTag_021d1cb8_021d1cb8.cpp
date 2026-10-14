#include <globaldefs.h>

struct SearchStruct0202c1a4 {
    char pad[0x1038];
    signed char arr[16];
};

extern "C" int* func_0202ae18(void);
int CheckField0NonZero_0202b7d8(int* obj);
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);
void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct LocalEvt021d1cb8 {
    unsigned char tag;
    char pad[19];
};

// USA: func_ov017_021d1cb8
ARM void CheckAndEnqueueTag_021d1cb8_021d1cb8(void) {
    if (!CheckField0NonZero_0202b7d8(func_0202ae18())) return;
    if (GetSearchStructCurrentArrEntry((struct SearchStruct0202c1a4*)func_0202ae18()) != 0) return;
    void* p = GetData02100044_0202ae24();

    struct LocalEvt021d1cb8 buf;
    buf.tag = 0xb4;
    func_0205e330(p, &buf, 0);
}
