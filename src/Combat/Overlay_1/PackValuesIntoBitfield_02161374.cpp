#include <globaldefs.h>
#include "Resource/GameResources.h"

extern "C" int func_ov017_021d60f4(void* a);

struct BitfieldHolder_02161374 {
	#if defined(jpn)
	char pad[0xf4];
#else
	char pad[0xf8];
#endif
	unsigned int flags : 27;
	unsigned int field_0xf8_27 : 5;
};

// KEEP-NAME
// USA: func_ov001_02161374
ARM int PackValuesIntoBitfield_02161374(void* values, int count) {
	BitfieldHolder_02161374* holder = (BitfieldHolder_02161374*)func_ov017_0218b5b0()->unknown_ptr_array_371c[6];
	for (int i = 0; i < count; i++) {
		holder->flags |= func_ov017_021d60f4(values);
		values = (char*)values + 8;
	}
	return 1;
}
