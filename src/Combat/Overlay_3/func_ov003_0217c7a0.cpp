#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Filesystem/BackgroundLoader.h"
#include "Resource/Brightness.h"
#include "System/Matrix.h"

struct Obj0204b010;
struct List0204afb4;

struct Camera0217c7a0
{
    char unk_0[0x10];
    Vector3i position;
};

struct RecordList0217c7a0
{
    char data[0x20];
};

struct Scene0217c7a0
{
    SafeAllocator* allocator;
    SafeAllocator allocA;
    SafeAllocator allocB;
    SafeAllocator allocC;
    RecordList0217c7a0 listA;
    RecordList0217c7a0 listB;
    char unk_80[0x130 - 0x80];
    int taskA;
    int taskB;
    int taskC;
    char unk_13c[0x141 - 0x13c];
    signed char state;
    char unk_142;
    unsigned char finished;
    Vector3i cameraPosition;
    int cameraTail[3];
};

extern "C" GameResources* func_ov017_0218b5b0(void);
extern "C" void _Z19ClearBuffer0204b010P11Obj0204b010Pv(Obj0204b010* obj, void* buf);
extern "C" void func_0204b04c(void* obj, int flag);
extern "C" void func_0204b088(void* obj, int flag);
extern "C" void _Z23ResetRecordList0204afb4P12List0204afb4(List0204afb4* list);
void Set3DClearColor(int a, int b, int c, int d, int e);
Camera0217c7a0* GetField0x3b0Value(GameState* gs);
void ApplyVec3Tail(void* obj, int* vec);
void SetField0x238True(void* obj);
void ApplyVecFromField0x21e(char* obj);
extern "C" int _Z24SetPowCnt1Bit15_0217c2a0i(int enable);
void ClearCombatantSlot(GameState* gs, int id);

// USA: func_ov003_0217c7a0
extern "C" ARM void func_ov003_0217c7a0(Scene0217c7a0* self)
{
    GameResources* resources = func_ov017_0218b5b0();
    if (self->state == 0)
    {
        SetBrightness(resources, -16, 0x3c);
        self->state++;
    }
    else if (self->state == 1)
    {
        if (IsBrightnessTransitionActive(resources))
            return;

        GameState* gs = GameState::GetInstance();
        void* block;

        block = self->allocA.GetSignedAllocator();
        if (block)
        {
            self->allocA.Destroy();
            self->allocator->Free(block);
        }
        block = self->allocB.GetSignedAllocator();
        if (block)
        {
            self->allocB.Destroy();
            self->allocator->Free(block);
        }
        block = self->allocC.GetSignedAllocator();
        if (block)
        {
            self->allocC.Destroy();
            self->allocator->Free(block);
        }

        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        loader->RemoveTask(self->taskA);
        self->taskA = -1;
        loader->RemoveTask(self->taskB);
        self->taskB = -1;
        loader->RemoveTask(self->taskC);
        self->taskC = -1;

        _Z19ClearBuffer0204b010P11Obj0204b010Pv((Obj0204b010*)&self->listA, 0);
        func_0204b04c(&self->listA, 0);
        func_0204b088(&self->listA, 0);
        _Z23ResetRecordList0204afb4P12List0204afb4((List0204afb4*)&self->listA);
        _Z19ClearBuffer0204b010P11Obj0204b010Pv((Obj0204b010*)&self->listB, 0);
        func_0204b04c(&self->listB, 0);
        func_0204b088(&self->listB, 0);
        _Z23ResetRecordList0204afb4P12List0204afb4((List0204afb4*)&self->listB);

        Set3DClearColor(0, 0, 0x7fff, 0, 0);
        Camera0217c7a0* camera = GetField0x3b0Value(gs);
        camera->position = self->cameraPosition;
        ApplyVec3Tail(camera, self->cameraTail);
        SetField0x238True(camera);
        ApplyVecFromField0x21e((char*)camera);
        _Z24SetPowCnt1Bit15_0217c2a0i(0);
        ClearCombatantSlot(gs, 0xa0);
        self->finished = 1;
    }
}
