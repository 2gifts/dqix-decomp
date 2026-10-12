#include <globaldefs.h>

#if defined(jpn)
#define BuildChain_021e1b0c func_ov023_021e20c0
#endif

extern "C" void* func_ov023_021e1bac(void* a, int b, int c, int d);

// USA: func_ov023_021e1b0c
#if defined(jpn)
extern "C"
#endif
ARM void BuildChain_021e1b0c(void* a, int b, int c, int d) {
	void* node = func_ov023_021e1bac(a, b, c, d);
	if (node == 0) return;
	*(void**)a = node;
	while (node != 0) {
		void* next = func_ov023_021e1bac(a, b, c, d);
		*(void**)node = next;
		node = next;
	}
}
