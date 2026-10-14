#include <globaldefs.h>

int PeekInputLogB_020a1fa8(void);
extern "C" int func_ov026_021dbf04(void* p);

// USA: func_ov000_02163d94
ARM int InvokeIfInputLogBIs3_021dbf04_ov000_02163d94(void* p) {
	int v = PeekInputLogB_020a1fa8();
	if (v != 3) {
		return v;
	}
	return func_ov026_021dbf04(p);
}
