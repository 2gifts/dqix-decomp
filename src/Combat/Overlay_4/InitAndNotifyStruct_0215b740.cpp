#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"

void* ZeroInitReturn020de824(void* obj);
void InitStruct0207cbe8(char* obj);
extern "C" void* func_ov004_02156fd4(void* obj, int key);
extern "C" void func_0207d300(void* buf, int a, int b, int c);
extern "C" void func_ov004_0215b7c8(void* obj);
extern "C" void func_ov011_021848a0(void* obj, int val);

// USA: func_ov004_0215b740
ARM int InitAndNotifyStruct_0215b740(void* obj) {
#if defined(jpn)
    enum { memberOffset = 0xc };
#else
    enum { memberOffset = 0x26c };
#endif
    char* p = (char*)GameState::GetInstance() + memberOffset + 0x5c00;
    void* node = func_ov004_02156fd4(obj, 5);
    char buf[0x38];
    ((SafeAllocator*)buf)->ResetAllocatorPointer();
    ZeroInitReturn020de824(buf + 0x14);
    InitStruct0207cbe8(buf);
    InitStruct0207cbe8(buf);
    *(void**)(buf + 0x2c) = node;
    short a = *(short*)(p + 0xf8);
    signed char b = *(unsigned short*)(p + 0xfa);
    func_0207d300(buf, a, b, 0);
    func_ov004_0215b7c8(p + 0xf8);
    func_ov011_021848a0(obj, 0x3a4);
    return 0;
}
