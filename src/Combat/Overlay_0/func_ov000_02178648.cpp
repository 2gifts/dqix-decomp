#include <globaldefs.h>
#include "GameState/GameState.h"

struct Container020e0310;

int IsField0x118Equal2(void* obj);
int AppendFrameTag02041c08(char* dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag(char* dst, int cursor);
int FormatCombatLogSuffix02041dd0(char* dst, int kind);
int AppendNameTag(char* dst, int n, const char* name);
int AppendPaletteTag(char* dst, int palette);
int AppendXTag(char* dst, int x);
int GetFieldByKey020e0434(struct Container020e0310* c, int key);
int AppendString02042058(char* dst, const char* src);
extern "C" int func_ov000_02170c7c(void* entry);

struct MemberInfo02178648 {
    char pad0[0x3c];
    unsigned int pad3c_0 : 30;
    unsigned int flag30 : 1;
    unsigned int pad3c_31 : 1;
};

struct Entry02178648 {
    char pad0[0x4c];
    int field4c;
#if defined(jpn)
    char pad1[0x488 - 0x50];
#else
    char pad1[0x448 - 0x50];
#endif
};

// USA: func_ov000_02178648
extern "C" ARM void func_ov000_02178648(char* obj, char* dst) {
    if (dst == NULL) return;

#if defined(jpn)
    signed char cursor = *(signed char*)(obj + 0x1fa3);
#else
    signed char cursor = *(signed char*)(obj + 0x1d6b);
#endif
    int n = 0;
    unsigned char count;
    GameState* gs = GameState::GetInstance();
    GetPtrField0x2a04(gs);

    if (IsField0x118Equal2(obj)) {
        AppendFrameTag02041c08(dst, cursor, 8, 5, 5, 5);
    }
    AppendCursorTag(dst, cursor);

    count = *(unsigned char*)(obj + 0x79);
    for (unsigned char i = 0; i < count; i++) {
        struct Entry02178648* entry = &((struct Entry02178648*)(obj + 0x958))[*(signed char*)(obj + i + 0x70)];
        GameObject* member = gs->GetPartyMemberByIndex((signed char)entry->field4c);
        if (member != NULL) {
            FormatCombatLogSuffix02041dd0(dst, func_ov000_02170c7c(entry));
            AppendNameTag(dst, n, (const char*)member->baseStats_);
            AppendPaletteTag(dst, 0xf);
            AppendXTag(dst, 0x46);
            struct MemberInfo02178648* info = (struct MemberInfo02178648*)member->baseStats_;
            AppendString02042058(dst, (const char*)GetFieldByKey020e0434((struct Container020e0310*)(obj + 0xb8), (short)((unsigned short)info->flag30 + 0x7551)));
            if (i != count - 1) {
                AppendString02042058(dst, (const char*)GetFieldByKey020e0434((struct Container020e0310*)(obj + 0xb8), 0));
            }
        }
        n++;
    }
#if !defined(jpn)
    AppendXTag(dst, 0x7a);
#endif
}
