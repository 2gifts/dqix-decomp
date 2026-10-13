#if defined(jpn)
#define func_ov013_021846a0 func_ov013_021856dc
#endif

#include <globaldefs.h>

#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "System/Graphics.h"

struct MenuManager {
#if defined(jpn)
    char unknown0[0x17ee];
#else
    char unknown0[0x19be];
#endif
    unsigned char menuActive;
};

struct SkillPointMenu {
    SafeAllocator allocator;
#if defined(jpn)
    char unknown14[0x1e - 0x14];
    char resetState[0x12];
#else
    char unknown14[0x20 - 0x14];
    char resetState[0x12];
    char unknown32[2];
#endif
    int savedDisplayLayers;
    char window[0xbc];
#if defined(jpn)
    char unknownF0[0x598 - 0xf0];
#else
    char unknownF4[0x60c - 0xf4];
#endif
    SafeAllocator textAllocator;
    char texts[0x18];
    unsigned char unknownStateBytes[4];
    unsigned char state;
    unsigned char previousState;
    unsigned char step;
    bool stateChanged;
    bool subScreen;
    unsigned int ticks;
    int windowInput;
#if !defined(jpn)
    int previousWindowInput;
#endif
    int task;
    void* canvasPixels;
};

MenuManager* GetGlobalField0x1c020421a0(void);

struct Struct02074bf4;
void ClearFlag0x11IfSet(struct Struct02074bf4*);
struct Struct02074bd0;
void ClearFlag0x10IfSet(struct Struct02074bd0*);

struct Entry_0205d6a0;
void ResetEntryList0205d6a0(struct Entry_0205d6a0*, int);
struct Cont0205d1e0;
void ClearBuffers0204b010OverList0x98(struct Cont0205d1e0*);
struct Cont0205d274;
void CallFunc0204b04cOverList0x98(struct Cont0205d274*);
struct Obj0205d2bc;
void InitEntries0205d2bc(struct Obj0205d2bc*);
extern "C" void func_0205d048(void*);

void CleanInvalidateCacheRange(const void*, unsigned int);
extern "C" int LoadToMainBG1CharacterData(const void*, int, unsigned int);

// USA: func_ov013_021846a0  (semantic: ResetCombatOverlayState021846a0)
extern "C" ARM void func_ov013_021846a0(SkillPointMenu* menu) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (menu->task >= 0) {
        loader->RemoveTask(menu->task);
        menu->task = -1;
    }

    GetGlobalField0x1c020421a0()->menuActive = 0;

    if (menu->subScreen) {
        ClearFlag0x11IfSet((struct Struct02074bf4*)menu->resetState);
        ResetEntryList0205d6a0((struct Entry_0205d6a0*)menu->window, 1);
        ClearBuffers0204b010OverList0x98((struct Cont0205d1e0*)menu->window);
        CallFunc0204b04cOverList0x98((struct Cont0205d274*)menu->window);
        InitEntries0205d2bc((struct Obj0205d2bc*)menu->window);
    } else {
        ClearFlag0x10IfSet((struct Struct02074bd0*)menu->resetState);
        ClearBuffers0204b010OverList0x98((struct Cont0205d1e0*)menu->window);
        CallFunc0204b04cOverList0x98((struct Cont0205d274*)menu->window);
        InitEntries0205d2bc((struct Obj0205d2bc*)menu->window);
        func_0205d048(menu->window);

        if (menu->canvasPixels) {
            memset(menu->canvasPixels, 0, 0x20);
            CleanInvalidateCacheRange(menu->canvasPixels, 0x20);
            LoadToMainBG1CharacterData(menu->canvasPixels, 0, 0x20);
        }

        DISPCNT = (DISPCNT & ~0x1f00) | (menu->savedDisplayLayers << 8);
    }

    if (menu->textAllocator.GetSignedAllocator()) {
        menu->textAllocator.Destroy();
    }
    if (menu->allocator.GetSignedAllocator()) {
        menu->allocator.Destroy();
    }

    menu->state = 6;
}
