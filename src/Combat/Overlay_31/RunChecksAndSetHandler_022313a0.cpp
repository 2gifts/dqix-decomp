#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int);
extern unsigned char data_ov031_02290cac;
extern int IsField19ZeroOrNull_02222e54(void);
extern "C" void func_ov031_02222bdc(void);
extern void* TailCallElemAtIndex30_0223c7c4(int);
extern "C" void func_ov031_02223440(void);
extern "C" void func_ov031_0223cbbc(int, int);
extern int CheckStateThenProcess_02227ba4(void);
extern void SetField1014_022274d0(int, int);
extern void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_02233248(void);
extern "C" void func_ov031_02231558(void);

// USA: func_ov031_022313a0
ARM void RunChecksAndSetHandler_022313a0(void) {
	if (func_ov031_0223c054(0) != 0) return;
	if (data_ov031_02290cac == 0) {
		if (func_ov031_0223c054(1) != 0) return;
	}
	if (IsField19ZeroOrNull_02222e54() == 0) return;

	func_ov031_02222bdc();
	TailCallElemAtIndex30_0223c7c4(0);

	if (data_ov031_02290cac == 0) {
		func_ov031_02223440();
		func_ov031_0223cbbc(1, 1);
	}
	func_ov031_0223cbbc(0, 0x15);

	if (data_ov031_02290cac == 0) {
		CheckStateThenProcess_02227ba4();
		SetField1014_022274d0(2, 1);
		SetField_022274c0_022274c0((int)func_ov031_02233248);
	} else {
		SetField1014_022274d0(0, 0);
		SetField_022274c0_022274c0((int)func_ov031_02231558);
	}
}
