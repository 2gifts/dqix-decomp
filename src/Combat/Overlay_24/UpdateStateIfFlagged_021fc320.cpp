#include <globaldefs.h>

#if defined(jpn)
#define UpdateStateIfFlagged_021fc320 func_ov024_021fcaec
#endif

extern "C" int func_ov024_021fe698(void* self, int idx);
extern "C" void func_ov024_021fd954(void* self, int idx);

// USA: func_ov024_021fc320
#if defined(jpn)
extern "C"
#endif
ARM void UpdateStateIfFlagged_021fc320(void* self) {
	void* p = *(void**)((char*)self + 0x64c);
	unsigned int raw = *(unsigned int*)((char*)p + 0x8);
	unsigned int field = (raw << 0x16) >> 0x1e;
	if (field == 1 || *(unsigned char*)((char*)self + 0x6e) == 0) {
		return;
	}
	if (!func_ov024_021fe698(self, 0xb)) {
		return;
	}
	func_ov024_021fd954(self, 0x17);
}
