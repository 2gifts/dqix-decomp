#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Resource/CharacterCreationUI.h>

struct NameDescriptor { char* singular_; char* plural_; unsigned int flags_; };
struct StoreStruct { char pad0[0x20]; NameDescriptor* names_; };
struct TargetMenu {
    char pad0[0x1c];
    signed char selected_;
    char pad1D[0xb8 - 0x1d];
    Container020e0310 strings_;
#if defined(jpn)
    char padC0[0x1d94 - 0xc0];
    char nameSlots[8][0x38];
#else
    char padC0[0x1d1c - 0xc0];
#endif
    int groupIDs_[8];
    int combatantIDs_[8];
};

int CountMatchingValues02175348(void*, int);
StoreStruct* GetGlobalField0x1c020421a0();
int GetFieldByKey020e0434(Container020e0310*, int);
int IsField0x118Equal2_ov000_0217542c(void*);
int AppendFrameTag02041c08(char*, int, int, int, int, int);
int AppendCursorTag_02041ea4(char*, int);
int AppendString02042058(char*, const char*);
extern "C" void* __clear(void*, int);
extern "C" void func_02046380(StoreStruct*);
void* Clear12Bytes020e46c4(void*);
GameObject* GetCombatantWithFlag0x400_0200fea4(GameState*, int);
extern "C" void func_020e4ce8(NameDescriptor*, GameObject*, int);
void TrimTrailingLetterCode_0217aa08(char*, char*);
extern "C" void func_020e4f18(NameDescriptor*, NameDescriptor*, int);
void StoreInArray0x8b0_020465c0(StoreStruct*, int, int);
extern "C" void func_02046608(StoreStruct*, int, const char*, char*, int, int, int);
int AppendNameTag_02041b70(char*, int, const char*);
extern char data_ov000_02184060[];

#if defined(jpn)
extern "C" void func_0203bdf4(char*, char*);
extern "C" void _Z22SetIndexedName02046574P11Obj02046574iPc(StoreStruct*, int, char*);
extern "C" void func_020474a8(StoreStruct*, int, const char*, char*);
#endif

// USA: func_ov000_0217a688
extern "C" ARM void func_ov000_0217a688(TargetMenu* self, void* unused, int count, char* output) {
    if (!output) return;
    int cursor;
    unsigned int previous;
#if defined(jpn)
    bool separated;
#else
    int separated;
#endif
    int selected;
    int i;
    previous = -1;
    cursor = 0;
    separated = 0;
    i = 0;
    selected = self->selected_;
    for (; i < count; ++i) {
        int group = self->groupIDs_[i];
        if (previous == group) continue;
        previous = group;
        int members = CountMatchingValues02175348(self, group);
        if (i <= selected && selected < i + members) cursor = i;
    }
    StoreStruct* store = GetGlobalField0x1c020421a0();
#if !defined(jpn)
    GameState* game = GameState::GetInstance();
    const char* separator = (const char*)GetFieldByKey020e0434(&self->strings_, 0);
    const char* format = (const char*)GetFieldByKey020e0434(&self->strings_, 0x754f);
#endif
    previous = -1;
#if defined(jpn)
    int showCursor = IsField0x118Equal2_ov000_0217542c(self);
    if (showCursor)
#else
    if (IsField0x118Equal2_ov000_0217542c(self))
#endif
        AppendFrameTag02041c08(output, cursor, 8, 5, 5, 5);
    AppendCursorTag_02041ea4(output, cursor);
    for (int i = 0; i < count; ++i) {
        int group = self->groupIDs_[i];
        if (previous == group) continue;
        previous = group;
        int members = CountMatchingValues02175348(self, group);
        if (!members) continue;
#if defined(jpn)
        if (separated) AppendString02042058(output, (const char*)GetFieldByKey020e0434(&self->strings_, 0));
#else
        if (separated) AppendString02042058(output, separator);
#endif
#if defined(jpn)
        char nameText[0x20];
        __clear(nameText, sizeof(nameText));
        char text[0x40];
        __clear(text, sizeof(text));
#else
        char text[0x80];
        __clear(text, sizeof(text));
#endif
        int index = i;
        if (i <= selected && selected < i + members) index = selected;
#if defined(jpn)
        func_0203bdf4(self->nameSlots[index], nameText);
        if (showCursor && cursor == i) {
            char original[0x20];
            __clear(original, sizeof(original));
            memcpy(original, nameText, sizeof(original));
            memset(nameText, 0, sizeof(nameText));
            TrimTrailingLetterCode_0217aa08(original, nameText);
        }
        func_02046380(store);
        _Z22SetIndexedName02046574P11Obj02046574iPc(store, 0, nameText);
        StoreInArray0x8b0_020465c0(store, 0, members);
        func_020474a8(store, 10, (const char*)GetFieldByKey020e0434(&self->strings_, 0x754f), text);
#else
        func_02046380(store);
        NameDescriptor names;
        Clear12Bytes020e46c4(&names);
        GameObject* target = GetCombatantWithFlag0x400_0200fea4(game, self->combatantIDs_[index]);
        char singular[0x80];
        __clear(singular, sizeof(singular));
        char plural[0x80];
        __clear(plural, sizeof(plural));
        if (target) {
            func_020e4ce8(&names, target, 1);
            NameDescriptor original;
            func_020e4ce8(&original, target, 0);
            TrimTrailingLetterCode_0217aa08(names.singular_, singular);
            TrimTrailingLetterCode_0217aa08(names.plural_, plural);
            names.singular_ = singular;
            names.plural_ = plural;
            func_020e4f18(&original, &names, 2);
            names.flags_ &= ~0x80000000;
        }
        store->names_ = &names;
        StoreInArray0x8b0_020465c0(store, 0, members);
        func_02046608(store, 10, format, text, 0x100, 0, 0);
#endif
        AppendNameTag_02041b70(output, i, text);
        separated = 1;
    }
#if !defined(jpn)
    AppendString02042058(output, data_ov000_02184060);
#endif
}
