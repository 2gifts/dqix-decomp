#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "Resource/Script.h"

struct Struct0x10;
void ZeroStruct0x10_020a810c(Struct0x10* obj);
void InitStruct020a8128(unsigned char* obj);

struct Variant02030b0c { int tag; union { int i; float f; } u; };

struct Struct02030b7c { int field0; void* field4; };

struct TaggedValue02030b44 { int type; union { int i; float f; } value; };

int StringLength_020d2ff0(const char* s);

struct Block020a825c { unsigned int v[4]; };
struct Elem020a825c {
    unsigned char b0, b1, b2, b3;
    unsigned int w4;
    Block020a825c block;
    unsigned short h18, h1a, h1c, gap1e;
    unsigned int w20, w24, w28;
};
struct List020a825c { Elem020a825c* base; unsigned short cap; unsigned short count; };
void AppendElement020a825c(List020a825c* list, Elem020a825c* src);

struct BssHolder020a7f88 { SafeAllocator* allocator; List020a825c* list; };
extern BssHolder020a7f88 data_02109fe0;
extern const char data_020f1b94;

// USA: func_020a7f88
ARM int PopulateElementFromVariantsAndAppend_020a7f88(unsigned char* src) {
    Elem020a825c elem;
    ZeroStruct0x10_020a810c((Struct0x10*)&elem.block);
    InitStruct020a8128((unsigned char*)&elem);
    InitStruct020a8128((unsigned char*)&elem);

    elem.b0 = (unsigned char)((Script::Parameter*)((Variant02030b0c*)src))->ToInt();
    elem.b2 = (unsigned char)((Script::Parameter*)((Variant02030b0c*)(src + 0x8)))->ToInt();
    char* name = (char*)(void*)((Script::Parameter*)((Struct02030b7c*)(src + 0x10)))->ToString();
    elem.h18 = (unsigned short)((Script::Parameter*)((Variant02030b0c*)(src + 0x18)))->ToInt();

    char* blk = (char*)&elem.block;
    *(short*)(blk + 0) = (short)((Script::Parameter*)((Variant02030b0c*)(src + 0x20)))->ToInt();
    *(short*)(blk + 2) = (short)(int)(((Script::Parameter*)((TaggedValue02030b44*)(src + 0x28)))->ToFloat() * 4096.0f);
    *(int*)(blk + 4) = (int)(((Script::Parameter*)((TaggedValue02030b44*)(src + 0x30)))->ToFloat() * 4096.0f);
    *(int*)(blk + 8) = (int)(((Script::Parameter*)((TaggedValue02030b44*)(src + 0x38)))->ToFloat() * 4096.0f);
    *(int*)(blk + 0xc) = (int)(((Script::Parameter*)((TaggedValue02030b44*)(src + 0x40)))->ToFloat() * 4096.0f);

    elem.h1a = (unsigned short)((Script::Parameter*)((Variant02030b0c*)(src + 0x48)))->ToInt();
    elem.h1c = (unsigned short)((Script::Parameter*)((Variant02030b0c*)(src + 0x50)))->ToInt();

    elem.w20 = (unsigned int)(int)(((Script::Parameter*)((TaggedValue02030b44*)(src + 0x58)))->ToFloat() * 4096.0f);
    elem.w24 = (unsigned int)(int)(((Script::Parameter*)((TaggedValue02030b44*)(src + 0x60)))->ToFloat() * 4096.0f);

    int len = StringLength_020d2ff0(name);
    elem.w4 = (unsigned int)data_02109fe0.allocator->Allocate(len + 1);
    sprintf((char*)elem.w4, &data_020f1b94, name);
    ((char*)elem.w4)[len] = 0;

    AppendElement020a825c(data_02109fe0.list, &elem);
    return 1;
}
