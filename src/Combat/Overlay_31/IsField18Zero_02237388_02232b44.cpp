#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int);
ARM int IsField18Zero_02237388(void);
extern int IsField19ZeroOrNull_02222e54(void);
extern "C" void func_ov031_0223ba20(int a);
extern "C" void func_ov031_022238cc(void);
extern "C" void func_ov031_02223440(void);
extern "C" void func_ov031_0223b710(int a);
typedef void (*Callback_022234d8)(void*, int, int);
extern "C" void func_ov031_022234d8(int a0, Callback_022234d8 cb);
extern "C" extern int LoadToMainObjStandardPalette(int, int, unsigned int);
extern "C" void func_ov031_0223cbbc(int, int);
void SetField1014_022274d0(int, int);
void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_02228024(void);
char* GetOffset400_02235c70(void);
extern "C" void func_ov031_02233248(void);
void SetField181c_0222750c(int, int);
void SetStoredByte1_02230ef0(unsigned char);
extern "C" void func_ov031_0222ea24(void);
extern "C" void func_ov031_02234520(void);
extern "C" int func_ov031_0223cf70(void*);

struct Inner02232b44 {
	int field0;
	int arr1[3];
	int arr2[3];
	unsigned char pad1;
	unsigned char f1d;
};

struct Outer02232b44 {
	unsigned char state;
	unsigned char pad[3];
	Inner02232b44* field4;
};

extern Outer02232b44 data_ov031_02290cc0;
extern int data_ov031_0224bcec;
extern char data_ov031_02290cc4;

// USA: func_ov031_02232b44
extern "C" ARM void func_ov031_02232b44(void) {
	if (func_ov031_0223c054(1) != 0) return;
	if (func_ov031_0223c054(0) != 0) return;
	if (IsField18Zero_02237388() == 0) return;
	if (IsField19ZeroOrNull_02222e54() == 0) return;

	Outer02232b44* outer = &data_ov031_02290cc0;
	unsigned int i = 0;
	do {
		int v = outer->field4->arr1[i];
		if (v != 0) {
			func_ov031_0223ba20(v);
		}
		i++;
	} while (i < 3);
	outer = &data_ov031_02290cc0;
	i = 0;
	do {
		int v = outer->field4->arr2[i];
		if (v != 0) {
			func_ov031_0223ba20(v);
		}
		i++;
	} while (i < 3);

	func_ov031_022238cc();
	func_ov031_02223440();
	func_ov031_0223b710(data_ov031_02290cc0.field4->field0);
	func_ov031_022234d8((int)&data_ov031_0224bcec, (Callback_022234d8)LoadToMainObjStandardPalette);
	func_ov031_0223cbbc(1, 1);
	func_ov031_0223cbbc(0, 0x14);

	if (data_ov031_02290cc0.field4->f1d == 2) {
		SetField1014_022274d0(0, 0);
		SetField_022274c0_022274c0((int)func_ov031_02228024);
	} else {
		switch (data_ov031_02290cc0.state) {
		case 0:
		case 1:
		case 2:
			SetField1014_022274d0(2, 0);
			if (*(unsigned char*)(GetOffset400_02235c70() + 0xe7) == 0xff) {
				SetField_022274c0_022274c0((int)func_ov031_02233248);
			} else {
				SetField181c_0222750c(0, 0);
				SetStoredByte1_02230ef0(0);
				SetField_022274c0_022274c0((int)func_ov031_0222ea24);
			}
			break;
		case 3:
			SetField1014_022274d0(2, 1);
			SetField_022274c0_022274c0((int)func_ov031_02234520);
			break;
		}
	}
	func_ov031_0223cf70(&data_ov031_02290cc4);
}
