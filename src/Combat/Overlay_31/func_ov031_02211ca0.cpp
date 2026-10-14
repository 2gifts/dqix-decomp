#include <globaldefs.h>
#include "System/Memory.h"

struct Q02211ca0 {
	int field0;
	unsigned short field4;
	unsigned short pad6;
	unsigned short field8;
	unsigned short fielda;
};

struct Glob0224e5b4_02211ca0 {
	char pad0[4];
	Q02211ca0* field4;
};

extern Glob0224e5b4_02211ca0 data_ov031_0224e5b4;

void SetGlobal0224e5a4IfNotNine_ov031_02211b08(int a, int b);
extern "C" int func_ov031_02212d40(void* buf);
void* CallWithConst32_02211b54(void*, void*);
extern "C" void func_ov031_02211b98(void*, void*);

struct Buf02211ca0 {
	void* (*fn0)(void*, void*);
	void (*fn1)(void*, void*);
	unsigned char b8;
	unsigned char b9;
	unsigned char pad[2];
};

// USA: func_ov031_02211ca0  (semantic: DispatchIfStateOne_02211ca0)
#pragma optimize_for_size off
extern "C" ARM void func_ov031_02211ca0(void) {
	Q02211ca0* q = data_ov031_0224e5b4.field4;
	if (q != 0) {
		if (q->field4 == 1) {
			Buf02211ca0 buf;
			VectorizedMemset(&buf, 0, 0xc);

			q = data_ov031_0224e5b4.field4;
			buf.b8 = (unsigned char)q->field8;
			buf.b9 = (unsigned char)q->fielda;
			buf.fn0 = CallWithConst32_02211b54;
			buf.fn1 = func_ov031_02211b98;
			q->field4 = 2;

			if (func_ov031_02212d40(&buf) == 0) {
				SetGlobal0224e5a4IfNotNine_ov031_02211b08(9, 0xffff3be9);
			}
		}
	} else {
		SetGlobal0224e5a4IfNotNine_ov031_02211b08(9, 0xffff3be9);
	}
}
