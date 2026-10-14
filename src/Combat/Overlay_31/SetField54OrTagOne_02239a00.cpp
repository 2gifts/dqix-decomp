#include <globaldefs.h>

extern "C" int func_ov031_02239368(int);
int SetField54IfTagNot9Or10_ov031_022393e4(int v);

// USA: func_ov031_02239a00
ARM int SetField54OrTagOne_02239a00(short* p) {
	unsigned short v = *(unsigned short*)((char*)p + 2);
	if (v != 0) {
		return SetField54IfTagNot9Or10_ov031_022393e4(v);
	}
	return func_ov031_02239368(1);
}
