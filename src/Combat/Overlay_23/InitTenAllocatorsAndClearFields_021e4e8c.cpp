#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

extern "C" void _ZN8Object3D10InitializeEv(void* p);

// JPN: func_ov023_021e5080
// USA: func_ov023_021e4e8c
ARM void InitTenAllocatorsAndClearFields_021e4e8c(void* obj) {
	char *base = (char*)obj;
	base[0xc11] = 0;
	for (int i = 0; i < 10; i++) {
		_ZN8Object3D10InitializeEv(base + i * 0xac);
		((SafeAllocator*)(base + 0x6b8 + i * 0x14))->ResetAllocatorPointer();
	}
	((SafeAllocator*)(base + 0x780))->ResetAllocatorPointer();
	base[0xc10] = 0;

#if defined(jpn)
	memset(base + 0xbf4, 0, 0x18);
#else
	for (int i = 0; i < 12; i++) {
		*(short*)(base + 0xbf4 + i * 2) = -1;
	}
#endif
	base[0xc12] = 0;
	base[0xc15] = 0;
	*(int*)(base + 0xc18) = 0;
	base[0xc14] = 1;
}
