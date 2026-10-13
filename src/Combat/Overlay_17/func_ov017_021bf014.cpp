#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"

struct EntryA68 { short key; void* value; };
struct TableA68 { EntryA68* entries; short count; };
struct GrottoDialogState { char pad[8]; int state; TableA68 text; SafeAllocator allocator; int task; };
struct Obj02046574;
#if defined(jpn)
enum { TextOffset = 0x28, ChoiceOffset = 0x218, DialogOffset = 0x868,
       PendingOffset = 0x870, ChoiceFlagOffset = 0x17e2, TextHeapSize = 0x1f4 };
extern const char data_ov017_021d86d4[];
#else
enum { TextOffset = 0x5c, ChoiceOffset = 0x2c8, DialogOffset = 0x998,
       PendingOffset = 0x9a0, ChoiceFlagOffset = 0x19b2, TextHeapSize = 0x320 };
#endif

struct Obj020d7aa0;
struct Obj020397cc;
extern AllocatorUnion data_02114e20;
extern char data_ov017_021d7ec0[];
extern char data_ov017_021d7ed5[];
extern "C" void func_0202ae18();
extern "C" Obj02046574* _Z26GetGlobalField0x1c020421a0v();
extern "C" void* func_02012fe4();
unsigned char* GetFieldIfFlag4(char*);
extern "C" Obj020d7aa0* _Z25GetGlobalResetObj020d7a50v();
extern "C" void _Z29TeardownAndResetState020d7aa0P11Obj020d7aa0(Obj020d7aa0*);
extern "C" void _Z27CancelPendingAction020397ccP11Obj020397cci(Obj020397cc*, int);
void ClearIntAt0x23c(unsigned char*);
void* AllocateAligned4(AllocatorUnion*, unsigned int);
extern "C" void func_020728ac(TableA68*, SafeAllocator*, void*, unsigned int, int, int, int);
extern "C" void func_02046380(Obj02046574*);
extern "C" void _Z22SetIndexedName02046574P11Obj02046574iPc(Obj02046574*, int, char*);
void* GetGlobal02109400();
extern "C" void _Z21BlankFunction02094b30v();
extern "C" bool _Z18AlwaysTrue02094b4cv();
typedef void (*BeginDialog)(void*, int, int);
typedef bool (*DialogReady)(void*);
char* FindEntryByKey(TableA68*, int);
extern "C" void func_0204500c(Obj02046574*, char*, int
#if !defined(jpn)
    , int
#endif
);
extern "C" int func_020457e0(Obj02046574*);
void ClearAllTreasureMapUnknownBits(void*);
extern "C" void _Z29SetCombatModeFromCase020dc2d0i(int);
extern "C" void _Z24ReinitController02043204Pc(char*);
void SetByteField0x253(void*);
extern "C" void _Z21BlankFunction02094b38v();
typedef void (*EndDialog)(void*, int);
extern "C" void func_02094ab0(void*);
extern "C" void _Z37ClearFieldsAndResetAllocator_021bf398Pc(char*);

// JPN: func_ov017_021bf5d0
// USA: func_ov017_021bf014
extern "C" ARM void func_ov017_021bf014(GrottoDialogState* self) {
    GameState* game = GameState::GetInstance();
    func_0202ae18();
    func_ov017_0218b5b0();
    Obj02046574* controller = _Z26GetGlobalField0x1c020421a0v();
    func_02012fe4();
    GrottoStruct* grotto = game->GetGrottoStruct();
    GameObject* combatant = game->GetUnknownGameObject();
    unsigned char* field = GetFieldIfFlag4((char*)game);
    if (self->state == 0) {
        _Z29TeardownAndResetState020d7aa0P11Obj020d7aa0(_Z25GetGlobalResetObj020d7a50v());
        _Z27CancelPendingAction020397ccP11Obj020397cci((Obj020397cc*)combatant, 1);
        ClearIntAt0x23c(field);
        void* buffer = AllocateAligned4(&data_02114e20, TextHeapSize);
        self->allocator.CreateTypeA(buffer, TextHeapSize);
#if defined(jpn)
        self->task = BackgroundLoader::GetInstance()->QueueLoadFile(data_ov017_021d86d4, 0);
#else
        self->task = BackgroundLoader::GetInstance()->QueueLoadFileInGP2(data_ov017_021d7ec0, data_ov017_021d7ed5, 0);
#endif
        self->state = 1;
    } else if (self->state == 1) {
        if (!BackgroundLoader::GetInstance()->GetTaskStatus(self->task)) return;
        void* file;
        unsigned int length;
        BackgroundLoader::GetInstance()->GetLoadedFileByID(self->task, &file, &length);
        self->allocator.Reset();
        func_020728ac(&self->text, &self->allocator, file, length, 0, 0, 0);
        BackgroundLoader::GetInstance()->RemoveTask(self->task);
        self->task = -1;
        func_02046380(controller);
        _Z22SetIndexedName02046574P11Obj02046574iPc(controller, 0, game->GetUnknownGameObject()->baseStats_->unk);
        BeginDialog begin = (BeginDialog)_Z21BlankFunction02094b30v;
        begin(GetGlobal02109400(), 0x203, 0);
        self->state = 2;
    }
    if (self->state == 2) {
        DialogReady ready = (DialogReady)_Z18AlwaysTrue02094b4cv;
        if (!ready(GetGlobal02109400())) return;
        if (grotto->activeMapData.GetDiscoveryState() == DiscoveryState_Undiscovered) self->state = 3;
        else self->state = 4;
    } else if (self->state == 3) {
        char* text = (*reinterpret_cast<char**>(reinterpret_cast<char*>(controller) + TextOffset));
        strcpy(text, FindEntryByKey(&self->text, 1));
        func_0204500c(controller, text, 0
#if !defined(jpn)
            , 0xe3
#endif
        );
        (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(controller) + ChoiceFlagOffset)) = 0;
        (*reinterpret_cast<int*>(reinterpret_cast<char*>(controller) + ChoiceOffset)) = 0;
        (*reinterpret_cast<int*>(reinterpret_cast<char*>(controller) + DialogOffset)) = 1;
        self->state = 5;
    } else if (self->state == 4) {
        char* text = (*reinterpret_cast<char**>(reinterpret_cast<char*>(controller) + TextOffset));
        strcpy(text, FindEntryByKey(&self->text, 2));
        func_0204500c(controller, text, 0
#if !defined(jpn)
            , 0xe3
#endif
        );
        (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(controller) + ChoiceFlagOffset)) = 0;
        (*reinterpret_cast<int*>(reinterpret_cast<char*>(controller) + DialogOffset)) = 1;
        (*reinterpret_cast<int*>(reinterpret_cast<char*>(controller) + ChoiceOffset)) = 0;
        self->state = 5;
    } else if (self->state == 5) {
        _Z27CancelPendingAction020397ccP11Obj020397cci((Obj020397cc*)combatant, 1);
        if ((*reinterpret_cast<int*>(reinterpret_cast<char*>(controller) + DialogOffset))) return;
        grotto->unknown_0[2] = 1;
        int result = func_020457e0(controller);
        if (result == 0) self->state = 6;
        else if (result == 1) self->state = 9;
    } else if (self->state == 6) {
        ClearAllTreasureMapUnknownBits(game);
        _Z29SetCombatModeFromCase020dc2d0i(0);
        self->state = 7;
    } else if (self->state == 7) {
        self->state = 8;
    } else if (self->state == 8) {
        _Z27CancelPendingAction020397ccP11Obj020397cci((Obj020397cc*)combatant, 1);
        if (!(*reinterpret_cast<int*>(reinterpret_cast<char*>(controller) + PendingOffset))) self->state = 9;
    } else if (self->state == 9) {
        _Z24ReinitController02043204Pc((char*)controller);
        SetByteField0x253(combatant);
        void* global = GetGlobal02109400();
        EndDialog end = (EndDialog)_Z21BlankFunction02094b38v;
        end(global, 0x203);
        func_02094ab0(global);
        _Z37ClearFieldsAndResetAllocator_021bf398Pc((char*)self);
    }
}
