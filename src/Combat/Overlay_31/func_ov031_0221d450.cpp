#include <globaldefs.h>

struct PacketEnvelope0221d450 {
    unsigned char padding[0xc];
    unsigned short flags;
    unsigned char padding_0xe[2];
    unsigned char address[8];
};

struct ResponseFields0221d450 {
    unsigned char kind;
    unsigned char padding;
    unsigned short valid;
    unsigned int status;
};

struct Packet0221d450 {
    unsigned char padding[0xc];
    PacketEnvelope0221d450 envelope;
    ResponseFields0221d450 response;
};
struct Validation0221d450;
extern Validation0221d450 data_ov031_0224e720;
extern int data_ov031_0224e6e0;
extern "C" int func_ov031_0221d7e0(void*, unsigned char*);
extern "C" unsigned short func_ov031_0221e638(unsigned short);
extern "C" unsigned int func_ov031_0221e610(unsigned int);
extern "C" void func_ov031_0221d060(int);
extern "C" int func_ov031_0221d82c(unsigned int*, Validation0221d450*);
extern "C" bool func_ov031_0221dc58(int);

// USA: func_ov031_0221d450
extern "C" THUMB int func_ov031_0221d450(int error, Packet0221d450* packet, int* attempts, void* argument) {
    if (error) {
        ++*attempts;
        return error;
    }
    PacketEnvelope0221d450* outer = &packet->envelope;
    ResponseFields0221d450* inner = &packet->response;
    if (func_ov031_0221d7e0(argument, outer->address) < 0) {
        ++*attempts;
        return error;
    }
    if (!func_ov031_0221e638(inner->valid)) {
        ++*attempts;
        return error;
    }
    if (inner->kind == 7) {
        if (func_ov031_0221e610(inner->status) == 0xfffffffeU) {
            func_ov031_0221d060(20);
        } else if (func_ov031_0221e610(inner->status) == 0xfffffffdU) {
            func_ov031_0221d060(21);
        } else {
            func_ov031_0221d060(24);
        }
        return -1;
    }
    if (inner->kind != 1) {
        ++*attempts;
        return error;
    }
    int result = func_ov031_0221d82c(&inner->status, &data_ov031_0224e720);
    if (result < 0) {
        if (result == -2) {
            func_ov031_0221d060(22);
            return -1;
        }
        ++*attempts;
        return error;
    }
    data_ov031_0224e6e0 = func_ov031_0221dc58(func_ov031_0221e638(outer->flags));
    *attempts = 0;
    return 1;
}
