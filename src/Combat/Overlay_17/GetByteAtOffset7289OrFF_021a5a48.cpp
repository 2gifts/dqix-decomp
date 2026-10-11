#include <globaldefs.h>

extern int data_ov017_021d83ac;

// USA: func_ov017_021a5a48
ARM int GetByteAtOffset7289OrFF_021a5a48(void) {
	int v = data_ov017_021d83ac;
	int result = 0xff;
	if (v != 0) {
		result = *(unsigned char*)(v +
#if defined(jpn)
            0x1b3d
#else
            0x1c79
#endif
);
	}
	return result;
}
