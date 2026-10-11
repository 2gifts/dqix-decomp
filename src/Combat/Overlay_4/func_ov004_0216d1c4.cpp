#include <globaldefs.h>
#include "GameState/GameState.h"


void SetByte0x7f70(void* obj, unsigned char value);
extern "C" void func_ov004_0216afb0(void* obj, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" int func_ov004_0216b7bc(void* obj, int a, int b, int c);
void* SetFieldAndClearBufferIfType7_0216b1c4(void* a, int id);
extern "C" int func_ov004_0216b2c8(void* obj, int id, int a, int b);
int SetFieldsIfType7_0216b338(void* a, int id, int val);
extern "C" void func_ov004_0216b20c(void* a0, int key, int b, int c);

struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
extern struct Obj0205eaa0 data_02108760;
extern unsigned char data_ov004_02171034[];

// USA: func_ov004_0216d1c4
// JPN: func_ov004_0216d77c
extern "C" ARM int func_ov004_0216d1c4(void* a) {
    SetByte0x7f70(GameState::GetInstance(), 0);
#if defined(jpn)
    int v0c = *(int*)&data_ov004_02171034[0x10];
#else
    int v0c = *(int*)&data_ov004_02171034[0xc];
#endif

    func_ov004_0216afb0(a, 0x37, 2, 0xd4, 0x39, 0xa, 0xa, 0xc, 1);
    v0c = func_ov004_0216b7bc(a, 0xd4, v0c, 1);
    SetFieldAndClearBufferIfType7_0216b1c4(a, 0x12d);

    func_ov004_0216afb0(a, 0x38, 2, 0xd3, 0x3d, 0xa, 0x6, 0xc, 1);
    func_ov004_0216afb0(a, 0x39, 2, 0xd3, 0x3e, 0xa, 0x14, 0xc, 1);

    for (int i = 0; i < 2; i++) {
        func_ov004_0216b2c8(a, 0x12d, i + 0x38, i);
    }
    SetFieldsIfType7_0216b338(a, 0x12d, 1);

    func_ov004_0216b20c(a, 0x38, 0x97, 0);
    func_ov004_0216b20c(a, 0x39, 0x64, 0);
    func_ov004_0216b7bc(a, 0xd3, v0c, 0);

    DispatchWithShortB4_0205eaa0(&data_02108760, 5, 0);
    return 0;
}
