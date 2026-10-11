#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_0202ae18(void);
int CheckField0NonZero(int* obj);
unsigned char GetField0x397cValue(GameState* battleStruct);
void EnqueueEventTag150_021d035c(unsigned char a, unsigned char b, unsigned char c);
extern "C" int func_ov001_02154c64(void* a);
extern "C" void func_ov001_021539d8(void* a);
int StoreArgIfMatched_02153948(unsigned short a);

struct Self02154de4 {
	unsigned char pad0[0x4a];
	unsigned short f4a;
#if defined(jpn)
	unsigned char pad1[0x104 - 0x4c];
#else
	unsigned char pad1[0x108 - 0x4c];
#endif
	unsigned char f108;
};

// USA: func_ov001_02154de4
ARM int ProcessAndDispatchState_02154de4(struct Self02154de4* self) {
	if (CheckField0NonZero((int*)func_0202ae18()) != 0) {
		GameState* bs = GameState::GetInstance();
		unsigned char v = GetField0x397cValue(bs);
		EnqueueEventTag150_021d035c(1, v & 0xff, self->f108);
	}
	if (func_ov001_02154c64(self) != 0) {
		return 0x11;
	}
	func_ov001_021539d8(self);
	StoreArgIfMatched_02153948(self->f4a);
	return 4;
}
