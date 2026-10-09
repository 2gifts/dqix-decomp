#include <globaldefs.h>
#include "Resource/Brightness.h"
#include "Memory/SafeAllocator.h"

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
	char pad0[0x23c];
	SafeAllocator alloc23c;
	char pad250[0x318 - 0x23c - sizeof(SafeAllocator)];
	struct View02160cf8* view;
	char pad31c[0x398 - 0x31c];
	void* field398;
	char pad39c[0x464 - 0x39c];
	unsigned int flags464;
	char pad468[0x4a8 - 0x468];
	unsigned char state;
};

// USA: func_ov003_02160cf8
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
