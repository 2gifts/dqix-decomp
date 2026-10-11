#include <globaldefs.h>

extern "C" int func_ov031_022270ac(int type, unsigned int flags);
int GetDataValue_022167b8(void);
void SetData02249b54_022167a8(int v);
extern "C" void func_ov031_02227128(void);
extern "C" void func_ov031_022271f0(void);
extern "C" void func_ov031_0223677c(void);
void SetField_022274c0_022274c0(int fn);
extern "C" void func_ov031_02227d94(void);
ARM void RunTwoStepUpdate_0223d0a4(void);
extern "C" void func_ov031_0223e168(int idx);
extern "C" void func_ov031_0223d704(void);
int TryFetchOrDispatch12_0223dfd0(void);
void DelayThenSyncBit0(void);
extern "C" void func_ov031_02227468(void);

extern int data_ov031_0224b608;

struct Ctx02226fe4 {
	unsigned char field0;
	unsigned char field1;
	char pad4[4 - 2];
	void* field4;
	char pad8[0xc - 0x8];
	void (*fieldC)(void);
};
extern Ctx02226fe4 data_ov031_02250c0c;

// USA: func_ov031_02226fe4  (semantic: ConfigureAndRunUpdateLoop_02226fe4)
extern "C" ARM int func_ov031_02226fe4(void* arg0, int type, unsigned int flags) {
	data_ov031_02250c0c.field4 = arg0;
	if (!func_ov031_022270ac(type, flags)) {
		return -1;
	}
	int oldVal = GetDataValue_022167b8();
	SetData02249b54_022167a8((int)&data_ov031_0224b608);
	data_ov031_02250c0c.field1 = 0;
	func_ov031_02227128();
	func_ov031_022271f0();
	func_ov031_0223677c();
	SetField_022274c0_022274c0((int)func_ov031_02227d94);
	int idx = 0;
	do {
		RunTwoStepUpdate_0223d0a4();
		data_ov031_02250c0c.fieldC();
		func_ov031_0223e168(idx);
		func_ov031_0223d704();
		TryFetchOrDispatch12_0223dfd0();
		DelayThenSyncBit0();
	} while (data_ov031_02250c0c.field1 == 0);
	func_ov031_02227468();
	SetData02249b54_022167a8(oldVal);
	return 0;
}
