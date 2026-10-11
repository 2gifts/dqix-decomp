#include <globaldefs.h>
#if defined(jpn)
enum { kRegion228 = 0x110 };
enum { kRegiond0 = 0x10 };
enum { kRegion998 = 0x868 };
enum { kRegion2d8 = 0x228 };
enum { kRegion2e6 = 0x236 };
#else
enum { kRegion228 = 0x228 };
enum { kRegiond0 = 0xd0 };
enum { kRegion998 = 0x998 };
enum { kRegion2d8 = 0x2d8 };
enum { kRegion2e6 = 0x2e6 };
#endif
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"

struct FlagWord020466f4;
struct Struct02074bd0;
struct Obj0207fcb8;
struct Cont0207fd44;
struct Cont0207fd88;
struct NotifyEntriesStruct0207f8bc;

void* GetDataPtr02114e04_020d6c00(void);
void ClearFlags020466f4(struct FlagWord020466f4* word, unsigned int mask);
extern "C" void* func_ov017_0218b5b0(void);
void ClearBitsInField4(unsigned int* obj, unsigned int mask);
void ClearFlag0x10IfSet(struct Struct02074bd0* obj);
void ClearAllBuffers0207fcb8(struct Obj0207fcb8* obj);
void CallFunc0204b04cOverList0x2c(struct Cont0207fd44* obj);
void CallFunc0204b088OverList0x2c(struct Cont0207fd88* obj);
void FlushNotifyEntries(struct NotifyEntriesStruct0207f8bc* p);
extern "C" void* memset(void* dst, int val, unsigned int len);
void CleanInvalidateCacheRange(const void* addr, unsigned int size);
extern "C" int LoadToMainBG1CharacterData(int arg0, int arg1, unsigned int arg2);
int GetGlobalField0x1c020421a0(void);
void ReinitController02043204(char* obj);
extern "C" void func_02043124(char* obj);

struct BattleView0215fb94 {
    unsigned char pad_0x0[kRegion228];
    SafeAllocator alloc_0x228;
    SafeAllocator alloc_0x23c;
    unsigned char pad_0x250[0x14];
    SafeAllocator alloc_0x264;
    SafeAllocator alloc_0x278;
    SafeAllocator alloc_0x28c;
    SafeAllocator alloc_0x2a0;
    SafeAllocator alloc_0x2b4;
    SafeAllocator alloc_0x2c8;
    unsigned char pad_0x2dc[0x18];
    unsigned char field_0x2f4[0x30];
    void* field_0x324;
    unsigned char pad_0x328[0x8];
    int savedBgMode;
    unsigned char pad_0x334[0x64];
    void* charBuffer;
    unsigned char pad_0x39c[kRegiond0];
    int loadTaskId;
};

// JPN: func_ov003_0215fd40
// USA: func_ov003_0215fb94
extern "C" ARM void func_ov003_0215fb94(BattleView0215fb94* view) {
    ClearFlags020466f4((struct FlagWord020466f4*)GetDataPtr02114e04_020d6c00(), 0x80000);
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (view->loadTaskId >= 0) {
        loader->RemoveTask(view->loadTaskId);
        view->loadTaskId = -1;
    }

    void* resources = func_ov017_0218b5b0();
    volatile unsigned int* dispcnt = (volatile unsigned int*)0x4000000;
    *dispcnt = (*dispcnt & ~0x1f00) | (view->savedBgMode << 8);
    ClearBitsInField4((unsigned int*)resources, 0xc0);
    *dispcnt = (*dispcnt & ~0x1f00) | 0x100;
    *(volatile unsigned short*)0x4000050 = 0;

    ClearFlag0x10IfSet((struct Struct02074bd0*)view->field_0x2f4);

    void* sub = view->field_0x324;
    if (sub != NULL) {
        ClearAllBuffers0207fcb8((struct Obj0207fcb8*)sub);
        CallFunc0204b04cOverList0x2c((struct Cont0207fd44*)sub);
        CallFunc0204b088OverList0x2c((struct Cont0207fd88*)sub);
        FlushNotifyEntries((struct NotifyEntriesStruct0207f8bc*)sub);
    }

    if (view->charBuffer != NULL) {
        memset(view->charBuffer, 0, 0x20);
        CleanInvalidateCacheRange(view->charBuffer, 0x20);
        LoadToMainBG1CharacterData((int)view->charBuffer, 0, 0x20);
    }
    view->charBuffer = NULL;

    char* controller = (char*)GetGlobalField0x1c020421a0();
    if (*(int*)(controller + kRegion998) != 0) {
        ReinitController02043204(controller);
        func_02043124(controller);
    }
    *(int*)(controller + kRegion2d8) = 0;
    controller[kRegion2e6] = 1;

    view->alloc_0x2c8.Destroy();
    view->alloc_0x2b4.Destroy();
    view->alloc_0x2a0.Destroy();
    view->alloc_0x28c.Destroy();
    view->alloc_0x278.Destroy();
    view->alloc_0x264.Destroy();
    view->alloc_0x23c.Destroy();
    view->alloc_0x228.Destroy();
}
