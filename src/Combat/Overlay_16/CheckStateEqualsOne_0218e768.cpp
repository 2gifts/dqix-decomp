#include <globaldefs.h>

extern "C" int func_ov016_0218f340(void* obj);

// USA: func_ov016_0218e768
ARM int CheckStateEqualsOne_0218e768(void* obj, void*) {
	if (obj == NULL) return 0;
	return func_ov016_0218f340(obj) == 1;
}
