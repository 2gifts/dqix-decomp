#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"

void SetByteField0x253_020397c0(void* obj);
int GetFieldIfFlag4_020100f8(char* obj);
void SetField0x23cTrue_020a27ac(void* obj);
void TailForward02012da4(AllocatorUnion* alloc, void* data);
extern int data_02114e20;

struct List020727d8;
void ResetListHeader020727ec(struct List020727d8* list);

// USA: func_ov017_021bf398
ARM void ClearFieldsAndResetAllocator_021bf398(char* self) {
	GameState* battle = GameState::GetInstance();
	int flagResult = GetFieldIfFlag4_020100f8((char*)battle);
	GameObject* combatant = battle->GetUnknownGameObject();
	SetField0x23cTrue_020a27ac((void*)flagResult);
	SetByteField0x253_020397c0(combatant);
	SafeAllocator* allocator = (SafeAllocator*)(self + 0x14);
	void* p = allocator->GetSignedAllocator();
	if (p) {
		allocator->Reset();
		allocator->Destroy();
		ResetListHeader020727ec((struct List020727d8*)(self + 0xc));
		TailForward02012da4((AllocatorUnion*)&data_02114e20, p);
	}
	self[1] = 1;
}
