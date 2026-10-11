#include <globaldefs.h>

#if defined(jpn)
enum { kRegionValue318_200 = 0x200 };
enum { kRegionValue464_28C = 0x28c };
enum { kRegionValue31C_204 = 0x204 };
enum { kRegionValue4A8_2D0 = 0x2d0 };
enum { kRegionValue468_290 = 0x290 };
#else
enum { kRegionValue318_200 = 0x318 };
enum { kRegionValue464_28C = 0x464 };
enum { kRegionValue31C_204 = 0x31c };
enum { kRegionValue4A8_2D0 = 0x4a8 };
enum { kRegionValue468_290 = 0x468 };
#endif


void* GetDataPtr02114e04_020d6c00(void);
extern "C" int func_ov017_0218b5b0(void);
extern "C" void _Z16SetSubBrightnessP13GameResourcesii(int, int, int);
extern "C" int _Z31IsSubBrightnessTransitionActiveP13GameResources(int* obj);
extern "C" void func_ov003_02167370(void* obj);
struct FlagWord020466f4;
void ClearFlags020466f4(struct FlagWord020466f4* word, unsigned int mask);
void SetCombatModeFromCase020dc2d0(int);

struct Self02160e34 {
	char pad0[kRegionValue318_200];
	void* field318; // 0x318
	char pad31c[kRegionValue464_28C - kRegionValue31C_204];
	int field464; // 0x464
	char pad468[kRegionValue4A8_2D0 - kRegionValue468_290];
	unsigned char field4a8; // 0x4a8
};

// USA: func_ov003_02160e34  (semantic: SyncStateAndClearMode_02160e34)
// JPN: func_ov003_02160f90
extern "C" ARM int func_ov003_02160e34(struct Self02160e34* self) {
	int result = 0;
	void* dataPtr = GetDataPtr02114e04_020d6c00();
	int w = func_ov017_0218b5b0();
	unsigned char state = self->field4a8;

	if (state == 0) {
		_Z16SetSubBrightnessP13GameResourcesii(w, -16, 8);
		self->field4a8 = self->field4a8 + 1;
		goto end;
	}
	if (state != 1) {
		goto end;
	}
	if (_Z31IsSubBrightnessTransitionActiveP13GameResources((int*)w) != 0) {
		goto end;
	}

	func_ov003_02167370(self->field318);
	self->field4a8 = 0;
	result = 1;
	ClearFlags020466f4((struct FlagWord020466f4*)dataPtr, 0x41);
	SetCombatModeFromCase020dc2d0(0);
	self->field464 &= ~0x800;
end:
	return result;
}
