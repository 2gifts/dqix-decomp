#include <globaldefs.h>

struct SessionState0220480c {
    char padding_0x00[0x20];
    unsigned int context;
};

void InitSessionFields_0220321c();
void ResetSessionState02203190();
void UpdateObjFromContext_022031bc(int, unsigned short, unsigned int);
extern "C" unsigned char* func_ov031_02203fdc(void*, int, int);
void* FillRemainder_02204168(int, unsigned int, void*, unsigned int);
extern "C" void func_ov031_02203a84(void*, unsigned int);
void ZeroField164_02203250();
extern SessionState0220480c data_ov031_0224c980;
extern unsigned char data_ov031_0224ced6[0x12c] __attribute__((aligned(2)));

// USA: func_ov031_0220480c
extern "C" ARM void func_ov031_0220480c() {
    InitSessionFields_0220321c();
    ResetSessionState02203190();
    UpdateObjFromContext_022031bc(0x44, 0x43, data_ov031_0224c980.context);
    unsigned char* buffer = data_ov031_0224ced6;
    unsigned char* end = func_ov031_02203fdc(buffer, 7, 0);
    unsigned char terminator = 0xff;
    unsigned char* remainder = end + 1;
    *end = terminator;
    end = remainder;
    end = (unsigned char*)FillRemainder_02204168(0, 0x12c, end, end - buffer);
    func_ov031_02203a84(buffer, end - buffer);
    ZeroField164_02203250();
}
