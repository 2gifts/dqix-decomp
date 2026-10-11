#include <globaldefs.h>
#if defined(jpn)
enum { kRegion5a4 = 0x5a0 };
enum { kRegion4e0 = 0x4dc };
enum { kRegion4ec = 0x4e8 };
enum { kRegion4e8 = 0x4e4 };
#else
enum { kRegion5a4 = 0x5a4 };
enum { kRegion4e0 = 0x4e0 };
enum { kRegion4ec = 0x4ec };
enum { kRegion4e8 = 0x4e8 };
#endif

#include "Filesystem/BackgroundLoader.h"

extern "C" void func_ov003_02168324(void* obj);

// JPN: func_ov003_0216a95c
// USA: func_ov003_0216adbc
ARM void MaybeReset0216adbc(void* obj) {
	if (*(unsigned char*)((char*)obj + kRegion5a4) != 0) return;
	int v = (int)BackgroundLoader::GetInstance();
	((BackgroundLoader*)(v))->MaybeFreeAllocations();
	((BackgroundLoader*)(v))->RemoveTask((int)(*(int*)((char*)obj + kRegion4e0)));
	*(int*)((char*)obj + kRegion4e0) = -1;
	func_ov003_02168324(obj);
	*(unsigned char*)((char*)obj + kRegion4ec) = 6;
	*(unsigned char*)((char*)obj + kRegion4e8) = 0;
}
