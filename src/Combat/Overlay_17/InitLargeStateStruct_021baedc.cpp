// JPN: func_ov017_021bb4d4
#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

#if defined(jpn)
enum { LaterFieldShift = -0x4 };
#else
enum { LaterFieldShift = 0x0 };
#endif

struct ByteHeader0204693c;
void ResetByteHeader(struct ByteHeader0204693c* p);

struct Obj021bb088;
void InitTimerObj_021bb088(struct Obj021bb088* p);

extern "C" void* func_ov017_0218b5b0(void);
unsigned int GetBitsInField0(unsigned int* obj, unsigned int mask);

struct BitField0x178_021baedc { unsigned char bit0:1; unsigned char rest:7; };

// USA: func_ov017_021baedc  (semantic: InitLargeStateStruct_021baedc)
extern "C" ARM void func_ov017_021baedc(void* self, int flag) {
	char* base = (char*)self;
	ResetByteHeader((struct ByteHeader0204693c*)base);
	*(signed char*)(base + 0x0) = 4;
	*(short*)(base + 0x8) = 0;
	*(short*)(base + 0xa) = 0;
	*(int*)(base + 0x90 + LaterFieldShift) = 0;
	*(unsigned short*)(base + 0x11a + LaterFieldShift) = 0;
	*(short*)(base + 0x14e + LaterFieldShift) = -1;
	*(unsigned char*)(base + 0x9c + LaterFieldShift) = 0;
	*(unsigned char*)(base + 0x98 + LaterFieldShift) = 0;
	*(unsigned char*)(base + 0x99 + LaterFieldShift) = 0;
	*(unsigned char*)(base + 0x9a + LaterFieldShift) = 0;
	*(unsigned char*)(base + 0x9b + LaterFieldShift) = 0;
	*(unsigned char*)(base + 0xcc + LaterFieldShift) = 0;
	*(unsigned char*)(base + 0xcd + LaterFieldShift) = 0;
	*(signed char*)(base + 0xa0 + LaterFieldShift) = -1;
	*(int*)(base + 0x110 + LaterFieldShift) = -1;
	*(unsigned char*)(base + 0xfe + LaterFieldShift) = 0;
	*(unsigned char*)(base + 0x100 + LaterFieldShift) = 0;
	*(unsigned char*)(base + 0x101 + LaterFieldShift) = 0;
	*(unsigned char*)(base + 0x102 + LaterFieldShift) = 0;
	*(unsigned char*)(base + 0x103 + LaterFieldShift) = 0;
	*(unsigned char*)(base + 0x104 + LaterFieldShift) = 0;
	*(unsigned char*)(base + 0x106 + LaterFieldShift) = 0;
	*(unsigned char*)(base + 0x107 + LaterFieldShift) = 0;
	*(unsigned char*)(base + 0x108 + LaterFieldShift) = 0;
	*(unsigned char*)(base + 0x109 + LaterFieldShift) = 0;
	*(unsigned char*)(base + 0x10a + LaterFieldShift) = 0;
	*(unsigned char*)(base + 0x10b + LaterFieldShift) = 0;
	*(unsigned char*)(base + 0x10c + LaterFieldShift) = 0;
	if (flag == 0) {
		*(unsigned char*)(base + 0x105 + LaterFieldShift) = 0;
	}
	if (flag == 0) {
		*(unsigned short*)(base + 0x11c + LaterFieldShift) = 0;
	}
	memset(base + 0xc, 0, 0x68);
	*(unsigned short*)(base + 0x114 + LaterFieldShift) = 0;
	InitTimerObj_021bb088((struct Obj021bb088*)(base + 0xd0 + LaterFieldShift));
	if (GetBitsInField0((unsigned int*)func_ov017_0218b5b0(), 0x1000) == 0) {
		((SafeAllocator*)(base + 0x7c + LaterFieldShift))->ResetAllocatorPointer();
	}
	*(int*)(base + 0x120 + LaterFieldShift) = 0;
	((SafeAllocator*)(base + 0x124 + LaterFieldShift))->ResetAllocatorPointer();
	memset(base + 0x13c + LaterFieldShift, 0, 0x12);
	memset(base + 0x150 + LaterFieldShift, 0, 0xa);
	*(int*)(base + 0x15c + LaterFieldShift) = 0;
	*(unsigned char*)(base + 0xfd + LaterFieldShift) = 0;
	*(signed char*)(base + 0x116 + LaterFieldShift) = -1;
	*(int*)(base + 0x160 + LaterFieldShift) = 0;
	*(unsigned char*)(base + 0x164 + LaterFieldShift) = 1;
	*(int*)(base + 0x170 + LaterFieldShift) = 0;
	*(int*)(base + 0x168 + LaterFieldShift) = 0;
	*(int*)(base + 0x16c + LaterFieldShift) = 0;
	*(int*)(base + 0x138 + LaterFieldShift) = 0;
	*(unsigned char*)(base + 0xff + LaterFieldShift) = 0;
	*(unsigned char*)(base + 0x174 + LaterFieldShift) = 0;
	*(unsigned char*)(base + 0x175 + LaterFieldShift) = 0;
	((BitField0x178_021baedc*)(base + 0x178 + LaterFieldShift))->bit0 = 0;
	((BitField0x178_021baedc*)(base + 0x178 + LaterFieldShift))->rest = 0;
	*(unsigned char*)(base + 0x179 + LaterFieldShift) = 0;
	*(unsigned char*)(base + 0x17a + LaterFieldShift) = 0;
	*(unsigned char*)(base + 0x17b + LaterFieldShift) = 0;
	*(float*)(base + 0x17c + LaterFieldShift) = -1.0f;
	*(unsigned short*)(base + 0x184 + LaterFieldShift) = 0;
	memset(base + 0x188 + LaterFieldShift, 0, 0x30);
	memset(base + 0x1b8 + LaterFieldShift, 0, 0x10);
}
