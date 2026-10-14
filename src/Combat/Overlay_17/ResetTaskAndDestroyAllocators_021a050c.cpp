#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"
#include "Combat/MapDisplay.h"
#include "Memory/AllocatorUnion.h"

class AllocatorUnion;
int TailForward02012da4(AllocatorUnion*, void*);
void* AllocateAligned4(AllocatorUnion* alloc, unsigned int size);

extern AllocatorUnion data_02114e20;
extern int data_ov017_021d669c[];

// USA: func_ov017_021a050c
ARM void ResetTaskAndDestroyAllocators_021a050c(GameResources* self) {
    MapDisplay* display = self->unknown_ptr_36d0;
    func_02020720(display);

    for (int i = 0; data_ov017_021d669c[i] >= 0; i++) {
        int index = data_ov017_021d669c[i];
        void* p = self->allocator_array_38[index].GetSignedAllocator();
        self->allocator_array_38[index].Destroy();
        self->allocator_array_38[index].ResetAllocatorPointer();
        if (p != NULL) {
            TailForward02012da4(&data_02114e20, p);
        }
    }

    void* buf = AllocateAligned4(&data_02114e20, 0x6f78);
    self->allocator_array_38[5].CreateTypeA(buf, 0x6f78);
}
