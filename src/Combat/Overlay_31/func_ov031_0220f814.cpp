#include <globaldefs.h>

struct Command0220f814 {
    unsigned int words[6];
    char padding[0x414 - 0x18];
};

extern void* data_ov031_0224e580;
extern "C" int func_ov031_0220fe44(int (*callback)(int*));
extern "C" int func_ov031_0220f770(int* command);
int IsField0Unchanged_0220ff18(void* command);
void WaitForField2CNonZero_0220fea0(void);
void ClearField28SetField2C_0220fed8(void);

// USA: func_ov031_0220f814
extern "C" ARM void func_ov031_0220f814(void) {
    Command0220f814 command;
    unsigned int* words = (unsigned int*)&command;
    words[0] = 0x18;
    words[1] = 0x44535359;
    words[2] = 0xdb;
    void* context = data_ov031_0224e580;
    words[3] = *(int*)((char*)(*(void**)((char*)context + 0x24)) + 4);
    words[4] = *(int*)((char*)(*(void**)((char*)context + 0x24)) + 0x10);
    words[5] = *(int*)((char*)(*(void**)((char*)context + 0x24)) + 0x14);
    if (func_ov031_0220fe44(func_ov031_0220f770) != 0) {
        if (IsField0Unchanged_0220ff18(&command) != 0) {
            WaitForField2CNonZero_0220fea0();
        }
    }
    ClearField28SetField2C_0220fed8();
}
