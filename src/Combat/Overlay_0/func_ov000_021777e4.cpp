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
#if defined(jpn)
    char pad50[0x88 - 0x50];
    char nameSlot[0x488 - 0x88];
#else
    char pad50[0x68 - 0x50];
    char nameSlot[0x448 - 0x68];
#endif
};

struct MemberInfo_021777e4 {
#if defined(jpn)
    char pad0[0x8b4];
#else
    char pad0[0x94c];
#endif
    int vocation;
};

struct Menu_021777e4 {
    char pad0[0x6c];
    signed char order[0xb8 - 0x6c];
    char strings[0x958 - 0xb8];
    MenuEntry_021777e4 entries[4];
#if defined(jpn)
    char pad[0x1fa3 - 0x958 - 4 * 0x488];
#else
    char pad[0x1d6b - 0x958 - 4 * 0x448];
#endif
    signed char cursor;
    char pad1d6c[0x1d74 - 0x1d6c];
    unsigned char choices[8];
};

int IsField0x118Equal2_ov000_0217542c(void* obj);
int AppendFrameTag02041c08(char* dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag_02041ea4(char* dst, int cursor);
MemberInfo_021777e4* GetFieldAt0x150_02053c6c(unsigned char* obj);
extern "C" void __clear(void* dst, int size);
extern "C" int func_ov000_02170c7c(MenuEntry_021777e4* entry);
int FormatCombatLogSuffix02041dd0(char* dst, int value);
#if defined(jpn)
extern "C" void func_0203bdf4(char* slot, char* out);
#define _Z25InvokeGlobalEntry0203c248Pci func_0203bdf4
#else
extern "C" void _Z25InvokeGlobalEntry0203c248Pci(char* slot, char* out);
#endif
int AppendNameTag_02041b70(char* dst, int n, const char* name);
int AppendXTag_02041a28(char* dst, int x);
const char* GetFieldByKey020e0434(struct Container020e0310* c, int key);
int AppendString02042058(char* dst, const char* src);
const char* CallFunc020e0434With02153694_020e51cc(int key);
#if defined(jpn)
extern char data_ov000_02185160[];
#endif

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
#if defined(jpn)
    char name[0x20];
#else
    char name[0x80];
#endif
    int member;

    gs = GameState::GetInstance();
    cursor = menu->cursor;
    n = 0;

    if (IsField0x118Equal2_ov000_0217542c(menu)) {
        AppendFrameTag02041c08(dst, cursor, 8, 5, 5, 5);
    }
    AppendCursorTag_02041ea4(dst, cursor);

    party = (PartyInfo_021777e4*)GetPtrField0x2a04_02010828(gs);
    for (i = 0; i < party->memberCount; i++) {
        entry = &menu->entries[menu->order[i]];
        member = entry->memberIndex;
        if (!IsPartyIndex(member)) continue;
        if (entry->flags & 2) continue;

        obj = gs->GetPartyMemberByIndex(member);
        if (obj == NULL) return;
        info = GetFieldAt0x150_02053c6c((unsigned char*)obj);
        __clear(name, sizeof(name));
        vocation = info->vocation;

        FormatCombatLogSuffix02041dd0(dst, func_ov000_02170c7c(entry));
        _Z25InvokeGlobalEntry0203c248Pci(entry->nameSlot, name);
        AppendNameTag_02041b70(dst, n, name);
        AppendXTag_02041a28(dst, 0x4e);
        FormatCombatLogSuffix02041dd0(dst, 0);
        AppendString02042058(dst, GetFieldByKey020e0434((struct Container020e0310*)menu->strings, (short)(vocation + 0x753e)));
        AppendString02042058(dst, GetFieldByKey020e0434((struct Container020e0310*)menu->strings, 0));
        menu->choices[n] = member;
        n++;
    }
    menu->choices[n] = 4;
#if defined(jpn)
    AppendNameTag_02041b70(dst, n, data_ov000_02185160);
#else
    AppendNameTag_02041b70(dst, n, CallFunc020e0434With02153694_020e51cc(0x1a));
#endif
}
