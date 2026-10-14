#include <globaldefs.h>

int GetFieldAt0x150_02053c6c(unsigned char* obj);

struct FieldWord0x150_021f72f8 { unsigned int w0; unsigned int val : 10; };
struct TableStruct_021f72f8 { void* obj; char pad[0x10]; float in14; float in18; float f1c; float f20; };

// USA: func_ov024_021f72f8  (semantic: ComputeOffsetFloats_021f72f8)
extern "C" ARM int func_ov024_021f72f8(struct TableStruct_021f72f8* s) {
	int base = GetFieldAt0x150_02053c6c((unsigned char*)s->obj);
	int v = ((struct FieldWord0x150_021f72f8*)base)->val;
	s->f1c = s->in14 / 2.0f + (float)v;
	s->f20 = s->in18 / 2.0f + (float)v;
	return 1;
}
