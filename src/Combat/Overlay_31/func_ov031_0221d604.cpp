#include <globaldefs.h>

struct Record0221d604 {
    unsigned char tag;
    unsigned char field_0x1;
    unsigned short length;
    unsigned int status;
};
struct ContextBody0221d604 { char field_0x0[0x10]; char header[8]; Record0221d604 record; };
struct Context0221d604 { char field_0x0[0xc]; ContextBody0221d604 body; };
inline ContextBody0221d604* GetBody0221d604(Context0221d604* context) { return &context->body; }
inline char* GetHeader0221d604(ContextBody0221d604* body) { return body->header; }
struct Packet0221d604 { char field_0x0[0x10]; char data[1]; };
inline void* GetPacketData0221d604(Packet0221d604* packet) { return packet->data; }
extern "C" int func_ov031_0221d7e0(void*, void*);
extern "C" unsigned short func_ov031_0221e638(short);
extern "C" unsigned int func_ov031_0221e610(unsigned int);
typedef unsigned short (*UnsignedSwap16_0221d604)(unsigned short);
inline unsigned short SwapUnsigned16_0221d604(unsigned short value) { return ((UnsignedSwap16_0221d604)func_ov031_0221e638)(value); }
extern "C" void func_ov031_0221d060(int);
inline int ParsePacket0221d604(void* data, ContextBody0221d604* body) { return func_ov031_0221d7e0(data, GetHeader0221d604(body)); }

// USA: func_ov031_0221d604
extern "C" THUMB int func_ov031_0221d604(int state, Context0221d604* context, int* counter, Packet0221d604* packet) {
    if (state != 2) { ++*counter; return state; }
    Record0221d604* record = &context->body.record;
    void* data = GetPacketData0221d604(packet);
    ContextBody0221d604* body = GetBody0221d604(context);
    if (ParsePacket0221d604(data, body) < 0) { ++*counter; return state; }
    if (record->tag != 7) { ++*counter; return state; }
    if (SwapUnsigned16_0221d604(record->length) == 0) { ++*counter; return state; }
    if (func_ov031_0221e610(record->status) == 0) return 100;
    if (func_ov031_0221e610(record->status) == -2) {
        func_ov031_0221d060(20);
        return -1;
    }
    if (func_ov031_0221e610(record->status) == -3) {
        func_ov031_0221d060(21);
        return -1;
    }
    func_ov031_0221d060(24);
    return -1;
}
