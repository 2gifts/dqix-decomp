#include <globaldefs.h>

#if defined(jpn)
enum { kCursorOffset = 0x1438, kStringsOffset = 0x1314, kSeparatorOffset = 0x1348 };
#else
enum { kCursorOffset = 0x13e0, kStringsOffset = 0x133c, kSeparatorOffset = 0x1378 };
#endif

ARM int AppendFrameTag02041c08(char* dst, int a1, int a2, int a3, int a4, int a5);
ARM int AppendCursorTag_02041ea4(char* dst, int cursor);
ARM int AppendNameTag_02041b70(char* dst, int n, const char* name);
ARM int AppendString02042058(char* dst, const char* src);

struct TableA68;
void* FindEntryByKey_02072a68(struct TableA68* table, int key);

// USA: func_ov012_02189cbc  (semantic: BuildBattleTag02189cbc)
extern "C" ARM void func_ov012_02189cbc(char* self, char* dst, int flag) {
    if (dst == 0) return;

    int val = *(int*)(self + kCursorOffset);
    if (flag != 0) {
        AppendFrameTag02041c08(dst, val, 8, 5, 5, 5);
    }
    AppendCursorTag_02041ea4(dst, val);

    int i;
    for (i = 0; i < 8; i++) {
        if (i != 0) {
            AppendString02042058(dst, *(const char**)(self + kSeparatorOffset));
        }
        const char* name = (const char*)FindEntryByKey_02072a68((struct TableA68*)(self + kStringsOffset), (short)(i + 0x27d8));
        AppendNameTag_02041b70(dst, i, name);
    }
}
