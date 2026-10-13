#include <globaldefs.h>

extern "C" void func_ov028_021d9188(void* a);
void BlankFunction0208be90(void*);
int IsIndexMappedToSelf020a18f4(unsigned int idx);
extern "C" void func_ov001_0215686c(int a);

// USA: func_ov017_021bb8f0
ARM void ForwardTeardown_021bb8f0(char* p) {
	#if defined(jpn)
    void* a = *(void**)(p + 0x15c);
#else
    void* a = *(void**)(p + 0x160);
#endif
	if (a != NULL) func_ov028_021d9188(a);
	#if defined(jpn)
    void* state = *(void**)(p + 0x11c);
#else
    void* state = *(void**)(p + 0x120);
#endif
    if (state != NULL) BlankFunction0208be90(state);
	int r = IsIndexMappedToSelf020a18f4(1);
	if (r == 0) return;
	func_ov001_0215686c(r);
}
