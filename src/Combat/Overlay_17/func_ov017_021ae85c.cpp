#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include <std_library_functions.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/AllocatorUnion.h"
#include "World/ZoneLootableRecord.h"

struct Bytes02033b88;
struct Obj020397cc;
struct Obj02033b68;
struct Obj0205eaa0;
struct Vec3copy0202ec84;
struct Vec3Target0203a46c;
struct StructAt020473c8;
struct Container020dedd0 { unsigned int fields[4]; };
struct StructDE234_020de234 {
    int fields[4]; unsigned int low:10, mid:10, kind:8, unused:4;
};
struct State0207dfc8 { unsigned int words[28]; };
struct ResourceState021ae85c { char pad0[0x230]; State0207dfc8 spriteTables; };
struct Zone021ae85c {
    char pad0[0x600]; Foo02048004 sprites[6]; char pad930[0x2754 - 0x930];
    Container020dedd0 container;
};
struct Controller021ae85c {
    char pad0[0x2d8]; int field2d8; char pad2dc[0xa]; unsigned char field2e6;
};
struct Event021ae85c {
    unsigned char pad0, done; char pad2[6]; unsigned char stage, mode;
    unsigned short timer; short key; char pade[2]; int task;
    Vector3fix position; int angle, fade; Foo02048004* sprite; SafeAllocator allocator;
};
struct TextContext021ae85c {
    SafeAllocator allocator; char list[0x18]; Container020dedd0* container;
    int field30, field34;
};
extern "C" Zone021ae85c* func_02012fe4();
extern "C" void* func_0202ae18();
extern "C" int func_0202c540(void*);
extern "C" void func_ov017_021aeea8(Event021ae85c*);
void SetByte0xbeShiftPrev(Bytes02033b88*, int);
void CancelPendingAction020397cc(Obj020397cc*, int);
void SetByteIfChanged02033b68(Obj02033b68*, int);
void DispatchWithShortB4_0205eaa0(Obj0205eaa0*, int, int);
StructDE234_020de234* FindElementByKey020dedd0(Container020dedd0*, int);
int GetField0x3acValue(GameState*);
unsigned short GetPreferredPackedField020de234(StructDE234_020de234*, int);
void SetByteField0x253(void*);
void* AllocateAligned4(AllocatorUnion*, unsigned int);
void CopyState0207dfc8(State0207dfc8*, State0207dfc8*);
void RestorePairTables0207df90(char*);
void Forward02047b30(void*, int, int, int);
void BackupPairTables0207dfac(char*);
Controller021ae85c* GetGlobalField0x1c020421a0();
extern "C" void __clear(void*, int);
void* ZeroInitReturn020de824(void*);
void InitStruct0207cbe8(char*);
extern "C" int func_0207d538(void*, int, int, char*, int);
void* GetGlobalResetObj020d7a50();
extern "C" void func_020d7e10(void*, char*, int, int, int, int);
void* GetField0x3b0Value(GameState*);
void ComputeTwoFromVec3_0202ec84(void*, Vec3copy0202ec84*, int*, int*);
void SetVec3At0x1c(Vec3Target0203a46c*, int, int, int);
void RenderFlaggedIndexedEntry(StructAt020473c8*, int);
extern Obj0205eaa0 data_02108760;
extern const char data_ov017_021d79a8[];
extern AllocatorUnion data_02114e20;
static inline ResourceState021ae85c* ResourceStateBuffer021ae85c(GameResources* resources) {
    return (ResourceState021ae85c*)resources->unknown_2cc;
}

// USA: func_ov017_021ae85c
extern "C" ARM void func_ov017_021ae85c(Event021ae85c* self) {
    GameState* game = GameState::GetInstance();
    func_02012fe4();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    void* search = func_0202ae18();
    GameResources* resources = func_ov017_0218b5b0();
    if (func_0202c540(search)) {
        if (resources->unknown_flag_42e2) {
            func_ov017_021aeea8(self); self->done = 1; return;
        }
        if (self->mode != 1) {
            if (self->mode == 0) return;
            if (self->mode == 2) { self->done = 1; return; }
        }
    }
    if (self->stage == 0) {
        GameObject* actor = game->GetUnknownGameObject();
        if (!actor) { func_ov017_021aeea8(self); self->done = 1; return; }
        SetByte0xbeShiftPrev((Bytes02033b88*)actor, 0);
        CancelPendingAction020397cc((Obj020397cc*)actor, 1);
        self->timer = 5; self->stage = 1;
    } else if (self->stage == 1) {
        self->timer--;
        if (self->timer) return;
        GameObject* actor = game->GetUnknownGameObject();
        if (actor) SetByteIfChanged02033b68((Obj02033b68*)actor, 8);
        DispatchWithShortB4_0205eaa0(&data_02108760, 0x5b, 0);
        self->stage = 2; self->timer = 30;
    } else if (self->stage == 2) {
        self->timer--;
        if (self->timer) return;
        Zone021ae85c* zone = func_02012fe4();
        StructDE234_020de234* entry = FindElementByKey020dedd0(&zone->container, self->key);
        if (entry) {
            self->sprite = &zone->sprites[GetField0x3acValue(game)];
            MaybeInvoke0204719c(self->sprite);
            char filename[0x80];
            sprintf(filename, data_ov017_021d79a8, (signed char)entry->kind, GetPreferredPackedField020de234(entry, 0));
            self->task = loader->QueueLoadFile(filename, 0);
        } else {
            func_ov017_021aeea8(self); self->done = 1;
            SetByteField0x253(game->GetUnknownGameObject()); return;
        }
        self->stage = 3;
    } else if (self->stage == 3) {
        if (!loader->GetTaskStatus(self->task)) return;
        void* file = 0; unsigned int length = 0;
        loader->GetLoadedFileByID(self->task, &file, &length);
        if (file) {
            void* buffer = AllocateAligned4(&data_02114e20, 0x100);
            if (buffer) {
                self->allocator.ResetAllocatorPointer();
                self->allocator.CreateTypeA(buffer, 0x100); self->allocator.Reset();
                MaybeInvoke0204719c(self->sprite); func_0204719c(self->sprite);
                State0207dfc8 saved;
                CopyState0207dfc8(&ResourceStateBuffer021ae85c(resources)->spriteTables, &saved);
                RestorePairTables0207df90((char*)&saved);
                Forward02047b30(self->sprite, (int)file, length, (int)&self->allocator);
                BackupPairTables0207dfac((char*)&saved);
            } else {
                func_ov017_021aeea8(self); self->done = 1;
                SetByteField0x253(game->GetUnknownGameObject());
                loader->RemoveTask(self->task); return;
            }
        }
        loader->RemoveTask(self->task);
        FontBankLoader* global = GetGlobal02109400();
        BlankFunction02094b3c(global, 10);
        BlankFunction02094b30(global, 0x1f9, 0);
        self->stage = 4;
    } else if (self->stage == 4) {
        if (!AlwaysTrue02094b4c(GetGlobal02109400())) return;
        GetGlobalField0x1c020421a0();
        char text[0x80] = {};
        Zone021ae85c* zone = func_02012fe4();
        TextContext021ae85c context;
        context.allocator.ResetAllocatorPointer();
        ZeroInitReturn020de824(context.list);
        InitStruct0207cbe8((char*)&context); InitStruct0207cbe8((char*)&context);
        context.container = &zone->container;
        if (func_0207d538(&context, 2, (unsigned short)self->key, text, 1))
            func_020d7e10(GetGlobalResetObj020d7a50(), text, 0, 0, 1, 1);
        DispatchWithShortB4_0205eaa0(&data_02108760, 14, 0);
        self->stage = 5; self->timer = 20; self->fade = 61;
    } else if (self->stage == 5) {
        self->timer--;
        int tick = game->GetTickCount();
        void* camera = GetField0x3b0Value(game);
        Vector3fix position = self->position;
        if (self->angle < 0x191e) self->angle += tick * 0x199;
        position.y += fix32sin(self->angle);
        int x, y;
        if (camera) {
            ComputeTwoFromVec3_0202ec84(camera, (Vec3copy0202ec84*)&position, &x, &y);
        }
        SetVec3At0x1c((Vec3Target0203a46c*)self->sprite, (x - 12) << 12, (y - 40) << 12, 0);
        RenderFlaggedIndexedEntry((StructAt020473c8*)self->sprite, 1);
        if (!self->timer) { self->stage = 6; self->timer = 7; }
    } else if (self->stage == 6) {
        self->timer--;
        int tick = game->GetTickCount();
        void* camera = GetField0x3b0Value(game);
        Vector3fix position = self->position;
        position.y += fix32sin(self->angle);
        if (self->fade) {
            int x, y;
            if (camera) {
                ComputeTwoFromVec3_0202ec84(camera, (Vec3copy0202ec84*)&position, &x, &y);
            }
            SetVec3At0x1c((Vec3Target0203a46c*)self->sprite, (x - 12) << 12, (y - 40) << 12, 0);
            RenderFlaggedIndexedEntry((StructAt020473c8*)self->sprite, 1);
            self->fade -= tick;
            self->sprite->field82 = self->fade > 31 ? 31 : self->fade;
            if (self->fade < 0) self->fade = 0;
        }
        if (!self->timer) { GetGlobalField0x1c020421a0(); self->stage = 7; }
        else if (self->timer == 5) {
            GameObject* actor = game->GetUnknownGameObject();
            SetByteField0x253(actor); SetByteIfChanged02033b68((Obj02033b68*)actor, 0);
        }
    } else if (self->stage == 7) {
        Controller021ae85c* controller = GetGlobalField0x1c020421a0();
        controller->field2d8 = 0; controller->field2e6 = 1;
        func_02094ab0(GetGlobal02109400());
        func_ov017_021aeea8(self); self->done = 1;
    }
}
