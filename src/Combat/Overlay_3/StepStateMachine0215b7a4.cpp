#include <globaldefs.h>



extern "C" void func_ov003_0215b3bc(void* obj);
extern "C" int func_ov003_0215b328(void* obj);
extern "C" void func_ov003_0215c01c(void* obj, int a, int b, int c);

void SetChannelAFlag0205cef8(void* obj);
void SetChannelBFlag0205cf04(void* obj);
void ClearChannelAFlag0205cf10(void* obj);

struct Struct0205cf1c;
void ClearFlagByte0205cf1c(struct Struct0205cf1c* s);

struct Struct_0205c570;
int GetActiveScaledSum0205d794(struct Struct_0205c570* s);

struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);

int CheckStateFlag0215b370(void* obj, int flag);

extern int data_02108760;

// USA: func_ov003_0215b7a4
// JPN: func_ov003_0215cba4
ARM int StepStateMachine0215b7a4(void* p) {
    char* obj = (char*)p;
    unsigned char state = *(unsigned char*)(obj + 0x581);
    if (state == 0) {
        func_ov003_0215b3bc(obj);
        SetChannelAFlag0205cef8(obj + 0xf4);
        SetChannelBFlag0205cf04(obj + 0xf4);
        *(unsigned char*)(obj + 0x581) = *(unsigned char*)(obj + 0x581) + 1;
    }
    if (state == 1) {
        *(unsigned char*)(obj + 0x59f) |= 1;
        int e = GetActiveScaledSum0205d794((struct Struct_0205c570*)(obj + 0xf4));
        *(unsigned char*)(obj + 0x584) = (unsigned char)e;
        if (func_ov003_0215b328(obj) != 0) {
            unsigned char v = *(unsigned char*)(obj + 0x59f);
            int masked = v & ~1;
            *(unsigned char*)(obj + 0x59f) = masked;
            func_ov003_0215c01c(obj, 1, 1, masked);
            DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, 1, 0);
            ClearChannelAFlag0205cf10(obj + 0xf4);
            ClearFlagByte0205cf1c((struct Struct0205cf1c*)(obj + 0xf4));
            *(unsigned char*)(obj + 0x581) = 0;
            signed char idx = *(signed char*)(obj + 0x584);
            return *(signed char*)(obj + idx + 0x58a);
        } else {
            if (CheckStateFlag0215b370(obj, 1) != 0) {
                ClearChannelAFlag0205cf10(obj + 0xf4);
                ClearFlagByte0205cf1c((struct Struct0205cf1c*)(obj + 0xf4));
                *(unsigned char*)(obj + 0x581) = 0;
                return -2;
            }
        }
    }
    return -1;
}
