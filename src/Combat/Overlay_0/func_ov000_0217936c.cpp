#include <globaldefs.h>

struct UnkStruct0205c508;
struct Container020e0310;

struct ListMenu {
    char pad0[0x1e];
    short cursor;
};

struct ListWindow {
    char pad0[0xb8];
    char texts[0x1dc - 0xb8];
    char scroll[4];
};

extern "C" void _Z26ComputeProductSums0205c508P17UnkStruct0205c508PiS1_(struct UnkStruct0205c508* s, int* out1, int* out2);
int IsField0x118Equal2(void* obj);
extern "C" int _Z22AppendFrameTag02041c08Pciiiii(char* dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag(char* dst, int cursor);
extern "C" int* _Z27GetBoundedField420_0217199cPvi(void* obj, int index);
extern "C" int _Z20IsBitFlagSet0217c4e8Pvi(void* obj, int index);
int AppendPaletteTag(char* dst, int palette);
extern "C" void __clear(void* buf, int size);
extern "C" void func_020e4864(int id, char* dst, int a, int b, int c, int d);
extern "C" void _Z37CopyTextAndUppercaseIfFlagged0206819cPKcPci(const char* src, char* dst, int flag);
int AppendNameTag(char* dst, int n, const char* name);
extern "C" int _Z21GetFieldByKey020e0434P17Container020e0310i(struct Container020e0310* c, int key);
extern "C" int _Z20AppendString02042058PcPKc(char* dst, const char* src);

// USA: func_ov000_0217936c
extern "C" ARM void func_ov000_0217936c(struct ListWindow* window, struct ListMenu* menu, char* dst) {
    char name[0x80];
    char upper[0x80];
    int first;
    int last;
    if (menu == NULL || dst == NULL) {
        return;
    }
    _Z26ComputeProductSums0205c508P17UnkStruct0205c508PiS1_((struct UnkStruct0205c508*)window->scroll, &first, &last);
    short top = first;
    short end = last;
    short cursor = menu->cursor;
    if (IsField0x118Equal2(window)) {
        _Z22AppendFrameTag02041c08Pciiiii(dst, cursor - top, 8, 5, 5, 5);
    }
    AppendCursorTag(dst, cursor - top);
    for (short i = top; i < end; i++) {
        int* entry = _Z27GetBoundedField420_0217199cPvi(menu, i);
        if (entry == NULL) {
            continue;
        }
        int palette = 3;
        if (_Z20IsBitFlagSet0217c4e8Pvi(menu, i)) {
            palette = 0xf;
        }
        AppendPaletteTag(dst, palette);
        __clear(name, sizeof(name));
        __clear(upper, sizeof(upper));
        func_020e4864(*entry, name, 1, 0, 0, 0);
        _Z37CopyTextAndUppercaseIfFlagged0206819cPKcPci(name, upper, 0);
        AppendNameTag(dst, i - top, name);
        if (i != end - 1) {
            _Z20AppendString02042058PcPKc(dst, (const char*)_Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310*)window->texts, 0));
        }
    }
}
