#include <globaldefs.h>
#if defined(jpn)
#define data_020efe50 data_020efd68
#endif
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"

void* LoadFileIntoMemory(const char*, void*, unsigned int*);

extern "C" void func_0203fd5c(void* p0, void* buf, int p2, void* p3);

extern char data_020efe50[];
extern char data_0211e33c[];

// USA: func_0203fce0
ARM void CheckSuffixAndLoadResource0203fce0(void* p0, char* p1, int p2) {
    char buf[0x80];
    char* end = p1 + strlen(p1);
    if (end[-1] == 'r') {
        sprintf(buf, data_020efe50, p1);
        BackgroundLoader::AddLockGlobal();
        void* result = LoadFileIntoMemory(buf, data_0211e33c, (unsigned int*)0);
        if (result != NULL) {
            func_0203fd5c(p0, buf, p2, result);
        }
        BackgroundLoader::RemoveLockGlobal();
    }
}
