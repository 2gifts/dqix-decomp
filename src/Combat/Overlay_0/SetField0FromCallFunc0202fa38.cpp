#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"


extern int data_ov000_02183fcc;
extern int data_ov000_02183fe0;
#if defined(jpn)
extern char data_ov000_02185100[];
#endif

struct Struct0216fd0c {
	int field0;
};

// USA: func_ov000_0216fd0c
ARM void SetField0FromCallFunc0202fa38(struct Struct0216fd0c* obj) {
#if defined(jpn)
    obj->field0 = BackgroundLoader::GetInstance()->QueueLoadFile(data_ov000_02185100, (SafeAllocator*)0);
#else
	obj->field0 = ((BackgroundLoader*)((int)BackgroundLoader::GetInstance()))->QueueLoadFileInGP2((const char*)((int)&data_ov000_02183fcc), (const char*)((int)&data_ov000_02183fe0), (SafeAllocator*)(0));
#endif
}
