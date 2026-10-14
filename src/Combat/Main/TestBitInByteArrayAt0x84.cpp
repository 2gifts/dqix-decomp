#include <globaldefs.h>

int TestBitInByteArray02096100(int unused, unsigned char* arr, int idx);

// USA: func_02096088
ARM int TestBitInByteArrayAt0x84_02096088(void* obj, int idx) {
    return TestBitInByteArray02096100((int)obj, (unsigned char*)obj + 0x84, idx);
}
