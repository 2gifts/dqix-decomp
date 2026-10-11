#include <globaldefs.h>

#if defined(jpn)
enum { kRegionValue89C_818 = 0x818 };
enum { kRegionValue1006_F82 = 0xf82 };
enum { kRegionValue1014_F90 = 0xf90 };
enum { kRegionValue835_7B1 = 0x7b1 };
enum { kRegionValue800_700 = 0x700 };
enum { kRegionValue48_C4 = 0xc4 };
enum { kRegionValue1000_F00 = 0xf00 };
enum { kRegionValue3A_B6 = 0xb6 };
#else
enum { kRegionValue89C_818 = 0x89c };
enum { kRegionValue1006_F82 = 0x1006 };
enum { kRegionValue1014_F90 = 0x1014 };
enum { kRegionValue835_7B1 = 0x835 };
enum { kRegionValue800_700 = 0x800 };
enum { kRegionValue48_C4 = 0x48 };
enum { kRegionValue1000_F00 = 0x1000 };
enum { kRegionValue3A_B6 = 0x3a };
#endif


short FindMappedMemberId02080468(void* obj, int id);

// USA: func_ov003_02178548  (semantic: UpdateMappedIndexAndRemainder_02178548)
// JPN: func_ov003_02177428
extern "C" ARM void func_ov003_02178548(unsigned char* self) {
	void* obj89c = *(void**)(self + kRegionValue89C_818);
	short id1 = FindMappedMemberId02080468(obj89c, 3);
	short base6 = *(short*)(self + kRegionValue1006_F82);
	int diff = base6 - id1;
	short mult = *(short*)(self + kRegionValue1014_F90);
	short idx = (short)(mult * 6 + diff);

	unsigned char byteVal = *(unsigned char*)(self + kRegionValue835_7B1);
	if ((int)byteVal <= (int)idx) {
		idx = (short)(byteVal - 1);
	}

	short v = *(short*)(self + kRegionValue800_700 + idx * 2 + kRegionValue48_C4);
	*(short*)(self + kRegionValue1000_F00 + kRegionValue3A_B6) = v;

	short id2 = FindMappedMemberId02080468(obj89c, 3);
	int rem = idx % 6;
#if defined(jpn)
	*(short*)(self + 0xf00 + 0x82) = (short)(rem + id2);
#else
	*(short*)(self + 0x1000 + 6) = (short)(rem + id2);
#endif
}
