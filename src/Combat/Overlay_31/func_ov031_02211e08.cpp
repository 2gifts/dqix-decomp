#include <globaldefs.h>

extern "C" ARM void func_ov031_02211e08(void);
ARM int CheckField4Eq6_02212248(void);
extern "C" ARM int func_ov031_02213024(void);
ARM int GetField260_0220d540(void);
ARM void SetGlobal0224e5a4IfNotNine_ov031_02211b08(int a, int b);

// USA: func_ov031_022123d4  (semantic: ClampTierAndSetGlobal_022123d4)
#pragma optimize_for_size off
extern "C" ARM int func_ov031_022123d4(void) {
	func_ov031_02211e08();
	if (CheckField4Eq6_02212248()) {
		unsigned int tier = func_ov031_02213024();
		if (tier == 0xff || tier > 0x63) tier = 0x63;

		if (GetField260_0220d540() == 0xb) {
			SetGlobal0224e5a4IfNotNine_ov031_02211b08(9, (int)0xffff298c - tier);
		} else {
			SetGlobal0224e5a4IfNotNine_ov031_02211b08(8, (int)0xffff2d10 - tier);
		}
		return 1;
	}
	return 0;
}
