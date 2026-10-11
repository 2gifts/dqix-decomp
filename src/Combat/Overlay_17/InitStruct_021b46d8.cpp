#include <globaldefs.h>

struct ByteHeader0204693c;
extern void ResetByteHeader(ByteHeader0204693c* p);

struct Struct021b46d8 {
	unsigned char byte0;
	unsigned char pad1[7];
	int word8;
	int word_c;
	unsigned char byte10;
	unsigned char byte11;
	unsigned short half12;
	int word14;
};

// USA: func_ov017_021b46d8
ARM void InitStruct_021b46d8(struct Struct021b46d8* p) {
	ResetByteHeader((ByteHeader0204693c*)p);
	p->byte0 = 0x14;
	p->word8 = 0;
	p->byte10 = 0;
	p->word_c = -1;
	p->half12 = 0;
#if !defined(jpn)
	p->word14 = 0;
#endif
	p->byte11 = 0;
}
