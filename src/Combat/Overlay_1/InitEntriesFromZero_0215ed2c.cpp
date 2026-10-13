#include <globaldefs.h>
#include "std_library_functions.h"
#include "Filesystem/BackgroundLoader.h"

extern int data_ov001_021658b8;
extern int data_ov001_021658e0[];
extern const char data_ov001_02165745[];
extern "C" void* func_ov017_021d612c(void*);
extern "C" void func_ov001_0215ec94(void*, int);
extern "C" int func_ov001_0215ad3c(char*, char*, char*);

struct PathParameter0215ed2c {
    int type;
    char* path;
};

// KEEP-NAME
// USA: func_ov001_0215ed2c
// JPN: func_ov001_0216030c
ARM int InitEntriesFromZero_0215ed2c(void* entries, int count) {
#if defined(jpn)
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    char tag[0x50];
    char archive[0x50];
    *(int*)((char*)&data_ov001_021658b8 + 0x88) = 0;
    PathParameter0215ed2c* parameter = (PathParameter0215ed2c*)entries;
    for (int i = 0; i < count; i++) {
        char* path = (char*)func_ov017_021d612c(parameter++);
        if (func_ov001_0215ad3c(path, tag, archive) != 0) {
            data_ov001_021658e0[i] = loader->QueueLoadFileInGP2(archive, tag, NULL);
        } else {
            sprintf(tag, data_ov001_02165745, path);
            data_ov001_021658e0[i] = loader->QueueLoadFile(tag, NULL);
        }
        *(int*)((char*)&data_ov001_021658b8 + 0x88) += 1;
    }
#else
    *(int*)((char*)&data_ov001_021658b8 + 0x88) = 0;
    int i;
    for (i = 0; i < count; i++) {
        void* mapped = func_ov017_021d612c(entries);
        entries = (char*)entries + 8;
        func_ov001_0215ec94(mapped, i);
    }
#endif
    return 1;
}
