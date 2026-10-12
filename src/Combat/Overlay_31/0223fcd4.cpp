typedef void* (*AllocateCallback)(unsigned int, unsigned int);
typedef void (*FreeCallback)(void*);
struct InitContext0223fcd4 {
    int active;
    int error;
    AllocateCallback allocate;
    FreeCallback release;
    int field10;
    int field14;
    void* buffer;
    int field1c;
    int field20;
};
extern InitContext0223fcd4 data_ov031_02290fbc;
int ClearFourWords022918a4_022402f4(void);
extern "C" void func_ov031_0224030c(void);
extern "C" int func_ov031_02240338(int, int);

// USA: func_ov031_0223fcd4
extern "C" int func_ov031_0223fcd4(AllocateCallback allocate, FreeCallback release, int argument) {
    data_ov031_02290fbc.allocate = allocate;
    data_ov031_02290fbc.release = release;
    data_ov031_02290fbc.error = 0;
    data_ov031_02290fbc.field1c = 0;
    data_ov031_02290fbc.field20 = 0;
    data_ov031_02290fbc.field10 = 0;
    data_ov031_02290fbc.field14 = 0;
    switch (ClearFourWords022918a4_022402f4()) {
    case 0:
        data_ov031_02290fbc.error = 9;
        return 0;
    default: break;
    }
    void* buffer = data_ov031_02290fbc.allocate(0x2000, 8);
    data_ov031_02290fbc.buffer = buffer;
    if (!buffer) {
        data_ov031_02290fbc.error = 1;
        func_ov031_0224030c();
        return 0;
    }
    if (func_ov031_02240338(argument, (int)buffer)) {
        data_ov031_02290fbc.active = 1;
        return 1;
    }
    data_ov031_02290fbc.error = 9;
    data_ov031_02290fbc.release(data_ov031_02290fbc.buffer);
    func_ov031_0224030c();
    return 0;
}
