#include <globaldefs.h>

#if defined(jpn)
enum { kRegionValue4ED_4E9 = 0x4e9 };
#else
enum { kRegionValue4ED_4E9 = 0x4ed };
#endif


struct Container020e0310;
int AppendFrameTag02041c08(char* dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag(char* dst, int cursor);
int GetFieldByKey020e0434(struct Container020e0310* c, int key);
int AppendNameTag(char* dst, int n, const char* name);
int AppendString02042058(char* dst, const char* src);

// USA: func_ov003_02169a84  (semantic: AppendEntryNamesWithSeparator_02169a84)
// JPN: func_ov003_02169864
extern "C" ARM void func_ov003_02169a84(char* base, char* dst, int flag) {
    if (dst == NULL) return;

    signed char cursor = *(signed char*)(base + kRegionValue4ED_4E9);
    if (flag) {
        AppendFrameTag02041c08(dst, cursor, 8, 5, 5, 5);
    }
    AppendCursorTag(dst, cursor);

    struct Container020e0310* c = (struct Container020e0310*)(base + 0x64);
    int i = 0;
    while (i < 3) {
        int name = GetFieldByKey020e0434(c, (short)i);
        AppendNameTag(dst, i, (const char*)name);
        if (i != 2) {
            int sep = GetFieldByKey020e0434(c, 0x64);
            AppendString02042058(dst, (const char*)sep);
        }
        i++;
    }
}
