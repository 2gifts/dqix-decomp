#include <globaldefs.h>

#if defined(jpn)
#define ResetAllocatorAndCallInner02154da8 func_ov005_02156408
enum { kInnerPrefix = 0x164 };
#else
enum { kInnerPrefix = 0x1ec };
#endif


#include "Memory/SafeAllocator.h"

struct Obj02154da8 {
	char pad[0x26c];
	SafeAllocator allocator;
};
struct Level2_02154da8 { char pad2[0x1800]; int field; };
struct Mid02154da8 { char pad[kInnerPrefix]; Level2_02154da8 lvl2; };

extern "C" void func_ov023_021dad78(void* p);
extern "C" void func_ov023_021dad8c(void* p, void* allocator, int a, int b);

// USA: func_ov005_02154da8
#if defined(jpn)
extern "C"
#endif
ARM void ResetAllocatorAndCallInner02154da8(Mid02154da8* obj, int a, int b) {
	SafeAllocator* alloc = (SafeAllocator*)((char*)obj + 0x26c);
	alloc->Reset();
	func_ov023_021dad78(&obj->lvl2.field);
	func_ov023_021dad8c(&obj->lvl2.field, alloc, a, b);
}
