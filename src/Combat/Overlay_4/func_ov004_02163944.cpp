#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "Grotto/Main/TreasureMapDataStructs.h"
#include "Resource/GameResources.h"
#include "std_library_functions.h"

struct MapDisplayBuffer { TreasureMapMetadata maps[99]; DetailedTreasureMapData details[8]; unsigned char count; char pad18f5[9]; unsigned char busy; char name[17]; int state; };
struct MapDisplayPointers { MapDisplayBuffer* buffer; void* scratch; void* file; };
struct SavedMapList { unsigned char count; unsigned char padding; TreasureMapMetadata maps[99]; };
struct ResourcePanel { char pad[0x14]; int state; };
struct MapZone { char pad[0x26]; char name[17]; };
struct MapController { char pad[0x1962]; unsigned char active; char pad1963; int first[9]; int second[3]; };
struct AxisFloats0203b5a0;
struct MapAllocatorNode { int field0; SafeAllocator allocator; };
extern MapDisplayPointers data_ov004_02171010;
extern char data_ov004_0217055c[];
extern char data_ov004_02170572[];
extern "C" MapAllocatorNode* func_ov011_021845f8(void*, int);
extern "C" void func_020a3844(SafeAllocator*);
void InitBufferAndCopyByte_0216342c(void*);
bool CopyOutBattleRegion0x64f4_020ac760(void*);
extern "C" void VectorizedInvertedMemcpy(const void*, void*, unsigned int);
extern "C" void func_ov004_02163530(void*);
extern "C" void func_ov004_02163c40(void*);
bool FindTreasureMapIndexAndDivide_021635d0(int*, int*);
void Zero4Bytes_020e526c(void*);
extern "C" void func_020e5604(void*, SafeAllocator*, void*, unsigned int);
extern "C" MapZone* func_02012fe4();
void SetByteFieldAt0x765_02026420(unsigned char*, unsigned char);
void SetFieldAt0x76c_020263dc(unsigned char*, void*);
void Notify02022d78WithCode2_020dc3b8();
bool IsAxisIntWithin16(AxisFloats0203b5a0*, int);
void SetSubBrightness(GameResources*, int, int);
extern "C" void func_ov004_021636b0(void*, const char*);
char* GetGlobalField0x1c020421a0();
void ReinitController02043204(char*);
void SetFieldsAt0x4And0x8_020e2d24(int*, int, int);

// USA: func_ov004_02163944
extern "C" ARM int func_ov004_02163944(void* obj) {
    MapAllocatorNode* heap = func_ov011_021845f8(obj, 0);
    if (!heap) return 0;
    SafeAllocator* allocator = &heap->allocator;
    if (!allocator) return 0;
    func_020a3844(allocator);
    data_ov004_02171010.buffer = (MapDisplayBuffer*)allocator->Allocate(0x1914);
    if (!data_ov004_02171010.buffer) return 0;
    InitBufferAndCopyByte_0216342c(data_ov004_02171010.buffer);
    data_ov004_02171010.buffer->busy = 1;
    data_ov004_02171010.scratch = func_ov011_021845f8(obj, 4)->allocator.Allocate(0x333);
    memset(data_ov004_02171010.scratch, 0, 0x333);
    SavedMapList saved;
    if (CopyOutBattleRegion0x64f4_020ac760(&saved)) {
        data_ov004_02171010.buffer->count = saved.count;
        for (int i = 0; i < 99; i++) VectorizedInvertedMemcpy(&saved.maps[i], &data_ov004_02171010.buffer->maps[i], 0x1c);
    }
    func_ov004_02163530(obj);
    func_ov004_02163c40(obj);
    int page = 0;
    int selection = 0;
    if (!FindTreasureMapIndexAndDivide_021635d0(&page, &selection)) { page = 0; selection = 0; }
    for (int i = 0; i < 8; i++) {
        ExportDetailedTreasureMapData(&data_ov004_02171010.buffer->maps[i + page * 8], &data_ov004_02171010.buffer->details[i], true, 0);
    }
    MapAllocatorNode* fileHeap = func_ov011_021845f8(obj, 3);
    if (!fileHeap) return 0;
    data_ov004_02171010.file = fileHeap->allocator.Allocate(12);
    Zero4Bytes_020e526c(data_ov004_02171010.file);
    BackgroundLoader::AddLockGlobal();
    unsigned int length = 0;
    void* file = ExtractFileFromGP2(data_ov004_0217055c, data_ov004_02170572, &length);
    func_020e5604(data_ov004_02171010.file, &fileHeap->allocator, file, length);
    BackgroundLoader::RemoveLockGlobal();
    MapZone* zone = func_02012fe4();
    ResourcePanel* panel = (ResourcePanel*)func_ov017_0218b5b0()->unknown_ptr_36d0;
    data_ov004_02171010.buffer->state = panel->state;
    strcpy(data_ov004_02171010.buffer->name, zone->name);
    SetByteFieldAt0x765_02026420((unsigned char*)panel, 1);
    SetFieldAt0x76c_020263dc((unsigned char*)panel, allocator);
    Notify02022d78WithCode2_020dc3b8();
    GameResources* resources = func_ov017_0218b5b0();
    if (IsAxisIntWithin16((AxisFloats0203b5a0*)resources, 1)) SetSubBrightness(resources, -16, 0);
    func_ov004_021636b0(obj, data_ov004_02171010.buffer->details[selection].mapImageName_);
    MapController* controller = (MapController*)GetGlobalField0x1c020421a0();
    ReinitController02043204((char*)controller);
    controller->active = 1;
    SetFieldsAt0x4And0x8_020e2d24(controller->first, 9, 1);
    SetFieldsAt0x4And0x8_020e2d24(controller->second, 25, 1);
    data_ov004_02171010.buffer->busy = 0;
    return 0;
}
