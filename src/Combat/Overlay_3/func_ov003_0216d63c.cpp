#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"
#include "System/Graphics.h"
#include "World/Object3D.h"

#if defined(jpn)
enum { kRegionValue410_428 = 0x428 };
enum { kRegionValue7E0_768 = 0x768 };
enum { kRegionValueF08_D8C = 0xd8c };
enum { kRegionValue1264_10F4 = 0x10f4 };
enum { kRegionValueF0C_D90 = 0xd90 };
enum { kRegionValue12C0_1150 = 0x1150 };
enum { kRegionValue126C_10FC = 0x10fc };
enum { kRegionValue1408_1298 = 0x1298 };
enum { kRegionValue13FF_128F = 0x128f };
#else
enum { kRegionValue410_428 = 0x410 };
enum { kRegionValue7E0_768 = 0x7e0 };
enum { kRegionValueF08_D8C = 0xf08 };
enum { kRegionValue1264_10F4 = 0x1264 };
enum { kRegionValueF0C_D90 = 0xf0c };
enum { kRegionValue12C0_1150 = 0x12c0 };
enum { kRegionValue126C_10FC = 0x126c };
enum { kRegionValue1408_1298 = 0x1408 };
enum { kRegionValue13FF_128F = 0x13ff };
#endif


struct Struct020dfc40 {
	char data[0x18];
};
struct Struct020a9ea4 {
	char data[8];
};

extern "C" void _Z18InitStruct0205a444Pc(char* obj);
extern "C" void _Z19ResetStruct020dfc40P14Struct020dfc40(struct Struct020dfc40* p);
extern "C" void _Z19ClearStruct020a9ea4P14Struct020a9ea4(struct Struct020a9ea4* p);
extern "C" void func_ov003_0215c650(void* obj);
extern "C" void func_ov003_0216ffbc(void* obj);
extern "C" void func_ov003_02170b74(void* obj);

struct Scene0216d63c {
	unsigned int savedPlanes;
	unsigned short field4;
	unsigned short field6;
	unsigned short field8;
	unsigned short fieldA;
	int fieldC;
	int field10;
	char sub14[kRegionValue410_428 - 0x14];
	char sub410[kRegionValue7E0_768 - kRegionValue410_428];
	char sub7e0[kRegionValueF08_D8C - kRegionValue7E0_768];
	void* activeSub;
	char padf0c[kRegionValue1264_10F4 - kRegionValueF0C_D90];
	int field1264;
	int field1268;
	char sub126c[kRegionValue12C0_1150 - kRegionValue126C_10FC];
	int field12c0;
	int field12c4;
	int field12c8;
	int field12cc;
	int field12d0;
	SafeAllocator allocs[4];
	struct Struct020dfc40 texts;
	Object3D object;
	unsigned char field13e8;
	unsigned char field13e9;
	unsigned char field13ea;
	unsigned char field13eb;
	unsigned char field13ec;
	unsigned char field13ed;
	unsigned char field13ee;
	unsigned char field13ef;
	int field13f0;
	int field13f4;
	char pad13f8[4];
	signed char field13fc[3];
	char pad13ff[kRegionValue1408_1298 - kRegionValue13FF_128F];
	int field1408;
	struct Struct020a9ea4 field140c;
};

// USA: func_ov003_0216d63c
// JPN: func_ov003_0216d10c
extern "C" ARM void func_ov003_0216d63c(struct Scene0216d63c* self) {
	self->savedPlanes = (DISPCNT & 0x1f00) >> 8;
	self->field4 = 0;
	self->field6 = 0;
	self->field8 = 0;
	self->field13ec = 0;
	self->fieldA = 0;
	self->fieldC = 0;
	self->field10 = 0;
	func_ov003_0215c650(self->sub14);
	func_ov003_0216ffbc(self->sub410);
	func_ov003_02170b74(self->sub7e0);
	self->activeSub = self->sub410;
	self->field1264 = 0;
	self->field1268 = 0;
	_Z18InitStruct0205a444Pc(self->sub126c);
	self->field12c0 = 0;
	self->field12c4 = 0;
	self->field12c8 = 0;
	self->field12cc = 0;
	self->field12d0 = 0;
	self->allocs[0].ResetAllocatorPointer();
	self->allocs[1].ResetAllocatorPointer();
	self->allocs[2].ResetAllocatorPointer();
	self->allocs[3].ResetAllocatorPointer();
	_Z19ResetStruct020dfc40P14Struct020dfc40(&self->texts);
	self->object.Initialize();
	self->field13e8 = 0;
	self->field13e9 = 0;
	self->field13ea = 0;
	self->field13eb = 1;
	self->field13ef = 0;
	self->field13f0 = 0;
	self->field13ee = 0;
	self->field13f4 = -1;
	memset(self->field13fc, -1, 3);
	self->field1408 = 0;
	self->field13ed = 0;
	_Z19ClearStruct020a9ea4P14Struct020a9ea4(&self->field140c);
}
