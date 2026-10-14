#include <globaldefs.h>

#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "Resource/Script.h"

struct Ctx0209a8b4 {
    void* field0;
};
extern struct Ctx0209a8b4* data_02109ba8;
extern char data_020f1640[];

struct ResetStruct;

struct StreamState;
struct StreamHeader;

struct Struct02030774;

// USA: func_0209a8b4
ARM void SetupAndRunBufferedScript0209a8b4(struct Ctx0209a8b4* ctx, SafeAllocator* alloc, struct StreamHeader* buffer, int length) {
    void* mem = alloc->Allocate(0x550);
    ctx->field0 = mem;
    if (mem != NULL) {
        memset(mem, 0, 0x550);
        char local[0x430];
        data_02109ba8 = ctx;
        ((Script*)((struct ResetStruct*)local))->Initialize();
        ((Script*)((struct ResetStruct*)local))->SetOpcodeLookup((Script::OpcodeLookupEntry*)data_020f1640);
        ((Script*)((struct StreamState*)local))->Load(buffer, length);
        ((Script*)((struct Struct02030774*)local))->Execute();
        data_02109ba8 = NULL;
    }
}
