#include <globaldefs.h>

#if defined(jpn)
#define func_ov008_02184968 func_ov008_02185a64
#define ForwardTeardownB_021b9928 func_ov017_021b9e24
extern "C" void ForwardTeardownB_021b9928(char*);
#endif
extern "C" void func_ov008_02184968(void* a);
#if defined(jpn)
#define BlankFunction0208be90 func_0208c768
extern "C" void BlankFunction0208be90(void);
#else
void BlankFunction0208be90(void);
#endif

typedef void (*BlankFn)(void*);

// USA: func_ov017_021b9928
ARM void ForwardTeardownB_021b9928(char* p) {
	void* a = *(void**)(p + 0x118);
	if (a != NULL) func_ov008_02184968(a);
	((BlankFn)BlankFunction0208be90)(p + 0x30);
}
