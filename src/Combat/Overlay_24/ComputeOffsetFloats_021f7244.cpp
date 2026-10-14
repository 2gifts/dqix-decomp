#include <globaldefs.h>

unsigned short GetTableValue_0202053c(void* obj);

struct TableStruct_021f7244 { void* obj; char pad[0x10]; float in14; float in18; float f1c; float f20; };

// USA: func_ov024_021f7244
ARM int ComputeOffsetFloats_021f7244(struct TableStruct_021f7244* s) {
	GetTableValue_0202053c(s->obj);
	s->f1c = s->in14 / 4.0f + 5.0f;
	s->f20 = s->in18 / 4.0f + 5.0f;
	return 1;
}
