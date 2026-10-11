// JPN: func_ov017_021b507c
#if defined(jpn)
enum { RegionOffset18 = 0x14 };
#else
enum { RegionOffset18 = 0x18 };
#endif

#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Filesystem/FileIO.h"

struct List0202fe68;
struct List0202fec8;
struct InitStruct;
ARM void InitializeStruct(struct InitStruct* s);
struct Struct0202811c;
void ProcessAndCheckPairs02028104(struct Struct0202811c* s, int b, int c, int d);
extern "C" void func_02028214(void* a, int b);

extern char data_ov017_021d7b4f;
extern char data_ov017_021d7b3a;

struct Obj021b498c {
    char pad0[8];
    void* sub;
    int key;
    unsigned char field10;
    char pad1[3];
    int field14;
};

// USA: func_ov017_021b498c  (semantic: ApplyPendingListEntryWithNarcFile_021b498c)
extern "C" ARM void func_ov017_021b498c(struct Obj021b498c* obj) {
    GameState::GetInstance();
    int list = (int)BackgroundLoader::GetInstance();
    if (!((BackgroundLoader*)(list))->GetTaskStatus((int)(obj->key))) {
        return;
    }

    if (((BackgroundLoader*)((struct List0202fe68*)list))->GetDetailedTaskStatus((int)(obj->key)) == 2) {
        int out2, out1;
        ((BackgroundLoader*)((struct List0202fec8*)list))->GetLoadedFileByID((int)(obj->key), (void**)(&out1), (unsigned int*)(&out2));
        if (out1 != 0) {
            unsigned int fileSize;
            const void* filePtr;
            FindFilesInNarcBySubstring((const void*)out1, &data_ov017_021d7b4f, &filePtr, &fileSize, 1);
            if (filePtr != 0) {
                char* sub = (char*)obj->sub;
                InitializeStruct((struct InitStruct*)(sub + RegionOffset18));
                ProcessAndCheckPairs02028104((struct Struct0202811c*)(sub + RegionOffset18), *(int*)((char*)obj->sub + 0x10), (int)filePtr, (int)fileSize);
                func_02028214(sub + RegionOffset18, *(int*)((char*)obj->sub + 0x10));
                sub[0xc] = 1;
            }
        }
    }

    ((BackgroundLoader*)(list))->RemoveTask((int)(obj->key));
    obj->key = -1;
    obj->key = ((BackgroundLoader*)(list))->QueueLoadFile((const char*)((int)&data_ov017_021d7b3a), (SafeAllocator*)(0));
    obj->field10 = 3;
}
