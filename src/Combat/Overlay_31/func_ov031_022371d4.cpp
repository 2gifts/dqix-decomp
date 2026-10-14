#include <globaldefs.h>

struct Header_0223bd28;
void ExtractPackedHiLo_0223bd28(Header_0223bd28*, int, unsigned int*, unsigned int*);
extern "C" void func_ov031_0223bbd8(void*, int, int, int);
extern "C" void func_ov031_0223e2b8(void*, int);
extern "C" void func_ov031_022372b0(void*);

struct Base022371d4 { char pad[4]; int* p; };
extern Base022371d4 data_ov031_02290d04;

struct Entry0224926a { unsigned short lo; unsigned short hi; };
extern Entry0224926a data_ov031_0224926a[];

// USA: func_ov031_022371d4  (semantic: DispatchEntriesFromIndex1_022371d4)
#pragma optimize_for_size off
extern "C" ARM void func_ov031_022371d4(void* obj) {
	unsigned int outHi, outLo;
	ExtractPackedHiLo_0223bd28((Header_0223bd28*)data_ov031_02290d04.p[1], 0, &outHi, &outLo);
	outHi = outHi - 8;
	if ((int)outHi > 0x20) {
		int i = 1;
		do {
			Entry0224926a* e = &data_ov031_0224926a[i];
			func_ov031_0223bbd8((void*)data_ov031_02290d04.p[i], -1, outHi, e->hi);
			i++;
		} while (i < 5);
		return;
	}
	outHi = 0x20;
	{
		int i = 1;
		do {
			Entry0224926a* e = &data_ov031_0224926a[i];
			func_ov031_0223bbd8((void*)data_ov031_02290d04.p[i], -1, outHi, e->hi);
			i++;
		} while (i < 5);
	}
	func_ov031_0223e2b8(obj, (int)func_ov031_022372b0);
}
