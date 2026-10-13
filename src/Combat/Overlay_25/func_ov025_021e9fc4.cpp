#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct Struct0216fd38;
struct ShortSetStruct0216fdf8;
struct EntryTask0216fd80;
struct List02160094;
struct List021600f8;
struct ListNode0215feb4 {
    char pad00[0x1f];
    unsigned char count;
    ListNode0215feb4* next;
};
struct ListNode02160094 {
    char pad00[0x26];
    unsigned char counts[6];
    char pad2c[4];
    ListNode02160094* next;
};
struct ListNode021600f8 {
    char pad00[0xe];
    short ids[3];
    unsigned char codes[3], codeCount;
    unsigned char counts[3];
    char pad1b[5];
    ListNode021600f8* next;
};
struct CombatSlot021e9fc4 {
    char pad00[8];
    unsigned char count0, count1;
    char pad0a[0xe];
    short ids[7];
};
struct EntryTaskView021e9fc4 {
    int id;
    short values[64];
    int count;
    char pad88[0x18];
    unsigned char ready, active;
    char padA2[2];
};
struct CombatTaskReceiver021e9fc4 {
    char pad00[0x10];
    int tasks[8];
    unsigned char selected;
    char pad31[0x5b7];
    char nameState[0x1ac];
    short nameId;
    unsigned short pad796;
    EntryTaskView021e9fc4 task;
    char name[0x40];
    unsigned char loaded;
    char pad87d[3];
    int loadTask, loadNameId;
};
void* GetActiveCombatWork();
CombatSlot021e9fc4* GetSlotPtr02160f20(void*);
int CheckOrSetFlagA0_0216fd38(Struct0216fd38*);
void AppendUniqueShort0216fdf8(ShortSetStruct0216fdf8*, int);
void BeginListEntryTask_0216fd80(EntryTask0216fd80*, int);
ListNode02160094* GetNodeAtIndex02160094(List02160094*, int);
ListNode021600f8* GetNodeAtIndex021600f8(List021600f8*, int);
ListNode0215feb4* GetNodeAtIndex0215feb4(char*, int, int);
void* GetNodeAtIndex0215fe2c(void*, int);
void* FindNodeAtDepth0215fff4(void*, int, int);
void SetName021ed324(void*, const char*);
extern "C" const char* func_020e046c(char*, void*, unsigned int, short);
extern "C" void func_ov025_021ed634(void*);

static inline int AtMostThree021e9fc4(int id) { return id <= 3; }
static inline short NarrowCode021e9fc4(int value) { return value; }
static inline unsigned char* Codes021e9fc4(ListNode021600f8* node) { return node->codes; }

// USA: func_ov025_021e9fc4
extern "C" ARM void func_ov025_021e9fc4(CombatTaskReceiver021e9fc4* self) {
    if (self->loaded == 0) {
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        if (self->loadTask >= 0) {
            if (loader->GetTaskStatus(self->loadTask) != 0) {
                void* file = 0;
                unsigned int size = 0;
                loader->GetLoadedFileByID(self->loadTask, &file, &size);
                if (file != 0) {
                    func_020e046c(self->name, file, size, (short)self->loadNameId);
                }
                SetName021ed324(self->nameState, self->name);
                self->nameId = self->loadNameId;
                loader->RemoveTask(self->loadTask);
                self->loadTask = -1;
                self->loaded = 1;
            }
        } else self->loaded = 1;
    }
    if (self->task.active != 0) {
        if (self->loaded != 0) func_ov025_021ed634(self->nameState);
    } else if (self->tasks[self->selected] != 0 &&
               CheckOrSetFlagA0_0216fd38((Struct0216fd38*)&self->task) != 0) {
        CombatSlot021e9fc4* slot = GetSlotPtr02160f20(GetActiveCombatWork());
        AppendUniqueShort0216fdf8((ShortSetStruct0216fdf8*)&self->task, slot->ids[0]);
        AppendUniqueShort0216fdf8((ShortSetStruct0216fdf8*)&self->task, slot->ids[1]);
        AppendUniqueShort0216fdf8((ShortSetStruct0216fdf8*)&self->task, slot->ids[2]);
        AppendUniqueShort0216fdf8((ShortSetStruct0216fdf8*)&self->task, slot->ids[3]);
        AppendUniqueShort0216fdf8((ShortSetStruct0216fdf8*)&self->task, slot->ids[4]);
        AppendUniqueShort0216fdf8((ShortSetStruct0216fdf8*)&self->task, slot->ids[5]);
        AppendUniqueShort0216fdf8((ShortSetStruct0216fdf8*)&self->task, slot->ids[6]);
        AppendUniqueShort0216fdf8((ShortSetStruct0216fdf8*)&self->task, 0x7e);
        AppendUniqueShort0216fdf8((ShortSetStruct0216fdf8*)&self->task, 0x7f);
        if ((unsigned short)slot->ids[0] == 0xfa) AppendUniqueShort0216fdf8((ShortSetStruct0216fdf8*)&self->task, 0x1e0);
        for (int index = 0; index < slot->count0; index++) {
            ListNode02160094* node = GetNodeAtIndex02160094((List02160094*)slot, index);
            if (node == 0) continue;
            for (int group = 0; group < 6; group++) {
                for (int item = 0; item < node->counts[group]; item++) {
                    ListNode0215feb4* link = GetNodeAtIndex0215feb4((char*)node, item, (unsigned char)group);
                    if (link == 0) continue;
                    for (int child = 0; child < link->count; child++) {
                        short* value = (short*)GetNodeAtIndex0215fe2c(link, child);
                        if (value != 0) AppendUniqueShort0216fdf8((ShortSetStruct0216fdf8*)&self->task, *value);
                    }
                }
            }
        }
        for (int index = 0; index < slot->count1; index++) {
            ListNode021600f8* node = GetNodeAtIndex021600f8((List021600f8*)slot, index);
            if (node == 0) continue;
            unsigned char* codes;
            for (int code = 1; code < node->codeCount; code++) {
                codes = Codes021e9fc4(node);
                int type = codes[code];
                if (type == 3) AppendUniqueShort0216fdf8((ShortSetStruct0216fdf8*)&self->task, 0x1b8);
                else if (type == 1) {
                    short value = 0xaa;
                    int id = node->ids[code - 1];
                    int valid = 0;
                    if (id >= 0) valid = AtMostThree021e9fc4(id);
                    if (valid) value = 0xa9;
                    AppendUniqueShort0216fdf8((ShortSetStruct0216fdf8*)&self->task, NarrowCode021e9fc4(value));
                } else if (!(type != 8 && type != 7 && type != 6)) AppendUniqueShort0216fdf8((ShortSetStruct0216fdf8*)&self->task, 0x7e);
                else if (!(type != 4 && type != 5)) AppendUniqueShort0216fdf8((ShortSetStruct0216fdf8*)&self->task, 0x142);
                else if (type == 10) AppendUniqueShort0216fdf8((ShortSetStruct0216fdf8*)&self->task, 0x143);
                else if (type == 2) {
                    short value = 0x29;
                    int id = node->ids[code - 1];
                    int valid = 0;
                    if (id >= 0) valid = AtMostThree021e9fc4(id);
                    if (valid) value = 0x28;
                    AppendUniqueShort0216fdf8((ShortSetStruct0216fdf8*)&self->task, NarrowCode021e9fc4(value));
                }
            }
            for (int group = 0; group < 3; group++) {
                for (int item = 0; item < node->counts[group]; item++) {
                    ListNode0215feb4* link = (ListNode0215feb4*)FindNodeAtDepth0215fff4(node, item, (unsigned char)group);
                    if (link == 0) continue;
                    for (int child = 0; child < link->count; child++) {
                        short* value = (short*)GetNodeAtIndex0215fe2c(link, child);
                        if (value != 0) AppendUniqueShort0216fdf8((ShortSetStruct0216fdf8*)&self->task, *value);
                    }
                }
            }
        }
        BeginListEntryTask_0216fd80((EntryTask0216fd80*)&self->task, self->tasks[self->selected]);
    }
}
