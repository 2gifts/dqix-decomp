#include <globaldefs.h>

#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Ctx0209a470 {
    void* field0;
};
extern struct Ctx0209a470* data_02109ba4;
extern char data_020f15e8[];

struct ResetStruct;

struct StreamState;
struct StreamHeader;

struct Struct02030774;

extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(struct ResetStruct*, char*);

// USA: func_0209a470
ARM void SetupAndRunBufferedScript0209a470(struct Ctx0209a470* ctx, SafeAllocator* alloc, struct StreamHeader* buffer, int length) {
    void* mem = alloc->Allocate(0xd74);
    ctx->field0 = mem;
    if (mem != NULL) {
        char local[0x430];
        data_02109ba4 = ctx;
        ((Script*)((struct ResetStruct*)local))->Initialize();
        _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE((struct ResetStruct*)local, data_020f15e8);
        ((Script*)((struct StreamState*)local))->Load(buffer, length);
        ((Script*)((struct Struct02030774*)local))->Execute();
        data_02109ba4 = NULL;
    }
}
