#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include <std_library_functions.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/AllocatorUnion.h"

#if defined(jpn)
enum { kTextBufferCapacity = 0x800 };
#else
enum { kTextBufferCapacity = 0x960 };
#endif

struct Obj020397cc;
struct Obj02033834;
struct Obj0205eaa0;
struct BitFlags020d805c;
struct Obj020d7aa0;
struct StreamHeader;
struct Source021ac3b0 { unsigned short id; char pad2[0x1e]; short angle; };
struct Descriptor021ac3b0 { char pad0[5]; signed char kind; };
struct Zone021ac3b0 { unsigned short id; char pad2[6]; Descriptor021ac3b0* descriptor; };
struct ScriptInfo021ac3b0 {
    const char* text; const char* alternateText; const char* completedText;
    void* data; unsigned short zone; short key; unsigned char kind, index, count, enabled;
};
struct Item021ac3b0 {
    short id; unsigned short bit0:1, bit1:1, rest:14;
};
struct Event021ac3b0 {
    unsigned char pad0, done; char pad2[6]; Source021ac3b0* source;
    ScriptInfo021ac3b0* info; SafeAllocator allocator; int task;
    unsigned char stage, cancelled;
};
struct Controller021ac3b0 {
#if defined(jpn)
    char pad0[0x28]; char* formatted; char* text; char pad64[0x868 - 0x30];
    int active; char pad99c[0x17e2 - 0x86c]; unsigned char field19b2;
#else
    char pad0[0x5c]; char* formatted; char* text; char pad64[0x998 - 0x64];
    int active; char pad99c[0x19b2 - 0x99c]; unsigned char field19b2;
#endif
};
struct Flags021ac3b0 { char pad0[0x8c]; unsigned char bits[1]; };
struct Lookup021ac3b0 {
    char pad0[0xc]; int zone; char pad10[0x14]; int key; char pad28[0xc];
};
extern "C" Zone021ac3b0* func_02012fe4();
Controller021ac3b0* GetGlobalField0x1c020421a0();
void CancelPendingAction020397cc(Obj020397cc*, int);
extern "C" int func_ov017_021959b4();
void ReinitController02043204(char*);
extern "C" void func_ov017_021ac32c(Event021ac3b0*);
int GetFieldIfFlag4(char*);
void SetFlagsAt0x244(unsigned char*, unsigned char);
void DispatchWithShortB4_0205eaa0(Obj0205eaa0*, int, int);
void* GetGlobalResetObj020d7a50();
int GetByte0x150Bit6(BitFlags020d805c*);
void TeardownAndResetState020d7aa0(Obj020d7aa0*);
#if defined(jpn)
extern "C" void func_0204500c(void*, const char*, int);
#else
extern "C" void func_0204500c(void*, const char*, int, int);
#endif
extern "C" void func_020a0cc4(unsigned int);
void SetVecYByMode02033834(Obj02033834*, int);
extern "C" void func_020a0c0c();
void* AllocateAligned4(AllocatorUnion*, unsigned int);
void InitAndRunScript_021acc8c(void*, StreamHeader*, int, int);
extern "C" Flags021ac3b0* func_0205ec34();
int TestBitInByteArray(int, unsigned char*, int);
void AppendString02042058(char*, const char*);
const char* CallFunc020e0434With02153694(int);
char* GetData02108d18();
void Init0206f510(char*);
extern "C" void func_0206f550(char*, char*, char*);
extern "C" int func_020ac2d4(int, void*, Item021ac3b0*, int);
extern "C" void func_020ac104(int, Item021ac3b0*, int);
void SetOrClearBitInArray(void*, unsigned char*, int, int);
void SetByteField0x253(void*);
int LookupAndForEachNode020649b0(void*, int, void*);
extern "C" void func_0206f81c(Lookup021ac3b0*);
extern Obj0205eaa0 data_02108760;
#if defined(jpn)
extern const char data_ov017_021d7e88[], data_ov017_021d7e96[];
extern const char data_ov017_021d7eb0[], data_ov017_021d7ed2[];
#else
extern const char data_ov017_021d7920[], data_ov017_021d792f[], data_ov017_021d7949[];
#endif
extern AllocatorUnion data_02114e20;

// USA: func_ov017_021ac3b0
extern "C" ARM void func_ov017_021ac3b0(Event021ac3b0* self) {
    GameState* game = GameState::GetInstance();
    func_ov017_0218b5b0();
    GameObject* leader = game->GetUnknownGameObject();
    Zone021ac3b0* zone = func_02012fe4();
    Controller021ac3b0* controller = GetGlobalField0x1c020421a0();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    FontBankLoader* global = GetGlobal02109400();
    CancelPendingAction020397cc((Obj020397cc*)leader, 1);
    if (!self->cancelled && func_ov017_021959b4()) {
        self->cancelled = 1; ReinitController02043204((char*)controller);
        func_ov017_021ac32c(self); self->done = 1; return;
    }
    if (self->stage == 0) {
        int actor = GetFieldIfFlag4((char*)game);
        if (actor) SetFlagsAt0x244((unsigned char*)actor, 3);
        DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
        void* reset = GetGlobalResetObj020d7a50();
        if (GetByte0x150Bit6((BitFlags020d805c*)reset)) TeardownAndResetState020d7aa0((Obj020d7aa0*)reset);
#if defined(jpn)
        func_0204500c(controller, data_ov017_021d7e88, 0);
#else
        func_0204500c(controller, data_ov017_021d7920, 0, 0xe3);
#endif
        controller->field19b2 = 0; controller->active = 1;
        BlankFunction02094b3c(global, 10);
        BlankFunction02094b30(global, 0x1f6, 1);
        self->stage++;
    } else if (self->stage == 1) {
        if (AlwaysTrue02094b4c(global)) self->stage++;
    } else if (self->stage == 2) {
        func_020a0cc4(0x2800);
        CancelPendingAction020397cc((Obj020397cc*)leader, 1);
        SetVecYByMode02033834((Obj02033834*)leader, fix32ReduceAngle0To2Pi(self->source->angle));
        Descriptor021ac3b0* descriptor = zone->descriptor;
        char archive[0x50];
#if defined(jpn)
        sprintf(archive, data_ov017_021d7e96, descriptor->kind);
        self->task = loader->QueueLoadFile(archive, 0);
#else
        char filename[0x40];
        sprintf(archive, data_ov017_021d792f, descriptor->kind);
        sprintf(filename, data_ov017_021d7949, descriptor->kind);
        self->task = loader->QueueLoadFileInGP2(archive, filename, 0);
#endif
        self->stage++;
    } else if (self->stage == 3) {
        if (!loader->GetTaskStatus(self->task)) return;
        if (loader->GetDetailedTaskStatus(self->task) != 2) {
            loader->RemoveTask(self->task); self->task = -1; self->done = 1;
            func_ov017_021ac32c(self); func_020a0c0c(); return;
        }
        void* file; unsigned int length;
        loader->GetLoadedFileByID(self->task, &file, &length);
        self->allocator.CreateTypeA(AllocateAligned4(&data_02114e20, 0x2800), 0x2800);
        self->allocator.Reset();
        Zone021ac3b0* state = func_02012fe4();
        ScriptInfo021ac3b0* info = (ScriptInfo021ac3b0*)self->allocator.Allocate(0x18);
        self->info = info;
        info->text = 0; info->alternateText = 0; info->completedText = 0; info->data = 0;
        info->zone = 0; info->key = -1;
        info->kind = 0; info->index = 0; info->count = 0; info->enabled = 0;
        self->info->zone = state->id; self->info->key = self->source->id;
        InitAndRunScript_021acc8c(&self->allocator, (StreamHeader*)file, length, (int)self->info);
        loader->RemoveTask(self->task); self->task = -1; self->stage = 4;
    } else if (self->stage == 4) {
        char* formatted = controller->formatted;
        char* text = controller->text;
        memset(formatted, 0, kTextBufferCapacity); memset(text, 0, kTextBufferCapacity);
        if (self->info->enabled) {
            const char* message = self->info->text;
            if (self->info->kind == 1) {
                Flags021ac3b0* flags = func_0205ec34();
                if (TestBitInByteArray((int)flags, flags->bits, 0x777)) {
                    message = self->info->alternateText;
                    if (TestBitInByteArray((int)flags, flags->bits, self->info->index + 0x114c) && self->info->completedText)
                        message = self->info->completedText;
                }
            }
            if (message) AppendString02042058(text, message);
#if defined(jpn)
            else AppendString02042058(text, data_ov017_021d7eb0);
        } else AppendString02042058(text, data_ov017_021d7ed2);
#else
            else AppendString02042058(text, CallFunc020e0434With02153694(0x3f2));
        } else AppendString02042058(text, CallFunc020e0434With02153694(0x53));
#endif
        if (strlen(text) >= kTextBufferCapacity) text[kTextBufferCapacity - 1] = 0;
        char* data = GetData02108d18();
        Init0206f510(data); func_0206f550(data, text, formatted);
#if defined(jpn)
        func_0204500c(controller, formatted, 0);
#else
        func_0204500c(controller, formatted, 0, 0xe3);
#endif
        controller->active = 1; controller->field19b2 = 0; self->stage = 5;
    } else if (self->stage == 5) {
        if (controller->active) return;
        Flags021ac3b0* flags = func_0205ec34();
        if (TestBitInByteArray((int)flags, flags->bits, 0x777) && self->info->kind == 1 &&
            !TestBitInByteArray((int)flags, flags->bits, self->info->index + 0x114c)) {
            unsigned char count = self->info->count;
            if (count) {
                Item021ac3b0* items = (Item021ac3b0*)self->allocator.Allocate(count * 4);
                for (unsigned char i = 0; i < count; i++) {
                    items[i].id = -1; items[i].bit0 = 0; items[i].bit1 = 0; items[i].rest = 0;
                }
                if (func_020ac2d4(0, self->info->data, items, count)) {
                    for (unsigned char i = 0; i < count; i++) items[i].bit1 = 1;
                    func_020ac104(0, items, count);
                }
            }
            SetOrClearBitInArray(flags, flags->bits, self->info->index + 0x114c, 1);
        }
        FontBankLoader* state = GetGlobal02109400(); func_02094ab0(state);
        BlankFunction02094b34(state, 0x6f, 0x1388, 1, 1);
        self->stage = 6;
    } else if (self->stage == 6) {
        if (!AlwaysTrue02094b4c(GetGlobal02109400())) return;
        func_ov017_021ac32c(self); SetByteField0x253(leader); self->done = 1;
        Flags021ac3b0* flags = func_0205ec34();
        Lookup021ac3b0 lookup;
        lookup.zone = zone->id; lookup.key = self->source->id;
        if (LookupAndForEachNode020649b0(flags, 0x18, &lookup)) func_0206f81c(&lookup);
    }
}
