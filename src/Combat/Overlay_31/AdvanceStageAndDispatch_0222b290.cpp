#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int a);
int IsField19ZeroOrNull_02222e54(void);
extern "C" void func_ov031_02226f18(int a);
extern "C" void func_ov031_02222bdc(void);
void* TailCallElemAtIndex30_0223c7c4(int idx);
extern "C" void func_ov031_02223440(void);
extern "C" void func_ov031_0223cbbc(int a, int b);
void SetField1014_022274d0(int a, int b);
void SetField_022274c0_022274c0(int v);

extern unsigned char data_ov031_02290c80;
extern "C" void func_ov031_02233248(void);
extern "C" void func_ov031_0222b450(void);

// USA: func_ov031_0222b290  (semantic: AdvanceStageAndDispatch_0222b290)
extern "C" ARM void func_ov031_0222b290(void) {
    if (func_ov031_0223c054(0) != 0) return;
    if (data_ov031_02290c80 == 0) {
        if (func_ov031_0223c054(1) != 0) return;
    }

    if (IsField19ZeroOrNull_02222e54() == 0) return;

    func_ov031_02226f18(data_ov031_02290c80 != 0 ? 1 : 0);
    func_ov031_02222bdc();
    TailCallElemAtIndex30_0223c7c4(0);

    if (data_ov031_02290c80 == 0) {
        func_ov031_02223440();
        func_ov031_0223cbbc(1, 1);
    }
    func_ov031_0223cbbc(0, 0x15);

    if (data_ov031_02290c80 == 0) {
        SetField1014_022274d0(2, 1);
        SetField_022274c0_022274c0((int)func_ov031_02233248);
    } else {
        SetField1014_022274d0(0, 0);
        SetField_022274c0_022274c0((int)func_ov031_0222b450);
    }
}
