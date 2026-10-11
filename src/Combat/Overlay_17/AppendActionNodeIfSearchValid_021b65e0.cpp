// JPN: func_ov017_021b6b94
#if defined(jpn)
enum { RegionOffsetb00 = 0x8e0, RegionOffset6fc = 0x4ec };
#else
enum { RegionOffsetb00 = 0xb00, RegionOffset6fc = 0x6fc };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_0202ae18(void);
int CheckField0NonZero(int* obj);
extern "C" int func_0202c508(void* state);
struct SearchStruct;
int TestMaskBitBySignedByteIndex(struct SearchStruct* obj, int value);

struct Obj021b6790;
extern "C" void func_ov017_021b6790(Obj021b6790* self);

struct TailList020469b4;
struct TailNode020469b4;
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);

// USA: func_ov017_021b65e0  (semantic: AppendActionNodeIfSearchValid_021b65e0)
extern "C" ARM void func_ov017_021b65e0(unsigned char* obj, int arg1) {
	GameState* bs = GameState::GetInstance();
	void* search = func_0202ae18();
	bool ok = true;
	if (arg1 == 0 && CheckField0NonZero((int*)search) && func_0202c508(search) != 0) {
		for (int i = 0; i < 4; i++) {
			if (TestMaskBitBySignedByteIndex((struct SearchStruct*)search, i)) {
				if (bs->GetGameObjectByIndex(i) == NULL) {
					ok = false;
				}
			}
		}
	}
	if (!ok) {
		return;
	}
	func_ov017_021b6790(*(Obj021b6790**)(obj + 0x3000 + RegionOffsetb00));
	*(unsigned char*)((char*)(*(Obj021b6790**)(obj + 0x3000 + RegionOffsetb00)) + 0x1c) = arg1;
	AppendNodeToTail(*(struct TailList020469b4**)(obj + 0x3000 + RegionOffset6fc), (struct TailNode020469b4*)(*(Obj021b6790**)(obj + 0x3000 + RegionOffsetb00)));
	search = func_0202ae18();
	if (func_0202c508(search) == 0) {
		return;
	}
	if (arg1 == 0) {
		*(unsigned char*)((char*)search + 0x1000 + 0x11) = 0;
	}
}
