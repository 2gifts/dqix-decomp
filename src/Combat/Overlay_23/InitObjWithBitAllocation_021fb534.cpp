#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_ov023_021f6ed8(void* obj);
extern "C" void* func_ov011_021849c8(void* x);
extern "C" int func_ov023_021f6c90(void* list, int elemIndex, int flag);
ARM void SetBitsInArray021f6bec(void* obj, int elemIndex, unsigned int startBit, unsigned int count);
struct InitStruct02075cdcStruct;
void InitStruct02075cdc(struct InitStruct02075cdcStruct* s);
extern "C" void* func_0203bd08(void);
extern "C" void* func_0203be40(void);
extern "C" void* func_0203be4c(void);
int FindClearBit_021f6e5c(void* obj, int idx);
void SetBit_021f6e10(void* obj, int idx, unsigned int bit);
struct Obj021fb8dc;
extern "C" void func_ov023_021fb8dc(struct Obj021fb8dc* obj, void* keyObj);

// JPN: func_ov023_021fa8dc
// USA: func_ov023_021fb534  (semantic: InitObjWithBitAllocation_021fb534)
extern "C" ARM int func_ov023_021fb534(void* obj, void* ctx, unsigned short arg2, unsigned short arg3, unsigned int arg4, int arg5) {
    func_ov023_021f6ed8(obj);
    *(unsigned short*)((char*)obj + 0x4) = 0xc;
    *(unsigned short*)((char*)obj + 0x6) = arg2;
    *(unsigned short*)((char*)obj + 0x8) = arg3;
    *(unsigned short*)((char*)obj + 0xa) = 0;
    *(unsigned int*)((char*)obj + 0x10) = arg4;
    void* list = func_ov011_021849c8(ctx);
    int flagIdx = func_ov023_021f6c90(list, arg5, 1);
    SetBitsInArray021f6bec(list, arg5, flagIdx, 1);
    InitStruct02075cdc((struct InitStruct02075cdcStruct*)((char*)obj + 0x20));
    void* base;
    if (arg5 == 0) {
        func_0203bd08();
        base = func_0203be40();
    } else {
        func_0203bd08();
        base = func_0203be4c();
    }
    *(void**)((char*)obj + 0x34) = (char*)base + flagIdx * 8;
    *(unsigned int*)((char*)obj + 0x58) = 0;
    int bit = FindClearBit_021f6e5c(list, arg5);
    SetBit_021f6e10(list, arg5, bit);
    *(unsigned int*)((char*)obj + 0x5c) = bit & 0xf;
    *(unsigned int*)((char*)obj + 0x60) = 0;
    *(unsigned char*)((char*)obj + 0x7e) = (unsigned char)arg5;
    *(unsigned short*)((char*)obj + 0xa4) = 0;
    memset((char*)obj + 0x94, 0, 0x10);
    *(unsigned int*)((char*)obj + 0xa8) = 0;
    *(unsigned int*)((char*)obj + 0xac) = 0;
#if defined(jpn)
    *(unsigned char*)((char*)obj + 0xb0) = 0;
#else
    *(unsigned char*)((char*)obj + 0xb0) = 0;
    *(unsigned char*)((char*)obj + 0xb1) = 0;
#endif
    func_ov023_021fb8dc((struct Obj021fb8dc*)obj, ctx);
    return 1;
}
