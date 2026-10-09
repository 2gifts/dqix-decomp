#include <globaldefs.h>
#include "GameState/GameState.h"

struct Container020e0310;

struct PartyInfo_021777e4 {
    char pad0[0xf7c];
    unsigned char memberCount;
};

struct MenuEntry_021777e4 {
    char pad0[0x24];
    unsigned char flags;
    char pad25[0x4c - 0x25];
    int memberIndex;
    char pad50[0x68 - 0x50];
    char nameSlot[0x448 - 0x68];
};

struct MemberInfo_021777e4 {
    char pad0[0x94c];
    int vocation;
};

struct Menu_021777e4 {
    char pad0[0x6c];
    signed char order[0xb8 - 0x6c];
    char strings[0x958 - 0xb8];
    MenuEntry_021777e4 entries[4];
    char pad[0x1d6b - 0x958 - 4 * 0x448];
    signed char cursor;
    char pad1d6c[0x1d74 - 0x1d6c];
    unsigned char choices[8];
};

int IsField0x118Equal2(void* obj);
int AppendFrameTag02041c08(char* dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag(char* dst, int cursor);
MemberInfo_021777e4* GetFieldAt0x150(unsigned char* obj);
extern "C" void __clear(void* dst, int size);
extern "C" int func_ov000_02170c7c(MenuEntry_021777e4* entry);
int FormatCombatLogSuffix02041dd0(char* dst, int value);
extern "C" void _Z25InvokeGlobalEntry0203c248Pci(char* slot, char* out);
int AppendNameTag(char* dst, int n, const char* name);
int AppendXTag(char* dst, int x);
const char* GetFieldByKey020e0434(struct Container020e0310* c, int key);
int AppendString02042058(char* dst, const char* src);
const char* CallFunc020e0434With02153694(int key);

static inline int IsPartyIndex(int i) {
    return i >= 0 && i <= 3;
}

// USA: func_ov000_021777e4
extern "C" ARM void func_ov000_021777e4(Menu_021777e4* menu, char* dst) {
    if (dst == NULL) return;

    MenuEntry_021777e4* entry;
    GameState* gs;
    int cursor;
    int n;
    PartyInfo_021777e4* party;
    unsigned char i;
    GameObject* obj;
    MemberInfo_021777e4* info;
    signed char vocation;
    char name[0x80];
    int member;

    gs = GameState::GetInstance();
    cursor = menu->cursor;
    n = 0;

    if (IsField0x118Equal2(menu)) {
        AppendFrameTag02041c08(dst, cursor, 8, 5, 5, 5);
    }
    AppendCursorTag(dst, cursor);

    party = (PartyInfo_021777e4*)GetPtrField0x2a04(gs);
    for (i = 0; i < party->memberCount; i++) {
        entry = &menu->entries[menu->order[i]];
        member = entry->memberIndex;
        if (!IsPartyIndex(member)) continue;
        if (entry->flags & 2) continue;

        obj = gs->GetPartyMemberByIndex(member);
        if (obj == NULL) return;
        info = GetFieldAt0x150((unsigned char*)obj);
        __clear(name, 0x80);
        vocation = info->vocation;

        FormatCombatLogSuffix02041dd0(dst, func_ov000_02170c7c(entry));
        _Z25InvokeGlobalEntry0203c248Pci(entry->nameSlot, name);
        AppendNameTag(dst, n, name);
        AppendXTag(dst, 0x4e);
        FormatCombatLogSuffix02041dd0(dst, 0);
        AppendString02042058(dst, GetFieldByKey020e0434((struct Container020e0310*)menu->strings, (short)(vocation + 0x753e)));
        AppendString02042058(dst, GetFieldByKey020e0434((struct Container020e0310*)menu->strings, 0));
        menu->choices[n] = member;
        n++;
    }
    menu->choices[n] = 4;
    AppendNameTag(dst, n, CallFunc020e0434With02153694(0x1a));
}
