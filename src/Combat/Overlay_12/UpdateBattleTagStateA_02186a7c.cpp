#if defined(jpn)
#define func_ov023_021e6de4 func_ov023_021e7148
#define func_ov012_0218943c func_ov012_02189d18
enum {
    kStepOffset = 0x1340,
    kStateOffset = 0x1341,
    kActiveOffset = 0x1368,
    kWindowOffset = 0x90,
    kPreviousStateOffset = 0x148,
    kMainChoiceOffset = 0x142c,
    kSecondaryState = 7
};
#else
enum {
    kStepOffset = 0x1370,
    kStateOffset = 0x1371,
    kActiveOffset = 0x13a0,
    kWindowOffset = 0xac,
    kPreviousStateOffset = 0x164,
    kMainChoiceOffset = 0x13d4,
    kSecondaryState = 9
};
#endif

#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

extern "C" void* _Z10GetWord0x0Pi(void* battle);
extern "C" void* _Z17GetGlobal02109400v();

struct Struct0205de24;
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);

struct Struct_0205c570;
int GetActiveScaledSum0205d794(struct Struct_0205c570* s);

struct Obj0205eaa0;
extern struct Obj0205eaa0 data_02108760;
extern "C" int _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(struct Obj0205eaa0* obj, int a, int b);

struct Entry_0205d6a0;
extern "C" void _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(struct Entry_0205d6a0* a, int flag);

struct Obj021e6e20;
int TestFlagsAndActiveElement2_021e6e20(struct Obj021e6e20* obj);

extern "C" void func_ov023_021e6e60(void* self);
extern "C" int func_ov023_021e6de4(char* obj);
extern "C" void func_ov012_0218943c(void* self);

// USA: func_ov012_02186a7c  (semantic: UpdateBattleTagStateA_02186a7c)
extern "C" ARM void func_ov012_02186a7c(char* self) {
	_Z10GetWord0x0Pi(GameState::GetInstance());
	BackgroundLoader::GetInstance();
	_Z17GetGlobal02109400v();

	unsigned char state = *(unsigned char*)(self + kStepOffset);
	if (state == 0) {
		*(unsigned char*)(self + kActiveOffset) = 0;
		*(int*)(self + kMainChoiceOffset) = 0;
		FindAndLinkMatchingEntry0205de24((struct Struct0205de24*)(self + kWindowOffset), 0, 2);
		func_ov023_021e6e60(self);
		func_ov012_0218943c(self);
		(*(unsigned char*)(self + kStepOffset))++;
		return;
	}
	if (state != 1) return;

	*(unsigned char*)(self + kActiveOffset) = 1;
	*(int*)(self + kMainChoiceOffset) = GetActiveScaledSum0205d794((struct Struct_0205c570*)(self + kWindowOffset));

	int flag = 0;
	if (func_ov023_021e6de4(self) != 0) {
		*(unsigned char*)(self + kPreviousStateOffset) = *(unsigned char*)(self + kStateOffset);
		*(unsigned char*)(self + kActiveOffset) = 0;
		_Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, 1, 0);

		int v = *(int*)(self + kMainChoiceOffset);
		switch (v) {
		case 0: *(unsigned char*)(self + kStateOffset) = 2; *(unsigned char*)(self + kStepOffset) = flag; break;
		case 1: *(unsigned char*)(self + kStateOffset) = kSecondaryState; *(unsigned char*)(self + kStepOffset) = flag; break;
		case 2: *(unsigned char*)(self + kStateOffset) = 0xa; *(unsigned char*)(self + kStepOffset) = flag; break;
		case 3: *(unsigned char*)(self + kStateOffset) = 0xd; *(unsigned char*)(self + kStepOffset) = flag; break;
		case 4: *(unsigned char*)(self + kStateOffset) = 0xe; *(unsigned char*)(self + kStepOffset) = flag; break;
		case 5: flag = 1; break;
		}
	} else {
		if (TestFlagsAndActiveElement2_021e6e20((struct Obj021e6e20*)self) != 0) flag = 1;
	}

	if (flag == 0) return;
	*(unsigned char*)(self + kActiveOffset) = 0;
	*(int*)(self + kMainChoiceOffset) = 0;
	_Z22ResetEntryList0205d6a0P14Entry_0205d6a0i((struct Entry_0205d6a0*)(self + kWindowOffset), 1);
	*(unsigned char*)(self + kStateOffset) = 0xf;
	*(unsigned char*)(self + kStepOffset) = 0;
}
