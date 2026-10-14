#include <globaldefs.h>

struct Header_0223bd28;
void ExtractPackedHiLo_0223bd28(Header_0223bd28*, int, unsigned int*, unsigned int*);
struct StructFieldC_0223baac;
unsigned char GetFieldC_0223baac(StructFieldC_0223baac*);
extern "C" ARM void func_ov031_0223bab4(void* obj, int index, int val, int zero);

#pragma optimize_for_size off
// USA: func_ov031_02238370
extern "C" ARM void func_ov031_02238370(Header_0223bd28* obj, int threshold) {
    int count = GetFieldC_0223baac((StructFieldC_0223baac*)obj);
    int i = 0;
    if (count <= 0)
        return;
    int zeroVal = i;
    int fullVal = 0x200;
    do {
        unsigned int hi, lo;
        ExtractPackedHiLo_0223bd28(obj, i, &hi, &lo);
        int val;
        if ((int)lo < threshold)
            goto setFull;
        if ((int)lo < 0xc0) {
            val = zeroVal;
            goto haveVal;
        }
    setFull:
        val = fullVal;
    haveVal:
        func_ov031_0223bab4(obj, i, val, 0);
        i++;
    } while (i < count);
}
