#include <globaldefs.h>

#if defined(jpn)
#define DispatchGlobalWithFields_021d1854 func_ov017_021d1cd8
#endif

struct Src_021d1854 { unsigned char pad0[4]; short h4; short h6; signed char b8; };

int* GetGlobal02109030(void);
extern "C" void func_02094030(int*, short, short, signed char);

// USA: func_ov017_021d1854
#if defined(jpn)
extern "C"
#endif
ARM void DispatchGlobalWithFields_021d1854(void* unused0, Src_021d1854* src) {
	int* g = GetGlobal02109030();
	func_02094030(g, src->h4, src->h6, src->b8);
}
