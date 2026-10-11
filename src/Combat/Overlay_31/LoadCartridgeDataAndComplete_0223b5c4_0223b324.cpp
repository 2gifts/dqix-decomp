#include <globaldefs.h>
#include "Filesystem/NitroVM.h"
#include "Filesystem/LowNitroHandle.h"
#include "Filesystem/FileAccessor.h"
#include "System/GamecardBusOwnership.h"

struct FileBlock_0223b324 {
	void* tableBuffer;
	unsigned char pad0[0x84 - 4];
	void* slotArray;
	NitroHandle handle;
	unsigned short lockOwnerId;
};
struct Outer_0223b324 { FileBlock_0223b324* p; };
extern struct Outer_0223b324 data_ov031_02290d24;

extern "C" int func_ov031_0223b560(NitroVM* vm, int tag);
extern "C" int func_ov031_0223b614(NitroHandle*, const void*, unsigned int, unsigned int);
ARM int LoadCartridgeDataAndComplete_0223b5c4(NitroHandle* a, void* b, unsigned int c, unsigned int d);

extern "C" ARM void* func_ov031_0223cf4c(unsigned int len, int align);
extern "C" void func_020c9be0(void);
ARM void* FillSlotArrayField4_0223beec(int n, int base, int stride);
int VariadicForward020c7130(int a, int b, ...);

extern const char data_ov031_0224c544[];
extern const char data_ov031_0224939c[];
extern const char data_ov031_0224c55c[];

struct FatFntPair_0223b324 { unsigned int offset; unsigned int size; };

// USA: func_ov031_0223b324
// JPN: func_ov031_0223bb04
extern "C" ARM void func_ov031_0223b324(void) {
	data_ov031_02290d24.p = (FileBlock_0223b324*)func_ov031_0223cf4c(0xe8, 4);

	NitroVM vm;
	NitroVM_Initialize(&vm);
	if (!NitroVM_PrepareReadFileByPath(&vm, data_ov031_0224c544))
		func_020c9be0();

	data_ov031_02290d24.p->lockOwnerId = GenerateLockOwnerID();
	void* image = (void*)vm.fileInfo.startOffset;
	FatFntPair_0223b324 fnt;
	NitroVM_ReadSync(&vm, &fnt, 8);
	FatFntPair_0223b324 fat;
	NitroVM_ReadSync(&vm, &fat, 8);
	NitroVM_FinishRead(&vm);

	NitroHandle_Initialize(&data_ov031_02290d24.p->handle);
	if (!NitroHandle_AddToHandleList(&data_ov031_02290d24.p->handle, data_ov031_0224939c, 3))
		func_020c9be0();

	NitroHandle_SetOpcodeOverride(&data_ov031_02290d24.p->handle, func_ov031_0223b560, 0x602);

	if (!NitroHandle_Populate(&data_ov031_02290d24.p->handle, image,
			fat.offset, fat.size, fnt.offset, fnt.size,
			LoadCartridgeDataAndComplete_0223b5c4, func_ov031_0223b614))
		func_020c9be0();

	unsigned int capacity = NitroHandle_LoadFileTables(&data_ov031_02290d24.p->handle, NULL, 0);
	data_ov031_02290d24.p->tableBuffer = func_ov031_0223cf4c(capacity, 4);
	NitroHandle_LoadFileTables(&data_ov031_02290d24.p->handle, data_ov031_02290d24.p->tableBuffer, capacity);

	data_ov031_02290d24.p->slotArray = FillSlotArrayField4_0223beec(0x20, (int)data_ov031_02290d24.p + 4, 4);

	char buf[0x80];
	VariadicForward020c7130((int)buf, (int)data_ov031_0224c55c, (int)data_ov031_0224939c);
	SetROMFilesystemRoot(buf);
}
