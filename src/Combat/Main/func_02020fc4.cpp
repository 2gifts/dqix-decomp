#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

struct State0xbb1c;
struct Obj0203bb3c;
struct Bcb8Params;

void ClearFields0x8_0203bb1c(struct State0xbb1c* obj);
void SetupAndDispatchCharTransfer0203bb3c(struct Obj0203bb3c* obj, char* src, SafeAllocator* allocator, int category, unsigned short arg5);
void ForwardParamsToB8bc_0203bcb8(struct Bcb8Params* s, int arg1, int arg2);
int DispatchCharTransfer0203b784(int* arr1, int idx, int category, int addr, unsigned int len, unsigned int len2);
void* GetData02105254_0203b628(void);

struct CharTileTask_02020fc4 {
    char pad0[0x14];
    int state;
    char pad18[0x5c];
    int totalSize;
    unsigned char tileWidth;
    unsigned char tileHeight;
    char pad7a[0x12];
    unsigned short charBaseOffset;
};

#if defined(jpn)
typedef int TaskHandle02020fc4;
#else
typedef int* TaskHandle02020fc4;
#endif
// USA: func_02020fc4
extern "C" ARM void func_02020fc4(struct CharTileTask_02020fc4* task, TaskHandle02020fc4 taskID, SafeAllocator* allocator) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    int* charTable = (int*)GetData02105254_0203b628();

    if (task->state == 3) {
        task->totalSize = 0;
    } else {
        void* fileData = 0;
        unsigned int fileLength = 0;
        loader->GetLoadedFileByID((IS_JPN ? (int)taskID : *(int*)taskID), &fileData, &fileLength);
        ClearFields0x8_0203bb1c((struct State0xbb1c*)((char*)task + 0x78));
        SetupAndDispatchCharTransfer0203bb3c((struct Obj0203bb3c*)((char*)task + 0x78), (char*)fileData, allocator, 1, 1);

        int row;
        for (row = 0; row < 0x20 / task->tileHeight; row++) {
            int col;
            for (col = 0; col < 0x20 / task->tileWidth; col++) {
                ForwardParamsToB8bc_0203bcb8((struct Bcb8Params*)((char*)task + 0x78),
                                    col * task->tileWidth, row * task->tileHeight);
            }
        }

        int buffer[8];
        task->totalSize = task->tileWidth * task->tileHeight + task->charBaseOffset;
        memset(buffer, 0, 0x20);
        DispatchCharTransfer0203b784(charTable, 1, 0, (int)buffer, 0x20, 1);
    }

    BackgroundLoader::GetInstance()->RemoveTask(IS_JPN ? (int)taskID : *(int*)taskID);
#if !defined(jpn)
    *taskID = -1;
#endif
}
