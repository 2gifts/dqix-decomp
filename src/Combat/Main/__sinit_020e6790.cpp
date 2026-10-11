#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern "C" void func_0200ee94(void* obj, int count, int size, void* cb1, void* cb2);

extern "C" void _ZN18VRAMStagingManager4TaskC1Ev(void* self);
extern "C" void _ZN18VRAMStagingManager22StagingSpaceAllocationC1Ev(void* self);
extern "C" void _ZN18VRAMStagingManager23CommonVRAMRegionTaskSetC1EPht(void* self,
    unsigned char* pendingTaskIndices, unsigned short maxNumTasks);
extern "C" void _ZN18VRAMStagingManagerC1Ev(void* self);
extern "C" void _ZN18VRAMStagingManagerD1Ev(void* self);
extern "C" void __register_global_object(void* obj, void* func, void* node);

extern char g_vramStagingTaskQueue[0x100][0x10];
extern char g_vramStagingAllocations[0x80][6];

extern char g_vramStagingRegionalTaskSets;
extern char data_01ffdd84;
extern char data_01ffdd90;
extern char data_01ffdd9c;
extern char data_01ffdda8;
extern char data_01ffddb4;
extern char data_01ffddc0;
extern char data_01ffddcc;
extern char data_01ffddd8;
extern char data_01ffdde4;

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

extern int g_stagingManagerInstance;
extern int data_0214e5b0;

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_020e6790
extern "C" __declspec(initcode) ARM void __sinit_020e6790(void) {
    func_0200ee94(g_vramStagingTaskQueue, 0x100, 0x10, (void*)_ZN18VRAMStagingManager4TaskC1Ev, 0);
    func_0200ee94(g_vramStagingAllocations, 0x80, 6,
        (void*)_ZN18VRAMStagingManager22StagingSpaceAllocationC1Ev, 0);

    _ZN18VRAMStagingManager23CommonVRAMRegionTaskSetC1EPht(&g_vramStagingRegionalTaskSets,
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

    ((void (*)(void*))_ZN18VRAMStagingManagerC1Ev)(&g_stagingManagerInstance);
    __register_global_object(&g_stagingManagerInstance, (void*)_ZN18VRAMStagingManagerD1Ev,
        &data_0214e5b0);
}
