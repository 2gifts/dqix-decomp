#include <globaldefs.h>

// JPN: func_ov024_021f7180
// USA: func_ov024_021f69b4
ARM void* FindByKeyIndexed_021f69b4(char* base, int key) {
#if defined(jpn)
 enum {regionalOffset0=0x488};
#else
 enum {regionalOffset0=0x448};
#endif
	int valid = (key >= 0 && key <= 3) ? 1 : 0;
	if (!valid) goto notfound;
	for (int i = 0; i < 4; i++) {
		int entryKey = *(int*)(base + i * regionalOffset0 + 0x9a4);
		if (key == entryKey) {
			return base + 0x958 + i * regionalOffset0;
		}
	}
notfound:
	return (void*)0;
}
