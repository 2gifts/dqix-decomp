#include <globaldefs.h>

void* GetNodeIfType6_0216ae9c(void* a, int id);
extern "C" void func_ov023_021f8120(void* node);
extern "C" void func_ov023_021f7eb8(void* node, void* a, int buf, int mode, int a5, int a6, int a7, int a8, int a9, int a10);
void SetOffset100Fields_021f8960(char* base, short a, short b);
struct Obj_02184ad8;
ARM void SetField1c8True_02184ad8(Obj_02184ad8* obj);

extern unsigned char data_ov004_02171034;

#if defined(jpn)
enum { kModeIndex = 5, kVariantIndex = 0 };
#else
enum { kModeIndex = 3, kVariantIndex = 2 };
#endif

// USA: func_ov004_0216b7bc  (semantic: DispatchByType_0216b7bc)
extern "C" ARM int func_ov004_0216b7bc(void* a, int type, int buf, int d) {
	void* node = GetNodeIfType6_0216ae9c(a, type);
	func_ov023_021f8120(node);
	switch (type) {
	case 0xd4:
		if (((unsigned char*)&data_ov004_02171034)[kModeIndex] == 0 || d == 1) {
			SetOffset100Fields_021f8960((char*)node, 0, 6);
		}
		func_ov023_021f7eb8(node, a, buf, 0, 0x10, 0x20, 8, 0, 1, 0);
		buf += 0x2800;
		break;
	case 0xd3:
		if (((unsigned char*)&data_ov004_02171034)[kModeIndex] == 4) {
			func_ov023_021f7eb8(node, a, buf, 0x19, 0xa, 7, 5, 0, 1, 0);
			buf += 0x460;
		} else if (((unsigned char*)&data_ov004_02171034)[kVariantIndex] == 0) {
			func_ov023_021f7eb8(node, a, buf, 0x19, 0xb, 7, 5, 0, 1, 0);
			buf += 0x460;
		} else if (((unsigned char*)&data_ov004_02171034)[kVariantIndex] == 1) {
			func_ov023_021f7eb8(node, a, buf, 8, 0xa, 0x18, 5, 0, 1, 0);
			buf += 0xf00;
		}
		break;
	case 0x3e8:
		if (((unsigned char*)&data_ov004_02171034)[kModeIndex] == 4) {
			func_ov023_021f7eb8(node, a, buf, 0x19, 0xa, 7, 5, 0, 1, 0);
			buf += 0x460;
		} else if (((unsigned char*)&data_ov004_02171034)[kVariantIndex] == 0) {
			func_ov023_021f7eb8(node, a, buf, 0x19, 0xb, 7, 5, 0, 1, 0);
			buf += 0x460;
		} else if (((unsigned char*)&data_ov004_02171034)[kVariantIndex] == 1) {
			func_ov023_021f7eb8(node, a, buf, 0xc, 0xb, 0x14, 4, 0, 1, 0);
			buf += 0xa00;
		}
		break;
	}
	SetField1c8True_02184ad8((Obj_02184ad8*)a);
	return buf;
}
