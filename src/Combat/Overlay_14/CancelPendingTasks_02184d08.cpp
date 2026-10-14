#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct HandleState_02188d10;
void ResetHandle_02188d10(HandleState_02188d10* h);

// USA: func_ov014_02184d08  (semantic: CancelPendingTasks_02184d08)
extern "C" ARM void func_ov014_02184d08(char* obj) {
    void* loader = BackgroundLoader::GetInstance();
    unsigned char flags = *(unsigned char*)(obj + 0x81);
    if (flags & 1) {
        *(unsigned char*)(obj + 0x81) = flags & ~1;
        int id = *(int*)(obj + 0x6c);
        if (id >= 0) {
            ((BackgroundLoader*)loader)->RemoveTask(id);
            *(int*)(obj + 0x6c) = -1;
        }
        for (int i = 0; i < 5; i++) {
            short tid = *(short*)(obj + i * 2 + 0x86);
            if (tid >= 0) {
                ((BackgroundLoader*)BackgroundLoader::GetInstance())->RemoveTask(tid);
                ((short*)(obj + 0x86))[i] = -1;
            }
        }
        ResetHandle_02188d10((HandleState_02188d10*)(obj + 0x1c));
        *(unsigned char*)(obj + 0x7f) = 0;
    }
    unsigned char flags2 = *(unsigned char*)(obj + 0x81);
    if (flags2 & 0x10) return;
    *(unsigned char*)(obj + 0x81) = flags2 | 0x10;
    int id2 = *(int*)(obj + 0x70);
    if (id2 >= 0) {
        ((BackgroundLoader*)loader)->RemoveTask(id2);
        *(int*)(obj + 0x70) = -1;
    }
    *(unsigned char*)(obj + 0x7e) = 0;
}
