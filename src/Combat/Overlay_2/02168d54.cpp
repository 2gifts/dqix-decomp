#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"
#include "System/OverlayId.h"

#if defined(jpn)
#define REGION_VALUE(j, u) (j)
#define func_ov002_021682c0 func_ov002_02168d54
#define func_ov002_02168354 func_ov002_02168de4
#define func_ov002_021685bc func_ov002_02168ff4
#define _Z31UpdateBattleTagCounter_0216885cPc func_ov002_02169140
#define func_ov002_0215a938 func_ov002_0215bd28
#define func_ov002_02161cf0 func_ov002_02162acc
#define func_ov002_02160274 func_ov002_02161228
#define data_ov002_0216d350 data_ov002_0216dacf
#define data_ov002_0216d368 data_ov002_0216dae7
#else
#define REGION_VALUE(j, u) (u)
#endif

struct Pair0209a338;
struct Ctx0209a470;
struct StreamHeader;
struct IntField0x60_0209ff64;
struct TaskState0209ff6c;
struct Obj0209fee4;
struct List020727d8;
struct FlagWord020466f4;
struct Struct0205de24;

int GetWord0x0_0200fb8c(int* obj);
extern "C" void func_020a1940(unsigned int id);
extern "C" void func_ov002_021682c0(char* self);
void SetSubBrightness(GameResources* resources, int brightness, int duration);
void* GetDataPtr02114e04_020d6c00(void);
void OrBitsIntoField0_020466e4(unsigned int* p, unsigned int mask);
void OrGlobalFlag0x40_020dc2bc(void);
void ClearFirstTwoWords0209a338(Pair0209a338* p);
void SetupAndRunBufferedScript0209a470(Ctx0209a470* ctx, SafeAllocator* alloc, StreamHeader* data, int length);
int IsSubBrightnessTransitionActive(GameResources* resources);
extern "C" int func_ov013_021870f0(char* obj);
extern "C" void func_ov013_02184360(char* obj, int v);
extern "C" void func_ov013_02184cf0(char* obj, SafeAllocator* alloc);
int GetField110ArrayValue021574d4(void* self, int index);
GameObject* GetCombatantWithFlag0x100_0200ff1c(GameState* gameState, int combatantId);
extern "C" void func_ov013_02184b4c(char* obj, GameObject* combatant);
extern "C" void func_ov002_02168354(char* self);
extern "C" void func_ov013_0218782c(char* obj, int a, int b);
void HandleFieldFlagsAndState021870c0(void* obj);
extern "C" void func_ov002_021685bc(char* self);
extern "C" void _Z31UpdateBattleTagCounter_0216885cPc(char* self);
int GetGlobalField0x1c020421a0(void);
int TestFlag0SetAndFlag1Clear_02012444(unsigned short* obj, int mask);
int CheckByteSetAndByteClear_02012aac(unsigned char* obj);
void ReinitController02043204(char* obj);
extern "C" void func_02043124(void* self);
void PushInputLogB_020a1ef0(int id);
void Reset0209fe9c(char* obj);
void InitManagerAndAllocateBuffers0209fee4(Obj0209fee4* obj, SafeAllocator* alloc, int data, int length);
void SetIntAt0x60(IntField0x60_0209ff64* obj, int v);
void PollOv017Task0209ff6c(TaskState0209ff6c* task);
int AreFields60And64BothNegOne_02168c00(unsigned char* obj);
extern "C" void func_ov013_02186fa0(char* obj);
extern "C" void func_ov002_021688f8(char* self);
void ResetListHeader020727ec(List020727d8* list);
void Zero4Bytes020e5280(void* obj);
extern "C" void func_ov023_021eb138(char* obj, int v);
extern "C" void func_ov023_021eb080(char* obj, SafeAllocator* alloc);
extern "C" void func_ov023_021eb564(char* obj, int a, int b);
extern "C" void func_ov023_021eb26c(void* obj);
extern "C" void ColorEffect_ConfigureAlphaBlend(int control, unsigned int pixel1Source, unsigned int pixel2Source, unsigned int pixel1Alpha, unsigned int pixel2Alpha);
void ClearFlags020466f4(FlagWord020466f4* word, unsigned int mask);
void PopStack1AndTrigger_020a1f4c(int flag);
void SetCombatModeFromCase020dc2d0(int mode);
extern "C" void func_ov002_0215a938(char* self);
extern "C" void func_ov002_02161cf0(char* base);
void FindAndLinkMatchingEntry0205de24(Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);
extern "C" void func_ov002_02160274(char* self);

extern char data_ov002_0216d350;
extern char data_ov002_0216d368;
extern unsigned short data_02114e30;
extern unsigned char data_02114e54;

// USA: func_ov002_02168d54; JPN: func_ov002_021695d8
#if defined(jpn)
extern "C" ARM void func_ov002_021695d8(char* self) {
#else
extern "C" ARM void func_ov002_02168d54(char* self) {
#endif
    GameState* gs = GameState::GetInstance();
    GameResources* res = (GameResources*)GetWord0x0_0200fb8c((int*)gs);
    BackgroundLoader* loader = BackgroundLoader::GetInstance();

    if (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)) == 0) {
        self[REGION_VALUE(0x228a, 0x2456)] = 1;
        func_020a1940(OVERLAY_ID(13));
        func_ov002_021682c0(self);
        SetSubBrightness(res, -0x10, 0xf);
        *(int*)(self + REGION_VALUE(0x228c, 0x2458)) = loader->QueueLoadFile(&data_ov002_0216d350, NULL);
#if !defined(jpn)
        OrBitsIntoField0_020466e4((unsigned int*)GetDataPtr02114e04_020d6c00(), 1);
        OrGlobalFlag0x40_020dc2bc();
#endif
    } else if (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)) == 1) {
        if (*(int*)(self + REGION_VALUE(0x228c, 0x2458)) >= 0) {
            if (loader->GetTaskStatus(*(int*)(self + REGION_VALUE(0x228c, 0x2458))) != 0) {
                void* data;
                unsigned int length;
                loader->GetLoadedFileByID(*(int*)(self + REGION_VALUE(0x228c, 0x2458)), &data, &length);
                ClearFirstTwoWords0209a338((Pair0209a338*)(self + REGION_VALUE(0x2274, 0x243c)));
                SetupAndRunBufferedScript0209a470((Ctx0209a470*)(self + REGION_VALUE(0x2274, 0x243c)), (SafeAllocator*)(self + REGION_VALUE(0x7b4, 0x850)), (StreamHeader*)data, length);
                loader->RemoveTask(*(int*)(self + REGION_VALUE(0x228c, 0x2458)));
                *(int*)(self + REGION_VALUE(0x228c, 0x2458)) = -1;
            }
        } else if (!IsSubBrightnessTransitionActive(res)) {
#if defined(jpn)
            OrBitsIntoField0_020466e4((unsigned int*)GetDataPtr02114e04_020d6c00(), 1);
            OrGlobalFlag0x40_020dc2bc();
#endif
            (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)))++;
        }
    } else if (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)) == 2) {
        if (func_ov013_021870f0(self + REGION_VALUE(0x1bc8, 0x1d04))) {
            (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)))++;
        }
    } else if (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)) == 3) {
        SetSubBrightness(res, 0, 0xf);
        (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)))++;
    } else if (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)) == 4) {
        if (!IsSubBrightnessTransitionActive(res)) {
            ((SafeAllocator*)(self + REGION_VALUE(0x78c, 0x828)))->Reset();
            func_ov013_02184360(self + REGION_VALUE(0x1c20, 0x1d70), 0);
            func_ov013_02184cf0(self + REGION_VALUE(0x1c20, 0x1d70), (SafeAllocator*)(self + REGION_VALUE(0x78c, 0x828)));
            *(int*)(self + REGION_VALUE(0x1c38, 0x1d88)) = *(int*)(self + REGION_VALUE(0x19c0, 0x1a68));
            *(short*)(self + REGION_VALUE(0x1c3c, 0x1d8c)) = 0;
            GameObject* combatant = GetCombatantWithFlag0x100_0200ff1c(gs, GetField110ArrayValue021574d4(self, *(short*)(self + REGION_VALUE(0x1ad0, 0x1c08))));
            if (combatant) {
                func_ov013_02184b4c(self + REGION_VALUE(0x1c20, 0x1d70), combatant);
            }
            (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)))++;
        }
    } else if (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)) == 5) {
        func_ov002_02168354(self);
#if !defined(jpn)
        int variant = *(int*)(self + 0x23cc);
        int value = GetField110ArrayValue021574d4(self, *(short*)(self + REGION_VALUE(0x1ad0, 0x1c08)));
        func_ov013_0218782c(self + REGION_VALUE(0x1bc8, 0x1d04), (signed char)value, (unsigned char)variant);
        HandleFieldFlagsAndState021870c0(self + REGION_VALUE(0x1bc8, 0x1d04));
#endif
    } else if (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)) == 6) {
#if !defined(jpn)
        HandleFieldFlagsAndState021870c0(self + REGION_VALUE(0x1bc8, 0x1d04));
#endif
        func_ov002_021685bc(self);
    } else if (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)) == 7) {
#if !defined(jpn)
        HandleFieldFlagsAndState021870c0(self + REGION_VALUE(0x1bc8, 0x1d04));
#endif
        _Z31UpdateBattleTagCounter_0216885cPc(self);
    } else if (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)) == 8) {
#if !defined(jpn)
        HandleFieldFlagsAndState021870c0(self + REGION_VALUE(0x1bc8, 0x1d04));
#endif
        char* controller = (char*)GetGlobalField0x1c020421a0();
        if (*(int*)(controller + REGION_VALUE(0x868, 0x998)) != 0) {
            controller[REGION_VALUE(0x17de, 0x19ae)] = 0;
            if (*(int*)(controller + REGION_VALUE(0x870, 0x9a0)) != 3) {
                return;
            }
            if (!TestFlag0SetAndFlag1Clear_02012444(&data_02114e30, 0x203) && !CheckByteSetAndByteClear_02012aac(&data_02114e54)) {
                return;
            }
        }
        ReinitController02043204(controller);
        func_02043124(controller);
        FontBankLoader* global = GetGlobal02109400_02094a00();
        BlankFunction02094b3c(global, 0xc);
        func_02094ab0(global);
        self[REGION_VALUE(0x2288, 0x2454)] = 0;
        self[REGION_VALUE(0x2289, 0x2455)] = 0;
        (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)))++;
        SetSubBrightness(res, -0x10, 0xf);
        self[REGION_VALUE(0x228a, 0x2456)] = 0;
        PushInputLogB_020a1ef0(1);
        self[REGION_VALUE(0x22a2, 0x2472)] = 1;
        self[REGION_VALUE(0x1afb, 0x1c33)] = 1;
        self[REGION_VALUE(0x22bf, 0x248f)] = 1;
        *(int*)(self + REGION_VALUE(0x228c, 0x2458)) = loader->QueueLoadFile(&data_ov002_0216d368, NULL);
    } else if (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)) == 9) {
#if !defined(jpn)
        HandleFieldFlagsAndState021870c0(self + REGION_VALUE(0x1bc8, 0x1d04));
#endif
        if (loader->GetTaskStatus(*(int*)(self + REGION_VALUE(0x228c, 0x2458))) != 0) {
            void* data;
            unsigned int length;
            loader->GetLoadedFileByID(*(int*)(self + REGION_VALUE(0x228c, 0x2458)), &data, &length);
            ((SafeAllocator*)(self + REGION_VALUE(0x78c, 0x828)))->Reset();
            *(char**)(self + REGION_VALUE(0x2290, 0x2460)) = (char*)((SafeAllocator*)(self + REGION_VALUE(0x78c, 0x828)))->Allocate(0xd0);
            Reset0209fe9c(*(char**)(self + REGION_VALUE(0x2290, 0x2460)));
            InitManagerAndAllocateBuffers0209fee4(*(Obj0209fee4**)(self + REGION_VALUE(0x2290, 0x2460)), (SafeAllocator*)(self + REGION_VALUE(0x78c, 0x828)), (int)data, length);
            loader->RemoveTask(*(int*)(self + REGION_VALUE(0x228c, 0x2458)));
            *(int*)(self + REGION_VALUE(0x228c, 0x2458)) = -1;
            SetIntAt0x60(*(IntField0x60_0209ff64**)(self + REGION_VALUE(0x2290, 0x2460)), 100);
            do {
                PollOv017Task0209ff6c(*(TaskState0209ff6c**)(self + REGION_VALUE(0x2290, 0x2460)));
            } while (!AreFields60And64BothNegOne_02168c00(*(unsigned char**)(self + REGION_VALUE(0x2290, 0x2460))));
            (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)))++;
        }
    } else if (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)) == 0xa) {
#if !defined(jpn)
        HandleFieldFlagsAndState021870c0(self + REGION_VALUE(0x1bc8, 0x1d04));
#endif
        if (!IsSubBrightnessTransitionActive(res)) {
            func_ov013_02186fa0(self + REGION_VALUE(0x1bc8, 0x1d04));
            ((SafeAllocator*)(self + REGION_VALUE(0x7b4, 0x850)))->Reset();
            (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)))++;
        }
    } else if (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)) == 0xb) {
        func_ov002_021688f8(self);
    } else if (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)) == 0xc) {
#if !defined(jpn)
        if (*(List020727d8**)(self + 0x2448) != NULL) {
            ResetListHeader020727ec(*(List020727d8**)(self + 0x2448));
        }
        *(void**)(self + 0x2448) = NULL;
        if (*(void**)(self + 0x244c) != NULL) {
            Zero4Bytes020e5280(*(void**)(self + 0x244c));
        }
        *(void**)(self + 0x244c) = NULL;
#endif
        ((SafeAllocator*)(self + REGION_VALUE(0x7c8, 0x864)))->Reset();
        *(char**)(self + REGION_VALUE(0x2298, 0x2468)) = (char*)((SafeAllocator*)(self + REGION_VALUE(0x7c8, 0x864)))->Allocate(0x44c);
        func_ov023_021eb138(*(char**)(self + REGION_VALUE(0x2298, 0x2468)), 7);
        func_ov023_021eb080(*(char**)(self + REGION_VALUE(0x2298, 0x2468)), (SafeAllocator*)(self + REGION_VALUE(0x7c8, 0x864)));
        func_ov023_021eb564(*(char**)(self + REGION_VALUE(0x2298, 0x2468)), *(int*)(self + REGION_VALUE(0x229c, 0x246c)), *(unsigned char*)(self + REGION_VALUE(0x22a0, 0x2470)));
        char* menu = *(char**)(self + REGION_VALUE(0x2298, 0x2468));
        if (*(unsigned char*)(self + REGION_VALUE(0x22a1, 0x2471)) != 0) {
            *(unsigned short*)(menu + 0x438) |= 0x400;
        } else {
            *(unsigned short*)(menu + 0x438) &= ~0x400;
        }
        (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)))++;
    } else if (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)) == 0xd) {
        if (*(unsigned short*)(*(char**)(self + REGION_VALUE(0x2298, 0x2468)) + 0x438) & 4) {
            (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)))++;
        }
    } else if (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)) == 0xe) {
        self[REGION_VALUE(0x22a2, 0x2472)] = 0;
        func_ov023_021eb26c(*(void**)(self + REGION_VALUE(0x2298, 0x2468)));
        ((SafeAllocator*)(self + REGION_VALUE(0x78c, 0x828)))->Reset();
        ((SafeAllocator*)(self + REGION_VALUE(0x7c8, 0x864)))->Reset();
        *(void**)(self + REGION_VALUE(0x2298, 0x2468)) = NULL;
        *(int*)(self + REGION_VALUE(0x229c, 0x246c)) = 0;
        self[REGION_VALUE(0x22a0, 0x2470)] = 0;
        self[REGION_VALUE(0x22a1, 0x2471)] = 0;
        (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)))++;
    } else if (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)) == 0xf) {
        FontBankLoader* global = GetGlobal02109400_02094a00();
        BlankFunction02094b40(global);
        BlankFunction02094b30(global, 100, 0);
        (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)))++;
    } else if (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)) == 0x10) {
        if (AlwaysTrue02094b4c(GetGlobal02109400_02094a00())) {
            *(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)) = 100;
            ColorEffect_ConfigureAlphaBlend(0x04000050, 2, 1, 10, 6);
        }
    } else if (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)) == 100) {
        ClearFlags020466f4((FlagWord020466f4*)GetDataPtr02114e04_020d6c00(), 1);
        PopStack1AndTrigger_020a1f4c(1);
        self[REGION_VALUE(0x1afb, 0x1c33)] = 0;
        self[REGION_VALUE(0x22bf, 0x248f)] = 0;
        SetCombatModeFromCase020dc2d0(0);
        *(int*)(self + REGION_VALUE(0x22ac, 0x247c)) |= 2;
        self[REGION_VALUE(0x22aa, 0x247a)] = 0;
        (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)))++;
    } else if (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)) == 101) {
        if (!(*(int*)(self + REGION_VALUE(0x22ac, 0x247c)) & 2)) {
            (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)))++;
        }
    } else if (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)) == 102) {
        (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)))++;
    } else if (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)) == 103) {
        func_ov002_0215a938(self);
        *(int*)(self + REGION_VALUE(0x1a80, 0x1bb8)) = REGION_VALUE(0x20, 0x1f);
        func_ov002_02161cf0(self);
        FindAndLinkMatchingEntry0205de24((Struct0205de24*)(self + REGION_VALUE(0xe20, 0xec8)), 0, 2);
        func_ov002_02160274(self);
    }
}
