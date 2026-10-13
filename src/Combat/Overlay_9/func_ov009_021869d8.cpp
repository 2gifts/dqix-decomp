#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"

#if defined(jpn)
#define func_ov009_02188ee8 func_ov009_02189e04
#define _Z20SetStatValue021855dcPhi func_ov009_021867bc
#endif

extern "C" void func_ov009_02188c2c(CharacterCreationUI* self);
extern "C" void func_ov009_02188d9c(CharacterCreationUI* self);
extern "C" void func_ov009_02188e70(CharacterCreationUI* self, int val);
extern "C" void func_ov009_02188944(CharacterCreationUI* self, int val);
extern "C" int func_ov009_02188ee8(CharacterCreationUI* self);
extern "C" ARM void _Z20SetStatValue021855dcPhi(unsigned char *self, int val);

// USA: func_ov009_021869d8  (semantic: AdvanceStatStep_021869d8)
extern "C" ARM void func_ov009_021869d8(CharacterCreationUI* self) {
	unsigned char step = self->step;
	if (step == 0) {
		func_ov009_02188c2c(self);
		func_ov009_02188d9c(self);
		int idx = self->sex;
		unsigned char val = self->hairColor[idx];
		func_ov009_02188e70(self, val);
		self->flags |= 1;
		self->step = self->step + 1;
		return;
	}
	if (step == 1) {
		if (self->flags & 0x80) {
			return;
		}
		int idx = self->sex;
		unsigned char val = self->hairColor[idx];
		func_ov009_02188944(self, val);
		self->step = self->step + 1;
		return;
	}
	if (step != 2) {
		return;
	}
	int result = func_ov009_02188ee8(self);
	if (result == -2) {
		_Z20SetStatValue021855dcPhi((unsigned char*)self, 5);
		return;
	}
	if (result == -3) {
		_Z20SetStatValue021855dcPhi((unsigned char*)self, 3);
		return;
	}
	if (result < 0x65 || result > 0x6c) {
		return;
	}
	int idx2 = self->sex;
	int v = result - 0x64;
	signed char *arr = self->furthestState;
	if (v > arr[idx2]) {
		return;
	}
	if (v == self->state) {
		return;
	}
	_Z20SetStatValue021855dcPhi((unsigned char*)self, v & 0xff);
}
