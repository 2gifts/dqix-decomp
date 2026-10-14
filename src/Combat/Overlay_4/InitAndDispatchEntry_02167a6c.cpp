#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"

void* ZeroInitReturn020de824(void* obj);
void InitStruct0207cbe8(char* obj);
extern "C" int func_ov004_02167908(void* a, int key);
extern "C" void func_0207d300(void* buf, void* b, int c, int d);

// USA: func_ov004_02167a6c
ARM int InitAndDispatchEntry_02167a6c(void* a, void* b) {
	GetPtrField0x2a04_02010828(GameState::GetInstance());
	void* node = (void*)func_ov004_02167908(a, 5);
	if (node != NULL) {
		char buf[0x38];
		((SafeAllocator*)buf)->ResetAllocatorPointer();
		ZeroInitReturn020de824(buf + 0x14);
		InitStruct0207cbe8(buf);
		InitStruct0207cbe8(buf);
		*(void**)(buf + 0x2c) = node;
		func_0207d300(buf, b, 1, 0);
	}
	return 0;
}
