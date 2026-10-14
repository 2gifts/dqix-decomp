#include <globaldefs.h>

unsigned short GetTableValue_0202053c(void* obj);

struct TableEntryStruct_021f70bc { void* obj; char pad[0x18]; float scaledA; float scaledB; };

// USA: func_ov024_021f70bc
ARM int ComputeScaledTableValues_021f70bc(struct TableEntryStruct_021f70bc* s) {
	int idx = GetTableValue_0202053c(s->obj) * 2;
	s->scaledA = (float)(idx + 125);
	s->scaledB = (float)(idx + 125) * 0.85f;
	return 1;
}
