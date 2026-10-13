#include <globaldefs.h>

#if defined(jpn)
enum { kSelectionPointer = 0x10 };
#else
enum { kSelectionPointer = 0x18 };
#endif

#include "GameState/GameState.h"

int GetWord0x0(int* obj);

struct Obj020e25e8;
void ResetSelectionState020e25e8(struct Obj020e25e8* obj);
extern "C" void _Z13SetBrightnessP13GameResourcesii(void* obj, int value, int frames);
struct Actor0209c678;
void DispatchContextByState0209c678(struct Actor0209c678* actor, int arg);
extern "C" int _Z28IsBrightnessTransitionActiveP13GameResources(int* obj);

extern int data_02109bf4;

struct Struct0215f2b4 {
	unsigned char pad0[kSelectionPointer];
	struct Obj020e25e8* f18;
	unsigned char pad1[0x38f - kSelectionPointer - 4];
	unsigned char f38f;
	unsigned char f390;
	unsigned char pad2[0x394 - 0x391];
	unsigned short f394;
};

// USA: func_ov006_0215f2b4  (semantic: UpdateSelectionAndDispatchState_0215f2b4)
extern "C" ARM void func_ov006_0215f2b4(struct Struct0215f2b4* obj) {
	int ctx = GetWord0x0((int*)GameState::GetInstance());
	if (obj->f390 == 0) {
		if (obj->f18 != 0) {
			ResetSelectionState020e25e8(obj->f18);
		}
		_Z13SetBrightnessP13GameResourcesii((void*)ctx, -16, 16);
		if ((obj->f394 & 2) == 0) {
			DispatchContextByState0209c678((struct Actor0209c678*)&data_02109bf4, 0xf);
		}
		obj->f390 += 1;
		return;
	}
	if (obj->f390 != 1) {
		return;
	}
	if (_Z28IsBrightnessTransitionActiveP13GameResources((int*)ctx) == 0) {
		obj->f38f = 0xd;
		obj->f390 = 0;
	}
}
