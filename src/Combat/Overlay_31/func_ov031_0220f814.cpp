#include <globaldefs.h>

struct Session0220f814 {
    char padding_0[4];
    int identifier;
    char padding[8];
    int unknown_10;
    int unknown_14;
};
struct NetworkContext0220f814 {
    char padding[0x24];
    Session0220f814* session;
};
struct SessionMessage0220f814 {
    unsigned int length;
    unsigned int magic;
    unsigned int command;
    int identifier;
    int unknown_10;
    int unknown_14;

};
extern NetworkContext0220f814* data_ov031_0224e580;
extern "C" int func_ov031_0220fe44(int (*)(int*));
extern "C" int func_ov031_0220f770(int*);
int IsField0Unchanged_0220ff18(void*);
void WaitForField2CNonZero_0220fea0();
void ClearField28SetField2C_0220fed8();

// USA: func_ov031_0220f814
extern "C" ARM void func_ov031_0220f814() {
    char storage[0x414];
    SessionMessage0220f814* message = (SessionMessage0220f814*)storage;
    message->length = 0x18;
    message->magic = 0x44535359;
    NetworkContext0220f814* context = data_ov031_0224e580;
    message->command = 0xdb;
    message->identifier = context->session->identifier;
    message->unknown_10 = context->session->unknown_10;
    message->unknown_14 = context->session->unknown_14;
    if (func_ov031_0220fe44(func_ov031_0220f770)) {
        if (IsField0Unchanged_0220ff18(storage)) {
            WaitForField2CNonZero_0220fea0();
        }
    }
    ClearField28SetField2C_0220fed8();
}
