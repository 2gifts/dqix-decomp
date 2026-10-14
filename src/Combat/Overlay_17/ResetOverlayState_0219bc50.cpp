#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Graphics/Model3D.h"
#include "World/Object3D.h"

struct Foo0207df50;
void CopyInternalFields0207df50(struct Foo0207df50* p);

#if defined(jpn)
static const int kModel=0x34b8, kObject=0x34bc, kFields=0x51c;
#else
static const int kModel=0x36c8, kObject=0x36cc, kFields=0x56c;
#endif

// USA: func_ov017_0219bc50
ARM void ResetOverlayState_0219bc50(unsigned char* self) {
	((Model3D*)(*(unsigned char**)(self + kModel)))->Clear();
	((Object3D*)(*(void**)(self + kObject)))->Initialize();
	((SafeAllocator*)(self + 0xb0))->Reset();
	CopyInternalFields0207df50((struct Foo0207df50*)(self + kFields));
}
