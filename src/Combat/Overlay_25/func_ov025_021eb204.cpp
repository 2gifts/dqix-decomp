#include <globaldefs.h>
#include "std_library_functions.h"
#include "Filesystem/BackgroundLoader.h"

struct Obj021eb3c0 {
    int taskId;
    unsigned short nodeId;
    unsigned short fileNo;
    unsigned char kind;
    unsigned char state;
};

struct Loader021eb204 {
    char pad0[0x10];
    SafeAllocator* allocators[4];
    int params[4];
    unsigned char slot;
};

struct Codes021eb204 {
    unsigned char c[4];
};

struct Names021eb204 {
    const char* names[4];
};

extern "C" void _Z12Init021eb3c0P11Obj021eb3c0(struct Obj021eb3c0* obj);
extern "C" void* func_02057924(void);
extern "C" int func_02057e6c(void* mgr, int id, SafeAllocator* alloc, void* data, unsigned int length, int param);

extern struct Names021eb204 data_ov025_021eeff4;
extern struct Codes021eb204 data_ov025_021eeff0;
extern char data_ov025_021ef8e0[];
extern char data_ov025_021ef8e9[];

// USA: func_ov025_021eb204
extern "C" ARM int func_ov025_021eb204(struct Loader021eb204* self) {
    int busy;
    struct Obj021eb3c0* entry = (struct Obj021eb3c0*)((char*)self + 0x194 + 0x400);
    busy = 0;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    void* mgr = func_02057924();
    SafeAllocator* alloc = self->allocators[self->slot];
    int param = self->params[self->slot];
    for (unsigned char i = 0; i < 4; i++, entry++) {
        if (entry->state == 0) {
            continue;
        }
        busy = 1;
        switch (entry->state) {
        case 1: {
            struct Names021eb204 names = data_ov025_021eeff4;
            struct Codes021eb204 codes = data_ov025_021eeff0;
            char fmt[0x40];
            char path[0x40];
            sprintf(fmt, data_ov025_021ef8e0, names.names[entry->kind], codes.c[entry->kind]);
            sprintf(path, fmt, entry->fileNo);
            sprintf(fmt, data_ov025_021ef8e9, path);
            entry->taskId = loader->QueueLoadFile(fmt, alloc);
            if (entry->taskId != -1) {
                entry->state = 2;
            } else {
                _Z12Init021eb3c0P11Obj021eb3c0(entry);
            }
            break;
        }
        case 2:
            if (loader->GetTaskStatus(entry->taskId) != 0) {
                entry->state = 3;
            }
            break;
        case 3: {
            void* data = NULL;
            unsigned int length = 0;
            loader->GetLoadedFileByID(entry->taskId, &data, &length);
            if (data != NULL) {
                func_02057e6c(mgr, entry->nodeId, alloc, data, length, param);
            }
            loader->RemoveTask(entry->taskId);
            _Z12Init021eb3c0P11Obj021eb3c0(entry);
            break;
        }
        default:
            _Z12Init021eb3c0P11Obj021eb3c0(entry);
            break;
        }
    }
    return busy;
}
