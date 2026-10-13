#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"
#include "System/OverlayId.h"

struct Pair0209a338;
struct Ctx0209a470;
struct StreamHeader;
struct IntField0x60_0209ff64;
struct TaskState0209ff6c;
struct Obj0209fee4;
struct List020727d8;
struct FlagWord020466f4;
struct Struct0205de24;

int GetWord0x0(int* obj);
extern "C" void func_020a1940(unsigned int id);
extern "C" void func_ov002_021682c0(char* self);
void SetSubBrightness(GameResources* resources, int brightness, int duration);
extern "C" void* _Z27GetDataPtr02114e04_020d6c00v(void);
void OrBitsIntoField0(unsigned int* p, unsigned int mask);
void OrGlobalFlag0x40(void);
extern "C" void _Z26ClearFirstTwoWords0209a338P12Pair0209a338(Pair0209a338* p);
extern "C" void _Z33SetupAndRunBufferedScript0209a470P11Ctx0209a470P13SafeAllocatorP12StreamHeaderi(Ctx0209a470* ctx, SafeAllocator* alloc, StreamHeader* data, int length);
int IsSubBrightnessTransitionActive(GameResources* resources);
extern "C" int func_ov013_021870f0(char* obj);
extern "C" void func_ov013_02184360(char* obj, int v);
extern "C" void func_ov013_02184cf0(char* obj, SafeAllocator* alloc);
extern "C" int _Z29GetField110ArrayValue021574d4Pvi(void* self, int index);
GameObject* GetCombatantWithFlag0x100(GameState* gameState, int combatantId);
extern "C" void func_ov013_02184b4c(char* obj, GameObject* combatant);
extern "C" void func_ov002_02168354(char* self);
extern "C" void func_ov013_0218782c(char* obj, int a, int b);
extern "C" void _Z32HandleFieldFlagsAndState021870c0Pv(void* obj);
extern "C" void func_ov002_021685bc(char* self);
extern "C" void _Z31UpdateBattleTagCounter_0216885cPc(char* self);
extern "C" int _Z26GetGlobalField0x1c020421a0v(void);
int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);
int CheckByteSetAndByteClear(unsigned char* obj);
extern "C" void _Z24ReinitController02043204Pc(char* obj);
extern "C" void func_02043124(void* self);
void PushInputLogB(int id);
extern "C" void _Z13Reset0209fe9cPc(char* obj);
extern "C" void _Z37InitManagerAndAllocateBuffers0209fee4P11Obj0209fee4P13SafeAllocatorii(Obj0209fee4* obj, SafeAllocator* alloc, int data, int length);
void SetIntAt0x60(IntField0x60_0209ff64* obj, int v);
extern "C" void _Z21PollOv017Task0209ff6cP17TaskState0209ff6c(TaskState0209ff6c* task);
extern "C" int _Z35AreFields60And64BothNegOne_02168c00Ph(unsigned char* obj);
extern "C" void func_ov013_02186fa0(char* obj);
extern "C" void func_ov002_021688f8(char* self);
extern "C" void _Z23ResetListHeader020727ecP12List020727d8(List020727d8* list);
extern "C" void _Z18Zero4Bytes020e5280Pv(void* obj);
extern "C" void func_ov023_021eb138(char* obj, int v);
extern "C" void func_ov023_021eb080(char* obj, SafeAllocator* alloc);
extern "C" void func_ov023_021eb564(char* obj, int a, int b);
extern "C" void func_ov023_021eb26c(void* obj);
extern "C" void ColorEffect_ConfigureAlphaBlend(int control, unsigned int pixel1Source, unsigned int pixel2Source, unsigned int pixel1Alpha, unsigned int pixel2Alpha);
extern "C" void _Z18ClearFlags020466f4P16FlagWord020466f4j(FlagWord020466f4* word, unsigned int mask);
void PopStack1AndTrigger(int flag);
extern "C" void _Z29SetCombatModeFromCase020dc2d0i(int mode);
extern "C" void func_ov002_0215a938(char* self);
extern "C" void func_ov002_02161cf0(char* base);
extern "C" void _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh(Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);
extern "C" void func_ov002_02160274(char* self);

extern char data_ov002_0216d350;
extern char data_ov002_0216d368;
extern unsigned short data_02114e30;
extern unsigned char data_02114e54;

// USA: func_ov002_02168d54
extern "C" ARM void func_ov002_02168d54(char* self) {
    GameState* gs = GameState::GetInstance();
    GameResources* res = (GameResources*)GetWord0x0((int*)gs);
    BackgroundLoader* loader = BackgroundLoader::GetInstance();

    if (*(int*)(self + 0x1bc0) == 0) {
        self[0x2456] = 1;
        func_020a1940(OVERLAY_ID(13));
        func_ov002_021682c0(self);
        SetSubBrightness(res, -0x10, 0xf);
        *(int*)(self + 0x2458) = loader->QueueLoadFile(&data_ov002_0216d350, NULL);
        OrBitsIntoField0((unsigned int*)_Z27GetDataPtr02114e04_020d6c00v(), 1);
        OrGlobalFlag0x40();
    } else if (*(int*)(self + 0x1bc0) == 1) {
        if (*(int*)(self + 0x2458) >= 0) {
            if (loader->GetTaskStatus(*(int*)(self + 0x2458)) != 0) {
                void* data;
                unsigned int length;
                loader->GetLoadedFileByID(*(int*)(self + 0x2458), &data, &length);
                _Z26ClearFirstTwoWords0209a338P12Pair0209a338((Pair0209a338*)(self + 0x243c));
                _Z33SetupAndRunBufferedScript0209a470P11Ctx0209a470P13SafeAllocatorP12StreamHeaderi((Ctx0209a470*)(self + 0x243c), (SafeAllocator*)(self + 0x850), (StreamHeader*)data, length);
                loader->RemoveTask(*(int*)(self + 0x2458));
                *(int*)(self + 0x2458) = -1;
            }
        } else if (!IsSubBrightnessTransitionActive(res)) {
            (*(int*)(self + 0x1bc0))++;
        }
    } else if (*(int*)(self + 0x1bc0) == 2) {
        if (func_ov013_021870f0(self + 0x1d04)) {
            (*(int*)(self + 0x1bc0))++;
        }
    } else if (*(int*)(self + 0x1bc0) == 3) {
        SetSubBrightness(res, 0, 0xf);
        (*(int*)(self + 0x1bc0))++;
    } else if (*(int*)(self + 0x1bc0) == 4) {
        if (!IsSubBrightnessTransitionActive(res)) {
            ((SafeAllocator*)(self + 0x828))->Reset();
            func_ov013_02184360(self + 0x1d70, 0);
            func_ov013_02184cf0(self + 0x1d70, (SafeAllocator*)(self + 0x828));
            *(int*)(self + 0x1d88) = *(int*)(self + 0x1a68);
            *(short*)(self + 0x1d8c) = 0;
            GameObject* combatant = GetCombatantWithFlag0x100(gs, _Z29GetField110ArrayValue021574d4Pvi(self, *(short*)(self + 0x1c08)));
            if (combatant) {
                func_ov013_02184b4c(self + 0x1d70, combatant);
            }
            (*(int*)(self + 0x1bc0))++;
        }
    } else if (*(int*)(self + 0x1bc0) == 5) {
        func_ov002_02168354(self);
        int variant = *(int*)(self + 0x23cc);
        int value = _Z29GetField110ArrayValue021574d4Pvi(self, *(short*)(self + 0x1c08));
        func_ov013_0218782c(self + 0x1d04, (signed char)value, (unsigned char)variant);
        _Z32HandleFieldFlagsAndState021870c0Pv(self + 0x1d04);
    } else if (*(int*)(self + 0x1bc0) == 6) {
        _Z32HandleFieldFlagsAndState021870c0Pv(self + 0x1d04);
        func_ov002_021685bc(self);
    } else if (*(int*)(self + 0x1bc0) == 7) {
        _Z32HandleFieldFlagsAndState021870c0Pv(self + 0x1d04);
        _Z31UpdateBattleTagCounter_0216885cPc(self);
    } else if (*(int*)(self + 0x1bc0) == 8) {
        _Z32HandleFieldFlagsAndState021870c0Pv(self + 0x1d04);
        char* controller = (char*)_Z26GetGlobalField0x1c020421a0v();
        if (*(int*)(controller + 0x998) != 0) {
            controller[0x19ae] = 0;
            if (*(int*)(controller + 0x9a0) != 3) {
                return;
            }
            if (!TestFlag0SetAndFlag1Clear(&data_02114e30, 0x203) && !CheckByteSetAndByteClear(&data_02114e54)) {
                return;
            }
        }
        _Z24ReinitController02043204Pc(controller);
        func_02043124(controller);
        FontBankLoader* global = GetGlobal02109400();
        BlankFunction02094b3c(global, 0xc);
        func_02094ab0(global);
        self[0x2454] = 0;
        self[0x2455] = 0;
        (*(int*)(self + 0x1bc0))++;
        SetSubBrightness(res, -0x10, 0xf);
        self[0x2456] = 0;
        PushInputLogB(1);
        self[0x2472] = 1;
        self[0x1c33] = 1;
        self[0x248f] = 1;
        *(int*)(self + 0x2458) = loader->QueueLoadFile(&data_ov002_0216d368, NULL);
    } else if (*(int*)(self + 0x1bc0) == 9) {
        _Z32HandleFieldFlagsAndState021870c0Pv(self + 0x1d04);
        if (loader->GetTaskStatus(*(int*)(self + 0x2458)) != 0) {
            void* data;
            unsigned int length;
            loader->GetLoadedFileByID(*(int*)(self + 0x2458), &data, &length);
            ((SafeAllocator*)(self + 0x828))->Reset();
            *(char**)(self + 0x2460) = (char*)((SafeAllocator*)(self + 0x828))->Allocate(0xd0);
            _Z13Reset0209fe9cPc(*(char**)(self + 0x2460));
            _Z37InitManagerAndAllocateBuffers0209fee4P11Obj0209fee4P13SafeAllocatorii(*(Obj0209fee4**)(self + 0x2460), (SafeAllocator*)(self + 0x828), (int)data, length);
            loader->RemoveTask(*(int*)(self + 0x2458));
            *(int*)(self + 0x2458) = -1;
            SetIntAt0x60(*(IntField0x60_0209ff64**)(self + 0x2460), 100);
            do {
                _Z21PollOv017Task0209ff6cP17TaskState0209ff6c(*(TaskState0209ff6c**)(self + 0x2460));
            } while (!_Z35AreFields60And64BothNegOne_02168c00Ph(*(unsigned char**)(self + 0x2460)));
            (*(int*)(self + 0x1bc0))++;
        }
    } else if (*(int*)(self + 0x1bc0) == 0xa) {
        _Z32HandleFieldFlagsAndState021870c0Pv(self + 0x1d04);
        if (!IsSubBrightnessTransitionActive(res)) {
            func_ov013_02186fa0(self + 0x1d04);
            ((SafeAllocator*)(self + 0x850))->Reset();
            (*(int*)(self + 0x1bc0))++;
        }
    } else if (*(int*)(self + 0x1bc0) == 0xb) {
        func_ov002_021688f8(self);
    } else if (*(int*)(self + 0x1bc0) == 0xc) {
        if (*(List020727d8**)(self + 0x2448) != NULL) {
            _Z23ResetListHeader020727ecP12List020727d8(*(List020727d8**)(self + 0x2448));
        }
        *(void**)(self + 0x2448) = NULL;
        if (*(void**)(self + 0x244c) != NULL) {
            _Z18Zero4Bytes020e5280Pv(*(void**)(self + 0x244c));
        }
        *(void**)(self + 0x244c) = NULL;
        ((SafeAllocator*)(self + 0x864))->Reset();
        *(char**)(self + 0x2468) = (char*)((SafeAllocator*)(self + 0x864))->Allocate(0x44c);
        func_ov023_021eb138(*(char**)(self + 0x2468), 7);
        func_ov023_021eb080(*(char**)(self + 0x2468), (SafeAllocator*)(self + 0x864));
        func_ov023_021eb564(*(char**)(self + 0x2468), *(int*)(self + 0x246c), *(unsigned char*)(self + 0x2470));
        char* menu = *(char**)(self + 0x2468);
        if (*(unsigned char*)(self + 0x2471) != 0) {
            *(unsigned short*)(menu + 0x438) |= 0x400;
        } else {
            *(unsigned short*)(menu + 0x438) &= ~0x400;
        }
        (*(int*)(self + 0x1bc0))++;
    } else if (*(int*)(self + 0x1bc0) == 0xd) {
        if (*(unsigned short*)(*(char**)(self + 0x2468) + 0x438) & 4) {
            (*(int*)(self + 0x1bc0))++;
        }
    } else if (*(int*)(self + 0x1bc0) == 0xe) {
        self[0x2472] = 0;
        func_ov023_021eb26c(*(void**)(self + 0x2468));
        ((SafeAllocator*)(self + 0x828))->Reset();
        ((SafeAllocator*)(self + 0x864))->Reset();
        *(void**)(self + 0x2468) = NULL;
        *(int*)(self + 0x246c) = 0;
        self[0x2470] = 0;
        self[0x2471] = 0;
        (*(int*)(self + 0x1bc0))++;
    } else if (*(int*)(self + 0x1bc0) == 0xf) {
        FontBankLoader* global = GetGlobal02109400();
        BlankFunction02094b40(global);
        BlankFunction02094b30(global, 100, 0);
        (*(int*)(self + 0x1bc0))++;
    } else if (*(int*)(self + 0x1bc0) == 0x10) {
        if (AlwaysTrue02094b4c(GetGlobal02109400())) {
            *(int*)(self + 0x1bc0) = 100;
            ColorEffect_ConfigureAlphaBlend(0x04000050, 2, 1, 10, 6);
        }
    } else if (*(int*)(self + 0x1bc0) == 100) {
        _Z18ClearFlags020466f4P16FlagWord020466f4j((FlagWord020466f4*)_Z27GetDataPtr02114e04_020d6c00v(), 1);
        PopStack1AndTrigger(1);
        self[0x1c33] = 0;
        self[0x248f] = 0;
        _Z29SetCombatModeFromCase020dc2d0i(0);
        *(int*)(self + 0x247c) |= 2;
        self[0x247a] = 0;
        (*(int*)(self + 0x1bc0))++;
    } else if (*(int*)(self + 0x1bc0) == 101) {
        if (!(*(int*)(self + 0x247c) & 2)) {
            (*(int*)(self + 0x1bc0))++;
        }
    } else if (*(int*)(self + 0x1bc0) == 102) {
        (*(int*)(self + 0x1bc0))++;
    } else if (*(int*)(self + 0x1bc0) == 103) {
        func_ov002_0215a938(self);
        *(int*)(self + 0x1bb8) = 0x1f;
        func_ov002_02161cf0(self);
        _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh((Struct0205de24*)(self + 0xec8), 0, 2);
        func_ov002_02160274(self);
    }
}
