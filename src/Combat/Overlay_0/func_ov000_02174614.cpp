#include <globaldefs.h>

extern "C" void* memset(void* dst, int value, unsigned int size);

struct CombatantEntry {
    char pad0[0x38];
    int field_0x38;
    char pad3c[0x4c - 0x3c];
    int id;
    char pad50[0x87 - 0x50];
    unsigned char active;
    char pad88[0x448 - 0x88];
};

struct CombatantTable {
    char pad0[0x6c];
    signed char order[4];
    char pad70[0x958 - 0x70];
    CombatantEntry entries[4];
    char pad1a78[0x1d60 - 0x1a78];
    unsigned char selected[8];
    signed char cursor;
};

extern "C" int _Z29HasAnyFlags_021719f8_021719f8Pi(int* obj);
extern "C" void func_ov000_0217f518(CombatantEntry* entry);
extern "C" void func_ov000_0217636c(CombatantEntry* entry, int mode);

// USA: func_ov000_02174614
extern "C" ARM void func_ov000_02174614(CombatantTable* table, int id)
{
    CombatantEntry* entry;
    if (id < 0) {
        int i;
        memset(table->selected, 0, sizeof(table->selected));
        table->cursor = 0;
        table->selected[table->cursor] = 1;
        for (i = 0; i < 4; i++) {
            entry = &table->entries[table->order[i]];
            if (entry->id >= 0 && entry->active != 0 && !_Z29HasAnyFlags_021719f8_021719f8Pi((int*)entry)) {
                func_ov000_0217f518(entry);
                if (entry->field_0x38 != 0) {
                    func_ov000_0217636c(entry, 0);
                }
            }
        }
        return;
    }
    int i;
    for (i = 0; i < 4; i++) {
        entry = &table->entries[table->order[i]];
        if (id == entry->id) {
            func_ov000_0217f518(entry);
            if (entry->field_0x38 != 0) {
                func_ov000_0217636c(entry, 0);
            }
            return;
        }
    }
}
