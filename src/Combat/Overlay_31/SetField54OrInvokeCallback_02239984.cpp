#include <globaldefs.h>

struct CallbackHolder_02239984 { void (*fn)(int, void*); };
extern struct CallbackHolder_02239984 data_ov031_02290d18;
extern int data_ov031_0224c3f4;

extern "C" int func_ov031_022399d8(void);
void SetField54IfTagNot9Or10_ov031_022393e4(int v);
int CheckFirstOrRunTen_0223a358(void);

// USA: func_ov031_02239984  (semantic: SetField54OrInvokeCallback_02239984)
extern "C" ARM void func_ov031_02239984(short* p) {
	unsigned short v = *(unsigned short*)((char*)p + 2);
	if (v != 0) {
		SetField54IfTagNot9Or10_ov031_022393e4(v);
		CheckFirstOrRunTen_0223a358();
		return;
	}
	if (func_ov031_022399d8() != 0) {
		return;
	}
	if (data_ov031_02290d18.fn != 0) {
		data_ov031_02290d18.fn(0x8000000, &data_ov031_0224c3f4);
	}
	CheckFirstOrRunTen_0223a358();
}
