#include <globaldefs.h>

extern int data_02108760;
extern int data_02109bf4;

unsigned char GetByteFieldAt0xcc_0205ea18(unsigned char* obj);
void SetModeClamped0209ca70(void* obj, int val);
struct Obj0205e9f4;
void SetStateAndDispatch0205e9f4(struct Obj0205e9f4* obj, int state);
struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);

// USA: func_ov002_0215b268
ARM void SyncModeIfChanged0215b268(char* p) {
    unsigned char a = GetByteFieldAt0xcc_0205ea18((unsigned char*)&data_02108760);
    unsigned char b1 = *(unsigned char*)(p + 0x1000 + 0xc2c);
    SetModeClamped0209ca70(&data_02109bf4, b1);
    unsigned char b2 = *(unsigned char*)(p + 0x1000 + 0xc2d);
    SetStateAndDispatch0205e9f4((struct Obj0205e9f4*)&data_02108760, b2);
    unsigned char b3 = *(unsigned char*)(p + 0x1000 + 0xc2d);
    if (a == b3) return;
    DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, 1, 0);
}
