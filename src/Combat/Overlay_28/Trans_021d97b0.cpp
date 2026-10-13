#include <globaldefs.h>
#include "Resource/Script.h"
#include "Memory/SafeAllocator.h"

struct AllocLoopStruct_021d9940;
void AllocateAndInitEntries_021d9940(AllocLoopStruct_021d9940* obj, SafeAllocator* allocator, unsigned int count);

struct Ctx9bc4_97b0 {
    AllocLoopStruct_021d9940* field0;
    SafeAllocator* field4;
};
extern Ctx9bc4_97b0 data_ov028_021d9bc4;

// USA: func_ov028_021d97b0  (semantic: Trans_021d97b0)
extern "C" ARM int func_ov028_021d97b0(Script::Parameter* params, int count) {
    AllocateAndInitEntries_021d9940(data_ov028_021d9bc4.field0, data_ov028_021d9bc4.field4, (unsigned short)params->ToInt());
    return 1;
}
