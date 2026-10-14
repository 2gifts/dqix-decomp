#include <globaldefs.h>
#if defined(jpn)
#define REGION_FIELD_0 0x4ec
#define REGION_FIELD_1 0x50c
#else
#define REGION_FIELD_0 0x6fc
#define REGION_FIELD_1 0x71c
#endif

#include "GameState/GameState.h"

struct Obj020397cc;
void CancelPendingAction020397cc(struct Obj020397cc* obj, int arg1);

extern "C" void func_ov017_021a5568(void* p);
struct List02046a3c;
struct Node02046a3c;
void InsertNodeAfterHead(List02046a3c*, Node02046a3c*);

// USA: func_ov017_021a5530
ARM void CancelActionAndInsertNode_021a5530(char* self) {
	CancelPendingAction020397cc((struct Obj020397cc*)GameState::GetInstance()->GetUnknownGameObject(), 1);
	func_ov017_021a5568(*(void**)(self + 0x3000 + REGION_FIELD_1));
	void* list = *(void**)(self + 0x3000 + REGION_FIELD_0);
	InsertNodeAfterHead((List02046a3c*)list, (Node02046a3c*)(*(void**)(self + 0x3000 + REGION_FIELD_1)));
}
