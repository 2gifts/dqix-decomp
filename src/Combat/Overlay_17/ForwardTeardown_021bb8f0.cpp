#include <globaldefs.h>
#if defined(jpn)
#define ForwardTeardown_021bb8f0 func_ov017_021bbee8
#define func_ov001_0215686c func_ov001_02157f44
#define BlankFunction0208be90 func_0208c768
extern "C" void ForwardTeardown_021bb8f0(char*);
extern "C" void BlankFunction0208be90(void);
#endif

extern "C" void func_ov028_021d9188(void* a);
void BlankFunction0208be90(void);
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
    if (*(void**)(p + 0x11c) != NULL) BlankFunction0208be90();
#else
    if (*(void**)(p + 0x120) != NULL) BlankFunction0208be90();
#endif
	int r = IsIndexMappedToSelf020a18f4(1);
	if (r == 0) return;
	func_ov001_0215686c(r);
}
