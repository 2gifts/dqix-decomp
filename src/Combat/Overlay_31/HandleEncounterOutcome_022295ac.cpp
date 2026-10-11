#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int flag);
int IsField19ZeroOrNull_02222e54(void);
extern "C" void func_ov031_0223da58(void* p);
extern "C" void func_ov031_022238cc(void);
extern "C" void func_ov031_02223440(void);
extern "C" void func_ov031_0223b710(void* p);
extern "C" void func_ov031_0223cbbc(int a, int b);
void SetField1014_022274d0(int a, int b);
void SetField_022274c0_022274c0(int fn);
extern "C" void func_ov031_02228024(void);
extern "C" void func_ov031_02228bac(void);
extern "C" void func_ov031_0222859c(void);
extern "C" void func_ov031_02229e28(void);

struct Ctx02290c5c {
	unsigned char field0;
	unsigned char field1;
	char pad2[2];
	void* field4;
	void* field8;
};
extern Ctx02290c5c data_ov031_02290c5c;

// USA: func_ov031_022295ac  (semantic: HandleEncounterOutcome_022295ac)
extern "C" ARM void func_ov031_022295ac(void) {
	if (func_ov031_0223c054(1)) return;
	if (func_ov031_0223c054(0)) return;
	if (!IsField19ZeroOrNull_02222e54()) return;

	func_ov031_0223da58(data_ov031_02290c5c.field8);
	func_ov031_022238cc();
	func_ov031_02223440();
	func_ov031_0223b710(data_ov031_02290c5c.field4);
	func_ov031_0223cbbc(1, 1);
	func_ov031_0223cbbc(0, 0x14);

	if (data_ov031_02290c5c.field1 == 0) {
		SetField1014_022274d0(0, 0);
		SetField_022274c0_022274c0((int)func_ov031_02228024);
		return;
	}

	switch (data_ov031_02290c5c.field0) {
	case 0:
		SetField1014_022274d0(0, 1);
		SetField_022274c0_022274c0((int)func_ov031_02228bac);
		break;
	case 1:
		SetField1014_022274d0(0, 1);
		SetField_022274c0_022274c0((int)func_ov031_0222859c);
		break;
	case 2:
		SetField1014_022274d0(0, 1);
		SetField_022274c0_022274c0((int)func_ov031_02229e28);
		break;
	}
}
