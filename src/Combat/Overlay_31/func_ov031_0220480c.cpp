#include <globaldefs.h>

struct SessionState0220480c {
    char padding_0x00[0x20];
    unsigned int context;
};

extern "C" void _Z26InitSessionFields_0220321cv();
extern "C" void _Z25ResetSessionState02203190v();
extern "C" void _Z29UpdateObjFromContext_022031bcitj(int, unsigned short, unsigned int);
extern "C" unsigned char* func_ov031_02203fdc(void*, int, int);
extern "C" void* _Z22FillRemainder_02204168ijPvj(int, unsigned int, void*, unsigned int);
extern "C" void func_ov031_02203a84(void*, unsigned int);
extern "C" void _Z21ZeroField164_02203250v();
extern SessionState0220480c data_ov031_0224c980;
extern unsigned char data_ov031_0224ced6[0x12c] __attribute__((aligned(2)));

// USA: func_ov031_0220480c
extern "C" ARM void func_ov031_0220480c() {
    _Z26InitSessionFields_0220321cv();
    _Z25ResetSessionState02203190v();
    _Z29UpdateObjFromContext_022031bcitj(0x44, 0x43, data_ov031_0224c980.context);
    unsigned char* buffer = data_ov031_0224ced6;
    unsigned char* end = func_ov031_02203fdc(buffer, 7, 0);
    unsigned char terminator = 0xff;
    unsigned char* remainder = end + 1;
    *end = terminator;
    end = remainder;
    end = (unsigned char*)_Z22FillRemainder_02204168ijPvj(0, 0x12c, end, end - buffer);
    func_ov031_02203a84(buffer, end - buffer);
    _Z21ZeroField164_02203250v();
}
