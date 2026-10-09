#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "Memory/SafeAllocator.h"
#include <std_library_functions.h>

struct BattleState { char pad0[0x8e14]; signed char outcome; char pad8e15[0xb]; int mode; int count; };
struct Work {
    char pad0[0x30]; SafeAllocator allocator;
    char padAllocator[0x14c-0x30-sizeof(SafeAllocator)]; char secondaryAllocator[0x29c-0x14c];
    BattleState* battle; char pad2a0[8]; char display[0xa40-0x2a8];
    char task[0xa0]; unsigned char taskReady; char padAe1[0xb30-0xae1];
    char events[0xc18-0xb30]; char cameraTask[0xe78-0xc18];
    unsigned char active; char padE79[0xeac-0xe79]; int state;
    char padEb0[0x55d8-0xeb0]; int slot;
    char pad55dc[0x5951-0x55dc]; unsigned char mode : 2; unsigned char flags : 6;
};
struct List02160094;
struct List021600f8;
struct ListNode02160094 { char pad0[0x20]; unsigned short id; };
struct ListNode021600f8 { int flags; char pad4[8]; int value; char pad10[8]; unsigned char flag18; char pad19[2]; unsigned char flag1b; };
struct MessageSystem { char pad0[0x998]; int active; };
struct Obj0205eaa0;
struct Struct0216fe48;
struct ShortSetStruct0216fdf8;
struct Struct0216fd0c;
struct Struct0216fd38;
struct EntryTask0216fd80;
void* GetSlotPtr02160f20(void*);
extern "C" void* func_02057924();
unsigned char* GetField02163524(void*);
extern "C" unsigned char _ZZ16GetTimer021ef974vE1s __attribute__((aligned(4)));
extern Obj0205eaa0 data_02108760;
extern "C" void func_ov025_021db6dc(Work*);
int ClassifyField0x81fe(char*);
ListNode02160094* GetNodeAtIndex02160094(List02160094*, int);
ListNode021600f8* GetNodeAtIndex021600f8(List021600f8*, int);
extern "C" void func_ov025_021e88d8(char*);
void SetTwoFields_021e8a40(char*, int, int);
void SetField_021e8a4c(char*, int);
extern "C" void func_ov000_0216df00(void*, int, int, int, float);
extern "C" void func_ov000_021626a0(void*, int, int);
void SetCombatWorkFlags0x55f4(void*, int);
int GetCombatWorkFlags0x55f4(void*, int);
void ClearCombatWorkFlags0x55f4(void*, int);
void DispatchWithShortB4_0205eaa0(Obj0205eaa0*, int, int);
extern "C" void func_ov025_021dbe10(Work*);
void ResetStruct0216fe48(Struct0216fe48*);
void AppendUniqueShort0216fdf8(ShortSetStruct0216fdf8*, int);
void SetField0FromCallFunc0202fa38(Struct0216fd0c*);
MessageSystem* GetGlobalField0x1c020421a0();
void CheckOrSetFlagA0_0216fd38(Struct0216fd38*);
int GetArrayEntry_021e8a54_021e8a54(char*);
void BeginListEntryTask_0216fd80(EntryTask0216fd80*, int);
char* GetFieldByKeyFromWork0x88(void*, int);
extern "C" void func_0204500c(MessageSystem*, char*, int, int);
extern "C" void func_ov025_021eedb0(char*);
extern "C" void func_ov025_021dcf14(Work*);
extern "C" void func_ov025_021de124(Work*);
extern "C" void func_ov025_021e9fc4(char*);
extern "C" void func_ov025_021dc168(Work*);
extern "C" void func_ov025_021dc324(Work*);
extern "C" void func_ov025_021dc590(Work*);
extern "C" void func_ov025_021dc694(Work*);
extern "C" void func_ov025_021dc880(Work*);
extern "C" void func_ov025_021db458(Work*);
extern "C" void func_ov025_021db7f8(Work*);
void SetFieldsAndSignalData02184220(void*, int);
void SetBitsInWord(unsigned int*, unsigned int);
inline unsigned int AlignedSize(unsigned int length) { return (length + 3) & ~3; }

// USA: func_ov025_021db038
extern "C" ARM void func_ov025_021db038(Work* work) {
    BattleState* battle = work->battle;
    void* list = GetSlotPtr02160f20(work);
    GameState* game = GameState::GetInstance();
    GameResources* resources = func_ov017_0218b5b0();
    func_02057924();
    GetField02163524(work);
    _ZZ16GetTimer021ef974vE1s = 0;
    if (!work->active) _ZZ16GetTimer021ef974vE1s = 1;
    if (!work->state) func_ov025_021db6dc(work);
    if (work->state == 1) {
        int id;
        ListNode021600f8* target;
        ListNode02160094* actor;
        int messageId;
        messageId = -1;
        if (ClassifyField0x81fe((char*)battle)) {
            actor = GetNodeAtIndex02160094((List02160094*)list, 0);
            target = GetNodeAtIndex021600f8((List021600f8*)list, 0);
            if (actor) {
                id = actor->id;
                if (battle->mode == 1 && id == 0xc0) {
                    func_ov025_021e88d8(work->display);
                    SetTwoFields_021e8a40(work->display, (int)&work->allocator, (int)work->secondaryAllocator);
                    SetField_021e8a4c(work->display, (int)battle);
                    func_ov000_0216df00(work->cameraTask, id, 0, 0, 1.8f);
                    func_ov000_021626a0(work, 4, 0);
                    func_ov000_021626a0(work, 0, 1);
                    SetCombatWorkFlags0x55f4(work, 0x1000000);
                    if (ClassifyField0x81fe((char*)battle) == 1) messageId = 0x1ee;
                    else if (ClassifyField0x81fe((char*)battle) == 2) messageId = 0x211;
                }
                if (actor->id == 0) {
                    DispatchWithShortB4_0205eaa0(&data_02108760, 7, 0);
                    if (target) { target->flags = 0; target->flag18 = 0; target->value = 0; target->flag1b = 0; }
                }
            }
        }
        func_ov025_021dbe10(work);
        if (messageId > 0) {
            ResetStruct0216fe48((Struct0216fe48*)work->task);
            AppendUniqueShort0216fdf8((ShortSetStruct0216fdf8*)work->task, (short)messageId);
            SetField0FromCallFunc0202fa38((Struct0216fd0c*)work->task);
        }
    }
    if (GetCombatWorkFlags0x55f4(work, 0x1000000)) {
        GameState* game;
        char* format;
        GameObject* actor;
        MessageSystem* messages;
        game = GameState::GetInstance();
        messages = GetGlobalField0x1c020421a0();
        if (!work->taskReady) {
            CheckOrSetFlagA0_0216fd38((Struct0216fd38*)work->task);
            if (!work->taskReady) return;
            BeginListEntryTask_0216fd80((EntryTask0216fd80*)work->task, GetArrayEntry_021e8a54_021e8a54(work->display));
            actor = GetCombatantWithFlag0x100(game, 0);
            format = 0;
            if (ClassifyField0x81fe((char*)battle) == 1) format = GetFieldByKeyFromWork0x88(work->task, 0x1ee);
            else if (ClassifyField0x81fe((char*)battle) == 2) format = GetFieldByKeyFromWork0x88(work->task, 0x211);
            if (!actor || !format) return;
            char* name = (char*)actor->baseStats_;
            int length = strlen(format);
            length += strlen(name);
            char* text = (char*)work->allocator.Allocate(AlignedSize(length - 1));
            if (!text) return;
            sprintf(text, format, actor->baseStats_);
            func_0204500c(messages, text, 0, 0xe3);
            messages->active = 1;
            return;
        }
        if (messages->active) return;
        ClearCombatWorkFlags0x55f4(work, 0x1000000);
        return;
    }
    func_ov025_021eedb0(work->events);
    func_ov025_021dcf14(work);
    func_ov025_021de124(work);
    func_ov025_021e9fc4(work->display);
    if (work->mode != 1) func_ov025_021dc168(work);
    if (work->state == 6) func_ov025_021dc324(work);
    if (work->state == 3) func_ov025_021dc590(work);
    if (work->state == 4) func_ov025_021dc694(work);
    if (work->state == 5) func_ov025_021dc880(work);
    func_ov025_021db458(work);
    if (work->slot != battle->count) return;
    func_ov025_021db7f8(work);
    if (work->battle->outcome == 2) SetFieldsAndSignalData02184220(work, 10);
    else if (work->battle->outcome == 1) SetFieldsAndSignalData02184220(work, 9);
    else {
        SetFieldsAndSignalData02184220(work, 7);
        SetBitsInWord(&resources->brightnessFlags_0, 0x800);
    }
    game->SetGameSpeed(0x1000);
}
