#include <globaldefs.h>
#include "GameState/GameState.h"
#include "World/Object3D.h"

struct QueueEntry_0215ab54 { int a; int b; int c; int d; };
struct DataOv001_0215ab54 { char pad0[4]; QueueEntry_0215ab54* table; };
extern DataOv001_0215ab54 data_ov001_02165880;

struct TableEntry_0215ab54 { char pad0[0x90]; fix32_t radius; };

struct Entry_203dce4;
struct EntryList_203dce4;
EntryList_203dce4* GetGlobalPtr021075f4(void);
Entry_203dce4* GetEntryUnlessFlag0x8000(EntryList_203dce4* list, int id);
int GetField0x3acValue(GameState* state);
extern "C" void _Z29SetQueueEntryChecked_02164214Pviiii(void* table, int slot, int mode, int id, int target);
extern "C" void _Z29SetQueueEntryChecked_02164248Pviiii(void* table, int slot, int mode, int id, int target);

extern "C" void func_ov001_0215acb4(QueueEntry_0215ab54* entry);
extern "C" TableEntry_0215ab54* func_ov001_0215ab20(int index);
extern "C" void func_ov001_02159d9c(void* obj);
extern "C" void func_ov001_02159ea8(void* obj, int v);

// USA: func_ov001_0215ab54
extern "C" ARM void func_ov001_0215ab54(int mode, int id, int slot) {
    GameState* state = GameState::GetInstance();
    fix32_t radius = 0x1000;
    func_ov001_0215acb4(&data_ov001_02165880.table[slot]);

    if (mode == 0 || mode == 1 || mode == 4 || mode == 5) {
        GameObject* object = NULL;
        if (mode == 0) {
            object = state->GetGameObjectByIndex(GetField0x3acValue(state));
        } else if (mode == 1) {
            object = state->GetGameObjectByIndex(id);
        } else if (mode == 4) {
            object = state->GetGameObjectByIndex(0);
        } else if (mode == 5) {
            object = state->GetGameObjectByIndex(id);
        }
        if (object == NULL) return;
        _Z29SetQueueEntryChecked_02164214Pviiii(data_ov001_02165880.table, slot, mode, id, (int)object);
        radius = object->obj3D_.GetRadius();
    } else if (mode == 2 || mode == 6) {
        Entry_203dce4* entry = GetEntryUnlessFlag0x8000(GetGlobalPtr021075f4(), id);
        if (entry == NULL) return;
        _Z29SetQueueEntryChecked_02164248Pviiii(data_ov001_02165880.table, slot, mode, id, (int)entry);
    }

    TableEntry_0215ab54* tableEntry = func_ov001_0215ab20(slot);
    if (tableEntry == NULL) return;
    func_ov001_02159d9c(tableEntry);
    func_ov001_02159ea8(tableEntry, slot);
    tableEntry->radius = radius;
}
