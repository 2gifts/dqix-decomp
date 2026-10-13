#include <globaldefs.h>
#include "World/Zone3D.h"
#include "World/ZoneFeatures.h"
#include "Filesystem/FileIO.h"

struct StreamHeader;
void RegisterAndRunBufferedScript0201f040(void*, void*, StreamHeader*, unsigned int);


// USA: func_02014900
// KEEP-NAME: exported Zone3D member ABI, with an explicit receiver here.
extern "C" ARM int _ZN6Zone3D15ProcessBMDJFileEPKvjPN12ZoneFeatures13Opcode64EntryE(
    Zone3D* zone, const void* source, unsigned int sourceLength, ZoneFeatures::Opcode64Entry* entry) {
    SafeAllocator* allocator = zone->pAllocator_68_;
    BmdjScriptNode* node = (BmdjScriptNode*)allocator->Allocate(sizeof(BmdjScriptNode));
    if (node == NULL) return 0;
    InitStruct02013454(node);
    node->unknown0 = entry->unk_0;
    node->position = entry->vector_4.vec;
    unsigned int scriptLength;
    void* script = DecompressLZ77FileIntoScratchSpace(*allocator, source, scriptLength);
    if (script == NULL) return 0;
    RegisterAndRunBufferedScript0201f040(&node->scriptState, allocator,
                                        (StreamHeader*)script, scriptLength);
    node->next = zone->firstBMDJStruct_41c_;
    zone->firstBMDJStruct_41c_ = node;
    return 1;
}
