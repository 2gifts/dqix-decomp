#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/CharacterCreationUI.h"
#include "std_library_functions.h"

struct StoreStruct { void* object; };
struct Status0215b964 { unsigned int flags; unsigned short currentHP; };
struct Combatant0215b964 {
    unsigned char padding_0[4];
    short id;
    unsigned char padding_6[0x12a];
    Status0215b964* status;
    BaseCombatStats* baseStats;
};
struct Detail0215b964 {
    unsigned char padding_0[0x16c];
    unsigned short values[(0x950 - 0x16c) / 2];
    int selected;
};
struct TextBuffers0215b964 {
    char padding_0[0x8e0];
    char formatted[0x40];
    char input[0x40];
};
struct PartyMenu0215b964 {
    unsigned char padding_0[0x64];
    Container020e0310 texts;
    unsigned char padding_6c[0x10];
    TextBuffers0215b964* buffers;
    unsigned char padding_80[0x505];
    signed char cursor;
    unsigned char padding_586[0xa];
    unsigned char count;
    unsigned char combatants[1];
};
int GetGlobalField0x1c020421a0();
int GetFieldByKey020e0434(Container020e0310*, int);
int GetFieldAt0x150(unsigned char*);
int AppendFormatted02041fac(char*, int, int);
int AppendFrameTag02041c08(char*, int, int, int, int, int);
int AppendCursorTag(char*, int);
int AppendPaletteTag(char*, int);
int AppendXYTag(char*, int, int);
int AppendXTag(char*, int);
int AppendString02042058(char*, const char*);
int AppendNameTag(char*, int, const char*);
void InitObjFromCombatantId020e4bf4(void*, int);
extern "C" void func_02046380(void*);
extern "C" void func_02046608(void*, int, void*, void*, int, int, int);
void StoreInArray0x8b0(StoreStruct*, int, int);
void SetByteInRange(unsigned char*, int, unsigned char);
void SetByteAtIndex(unsigned char*, int, unsigned char);
int CallFunc020e0434With02153694(int);

// USA: func_ov003_0215b964
extern "C" ARM void func_ov003_0215b964(PartyMenu0215b964* menu, char* output, int showFrame) {
    TextBuffers0215b964* buffers;
    if (!output) return;
    StoreStruct* formatter = (StoreStruct*)GetGlobalField0x1c020421a0();
    int cursor = menu->cursor;
    buffers = menu->buffers;
    if (cursor == -1) {
        AppendFormatted02041fac(output, GetFieldByKey020e0434(&menu->texts, 10), 14);
    } else {
        AppendFormatted02041fac(output, GetFieldByKey020e0434(&menu->texts, 11), 14);
        if (showFrame) AppendFrameTag02041c08(output, cursor, 8, 5, 5, 5);
        AppendCursorTag(output, cursor);
    }
    GameState* game = GameState::GetInstance();
    for (int index = 0; index < menu->count; ++index) {
        Combatant0215b964* combatant = (Combatant0215b964*)GetCombatantWithFlag0x100(game, menu->combatants[index]);
        Detail0215b964* detail = (Detail0215b964*)GetFieldAt0x150((unsigned char*)combatant);
        float ratio;
        int maximumHP;
        Status0215b964* status = combatant->status;
        unsigned int flags = status->flags;
        maximumHP = combatant->baseStats->primaryStats.maxHP;
        if (0.0f == (float)maximumHP) ratio = 0.0f;
        else {
            float currentHP = (float)(int)status->currentHP;
            ratio = currentHP / (float)maximumHP;
        }
        if (flags & 1) AppendPaletteTag(output, 9);
        else if (ratio <= 0.08f) AppendPaletteTag(output, 11);
        else if (ratio <= 0.25f) AppendPaletteTag(output, 13);
        else AppendPaletteTag(output, 15);
        AppendXYTag(output, 12, index * 14 + 20);
        const char* name;
        if (cursor == -1) {
            name = combatant->baseStats->unk;
            AppendString02042058(output, name);
        } else {
            name = combatant->baseStats->unk;
            AppendNameTag(output, index, name);
        }
        memset(buffers->formatted, 0, 0x40);
        memset(buffers->input, 0, 0x40);
        AppendXTag(buffers->input, 0x40);
        if (combatant->status->flags & 1)
            AppendString02042058(buffers->input, (const char*)GetFieldByKey020e0434(&menu->texts, 13));
        else if (flags & 2)
            AppendString02042058(buffers->input, (const char*)GetFieldByKey020e0434(&menu->texts, 14));
        else if (flags & 4)
            AppendString02042058(buffers->input, (const char*)GetFieldByKey020e0434(&menu->texts, 15));
        unsigned int descriptor[3];
        InitObjFromCombatantId020e4bf4(descriptor, combatant->id);
        func_02046380(formatter);
        formatter->object = descriptor;
        func_02046608(formatter, 10, buffers->input, buffers->formatted, 0x100, 0, 0);
        AppendString02042058(output, buffers->formatted);
        if (!(combatant->status->flags & 1) && !(flags & 6)) {
            func_02046380(formatter);
            StoreInArray0x8b0(formatter, 0, detail->values[detail->selected]);
            SetByteInRange((unsigned char*)formatter, 0, 2);
            SetByteAtIndex((unsigned char*)formatter, 0, 1);
            memset(buffers->formatted, 0, 0x40);
            memset(buffers->input, 0, 0x40);
            AppendXTag(buffers->input, 0x40);
            AppendString02042058(buffers->input, (const char*)CallFunc020e0434With02153694(0x3f3));
            AppendString02042058(buffers->input, (const char*)GetFieldByKey020e0434(&menu->texts, 12));
            func_02046608(formatter, 10, buffers->input, buffers->formatted, 0x100, 0, 0);
            AppendString02042058(output, buffers->formatted);
        }
    }
}
