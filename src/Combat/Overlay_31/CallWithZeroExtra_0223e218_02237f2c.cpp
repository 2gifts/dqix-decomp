#include <globaldefs.h>

struct Header_0223bd28;
void ExtractPackedHiLo_0223bd28(Header_0223bd28*, int, unsigned int*, unsigned int*);
extern "C" void func_ov031_022381c8(int);
ARM void* CallWithZeroExtra_0223e218(void* a, void* b, void* c, int d);
extern "C" void func_ov031_0223815c(void);
extern "C" void func_ov031_02238000(void);
extern "C" void func_ov031_0223e2c0(int, void*);

struct Struct02237f2c {
    Header_0223bd28* header;
    unsigned char pad[0x14 - 4];
    void* field14;
    unsigned char pad2[0x1c - 0x18];
    unsigned char field1c;
};
extern Struct02237f2c* data_ov031_02290d10;

extern unsigned short data_ov031_02249336[];

// USA: func_ov031_02237f2c  (semantic: CheckDiffAgainstThresholdThenSetup_02237f2c)
#pragma optimize_for_size off
extern "C" ARM void func_ov031_02237f2c(void* arg) {
    unsigned int outHi, outLo;
    ExtractPackedHiLo_0223bd28(data_ov031_02290d10->header, 0, &outHi, &outLo);
    outLo = outLo - 0xc;
    unsigned short threshold = data_ov031_02249336[data_ov031_02290d10->field1c * 2];
    if ((int)outLo > threshold) {
        func_ov031_022381c8(outLo);
        return;
    }
    func_ov031_022381c8(threshold);
    if (data_ov031_02290d10->field1c == 5) {
        data_ov031_02290d10->field14 = CallWithZeroExtra_0223e218(0, (void*)func_ov031_0223815c, 0, 0x78);
    } else {
        data_ov031_02290d10->field14 = CallWithZeroExtra_0223e218(0, (void*)func_ov031_02238000, 0, 0x78);
    }
    func_ov031_0223e2c0(1, arg);
}
