#include <globaldefs.h>

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

struct State02166ac4 {
    unsigned char unknown00[0x1c];
    SafeAllocator allocators[2];
    int taskId;
    unsigned char unknown48[8];
    unsigned char flags;
    unsigned char savedBytes[0x66];
    int savedWord;
};

// USA: func_ov004_02166ac4  (semantic: ResetAllocatorsAndSyncGlobals_02166ac4)
extern "C" ARM int func_ov004_02166ac4() {
    State02166ac4* state = (State02166ac4*)CurrentBase0217101c;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    int taskId = state->taskId;
    loader->RemoveTask(taskId);
    state->taskId = -1;
    state->allocators[1].Destroy();
    state->allocators[0].Destroy();
    char* c = (char*)func_0205ec34();
    memcpy(c + 0x2cc, ((State02166ac4*)CurrentBase0217101c)->savedBytes, 0x66);
    int* g = GetGlobal02109418();
    *(int*)((char*)g + 0xa0) = ((State02166ac4*)CurrentBase0217101c)->savedWord;
    char* f = (char*)GetGlobalField0x1c020421a0();
    *(unsigned char*)(f + 0x1000 + resetFlagOffset) = 0;
    return 0;
}
