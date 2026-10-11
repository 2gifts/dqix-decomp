#include <globaldefs.h>

extern "C" void func_ov031_02210358(int a, int b);
void SetGlobal0224e588Deref_022103dc(void* value);
extern "C" int func_ov031_02210f24(const char* s);
extern "C" int func_ov031_02210f78(int a, int code, void* buf);
ARM void ResetFieldAndUnblock_022103f8(void* value);
extern "C" int _Z21SelectAndCall022071d8ii(int unused, int mode, int extra);
struct Obj022078f0;
ARM int Validate_022078f0(struct Obj022078f0* obj, void* v);
struct Packet02207230;
int SendSwapped_02207230(void* ctx, struct Packet02207230* pkt);

struct Ctx02210988 {
	char pad0[0x4];
	int field4;
	char pad1[0x20 - 0x8];
	int field20;
	unsigned short field24;
	char pad2[0x48 - 0x26];
	char field48[1];
	char pad3[0x1b8 - 0x49];
	int field1b8;
	char pad4[0x1d4 - 0x1bc];
};
extern Ctx02210988* data_ov031_0224e588;
extern void* data_ov031_022499f8;

// USA: func_ov031_02210988  (semantic: BuildValidateAndSendState_02210988)
#pragma optimize_for_size off
extern "C" ARM void func_ov031_02210988(void) {
	unsigned char local[8];

	void* r4 = &data_ov031_022499f8;
	int mode = 0xd68f;
	int h = data_ov031_0224e588->field20;
	if (h != 0) {
		r4 = (void*)h;
	} else if (func_ov031_02210f24(data_ov031_0224e588->field48)) {
		r4 = (char*)data_ov031_0224e588 + 0x48;
	}

	int rv = data_ov031_0224e588->field24;
	if (rv != 0) mode = rv;

	if (data_ov031_0224e588->field4 == 2) {
		SetGlobal0224e588Deref_022103dc((void*)5);
		return;
	}

	if (!func_ov031_02210f78((int)r4, mode, local)) {
		func_ov031_02210358(5, 5 - 0x23);
		ResetFieldAndUnblock_022103f8((void*)5);
		return;
	}

	if (data_ov031_0224e588->field4 == 2) {
		SetGlobal0224e588Deref_022103dc((void*)5);
		return;
	}

	int sel = _Z21SelectAndCall022071d8ii(2, 1, 0);
	if (sel < 0) {
		func_ov031_02210358(5, 5 - 0x37);
		ResetFieldAndUnblock_022103f8((void*)5);
		return;
	}
	data_ov031_0224e588->field1b8 = sel;

	if (data_ov031_0224e588->field4 == 2) {
		SetGlobal0224e588Deref_022103dc((void*)5);
		return;
	}

	int val = Validate_022078f0((struct Obj022078f0*)data_ov031_0224e588->field1b8, (char*)data_ov031_0224e588 + 0x1d4);
	if (val < 0) {
		func_ov031_02210358(5, 5 - 0x37);
		ResetFieldAndUnblock_022103f8((void*)5);
		return;
	}

	if (data_ov031_0224e588->field4 == 2) {
		SetGlobal0224e588Deref_022103dc((void*)5);
		return;
	}

	int sw = SendSwapped_02207230((void*)data_ov031_0224e588->field1b8, (struct Packet02207230*)local);
	if (sw < 0) {
		func_ov031_02210358(6, 6 - 0x42);
		ResetFieldAndUnblock_022103f8((void*)5);
		return;
	}
	SetGlobal0224e588Deref_022103dc((void*)6);
}
