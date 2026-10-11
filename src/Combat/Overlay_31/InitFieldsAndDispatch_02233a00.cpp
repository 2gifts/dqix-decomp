#include <globaldefs.h>

struct Struct02233a00 {
	unsigned char flag0;
	unsigned char pad[3];
	int field4;
};
extern Struct02233a00 data_ov031_02290cd0;

extern "C" void func_ov031_02233a8c(void);
void GetFields181c_02227520(int* a, int* b);
extern "C" void func_ov031_0222336c(int, int, int);
extern "C" int func_ov031_02223518(void* obj);
extern "C" void func_ov031_022239f4(void);
extern "C" void func_ov031_022235a0(void* arg);
extern "C" void func_ov031_02222b0c(int);
extern "C" void func_ov031_02233b34(void);
extern "C" void func_ov031_02223a64(int);
extern "C" int func_ov031_02236878(int index);
void SetField_022274c0_022274c0(int v);
extern "C" void func_ov031_02233bd4(void);

// USA: func_ov031_02233a00  (semantic: InitFieldsAndDispatch_02233a00)
extern "C" ARM void func_ov031_02233a00(void) {
	data_ov031_02290cd0.flag0 = 0;
	func_ov031_02233a8c();
	int b;
	GetFields181c_02227520(0, &b);
	if (b != 0) goto skipInit;
	func_ov031_0222336c(0x31, 0x31 - 0x32, 0);
skipInit:
	func_ov031_02223518((void*)2);
	if (b != 0) goto skipCall;
	func_ov031_022239f4();
skipCall:
	func_ov031_022235a0((void*)0x2c);
	func_ov031_02222b0c(0);
	func_ov031_02233b34();
	func_ov031_02223a64(0);
	func_ov031_02236878(0xc);
	SetField_022274c0_022274c0((int)func_ov031_02233bd4);
}
