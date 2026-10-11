#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
void* SetFieldAndClearBufferIfType7_0216b1c4(void* a, int id);
extern "C" void func_ov004_0216afb0(void* obj, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" int func_ov004_0216b7bc(void* obj, int a, int b, int c);
extern "C" int func_ov004_0216b2c8(void* obj, int id, int a, int b);
extern "C" void func_ov004_0216b20c(void* a0, int key, int b, int c);

extern unsigned char data_ov004_02171034[];

#if defined(jpn)
#define RESULT_OFFSET 0x10
#else
#define RESULT_OFFSET 0xc
#endif

// USA: func_ov004_0216c750  (semantic: SetupTreasureMapEntriesAndDispatch_0216c750)
extern "C" ARM int func_ov004_0216c750(void* a) {
    void* node = func_ov023_021f6880(func_ov011_021849c8(a), 1);
    if (node != 0) {
        *(unsigned char*)((char*)node + 0xc) |= 8;
    }
    SetFieldAndClearBufferIfType7_0216b1c4(a, 0x12c);

    func_ov004_0216afb0(a, 0x32, 2, 0xd4, 0x36, 0xa, 0xa, 0xc, 1);
    *(int*)&data_ov004_02171034[RESULT_OFFSET] = func_ov004_0216b7bc(a, 0xd4, 0x60, 0);

    func_ov004_0216b2c8(a, 0x12c, 0x32, 0);

    func_ov004_0216b20c(a, 0x32, 0xc9, 0);

    return 0;
}
