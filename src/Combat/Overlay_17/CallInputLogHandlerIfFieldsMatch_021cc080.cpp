#include <globaldefs.h>

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" void* func_ov017_021b8468(void* obj);
int InvokeIfInputLogBIs3_021dbf04(void* p);

struct Src021cc080 { unsigned char pad[4]; unsigned short field4; };
struct Ret021cc080 { unsigned char pad[8]; unsigned short field8; };

// USA: func_ov017_021cc080
ARM void CallInputLogHandlerIfFieldsMatch_021cc080(int unused0, Src021cc080* src, int unused2, unsigned char* obj) {
	obj += 0x3000;
	void* work = *(void**)(obj +
#if defined(jpn)
        0x508
#else
        0x718
#endif
);
	Ret021cc080* r = (Ret021cc080*)func_ov017_021b8478(work);
	void* r2 = func_ov017_021b8468(work);
	if (!r) {
		return;
	}
	if (r->field8 != src->field4) {
		return;
	}
	if (!r2) {
		return;
	}
	InvokeIfInputLogBIs3_021dbf04(r2);
}
