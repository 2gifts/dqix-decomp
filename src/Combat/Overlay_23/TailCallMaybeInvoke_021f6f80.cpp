#include <globaldefs.h>
#include "World/ZoneLootableRecord.h"

struct Foo02048004;
void MaybeInvoke0204719c(Foo02048004* obj);

// USA: func_ov023_021f6f80  (semantic: TailCallMaybeInvoke_021f6f80)
extern "C" ARM void func_ov023_021f6f80(void* p) {
	MaybeInvoke0204719c((Foo02048004*)((char*)p + 0x20));
}
