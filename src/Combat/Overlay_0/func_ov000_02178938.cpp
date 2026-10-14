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
int CountMatchingValues02175348(void*, int);
int IsField0x118Equal2_ov000_0217542c(void*);
StoreStruct* GetGlobalField0x1c020421a0();
int GetFieldByKey020e0434(Container020e0310*, int);
void AppendFrameTag02041c08(char*, int, int, int, int, int);
void AppendCursorTag_02041ea4(char*, int);
void AppendString02042058(char*, const char*);
extern "C" void __clear(void*, int);
extern "C" void func_02046380(StoreStruct*);
void Clear12Bytes020e46c4(void*);
GameObject* GetCombatantWithFlag0x400_0200fea4(GameState*, int);
extern "C" void func_020e4ce8(NameParts*, GameObject*, int);
void TrimTrailingLetterCode_0217aa08(char*, char*);
extern "C" void func_020e4f18(NameParts*, NameParts*, int);
void StoreInArray0x8b0_020465c0(StoreStruct*, int, int);
extern "C" void func_02046608(StoreStruct*, int, const char*, char*, int, int, int);
void AppendNameTag_02041b70(char*, int, const char*);
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
            int groupSize = CountMatchingValues02175348(menu, kind);
            if (i <= selected && selected < i + groupSize) selectedStart = i;
        }
    }
    int showCursor = IsField0x118Equal2_ov000_0217542c(menu);
    StoreStruct* formatter = GetGlobalField0x1c020421a0();
#if !defined(jpn)
    GameState* game = GameState::GetInstance();
    const char* separator = (const char*)GetFieldByKey020e0434((Container020e0310*)menu->messages, 0);
    const char* format = (const char*)GetFieldByKey020e0434((Container020e0310*)menu->messages, 0x754f);
#endif
    previous = -1;
    if (showCursor) {
        AppendFrameTag02041c08(output, selectedStart, 8, 5, 5, 5);
    }
    AppendCursorTag_02041ea4(output, selectedStart);
    for (int i = 0; i < count; i++) {
        int kind = menu->kinds[i];
        if (previous != kind) {
            previous = kind;
            int groupSize = CountMatchingValues02175348(menu, kind);
            if (groupSize) {
#if defined(jpn)
                if (appended) AppendString02042058(output, (const char*)GetFieldByKey020e0434((Container020e0310*)menu->messages, 0));
#else
                if (appended) AppendString02042058(output, separator);
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
                    TrimTrailingLetterCode_0217aa08(original, nameText);
                }
                func_02046380(formatter);
                _Z22SetIndexedName02046574P11Obj02046574iPc(formatter, 0, nameText);
                StoreInArray0x8b0_020465c0(formatter, 0, groupSize);
                func_020474a8(formatter, 10, (const char*)GetFieldByKey020e0434((Container020e0310*)menu->messages, 0x754f), text);
#else
                func_02046380(formatter);
                NameParts name;
                Clear12Bytes020e46c4(&name);
                GameObject* combatant = GetCombatantWithFlag0x400_0200fea4(game, menu->combatants[index]);
                char singular[128];
                char plural[128];
                __clear(singular, 128);
                __clear(plural, 128);
                if (combatant) {
                    func_020e4ce8(&name, combatant, 1);
                    NameParts unusedName;
                    func_020e4ce8(&unusedName, combatant, 0);
                    TrimTrailingLetterCode_0217aa08(name.singular, singular);
                    TrimTrailingLetterCode_0217aa08(name.plural, plural);
                    name.singular = singular;
                    name.plural = plural;
                    func_020e4f18(&unusedName, &name, 2);
                    name.flags &= ~0x80000000;
                }
                formatter->name = &name;
                StoreInArray0x8b0_020465c0(formatter, 0, groupSize);
                func_02046608(formatter, 10, format, text, 256, 0, 0);
#endif
                AppendNameTag_02041b70(output, i, text);
                appended = 1;
            }
        }
    }
#if !defined(jpn)
    AppendString02042058(output, data_ov000_02184060);
#endif
}
