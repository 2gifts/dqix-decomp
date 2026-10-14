#include <globaldefs.h>

struct Obj5d594 {
    char unk[0x1c];
    unsigned char lowNibble : 4;
    unsigned char highNibble : 4;
};

// USA: func_0205d594
ARM void GetNibbles_0205d594(struct Obj5d594* obj, unsigned char* outLow, unsigned char* outHigh) {
    *outLow = obj->lowNibble;
    *outHigh = obj->highNibble;
}
