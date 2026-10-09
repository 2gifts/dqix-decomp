#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

extern "C" int _Z26GetGlobalField0x1c020421a0v(void);
extern "C" void* _Z27GetDataPtr02114e04_020d6c00v(void);
struct FlagWord020466f4;
extern "C" void _Z18ClearFlags020466f4P16FlagWord020466f4j(struct FlagWord020466f4* word, unsigned int mask);
struct ClearTarget0205a244;
extern "C" void _Z23ClearField0And40205a244P19ClearTarget0205a244(struct ClearTarget0205a244* target);
extern "C" void _Z23EmptyDestructor0205a494Pv(void* obj);
extern "C" void _Z32ResetSubBg1AndClearCache020a64e8v(void* obj);
struct Struct02074bd0;
void ClearFlag0x10IfSet(struct Struct02074bd0* obj);
struct Struct02074bf4;
void ClearFlag0x11IfSet(struct Struct02074bf4* obj);
void ClearBitsInWord(unsigned int* obj, unsigned int mask);
void ClearBitsInField4(unsigned int* obj, unsigned int mask);
struct List020727d8 {
    void* entries;
    short capacity;
    short count;
};
extern "C" void _Z23ResetListHeader020727ecP12List020727d8(struct List020727d8* list);
void CleanCacheRange(const void* addr, unsigned int size);
void CleanInvalidateCacheRange(const void* addr, unsigned int size);
extern "C" int LoadToMainBG1CharacterData(const void* src, unsigned int offset, unsigned int size);
extern "C" void* GetMainBG1ScreenBase(void);
unsigned long long GetCurrentTimestamp(void);

struct BattleScene_02173d40 {
    unsigned char pad0[0xd8];
    unsigned char field_0xd8[0xfa - 0xd8];
    unsigned char field_0xfa[0x10c - 0xfa];
    unsigned char field_0x10c[0x120 - 0x10c];
    int mainBgPriority;
    int subBgPriority;
    unsigned char pad128[0x12c - 0x128];
    struct ClearTarget0205a244* field_0x12c;
    unsigned char field_0x130[0x184 - 0x130];
    SafeAllocator allocators[3];
    unsigned char pad1c0[0x1c8 - 0x1c0];
    struct List020727d8 lists[3];
};

// USA: func_ov003_02173d40
extern "C" ARM void func_ov003_02173d40(BattleScene_02173d40* scene) {
    GameState* gs = GameState::GetInstance();
    GameResources* resources = func_ov017_0218b5b0();
    unsigned char* global = (unsigned char*)_Z26GetGlobalField0x1c020421a0v();
    _Z18ClearFlags020466f4P16FlagWord020466f4j((struct FlagWord020466f4*)_Z27GetDataPtr02114e04_020d6c00v(), 0x1000);
    global[0x1000 + 0x9be] = 0;
    _Z23ClearField0And40205a244P19ClearTarget0205a244(scene->field_0x12c);
    _Z23EmptyDestructor0205a494Pv(scene->field_0x130);
    _Z32ResetSubBg1AndClearCache020a64e8v(scene->field_0xd8);
    *(volatile int*)0x4001010 = 0;
    ClearFlag0x10IfSet((struct Struct02074bd0*)scene->field_0xfa);
    ClearFlag0x11IfSet((struct Struct02074bf4*)scene->field_0x10c);

    volatile unsigned int* dispcnt = (volatile unsigned int*)0x4000000;
    *dispcnt = (*dispcnt & ~0x1f00) | (scene->mainBgPriority << 8);
    volatile unsigned int* subDispcnt = (volatile unsigned int*)0x4001000;
    *subDispcnt = (*subDispcnt & ~0x1f00) | (scene->subBgPriority << 8);

    ClearBitsInWord(&resources->brightnessFlags_0, 4);
    ClearBitsInField4(&resources->brightnessFlags_0, 0x81e);
    _Z23ResetListHeader020727ecP12List020727d8(&scene->lists[0]);
    _Z23ResetListHeader020727ecP12List020727d8(&scene->lists[1]);
    _Z23ResetListHeader020727ecP12List020727d8(&scene->lists[2]);
    scene->allocators[0].Destroy();
    scene->allocators[1].Destroy();
    scene->allocators[2].Destroy();

    unsigned char palette[0x20];
    memset(palette, 0, 0x20);
    CleanCacheRange(palette, 0x20);
    CleanInvalidateCacheRange(palette, 0x20);
    LoadToMainBG1CharacterData(palette, 0, 0x20);
    memset(GetMainBG1ScreenBase(), 0, 0x800);

    *(int*)(global + 0x2d8) = 0;
    *(int*)(global + 0x2dc) = 0;
    *(int*)(global + 0x2e0) = 0;
    gs->mainTimestamp_ = GetCurrentTimestamp();
    gs->altTimestamp_ = GetCurrentTimestamp();
}
