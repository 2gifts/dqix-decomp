#include <globaldefs.h>

#if defined(jpn)
enum { kCursorOffset = 0x1450, kStringsOffset = 0x1314, kSeparatorOffset = 0x1348 };
#else
enum { kCursorOffset = 0x13f8, kStringsOffset = 0x133c, kSeparatorOffset = 0x1378 };
#endif

ARM int AppendFrameTag02041c08(char* dst, int a1, int a2, int a3, int a4, int a5);
ARM int AppendCursorTag(char* dst, int cursor);
ARM int AppendNameTag(char* dst, int n, const char* name);
ARM int AppendString02042058(char* dst, const char* src);

struct TableA68;
void* FindEntryByKey(struct TableA68* table, int key);

// USA: func_ov012_02189fb0  (semantic: BuildBattleTag02189fb0)
// JPN: func_ov012_0218aaa4
extern "C" ARM void func_ov012_02189fb0(char* self, char* dst, int flag) {
    if (dst == 0) return;

    int val = *(int*)(self + kCursorOffset);
    if (flag != 0) {
        AppendFrameTag02041c08(dst, val, 8, 5, 5, 5);
    }
    AppendCursorTag(dst, val);

    const char* name1 = (const char*)FindEntryByKey((struct TableA68*)(self + kStringsOffset), 0x10);
    AppendNameTag(dst, 0, name1);

    AppendString02042058(dst, *(const char**)(self + kSeparatorOffset));

    const char* name2 = (const char*)FindEntryByKey((struct TableA68*)(self + kStringsOffset), 0x11);
    AppendNameTag(dst, 1, name2);
}
