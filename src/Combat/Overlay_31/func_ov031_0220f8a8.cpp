#include <globaldefs.h>
#include "System/Memory.h"

struct Request0220f8a8 {
    int type;
    int parameter;
    int unknown_0x8;
    const unsigned char* source;
    int unknown_0x10;
    unsigned int length;
    unsigned int consumed;
    int unknown_0x1c;
    int successful;
    unsigned int received;
};
struct Context0220f8a8 {
    char padding[0x24];
    Request0220f8a8* request;
};
struct Message0220f8a8 {
    unsigned int size;
    unsigned int signature;
    int command;
    int parameter;
    unsigned int length;
    unsigned char payload[0x400];
};
extern Context0220f8a8* data_ov031_0224e580;
extern "C" int func_ov031_0220fe44(int (*)(int*));
extern "C" int func_ov031_0220ff34(int*);
int IsField0Unchanged_0220ff18(void*);
void WaitForField2CNonZero_0220fea0();
void ClearField28SetField2C_0220fed8();

// USA: func_ov031_0220f8a8
extern "C" ARM void func_ov031_0220f8a8() {
    unsigned char storage[sizeof(Message0220f8a8)];
    Message0220f8a8* message = (Message0220f8a8*)storage;
    const unsigned char* source = data_ov031_0224e580->request->source;
    unsigned int consumed = data_ov031_0224e580->request->length;
    if (consumed > 0x400) consumed = 0x400;
    message->size = consumed + 20;
    message->signature = 0x44535359;
    message->command = 0xcd;
    message->length = data_ov031_0224e580->request->length;
    message->parameter = data_ov031_0224e580->request->parameter;
    VectorizedInvertedMemcpy(source, message->payload, consumed);
    if (func_ov031_0220fe44(func_ov031_0220ff34)) {
        if (IsField0Unchanged_0220ff18(storage)) {
            int last = 1;
            if (consumed < data_ov031_0224e580->request->length) do {
                unsigned int amount = data_ov031_0224e580->request->length - consumed;
                last = 1;
                if (amount > 0x400) { amount = 0x400; last = 0; }
                message->signature = 0x44535359;
                message->command = 0xcf;
                message->size = amount + 20;
                message->parameter = !last;
                message->length = amount;
                VectorizedInvertedMemcpy(source + consumed, message->payload, amount);
                if (!IsField0Unchanged_0220ff18(storage)) break;
                consumed += amount;
                data_ov031_0224e580->request->consumed = consumed;
            } while (consumed < data_ov031_0224e580->request->length);
            if (last) {
                WaitForField2CNonZero_0220fea0();
                Request0220f8a8* request = data_ov031_0224e580->request;
                if (consumed != request->received) request->successful = 0;
            }
        }
    }
    ClearField28SetField2C_0220fed8();
}
