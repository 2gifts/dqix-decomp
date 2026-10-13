#include <globaldefs.h>
#include "Resource/GameResources.h"

struct EventHeader021a4368;
extern "C" void func_ov017_021a4368(void *p, EventHeader021a4368* event);
extern "C" void func_020439b0(int a, int b);
int GetGlobalField0x1c020421a0();

struct ObjWithField4_021afabc { char unknown0[4]; EventHeader021a4368* event; };

// USA: func_ov017_021afabc
ARM void CallField700ThenNotify_021afabc(ObjWithField4_021afabc *obj) {
	GameResources *ov = func_ov017_0218b5b0();
	void *p = ov->unknown_ptr_array_36fc[1];
	func_ov017_021a4368(p, obj->event);
	func_020439b0(GetGlobalField0x1c020421a0(), 0);
}
