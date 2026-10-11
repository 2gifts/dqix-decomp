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

extern "C" void func_ov003_02165c9c(unsigned char* self);

// USA: func_ov003_02165bd8  (semantic: UpdateCursorState_02165bd8)
// JPN: func_ov003_02165b84
extern "C" ARM void func_ov003_02165bd8(unsigned char* self) {
    short outHigh, outLow;
    func_ov003_02160c58(self, &outHigh, &outLow);

    unsigned char byteF7C = *((unsigned char*)GetPtrField0x2a04(GameState::GetInstance()) + 0xf7c);
    outLow = outLow - (byteF7C - 1);

    unsigned char* base = (unsigned char*)GetPtrField0x2a04(GameState::GetInstance()) + 0x2000;
    int byteC8C = base[0xc8c];
    if (outLow != 0) {
        byteC8C += 1;
    }
    int limit = (byteC8C + 3) / 4;

    int flags = *(int*)(self + kRegionValue45C_284);
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

    func_ov003_02165c9c(self);
}
