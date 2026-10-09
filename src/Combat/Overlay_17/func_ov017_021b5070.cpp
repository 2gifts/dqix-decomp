#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"

struct StreamHeader;

struct HalfwordArray {
    unsigned short arr[12];
    unsigned short count;
};

struct Scene021b5070 {
    char pad0[0x10];
    int scriptArg;
    SafeAllocator* allocator;
    char pad18[0x44 - 0x18];
    HalfwordArray ids;
    char pad5e[0x60 - 0x5e];
    char scriptContext[0x124 - 0x60];
    char scriptBuffer[1];
};

struct Loader021b5070 {
    char pad0[8];
    Scene021b5070* scene;
    int taskId;
    unsigned char state;
    char pad11[3];
    unsigned char* idTable;
};

extern "C" void __clear(void* buf, int size);
extern "C" void* memset(void* dst, int value, unsigned int size);
unsigned short CopyHalfwordArrayByCount(HalfwordArray* src, HalfwordArray* dst);
extern "C" void _Z33SetupAndRunBufferedScript0209af58PvP12StreamHeaderiii(void* param0, StreamHeader* param1, int param2, int param3, int param4);

void* LoadFileIntoMemory(const char* path, void* buffer, unsigned int* outLength);

extern unsigned char data_0211e33c[0x30000] __attribute__((aligned(4)));
extern char data_ov017_021d7b85[];
extern char data_ov017_021d7b9b[];
extern char data_ov017_021d7bb1[];

// USA: func_ov017_021b5070
extern "C" ARM void func_ov017_021b5070(Loader021b5070* self) {
    GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (!loader->GetTaskStatus(self->taskId)) return;
    if (loader->GetDetailedTaskStatus(self->taskId) == 2) {
        unsigned int length;
        void* file;
        loader->GetLoadedFileByID(self->taskId, &file, &length);
        if (file != NULL) {
            Scene021b5070* scene = self->scene;
            _Z33SetupAndRunBufferedScript0209af58PvP12StreamHeaderiii(scene->scriptBuffer, (StreamHeader*)file, length, self->scene->scriptArg, (int)scene->scriptContext);
        }
    }
    loader->RemoveTask(self->taskId);
    self->taskId = -1;
    Scene021b5070* scene = self->scene;
    unsigned short ids[12];
    __clear(ids, sizeof(ids));
    short count = CopyHalfwordArrayByCount(&scene->ids, (HalfwordArray*)ids);
    SafeAllocator* allocator = self->scene->allocator;
    unsigned char* table;
    if (allocator == NULL) {
        table = NULL;
    } else if ((unsigned short)count == 0) {
        table = NULL;
    } else {
        unsigned int size;
        BackgroundLoader::AddLockGlobal();
        BackgroundLoader::FreeAllocationsGlobal();
        short* data = (short*)LoadFileIntoMemory(data_ov017_021d7b85, data_0211e33c, &size);
        BackgroundLoader::RemoveLockGlobal();
        if (data == NULL) {
            table = NULL;
        } else if (size == 0) {
            table = NULL;
        } else {
            unsigned char* values;
            int n;
            int j;
            int i;
            n = data[0];
            values = (unsigned char*)data + (n * 2 + 2);
            table = (unsigned char*)allocator->Allocate(0xc);
            memset(table, 0, 0xc);
            for (i = 0; i < (unsigned short)count; i++) {
                short id = ids[i];
                short* key = data + 1;
                for (j = 0; j < n; j++) {
                    if (*key++ == id) break;
                }
                if (j >= 0 && j < n) {
                    table[i] = values[j];
                }
            }
        }
    }
    self->idTable = table;
    self->taskId = loader->QueueLoadFileInGP2(data_ov017_021d7b9b, data_ov017_021d7bb1, NULL);
    self->state = 6;
}
