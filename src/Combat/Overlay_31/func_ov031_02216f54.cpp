#include <globaldefs.h>
struct State02216f54 {
    char padding_0x0[0x1008];
    int state;
    char padding_0x100c[0x200];
    void* (*allocate)(void*, unsigned int);
    void (*release)(void*, void*, int);
    char padding_0x1214[0x100];
    void* field_0x1314;
};
struct Global02216f54 { int field_0x0, field_0x4; State02216f54* object; };
extern Global02216f54 data_ov031_0224e5e8;
extern char data_ov031_02249bd8, data_ov031_02249be8, data_ov031_0224e5f4;
extern "C" int func_ov031_02218b8c(void*, int);
extern "C" int func_ov031_0221712c();
extern "C" int _Z15Update_0221c208Pvi(void*, int);
extern "C" void func_ov031_0221c258(void*);
extern "C" bool func_ov031_0221c1c4(int);
// USA: func_ov031_02216f54
extern "C" ARM int func_ov031_02216f54() {
    State02216f54* object = data_ov031_0224e5e8.object;
    void* (*allocate)(void*, unsigned int) = object->allocate;
    void (*release)(void*, void*, int) = object->release;
    if (func_ov031_02218b8c(object->field_0x1314, 0) != 1) {
        data_ov031_0224e5e8.object->state = 0x4e84;
        return 14;
    }
    if (func_ov031_0221712c()) return 14;
    int state = data_ov031_0224e5e8.object->state;
    if (state < 0x4e84) {
        if (state == 0x4e22) {
            void* storage = allocate(&data_ov031_02249bd8, 0x71f);
            if (!storage) { data_ov031_0224e5e8.object->state = 0x4e84; return 2; }
            if (_Z15Update_0221c208Pvi(&data_ov031_0224e5f4, ((int)storage + 31) & ~31) != 1) {
                release(&data_ov031_02249be8, storage, 0);
                data_ov031_0224e5e8.object->state = 0x4e84;
                return 15;
            }
            release(&data_ov031_02249be8, storage, 0);
        }
        return 21;
    }
    switch (state) {
    case 0x4e88: {
        func_ov031_0221c258(&data_ov031_0224e5f4);
        data_ov031_0224e5e8.object->state = 0x4e88;
        return 16;
    }
    case 0x4e8c: {
        void* storage = allocate(&data_ov031_02249bd8, 0x700);
        if (!storage) { data_ov031_0224e5e8.object->state = 0x4e8c; return 17; }
        func_ov031_0221c1c4(((int)storage + 31) & ~31);
        release(&data_ov031_02249be8, storage, 0);
        data_ov031_0224e5e8.object->state = 0x4e8c;
        return 17;
    }
    default: break;
    }
    return 18;
}
