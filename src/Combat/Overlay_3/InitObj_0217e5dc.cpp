#include <globaldefs.h>
#if defined(jpn)
enum { kRegion998 = 0x868 };
enum { kRegion36fc = 0x34ec };
enum { kRegion3b04 = 0x38e4 };
#else
enum { kRegion998 = 0x998 };
enum { kRegion36fc = 0x36fc };
enum { kRegion3b04 = 0x3b04 };
#endif

#include "GameState/GameState.h"

int GetGlobalField0x1c020421a0(void);

void ReinitController02043204(char* obj);
extern "C" void func_02043124(char* obj);

struct TailNode020469b4;
struct TailList020469b4;
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);

void InitStruct0217e630(void* obj, signed char flag);

struct Obj0217e5dc {
	char pad1[kRegion36fc];
	struct TailList020469b4* list; // kRegion36fc
	char pad2[kRegion3b04 - kRegion36fc - 4];
	void* target; // kRegion3b04
};

// JPN: func_ov003_0217d2e4
// USA: func_ov003_0217e5dc
ARM void InitObj_0217e5dc(struct Obj0217e5dc* self, signed char flag) {
	GameState::GetInstance();
	int* g = (int*)(int)GetGlobalField0x1c020421a0();
	if (*(int*)((char*)g + kRegion998) != 0) {
		ReinitController02043204((char*)g);
		func_02043124((char*)g);
	}
	InitStruct0217e630(self->target, flag);
	AppendNodeToTail(self->list, (struct TailNode020469b4*)self->target);
}
