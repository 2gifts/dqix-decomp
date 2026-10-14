#include <globaldefs.h>

void ClearBitRange_021f6c3c(void*, unsigned int, unsigned int, unsigned int);
extern "C" void func_ov023_021f6d9c(void* a, void* b);
void ClearBit_021f6e34(void* obj, int idx, unsigned int bit);

// USA: func_ov023_021fb640
ARM void ApplyFieldsToObj_021fb640(void* p, void* obj) {
    ClearBitRange_021f6c3c(obj, ((unsigned char*)p)[0x7e], *(unsigned short*)((char*)p + 0x90), 1);
    func_ov023_021f6d9c(obj, (char*)p + 0x94);
    ClearBit_021f6e34(obj, ((unsigned char*)p)[0x7e], *(unsigned int*)((char*)p + 0x5c));
}
