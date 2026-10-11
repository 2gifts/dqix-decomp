#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { kRegionValue45C_284 = 0x284 };
enum { kRegionValue49F_2C7 = 0x2c7 };
#else
enum { kRegionValue45C_284 = 0x45c };
enum { kRegionValue49F_2C7 = 0x49f };
#endif


extern "C" void func_ov003_02160c58(unsigned char* self, short* outHigh, short* outLow);
void* GetPtrField0x2a04(GameState*);
extern "C" void func_ov003_02166220(unsigned char* self);

// USA: func_ov003_02166184  (semantic: UpdateCursorLimit_02166184)
// JPN: func_ov003_021660d0
extern "C" ARM void func_ov003_02166184(unsigned char* self) {
	short outHigh, outLow;
	unsigned char* base;
	int byteC8C;
	int limit;
	int flags;
	func_ov003_02160c58(self, &outHigh, &outLow);

	base = (unsigned char*)GetPtrField0x2a04(GameState::GetInstance()) + 0x2000;
	byteC8C = base[0xc8c];
	limit = (byteC8C + 3) / 4;

	flags = *(int*)(self + kRegionValue45C_284);
	if (flags & 0x10) {
		self[kRegionValue49F_2C7] = (signed char)self[kRegionValue49F_2C7] + 1;
	} else if (flags & 0x20) {
		self[kRegionValue49F_2C7] = (signed char)self[kRegionValue49F_2C7] - 1;
	}
	if (limit <= (signed char)self[kRegionValue49F_2C7]) {
		self[kRegionValue49F_2C7] = 0;
	} else if ((signed char)self[kRegionValue49F_2C7] < 0) {
		self[kRegionValue49F_2C7] = limit - 1;
	}

	func_ov003_02166220(self);
}
