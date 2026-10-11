// JPN: func_ov017_021b2be8
#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "Resource/Brightness.h"
#include "Resource/GameResources.h"
#include "System/OverlayId.h"

#if defined(jpn)
enum { Field105 = 0x125, Field2cc = 0x27c };
#else
enum { Field105 = 0x105, Field2cc = 0x2cc };
#endif

extern "C" void func_020c9be0(void);
extern "C" void* func_02012fe4(void);
extern "C" void func_020a1940(unsigned int id);
void PushInputLogB(int value);
void PushInputLogA(int value);
extern "C" void func_ov011_0218438c(char* obj);
extern "C" void func_ov011_02184550(char* obj, SafeAllocator* allocator, void* data, unsigned int length);
extern "C" void _Z26InitAndCreateTypeB021845c8PcPvj(char* obj, void* buffer, unsigned int size);
extern "C" void _Z17InitEntry02184640PcS_(char* obj, char* entry);
extern "C" void func_ov011_02184694(char* obj);
void SetBitsInField4(unsigned int* field, unsigned int bits);
void Set3DClearColor(int a, int b, int c, int d, int e);

struct Flags021b24d0 {
    char pad[Field105];
    unsigned char flags;
};

struct Region2cc {
    char pad[0xc40];
    char entry[1];
};

struct Holder021b24d0 {
    int f0;
    char* scene;
};

extern Holder021b24d0 data_ov017_021d83f0;

struct Task021b24d0 {
    char pad0[8];
    int result;
    int taskId;
    SafeAllocator allocator;
    char pad1[0x30 - 0x24];
    void (*onAllocate)(SafeAllocator* allocator, char* scene);
    char pad2[0x38 - 0x34];
    unsigned int flag0 : 5;
    unsigned int keepField4Bits : 1;
};

// USA: func_ov017_021b24d0
extern "C" ARM int func_ov017_021b24d0(Task021b24d0* task) {
    GameResources* res = func_ov017_0218b5b0();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (IsBrightnessTransitionActive(res)) {
        return task->result;
    }
    if (loader->GetTaskStatus(task->taskId) == 0) {
        return task->result;
    }
    if (loader->GetDetailedTaskStatus(task->taskId) != 2) {
        func_020c9be0();
    }
    Flags021b24d0* flags = (Flags021b24d0*)func_02012fe4();
    if (flags != NULL) {
        flags->flags |= 1;
    }
    unsigned int length;
    void* data;
    loader->GetLoadedFileByID(task->taskId, &data, &length);
    if (data == NULL || length == 0) {
        func_020c9be0();
    }
    func_020a1940(OVERLAY_ID(11));
    PushInputLogB(1);
    PushInputLogA(4);
    data_ov017_021d83f0.scene = (char*)task->allocator.Allocate(0x1e0);
    if (data_ov017_021d83f0.scene == NULL) {
        func_020c9be0();
    }
    func_ov011_0218438c(data_ov017_021d83f0.scene);
    func_ov011_02184550(data_ov017_021d83f0.scene, &task->allocator, data, length);
    if (task->onAllocate != NULL) {
        task->onAllocate(&task->allocator, data_ov017_021d83f0.scene);
    }
    unsigned int size = task->allocator.GetMaxPossibleAllocation();
    _Z26InitAndCreateTypeB021845c8PcPvj(data_ov017_021d83f0.scene, task->allocator.Allocate(size), size);
    _Z17InitEntry02184640PcS_(data_ov017_021d83f0.scene, ((Region2cc*)((char*)res + Field2cc))->entry);
    loader->RemoveTask(task->taskId);
#if !defined(jpn)
    task->taskId = -1;
#endif
    func_ov011_02184694(data_ov017_021d83f0.scene);
    if (!task->keepField4Bits) {
        SetBitsInField4((unsigned int*)res, 0x609fe);
    }
    Set3DClearColor(0, 0, 0x7fff, 0, 0);
    return 2;
}
