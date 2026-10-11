#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void _ZN7Model3D5ClearEv(unsigned char* self);
extern "C" void _ZN8Object3D10InitializeEv(void* p);
struct Foo0207df50;
void CopyInternalFields0207df50(struct Foo0207df50* p);

#if defined(jpn)
static const int kModel=0x34b8, kObject=0x34bc, kFields=0x51c;
#else
static const int kModel=0x36c8, kObject=0x36cc, kFields=0x56c;
#endif

// USA: func_ov017_0219bc50
ARM void ResetOverlayState_0219bc50(unsigned char* self) {
	_ZN7Model3D5ClearEv(*(unsigned char**)(self + kModel));
	_ZN8Object3D10InitializeEv(*(void**)(self + kObject));
	((SafeAllocator*)(self + 0xb0))->Reset();
	CopyInternalFields0207df50((struct Foo0207df50*)(self + kFields));
}
