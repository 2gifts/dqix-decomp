#include <globaldefs.h>

struct PacketHeader0221db18 {
    unsigned char type;
    unsigned char flags;
    unsigned short length;
    unsigned short field_4;
};
struct Packet0221db18 { unsigned char prefix[6]; PacketHeader0221db18 header; };
extern "C" unsigned short func_ov031_0221e638(short);
extern "C" void func_ov031_0221e51c(void*, const void*, unsigned int);

static inline int DecodePacketLength(unsigned short value) {
    typedef int (*LengthDecoder)(unsigned short);
    LengthDecoder decode = (LengthDecoder)func_ov031_0221e638;
    return decode(value);
}

// USA: func_ov031_0221db18
extern "C" THUMB int func_ov031_0221db18(Packet0221db18* packet, void* destination) {
    PacketHeader0221db18* header = &packet->header;
    int length = DecodePacketLength(header->length);
    if (length <= 0) return -1;
    if (header->type != 0x70) return -1;
    func_ov031_0221e51c(destination, header + 1, length);
    return 0;
}
