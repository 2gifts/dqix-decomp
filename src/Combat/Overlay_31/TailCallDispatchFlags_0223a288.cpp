#include <globaldefs.h>

int TestFlagBitsAndDispatch020d6884_020d6830(int a, unsigned short* b, int c);

struct Outer_0223a288 { unsigned char pad[4]; unsigned char* inner; };
extern struct Outer_0223a288 data_ov031_02290d18;

// USA: func_ov031_0223a288
ARM int TailCallDispatchFlags_0223a288(int c) {
	unsigned char* inner = data_ov031_02290d18.inner;
	return TestFlagBitsAndDispatch020d6884_020d6830((int)(inner + 0x13e0), (unsigned short*)(inner + 0x1c00), c);
}
