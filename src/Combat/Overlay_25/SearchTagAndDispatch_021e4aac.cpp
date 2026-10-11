// JPN: func_ov025_021e4f9c
#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"
#include "GameState/GameState.h"

void* GetArrayEntry_021e8a54_021e8a54(char* obj);
int FindTagAndCopy_021e24d0(char* s, char* out2, char* out1);

struct SearchObj0202ffd8;
struct SearchObj0202ff34;
int DispatchByIndex021820bc(void* obj, int unused, int index, int arg);
extern "C" void func_ov025_021e267c(int combatantId, int arg1, int arg2, int flag);
struct RemoveList021eb084;
void RemoveMatchingShort_021eb084(struct RemoveList021eb084* obj, int val);

extern int data_ov025_021ef988;
extern char data_ov025_021eefa0[];

struct Param021e4aac {
    char pad[8];
    unsigned char field8;
    char pad2[3];
    char* field0xc;
};

#if defined(jpn)
enum { RegionOffsetc = 0x4 };
#else
enum { RegionOffsetc = 0xc };
#endif

// USA: func_ov025_021e4aac  (semantic: SearchTagAndDispatch_021e4aac)
extern "C" ARM int func_ov025_021e4aac(struct Param021e4aac* p, int unused, int unusedR2, void* dispatchObj) {
    GameState::GetInstance();
    int handle = (int)BackgroundLoader::GetInstance();
    GetArrayEntry_021e8a54_021e8a54(*(char**)((char*)&data_ov025_021ef988 + RegionOffsetc));

    char buf[0x50];
    int n = 0x50;
    unsigned char* d = (unsigned char*)buf;
    unsigned char* s = (unsigned char*)data_ov025_021eefa0;
    do {
        *d = *s;
        d++;
        s++;
    } while (--n);
    strcat(buf, p->field0xc);

    char name1[0x50];
    char name2[0x50];
    int out1 = 0;
    int out2;
    int id;
    if (FindTagAndCopy_021e24d0(buf, name1, name2)) {
        id = ((BackgroundLoader*)((struct SearchObj0202ffd8*)handle))->GetLoadedFileInArchive((const char*)(name1), (const char*)(name2), (void**)(&out1), (unsigned int*)(&out2));
    } else {
        id = ((BackgroundLoader*)((struct SearchObj0202ff34*)handle))->GetLoadedFileByName((const char*)(buf), (void**)(&out1), (unsigned int*)(&out2));
    }

    if (out1 != 0) {
        int ids[8];
        int count = DispatchByIndex021820bc(dispatchObj, unused, p->field8, (int)&ids[0]);
        if (count > 0) {
            for (int i = 0; i < count; i++) {
                func_ov025_021e267c(ids[i], out1, out2, 0);
            }
        }
    }

    ((BackgroundLoader*)(handle))->RemoveTask((int)(id));
    RemoveMatchingShort_021eb084((struct RemoveList021eb084*)(*(char**)((char*)&data_ov025_021ef988 + RegionOffsetc)), id);
    return 1;
}
