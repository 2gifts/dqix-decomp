#include <globaldefs.h>

#if defined(jpn)
enum { BUFFER_OFFSET = 0x24 };
#else
enum { BUFFER_OFFSET = 0x28 };
#endif


#if defined(jpn)
#define CallFunc0204b04cIfNotFlag0Set_021f7884 func_ov023_021f6d7c
#endif

extern "C" void func_0204b04c(void* obj, void* p);

struct Obj28_021f7884 { char pad[0xc]; unsigned char flags; };

// USA: func_ov023_021f7884
#if defined(jpn)
extern "C"
#endif
ARM void CallFunc0204b04cIfNotFlag0Set_021f7884(struct Obj28_021f7884* obj) {
	if (obj->flags & 1) return;
	func_0204b04c((char*)obj + BUFFER_OFFSET, NULL);
}
