#include <globaldefs.h>

ARM int IsNonzeroAndNotNeg1_02201b94(int a, int b);
extern "C" int func_ov031_022021d4(void* a, void* b, int length);
extern "C" void* func_ov031_02201c84(void* a, void* b);
extern "C" void func_ov031_022020e8(void* header, void* data, void* out);
void CycleCurrentPriorityContexts(void);

struct Header0220225c { unsigned char pad0[0xc]; unsigned short fc; unsigned short fe; unsigned short f10; unsigned short f12; };

// USA: func_ov031_0220225c
extern "C" ARM void func_ov031_0220225c(Header0220225c* header, void* data, int length) {
	unsigned short v12 = header->f12;
	unsigned short v10 = header->f10;
	unsigned short ve = header->fe;
	unsigned short vc = header->fc;
	unsigned short swc = (unsigned short)((vc >> 8) | (vc << 8));
	unsigned short swe = (unsigned short)((ve >> 8) | (ve << 8));
	unsigned short sw10 = (unsigned short)((v10 >> 8) | (v10 << 8));
	unsigned short sw12 = (unsigned short)((v12 >> 8) | (v12 << 8));
	int a = ((unsigned int)swc << 0x10) | swe;
	int b = ((unsigned int)sw10 << 0x10) | sw12;

	if (!IsNonzeroAndNotNeg1_02201b94(a, b)) {
		return;
	}
	if (func_ov031_022021d4(header, data, length) != 0) {
		return;
	}
	void* field = func_ov031_02201c84(header, data);
	if (field != NULL) {
		func_ov031_022020e8(header, data, field);
		return;
	}
	CycleCurrentPriorityContexts();
	field = func_ov031_02201c84(header, data);
	if (field == NULL) {
		return;
	}
	func_ov031_022020e8(header, data, field);
}
