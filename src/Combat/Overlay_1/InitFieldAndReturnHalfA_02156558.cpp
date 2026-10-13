#include <globaldefs.h>

struct Struct02156558 {
	unsigned char pad0[1];
	unsigned char byte1;
	unsigned char pad2[8];
	unsigned short halfA;
};

extern "C" void func_ov001_02154da0(struct Struct02156558* p);
extern "C" void func_ov017_021bb27c(struct Struct02156558* p);

// KEEP-NAME
// USA: func_ov001_02156558
// JPN: func_ov001_02157c64
ARM unsigned short InitFieldAndReturnHalfA_02156558(struct Struct02156558* p) {
	func_ov001_02154da0(p);
	func_ov017_021bb27c(p);
	p->byte1 = 1;
	return p->halfA;
}
