#include <globaldefs.h>

typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef unsigned int u32;

struct Container02080cc0 {
    u8 padding_0[0x36];
    s16 selected;
};
struct Container02080f8c;
struct Container02080fa8;
struct StatusOwner02081198;
struct StatusOwner02081164;
struct Container020e0310 {
    u8 padding_0[0x48];
};
struct CombatMenuEntry021666c4 {
    u8 enabled : 1;
    u8 count : 6;
    u8 active : 1;
    char text[0x36];
};
struct CombatMenu021666c4 {
    CombatMenuEntry021666c4 entries[10];
    s16 entry_count;
    u8 padding_228[0xb4];
    Container020e0310 messages;
    Container02080cc0* menu;
    u8 padding_328[0x13c];
    u32 flags;
    u8 padding_468[0x38];
    s8 page;
    u8 padding_4a1[0x1c];
    u8 selection;
};

void SetSublistEntriesFlag1(void*, int);
extern "C" void func_0202ae18();
void SetEntryHighNibble0x13(Container02080cc0*, int, int);
extern "C" void _Z24SetEntryFlagById02080b40Pvi(void*, int);
extern "C" void _Z26SetEntryFirstField02080f8cP17Container02080f8cii(Container02080f8c*, int, int);
extern "C" void _Z26SetEntryFirstField02080fa8P17Container02080fa8ii(Container02080fa8*, int, int);
extern "C" int _Z21GetFieldByKey020e0434P17Container020e0310i(Container020e0310*, int);
void SetEntryNibbleByShortId(StatusOwner02081198*, int, int);
void SetEntryFlag0x2ByShortId(StatusOwner02081164*, int, int);
extern "C" void func_020813ec(void*, int);
extern "C" void func_ov003_02160794(CombatMenu021666c4*);

// USA: func_ov003_021666c4
extern "C" ARM void func_ov003_021666c4(CombatMenu021666c4* self) {
    Container02080cc0* menu = self->menu;
    SetSublistEntriesFlag1(menu, 16);
    int id = 69;
    func_0202ae18();
    self->selection = id;
    int index = self->page * 4;
    int end = index + 4;
    for (; index < end; id = (s16)(id + 1), index++) {
        int color = 15;
        if (id == menu->selected) color = 10;
        SetEntryHighNibble0x13(menu, id, color);
        CombatMenuEntry021666c4* entry = &self->entries[index];
        if (entry->active && index < self->entry_count) {
            char* text;
            int count;
            if (entry->enabled) {
                text = entry->text;
                count = 4 - entry->count;
            } else {
                if (id == menu->selected) SetEntryHighNibble0x13(menu, id, 8);
                else SetEntryHighNibble0x13(menu, id, 4);
                text = entry->text;
                count = 0;
            }
            for (int row = 1; row < 3; row = (s16)(row + 1)) {
                int row_id = id + row * 4;
                SetEntryHighNibble0x13(menu, (s16)row_id, color);
                _Z24SetEntryFlagById02080b40Pvi(menu, (s16)(unsigned int)row_id);
            }
            _Z26SetEntryFirstField02080f8cP17Container02080f8cii((Container02080f8c*)menu, id, (int)text);
            _Z26SetEntryFirstField02080fa8P17Container02080fa8ii((Container02080fa8*)menu, (s16)(id + 4), count);
        } else {
            int text = _Z21GetFieldByKey020e0434P17Container020e0310i(&self->messages, 30000);
            _Z26SetEntryFirstField02080f8cP17Container02080f8cii((Container02080f8c*)menu, (s16)id, text);
        }
        _Z24SetEntryFlagById02080b40Pvi(menu, id);
    }
    _Z26SetEntryFirstField02080fa8P17Container02080fa8ii((Container02080fa8*)menu, 201, self->page + 1);
    _Z26SetEntryFirstField02080fa8P17Container02080fa8ii((Container02080fa8*)menu, 202, 2);
    _Z24SetEntryFlagById02080b40Pvi(menu, 200);
    _Z24SetEntryFlagById02080b40Pvi(menu, 201);
    _Z24SetEntryFlagById02080b40Pvi(menu, 202);
    SetEntryNibbleByShortId((StatusOwner02081198*)menu, 16, 1);
    SetEntryFlag0x2ByShortId((StatusOwner02081164*)menu, 16, 1);
    func_020813ec(menu, 16);
    self->flags |= 0xd00000;
    func_ov003_02160794(self);
}
