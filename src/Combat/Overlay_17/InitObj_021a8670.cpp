#include <globaldefs.h>
#if defined(jpn)
#define ALLOC_OFFSET 0x1f4
#define RESET_OFFSET 0x208
#else
#define ALLOC_OFFSET 0x264
#define RESET_OFFSET 0x278
#endif
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct ByteHeader0204693c;
void ResetByteHeader(struct ByteHeader0204693c* p);
void InitBigStruct0205c790(char* obj);
struct Struct020dfc40;
void ResetStruct020dfc40(struct Struct020dfc40* p);

// USA: func_ov017_021a8670
ARM void InitObj_021a8670(char* obj) {
	ResetByteHeader((struct ByteHeader0204693c*)obj);
	obj[0] = 0x38;
	*(int*)(obj + 0x8) = 0;
	*(int*)(obj + 0x28) = -1;
	*(int*)(obj + 0xc) = 0;
	*(int*)(obj + 0x10) = 0;
	*(int*)(obj + 0x14) = 0;
	memset(obj + 0x18, 0, 5);
	*(int*)(obj + 0x20) = 0;
	InitBigStruct0205c790(obj + 0x2c);
	((SafeAllocator*)(obj + ALLOC_OFFSET))->ResetAllocatorPointer();
	ResetStruct020dfc40((struct Struct020dfc40*)(obj + RESET_OFFSET));
}
