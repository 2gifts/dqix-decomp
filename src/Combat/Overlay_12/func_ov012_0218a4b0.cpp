#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#if defined(jpn)
extern char data_ov012_0218bfdf[];
#endif
#include <globaldefs.h>

struct EntryA68 {
    short key;
    void* value;
};

struct TableA68 {
    struct EntryA68* entries;
    short count;
};

int AppendFrameTag02041c08(char* dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag(char* dst, int cursor);
void* FindEntryByKey(struct TableA68* table, int key);
int AppendNameTag(char* dst, int n, const char* name);
int AppendString02042058(char* dst, const char* src);
int AppendPaletteTag(char* dst, int palette);

// USA: func_ov012_0218a4b0
extern "C" ARM void func_ov012_0218a4b0(unsigned char* self, char* dst, int c) {
    if (dst == 0) return;

    int cursor = *(int*)(self + R(0x1440,0x13e8));
    if (c != 0) {
        AppendFrameTag02041c08(dst, cursor, 8, 5, 5, 5);
    }
    AppendCursorTag(dst, cursor);

    void* name = FindEntryByKey((struct TableA68*)(self + R(0x1314,0x133c)), 0xa);
    AppendNameTag(dst, 0, (const char*)name);

    AppendString02042058(dst, *(char**)(self + R(0x1348,0x1378)));

    unsigned short raw = *(unsigned short*)(self + R(0x141c,0x13c4));
    unsigned int t = ((unsigned int)raw << 16) >> 21;
    if (t == 0) {
#if defined(jpn)
        AppendString02042058(dst, data_ov012_0218bfdf);
#else
        AppendPaletteTag(dst, 3);
#endif
    }

    void* name2 = FindEntryByKey((struct TableA68*)(self + R(0x1314,0x133c)), 0xb);
    AppendNameTag(dst, 1, (const char*)name2);
}
