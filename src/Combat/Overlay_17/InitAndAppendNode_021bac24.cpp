#include <globaldefs.h>

#if defined(jpn)
#define REGION_FIELD_0 0x518
#define REGION_FIELD_1 0x4ec
#else
#define REGION_FIELD_0 0x728
#define REGION_FIELD_1 0x6fc
#endif

#include "GameState/GameState.h"

int GetGlobalField0x1c020421a0();

extern "C" void func_ov017_021bac58(unsigned char* self);

struct TailNode020469b4 { unsigned char pad0[2]; unsigned char inList; unsigned char pad3; void* next; };
struct TailList020469b4 { void* head; void* tail; };
void AppendNodeToTail(TailList020469b4* list, TailNode020469b4* node);

// USA: func_ov017_021bac24  (semantic: InitAndAppendNode_021bac24)
extern "C" ARM void func_ov017_021bac24(unsigned char* base) {
    GameState::GetInstance()->GetUnknownGameObject();
    GetGlobalField0x1c020421a0();
    func_ov017_021bac58(*(unsigned char**)(base + 0x3000 + REGION_FIELD_0));
    TailList020469b4* list = *(TailList020469b4**)(base + 0x3000 + REGION_FIELD_1);
    TailNode020469b4* node = *(TailNode020469b4**)(base + 0x3000 + REGION_FIELD_0);
    AppendNodeToTail(list, node);
}
