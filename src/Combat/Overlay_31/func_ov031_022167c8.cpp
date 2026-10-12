#include <globaldefs.h>
#include "System/Memory.h"

typedef void* (*WorkAllocator022167c8)(const char*, unsigned int);
union WorkCallbacks022167c8 {
    struct {
        char pad_0[0x40];
        WorkAllocator022167c8 allocate;
        int field_44;
    } functions;
    unsigned int words[18];
};
struct InitWork022167c8 {
    char pad_0[0x1004];
    int result;
    struct {
        unsigned int signature;
        char data[0x1c0];
    } buffer;
    union {
        WorkCallbacks022167c8 callbacks;
        struct {
            char pad_0[0x32];
            unsigned short counter;
            char pad_34[0xb];
            unsigned char flag;
        } state;
    } config;
    char pad_1214[0x100];
    void* context;
};
struct InitGlobals022167c8 {
    int state;
    int field_4;
    InitWork022167c8* work;
};
extern InitGlobals022167c8 data_ov031_0224e5e8;
extern const char data_ov031_02249b98[];
extern "C" int func_ov031_02216b90(int);
extern "C" void func_ov031_022168ec();

// USA: func_ov031_022167c8
extern "C" ARM int func_ov031_022167c8(WorkCallbacks022167c8* callbacks, void* context) {
    WorkAllocator022167c8 allocate = callbacks->functions.allocate;
    if (data_ov031_0224e5e8.work) return 2;
    data_ov031_0224e5e8.work = (InitWork022167c8*)allocate(data_ov031_02249b98, 0x13f4);
    if (!data_ov031_0224e5e8.work) return 2;
    VectorizedMemset(data_ov031_0224e5e8.work, 0, 0x13f4);
    data_ov031_0224e5e8.work->context = context;
    data_ov031_0224e5e8.state = 0;
    VectorizedMemset(&data_ov031_0224e5e8.work->buffer, 0, 0x1c4);
    data_ov031_0224e5e8.work->buffer.signature = 0x4e84;
    data_ov031_0224e5e8.work->config.callbacks = *callbacks;
    data_ov031_0224e5e8.work->config.state.counter = 0;
    data_ov031_0224e5e8.work->config.state.flag = 0;
    data_ov031_0224e5e8.work->result = func_ov031_02216b90(1);
    if (data_ov031_0224e5e8.work->result) return data_ov031_0224e5e8.work->result;
    data_ov031_0224e5e8.field_4 = 0;
    func_ov031_022168ec();
    return 0;
}
