#include <globaldefs.h>

#if defined(jpn)
#define func_ov004_02166ac4 func_ov004_021670b0
#endif

#if defined(jpn)
enum { resetFlagOffset = 0x790 };
#else
enum { resetFlagOffset = 0x962 };
#endif

#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

#if defined(jpn)
extern char* data_ov004_0217101c[2];
#define CurrentBase0217101c data_ov004_0217101c[1]
#else
extern char* data_ov004_0217101c;
#define CurrentBase0217101c data_ov004_0217101c
#endif
extern "C" void* func_0205ec34(void);
int* GetGlobal02109418(void);
int GetGlobalField0x1c020421a0(void);

// USA: func_ov004_02166ac4  (semantic: ResetAllocatorsAndSyncGlobals_02166ac4)
extern "C" ARM int func_ov004_02166ac4() {
    char* base = CurrentBase0217101c;
    int a = (int)BackgroundLoader::GetInstance();
    int b = *(int*)(base + 0x44);
    ((BackgroundLoader*)(a))->RemoveTask((int)(b));
    *(int*)(base + 0x44) = -1;
    ((SafeAllocator*)(base + 0x30))->Destroy();
    ((SafeAllocator*)(base + 0x1c))->Destroy();
    char* c = (char*)func_0205ec34();
    memcpy(c + 0x2cc, CurrentBase0217101c + 0x51, 0x66);
    int* g = GetGlobal02109418();
    *(int*)((char*)g + 0xa0) = *(int*)(CurrentBase0217101c + 0xb8);
    char* f = (char*)GetGlobalField0x1c020421a0();
    *(unsigned char*)(f + 0x1000 + resetFlagOffset) = 0;
    return 0;
}
