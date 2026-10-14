#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct ResetStruct;
struct StreamState;
struct StreamHeader;
struct Struct02030774;
extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(struct ResetStruct*, int*);

struct Global021537b0 { int word0; SafeAllocator* allocPtr; void* selfPtr; };
extern Global021537b0 data_ov001_02165800;
extern int data_ov001_02164b80;
extern int data_ov001_02164b90;

struct Self021537b0 { int field0; int field4; };

// USA: func_ov001_021537b0
extern "C" ARM void func_ov001_021537b0(Self021537b0* self, SafeAllocator* alloc, struct StreamHeader* buffer, int length) {
    char local[0x430];
    self->field0 = 0;
    self->field4 = 0;
    data_ov001_02165800.word0 = 0;
    data_ov001_02165800.allocPtr = alloc;
    data_ov001_02165800.selfPtr = self;

    ((Script*)((struct ResetStruct*)local))->Initialize();
    _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE((struct ResetStruct*)local, &data_ov001_02164b80);
    ((Script*)((struct StreamState*)local))->Load(buffer, length);
    ((Script*)((struct Struct02030774*)local))->Execute();

    self->field4 = data_ov001_02165800.word0;
    data_ov001_02165800.word0 = 0;
    void* mem = alloc->Allocate(self->field4 * 8);
    self->field0 = (int)mem;
    if (mem == NULL) {
        self->field4 = 0;
        return;
    }

    ((Script*)((struct ResetStruct*)local))->Initialize();
    _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE((struct ResetStruct*)local, &data_ov001_02164b90);
    ((Script*)((struct StreamState*)local))->Load(buffer, length);
    ((Script*)((struct Struct02030774*)local))->Execute();
}
