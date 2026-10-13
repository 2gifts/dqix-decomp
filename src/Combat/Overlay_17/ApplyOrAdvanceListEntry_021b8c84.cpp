#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

extern "C" {
}
extern "C" void* func_02012fe4(void);
extern "C" void* func_0205ec34(void);
extern "C" void func_0206461c(void* a, int b);
extern int data_ov017_021d7c3c;

struct List0202fe68;

struct Entry021b8c84 {
    unsigned char pad0;
    unsigned char flag;
    unsigned char pad1[6];
    int key;
};

// USA: func_ov017_021b8c84
ARM void ApplyOrAdvanceListEntry_021b8c84(struct Entry021b8c84* obj, void* context) {
    GameState::GetInstance();
    int listPtr = (int)BackgroundLoader::GetInstance();
    if (obj->key == -1) {
        obj->key = ((BackgroundLoader*)(listPtr))->QueueLoadFile((const char*)((int)&data_ov017_021d7c3c), (SafeAllocator*)(0));
        return;
    }
    if (!((BackgroundLoader*)(listPtr))->GetTaskStatus((int)(obj->key))) return;
    if (((BackgroundLoader*)((struct List0202fe68*)listPtr))->GetDetailedTaskStatus((int)(obj->key)) == 2) {
        void* a = func_0205ec34();
        func_0206461c(a, *(int*)((char*)func_02012fe4() + 8));
    }
    ((BackgroundLoader*)(listPtr))->RemoveTask((int)(obj->key));
    obj->key = -1;
    obj->flag = 1;
}
