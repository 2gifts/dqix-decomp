#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif

#include "Filesystem/BackgroundLoader.h"
#include "Combat/MapDisplay.h"

struct List0202fec8;

void* GetGlobalPtr02105244();
extern "C" void* func_0203bd08(void);
extern "C" void* func_0203be4c(void);

struct Rec020467f0;
int ProcessRecords0205a498(void* a, struct Rec020467f0* b, int flag, void* d);

void SetBitfieldStoreBytes0205af38(int a, char* obj, int c, int d);

// USA: func_02020aec  (semantic: ApplyGlobalTableAndFinalize02020aec)
extern "C" ARM void func_02020aec(MapDisplay* self, MapDisplayTaskHandle handle, SafeAllocator* allocator) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    void* fileData = 0;
    unsigned int fileLength = 0;
    #if defined(jpn)
    loader->GetLoadedFileByID(handle, &fileData, &fileLength);
#else
    loader->GetLoadedFileByID(*handle, &fileData, &fileLength);
#endif

    char* g = (char*)GetGlobalPtr02105244();
    *(int*)(g + (IS_JPN ? 0x608 : 0x508)) = 0x2000;
    func_0203bd08();

    char* p = (char*)func_0203be4c() + 0x2c0;
    g = (char*)GetGlobalPtr02105244();
    *(char**)g = p;

    ProcessRecords0205a498(&self->entryList, (Rec020467f0*)fileData, fileLength, allocator);

    loader = BackgroundLoader::GetInstance();
#if defined(jpn)
    loader->RemoveTask(handle);
#else
    loader->RemoveTask(*handle);
    *handle = -1;
#endif

    SetBitfieldStoreBytes0205af38((int)&self->entryList, (char*)&self->records[9], 1, 1);
    SetBitfieldStoreBytes0205af38((int)&self->entryList, (char*)&self->records[11], 1, 1);
}
