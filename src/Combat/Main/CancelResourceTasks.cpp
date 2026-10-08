#include "Filesystem/BackgroundLoader.h"
#include <globaldefs.h>

void ReleaseHandle02022b90(void *owner, int *handle);

struct CleanupReceiver02022bb0 {
    char pad0[0x9b8];
    unsigned char flag9b8;
    char pad9b9[8];
    unsigned char currentMode;
    unsigned char transitionState;
    unsigned char active;
    unsigned char flag9c4;
    unsigned char flag9c5;
    char pad9c6[6];
    int task9cc;
    int task9d0;
    int task9d4;
    int entryTasks[8];
    int task9f8;
    int task9fc;
    int taska00;
    int taska04;
    int taska08;
    int mode2Task;
    int taska10;
    int taska14;
    int taska18;
    int taska1c;
    int taska20;
    int taska24;
    int taska28;
    int taska2c;
    int taska30;
    unsigned char previousMode;
};

// USA: func_02022bb0
extern "C" ARM void func_02022bb0(void *receiver) {
    CleanupReceiver02022bb0 *object = (CleanupReceiver02022bb0 *) receiver;
    object->active                  = 0;
    object->transitionState         = 0;
    object->flag9c5                 = 0;
    object->flag9b8                 = 0;
    object->previousMode            = 0xff;
    object->flag9c4                 = 0;

    BackgroundLoader::GetInstance()->RemoveTask(object->task9cc);
    object->task9cc = -1;
    BackgroundLoader::GetInstance()->RemoveTask(object->task9f8);
    object->task9f8 = -1;
    BackgroundLoader::GetInstance()->RemoveTask(object->task9d0);
    object->task9d0 = -1;
    BackgroundLoader::GetInstance()->RemoveTask(object->task9d4);
    object->task9d4 = -1;

    for (int i = 0; i < 8; i++) {
        ReleaseHandle02022b90(receiver, &object->entryTasks[i]);
    }

    BackgroundLoader::GetInstance()->RemoveTask(object->task9fc);
    object->task9fc = -1;
    BackgroundLoader::GetInstance()->RemoveTask(object->taska00);
    object->taska00 = -1;
    BackgroundLoader::GetInstance()->RemoveTask(object->taska04);
    object->taska04 = -1;
    BackgroundLoader::GetInstance()->RemoveTask(object->taska08);
    object->taska08 = -1;
    BackgroundLoader::GetInstance()->RemoveTask(object->taska10);
    object->taska10 = -1;
    BackgroundLoader::GetInstance()->RemoveTask(object->taska14);
    object->taska14 = -1;
    BackgroundLoader::GetInstance()->RemoveTask(object->taska18);
    object->taska18 = -1;
    BackgroundLoader::GetInstance()->RemoveTask(object->taska1c);
    object->taska1c = -1;
    BackgroundLoader::GetInstance()->RemoveTask(object->taska20);
    object->taska20 = -1;
    BackgroundLoader::GetInstance()->RemoveTask(object->taska24);
    object->taska24 = -1;
    BackgroundLoader::GetInstance()->RemoveTask(object->taska28);
    object->taska28 = -1;
    BackgroundLoader::GetInstance()->RemoveTask(object->taska2c);
    object->taska2c = -1;
    BackgroundLoader::GetInstance()->RemoveTask(object->taska30);
    object->taska30 = -1;

    if (object->currentMode == 2) {
        BackgroundLoader::GetInstance()->RemoveTask(object->mode2Task);
        object->mode2Task = -1;
    }
}
