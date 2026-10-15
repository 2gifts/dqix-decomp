#include <globaldefs.h>

struct Obj0205eaa0;

extern "C" void func_0206b104(void* obj);
struct Ctx0206b2c8;
void InitOrReinitContext0206b2c8(Ctx0206b2c8*, int, void*);
void InitBigStructVariant0205c840(char* obj);
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
extern char data_02108760;

// USA: func_020679d4  (semantic: HandleActorStateTransition_020679d4)
extern "C" ARM void func_020679d4(char* self, int state) {
    switch (state) {
    case 0:
        func_0206b104(self);
        DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, 1, 0);
        InitOrReinitContext0206b2c8((Ctx0206b2c8*)self, 0xff16, *(void**)(self + 0x58));
        InitBigStructVariant0205c840(self + 0x90);
        *(unsigned char*)(self + 0x1000 + 0x9cd) = 1;
        *(int*)(self + 0x40) = 0;
        return;
    case 1:
        DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, 1, 0);
    case -2:
        *(int*)(self + 0x954) = 1;
        func_0206b104(self);
        InitOrReinitContext0206b2c8((Ctx0206b2c8*)self, 0xff17, *(void**)(self + 0x58));
        InitBigStructVariant0205c840(self + 0x90);
        *(unsigned char*)(self + 0x1000 + 0x9cd) = 1;
        *(int*)(self + 0x40) = 0;
        return;
    default:
        return;
    }
}
