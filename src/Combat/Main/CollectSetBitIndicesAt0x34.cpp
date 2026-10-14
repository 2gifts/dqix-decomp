#include <globaldefs.h>

ARM int TestBitAt0x34_020a35e0(unsigned char* obj, unsigned int index);

// USA: func_020a3634
ARM int CollectSetBitIndicesAt0x34_020a3634(unsigned char* obj, short* outArray) {
    int i;
    int outCount = 0;
    for (i = 0; i < 4; i++) {
        if (TestBitAt0x34_020a35e0(obj, (unsigned char)i)) {
            outArray[outCount] = i;
            outCount++;
        }
    }
    return outCount;
}
