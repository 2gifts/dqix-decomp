#include <globaldefs.h>

extern "C" int* func_0202ae18(void);
int CheckField0NonZero(int* obj);
extern "C" int func_0202c508(void* p);

// USA: func_ov017_021a01bc
ARM void SetByteIfDataAndCheckClear_021a01bc(unsigned char* self) {
	int* ptr = func_0202ae18();
	if (!CheckField0NonZero(ptr)) return;
	if (func_0202c508(ptr) == 0) {
		self[
#if defined(jpn)
            0x40c9
#else
            0x42e9
#endif
        ] = 1;
	}
}
