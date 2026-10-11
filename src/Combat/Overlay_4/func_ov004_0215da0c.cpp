#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"

short SumKeyedLookups02086bf4(char* obj, int key);
void* ZeroInitReturn020de824(void* obj);
void InitStruct0207cbe8(char* obj);
void InitStruct0207cc0c(char* obj);
extern "C" void func_0207cf30(void*, int, int, int);
extern "C" int func_ov004_02156fd4(void*, int);
extern "C" void func_ov011_021848a0(void*, int);
extern "C" void func_ov023_021f65d4(void*, int, int);

struct Struct021707d8_0215da0c { char pad[8]; unsigned char* ptr; };
extern Struct021707d8_0215da0c data_ov004_021707d8;

// USA: func_ov004_0215da0c
extern "C" ARM int func_ov004_0215da0c(void* obj) {
    void* p = GetPtrField0x2a04(GameState::GetInstance());
    int result4 = SumKeyedLookups02086bf4((char*)p, *(short*)(data_ov004_021707d8.ptr + 0xe));

#if !defined(jpn)
    unsigned char flag = data_ov004_021707d8.ptr[0x9d];
    if (!flag) return 0;
#endif

    int r6 = func_ov004_02156fd4(obj, 5);
    if (r6) {
        unsigned char local[0x38];
        ((SafeAllocator*)local)->ResetAllocatorPointer();
        ZeroInitReturn020de824(local + 0x14);
        InitStruct0207cbe8((char*)local);
        InitStruct0207cbe8((char*)local);

        *(int*)(local + 0x2c) = r6;
        func_0207cf30(local, *(short*)(data_ov004_021707d8.ptr + 0xe), data_ov004_021707d8.ptr[0x11], 1);

        InitStruct0207cc0c((char*)local);
#if defined(jpn)
        data_ov004_021707d8.ptr[0xa9] = 0;
#else
        data_ov004_021707d8.ptr[0x9d] = 0;
#endif
    }

    int sum = result4 + data_ov004_021707d8.ptr[0x11];
    if (sum > 0x63) {
        func_ov011_021848a0(obj, 0x2385);
    } else {
        func_ov011_021848a0(obj, 0x38d);
    }
    func_ov023_021f65d4(obj, 2, 8);
    return 0;
}
