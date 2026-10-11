#include <globaldefs.h>
#include "Resource/Brightness.h"
#include "Memory/SafeAllocator.h"

#if defined(jpn)
enum { kRegionValue23C_124 = 0x124 };
enum { kRegionValue318_200 = 0x200 };
enum { kRegionValue398_280 = 0x280 };
enum { kRegionValue31C_204 = 0x204 };
enum { kRegionValue464_28C = 0x28c };
enum { kRegionValue39C_284 = 0x284 };
enum { kRegionValue4A8_2D0 = 0x2d0 };
enum { kRegionValue468_290 = 0x290 };
#else
enum { kRegionValue23C_124 = 0x23c };
enum { kRegionValue318_200 = 0x318 };
enum { kRegionValue398_280 = 0x398 };
enum { kRegionValue31C_204 = 0x31c };
enum { kRegionValue464_28C = 0x464 };
enum { kRegionValue39C_284 = 0x39c };
enum { kRegionValue4A8_2D0 = 0x4a8 };
enum { kRegionValue468_290 = 0x468 };
#endif


extern "C" void* _Z27GetDataPtr02114e04_020d6c00v(void);
void OrBitsIntoField0(unsigned int* word, unsigned int bits);
extern "C" void _Z26ApplyElementEffect02161438Pv(void* obj);

struct View02160cf8 {
	void* field0;
};

extern "C" void func_ov003_021672e4(struct View02160cf8* view, int a, int b);
extern "C" void func_ov003_0216724c(struct View02160cf8* view, SafeAllocator* alloc);
extern "C" int func_ov003_0216759c(struct View02160cf8* view);

struct Self02160cf8 {
	char pad0[kRegionValue23C_124];
	SafeAllocator alloc23c;
	char pad250[kRegionValue318_200 - kRegionValue23C_124 - sizeof(SafeAllocator)];
	struct View02160cf8* view;
	char pad31c[kRegionValue398_280 - kRegionValue31C_204];
	void* field398;
	char pad39c[kRegionValue464_28C - kRegionValue39C_284];
	unsigned int flags464;
	char pad468[kRegionValue4A8_2D0 - kRegionValue468_290];
	unsigned char state;
};

// USA: func_ov003_02160cf8
// JPN: func_ov003_02160e54
extern "C" ARM int func_ov003_02160cf8(struct Self02160cf8* self) {
	GameResources* res = func_ov017_0218b5b0();
	void* dataPtr = _Z27GetDataPtr02114e04_020d6c00v();
	int result = 0;

	if (self->state == 0) {
		SetSubBrightness(res, -16, 8);
		self->state++;
	} else if (self->state == 1) {
		if (IsSubBrightnessTransitionActive(res) == 0) {
			OrBitsIntoField0((unsigned int*)dataPtr, 1);
			self->alloc23c.Reset();
			func_ov003_021672e4(self->view, 0, -1);
			self->view->field0 = self->field398;
			func_ov003_0216724c(self->view, &self->alloc23c);
			self->state++;
		}
	} else if (self->state == 2) {
		if (func_ov003_0216759c(self->view) != 0) {
			_Z26ApplyElementEffect02161438Pv(self);
			self->state++;
		}
	} else if (self->state == 3) {
		SetSubBrightness(res, 0, 8);
		self->state++;
	} else if (self->state == 4) {
		if (IsSubBrightnessTransitionActive(res) == 0) {
			self->state = 0;
			result = 1;
			self->flags464 &= ~0x400;
		}
	}
	return result;
}
