#if defined(jpn)
#define R(j,u) (j)
#define data_ov006_0215fffe data_ov006_02161350
#define func_ov006_0215f3d8 func_ov006_021607f8
#define func_ov006_0215f4dc func_ov006_021608fc
#define func_ov006_0215f740 func_ov006_02160b08
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" void func_ov006_0215f3d8(void *obj);
extern "C" void func_ov006_0215f740(void *obj);
extern "C" int func_ov006_021595b4(void *obj);

// USA: func_ov006_02159564
ARM int Check02159564(void *obj) {
	*(void**)((char*)obj + R(0x3c, 0x44)) = (char*)obj + 0x364;
	func_ov006_0215f3d8(obj);
	short *ptr = *(short**)((char*)obj + R(0x3c, 0x44));
	if (*(short*)((char*)obj + 0x300 + 0x5e) != *ptr) {
		func_ov006_0215f740(obj);
		return 0;
	}
	return func_ov006_021595b4(obj) != 0;
}
