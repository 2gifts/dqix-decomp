#if defined(jpn)
#define R(j,u) (j)
extern const char data_ov012_0218bfd7[];
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct TableA68;
void* FindEntryByKey_02072a68(struct TableA68* table, int key);
int AppendFrameTag02041c08(char* dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag_02041ea4(char* dst, int cursor);
int AppendNameTag_02041b70(char* dst, int n, const char* name);
int AppendString02042058(char* dst, const char* src);
int AppendPaletteTag_02041e70(char* dst, int palette);

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
    AppendCursorTag_02041ea4(dst, cursor);

    AppendNameTag_02041b70(dst, 0, (const char*)FindEntryByKey_02072a68((struct TableA68*)(base + R(0x1314, 0x133c)), 7));
    AppendString02042058(dst, *(char**)(base + R(0x1348, 0x1378)));

    AppendNameTag_02041b70(dst, 1, (const char*)FindEntryByKey_02072a68((struct TableA68*)(base + R(0x1314, 0x133c)), 8));
    AppendString02042058(dst, *(char**)(base + R(0x1348, 0x1378)));

    if (((struct PaletteFlags02189934*)(base + R(0x141c, 0x13c4)))->field == 0) {
        AppendPaletteTag_02041e70(dst, 3);
    }

    AppendNameTag_02041b70(dst, 2, (const char*)FindEntryByKey_02072a68((struct TableA68*)(base + R(0x1314, 0x133c)), 9));
    AppendString02042058(dst, *(char**)(base + R(0x1348, 0x1378)));

    if (((struct PaletteFlags02189934*)(base + R(0x141c, 0x13c4)))->field == 0) {
#if defined(jpn)
        AppendString02042058(dst, data_ov012_0218bfd7);
#else
        AppendPaletteTag_02041e70(dst, 0xf);
#endif
    }

    AppendNameTag_02041b70(dst, 3, (const char*)FindEntryByKey_02072a68((struct TableA68*)(base + R(0x1314, 0x133c)), 0x6d));
}
