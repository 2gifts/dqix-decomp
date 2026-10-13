#include <globaldefs.h>

struct PacketFields0221dedc { unsigned int field_0; unsigned int field_4; };
extern unsigned char data_ov031_0224e6e0[];
extern char data_ov031_0224b0dc[];
extern "C" void func_ov031_0221e52c(void*, int, unsigned int);
extern "C" void func_ov031_0221e51c(void*, const void*, unsigned int);
extern "C" int func_ov031_0221e650(const char*);
extern "C" void func_ov031_0221e354(PacketFields0221dedc*, int, const char*, int);
extern "C" void func_ov031_0221e028(void*, int, int, int, signed char, signed char, const void*);
extern "C" int func_ov031_0221e080(const void*, int, int, int);

// USA: func_ov031_0221dedc
extern "C" THUMB int func_ov031_0221dedc(int unused, const void* input, int channel) {
    void* buffer = *(void**)(data_ov031_0224e6e0 + 0x14);
    func_ov031_0221e52c(buffer, 0, 1500);
    PacketFields0221dedc fields;
    func_ov031_0221e51c(&fields, (const char*)input + 0x10, 8);
    func_ov031_0221e354(&fields, 8, data_ov031_0224b0dc, func_ov031_0221e650(data_ov031_0224b0dc));
    func_ov031_0221e028(buffer, 0x3000, 0, 0, 0, 0x11, &fields);
    func_ov031_0221e080(buffer, 0x18, 0, channel);
    return 0;
}
