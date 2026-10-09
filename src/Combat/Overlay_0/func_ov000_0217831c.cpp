#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Combat/Main/BattleList.h>

struct UnkStruct0205c508;
struct Container020e0310;
struct Container020dedd0;
struct Outer_02054000;
struct ItemNameEntry {
    unsigned int id;
    const char* name;
};
struct ActiveSub02054000 {
    unsigned char unk00[0x18];
    short itemKey;
};

struct BattleItemMenu {
    unsigned char unk0000[0x26];
    short itemKeys[37];
    signed char combatantIds[0x48];
    unsigned char textTable[0x48];
    unsigned char itemTable[0xdc];
    unsigned char range[0x1b8f];
    signed char currentCombatant;
    unsigned char unk1d6c[3];
    signed char cursor;
};

extern "C" void _Z26ComputeProductSums0205c508P17UnkStruct0205c508PiS1_(struct UnkStruct0205c508* s, int* first, int* last);
extern "C" const char* _Z21GetFieldByKey020e0434P17Container020e0310i(struct Container020e0310* c, int key);
extern "C" struct ActiveSub02054000* _Z21GetActiveSub_02054000P14Outer_02054000(struct Outer_02054000* p);
int IsField0x118Equal2(void* obj);
extern "C" int _Z22AppendFrameTag02041c08Pciiiii(char* dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag(char* dst, int cursor);
extern "C" struct ItemNameEntry* _Z24FindElementByKey020dedd0P17Container020dedd0i(struct Container020dedd0* c, int key);
extern "C" void _Z37CopyTextAndUppercaseIfFlagged0206819cPKcPci(const char* src, char* dst, int flag);
extern "C" int _Z20AppendString02042058PcPKc(char* dst, const char* src);
int AppendWidthTag(char* dst, int w);
int AppendNameTag(char* dst, int n, const char* name);
extern "C" void __clear(void* dst, unsigned int size);

// USA: func_ov000_0217831c
extern "C" ARM void func_ov000_0217831c(BattleItemMenu* menu, char* dst)
{
    int first;
    int last;
    _Z26ComputeProductSums0205c508P17UnkStruct0205c508PiS1_((struct UnkStruct0205c508*)menu->range, &first, &last);
    signed char start = first;
    signed char end = last;
    struct Container020e0310* texts = (struct Container020e0310*)menu->textTable;
    const char* separator = _Z21GetFieldByKey020e0434P17Container020e0310i(texts, 0);
    signed char cursor = menu->cursor;
    const char* unknownName = _Z21GetFieldByKey020e0434P17Container020e0310i(texts, 5);
    int n = 0;
    signed char combatantId = menu->combatantIds[menu->currentCombatant];
    int selectedKey = -1;
    GameState* state = GameState::GetInstance();
    GameObject* combatant = GetCombatantWithFlag0x100(state, combatantId);
    struct ActiveSub02054000* sub = _Z21GetActiveSub_02054000P14Outer_02054000((struct Outer_02054000*)combatant);
    if (sub != NULL) {
        selectedKey = sub->itemKey;
    }
    if (IsField0x118Equal2(menu)) {
        _Z22AppendFrameTag02041c08Pciiiii(dst, cursor - start, 8, 5, 5, 5);
    }
    AppendCursorTag(dst, cursor - start);
    for (signed char i = start; i < end; i++) {
        char line[0x40];
        __clear(line, sizeof(line));
        short key = menu->itemKeys[i];
        struct ItemNameEntry* item = _Z24FindElementByKey020dedd0P17Container020dedd0i((struct Container020dedd0*)menu->itemTable, key);
        const char* name = unknownName;
        if (item != NULL) {
            char text[0x100];
            __clear(text, sizeof(text));
            _Z37CopyTextAndUppercaseIfFlagged0206819cPKcPci(item->name, text, 0);
            name = text;
        }
        if (selectedKey == key) {
            _Z20AppendString02042058PcPKc(line, _Z21GetFieldByKey020e0434P17Container020e0310i(texts, 0x13));
            AppendWidthTag(line, 3);
        } else {
            AppendWidthTag(line, 8);
        }
        _Z20AppendString02042058PcPKc(line, name);
        AppendNameTag(dst, n, line);
        if (i != end - 1) {
            _Z20AppendString02042058PcPKc(dst, separator);
        }
        n++;
    }
}
