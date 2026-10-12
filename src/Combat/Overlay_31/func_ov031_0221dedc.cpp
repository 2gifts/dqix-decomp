#include <globaldefs.h>

struct PacketInput0221dedc {
    char pad_0[0x10];
    char payload[8];
};
struct PacketState0221dedc {
    char pad_0[0x14];
    void* buffer;
};
struct PacketFields0221dedc { unsigned int field_0; unsigned int field_4; };
extern PacketState0221dedc data_ov031_0224e6e0;
extern char data_ov031_0224b0dc[];
extern "C" void func_ov031_0221e52c(void*, int, unsigned int);
extern "C" void func_ov031_0221e51c(void*, const void*, unsigned int);
extern "C" int func_ov031_0221e650(const char*);
extern "C" void func_ov031_0221e354(PacketFields0221dedc*, int, const char*, int);
extern "C" void func_ov031_0221e028(void*, int, int, int, int, int, const PacketFields0221dedc*);
extern "C" int func_ov031_0221e080(const void*, int, int, int);

// USA: func_ov031_0221dedc
extern "C" THUMB int func_ov031_0221dedc(int unused, PacketInput0221dedc* input, int channel) {
    void* buffer = data_ov031_0224e6e0.buffer;
    func_ov031_0221e52c(buffer, 0, 1500);
    PacketFields0221dedc fields;
    func_ov031_0221e51c(&fields, input->payload, 8);
    func_ov031_0221e354(&fields, 8, data_ov031_0224b0dc, func_ov031_0221e650(data_ov031_0224b0dc));
    func_ov031_0221e028(buffer, 0x3000, 0, 0, 0, 0x11, &fields);
    func_ov031_0221e080(buffer, 0x18, 0, channel);
    return 0;
}
