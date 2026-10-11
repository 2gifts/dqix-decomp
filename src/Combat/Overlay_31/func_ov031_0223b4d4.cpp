#include <globaldefs.h>
#include "Filesystem/FileAccessor.h"
#include "Filesystem/NitroVM.h"
#include "Filesystem/LowNitroHandle.h"
#include "System/GamecardBusOwnership.h"

struct ShutdownState0223b4d4 {
    void* allocation;
    char pad04[0x84];
    NitroHandle handle;
    unsigned short owner;
};
extern "C" ShutdownState0223b4d4* data_ov031_02290d24;
namespace DuplicatePool {
    extern "C" ShutdownState0223b4d4* data_ov031_02290d24;
}
extern char data_ov031_0224c564[];
extern "C" unsigned int func_ov031_0223cf70(void**);

// USA: func_ov031_0223b4d4
extern "C" ARM void func_ov031_0223b4d4(void) {
    SetROMFilesystemRoot(data_ov031_0224c564);
    NitroHandle_ReleaseFileTables(&data_ov031_02290d24->handle);
    NitroHandle_Destroy(&data_ov031_02290d24->handle);
    NitroHandle_RemoveFromHandleList(&data_ov031_02290d24->handle);
    ReleaseLockOwnerID(data_ov031_02290d24->owner);
    data_ov031_02290d24->owner = 0;
    func_ov031_0223cf70(&data_ov031_02290d24->allocation);
    data_ov031_02290d24->allocation = NULL;
    func_ov031_0223cf70((void**)&DuplicatePool::data_ov031_02290d24);
}
