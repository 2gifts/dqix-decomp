#include <globaldefs.h>

int GetFieldAt0x150_02053c6c(unsigned char* obj);
int TestBitInArray0x8ec_02083b00(unsigned char* obj, int index);

// USA: func_020dd290
ARM unsigned int AdjustValueByFieldFlag_020dd290(void* obj, unsigned int val) {
    if (obj == 0) {
        return 0;
    }
    if (val == 0) {
        return 0;
    }
    int field150 = GetFieldAt0x150_02053c6c((unsigned char*)obj);
    if (field150 != 0) {
        if (TestBitInArray0x8ec_02083b00((unsigned char*)field150, 0x106)) {
            val = (unsigned int)(0.75f * (float)val + 0.75f);
        }
    }
    return val;
}
