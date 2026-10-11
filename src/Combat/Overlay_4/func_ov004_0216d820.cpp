#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
void* SetFieldAndClearBufferIfType7_0216b1c4(void* a, int id);
extern "C" void func_ov004_0216afb0(void* obj, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" int func_ov004_0216b2c8(void* obj, int id, int a, int b);
extern "C" int func_ov004_0216b7bc(void* obj, int a, int b, int c);

struct FieldGroup02171034_0216d820 {
#if defined(jpn)
    unsigned char pad0[0x10];
#else
    unsigned char pad0[0xc];
#endif
    int val0c;
};
extern struct FieldGroup02171034_0216d820 data_ov004_02171034;

class VObj0216d820 {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void Notify17(int n); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void Notify31(int n);
};

// USA: func_ov004_0216d820
extern "C" ARM int func_ov004_0216d820(void* a) {
    void* node = func_ov023_021f6880(func_ov011_021849c8(a), 1);
    if (node) {
        *((unsigned char*)node + 0xc) |= 0x8;
    }
    SetFieldAndClearBufferIfType7_0216b1c4(a, 0x12c);

    int v0c = data_ov004_02171034.val0c;

    func_ov004_0216afb0(a, 0x37, 2, 0xd4, 0x3b, 0xa, 0xa, 0xc, 1);
    func_ov004_0216b2c8(a, 0x12c, 0x37, 0);

    VObj0216d820* node2 = (VObj0216d820*)func_ov023_021f6880(func_ov011_021849c8(a), 0x37);
    if (node2) {
        node2->Notify17(0x10);
        node2->Notify31(0x10);
    }

    func_ov004_0216b7bc(a, 0xd4, v0c, 0);
    return 0;
}
