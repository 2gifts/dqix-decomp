#include <globaldefs.h>
#include "System/Memory.h"

void* CallWithConst32_02211b54(void* context, void* size);
void SetGlobal0224e5a4IfNotNine_ov031_02211b08(int state, int result);
extern "C" void func_020c9be0(void* allocation);
extern "C" void* func_ov031_02211b98(void* context, void* allocation, int size);
extern "C" int func_ov031_022167c8(void* request, void* context);
struct Context022125c8 {
    char padding0[0x1c14];
    char request[0x34];
    char identifier[9];
    char padding1c51[3];
    void* (*allocate)(void*, void*);
    void* (*release)(void*, void*, int);
    char padding1c5c[0x1e20 - 0x1c5c];
};
extern Context022125c8* data_ov031_0224e5bc;
extern const char data_ov031_02249a88[9];

// USA: func_ov031_022125c8
extern "C" ARM int func_ov031_022125c8() {
    if (data_ov031_0224e5bc != NULL) func_020c9be0(data_ov031_0224e5bc);
    data_ov031_0224e5bc = (Context022125c8*)CallWithConst32_02211b54((void*)4, (void*)0x1e20);
    if (data_ov031_0224e5bc == NULL) {
        SetGlobal0224e5a4IfNotNine_ov031_02211b08(9, 0xffffb17c);
        return 0;
    }
    VectorizedMemset(data_ov031_0224e5bc, 0, 0x1e20);
    VectorizedInvertedMemcpy(data_ov031_02249a88, data_ov031_0224e5bc->identifier, 9);
    data_ov031_0224e5bc->allocate = CallWithConst32_02211b54;
    data_ov031_0224e5bc->release = func_ov031_02211b98;
    func_ov031_022167c8(data_ov031_0224e5bc->request, data_ov031_0224e5bc);
    return 1;
}
