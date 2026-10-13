#include <globaldefs.h>

struct PacketHeader0221df48 {
    unsigned char id;
    unsigned char type;
    unsigned short length;
    unsigned short offset;
    unsigned char payload[1];
};
struct PacketFlags0221df48 {
    char pad_0[0x1d];
    signed char id;
};
struct PacketState0221df48 {
    char pad_0[0x24];
    void* data;
    int length;
};
extern PacketFlags0221df48 data_ov031_0224e700;
extern PacketState0221df48 data_ov031_0224e6e0;
extern "C" void func_ov031_0221e51c(void*, const void*, unsigned int);
extern "C" unsigned short func_ov031_0221e5f8(unsigned short);
extern "C" unsigned int func_ov031_0221e5d0(unsigned int);

// USA: func_ov031_0221df48
extern "C" THUMB short func_ov031_0221df48(PacketHeader0221df48* packet) {
    short total = 0;
    packet->id = data_ov031_0224e700.id;
    packet->type = 1;
    short length = data_ov031_0224e6e0.length;
    func_ov031_0221e51c(packet->payload, data_ov031_0224e6e0.data, length);
    packet->length = func_ov031_0221e5f8(length);
    short offset = (((short)(length + 6) + 1) / 2) * 2;
    packet->offset = func_ov031_0221e5f8(offset);
    total += offset;
    PacketHeader0221df48* extra = (PacketHeader0221df48*)((unsigned char*)packet + offset);
    extra->id = 0x60;
    extra->type = 0;
    extra->offset = func_ov031_0221e5f8(0);
    unsigned int value = func_ov031_0221e5d0(14);
    func_ov031_0221e51c(extra->payload, &value, 4);
    extra->length = func_ov031_0221e5f8(4);
    total += 10;
    return total;
}
