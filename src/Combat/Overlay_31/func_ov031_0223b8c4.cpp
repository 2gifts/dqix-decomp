#include <globaldefs.h>
#include "System/Interrupts.h"

struct AllocationNode0223b8c4 {
    AllocationNode0223b8c4* prev;
    AllocationNode0223b8c4* next;
    unsigned char* buffer;
    unsigned char count;
    char pad0d[3];
};

struct AllocationRegion0223b8c4 {
    char pad0[0x200];
    AllocationNode0223b8c4 front;
    AllocationNode0223b8c4 back;
    int field_0x220;
    void* freeNodes;
};

extern AllocationRegion0223b8c4* data_ov031_02290d28;
extern "C" AllocationNode0223b8c4* func_ov031_0223bfa0(void*);
extern "C" void func_ov031_0223d8d8(AllocationNode0223b8c4*, AllocationNode0223b8c4*);
extern "C" void func_020c9be0();

static inline AllocationRegion0223b8c4* GetRegion0223b8c4(int index) {
    AllocationRegion0223b8c4* region = data_ov031_02290d28;
    region += index;
    return region;
}

// USA: func_ov031_0223b8c4
extern "C" ARM AllocationNode0223b8c4* func_ov031_0223b8c4(int region, int count, int fromFront) {
    AllocationNode0223b8c4* result = func_ov031_0223bfa0(GetRegion0223b8c4(region)->freeNodes);
    AllocationNode0223b8c4* node;
    unsigned int interrupts = DisableSpecificInterrupts(1);
    if (fromFront) {
        node = &GetRegion0223b8c4(region)->front;
        if (node != &GetRegion0223b8c4(region)->back) {
            do {
                AllocationNode0223b8c4* next = node->next;
                unsigned char* start = node->buffer + node->count * 8;
                if (start + count * 8 <= next->buffer) {
                    result->buffer = start;
                    func_ov031_0223d8d8(next, result);
                    break;
                }
                node = next;
            } while (node != &data_ov031_02290d28[region].back);
        }
        if (node == &data_ov031_02290d28[region].back) func_020c9be0();
    } else {
        node = &GetRegion0223b8c4(region)->back;
        if (node != &GetRegion0223b8c4(region)->front) {
            do {
                AllocationNode0223b8c4* prev = node->prev;
                unsigned char* start = node->buffer - count * 8;
                if (start >= prev->buffer + prev->count * 8) {
                    result->buffer = start;
                    func_ov031_0223d8d8(node, result);
                    break;
                }
                node = prev;
            } while (node != &data_ov031_02290d28[region].front);
        }
        if (node == &data_ov031_02290d28[region].front) func_020c9be0();
    }
    EnableSpecificInterrupts(interrupts);
    result->count = count;
    return result;
}
