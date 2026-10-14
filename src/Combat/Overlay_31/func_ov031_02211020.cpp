#include <globaldefs.h>
#include "System/Memory.h"

struct PoolState02211020 {
    int state;
    int mode;
    void* message;
    void* context;
    unsigned char remaining[0x38];
};
extern PoolState02211020* data_ov031_0224e590;
extern "C" int func_ov031_02211410();
extern "C" void* func_ov031_02211b64(void*, void*, int);
void SetGlobal0224e598IfNotNine_02211864(int, int);
int GetConst4816_02210044();
int GetConst8f4_0220f3f4();
extern "C" void func_ov031_0220f400(void*);
extern "C" void func_ov031_02210050(void*, void*, int);
void SetGlobal0224e588Field30_022101ac(int);
void SetField4AndInvokeCallback_02211440(void*);

// USA: func_ov031_02211020
extern "C" ARM void func_ov031_02211020(void* owner, int mode) {
    unsigned char* allocation = (unsigned char*)func_ov031_02211b64((void*)0x53574300, (void*)func_ov031_02211410(), 32);
    if (!allocation) {
        SetGlobal0224e598IfNotNine_02211864(9, 9 - 10);
        return;
    }
    int offset = 0;
    data_ov031_0224e590 = (PoolState02211020*)allocation;
    VectorizedMemset(allocation, offset, 0x48);
    offset += 0x60;
    data_ov031_0224e590->message = allocation + offset;
    offset += ((unsigned int)(GetConst4816_02210044() + 31) >> 5) << 5;
    data_ov031_0224e590->context = allocation + offset;
    GetConst8f4_0220f3f4();
    data_ov031_0224e590->mode = mode;
    func_ov031_0220f400(data_ov031_0224e590->context);
    func_ov031_02210050(data_ov031_0224e590->message, owner, data_ov031_0224e590->mode);
    SetGlobal0224e588Field30_022101ac((int)SetField4AndInvokeCallback_02211440);
}
