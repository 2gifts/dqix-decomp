#include <globaldefs.h>

extern unsigned char data_ov031_0224f440[6];
extern "C" int func_ov031_0221e4fc(const void*, const void*, unsigned int);

// USA: func_ov031_0221d79c
extern "C" THUMB int func_ov031_0221d79c(int code, const void* address) {
    int result = 0;
    int index;
    int present;
    unsigned char* cursor;
    cursor = data_ov031_0224f440;
    present = 0;
    index = 0;
    do {
        if (*cursor != 0) {
            present = 1;
            break;
        }
        index++;
        cursor++;
    } while (index < 6);
    if (present != 0) {
        if (func_ov031_0221e4fc(data_ov031_0224f440, address, 6) != 0) {
            result = 1;
        }
    } else if (code != 0x1000) {
        result = 2;
    }
    return result;
}
