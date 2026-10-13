#include <globaldefs.h>

struct FlagWord020466f4;
void ClearFlags020466f4(struct FlagWord020466f4* word, unsigned int mask);
void* GetDataPtr02114e04_020d6c00(void);
void DispatchWithGlobalContext020daf9c(int a, int b, int c, int d);

struct Obj021aef0c {
	char pad0[0x1];
	unsigned char field1;
	char pad1[6];
	unsigned char field8;
};

typedef unsigned char (*StateFn021aef0c)(Obj021aef0c* self);

struct FnTable021aef0c {
	StateFn021aef0c fns[5];
};

extern FnTable021aef0c data_ov017_021d6ad8;

// USA: func_ov017_021aef0c
ARM void DispatchStateAndMaybeInit_021aef0c(Obj021aef0c* self, void* context) {
	FnTable021aef0c table = data_ov017_021d6ad8;
	self->field8 = table.fns[self->field8](self);

	if (self->field1 != 0) {
		ClearFlags020466f4((struct FlagWord020466f4*)GetDataPtr02114e04_020d6c00(), 0x800000);
		DispatchWithGlobalContext020daf9c(0, 1, 0, 1);
	}
}
