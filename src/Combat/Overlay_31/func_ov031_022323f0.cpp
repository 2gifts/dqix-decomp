#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int a);
extern int IsField19ZeroOrNull_02222e54(void);
extern "C" int func_ov031_022358e8(void);
extern "C" void func_ov031_02222bdc(void);
extern void* TailCallElemAtIndex30_0223c7c4(int idx);
extern "C" void func_ov031_02223440(void);
extern "C" void func_ov031_0223cbbc(int a, int b);
extern "C" void func_ov031_022357b4(void);
char* GetOffset400_02235c70(void);
extern "C" void func_ov031_02236094(int a);
void SetField1014_022274d0(int a, int b);
void SetField_022274c0_022274c0(int v);
void SetField181c_0222750c(int, int);
extern "C" void func_ov031_02233248(void);
extern "C" void func_ov031_0222b644(void);

extern unsigned char data_ov031_02290cbc;

// USA: func_ov031_022323f0  (semantic: CheckAndDispatchTag_022323f0)
extern "C" ARM void func_ov031_022323f0(void) {
	if (func_ov031_0223c054(1) != 0) return;
	if (func_ov031_0223c054(0) != 0) return;
	if (IsField19ZeroOrNull_02222e54() == 0) return;

	while (func_ov031_022358e8() == 0) {
	}

	func_ov031_02222bdc();
	TailCallElemAtIndex30_0223c7c4(0);
	func_ov031_02223440();
	func_ov031_0223cbbc(1, 1);
	func_ov031_0223cbbc(0, 0x15);

	if (data_ov031_02290cbc != 1) {
		func_ov031_022357b4();
		unsigned char b = GetOffset400_02235c70()[0xf4];
		func_ov031_02236094(b);
		SetField1014_022274d0(2, 1);
		SetField_022274c0_022274c0((int)func_ov031_02233248);
		return;
	}

	SetField1014_022274d0(0, 1);
	SetField181c_0222750c(0, 0);
	SetField_022274c0_022274c0((int)func_ov031_0222b644);
}
