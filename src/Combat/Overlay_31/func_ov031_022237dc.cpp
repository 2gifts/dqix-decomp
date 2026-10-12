#include <globaldefs.h>

extern int* data_ov031_02250bf0;

extern "C" void func_ov031_022238cc();
extern "C" int func_ov031_0223be70(int a, int b, int c);
extern "C" void func_ov031_0223bbd8(void* obj, int idx, int a, int b);

struct Obj0223bcc8 { unsigned char pad0[8]; void* list; unsigned char count; };
extern "C" void _Z30SetEntryHalfword4Bits_0223bcc8P11Obj0223bcc8ii(Obj0223bcc8* obj, int idx, int val);

// USA: func_ov031_022237dc
#pragma optimize_for_size off
extern "C" ARM void func_ov031_022237dc(int a, int b, int c, int d) {
	int id = 6;
	func_ov031_022238cc();
	int i = 0;
	int zero = 0;
	int one_a = 1;
	int negOne = -1;
	int one_b = one_a;
	do {
		int val = func_ov031_0223be70(zero, id, one_a);
		data_ov031_02250bf0[i] = val;
		_Z30SetEntryHalfword4Bits_0223bcc8P11Obj0223bcc8ii((Obj0223bcc8*)data_ov031_02250bf0[i], negOne, one_b);
		i++;
		id++;
	} while (i < 4);
	func_ov031_0223bbd8((void*)data_ov031_02250bf0[0], -1, a, c);
	func_ov031_0223bbd8((void*)data_ov031_02250bf0[1], -1, b, c);
	func_ov031_0223bbd8((void*)data_ov031_02250bf0[2], -1, a, d);
	func_ov031_0223bbd8((void*)data_ov031_02250bf0[3], -1, b, d);
}
