#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

struct TableA68;
void* FindEntryByKey(TableA68* table, int key);
extern "C" void func_020728ac(void* table, SafeAllocator* allocator, const void* file, unsigned int size, int, int, int);
#if defined(jpn)
extern char data_ov012_0218bf40[];
extern char data_ov012_0218bf52[];
#endif

// USA: func_ov012_02185e18
// JPN: func_ov012_02186468
extern "C" ARM void func_ov012_02185e18(char* editor) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
#if defined(jpn)
    void* archive;
    unsigned int archiveSize;
    const void* file;
    unsigned int size;
    loader->GetLoadedFileByID(*(int*)(editor + 0x1350), &archive, &archiveSize);
    if (!GetFileInNarc(archive, data_ov012_0218bf40, &file, &size, 0)) {
        loader->RemoveTask(*(int*)(editor + 0x1350));
        *(int*)(editor + 0x1350) = -1;
        return;
    }
    ((SafeAllocator*)(editor + 0x2c))->Reset();
    func_020728ac(editor + 0x1314, (SafeAllocator*)(editor + 0x2c), file, size, 0, 0, 0);
    *(void**)(editor + 0x1348) = FindEntryByKey((TableA68*)(editor + 0x1314), 0);
    if (!GetFileInNarc(archive, data_ov012_0218bf52, &file, (unsigned int*)(editor + 0x1410), 0)) {
        loader->RemoveTask(*(int*)(editor + 0x1350));
        *(int*)(editor + 0x1350) = -1;
        return;
    }
    memcpy(*(void**)(editor + 0x140c), file, *(unsigned int*)(editor + 0x1410));
    loader->RemoveTask(*(int*)(editor + 0x1350));
    *(int*)(editor + 0x1350) = -1;
#else
    int task = *(int*)(editor + 0x1380);
    void* file;
    unsigned int size;
    loader->GetLoadedFileByID(task, &file, &size);
    ((SafeAllocator*)(editor + 0x34))->Reset();
    func_020728ac(editor + 0x133c, (SafeAllocator*)(editor + 0x34), file, size, 0, 0, 0);
    *(void**)(editor + 0x1378) = FindEntryByKey((TableA68*)(editor + 0x133c), 0);
    loader->RemoveTask(*(int*)(editor + 0x1380));
    *(int*)(editor + 0x1380) = -1;
#endif
}
