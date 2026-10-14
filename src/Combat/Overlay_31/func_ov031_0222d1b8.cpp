#include <globaldefs.h>

extern "C" void func_ov031_02223440(void);

struct FlagObj0222d1b8 { unsigned int flags; };
extern "C" int func_ov031_0223da58(FlagObj0222d1b8*);

ARM void* TailCallElemAtIndex30_0223c7c4(int idx);

typedef void (*Callback_022234d8)(void*, int, int);
extern "C" void func_ov031_022234d8(int a0, Callback_022234d8 cb);
extern "C" int LoadToMainObjStandardPalette(int, int, unsigned int);

extern "C" void func_ov031_0223cbbc(int, int);

void GetFields181c_02227520(int*, int*);
ARM void SetField1014_022274d0(int a, int b);
void SetField181c_0222750c(int, int);
ARM void SetField_022274c0_022274c0(int);

extern "C" void* func_ov031_0222ea24(void);
extern "C" void* func_ov031_0222b644(void);
void* Setup022340c0(void);

extern void* data_ov031_02290c94;
extern "C" unsigned int func_ov031_0223cf70(void**);
extern int data_ov031_0224ba64;

// USA: func_ov031_0222d1b8
#pragma optimize_for_size off
extern "C" ARM void func_ov031_0222d1b8(void) {
    func_ov031_02223440();
    func_ov031_0223da58(*(FlagObj0222d1b8**)((char*)data_ov031_02290c94 + 4));
    TailCallElemAtIndex30_0223c7c4(0);
    func_ov031_022234d8((int)&data_ov031_0224ba64, (Callback_022234d8)LoadToMainObjStandardPalette);
    func_ov031_0223cbbc(1, 1);
    func_ov031_0223cbbc(0, 0x15);

    int a, b;
    GetFields181c_02227520(&a, &b);
    if (b == 0) {
        SetField1014_022274d0(2, 1);
        SetField181c_0222750c(0, a);
        SetField_022274c0_022274c0((int)func_ov031_0222ea24);
    } else {
        if (*((unsigned char*)data_ov031_02290c94 + 0x2a) == 0) {
            SetField1014_022274d0(0, 1);
            SetField181c_0222750c(1, 0);
            SetField_022274c0_022274c0((int)func_ov031_0222b644);
        } else {
            SetField1014_022274d0(0, 0);
            SetField181c_0222750c(0, 1);
            SetField_022274c0_022274c0((int)Setup022340c0);
        }
    }
#if defined(jpn)
    func_ov031_0223cf70((void**)0x02291894);
#else
    func_ov031_0223cf70((void**)0x02290C94);
#endif
}
