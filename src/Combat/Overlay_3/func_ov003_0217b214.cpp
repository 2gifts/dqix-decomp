#include <globaldefs.h>

struct Cont0207fdf0;
struct Obj0205eaa0;
struct Obj0208203c;

void CallFunc0204c804OnNonMatchingKey(struct Cont0207fdf0* obj, int key);
extern "C" void func_020813ec(void* obj, int key);
short FindMappedMemberId02080468(void* obj, int id);
void SetEntryLowNibbleAndElement02080c68(void* obj, int id, int value);
void ResetWithSub0208203c(struct Obj0208203c* obj);
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
int ComputePositiveCount_02175f90(void* self);
extern "C" void func_ov003_02177938(void* self);
extern "C" void func_ov003_021749c0(char* base);
extern "C" int func_ov003_021765b4(void* self);
extern "C" int func_ov003_021766e8(void* self);

extern struct Obj0205eaa0 data_02108760;

// USA: func_ov003_0217b214
extern "C" ARM void func_ov003_0217b214(char* self) {
    void* elemObj = *(void**)(self + 0x89c);
    int state = *(unsigned char*)(self + 0x1000 + 0x3f);

    if (state == 0) {
        *(short*)(self + 0x1000 + 0x14) = 0;
        *(short*)(self + 0x1000 + 0x16) = 0;
        CallFunc0204c804OnNonMatchingKey((struct Cont0207fdf0*)elemObj, 0);
        (*(unsigned char*)(self + 0x1000 + 0x3f))++;
        return;
    }

    if (state == 1) {
        func_020813ec(elemObj, 0x15);
        *(short*)(self + 0xf00 + 0xfe) = 0x1d;
        if (*(short*)(self + 0x1000 + 0x12) < 0) {
            *(short*)(self + 0x1000 + 0x12) = FindMappedMemberId02080468(elemObj, *(short*)(self + 0xf00 + 0xfe));
        }
        *(short*)((char*)elemObj + 0x36) = *(short*)(self + 0x1000 + 0x12);
        SetEntryLowNibbleAndElement02080c68(elemObj, *(short*)(self + 0xf00 + 0xfe), 0);
        func_020813ec(elemObj, *(short*)(self + 0xf00 + 0xfe));
        ResetWithSub0208203c((struct Obj0208203c*)(self + 0x88c));
        *(void**)(self + 0xff8) = 0;
        (*(unsigned char*)(self + 0x1000 + 0x3f))++;
        func_ov003_02177938(self);
        func_ov003_021749c0(self);
        return;
    }

    if (state == 2) {
        *(void**)(self + 0xff8) = self + 0x1000 + 0x12;
        func_ov003_02177938(self);
        SetEntryLowNibbleAndElement02080c68(elemObj, 0x15, 1);
        if (func_ov003_021765b4(self)) {
            DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
            ResetWithSub0208203c((struct Obj0208203c*)(self + 0x88c));
            *(void**)(self + 0xff8) = 0;
            if (ComputePositiveCount_02175f90(self) == 0) {
                *(short*)(self + 0x1000 + 0x36) = 0x24;
                CallFunc0204c804OnNonMatchingKey((struct Cont0207fdf0*)elemObj, 0);
                *(unsigned char*)(self + 0x1000 + 0x3f) = 0;
                *(unsigned short*)(self + 0x1000 + 0x46) |= 0x20;
                return;
            }
            CallFunc0204c804OnNonMatchingKey((struct Cont0207fdf0*)elemObj, 0);
            *(unsigned char*)(self + 0x1000 + 0x3e) = 8;
            *(unsigned char*)(self + 0x1000 + 0x3f) = 0;
            SetEntryLowNibbleAndElement02080c68(elemObj, *(short*)(self + 0xf00 + 0xfe), 1);
            *(short*)(self + 0xf00 + 0xfc) = *(short*)(self + 0xf00 + 0xfe);
            *(short*)(self + 0x1000 + 0xe) = -1;
            *(short*)(self + 0x1000 + 0x3a) = 1;
            return;
        }
        if (func_ov003_021766e8(self)) {
            CallFunc0204c804OnNonMatchingKey((struct Cont0207fdf0*)elemObj, 0);
            *(unsigned char*)(self + 0x1000 + 0x3e) = 3;
            *(unsigned char*)(self + 0x1000 + 0x3f) = 0;
            *(void**)(self + 0xff8) = 0;
        }
    }
}
