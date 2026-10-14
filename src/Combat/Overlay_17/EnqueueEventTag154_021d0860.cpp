#include <globaldefs.h>

extern "C" void* func_0202ae18(void);
struct SearchStruct0202c1a4;
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);
void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

// USA: func_ov017_021d0860
ARM void EnqueueEventTag154_021d0860(int a, int b, int c) {
	void* p = GetData02100044_0202ae24();
	void* self = func_0202ae18();
	unsigned char buf[0x14];
	unsigned char* q = buf + 4;
	q[2] = b;
	buf[0] = 0x9a;
	q[0] = a;
	signed char ret = GetSearchStructCurrentArrEntry((struct SearchStruct0202c1a4*)self);
	q[1] = ret;
	if (q[2] == 0) {
		q[3] = c;
	} else if (q[2] == 1) {
		q[3] = c;
	}
	func_0205e330(p, buf, 0);
}
