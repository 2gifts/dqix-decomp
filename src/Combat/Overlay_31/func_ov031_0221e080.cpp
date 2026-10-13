#include <globaldefs.h>

struct SendHeader0221e080 {
    unsigned char field_0;
    unsigned char type;
    unsigned short port;
    unsigned int address;
};
struct SendState0221e080 {
    char pad_0[0x34];
    unsigned int address;
};
struct SendFlags0221e080 {
    char pad_0[0x1c];
    signed char connected;
};
extern SendState0221e080 data_ov031_0224e6e0;
extern SendFlags0221e080 data_ov031_0224e700;
extern "C" void func_ov031_0221e52c(void*, int, unsigned int);
extern "C" unsigned short func_ov031_0221e5f8(unsigned short);
extern "C" unsigned int func_ov031_0221e5d0(unsigned int);
extern "C" int func_ov031_0221e5a0(int, const void*, int, int, const SendHeader0221e080*, int);

// USA: func_ov031_0221e080
extern "C" THUMB int func_ov031_0221e080(const void* buffer, int size, int recipient, int channel) {
    SendHeader0221e080 header;
    func_ov031_0221e52c(&header, 0, 8);
    header.type = 2;
    header.port = func_ov031_0221e5f8(0x5790);
    header.address = func_ov031_0221e5d0(data_ov031_0224e6e0.address);
    if (recipient == 0xff || data_ov031_0224e700.connected == 0)
        header.address = -1;
    return func_ov031_0221e5a0(channel, buffer, size, 0, &header, 8);
}
