#include <globaldefs.h>
#if defined(jpn)
#define RESOURCE_OFFSET 0x4f0
#else
#define RESOURCE_OFFSET 0x700
#endif
#include "Resource/GameResources.h"

extern "C" void func_ov017_021a4368(void *p, int v);
extern "C" void func_020439b0(int a, int b);
int GetGlobalField0x1c020421a0();

struct ObjWithField4_021afabc { char pad[4]; int field4; };

// USA: func_ov017_021afabc
ARM void CallField700ThenNotify_021afabc(ObjWithField4_021afabc *obj) {
	GameResources *ov = func_ov017_0218b5b0();
	void *p = *(void **)((char *)ov + 0x3000 + RESOURCE_OFFSET);
	func_ov017_021a4368(p, obj->field4);
	func_020439b0(GetGlobalField0x1c020421a0(), 0);
}
