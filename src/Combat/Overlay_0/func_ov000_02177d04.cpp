#include <globaldefs.h>
#include "GameState/GameState.h"

struct Container020e0310;
struct Outer_02054000;

struct ActiveSub_02054000 {
    int unk_0;
    const char* name;
};

void* GetPtrField0x2a04(GameState* battleStruct);
extern "C" int _Z21GetFieldByKey020e0434P17Container020e0310i(struct Container020e0310* c, int key);
int IsField0x118Equal2(void* obj);
extern "C" int _Z22AppendFrameTag02041c08Pciiiii(char* dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag(char* dst, int cursor);
extern "C" void* func_ov000_02161318(void* obj, int index);
GameObject* GetCombatantWithFlag0x100(GameState* gameState, int combatantId);
extern "C" int func_ov000_02170c7c(void* obj);
extern "C" int _Z29FormatCombatLogSuffix02041dd0Pci(char* dst, int code);
int AppendNameTag(char* dst, int n, const char* name);
int AppendXTag(char* dst, int x);
extern "C" ActiveSub_02054000* _Z21GetActiveSub_02054000P14Outer_02054000(struct Outer_02054000* p);
extern "C" void* __clear(void* dst, int count);
extern "C" void _Z37CopyTextAndUppercaseIfFlagged0206819cPKcPci(const char* src, char* dst, int flag);
extern "C" int _Z20AppendString02042058PcPKc(char* dst, const char* src);

// USA: func_ov000_02177d04
extern "C" ARM void func_ov000_02177d04(char* base, char* dst) {
    GameState* gs = GameState::GetInstance();
    unsigned char count = *((unsigned char*)GetPtrField0x2a04(gs) + 0xf7c);
    const char* sep = (const char*)_Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310*)(base + 0xb8), 0);
    signed char cursor = *(signed char*)(base + 0x1d00 + 0x6b);

    if (IsField0x118Equal2(base)) {
        _Z22AppendFrameTag02041c08Pciiiii(dst, cursor, 8, 5, 5, 5);
    }
    AppendCursorTag(dst, cursor);

    for (unsigned char i = 0; i < count; i++) {
        signed char id = *(signed char*)(base + 0x70 + i);
        void* entry = func_ov000_02161318(base, id);
        if (entry == 0) {
            continue;
        }
        GameObject* combatant = GetCombatantWithFlag0x100(gs, id);
        if (combatant == 0) {
            continue;
        }
        _Z29FormatCombatLogSuffix02041dd0Pci(dst, func_ov000_02170c7c(entry));
        AppendNameTag(dst, i, combatant->baseStats_->unk);
        AppendXTag(dst, 0x46);
        _Z29FormatCombatLogSuffix02041dd0Pci(dst, 0);
        ActiveSub_02054000* sub = _Z21GetActiveSub_02054000P14Outer_02054000((struct Outer_02054000*)combatant);
        if (sub != 0) {
            char text[0x100];
            __clear(text, 0x100);
            _Z37CopyTextAndUppercaseIfFlagged0206819cPKcPci(sub->name, text, 0);
            _Z20AppendString02042058PcPKc(dst, text);
        }
        if (i != count - 1) {
            _Z20AppendString02042058PcPKc(dst, sep);
        }
    }
}
