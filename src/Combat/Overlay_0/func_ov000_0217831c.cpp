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
#if defined(jpn)
    unsigned char range[0x1dc7];
#else
    unsigned char range[0x1b8f];
#endif
    signed char currentCombatant;
    unsigned char unk1d6c[3];
    signed char cursor;
};

void ComputeProductSums0205c508(struct UnkStruct0205c508* s, int* first, int* last);
const char* GetFieldByKey020e0434(struct Container020e0310* c, int key);
struct ActiveSub02054000* GetActiveSub_02054000(struct Outer_02054000* p);
int IsField0x118Equal2(void* obj);
int AppendFrameTag02041c08(char* dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag(char* dst, int cursor);
struct ItemNameEntry* FindElementByKey020dedd0(struct Container020dedd0* c, int key);
void CopyTextAndUppercaseIfFlagged0206819c(const char* src, char* dst, int flag);
int AppendString02042058(char* dst, const char* src);
#if defined(jpn)
extern "C" int func_02042158(char* dst, int w);
#define AppendWidthTag func_02042158
#else
int AppendWidthTag(char* dst, int w);
#endif
int AppendNameTag(char* dst, int n, const char* name);
extern "C" void __clear(void* dst, unsigned int size);

// USA: func_ov000_0217831c
extern "C" ARM void func_ov000_0217831c(BattleItemMenu* menu, char* dst)
{
    int first;
    int last;
    ComputeProductSums0205c508((struct UnkStruct0205c508*)menu->range, &first, &last);
    signed char start = first;
    signed char end = last;
    struct Container020e0310* texts = (struct Container020e0310*)menu->textTable;
    const char* separator = GetFieldByKey020e0434(texts, 0);
    signed char cursor = menu->cursor;
    const char* unknownName = GetFieldByKey020e0434(texts, 5);
    int n = 0;
    signed char combatantId = menu->combatantIds[menu->currentCombatant];
    int selectedKey = -1;
    GameState* state = GameState::GetInstance();
    GameObject* combatant = GetCombatantWithFlag0x100(state, combatantId);
    struct ActiveSub02054000* sub = GetActiveSub_02054000((struct Outer_02054000*)combatant);
    if (sub != NULL) {
        selectedKey = sub->itemKey;
    }
    if (IsField0x118Equal2(menu)) {
        AppendFrameTag02041c08(dst, cursor - start, 8, 5, 5, 5);
    }
    AppendCursorTag(dst, cursor - start);
    for (signed char i = start; i < end; i++) {
        char line[0x40];
        __clear(line, sizeof(line));
        int key = menu->itemKeys[i];
        struct ItemNameEntry* item = FindElementByKey020dedd0((struct Container020dedd0*)menu->itemTable, key);
        const char* name = unknownName;
        if (item != NULL) {
#if defined(jpn)
            name = item->name;
#else
            char text[0x100];
            __clear(text, sizeof(text));
            CopyTextAndUppercaseIfFlagged0206819c(item->name, text, 0);
            name = text;
#endif
        }
        if (selectedKey == key) {
            AppendString02042058(line, GetFieldByKey020e0434(texts, 0x13));
#if !defined(jpn)
            AppendWidthTag(line, 3);
#endif
        } else {
            AppendWidthTag(line, 8);
        }
        AppendString02042058(line, name);
        AppendNameTag(dst, n, line);
        if (i != end - 1) {
            AppendString02042058(dst, separator);
        }
        n++;
    }
}
