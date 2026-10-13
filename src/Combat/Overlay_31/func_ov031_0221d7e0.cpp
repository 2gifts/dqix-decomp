#include "System/OverlayResponse.h"

extern char data_ov031_0224b0dc[];
extern "C" int func_ov031_0221e650(const char*);
extern "C" void func_ov031_0221e354(void*, int, const char*, int);
extern "C" int func_ov031_0221e4fc(unsigned char*, unsigned char*, int);
// USA: func_ov031_0221d7e0
extern "C" THUMB int func_ov031_0221d7e0(ResponseIdentifier* packet, ResponseIdentifier* expected) {
    int result = 0;
    func_ov031_0221e354(expected, 8, data_ov031_0224b0dc, func_ov031_0221e650(data_ov031_0224b0dc));
    if (func_ov031_0221e4fc(packet->prefix, expected->prefix, 6) != 0)
        result--;
    else {
        unsigned short sequence = func_ov031_0221e638(packet->sequence);
        unsigned short expectedSequence = func_ov031_0221e638(expected->sequence);
        if (sequence + 1 != expectedSequence)
            result -= 2;
    }
    return result;
}
