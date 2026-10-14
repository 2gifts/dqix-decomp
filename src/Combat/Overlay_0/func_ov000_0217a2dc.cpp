#include <globaldefs.h>
#include "Resource/ActionDataTables.h"

struct Container020e0310;

int GetFieldByKey020e0434(struct Container020e0310* c, int key);
int AppendString02042058(char* dst, const char* src);
int IsField0x118Equal2(void* obj);
int AppendFrameTag02041c08(char* dst, int a1, int a2, int a3, int a4, int a5);

int AppendPaletteTag(char* dst, int palette);
const char** SearchBothTables02079e2c(char* table, int key);
int AppendCursorTag(char* dst, int cursor);
int AppendNameTag(char* dst, int n, const char* name);
extern "C" int func_020420e8(const char* text, int large);
int AppendXYTag(char* dst, int x, int y);
int AppendLineTag02041cc0(char* dst, int a1);
#if defined(jpn)
void* GetGlobalField0x1c020421a0();
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
    const char* emptyName = (const char*)GetFieldByKey020e0434(strings, 0x1f);
    const char* separator = (const char*)GetFieldByKey020e0434(strings, 0);
    signed char cursor = menu->cursor;
    AppendString02042058(dst, separator);

    if (menu->field1D81) {
        if (IsField0x118Equal2(menu)) {
            AppendFrameTag02041c08(dst, cursor, 8, 5, 5, 5);
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
                AppendString02042058(dst, emptyName);
            } else {
                const char** entry = SearchBothTables02079e2c((char*)table, (short)menu->itemIds[i]);
                if (entry == NULL) {
                    continue;
                }
#if defined(jpn)
                char name[0x40];
                __clear(name, sizeof(name));
                func_02041f50(*entry, name);
                AppendString02042058(dst, name);
#else
                AppendString02042058(dst, *entry);
#endif
            }
            if (i == menu->itemCount - 1) {
                continue;
            }
            AppendString02042058(dst, separator);
        }
    } else {
        if (IsField0x118Equal2(menu)) {
            AppendFrameTag02041c08(dst, cursor, 8, 5, 5, 5);
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
                const char** entry = SearchBothTables02079e2c((char*)table, (short)menu->itemIds[i]);
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
            AppendString02042058(dst, separator);
        }
    }

    AppendPaletteTag(dst, 0xf);
#if defined(jpn)
    void* formatter = GetGlobalField0x1c020421a0();
    func_02046380(formatter);
    _Z22SetIndexedName02046574P11Obj02046574iPc(formatter, 0,
        (const char*)GetFieldByKey020e0434(strings, 0x21));
    AppendString02042058(dst, data_ov000_021851af);
#else
    const char* title = (const char*)GetFieldByKey020e0434(strings, 0x21);
    AppendXYTag(dst, (0xb0 - func_020420e8(title, 0)) >> 1, 5);
    AppendString02042058(dst, title);
    AppendLineTag02041cc0(dst, 0x11);
#endif
}
