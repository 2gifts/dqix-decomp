#include <globaldefs.h>

struct Cont0207fd88;
void CallFunc0204b088OverList0x2c(struct Cont0207fd88* obj);

// USA: func_ov003_0216757c  (semantic: CallOverListIfFlagSet_0216757c)
extern "C" ARM void func_ov003_0216757c(char* obj) {
#if defined(jpn)
    enum { flagOffset = 0x44 };
#else
    enum { flagOffset = 0x74 };
#endif
	if (*(unsigned char*)(obj + flagOffset) != 0) {
		struct Cont0207fd88* p = *(struct Cont0207fd88**)(obj + 0x10);
		if (p != 0) CallFunc0204b088OverList0x2c(p);
	}
}
