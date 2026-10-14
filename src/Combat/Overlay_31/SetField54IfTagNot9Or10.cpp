#include <globaldefs.h>

struct Inner_022393e4 { unsigned char pad[0x40]; int field40; unsigned char pad2[0x10]; int field54; };
struct Outer_022393e4 { unsigned char pad[4]; struct Inner_022393e4* inner; };
extern struct Outer_022393e4 data_ov031_02290d18;

// USA: func_ov031_022393e4
ARM void SetField54IfTagNot9Or10_ov031_022393e4(int v) {
	int f = data_ov031_02290d18.inner->field40;
	if ((unsigned int)(f - 9) > 1) {
		data_ov031_02290d18.inner->field54 = v;
	}
}
