#include <globaldefs.h>
#include "Graphics/LightingManager.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Filesystem/BackgroundLoader.h"

extern int data_ov014_02189800;

struct HandleState_02188bd0;
struct HandleState_02188d10;
ARM int ResetHandle_02188d10(struct HandleState_02188d10* s);
ARM void Clear0x10Bytes02096fc4(void* p);
ARM int InitHandleState_02188bd0(struct HandleState_02188bd0* s);
ARM void SetField0x3b0Value_020100c4(GameState* battleStruct, int value);

struct State021845ec {
	char pad0[0xc];
	char clr10[0x10];
	char handleState[0x1e];
	char pad3a[2];
	SafeAllocator* allocs;
	char pad40[0x2c];
	int f6c;
	int f70;
	char pad74[0x12];
	short arr86[5];
};

// USA: func_ov014_021845ec
extern "C" ARM void func_ov014_021845ec(struct State021845ec* obj) {
	if (obj->f6c >= 0) {
		BackgroundLoader* loader = BackgroundLoader::GetInstance();
		loader->RemoveTask(obj->f6c);
		obj->f6c = -1;
	}
	if (obj->f70 >= 0) {
		BackgroundLoader* loader = BackgroundLoader::GetInstance();
		loader->RemoveTask(obj->f70);
		obj->f70 = -1;
	}
	for (int i = 0; i < 5; i++) {
		if (obj->arr86[i] >= 0) {
			BackgroundLoader::GetInstance()->RemoveTask(obj->arr86[i]);
			obj->arr86[i] = -1;
		}
	}
	ResetHandle_02188d10((struct HandleState_02188d10*)obj->handleState);
	Clear0x10Bytes02096fc4(obj->clr10);
	InitHandleState_02188bd0((struct HandleState_02188bd0*)obj->handleState);
	GameState* battle = GameState::GetInstance();
	SetField0x3b0Value_020100c4(battle, *(int*)((char*)&data_ov014_02189800 + 0xc));
	*(int*)((char*)&data_ov014_02189800 + 0xc) = 0;
	void* d = LightingManager::GetInstance();
	*((unsigned char*)d + 0x85) = 1;
	if (obj->allocs == 0) {
		return;
	}
	for (int j = 0; j < 6; j++) {
		if (obj->allocs[j].GetSignedAllocator()) {
			obj->allocs[j].Destroy();
		}
	}
}
