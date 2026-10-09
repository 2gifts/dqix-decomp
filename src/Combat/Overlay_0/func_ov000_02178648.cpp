#include <globaldefs.h>
#include "GameState/GameState.h"

struct Container020e0310;

int IsField0x118Equal2(void* obj);
extern "C" int _Z22AppendFrameTag02041c08Pciiiii(char* dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag(char* dst, int cursor);
extern "C" int _Z29FormatCombatLogSuffix02041dd0Pci(char* dst, int kind);
int AppendNameTag(char* dst, int n, const char* name);
int AppendPaletteTag(char* dst, int palette);
int AppendXTag(char* dst, int x);
extern "C" int _Z21GetFieldByKey020e0434P17Container020e0310i(struct Container020e0310* c, int key);
extern "C" int _Z20AppendString02042058PcPKc(char* dst, const char* src);
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
    char pad1[0x448 - 0x50];
};

// USA: func_ov000_02178648
extern "C" ARM void func_ov000_02178648(char* obj, char* dst) {
    if (dst == NULL) return;

    signed char cursor = *(signed char*)(obj + 0x1d6b);
    int n = 0;
    unsigned char count;
    GameState* gs = GameState::GetInstance();
    GetPtrField0x2a04(gs);

    if (IsField0x118Equal2(obj)) {
        _Z22AppendFrameTag02041c08Pciiiii(dst, cursor, 8, 5, 5, 5);
    }
    AppendCursorTag(dst, cursor);

    count = *(unsigned char*)(obj + 0x79);
    for (unsigned char i = 0; i < count; i++) {
        struct Entry02178648* entry = &((struct Entry02178648*)(obj + 0x958))[*(signed char*)(obj + i + 0x70)];
        GameObject* member = gs->GetPartyMemberByIndex((signed char)entry->field4c);
        if (member != NULL) {
            _Z29FormatCombatLogSuffix02041dd0Pci(dst, func_ov000_02170c7c(entry));
            AppendNameTag(dst, n, (const char*)member->baseStats_);
            AppendPaletteTag(dst, 0xf);
            AppendXTag(dst, 0x46);
            struct MemberInfo02178648* info = (struct MemberInfo02178648*)member->baseStats_;
            _Z20AppendString02042058PcPKc(dst, (const char*)_Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310*)(obj + 0xb8), (short)((unsigned short)info->flag30 + 0x7551)));
            if (i != count - 1) {
                _Z20AppendString02042058PcPKc(dst, (const char*)_Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310*)(obj + 0xb8), 0));
            }
        }
        n++;
    }
    AppendXTag(dst, 0x7a);
}
