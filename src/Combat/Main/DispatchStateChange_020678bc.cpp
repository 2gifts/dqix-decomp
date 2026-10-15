#include <globaldefs.h>

struct Obj0205eaa0;

extern "C" void func_0206b104(void* obj);
struct Ctx0206b2c8;
void InitOrReinitContext0206b2c8(Ctx0206b2c8*, int, void*);
void InitBigStructVariant0205c840(char* obj);
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
extern char data_02108760;

// USA: func_020678bc  (semantic: DispatchStateChange_020678bc)
extern "C" ARM void func_020678bc(char* self, int state) {
    int idx = *(int*)(self + 0x78);
    unsigned short* table = *(unsigned short**)(self + 0x4c);
    unsigned short value = table[idx];
    int isFF06 = (value == 0xff06);
    int isFF07 = (value == 0xff07);

    switch (state) {
    case 0:
        func_0206b104(self);
        if (!isFF06) {
            DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, 1, 0);
        }
        InitOrReinitContext0206b2c8((Ctx0206b2c8*)self, 0xff14, *(void**)(self + 0x58));
        InitBigStructVariant0205c840(self + 0x90);
        *(unsigned char*)(self + 0x1000 + 0x9cd) = 1;
        *(int*)(self + 0x40) = 0;
        return;
    case 1:
        if (!isFF06 && !isFF07) {
            DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, 1, 0);
        }
    case -2:
        *(int*)(self + 0x954) = 1;
        func_0206b104(self);
        InitOrReinitContext0206b2c8((Ctx0206b2c8*)self, 0xff15, *(void**)(self + 0x58));
        InitBigStructVariant0205c840(self + 0x90);
        *(unsigned char*)(self + 0x1000 + 0x9cd) = 1;
        *(int*)(self + 0x40) = 0;
        return;
    default:
        return;
    }
}
