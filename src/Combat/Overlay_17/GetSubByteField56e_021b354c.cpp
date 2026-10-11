#include <globaldefs.h>

struct SubObj56e_021b354c { unsigned char pad[0x56e]; unsigned char b56e; };
#if defined(jpn)
#define SUB_POINTER_OFFSET 0x144
#else
#define SUB_POINTER_OFFSET 0x150
#endif
struct Obj150_021b354c { unsigned char pad[SUB_POINTER_OFFSET]; SubObj56e_021b354c* sub; };

// USA: func_ov017_021b354c
ARM unsigned char GetSubByteField56e_021b354c(Obj150_021b354c* obj) {
	SubObj56e_021b354c* sub = obj->sub;
	if (sub) return sub->b56e;
	return 0;
}
