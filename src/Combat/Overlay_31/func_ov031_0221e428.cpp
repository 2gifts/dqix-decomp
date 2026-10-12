#include <globaldefs.h>

extern "C" void func_ov031_0221e51c(void*, const void*, unsigned int);

// USA: func_ov031_0221e428
extern "C" THUMB void func_ov031_0221e428(unsigned char* data, int length, unsigned char* scratch) {
    int half = length / 2;
    func_ov031_0221e51c(scratch, data + half, half);
    func_ov031_0221e51c(scratch + half, data, half);
    func_ov031_0221e51c(data, scratch, length);
}
