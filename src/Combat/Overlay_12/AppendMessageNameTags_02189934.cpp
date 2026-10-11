#if defined(jpn)
#define R(j,u) (j)
#define func_ov005_021562b8 func_ov005_021578a8
extern const char data_ov012_0218bfd7[];
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct TableA68;
void* FindEntryByKey(struct TableA68* table, int key);
int AppendFrameTag02041c08(char* dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag(char* dst, int cursor);
int AppendNameTag(char* dst, int n, const char* name);
int AppendString02042058(char* dst, const char* src);
int AppendPaletteTag(char* dst, int palette);

struct PaletteFlags02189934 {
    unsigned short field : 5;
};

// USA: func_ov012_02189934  (semantic: AppendMessageNameTags_02189934)
extern "C" ARM void func_ov012_02189934(char* base, char* dst, int flag) {
    if (dst == NULL) return;

    int cursor = *(int*)(base + R(0x1430, 0x13d8));
    if (flag != 0) {
        AppendFrameTag02041c08(dst, cursor, 8, 5, 5, 5);
    }
    AppendCursorTag(dst, cursor);

    AppendNameTag(dst, 0, (const char*)FindEntryByKey((struct TableA68*)(base + R(0x1314, 0x133c)), 7));
    AppendString02042058(dst, *(char**)(base + R(0x1348, 0x1378)));

    AppendNameTag(dst, 1, (const char*)FindEntryByKey((struct TableA68*)(base + R(0x1314, 0x133c)), 8));
    AppendString02042058(dst, *(char**)(base + R(0x1348, 0x1378)));

    if (((struct PaletteFlags02189934*)(base + R(0x141c, 0x13c4)))->field == 0) {
        AppendPaletteTag(dst, 3);
    }

    AppendNameTag(dst, 2, (const char*)FindEntryByKey((struct TableA68*)(base + R(0x1314, 0x133c)), 9));
    AppendString02042058(dst, *(char**)(base + R(0x1348, 0x1378)));

    if (((struct PaletteFlags02189934*)(base + R(0x141c, 0x13c4)))->field == 0) {
#if defined(jpn)
        AppendString02042058(dst, data_ov012_0218bfd7);
#else
        AppendPaletteTag(dst, 0xf);
#endif
    }

    AppendNameTag(dst, 3, (const char*)FindEntryByKey((struct TableA68*)(base + R(0x1314, 0x133c)), 0x6d));
}
