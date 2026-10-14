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

void ComputeProductSums0205c508(struct UnkStruct0205c508* s, int* out1, int* out2);
int IsField0x118Equal2(void* obj);
int AppendFrameTag02041c08(char* dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag(char* dst, int cursor);
int* GetBoundedField420_0217199c(void* obj, int index);
int IsBitFlagSet0217c4e8(void* obj, int index);
int AppendPaletteTag(char* dst, int palette);
extern "C" void __clear(void* buf, int size);
extern "C" void func_020e4864(int id, char* dst, int a, int b, int c, int d);
void CopyTextAndUppercaseIfFlagged0206819c(const char* src, char* dst, int flag);
int AppendNameTag(char* dst, int n, const char* name);
int GetFieldByKey020e0434(struct Container020e0310* c, int key);
int AppendString02042058(char* dst, const char* src);

// USA: func_ov000_0217936c
extern "C" ARM void func_ov000_0217936c(struct ListWindow* window, struct ListMenu* menu, char* dst) {
#if !defined(jpn)
    char name[0x80];
    char upper[0x80];
#endif
    int first;
    int last;
    if (menu == NULL || dst == NULL) {
        return;
    }
    ComputeProductSums0205c508((struct UnkStruct0205c508*)window->scroll, &first, &last);
    short top = first;
    short end = last;
    short cursor = menu->cursor;
    if (IsField0x118Equal2(window)) {
        AppendFrameTag02041c08(dst, cursor - top, 8, 5, 5, 5);
    }
    AppendCursorTag(dst, cursor - top);
    for (short i = top; i < end; i++) {
        int* entry = GetBoundedField420_0217199c(menu, i);
        if (entry == NULL) {
            continue;
        }
#if defined(jpn)
        if (IsBitFlagSet0217c4e8(menu, i)) {
            AppendPaletteTag(dst, 0xf);
        } else {
            AppendPaletteTag(dst, 3);
        }
        AppendNameTag(dst, i - top, (const char*)*entry);
#else
        int palette = 3;
        if (IsBitFlagSet0217c4e8(menu, i)) {
            palette = 0xf;
        }
        AppendPaletteTag(dst, palette);
        __clear(name, sizeof(name));
        __clear(upper, sizeof(upper));
        func_020e4864(*entry, name, 1, 0, 0, 0);
        CopyTextAndUppercaseIfFlagged0206819c(name, upper, 0);
        AppendNameTag(dst, i - top, name);
#endif
        if (i != end - 1) {
            AppendString02042058(dst, (const char*)GetFieldByKey020e0434((struct Container020e0310*)window->texts, 0));
        }
    }
}
