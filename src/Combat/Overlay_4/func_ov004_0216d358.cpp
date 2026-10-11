#include <globaldefs.h>


extern "C" void func_ov004_0216afb0(void* obj, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" int func_ov004_0216b7bc(void* obj, int a, int b, int c);
void* SetFieldAndClearBufferIfType7_0216b1c4(void* a, int id);
extern "C" int func_ov004_0216b2c8(void* obj, int id, int a, int b);
int SetFieldsIfType7_0216b338(void* a, int id, int val);
extern "C" void func_ov004_0216b20c(void* a0, int key, int b, int c);
extern "C" void* func_ov011_021849c8(void*);

class VObj0216d358 {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16();
    virtual void Method44(int arg);
    virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21();
    virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25();
    virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30();
    virtual void Method7c(int arg);
};
extern "C" VObj0216d358* func_ov023_021f6880(void*, int);

struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
extern struct Obj0205eaa0 data_02108760;
extern unsigned char data_ov004_02171034[];

// USA: func_ov004_0216d358
// JPN: func_ov004_0216d910
extern "C" ARM int func_ov004_0216d358(void* a) {
#if defined(jpn)
    int v0c = *(int*)&data_ov004_02171034[0x10];
#else
    int v0c = *(int*)&data_ov004_02171034[0xc];
#endif

    func_ov004_0216afb0(a, 0x37, 2, 0xd4, 0x3a, 0xa, 0xa, 0xc, 1);
    v0c = func_ov004_0216b7bc(a, 0xd4, v0c, 1);
    SetFieldAndClearBufferIfType7_0216b1c4(a, 0x12d);

    func_ov004_0216afb0(a, 0x38, 2, 0xd3, 0x3d, 0xa, 0x6, 0xc, 1);
    func_ov004_0216afb0(a, 0x39, 2, 0xd3, 0x3e, 0xa, 0x14, 0xc, 1);

    for (int i = 0; i < 2; i++) {
        func_ov004_0216b2c8(a, 0x12d, i + 0x38, i);
    }
    SetFieldsIfType7_0216b338(a, 0x12d, 1);

    VObj0216d358* node = func_ov023_021f6880(func_ov011_021849c8(a), 0x38);
    if (node) {
        node->Method44(9);
        node->Method7c(9);
    }

    func_ov004_0216b20c(a, 0x39, 0x64, 0);
    func_ov004_0216b7bc(a, 0xd3, v0c, 0);

    DispatchWithShortB4_0205eaa0(&data_02108760, 5, 0);
    return 0;
}
