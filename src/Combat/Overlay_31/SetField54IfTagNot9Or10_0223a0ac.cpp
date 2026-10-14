#include <globaldefs.h>

extern "C" int func_ov031_02239368(int val);
ARM void SetField54IfTagNot9Or10_ov031_022393e4(int v);
ARM int SetBattleContextField0xc8IfIdle_020d472c(void* param);
ARM void RunTagIfShort2Is8_0223a040(short* p);

// USA: func_ov031_0223a0ac  (semantic: RunTagOrRegisterCallback_0223a0ac)
extern "C" ARM int func_ov031_0223a0ac(short* p) {
	unsigned short v = *(unsigned short*)((char*)p + 2);
	if (v != 0) {
		SetField54IfTagNot9Or10_ov031_022393e4(v);
		return func_ov031_02239368(0xa);
	}
	int r = SetBattleContextField0xc8IfIdle_020d472c((void*)RunTagIfShort2Is8_0223a040);
	if (r != 0) {
		SetField54IfTagNot9Or10_ov031_022393e4(r);
		return func_ov031_02239368(0xa);
	}
	return func_ov031_02239368(1);
}
