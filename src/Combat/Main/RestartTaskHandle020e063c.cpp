#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif

#include "Filesystem/BackgroundLoader.h"

void ReleaseHandle02022b90(void* owner, int* handle);

struct Obj020e063c {
    unsigned char pad0[IS_JPN ? 0x919 : 0x9c5];
    unsigned char flag_9c5;
    unsigned char pad1[0xa0c - 0x9c6];
    int handle_a0c;
};

// USA: func_020e063c
ARM void RestartTaskHandle020e063c(struct Obj020e063c* self, int b, int c) {
    int h = (int)BackgroundLoader::GetInstance();
    self->flag_9c5 = 1;
    ReleaseHandle02022b90(self, &self->handle_a0c);
    self->handle_a0c = ((BackgroundLoader*)(h))->QueueLoadFileInGP2((const char*)(b), (const char*)(c), (SafeAllocator*)(0));
}
