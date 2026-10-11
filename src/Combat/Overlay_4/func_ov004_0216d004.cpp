#include <globaldefs.h>
#include "GameState/GameState.h"


int GetGlobalField0x1c020421a0(void);
struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
extern struct Obj0205eaa0 data_02108760;
void SetByte0x7f70(void* obj, unsigned char value);
struct Struct020a9ea4;
void ClearStruct020a9ea4(struct Struct020a9ea4* p);
extern "C" void func_ov004_0216afb0(void* obj, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" int func_ov004_0216b2c8(void* obj, int id, int a, int b);
extern "C" int func_ov004_0216b7bc(void* obj, int a, int b, int c);

struct FieldGroup02171034 {
#if defined(jpn)
#else
    unsigned char pad0[2];
#endif
    unsigned char flag2;
#if defined(jpn)
    unsigned char pad1[4];
#else
#endif
    unsigned char state3;
#if defined(jpn)
    unsigned char pad4[6];
#else
    unsigned char pad4[0xc];
#endif
    struct Struct020a9ea4* ptr10;
};
extern struct FieldGroup02171034 data_ov004_02171034;

// USA: func_ov004_0216d004
// JPN: func_ov004_0216d5bc
extern "C" ARM int func_ov004_0216d004(void* a) {
    char* g = (char*)GetGlobalField0x1c020421a0();
#if defined(jpn)
    g[0x1000 + 0x7fb] = 0;
#else
    g[0x1000 + 0x9ca] = 0;
#endif
    DispatchWithShortB4_0205eaa0(&data_02108760, 5, 0);

    SetByte0x7f70((void*)GameState::GetInstance(), 0);
    ClearStruct020a9ea4(data_ov004_02171034.ptr10);
    data_ov004_02171034.flag2 = 1;

    if (data_ov004_02171034.state3 == 4) {
        func_ov004_0216afb0(a, 0x38, 2, 0xd3, 0x3d, 0xc, 0x6, 0xc, 1);
        func_ov004_0216afb0(a, 0x39, 2, 0xd3, 0x3e, 0xc, 0x14, 0xc, 1);
    } else {
        func_ov004_0216afb0(a, 0x38, 2, 0xd3, 0x23, 0xa, 0x6, 0xa, 1);
        func_ov004_0216afb0(a, 0x39, 2, 0xd3, 0x35, 0xa, 0x14, 0xa, 1);
    }

    for (int i = 0; i < 2; i++) {
        func_ov004_0216b2c8(a, 0x12d, i + 0x38, i);
    }
    func_ov004_0216b7bc(a, 0xd3, 0x60, 0);
    return 0;
}
