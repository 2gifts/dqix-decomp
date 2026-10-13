#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"

#if defined(jpn)
enum { kWidgetCount = 17, kWidgetArrayOffset = 0x133c, kTargetOffset = 0x1338, kContainerOffset = 0x1334, kTaskOffset = 0x135c, kAllocatorOffset = 0x54 };
#else
enum { kWidgetCount = 19, kWidgetArrayOffset = 0x1364, kTargetOffset = 0x1360, kContainerOffset = 0x135c, kTaskOffset = 0x1390, kAllocatorOffset = 0x5c };
#endif

struct Struct0205a198;
void Init0205a198(Struct0205a198*);
struct ClearTarget0205a234;
void ClearField0And40205a234(ClearTarget0205a234*);
void InitStruct0205a444(char*);
struct ActiveEntry02046900;
int CountActiveEntries(ActiveEntry02046900*);
struct Rec020467f0;
void* FindRecordByIndex(Rec020467f0*, int, void**, int*);
extern "C" void func_0205a528(void*, void*, int, void*);

// USA: func_ov012_021861e0
// JPN: func_ov012_02186880
extern "C" ARM void func_ov012_021861e0(char* editor) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    for (unsigned char i = 0; i < kWidgetCount; ++i)
        Init0205a198((Struct0205a198*)(*(char**)(editor + kWidgetArrayOffset) + i * 0x28));
    ClearField0And40205a234(*(ClearTarget0205a234**)(editor + kTargetOffset));
    InitStruct0205a444(*(char**)(editor + kContainerOffset));
    *(unsigned char*)(*(char**)(editor + kContainerOffset) + 0x50) = 0;
    char* container = *(char**)(editor + kContainerOffset);
    *(void**)(container + 0x40) = *(void**)(editor + kWidgetArrayOffset);
    *(short*)(container + 0x4c) = kWidgetCount;
    void* target = *(void**)(editor + kTargetOffset);
    char* refreshedContainer = *(char**)(editor + kContainerOffset);
    *(void**)(refreshedContainer + 0x3c) = target;

    void* recordOut;
    void* fileData;
    unsigned int fileSize;
    int fieldOut;
    loader->GetLoadedFileByID(*(int*)(editor + kTaskOffset), &fileData, &fileSize);
    int count = CountActiveEntries((ActiveEntry02046900*)fileData);
    ((SafeAllocator*)(editor + kAllocatorOffset))->Reset();
    for (int i = 0; i < count; ++i) {
        void* record = FindRecordByIndex((Rec020467f0*)fileData, i, &recordOut, &fieldOut);
        func_0205a528(*(char**)(editor + kContainerOffset), record, fieldOut, editor + kAllocatorOffset);
    }
    loader->RemoveTask(*(int*)(editor + kTaskOffset));
    *(int*)(editor + kTaskOffset) = -1;
}
