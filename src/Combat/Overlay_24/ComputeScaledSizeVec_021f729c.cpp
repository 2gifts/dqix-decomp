#include <globaldefs.h>

unsigned short GetTableValue_0202053c(void* obj);
extern "C" double _dflt(int);

struct Obj_021f729c { void* ptr0; char pad[0x18]; float sx; float sy; };

// USA: func_ov024_021f729c  (semantic: ComputeScaledSizeVec_021f729c)
extern "C" ARM int func_ov024_021f729c(struct Obj_021f729c* obj) {
	int v = GetTableValue_0202053c(obj->ptr0) * 2;
	if (v < 0x23) v = 0x23;
	obj->sx = (float)v;
	obj->sy = (float)((0.85) * (_dflt(v)));
	return 1;
}
