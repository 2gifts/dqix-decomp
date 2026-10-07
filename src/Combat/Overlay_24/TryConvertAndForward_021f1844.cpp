#include <globaldefs.h>

extern "C" int func_ov000_0215e9fc(int a0, void* buf, int max, int flag);
extern "C" void func_ov024_021ed8c0(void* context, int id, int recordAddress, int* count, short* ids);

struct Obj_021f1844 { int field0; };

// USA: func_ov024_021f1844
ARM int TryConvertAndForward_021f1844(struct Obj_021f1844* obj, int b, int c, int* out, void* e) {
	int count = func_ov000_0215e9fc(obj->field0, e, 4, 1);
	*out = count;
	if (count <= 0) return 0;
	func_ov024_021ed8c0(obj, b, c, out, static_cast<short*>(e));
	return 1;
}
