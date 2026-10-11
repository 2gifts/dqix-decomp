#include <globaldefs.h>

#if defined(jpn)
extern "C" void func_0205d304(void* a, int b, int c, int d, int e, int f, int g);
#else
extern "C" void func_0205d304(void* a, int b, int c, int d, int e, int f, int g, int h);
#endif


// JPN: func_ov023_021d9aa8
// USA: func_ov023_021d921c
ARM void InitBoxLayout_021d921c(void* obj, int unused, int w, int h) {
	*(short*)((char*)obj + 0xc0) = (short)w;
	*(short*)((char*)obj + 0xc2) = (short)h;
	*(short*)((char*)obj + 0xc4) = (short)((0x20 - w) >> 1);
	*(short*)((char*)obj + 0xc6) = (short)((0x18 - h) >> 1);
	*(short*)((char*)obj + 0xc8) = 0;
	*(short*)((char*)obj + 0xca) = 5;
	*(short*)((char*)obj + 0xcc) = 0xa;
	*(short*)((char*)obj + 0xce) = 0xa;
	*(unsigned char*)((char*)obj + 0xd1) = 0;
	*(unsigned char*)((char*)obj + 0xd5) = 0;
#if defined(jpn)
	func_0205d304((char*)obj + 0x20, unused, 0, 0, 0, 1, 0);
#else
	func_0205d304((char*)obj + 0x20, unused, 0, 0, 0, 1, 0, 0);
#endif

}
