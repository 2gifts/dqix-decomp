#include <globaldefs.h>

struct ResponseHeader {
    unsigned char field_0x0[10];
    unsigned short protocol;
    unsigned char field_0xc[4];
    unsigned char token[8];
};
struct ResponseBody {
    unsigned char type;
    unsigned char field_0x1;
    unsigned short identifier;
    unsigned int error;
};
struct ResponseMessage {
    unsigned char field_0x0[12];
    ResponseHeader header;
    ResponseBody body;
};
struct ExpectedResponse {
    unsigned char field_0x0[8];
    unsigned char token[8];
};
struct ResponseFlags {
    unsigned char field_0x0[44];
    unsigned int expected;
    unsigned int received;
};
extern unsigned char data_ov031_0224eda0[];
extern unsigned char data_ov031_0224e720[];
extern ResponseFlags data_ov031_0224e6e0;
extern "C" int func_ov031_0221d7e0(const void* first, const void* second);
extern "C" unsigned short func_ov031_0221e638(short value);
typedef unsigned short (*UnsignedByteSwap16)(unsigned short value);
extern "C" unsigned int func_ov031_0221e610(unsigned int value);
extern "C" void func_ov031_0221d060(int error);
extern "C" void func_ov031_0221e52c(void* destination, int value, unsigned int size);
extern "C" int func_ov031_0221db48(int index, ResponseBody* body, int protocol, void* data, void* output);

// USA: func_ov031_0221d52c
extern "C" THUMB int func_ov031_0221d52c(int state, ResponseMessage* message, int* retries, ExpectedResponse* expected) {
    if (state != 1) {
        ++*retries;
        return state;
    }
    ResponseHeader* header = &message->header;
    ResponseBody* body = &message->body;
    if (func_ov031_0221d7e0(expected->token, header->token) < 0) {
        ++*retries;
        return state;
    }
    if (!((UnsignedByteSwap16)func_ov031_0221e638)(body->identifier)) {
        ++*retries;
        return state;
    }
    if (body->type == 7) {
        if (func_ov031_0221e610(body->error) == (unsigned int)-2)
            func_ov031_0221d060(20);
        else if (func_ov031_0221e610(body->error) == (unsigned int)-3)
            func_ov031_0221d060(21);
        else
            func_ov031_0221d060(24);
        return -1;
    }
    func_ov031_0221e52c(data_ov031_0224eda0, 0, 0x6a0);
    if (func_ov031_0221db48(0, body, ((UnsignedByteSwap16)func_ov031_0221e638)(header->protocol),
            data_ov031_0224eda0, data_ov031_0224e720) < 0) {
        ++*retries;
        return state;
    }
    if (!(data_ov031_0224e6e0.received & data_ov031_0224e6e0.expected))
        return state;
    *retries = 0;
    return 2;
}
