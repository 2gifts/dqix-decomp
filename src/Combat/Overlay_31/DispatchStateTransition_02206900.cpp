#include <globaldefs.h>

int IsInList0224e230_022071b4(void* item);
int IsNotInList0224e22c_02207180(void* v);
extern "C" int func_ov031_022051a8(void* a, void* b);
void* SetLookupFields_02205134(void* a, void* b, int c);
struct Obj02205194;
int GetField64OrField68Then022051a8_022051f4(Obj02205194* obj, void* extra);
extern "C" void func_ov031_022069d0(void);

// USA: func_ov031_02206900  (semantic: DispatchStateTransition_02206900)
#pragma optimize_for_size off
extern "C" ARM int func_ov031_02206900(void* obj) {
	if ((int)obj <= 0) {
		return ~0x1b;
	}
	if (IsInList0224e230_022071b4(obj) != 0) {
		return ~0x19;
	}
	if (IsNotInList0224e22c_02207180(obj) != 0) {
		return 0;
	}
	int flag1 = 0;
	if (obj != 0) {
		flag1 = (*(volatile short*)((char*)obj + 0x70) & 1) != 0;
	}
	if (!flag1) {
		return ~0x26;
	}
	if (*(volatile short*)((char*)obj + 0x70) & 0x10) {
		return ~0x19;
	}
	int flag2 = 1;
	*(volatile short*)((char*)obj + 0x70) |= 0x18;
	signed char b = *((signed char*)obj + 0x73);
	if (b != 0 && b != 4) {
		flag2 = 0;
	}
	if (flag2 != 0) {
		func_ov031_022051a8(*(void**)((char*)obj + 0x68), NULL);
	}
	void* p = SetLookupFields_02205134((void*)func_ov031_022069d0, obj, 1);
	*(int*)((char*)p + 8) = 0;
	GetField64OrField68Then022051a8_022051f4((Obj02205194*)obj, p);
	return 0;
}
