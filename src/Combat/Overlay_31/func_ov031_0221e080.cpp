#include <globaldefs.h>

struct SendHeader0221e080 {
    unsigned char field_0;
    unsigned char type;
    unsigned short port;
    unsigned int address;
};
extern unsigned char data_ov031_0224e6e0[];
extern unsigned char data_ov031_0224e700[];
extern "C" void func_ov031_0221e52c(void*, int, unsigned int);
extern "C" unsigned short func_ov031_0221e5f8(unsigned short);
extern "C" unsigned int func_ov031_0221e5d0(unsigned int);
extern "C" int func_ov031_0221e5a0(int, const void*, int, int, void*, int);

// USA: func_ov031_0221e080
extern "C" THUMB int func_ov031_0221e080(const void* buffer, int size, int recipient, int channel) {
    SendHeader0221e080 header;
    func_ov031_0221e52c(&header, 0, 8);
    header.type = 2;
    header.port = func_ov031_0221e5f8(0x5790);
    header.address = func_ov031_0221e5d0(*(unsigned int*)(data_ov031_0224e6e0 + 0x34));
    if (recipient == 0xff || *(signed char*)(data_ov031_0224e700 + 0x1c) == 0)
        header.address = -1;
    return func_ov031_0221e5a0(channel, buffer, size, 0, &header, 8);
}
