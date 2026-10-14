#include <globaldefs.h>
#include "System/ProcessorContext.h"

struct Q022120f8 {
	int field0;
	unsigned short field4;
	char pad[0x10 - 0x6];
	int field10;
};

struct Struct0224e5b4_022120f8 {
	char pad0[4];
	Q022120f8* field4;
};

extern Struct0224e5b4_022120f8 data_ov031_0224e5b4;
void BumpTag4To5_02216698(void);
extern "C" int func_ov031_02216360(void);
void ReleaseContextPair_022166b4(void);
extern "C" int func_ov031_022130ac(void);

// USA: func_ov031_022120f8  (semantic: SleepUntilReadyOrBumpTag_022120f8)
extern "C" ARM void func_ov031_022120f8(void) {
	Q022120f8* q = data_ov031_0224e5b4.field4;
	if (q == NULL) return;
	if (q->field4 == 1) {
		if (q->field10 == 1) {
			BumpTag4To5_02216698();
			int x;
			do {
				x = func_ov031_02216360();
				x -= 2;
			} while ((unsigned int)x > 2);
			ReleaseContextPair_022166b4();
		}
		data_ov031_0224e5b4.field4 = 0;
		return;
	}
	if (func_ov031_022130ac() == 0) {
		do {
			SleepCurrentContext(0xa);
		} while (func_ov031_022130ac() == 0);
	}
	data_ov031_0224e5b4.field4 = 0;
}
