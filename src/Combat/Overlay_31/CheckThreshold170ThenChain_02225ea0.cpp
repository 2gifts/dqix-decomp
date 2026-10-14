#include <globaldefs.h>

struct Header_0223bd28;
void ExtractPackedHiLo_0223bd28(Header_0223bd28*, int, unsigned int*, unsigned int*);
extern "C" void func_ov031_022266b0(int a, int b);
extern "C" void func_ov031_022269d8(void);
extern "C" void func_ov031_0223e2b8(void* obj, void* v);
void RunFourStagesB_02225f14(void);

struct Struct02225ea0 { unsigned char pad[0x40]; Header_0223bd28* header; };
extern Struct02225ea0* data_ov031_02250c00;

#pragma optimize_for_size off
// USA: func_ov031_02225ea0  (semantic: CheckThreshold170ThenChain_02225ea0)
extern "C" ARM void func_ov031_02225ea0(void* arg) {
    unsigned int outHi, outLo;
    ExtractPackedHiLo_0223bd28(data_ov031_02250c00->header, 0, &outHi, &outLo);
    int off = (int)outLo - 0xc;
    outLo = (unsigned int)off;
    if (off > 0xaa) {
        func_ov031_022266b0(4, off);
        return;
    }
    func_ov031_022266b0(4, 0xaa);
    func_ov031_022269d8();
    func_ov031_0223e2b8(arg, (void*)RunFourStagesB_02225f14);
}
