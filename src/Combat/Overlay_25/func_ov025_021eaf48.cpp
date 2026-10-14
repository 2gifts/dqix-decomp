#include <globaldefs.h>

struct ListNode02160094 {
    char pad0[0x1c];
    short altValue;
    char pad1e[2];
    unsigned short combatantId;
};
struct List02160094;

struct EffectEntry021eaf48 {
    unsigned short id;
    char pad2[2];
    struct EffectEntry021eaf48* next;
};

struct Effect021eaf48 {
    char pad0[8];
    struct EffectEntry021eaf48* entries;
    short value;
};

void* GetActiveCombatWork(void);
void* GetSlotPtr02160f20(void* obj);
struct ListNode02160094* GetNodeAtIndex02160094(struct List02160094* list, int index);
extern "C" int func_ov025_021ed380(char* obj, int id, int val2, int type, int val3, short val4, unsigned short val5);
void AddEntry_021ed5f0(char* obj, int val, int type, int val2);

// USA: func_ov025_021eaf48
extern "C" ARM void func_ov025_021eaf48(char* self, int index, int mode, struct Effect021eaf48* effect) {
    struct ListNode02160094* node = GetNodeAtIndex02160094((struct List02160094*)GetSlotPtr02160f20(GetActiveCombatWork()), index);
    if (node == 0) {
        return;
    }
    int id = node->combatantId;
    if (effect == 0) {
        return;
    }
    short target = id;
    if (mode == 3) {
        target = node->altValue;
    }
    struct EffectEntry021eaf48* entry = effect->entries;
    while (entry != 0) {
        int queued = func_ov025_021ed380(self + 0x1e8 + 0x400, entry->id, target, 3, (int)effect, id, 0);
        if (entry->id == 0x172) {
            AddEntry_021ed5f0(self + 0x1e8 + 0x400, effect->value, 4, queued);
        }
        entry = entry->next;
    }
}
