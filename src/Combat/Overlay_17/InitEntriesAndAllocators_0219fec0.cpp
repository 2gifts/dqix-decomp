#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"

extern "C" void* func_02012fe4(void);
struct Entry_02028bd0;
struct Entry_02028bd0* GetEntryTableBase_02027ca4(void);
struct Element0x318_02028bac { unsigned char data[0x318]; };
struct Element0x318_02028bac* GetElementStride0x318(struct Element0x318_02028bac* base, int index);
struct BigRecord020289c4;
void InitializeSubObjectsAndFields020289c4(struct BigRecord020289c4* obj);
void TailForward02012da4(AllocatorUnion* alloc, void* data);
void* AllocateAligned4_02012d88(AllocatorUnion* alloc, unsigned int size);

extern AllocatorUnion data_02114e20;

// USA: func_ov017_0219fec0
ARM void InitEntriesAndAllocators_0219fec0(void*) {
	func_02012fe4();
	struct Entry_02028bd0* entryTable = GetEntryTableBase_02027ca4();
	struct Element0x318_02028bac* elem0 = GetElementStride0x318((struct Element0x318_02028bac*)entryTable, 0);
	InitializeSubObjectsAndFields020289c4((struct BigRecord020289c4*)elem0);
	void* signedAlloc = (void*)(*(SafeAllocator**)((unsigned char*)elem0 + 0x10))->GetSignedAllocator();
	if (signedAlloc) {
		(*(SafeAllocator**)((unsigned char*)elem0 + 0x10))->Destroy();
		TailForward02012da4(&data_02114e20, signedAlloc);
	}
	for (int i = 0; i < 4; i++) {
		struct Element0x318_02028bac* elem = GetElementStride0x318((struct Element0x318_02028bac*)entryTable, i);
		void* p = AllocateAligned4_02012d88(&data_02114e20, 0x28a0);
		SafeAllocator* alloc = *(SafeAllocator**)((unsigned char*)elem + 0x10);
		alloc->CreateTypeA(p, 0x28a0);
	}
}
