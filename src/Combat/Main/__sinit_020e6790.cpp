#include "Graphics/itcm/VRAMStaging.h"
#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern "C" void func_0200ee94(void* obj, int count, int size, void* cb1, void* cb2);

extern "C" VRAMStagingManager::Task* _ZN18VRAMStagingManager4TaskC1Ev(VRAMStagingManager::Task* self);
extern "C" VRAMStagingManager::StagingSpaceAllocation* _ZN18VRAMStagingManager22StagingSpaceAllocationC1Ev(
    VRAMStagingManager::StagingSpaceAllocation* self);
extern "C" VRAMStagingManager::CommonVRAMRegionTaskSet* _ZN18VRAMStagingManager23CommonVRAMRegionTaskSetC1EPht(
    VRAMStagingManager::CommonVRAMRegionTaskSet* self, unsigned char* pendingTaskIndices, unsigned short maxNumTasks);
extern "C" VRAMStagingManager* _ZN18VRAMStagingManagerC1Ev(VRAMStagingManager* self);
extern "C" VRAMStagingManager* _ZN18VRAMStagingManagerD1Ev(VRAMStagingManager* self);
extern "C" void __register_global_object(void* obj, void* func, void* node);

extern VRAMStagingManager::Task g_vramStagingTaskQueue[0x100];
extern VRAMStagingManager::StagingSpaceAllocation g_vramStagingAllocations[0x80];

extern VRAMStagingManager::CommonVRAMRegionTaskSet g_vramStagingRegionalTaskSets[10];
extern VRAMStagingManager::CommonVRAMRegionTaskSet data_01ffdd84;
extern VRAMStagingManager::CommonVRAMRegionTaskSet data_01ffdd90;
extern VRAMStagingManager::CommonVRAMRegionTaskSet data_01ffdd9c;
extern VRAMStagingManager::CommonVRAMRegionTaskSet data_01ffdda8;
extern VRAMStagingManager::CommonVRAMRegionTaskSet data_01ffddb4;
extern VRAMStagingManager::CommonVRAMRegionTaskSet data_01ffddc0;
extern VRAMStagingManager::CommonVRAMRegionTaskSet data_01ffddcc;
extern VRAMStagingManager::CommonVRAMRegionTaskSet data_01ffddd8;
extern VRAMStagingManager::CommonVRAMRegionTaskSet data_01ffdde4;

extern unsigned char data_01ffddf0[0x80];
extern unsigned char data_01ffde70[0x100];
extern unsigned char data_01ffdc78[0x10];
extern unsigned char data_01ffdcf8[0x40];
extern unsigned char data_01ffdc88[0x10];
extern unsigned char data_01ffdd38[0x40];
extern unsigned char data_01ffdca8[0x10];
extern unsigned char data_01ffdcb8[0x20];
extern unsigned char data_01ffdc98[0x10];
extern unsigned char data_01ffdcd8[0x20];

extern VRAMStagingManager g_stagingManagerInstance;
extern int data_0214e5b0;

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_020e6790
extern "C" __declspec(initcode) ARM void __sinit_020e6790(void) {
    func_0200ee94(g_vramStagingTaskQueue, 0x100, 0x10, (void*)_ZN18VRAMStagingManager4TaskC1Ev, 0);
    func_0200ee94(g_vramStagingAllocations, 0x80, 6,
        (void*)_ZN18VRAMStagingManager22StagingSpaceAllocationC1Ev, 0);

    _ZN18VRAMStagingManager23CommonVRAMRegionTaskSetC1EPht(g_vramStagingRegionalTaskSets,
        data_01ffddf0, 0x80);
    _ZN18VRAMStagingManager23CommonVRAMRegionTaskSetC1EPht(&data_01ffdd84, data_01ffde70, 0x100);
    _ZN18VRAMStagingManager23CommonVRAMRegionTaskSetC1EPht(&data_01ffdd90, data_01ffdc78, 0x10);
    _ZN18VRAMStagingManager23CommonVRAMRegionTaskSetC1EPht(&data_01ffdd9c, data_01ffdcf8, 0x40);
    _ZN18VRAMStagingManager23CommonVRAMRegionTaskSetC1EPht(&data_01ffdda8, data_01ffdc88, 0x10);
    _ZN18VRAMStagingManager23CommonVRAMRegionTaskSetC1EPht(&data_01ffddb4, data_01ffdd38, 0x40);
    _ZN18VRAMStagingManager23CommonVRAMRegionTaskSetC1EPht(&data_01ffddc0, data_01ffdca8, 0x10);
    _ZN18VRAMStagingManager23CommonVRAMRegionTaskSetC1EPht(&data_01ffddcc, data_01ffdcb8, 0x20);
    _ZN18VRAMStagingManager23CommonVRAMRegionTaskSetC1EPht(&data_01ffddd8, data_01ffdc98, 0x10);
    _ZN18VRAMStagingManager23CommonVRAMRegionTaskSetC1EPht(&data_01ffdde4, data_01ffdcd8, 0x20);

    _ZN18VRAMStagingManagerC1Ev(&g_stagingManagerInstance);
    __register_global_object(&g_stagingManagerInstance, (void*)_ZN18VRAMStagingManagerD1Ev,
        &data_0214e5b0);
}
