#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ByteHeader0204693c;
extern void ResetByteHeader(ByteHeader0204693c* p);

struct Obj021a7d78 {
	unsigned char byte0;
	unsigned char pad0[7];
	SafeAllocator alloc;
	int f1c;
	int f20;
	int f24;
	int f28;
	int f2c;
	short f30;
	short pad30;
	int f34;
	short f38;
	short f3a;
	int f3c;
	int f40;
	int f44;
	int f48;
	int f4c;
};

// USA: func_ov017_021a7d78
ARM void InitObj_021a7d78(Obj021a7d78* p) {
	ResetByteHeader((ByteHeader0204693c*)p);
	p->byte0 = 0x41;
	p->alloc.ResetAllocatorPointer();
	p->f1c = 0;
	p->f20 = 0;
	p->f24 = 0;
	p->f28 = -1;
	p->f2c = 0;
	p->f30 = -1;
	p->f34 = -1;
	p->f38 = 0;
	p->f3a = 0;
#if !defined(jpn)
	p->f3c = 0;
	p->f40 = 0;
	p->f44 = 0;
	p->f48 = 0;
	p->f4c = 0;
#endif
}
