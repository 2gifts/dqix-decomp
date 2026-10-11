// JPN: func_ov031_0222d998
#include <globaldefs.h>

extern "C" void func_ov031_02223440(void);

struct FlagObj0222d1b8 { unsigned int flags; };
extern "C" int func_ov031_0223da58(FlagObj0222d1b8*);

extern "C" ARM void* _Z30TailCallElemAtIndex30_0223c7c4i(int idx);

typedef void (*Callback_022234d8)(void*, int, int);
extern "C" void func_ov031_022234d8(int a0, Callback_022234d8 cb);
extern "C" int LoadToMainObjStandardPalette(int, int, unsigned int);

extern "C" void func_ov031_0223cbbc(int, int);

extern "C" void _Z22GetFields181c_02227520PiS_(int*, int*);
extern "C" ARM void _Z21SetField1014_022274d0ii(int a, int b);
extern "C" void _Z21SetField181c_0222750cii(int, int);
extern "C" ARM void _Z26SetField_022274c0_022274c0i(int);

extern "C" void* func_ov031_0222ea24(void);
extern "C" void* func_ov031_0222b644(void);
extern "C" void* _Z13Setup022340c0v(void);

extern void* data_ov031_02290c94;
extern "C" unsigned int func_ov031_0223cf70(void**);
extern int data_ov031_0224ba64;

// USA: func_ov031_0222d1b8
#pragma optimize_for_size off
extern "C" ARM void func_ov031_0222d1b8(void) {
    func_ov031_02223440();
    func_ov031_0223da58(*(FlagObj0222d1b8**)((char*)data_ov031_02290c94 + 4));
    _Z30TailCallElemAtIndex30_0223c7c4i(0);
    func_ov031_022234d8((int)&data_ov031_0224ba64, (Callback_022234d8)LoadToMainObjStandardPalette);
    func_ov031_0223cbbc(1, 1);
    func_ov031_0223cbbc(0, 0x15);

    int a, b;
    _Z22GetFields181c_02227520PiS_(&a, &b);
    if (b == 0) {
        _Z21SetField1014_022274d0ii(2, 1);
        _Z21SetField181c_0222750cii(0, a);
        _Z26SetField_022274c0_022274c0i((int)func_ov031_0222ea24);
    } else {
        if (*((unsigned char*)data_ov031_02290c94 + 0x2a) == 0) {
            _Z21SetField1014_022274d0ii(0, 1);
            _Z21SetField181c_0222750cii(1, 0);
            _Z26SetField_022274c0_022274c0i((int)func_ov031_0222b644);
        } else {
            _Z21SetField1014_022274d0ii(0, 0);
            _Z21SetField181c_0222750cii(0, 1);
            _Z26SetField_022274c0_022274c0i((int)_Z13Setup022340c0v);
        }
    }
#if defined(jpn)
    func_ov031_0223cf70((void**)0x02291894);
#else
    func_ov031_0223cf70((void**)0x02290C94);
#endif
}
