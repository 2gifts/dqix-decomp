#include <globaldefs.h>

struct Request0221c4bc {
    unsigned int field_0;
    unsigned short length;
    unsigned char text[256];
    short field_106;
    short field_108;
    short field_10a;
    short field_10c;
    short field_10e;
    unsigned char padding[6];
    unsigned char status;
};
struct RequestState0221c4bc {
    unsigned char padding[0x14];
    void* buffer;
};
typedef void (*Callback0221c49c)(int);
typedef void (*Callback0221c4ac)(int);
extern Callback0221c49c data_ov031_0224f4c0;
extern Callback0221c4ac data_ov031_0224f4cc;
extern RequestState0221c4bc data_ov031_0224e6e0;
extern int data_ov031_0224b070;
extern "C" void func_ov031_0221c49c(int);
extern "C" void func_ov031_0221c4ac(int);
extern "C" int func_ov031_0221d384(int);
extern "C" int func_ov031_0221c5ac(Request0221c4bc*);
extern "C" void func_ov031_0221cfdc(void);
extern "C" int func_ov031_0221e5c8(void*);

static inline void* AllocateRequestBuffer(int size) {
    typedef void* (*Allocator)(int);
    Allocator allocator = (Allocator)func_ov031_0221c49c;
    return allocator(size);
}

// USA: func_ov031_0221c4bc
extern "C" THUMB int func_ov031_0221c4bc(Request0221c4bc* request) {
    int valid;
    if (request->field_106 == 0 || request->field_106 < -1 ||
        request->field_108 < -1 || request->field_10a == 0 ||
        request->field_10a < -1 || request->field_10c < -1 ||
        request->field_10e < -1 || request->length == 0 ||
        request->length > 256 || request->text[request->length - 1] != 0)
        valid = -1;
    else
        valid = 0;
    if (data_ov031_0224f4c0 == 0 || data_ov031_0224f4cc == 0)
        valid = -1;
    if (valid == -1) {
        request->status = 15;
        func_ov031_0221cfdc();
        return -1;
    }
    data_ov031_0224e6e0.buffer = AllocateRequestBuffer(0x5f8);
    if (data_ov031_0224e6e0.buffer == 0) {
        request->status = 15;
        func_ov031_0221cfdc();
        return -1;
    }
    func_ov031_0221d384(-1);
    int result = func_ov031_0221c5ac(request);
    func_ov031_0221c4ac((int)data_ov031_0224e6e0.buffer);
    func_ov031_0221cfdc();
    if (data_ov031_0224b070 != -1)
        func_ov031_0221e5c8((void*)data_ov031_0224b070);
    return result;
}
