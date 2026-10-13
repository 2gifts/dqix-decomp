#include <globaldefs.h>

struct PacketIdentifier0221d7e0 {
    unsigned char prefix[6];
    unsigned short sequence;
};
extern char data_ov031_0224b0dc[];
extern "C" int func_ov031_0221e650(const char*);
extern "C" void func_ov031_0221e354(void*, int, const char*, int);
extern "C" int func_ov031_0221e4fc(unsigned char*, unsigned char*, int);
extern "C" unsigned short func_ov031_0221e638(short);

static inline unsigned short SwapUnsignedHalfword(unsigned short value) {
    typedef unsigned short (*UnsignedHalfwordSwap)(unsigned short);
    UnsignedHalfwordSwap swap = (UnsignedHalfwordSwap)func_ov031_0221e638;
    return swap(value);
}

// USA: func_ov031_0221d7e0
extern "C" THUMB int func_ov031_0221d7e0(PacketIdentifier0221d7e0* packet, PacketIdentifier0221d7e0* expected) {
    int result = 0;
    func_ov031_0221e354(expected, 8, data_ov031_0224b0dc, func_ov031_0221e650(data_ov031_0224b0dc));
    if (func_ov031_0221e4fc(packet->prefix, expected->prefix, 6) != 0)
        result--;
    else {
        unsigned short sequence = SwapUnsignedHalfword(packet->sequence);
        unsigned short expectedSequence = SwapUnsignedHalfword(expected->sequence);
        if (sequence + 1 != expectedSequence)
            result -= 2;
    }
    return result;
}
