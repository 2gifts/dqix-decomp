#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "GameState/Field3b0.h"
#include "Memory/SafeAllocator.h"
#include "Resource/Brightness.h"
#include "System/BGBases.h"
#include "System/Matrix.h"
#include <globaldefs.h>

struct GameObject;

struct Camera0217bf78 {
    char unk_0[0x10];
    Vector3i position;
    char unk_1c[0x70 - 0x1c];
    Vector3i tail;
    char unk_7c[0x21e - 0x7c];
    short field_21e;
};

struct Scene0217bf78 {
    char unk_0[0x80];
    char object[0x130 - 0x80];
    int taskA;
    int taskB;
    int taskC;
    int taskD;
    unsigned char mode;
    signed char state;
    char unk_142[2];
    Vector3i cameraPosition;
    Vector3i cameraTail;
    char unk_15c[0x160 - 0x15c];
    int field_160;
};

extern "C" GameResources *func_ov017_0218b5b0(void);
void SetField0x238False(void *obj);
void SetField0x23cTrue(void *obj);
int GetField0x70(void *obj);
int GetGlobalField0x1c020421a0();
void ReinitController02043204(char *obj);
extern "C" void func_ov003_0217c974(Scene0217bf78 *self);
void ApplyVec3Tail(void *obj, int *vec);
void RegisterCombatantSlot(GameState *battleStruct, int id, GameObject *combatant);
extern "C" void func_ov003_0217ca84(Scene0217bf78 *self, unsigned short fillValue);
void ResetSubBg1AndClearCache020a64e8(void);
extern "C" void _ZN8Object3D10MakeHiddenEv(void *obj);
void Set3DClearColor(int a, int b, int c, int d, int e);
int SetPowCnt1Bit15_0217c2a0(int enable);
extern "C" void func_ov003_0217cb3c(Scene0217bf78 *self, int mainScreen, int alternate);
void SetForwardAndStore0205ebc0(void *sound, int a, int b);

extern char data_ov003_02180bef[];
extern char data_ov003_02180cf8[];
extern char data_ov003_02180d08[];
extern char data_ov003_02180c07[];
extern Vector3i data_ov003_02180ce0;
extern int data_ov003_02180cec[3];
extern int data_02108760;

// USA: func_ov003_0217bf78
extern "C" ARM void func_ov003_0217bf78(Scene0217bf78 *self) {
    BackgroundLoader *loader = BackgroundLoader::GetInstance();
    GameResources *resources = func_ov017_0218b5b0();

    if (self->state == 0) {
        GameState *gs          = GameState::GetInstance();
        self->taskA            = loader->QueueLoadFileInGP2(data_ov003_02180bef, data_ov003_02180cf8, 0);
        self->taskC            = loader->QueueLoadFile(data_ov003_02180d08, 0);
        self->taskB            = loader->QueueLoadFile(data_ov003_02180c07, 0);
        Camera0217bf78 *camera = (Camera0217bf78*)GetField0x3b0Value(gs);
        SetField0x238False(camera);
        SetField0x23cTrue(camera);
        camera->field_21e = GetField0x70(camera);
        loader->RemoveTask(self->taskD);
        self->taskD = -1;
        self->state++;
    } else if (self->state == 1) {
        if (!loader->GetTaskStatus(self->taskA)) return;
        if (IsBrightnessTransitionActive(resources)) return;
        if (loader->GetDetailedTaskStatus(self->taskA) != 2) {
            loader->RemoveTask(self->taskA);
            self->mode  = 4;
            self->state = 0;
        }
        GameState *gs = GameState::GetInstance();
        ReinitController02043204((char *) GetGlobalField0x1c020421a0());
        func_ov003_0217c974(self);
        Camera0217bf78 *camera = (Camera0217bf78*)GetField0x3b0Value(gs);
        self->cameraPosition   = camera->position;
        self->cameraTail       = camera->tail;
        camera->position       = data_ov003_02180ce0;
        ApplyVec3Tail(camera, data_ov003_02180cec);
        RegisterCombatantSlot(gs, 0xa0, (GameObject *) self->object);
        func_ov003_0217ca84(self, 0);
        self->state++;
    } else if (self->state == 2) {
        if (!loader->GetTaskStatus(self->taskB)) return;
        if (loader->GetDetailedTaskStatus(self->taskB) != 2) {
            loader->RemoveTask(self->taskB);
            self->mode  = 4;
            self->state = 0;
        }
        if (self->field_160 != 0) ResetSubBg1AndClearCache020a64e8();
        _ZN8Object3D10MakeHiddenEv(self->object);
        Set3DClearColor(0, 0x1f, 0x7fff, 0, 0);
        *(volatile unsigned int *) 0x4000000 = (*(volatile unsigned int *) 0x4000000 & ~0x1f00) | 0x100;
        SetPowCnt1Bit15_0217c2a0(1);
        self->state++;
    } else if (self->state == 3) {
        if (!loader->GetTaskStatus(self->taskC)) return;
        if (loader->GetDetailedTaskStatus(self->taskC) != 2) {
            loader->RemoveTask(self->taskC);
            self->mode  = 4;
            self->state = 0;
        }
        func_ov003_0217cb3c(self, 0, 0);
        unsigned short *screen = (unsigned short *) GetSubBG0ScreenBase();
        for (int i = 0; i < 0x800; i++)
            *screen++ = 0;
        *(volatile unsigned int *) 0x4001000 &= ~0x1f00;
        self->mode  = 2;
        self->state = 0;
        SetForwardAndStore0205ebc0(&data_02108760, 0x8b, 0x8b);
    }
}
