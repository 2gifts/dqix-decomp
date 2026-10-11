#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_0202ae18(void);
extern "C" void func_ov017_02195398(int, int);
extern "C" void func_ov017_02191234(int);
extern "C" void func_ov017_021905b8(int, int, int);

void SetFlagAndCleanup_02195618(unsigned char* obj);
int GetField0x3acValue(GameState* battleStruct);

struct SearchStruct;
void SetSearchFlagBit0202c660(struct SearchStruct* obj, int value);

struct S021b1454;
void ClearBitAtIndex_021b1454(struct S021b1454* obj, int bit);

// JPN: func_ov017_02196154
// USA: func_ov017_0219558c  (semantic: HandleFlagOrClearSlot_0219558c)
extern "C" ARM void func_ov017_0219558c(unsigned char* obj, int value) {
#if defined(jpn)
 enum {regionalOffset0=0x914};
#else
 enum {regionalOffset0=0xb34};
#endif
	GameState* battleStruct = GameState::GetInstance();
	int x = ((int)func_ov017_0218b5b0());
	struct SearchStruct* search = (struct SearchStruct*)func_0202ae18();
	if (value == 0) {
		SetFlagAndCleanup_02195618(obj);
		return;
	}
	if (value == GetField0x3acValue(battleStruct)) return;
	func_ov017_02195398(x, value);
	SetSearchFlagBit0202c660(search, value);
	func_ov017_02191234(x);
	func_ov017_021905b8(x, value, 1);
	ClearBitAtIndex_021b1454(*(struct S021b1454**)((char*)obj + 0x3000 + regionalOffset0), value & 0xff);
}
