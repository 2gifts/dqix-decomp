// JPN: func_ov017_021ac40c
#include <globaldefs.h>

#if defined(jpn)
enum { kContextPointerOffset = 0x148 };
#else
enum { kContextPointerOffset = 0x154 };
#endif

#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"
#include "System/OverlayId.h"
#include "World/Object3D.h"

struct Obj020397cc;
struct ListHead02046b60;
struct Foo0207df50;
struct Base02010834;
struct S021b2ba0;
struct S021b2bf4;
struct S021b2c0c;
struct S021b2bdc;
struct TailList020469b4;
struct TailNode020469b4;

struct ObjParams02078484 {
    unsigned char f00;
    unsigned char pad01[0xf];
    unsigned char f10;
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char b4 : 1;
    unsigned char b5 : 1;
    unsigned char b6 : 1;
    unsigned char b7 : 1;
    short f12;
    short f14;
    short f16;
    short f18;
    short f1a;
    short f1c;
    short pad1e;
    int f20;
    int f24;
    int f28;
    Vector3i position;
    int f38;
    int f3c;
    int f40;
    Vector3i scale;
};

struct Loader021abba8 {
    char pad0;
    unsigned char done;
    char pad2[6];
    unsigned char state;
    char pad9;
    short timer;
    unsigned char active;
    unsigned char members;
    char padE[2];
    SafeAllocator allocator;
    int task;
};

extern "C" void* func_0202ae18(void);
extern "C" void* func_02057924(void);
extern "C" void _Z27CancelPendingAction020397ccP11Obj020397cci(Obj020397cc* obj, int arg1);
int ListContainsId(ListHead02046b60* list, int id);
extern "C" void func_ov017_021ac2a8(void* obj);
extern "C" void func_02046a8c(void* list, void* node);
int IsField0Null(void** obj);
void SetBitsInWord(unsigned int* obj, unsigned int mask);
int GetGlobal02109400(void);
extern "C" void func_02094ab0(int g);
extern "C" void func_020a0cc4(unsigned int size);
void* AllocateAligned4(AllocatorUnion* alloc, unsigned int size);
extern "C" void _Z26CopyInternalFields0207df50P11Foo0207df50(Foo0207df50* p);
extern "C" int func_02057e6c(void* mgr, int id, SafeAllocator* alloc, void* data, unsigned int length, Foo0207df50* fields);
extern "C" void _Z34CopyCountedBytesToIntArray02010834P12Base02010834iPiS1_(Base02010834* base, int index, int* out, int* outCount);
extern "C" int func_0202c508(void* p);
extern "C" void _ZN8Vector3iaSERKS_(Vector3i* dst, const Vector3i& src);
extern "C" void _Z26FindNodeAndProcess02057fb4Pvii(void* list, int id, int params);
extern "C" void _Z26SetForwardAndStore0205ebc0Pvii(void* obj, int arg1, int arg2);
extern "C" void _Z34DispatchIfField0xc4NonNeg_0205ebfcPvii(void* obj, int a, int b);
void SetBrightness(GameResources* resources, int brightness, int duration);
int IsBrightnessTransitionActive(GameResources* resources);
void ClearBitsInWord(unsigned int* obj, unsigned int mask);
extern "C" void _Z27CallListIfFlagsSet_02197528v(void);
void SetByteField0x253(void* obj);
extern "C" void _Z25ForwardField0xc0_0205ebecPv(void* obj);
extern "C" void* func_0205ec34(void);
void SetOrClearBitInArray(void* unused, unsigned char* array, int bit, int value);
int CheckBitsInField0x63dc(void* obj, int mask);
extern "C" void _Z21InitObjState_021b2174Ph(unsigned char* obj);
extern "C" void _Z23SetNameChecked_021b2ba0P9S021b2ba0Pc(S021b2ba0* obj, char* name);
extern "C" void _Z25SetFields30And34_021b2bd0Pvii(void* obj, int a, int b);
extern "C" void _Z16SetBit4_021b2bf4P9S021b2bf4j(S021b2bf4* obj, unsigned int v);
extern "C" void _Z16SetBit5_021b2c0cP9S021b2c0cj(S021b2c0c* obj, unsigned int v);
extern "C" void _Z16SetBit3_021b2bdcP9S021b2bdcj(S021b2bdc* obj, unsigned int v);
void AppendNodeToTail(TailList020469b4* list, TailNode020469b4* node);
extern "C" void _Z29AllocateAndCopyBuf20_021689d8P13SafeAllocatorPv(SafeAllocator* a, void* target);

extern char data_ov017_021d78da;
extern char data_ov017_021d78f1;
extern char data_02108760;
extern AllocatorUnion data_02114e20;

// USA: func_ov017_021abba8
extern "C" ARM void func_ov017_021abba8(Loader021abba8* self, ListHead02046b60* list) {
    GameState* gs = GameState::GetInstance();
    void* search = func_0202ae18();
    GameResources* res = func_ov017_0218b5b0();
    GameObject* leader = gs->GetUnknownGameObject();
    void* mgr = func_02057924();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    int delta = gs->GetTickCount();

    if (self->state == 0) {
        _Z27CancelPendingAction020397ccP11Obj020397cci((Obj020397cc*)leader, 1);
        if (ListContainsId(list, 0x4e)) {
            self->done = 1;
            func_ov017_021ac2a8(self);
            if (ListContainsId(list, 3)) {
                func_02046a8c(list, res->unknown_ptr_array_36fc[4]);
            }
        } else if (IsField0Null((void**)res->unknown_ptr_array_36fc[1])) {
            SetBitsInWord((unsigned int*)res, 0x10);
            func_02094ab0(GetGlobal02109400());
            func_020a0cc4(0x2800);
            self->task = loader->QueueLoadFile(&data_ov017_021d78da, NULL);
            self->state++;
        }
    } else if (self->state == 1) {
        if (loader->GetTaskStatus(self->task) != 0) {
            if (loader->GetDetailedTaskStatus(self->task) != 2) {
                loader->RemoveTask(self->task);
                self->done = 1;
            }
            unsigned int length;
            void* data;
            loader->GetLoadedFileByID(self->task, &data, &length);
            self->allocator.CreateTypeA(AllocateAligned4(&data_02114e20, 0x2800), 0x2800);
            self->allocator.Reset();
            Foo0207df50* fields = (Foo0207df50*)(*(char**)((char*)gs->GetUnknownGameObject() + kContextPointerOffset) + 0x568);
            _Z26CopyInternalFields0207df50P11Foo0207df50(fields);
            void* copy = self->allocator.Allocate(length);
            memcpy(copy, data, length);
            func_02057e6c(mgr, 5, &self->allocator, copy, length, fields);
            loader->RemoveTask(self->task);
            self->state++;
        }
    } else if (self->state == 2) {
        int count = 0;
        int ids[5];
        ObjParams02078484 params[5];
        if (self->active != 0) {
            _Z34CopyCountedBytesToIntArray02010834P12Base02010834iPiS1_((Base02010834*)gs, *(short*)((char*)leader + 4), ids, &count);
            for (int i = 0; i < count; i++) {
                self->members |= 1 << ids[i];
            }
            if (gs->GetGameObjectByIndex(0xce) && func_0202c508(search)) {
                ids[count] = 0xce;
                self->members |= 0x10;
                count++;
            }
        } else {
            for (int i = 0; i < 5; i++) {
                if (self->members & (1 << i)) {
                    if (i != 4) {
                        ids[count] = i;
                    } else {
                        ids[count] = 0xce;
                    }
                    count++;
                }
            }
        }
        for (int k = 0; k < count; k++) {
            GameObject* member = gs->GetGameObjectByIndex(ids[k]);
            if (member) {
                params[k].f00 = 0;
                params[k].f10 = 1;
                params[k].f12 = 0;
                params[k].f14 = -1;
                params[k].f16 = -1;
                params[k].f18 = -1;
                params[k].f1a = -1;
                params[k].f1c = -0x1000;
                params[k].f20 = 0;
                params[k].f24 = 0;
                params[k].f28 = 0;
                params[k].position.x = 0;
                params[k].position.y = 0;
                params[k].position.z = 0;
                params[k].f38 = 0;
                params[k].f3c = 0;
                params[k].f40 = 0;
                params[k].scale.x = 0x1000;
                params[k].scale.y = 0x1000;
                params[k].scale.z = 0x1000;
                params[k].b0 = 0;
                params[k].b1 = 0;
                params[k].b2 = 1;
                params[k].b3 = 0;
                params[k].b4 = 0;
                params[k].b5 = 0;
                params[k].b6 = 0;
                params[k].b7 = 0;
                _ZN8Vector3iaSERKS_(&params[k].position, ((Object3D*)member)->position_);
                _ZN8Vector3iaSERKS_(&params[k].scale, ((Object3D*)member)->GetScale());
                _Z26FindNodeAndProcess02057fb4Pvii(mgr, 5, (int)&params[k]);
            }
        }
        self->state++;
    } else if (self->state == 3) {
        self->timer += delta;
        if (self->timer > 8) {
            _Z26SetForwardAndStore0205ebc0Pvii(&data_02108760, 0xb1, 0xb1);
            _Z34DispatchIfField0xc4NonNeg_0205ebfcPvii(&data_02108760, 0, 0);
            self->state++;
        }
    } else if (self->state == 4) {
        self->timer += delta;
        if (self->timer > 0x32) {
            for (int i = 0; i < 5; i++) {
                if (self->members & (1 << i)) {
                    GameObject* member = gs->GetGameObjectByIndex(i != 4 ? i : 0xce);
                    if (member) {
                        ((Object3D*)member)->EnableFlag(1);
                    }
                }
            }
            self->state++;
        }
    } else if (self->state == 5) {
        self->timer += delta;
        if (self->timer > 0x6e) {
            SetBrightness(res, -0x10, 0x1e);
            self->state++;
        }
    } else if (self->state == 6) {
        self->timer += delta;
        if (self->timer > 0xaa && !IsBrightnessTransitionActive(res)) {
            for (int i = 0; i < 5; i++) {
                if (self->members & (1 << i)) {
                    GameObject* member = gs->GetGameObjectByIndex(i != 4 ? i : 0xce);
                    if (member) {
                        ((Object3D*)member)->DisableFlag(1);
                    }
                }
            }
            ClearBitsInWord((unsigned int*)res, 0x10);
            _Z27CallListIfFlagsSet_02197528v();
            self->done = 1;
            SetByteField0x253(leader);
            func_ov017_021ac2a8(self);
            _Z25ForwardField0xc0_0205ebecPv(&data_02108760);
            if (func_0202c508(search)) {
                unsigned char* flags = (unsigned char*)func_0205ec34();
                SetOrClearBitInArray(flags, flags + 0x8c, 0x113d, 1);
            }
            if (CheckBitsInField0x63dc(gs, 1) && self->active != 0) {
                TailList020469b4* tail;
                unsigned char* node = (unsigned char*)res->unknown_ptr_array_3afc[0x14];
                tail = (TailList020469b4*)res->unknown_ptr_array_36fc[0];
                _Z21InitObjState_021b2174Ph(node);
                _Z23SetNameChecked_021b2ba0P9S021b2ba0Pc((S021b2ba0*)node, &data_ov017_021d78f1);
                _Z25SetFields30And34_021b2bd0Pvii(node, (int)_Z29AllocateAndCopyBuf20_021689d8P13SafeAllocatorPv, OVERLAY_ID(4));
                _Z16SetBit4_021b2bf4P9S021b2bf4j((S021b2bf4*)node, 1);
                _Z16SetBit5_021b2c0cP9S021b2c0cj((S021b2c0c*)node, 1);
                _Z16SetBit3_021b2bdcP9S021b2bdcj((S021b2bdc*)node, 0);
                AppendNodeToTail(tail, (TailNode020469b4*)node);
            }
        }
    }
}
