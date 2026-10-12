#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

#define REG_SUB_BG_0208cb08 (*(volatile SubRegisters_0208cb08*)0x04001000)
struct SubRegisters_0208cb08 {
    unsigned int display;
    unsigned int field_0x4;
    unsigned short backgrounds[4];
};
struct HeadNode02046b24;
struct SubBgControlBackup02074b64 { unsigned char registers[0x14]; };
struct AllocTarget0204b12c;
struct Foo0204af38;
struct Obj0204b5e8;
struct ActiveEntry02046900;
struct Rec020467f0;
struct Input_0208cb08 {
    unsigned char padding[0x1c];
    unsigned char flags;
    unsigned char padding_0x1d[3];
};
struct Arena_0208cb08 {
    SafeAllocator fileAllocator;
    SafeAllocator inputAllocator;
    unsigned char padding[0x14];
    SafeAllocator resourceAllocator;
};
struct Object_0208cb08 {
    Arena_0208cb08* arena;
    unsigned char container[0x28];
    SubBgControlBackup02074b64 backup;
    Input_0208cb08 input;
    unsigned char resource[0x40];
    void* source;
    unsigned char padding_0xa4[8];
    unsigned short format;
    unsigned char padding_0xae[2];
    unsigned char pending;
    unsigned char padding_0xb1[3];
    char* filename;
    unsigned int field_0xb8;
    int taskId;
    unsigned char padding_0xc0[0x12];
    short target;
    unsigned char complete, state, mode;
    unsigned char padding_0xd7[3];
    unsigned short flags;
};
int GetWord0x0(int*);
void SetBitsInWord(unsigned int*, unsigned int);
unsigned int* GetDataPtr02114e04_020d6c00();
void OrBitsIntoField0(unsigned int*, unsigned int);
int GetGlobal02109400();
int GetHeadNodeIdOrMinusOne(HeadNode02046b24**);
void BlankFunction02094b30();
int AlwaysTrue02094b4c();
void BackupSubBgControlRegisters(SubBgControlBackup02074b64*);
void OrGlobalFlag0x40();
void SetSubBrightness(GameResources*, int, int);
int IsSubBrightnessTransitionActive(GameResources*);
void SetWord0x18ClearByte0x1f(unsigned char*, int);
void AllocateAndClearBuffer0204b12c(AllocTarget0204b12c*, SafeAllocator*);
void AllocateArray0204af38(Foo0204af38*, int, SafeAllocator*);
void DispatchViaTable0204b5e8(Obj0204b5e8*, int, int);
void SetSubBg0Control0208c9cc(int, int, int, int, int);
int CountActiveEntries(ActiveEntry02046900*);
void* FindRecordByIndex(Rec020467f0*, int, void**, int*);
void WrapAddByteField0x22(int, char*, unsigned int, int);
extern "C" void func_0204b5b4(void*, int);
extern "C" int func_0205a528(void*, void*, int, int);
extern "C" void func_020dfec0(void*, SafeAllocator*, void*, unsigned int);
extern "C" void func_0208bf78(Object_0208cb08*);
extern char data_020f11a2[], data_020f11b3[], data_020f11c0[], data_020f11da[];
typedef void (*NotificationRequest_0208cb08)(int, int, int);

// USA: func_0208cb08
extern "C" ARM void func_0208cb08(Object_0208cb08* object) {
    if (object->target < 0) return;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    GameResources* resources = (GameResources*)GetWord0x0((int*)GameState::GetInstance());
    if (object->state == 0) {
        SetBitsInWord(&resources->brightnessFlags_0, 0x6000);
        OrBitsIntoField0(GetDataPtr02114e04_020d6c00(), 1);
        int global = GetGlobal02109400();
        int notification = 0x67;
        if (GetHeadNodeIdOrMinusOne((HeadNode02046b24**)resources->unknown_ptr_array_36fc[0]) != 0x2d) {
            if (object->target < 0) notification = 0x32;
            else {
                int level = object->target / 20;
                if (level > 9) level = 9;
                notification = level + 0x32;
            }
        }
        ((NotificationRequest_0208cb08)BlankFunction02094b30)(global, notification, 0);
        ++object->state;
    } else if (object->state == 1) {
        GetGlobal02109400();
        if (AlwaysTrue02094b4c()) ++object->state;
    } else if (object->state == 2) {
        BackupSubBgControlRegisters(&object->backup);
        OrGlobalFlag0x40();
        if (!(object->flags & 0x10)) SetSubBrightness(resources, -16, 8);
        ++object->state;
    } else if (object->state == 3) {
        if (IsSubBrightnessTransitionActive(resources)) return;
        Arena_0208cb08* arena = object->arena;
        arena->inputAllocator.Reset();
        SetWord0x18ClearByte0x1f((unsigned char*)&object->input, 0);
        object->input.flags = (object->input.flags & ~0xf) | 1;
        object->input.flags &= ~0xf0;
        func_0204b5b4(&object->input, 0);
        AllocateAndClearBuffer0204b12c((AllocTarget0204b12c*)&object->input, &arena->inputAllocator);
        AllocateArray0204af38((Foo0204af38*)&object->input, 1, &arena->inputAllocator);
        DispatchViaTable0204b5e8((Obj0204b5e8*)&object->input, 0, 0);
        SetSubBg0Control0208c9cc(0, 0, 15, 0, 0);
        object->pending = 1;
        object->source = object->filename;
        object->format = 3;
        object->taskId = loader->QueueLoadFileInGP2(data_020f11a2, data_020f11b3, 0);
        ++object->state;
    } else if (object->state == 4) {
        if (!loader->GetTaskStatus(object->taskId)) return;
        Arena_0208cb08* arena = object->arena;
        arena->resourceAllocator.Reset();
        void* record;
        void* file;
        unsigned int length;
        loader->GetLoadedFileByID(object->taskId, &file, &length);
        int count = CountActiveEntries((ActiveEntry02046900*)file);
        int index = 0;
        int size;
        for (; index < count; ++index) {
            void* data = FindRecordByIndex((Rec020467f0*)file, index, &record, &size);
            func_0205a528(object->resource, data, size, (int)&arena->resourceAllocator);
        }
        WrapAddByteField0x22((int)object->resource, object->filename, 3, 0x40);
        loader->RemoveTask(object->taskId);
        object->taskId = -1;
        ++object->state;
    } else if (object->state == 5) {
        object->taskId = loader->QueueLoadFileInGP2(data_020f11c0, data_020f11da, 0);
        ++object->state;
    } else if (object->state == 6) {
        if (!loader->GetTaskStatus(object->taskId)) return;
        Arena_0208cb08* arena = object->arena;
        void* file;
        unsigned int length;
        loader->GetLoadedFileByID(object->taskId, &file, &length);
        if (arena) {
            arena->fileAllocator.Reset();
            func_020dfec0(object->container, &arena->fileAllocator, file, length);
        }
        loader->RemoveTask(object->taskId);
        object->taskId = -1;
        ++object->state;
    } else if (object->state == 7) {
        func_0208bf78(object);
        ++object->state;
    } else if (object->state == 8) {
        if (!object->mode) {
            REG_SUB_BG_0208cb08.backgrounds[0] &= ~3;
            REG_SUB_BG_0208cb08.backgrounds[1] = (REG_SUB_BG_0208cb08.backgrounds[1] & ~3) | 2;
            REG_SUB_BG_0208cb08.backgrounds[2] = (REG_SUB_BG_0208cb08.backgrounds[2] & ~3) | 3;
            REG_SUB_BG_0208cb08.backgrounds[3] = (REG_SUB_BG_0208cb08.backgrounds[3] & ~3) | 1;
            REG_SUB_BG_0208cb08.display = (REG_SUB_BG_0208cb08.display & ~0x1f00) | 0x1900;
            if (GetHeadNodeIdOrMinusOne((HeadNode02046b24**)resources->unknown_ptr_array_36fc[0]) == 0x2d) {
                if (!IsSubBrightnessTransitionActive(resources)) SetSubBrightness(resources, 0, 25);
            } else if (!(object->flags & 0x10)) SetSubBrightness(resources, 0, 8);
            ++object->state;
        } else func_0208bf78(object);
    } else if (object->state == 9) {
        if (!IsSubBrightnessTransitionActive(resources)) {
            object->complete = 1;
            object->state = 0;
        }
    }
}
