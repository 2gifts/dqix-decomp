#include <globaldefs.h>

extern void* data_ov031_0224e5bc;
int GetFieldAndReleaseRef_02216ab4(void);
void InvokeHandlerAndClear_02216a2c(void);
extern "C" void func_ov031_02211b98(void* a, void* b, int c);
extern "C" void func_ov031_02216b00(int* arg);
void SetGlobal0224e5a4IfNotNine_ov031_02211b08(int a, int b);

// USA: func_ov031_0221268c  (semantic: DispatchResultCode_0221268c)
#pragma optimize_for_size off
extern "C" ARM int func_ov031_0221268c(void) {
	int buf[0x1c4 / 4];

	if (data_ov031_0224e5bc == NULL) return 0;

	int r = GetFieldAndReleaseRef_02216ab4();
	switch (r) {
	case 0:
		return 2;
	case 0x15:
		InvokeHandlerAndClear_02216a2c();
		func_ov031_02211b98((void*)4, data_ov031_0224e5bc, 0x1e20);
		data_ov031_0224e5bc = NULL;
		return 3;
	case 0x14:
		InvokeHandlerAndClear_02216a2c();
		func_ov031_02211b98((void*)4, data_ov031_0224e5bc, 0x1e20);
		data_ov031_0224e5bc = NULL;
		return 5;
	default:
		func_ov031_02216b00(buf);
		InvokeHandlerAndClear_02216a2c();
		func_ov031_02211b98((void*)4, data_ov031_0224e5bc, 0x1e20);
		data_ov031_0224e5bc = NULL;
		SetGlobal0224e5a4IfNotNine_ov031_02211b08(2, buf[0]);
		return 4;
	}
}
