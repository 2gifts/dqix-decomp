#include <globaldefs.h>

void CopyFrom027ffcf4(void*);
extern "C" int func_ov031_0223fc7c(char*, unsigned int, int);
extern "C" int func_ov031_0223e454(void*, const void*, int);

// USA: func_ov031_0223fae8
extern "C" ARM void func_ov031_0223fae8(void* destination) {
    unsigned char bytes[6];
    char encoded[12];
    CopyFrom027ffcf4(bytes);
    int index = 0;
    unsigned char* cursor = bytes;
    int offset = 0;
    do {
        func_ov031_0223fc7c(encoded + offset, *cursor, 2);
        ++cursor;
        ++index;
        offset += 2;
    } while (index < 6);
    func_ov031_0223e454(destination, encoded, 12);
}
