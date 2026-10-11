#include <globaldefs.h>

extern void SetField1e_0223521c(void);
extern void ClearField1e_02235204(void);
extern "C" void func_ov031_022238cc(void);
extern "C" int FastIntModulus(int numer, int denom);
extern "C" void func_ov031_0222f9ec(void);
extern "C" void func_ov031_02230120(void);
extern "C" void func_ov031_022351f8(int v);
extern "C" void func_ov031_022308d4(void);
extern "C" void func_ov031_0223e2c0(int a, int b);

struct CombatCtx0223060c { unsigned char unk0, unk1, unk2, unk3; unsigned short field4; unsigned short pad6; void* field8; };
extern struct CombatCtx0223060c data_ov031_02290ca0;

#pragma optimize_for_size off
// USA: func_ov031_0223060c  (semantic: AdvanceTimerAndDispatch_0223060c)
extern "C" ARM void func_ov031_0223060c(int a) {
	SetField1e_0223521c();
	func_ov031_022238cc();

	if (data_ov031_02290ca0.field4 > 6) data_ov031_02290ca0.field4 -= 6;
	else data_ov031_02290ca0.field4 = 0;

	int rem = FastIntModulus(data_ov031_02290ca0.field4, 0x1d);
	if (rem == 0x17) {
		func_ov031_0222f9ec();
		return;
	}
	if (rem > 0x17) {
		data_ov031_02290ca0.field4 = data_ov031_02290ca0.field4 + (0x1d - rem);
		rem = 0;
	}
	func_ov031_02230120();
	if (rem != 0) return;

	int div = (data_ov031_02290ca0.field4 * 0x37) / 145;
	func_ov031_022351f8(div);
	ClearField1e_02235204();
	func_ov031_022308d4();
	*(int*)((char*)data_ov031_02290ca0.field8 + 0x38) = 0;
	func_ov031_0223e2c0(0, a);
}
