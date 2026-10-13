#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"

#if defined(jpn)
enum { kTaskOffset = 0x1354, kAllocatorOffset = 0x7c, kTableOffset = 0x131c };
#else
enum { kTaskOffset = 0x1388, kAllocatorOffset = 0x84, kTableOffset = 0x1344 };
#endif

struct Container020dffc8;
extern "C" int func_020dfec0(Container020dffc8*, SafeAllocator*, void*, unsigned int);

// KEEP-NAME
// USA: func_ov012_02185f04
// JPN: func_ov012_021865a4
ARM void ResetAndRebuildEntry_02185f04(char* editor) {
    GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    int task = *(int*)(editor + kTaskOffset);
    void* fileData;
    unsigned int fileSize;
    loader->GetLoadedFileByID(task, &fileData, &fileSize);
    ((SafeAllocator*)(editor + kAllocatorOffset))->Reset();
    func_020dfec0((Container020dffc8*)(editor + kTableOffset), (SafeAllocator*)(editor + kAllocatorOffset), fileData, fileSize);
    loader->RemoveTask(*(int*)(editor + kTaskOffset));
    *(int*)(editor + kTaskOffset) = -1;
}
