#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct ResetStruct;

struct StreamHeader;
struct StreamState;

struct Struct02030774;

struct Elem0203066c { unsigned int key; int val; };
struct Obj0203066c { int count; struct Elem0203066c* list; };
extern "C" int _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(struct Obj0203066c* obj, struct Elem0203066c* arr);

struct Ctx9bc4_98e0 {
    void* field0;
    SafeAllocator* field4;
};
extern Ctx9bc4_98e0 data_ov028_021d9bc4;
extern struct Elem0203066c data_ov028_021d9ac0;

struct SelfObj98e0 {
    char pad0[4];
    int field4;
    short field8;
};

// USA: func_ov028_021d98e0  (semantic: SetupAndRunStream_021d98e0)
extern "C" ARM void func_ov028_021d98e0(SelfObj98e0* self, SafeAllocator* alloc, struct StreamHeader* header, int length) {
    char local[0x430];
    self->field4 = 0;
    self->field8 = 0;
    data_ov028_021d9bc4.field4 = alloc;
    data_ov028_021d9bc4.field0 = self;
    ((Script*)((struct ResetStruct*)local))->Initialize();
    _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE((struct Obj0203066c*)local, &data_ov028_021d9ac0);
    ((Script*)((struct StreamState*)local))->Load(header, length);
    ((Script*)((struct Struct02030774*)local))->Execute();
}
