#include <globaldefs.h>
#include <GameState/GameState.h>

struct Element020e0310;
struct Container020e0310 { unsigned int count : 12; unsigned int rest : 20; Element020e0310* base; };
struct NameDescriptor { char* singular_; char* plural_; unsigned int flags_; };
struct StoreStruct { char pad0[0x20]; NameDescriptor* names_; };
struct TargetMenu {
    char pad0[0x1c];
    signed char selected_;
    char pad1D[0xb8 - 0x1d];
    Container020e0310 strings_;
    char padC0[0x1d1c - 0xc0];
    int groupIDs_[8];
    int combatantIDs_[8];
};

extern "C" int _Z27CountMatchingValues02175348Pvi(void*, int);
extern "C" StoreStruct* _Z26GetGlobalField0x1c020421a0v();
extern "C" int _Z21GetFieldByKey020e0434P17Container020e0310i(Container020e0310*, int);
int IsField0x118Equal2(void*);
extern "C" int _Z22AppendFrameTag02041c08Pciiiii(char*, int, int, int, int, int);
int AppendCursorTag(char*, int);
extern "C" int _Z20AppendString02042058PcPKc(char*, const char*);
extern "C" void* __clear(void*, int);
extern "C" void func_02046380(StoreStruct*);
extern "C" void* _Z20Clear12Bytes020e46c4Pv(void*);
GameObject* GetCombatantWithFlag0x400(GameState*, int);
extern "C" void func_020e4ce8(NameDescriptor*, GameObject*, int);
extern "C" void _Z31TrimTrailingLetterCode_0217aa08PcS_(char*, char*);
extern "C" void func_020e4f18(NameDescriptor*, NameDescriptor*, int);
void StoreInArray0x8b0(StoreStruct*, int, int);
extern "C" void func_02046608(StoreStruct*, int, const char*, char*, int, int, int);
int AppendNameTag(char*, int, const char*);
extern char data_ov000_02184060[];

// USA: func_ov000_0217a688
extern "C" ARM void func_ov000_0217a688(TargetMenu* self, void* unused, int count, char* output) {
    if (!output) return;
    int cursor;
    unsigned int previous;
    int separated;
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
        int members = _Z27CountMatchingValues02175348Pvi(self, group);
        if (i <= selected && selected < i + members) cursor = i;
    }
    StoreStruct* store = _Z26GetGlobalField0x1c020421a0v();
    GameState* game = GameState::GetInstance();
    const char* separator = (const char*)_Z21GetFieldByKey020e0434P17Container020e0310i(&self->strings_, 0);
    const char* format = (const char*)_Z21GetFieldByKey020e0434P17Container020e0310i(&self->strings_, 0x754f);
    previous = -1;
    if (IsField0x118Equal2(self)) _Z22AppendFrameTag02041c08Pciiiii(output, cursor, 8, 5, 5, 5);
    AppendCursorTag(output, cursor);
    for (i = 0; i < count; ++i) {
        int group = self->groupIDs_[i];
        if (previous == group) continue;
        previous = group;
        int members = _Z27CountMatchingValues02175348Pvi(self, group);
        if (!members) continue;
        if (separated) _Z20AppendString02042058PcPKc(output, separator);
        char text[0x80];
        __clear(text, sizeof(text));
        int index = i;
        if (i <= selected && selected < i + members) index = selected;
        func_02046380(store);
        NameDescriptor names;
        _Z20Clear12Bytes020e46c4Pv(&names);
        GameObject* target = GetCombatantWithFlag0x400(game, self->combatantIDs_[index]);
        char singular[0x80];
        __clear(singular, sizeof(singular));
        char plural[0x80];
        __clear(plural, sizeof(plural));
        if (target) {
            func_020e4ce8(&names, target, 1);
            NameDescriptor original;
            func_020e4ce8(&original, target, 0);
            _Z31TrimTrailingLetterCode_0217aa08PcS_(names.singular_, singular);
            _Z31TrimTrailingLetterCode_0217aa08PcS_(names.plural_, plural);
            names.singular_ = singular;
            names.plural_ = plural;
            func_020e4f18(&original, &names, 2);
            names.flags_ &= ~0x80000000;
        }
        store->names_ = &names;
        StoreInArray0x8b0(store, 0, members);
        func_02046608(store, 10, format, text, 0x100, 0, 0);
        AppendNameTag(output, i, text);
        separated = 1;
    }
    _Z20AppendString02042058PcPKc(output, data_ov000_02184060);
}
