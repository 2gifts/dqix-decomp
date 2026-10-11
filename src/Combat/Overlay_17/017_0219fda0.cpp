// JPN: func_ov017_021a0850
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "Memory/AllocatorUnion.h"
#include "Memory/SafeAllocator.h"

extern "C" void* func_02012fe4(void);
struct Entry_02028bd0;
struct Entry_02028bd0* GetEntryTableBase(void);
struct Element0x318_02028bac {
	unsigned short kind;
	unsigned short flags;
	unsigned char unk4[0xc];
	SafeAllocator* allocator;
#if defined(jpn)
	unsigned char unk14[0x2f4];
#else
	unsigned char unk14[0x2f8];
#endif
	unsigned char buffers[0xc];
};
struct Element0x318_02028bac* GetElementStride0x318(struct Element0x318_02028bac* base, int index);
struct BigRecord020289c4;
extern "C" void _Z37InitializeSubObjectsAndFields020289c4P17BigRecord020289c4(struct BigRecord020289c4* obj);
extern "C" void _Z19TailForward02012da4P14AllocatorUnionPv(AllocatorUnion* alloc, void* data);
void* AllocateAligned4(AllocatorUnion* alloc, unsigned int size);
extern "C" void _Z20Clear12Bytes020a8e88Pv(void* p);
void ClearCombatantSlot(GameState* battleStruct, int id);
// Passed a trailing source-length argument that _Z33DeserializeElementBuffers020a8e9cP11Obj020a8e9cP13SafeAllocatorPv ignores, so the mangled
// name is spelled out instead of being re-derived from this declaration.
extern "C" void _Z33DeserializeElementBuffers020a8e9cP11Obj020a8e9cP13SafeAllocatorPv(
	void* obj, SafeAllocator* allocator, void* src, unsigned int srcSize);

extern AllocatorUnion data_02114e20;
extern const char data_ov017_021d7638[];
extern unsigned char data_0211e33c[0x30000];
#pragma opt_propagation off

// USA: func_ov017_0219fda0  (semantic: ResetEntriesAndReloadCombatData_0219fda0)
extern "C" ARM void func_ov017_0219fda0(void) {
	GameState* battle = GameState::GetInstance();
	func_02012fe4();
	struct Entry_02028bd0* entryTable = GetEntryTableBase();
	for (int i = 0; i < 4; i++) {
		struct Element0x318_02028bac* elem = GetElementStride0x318((struct Element0x318_02028bac*)entryTable, i);
		_Z37InitializeSubObjectsAndFields020289c4P17BigRecord020289c4((struct BigRecord020289c4*)elem);
		void* signedAlloc = (void*)elem->allocator->GetSignedAllocator();
		if (signedAlloc) {
			elem->allocator->Destroy();
			_Z19TailForward02012da4P14AllocatorUnionPv(&data_02114e20, signedAlloc);
		}
	}
	for (int id = 0x70; id <= 0x9f; id++) {
		ClearCombatantSlot(battle, id);
	}
	struct Element0x318_02028bac* elem0 = GetElementStride0x318((struct Element0x318_02028bac*)entryTable, 0);
	unsigned int size = 0xa000;
	elem0->flags |= 4;
	elem0->kind = 3;
	void* buffer = AllocateAligned4(&data_02114e20, size);
	elem0->allocator->CreateTypeA(buffer, size);
	if (elem0 == NULL) return;
	_Z20Clear12Bytes020a8e88Pv(elem0->buffers);
	BackgroundLoader::AddLockGlobal();
	unsigned int fileSize;
	if (LoadFileIntoMemory(data_ov017_021d7638, data_0211e33c, &fileSize) != NULL) {
		_Z33DeserializeElementBuffers020a8e9cP11Obj020a8e9cP13SafeAllocatorPv(
			elem0->buffers, elem0->allocator, data_0211e33c, fileSize);
	}
	BackgroundLoader::RemoveLockGlobal();
}
