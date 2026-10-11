#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif
#if defined(jpn)
typedef int RegionalTaskHandle;
#else
typedef int* RegionalTaskHandle;
#endif

#include "Filesystem/BackgroundLoader.h"


struct List0202fec8;

void* GetGlobalPtr02105244();
extern "C" void* func_0203bd08(void);
extern "C" void* func_0203be4c(void);

struct Rec020467f0;
int ProcessRecords0205a498(void* a, struct Rec020467f0* b, int flag, void* d);


void SetBitfieldStoreBytes0205af38(int a, char* obj, int c, int d);

// USA: func_02020aec  (semantic: ApplyGlobalTableAndFinalize02020aec)
extern "C" ARM void func_02020aec(char* self, RegionalTaskHandle handle, int arg2) {
    int listPtr = (int)BackgroundLoader::GetInstance();
    int out1 = 0, out2 = 0;
    #if defined(jpn)
    ((BackgroundLoader*)((struct List0202fec8*)listPtr))->GetLoadedFileByID(handle, (void**)(&out1), (unsigned int*)(&out2));
#else
    ((BackgroundLoader*)((struct List0202fec8*)listPtr))->GetLoadedFileByID((int)(*handle), (void**)(&out1), (unsigned int*)(&out2));
#endif

    char* g = (char*)GetGlobalPtr02105244();
    *(int*)(g + (IS_JPN ? 0x608 : 0x508)) = 0x2000;
    func_0203bd08();

    char* p = (char*)func_0203be4c() + 0x2c0;
    g = (char*)GetGlobalPtr02105244();
    *(char**)g = p;

    ProcessRecords0205a498(self + 0x94, (struct Rec020467f0*)out1, out2, (void*)arg2);

    listPtr = (int)BackgroundLoader::GetInstance();
#if defined(jpn)
    ((BackgroundLoader*)(listPtr))->RemoveTask(handle);
#else
    ((BackgroundLoader*)(listPtr))->RemoveTask((int)(*handle));
    *handle = -1;
#endif

    SetBitfieldStoreBytes0205af38((int)(self + 0x94), self + 0x250, 1, 1);
    SetBitfieldStoreBytes0205af38((int)(self + 0x94), self + 0x2a0, 1, 1);
}
