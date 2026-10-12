#include <globaldefs.h>

#if defined(jpn)
enum { kGlobalHolderInnerOffset = 0x4 };
#else
enum { kGlobalHolderInnerOffset = 0xc };
#endif


#if defined(jpn)
#define SetField5e8_021e80d8 func_ov025_021e8578
#endif

struct Holder021e80d8 {
    char pad0[kGlobalHolderInnerOffset];
    unsigned char* inner;
};

extern struct Holder021e80d8 data_ov025_021ef988;
extern "C" void func_ov025_021ed344(unsigned char* obj, int val);

// USA: func_ov025_021e80d8
#if defined(jpn)
extern "C"
#endif
ARM int SetField5e8_021e80d8(unsigned short* in) {
    func_ov025_021ed344(data_ov025_021ef988.inner + 0x5e8, in[4]);
    return 1;
}
