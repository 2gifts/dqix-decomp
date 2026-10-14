#include <globaldefs.h>
#include "Resource/ActionDataTables.h"

struct Container020e0310;

extern "C" int _Z21GetFieldByKey020e0434P17Container020e0310i(struct Container020e0310* c, int key);
extern "C" int _Z20AppendString02042058PcPKc(char* dst, const char* src);
int IsField0x118Equal2(void* obj);
extern "C" int _Z22AppendFrameTag02041c08Pciiiii(char* dst, int a1, int a2, int a3, int a4, int a5);

int AppendPaletteTag(char* dst, int palette);
extern "C" const char** _Z24SearchBothTables02079e2cPci(char* table, int key);
int AppendCursorTag(char* dst, int cursor);
int AppendNameTag(char* dst, int n, const char* name);
extern "C" int func_020420e8(const char* text, int large);
int AppendXYTag(char* dst, int x, int y);
extern "C" int _Z21AppendLineTag02041cc0Pci(char* dst, int a1);
#if defined(jpn)
extern "C" void* _Z26GetGlobalField0x1c020421a0v();
extern "C" void func_02046380(void*);
extern "C" void _Z22SetIndexedName02046574P11Obj02046574iPc(void*, int, const char*);
extern "C" void __clear(void*, int);
extern "C" void func_02041f50(const char*, char*);
extern char data_ov000_021851af[];
#endif

struct ItemMenu0217a2dc {
    char pad0[0x10];
    unsigned short itemIds[5];
    signed char itemCount;
#if defined(jpn)
    char pad1B[0x1fa5 - 0x1b];
#else
    char pad1B[0x1d6d - 0x1b];
#endif
    signed char cursor;
    char pad1D6E[0x1d81 - 0x1d6e];
    unsigned char field1D81;
};

// USA: func_ov000_0217a2dc
extern "C" ARM void func_ov000_0217a2dc(struct ItemMenu0217a2dc* menu, int unused, char* dst) {
    struct Container020e0310* strings = (struct Container020e0310*)((char*)menu + 0xb8);
    const char* emptyName = (const char*)_Z21GetFieldByKey020e0434P17Container020e0310i(strings, 0x1f);
    const char* separator = (const char*)_Z21GetFieldByKey020e0434P17Container020e0310i(strings, 0);
    signed char cursor = menu->cursor;
    _Z20AppendString02042058PcPKc(dst, separator);

    if (menu->field1D81) {
        if (IsField0x118Equal2(menu)) {
            _Z22AppendFrameTag02041c08Pciiiii(dst, cursor, 8, 5, 5, 5);
        }
        ActionDataTables* table = GetData02108e10();
        if (table == NULL) {
            return;
        }
        for (int i = 0; i < menu->itemCount; i++) {
#if defined(jpn)
            if (i == cursor) {
                AppendPaletteTag(dst, 5);
            } else {
                AppendPaletteTag(dst, 3);
            }
#else
            int palette = 3;
            if (i == cursor) {
                palette = 5;
            }
            AppendPaletteTag(dst, palette);
#endif
            if (menu->itemIds[i] == 0) {
                _Z20AppendString02042058PcPKc(dst, emptyName);
            } else {
                const char** entry = _Z24SearchBothTables02079e2cPci((char*)table, (short)menu->itemIds[i]);
                if (entry == NULL) {
                    continue;
                }
#if defined(jpn)
                char name[0x40];
                __clear(name, sizeof(name));
                func_02041f50(*entry, name);
                _Z20AppendString02042058PcPKc(dst, name);
#else
                _Z20AppendString02042058PcPKc(dst, *entry);
#endif
            }
            if (i == menu->itemCount - 1) {
                continue;
            }
            _Z20AppendString02042058PcPKc(dst, separator);
        }
    } else {
        if (IsField0x118Equal2(menu)) {
            _Z22AppendFrameTag02041c08Pciiiii(dst, cursor, 8, 5, 5, 5);
        }
        AppendCursorTag(dst, cursor);
        ActionDataTables* table = GetData02108e10();
        if (table == NULL) {
            return;
        }
        for (int i = 0; i < menu->itemCount; i++) {
            if (menu->itemIds[i] == 0) {
                AppendNameTag(dst, i, emptyName);
            } else {
                const char** entry = _Z24SearchBothTables02079e2cPci((char*)table, (short)menu->itemIds[i]);
                if (entry == NULL) {
                    continue;
                }
#if defined(jpn)
                char name[0x40];
                __clear(name, sizeof(name));
                func_02041f50(*entry, name);
                AppendNameTag(dst, i, name);
#else
                AppendNameTag(dst, i, *entry);
#endif
            }
            if (i == menu->itemCount - 1) {
                continue;
            }
            _Z20AppendString02042058PcPKc(dst, separator);
        }
    }

    AppendPaletteTag(dst, 0xf);
#if defined(jpn)
    void* formatter = _Z26GetGlobalField0x1c020421a0v();
    func_02046380(formatter);
    _Z22SetIndexedName02046574P11Obj02046574iPc(formatter, 0,
        (const char*)_Z21GetFieldByKey020e0434P17Container020e0310i(strings, 0x21));
    _Z20AppendString02042058PcPKc(dst, data_ov000_021851af);
#else
    const char* title = (const char*)_Z21GetFieldByKey020e0434P17Container020e0310i(strings, 0x21);
    AppendXYTag(dst, (0xb0 - func_020420e8(title, 0)) >> 1, 5);
    _Z20AppendString02042058PcPKc(dst, title);
    _Z21AppendLineTag02041cc0Pci(dst, 0x11);
#endif
}
