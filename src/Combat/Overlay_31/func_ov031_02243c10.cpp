#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"

struct Struct_02245528;
void SetField34AndClear35_37_02245528(struct Struct_02245528* p, int v);
int ProcessAndClassify_02212cbc(void* p);
extern "C" void func_ov031_022434b4(void);
void FreeIfNonNull_022434e8(void* a, void* b);
void SetGlobalFields_02211b40(void* a, void* b);
extern int data_0211e33c;

struct S02243c10 {
	unsigned char pad0[0x35];
	unsigned char state35;
	unsigned char pad1[0x48 - 0x36];
	void* field48;
	void* field4c;
	unsigned char pad2[0x374 - 0x50];
	unsigned char flags374;
	unsigned char pad2b[0x37c - 0x375];
	void* ptr37c;
	unsigned int size380;
	unsigned char pad3[0x438 - 0x384];
	unsigned char field438;
	unsigned char field439;
};

// USA: func_ov031_02243c10
extern "C" ARM void func_ov031_02243c10(S02243c10* obj) {
	switch (obj->state35) {
	case 0:
		if (!(obj->flags374 & 1) && !(obj->flags374 & 2)) goto skip374;
		if (obj->ptr37c == 0) {
			BackgroundLoader* loader = BackgroundLoader::GetInstance();
			if (loader->GetNumQueuedTasks() > 0) {
				SetField34AndClear35_37_02245528((struct Struct_02245528*)obj, 0);
				return;
			}
			obj->ptr37c = &data_0211e33c;
			obj->size380 = 0x30000;
		}
		memset(obj->ptr37c, 0, obj->size380);
		obj->field48 = obj->ptr37c;
	skip374:
		{
			int v = ProcessAndClassify_02212cbc(obj->field4c);
			obj->field439 = 1;
			if (v == 3) {
				obj->state35 = 8;
				obj->field438 = 1;
			} else {
				obj->state35 = 6;
			}
		}
		break;
	case 6:
		SetGlobalFields_02211b40((void*)func_ov031_022434b4, (void*)FreeIfNonNull_022434e8);
		SetField34AndClear35_37_02245528((struct Struct_02245528*)obj, 2);
		break;
	case 7:
		SetField34AndClear35_37_02245528((struct Struct_02245528*)obj, 0);
		break;
	case 8:
		SetField34AndClear35_37_02245528((struct Struct_02245528*)obj, 0);
		break;
	default:
		break;
	}
}
