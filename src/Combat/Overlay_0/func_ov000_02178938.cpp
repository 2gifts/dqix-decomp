#include <globaldefs.h>
#include <GameState/GameState.h>

struct Container020e0310;
struct NameParts { char* singular; char* plural; unsigned int flags; };
struct StoreStruct { char pad[0x20]; NameParts* name; };
#if defined(jpn)
struct TargetMenu { char pad0[0xb8]; char messages[0x20]; char pad1[0x1d94 - 0xd8]; char nameSlots[8][0x38]; int kinds[8]; int combatants[8]; };
#else
struct TargetMenu { char pad0[0xb8]; char messages[0x20]; char pad1[0x1c44]; int kinds[8]; int combatants[8]; };
#endif
struct TargetSelection { char pad[0x1d]; signed char index; };
extern "C" int _Z27CountMatchingValues02175348Pvi(void*, int);
int IsField0x118Equal2(void*);
extern "C" StoreStruct* _Z26GetGlobalField0x1c020421a0v();
extern "C" int _Z21GetFieldByKey020e0434P17Container020e0310i(Container020e0310*, int);
extern "C" void _Z22AppendFrameTag02041c08Pciiiii(char*, int, int, int, int, int);
void AppendCursorTag(char*, int);
extern "C" void _Z20AppendString02042058PcPKc(char*, const char*);
extern "C" void __clear(void*, int);
extern "C" void func_02046380(StoreStruct*);
extern "C" void _Z20Clear12Bytes020e46c4Pv(void*);
GameObject* GetCombatantWithFlag0x400(GameState*, int);
extern "C" void func_020e4ce8(NameParts*, GameObject*, int);
extern "C" void _Z31TrimTrailingLetterCode_0217aa08PcS_(char*, char*);
extern "C" void func_020e4f18(NameParts*, NameParts*, int);
void StoreInArray0x8b0(StoreStruct*, int, int);
extern "C" void func_02046608(StoreStruct*, int, const char*, char*, int, int, int);
void AppendNameTag(char*, int, const char*);
extern const char data_ov000_02184060[];

#if defined(jpn)
extern "C" void func_0203bdf4(char*, char*);
extern "C" void _Z22SetIndexedName02046574P11Obj02046574iPc(StoreStruct*, int, char*);
extern "C" void func_020474a8(StoreStruct*, int, const char*, char*);
#endif

// USA: func_ov000_02178938
extern "C" ARM void func_ov000_02178938(TargetMenu* menu, TargetSelection* selection, int count, char* output) {
    if (!output) return;
    int previous = -1;
#if defined(jpn)
    int selectedStart;
    int appended;
    appended = 0;
    selectedStart = 0;
#else
    int selectedStart = 0;
    int appended = 0;
#endif
    int selected = selection->index;
    for (int i = 0; i < count; i++) {
        int kind = menu->kinds[i];
        if (previous != kind) {
            previous = kind;
            int groupSize = _Z27CountMatchingValues02175348Pvi(menu, kind);
            if (i <= selected && selected < i + groupSize) selectedStart = i;
        }
    }
    int showCursor = IsField0x118Equal2(menu);
    StoreStruct* formatter = _Z26GetGlobalField0x1c020421a0v();
#if !defined(jpn)
    GameState* game = GameState::GetInstance();
    const char* separator = (const char*)_Z21GetFieldByKey020e0434P17Container020e0310i((Container020e0310*)menu->messages, 0);
    const char* format = (const char*)_Z21GetFieldByKey020e0434P17Container020e0310i((Container020e0310*)menu->messages, 0x754f);
#endif
    previous = -1;
    if (showCursor) {
        _Z22AppendFrameTag02041c08Pciiiii(output, selectedStart, 8, 5, 5, 5);
    }
    AppendCursorTag(output, selectedStart);
    for (int i = 0; i < count; i++) {
        int kind = menu->kinds[i];
        if (previous != kind) {
            previous = kind;
            int groupSize = _Z27CountMatchingValues02175348Pvi(menu, kind);
            if (groupSize) {
#if defined(jpn)
                if (appended) _Z20AppendString02042058PcPKc(output, (const char*)_Z21GetFieldByKey020e0434P17Container020e0310i((Container020e0310*)menu->messages, 0));
#else
                if (appended) _Z20AppendString02042058PcPKc(output, separator);
#endif
#if defined(jpn)
                char nameText[0x20];
                __clear(nameText, sizeof(nameText));
                char text[0x40];
                __clear(text, sizeof(text));
#else
                char text[128];
                __clear(text, 128);
#endif
                int index = i;
                if (i <= selected && selected < i + groupSize) index = selected;
#if defined(jpn)
                func_0203bdf4(menu->nameSlots[index], nameText);
                if (showCursor && selectedStart == i) {
                    char original[0x20];
                    __clear(original, sizeof(original));
                    memcpy(original, nameText, sizeof(original));
                    memset(nameText, 0, sizeof(nameText));
                    _Z31TrimTrailingLetterCode_0217aa08PcS_(original, nameText);
                }
                func_02046380(formatter);
                _Z22SetIndexedName02046574P11Obj02046574iPc(formatter, 0, nameText);
                StoreInArray0x8b0(formatter, 0, groupSize);
                func_020474a8(formatter, 10, (const char*)_Z21GetFieldByKey020e0434P17Container020e0310i((Container020e0310*)menu->messages, 0x754f), text);
#else
                func_02046380(formatter);
                NameParts name;
                _Z20Clear12Bytes020e46c4Pv(&name);
                GameObject* combatant = GetCombatantWithFlag0x400(game, menu->combatants[index]);
                char singular[128];
                char plural[128];
                __clear(singular, 128);
                __clear(plural, 128);
                if (combatant) {
                    func_020e4ce8(&name, combatant, 1);
                    NameParts unusedName;
                    func_020e4ce8(&unusedName, combatant, 0);
                    _Z31TrimTrailingLetterCode_0217aa08PcS_(name.singular, singular);
                    _Z31TrimTrailingLetterCode_0217aa08PcS_(name.plural, plural);
                    name.singular = singular;
                    name.plural = plural;
                    func_020e4f18(&unusedName, &name, 2);
                    name.flags &= ~0x80000000;
                }
                formatter->name = &name;
                StoreInArray0x8b0(formatter, 0, groupSize);
                func_02046608(formatter, 10, format, text, 256, 0, 0);
#endif
                AppendNameTag(output, i, text);
                appended = 1;
            }
        }
    }
#if !defined(jpn)
    _Z20AppendString02042058PcPKc(output, data_ov000_02184060);
#endif
}
