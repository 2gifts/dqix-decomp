#include <globaldefs.h>
#include "std_library_functions.h"

#if defined(jpn)
enum { kRegionValue840_860 = 0x860 };
#else
enum { kRegionValue840_860 = 0x840 };
#endif


struct Entry0209859c;
struct Entry0209859c* FindEntryByKey0209859c(struct Entry0209859c* list, void* key);
extern "C" void* func_02012fe4(void* obj);

struct KeyArrayObj_02171f80 {
	unsigned char pad0[0x8];
	unsigned char keys[0x32][0x8];
	unsigned char pad1[0x198 - (0x8 + 0x32 * 0x8)];
	unsigned char field198;
};

// USA: func_ov003_02171f80
// JPN: func_ov003_0217123c
ARM void ClearUnmatchedKeys_02171f80(struct KeyArrayObj_02171f80* obj) {
	unsigned char* list = (unsigned char*)func_02012fe4(obj);
	unsigned char* key = obj->keys[0];
	int i = 0;
	while (i < 0x32) {
		if (FindEntryByKey0209859c((struct Entry0209859c*)(list + kRegionValue840_860), key) == NULL) {
			memset(key, 0, 8);
			obj->field198 -= 1;
		}
		i++;
		key += 8;
	}
}
