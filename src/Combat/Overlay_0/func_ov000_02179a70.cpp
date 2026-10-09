#include <globaldefs.h>

struct Container020e0310;

int IsField0x118Equal2(void* obj);
extern "C" int _Z22AppendFrameTag02041c08Pciiiii(char* dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag(char* dst, int cursor);
extern "C" int _Z21GetFieldByKey020e0434P17Container020e0310i(struct Container020e0310* c, int key);
extern "C" int _Z20AppendString02042058PcPKc(char* dst, const char* src);
extern "C" int _Z29FormatCombatLogSuffix02041dd0Pci(char* buf, int index);
extern "C" void _Z25InvokeGlobalEntry0203c248Pci(char* obj, int arg1);
int AppendNameTag(char* dst, int n, const char* name);
extern "C" void __clear(void* buf, int n);

struct Member02179a70 {
    char pad[0x4c];
    int field_0x4c;
    char pad2[0x68 - 0x50];
    char name[0x448 - 0x68];
};

extern "C" int func_ov000_02170c7c(struct Member02179a70* obj);

struct Party02179a70 {
    char pad[0x74];
    signed char order[4];
    signed char count;
    char pad2[0xb8 - 0x79];
    char strings[0x958 - 0xb8];
    struct Member02179a70 members[1];
};

struct Cursor02179a70 {
    char pad[0x21];
    signed char cursor;
};

// USA: func_ov000_02179a70
extern "C" ARM void func_ov000_02179a70(struct Party02179a70* party, struct Cursor02179a70* src, int unused, char* dst) {
    if (src == NULL) return;

    signed char cursor = src->cursor;
    int n = 0;

    if (IsField0x118Equal2(party)) {
        _Z22AppendFrameTag02041c08Pciiiii(dst, cursor, 8, 5, 5, 5);
    }
    AppendCursorTag(dst, cursor);

    struct Member02179a70* m;
    for (int i = 0; i < party->count; i++) {
        m = &party->members[party->order[i]];
        if (m->field_0x4c >= 0) {
            if (n != 0) {
                _Z20AppendString02042058PcPKc(dst, (const char*)_Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310*)party->strings, 0));
            }
            _Z29FormatCombatLogSuffix02041dd0Pci(dst, func_ov000_02170c7c(m));
            char name[0x80];
            __clear(name, 0x80);
            _Z25InvokeGlobalEntry0203c248Pci(m->name, (int)name);
            AppendNameTag(dst, n, name);
            n++;
        }
    }
}
