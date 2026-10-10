#include <globaldefs.h>

extern "C" void VectorizedMemset(void* dst, int value, unsigned int length);
extern "C" int func_ov031_02201f10(int, int, int);

struct Header02201fac { unsigned char pad0[0xc]; unsigned short f0c; unsigned short f0e; };
struct Src02201fac { unsigned short f0; unsigned short f2; unsigned short f4; unsigned short f6; unsigned short f8; unsigned short fa; unsigned char pad0; unsigned char flags; };
struct Dst02201fac { unsigned char pad0[0x24]; unsigned int f24; unsigned int f28; };
struct Ca80Cache { unsigned char pad0[0x4e]; unsigned short f4e; unsigned char pad1[0x5c - 0x50]; unsigned short f5c; };
struct C980Cache { unsigned char pad0[0x160]; unsigned int f160; };

extern int data_ov031_0224cac4;
extern Ca80Cache data_ov031_0224ca80;
extern C980Cache data_ov031_0224c980;

#define SW16_02201fac(v) (unsigned short)(((v) >> 8) | ((v) << 8))

// USA: func_ov031_02201fac
extern "C" ARM int func_ov031_02201fac(Header02201fac* hdr, Src02201fac* src, unsigned int a, int b) {
	Dst02201fac* dst = (Dst02201fac*)&data_ov031_0224cac4;
	VectorizedMemset(dst, 0, 0x64);
	data_ov031_0224ca80.f4e = SW16_02201fac(src->f2);
	data_ov031_0224ca80.f5c = SW16_02201fac(src->f0);
	data_ov031_0224c980.f160 = ((unsigned int)SW16_02201fac(hdr->f0c) << 16) | SW16_02201fac(hdr->f0e);
	if (src->flags & 0x10) {
		dst->f28 = ((unsigned int)SW16_02201fac(src->f8) << 16) | SW16_02201fac(src->fa);
		return func_ov031_02201f10((int)dst, 4, b);
	}
	dst->f28 = 0;
	unsigned int v = a + (((unsigned int)SW16_02201fac(src->f4) << 16) | SW16_02201fac(src->f6));
	dst->f24 = v;
	if (src->flags & 3) {
		dst->f24 = v + 1;
	}
	return func_ov031_02201f10((int)dst, 0x14, b);
}
