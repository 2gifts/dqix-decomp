#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { kRegionValue480_2A8 = 0x2a8 };
#else
enum { kRegionValue480_2A8 = 0x480 };
#endif


void* GetPtrField0x2a04(GameState*);
extern "C" int func_ov003_02166a90(char* self, int val);

struct FindEntryContainer02086a04;
int RemoveOrShiftMarkedEntry02086a04(struct FindEntryContainer02086a04* c, int id);

extern "C" void* func_0205ec34(void);
void SetOrClearBitInArray(void* unused, unsigned char* array, int bit, int value);


struct Obj020397cc;
void CancelPendingAction020397cc(struct Obj020397cc* obj, int arg1);

// USA: func_ov003_021669f0  (semantic: HandleMarkedEntryRemoval_021669f0)
// JPN: func_ov003_021668ec
extern "C" ARM int func_ov003_021669f0(char* self) {
	GameState* bs;
	void* p2a04;
	int r;
	GameObject* c;

	if (*(short*)(self + kRegionValue480_2A8) < 0) return 1;

	bs = GameState::GetInstance();
	p2a04 = GetPtrField0x2a04(bs);
	r = func_ov003_02166a90(self, *(short*)(self + kRegionValue480_2A8));
	if (r == 0) return 0;
	if (r == 1) {
		RemoveOrShiftMarkedEntry02086a04((struct FindEntryContainer02086a04*)p2a04, (signed char)*(short*)(self + kRegionValue480_2A8));
		void* p = func_0205ec34();
		SetOrClearBitInArray(p, (unsigned char*)p + 0x8c, 0x784, 1);
	}

	c = bs->GetProtagonist();
	if (c != NULL) {
		CancelPendingAction020397cc((struct Obj020397cc*)c, 1);
	}
	return 1;
}
