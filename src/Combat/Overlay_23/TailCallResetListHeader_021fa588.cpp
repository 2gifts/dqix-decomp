#include <globaldefs.h>

#if defined(jpn)
#define func_ov023_021fa588 func_ov023_021f99b0
#endif

struct List020727d8;
void ResetListHeader020727d8(List020727d8* list);

// USA: func_ov023_021fa588  (semantic: TailCallResetListHeader_021fa588)
extern "C" ARM void func_ov023_021fa588(void* p) {
	ResetListHeader020727d8((List020727d8*)((char*)p + 0x20));
}
