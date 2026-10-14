#include <globaldefs.h>

#pragma optimize_for_size off

struct Mutex;
void* LockMutex(Mutex*);
void UpdateObjFromContext_022031bc(int a, unsigned short b, unsigned int c);
extern "C" int func_ov031_02203358(void);
struct RefNode020c80f8;
void UnlockMutex(Mutex*);

struct Ctx_0220586c {
	char pad0[0x64];
	void* inner;
	char pad1[0x70 - 0x64 - 4];
	volatile short field70;
};

struct Obj_0220586c {
	char pad0[4];
	Ctx_0220586c* ctx;
	char pad1[0xc - 0x4 - 4];
	signed char fieldC;
	char pad2[0x10 - 0xc - 1];
	unsigned short field10;
	unsigned short field12;
	unsigned int field14;
};

// USA: func_ov031_0220586c  (semantic: AcquireUpdateAndReleaseNode_0220586c)
extern "C" ARM int func_ov031_0220586c(Obj_0220586c* self) {
	Ctx_0220586c* ctx = self->ctx;
	char* inner = (char*)ctx->inner;
	int flag = 0;
	LockMutex((Mutex*)(inner + 0xe0));
	UpdateObjFromContext_022031bc(self->field10, self->field12, self->field14);
	*(int*)(inner + 0xf8) = 0;
	signed char b = self->fieldC;
	if (b == 0 || b == 4) {
		flag = func_ov031_02203358();
	}
	UnlockMutex((Mutex*)(inner + 0xe0));
	if (flag != 0) {
		ctx->field70 |= 0x40;
		return -0x4c;
	}
	ctx->field70 |= 4;
	return 0;
}
