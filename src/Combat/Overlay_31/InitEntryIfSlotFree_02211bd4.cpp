#include <globaldefs.h>
#include "System/Memory.h"

struct Entry02211bd4 {
	char pad4[4];
	unsigned short field4;
	unsigned short field6;
	unsigned short field8;
	unsigned short field0xa;
	unsigned char field0xc;
	char pad0xd[0x10 - 0xd];
	int field0x10;
};

struct Glob0224e5b4_02211bd4 { char pad0[4]; Entry02211bd4* field4; };
extern Glob0224e5b4_02211bd4 data_ov031_0224e5b4;

void SetGlobal022496fcField4_02207ce0(int);

// USA: func_ov031_02211bd4  (semantic: InitEntryIfSlotFree_02211bd4)
extern "C" ARM void func_ov031_02211bd4(Entry02211bd4* obj, unsigned short val1, int unused2, int val3) {
	if (data_ov031_0224e5b4.field4 != NULL) return;
	VectorizedMemset(obj, 0, 0x64);
	obj->field8 = val1;
	obj->field0xa = 1;
	obj->field4 = 1;
	obj->field6 = 0;
	obj->field0xc = 0;
	obj->field0x10 = 0;
	data_ov031_0224e5b4.field4 = obj;
	SetGlobal022496fcField4_02207ce0(val3);
}
