#if defined(jpn)
enum {regionalOffset0=0xd48, regionalOffset1=0x38, regionalOffset2=0xc0};
#else
enum {regionalOffset0=0xd84, regionalOffset1=0x30, regionalOffset2=0xe0};
#endif
#include <globaldefs.h>

struct Container020e0310;
int AppendFrameTag02041c08(char* dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag(char* dst, int cursor);
int AppendSourceRectTag(char* dst, int a, int b, int c, int d, int e);
int GetFieldByKey020e0434(struct Container020e0310* c, int key);
int AppendNameTag(char* dst, int n, const char* name);
int AppendString02042058(char* dst, const char* src);

// JPN: func_ov023_021da8cc
// USA: func_ov023_021da100  (semantic: AppendCursorAndNameTags_021da100)
extern "C" ARM void func_ov023_021da100(char* obj, char* dst, int flag) {
    if (dst == NULL) return;

    signed char cursor = *(signed char*)(obj + regionalOffset0);
    if (flag) {
        AppendFrameTag02041c08(dst, cursor, 8, 5, 5, 5);
    }
    AppendCursorTag(dst, cursor);

    AppendSourceRectTag(dst, 0, 0, 0, regionalOffset1, 0x28);

    struct Container020e0310* c = (struct Container020e0310*)(obj + regionalOffset2);
    for (int i = 0; i < 2; i++) {
        int name = GetFieldByKey020e0434(c, (short)(i + 0x465a));
        AppendNameTag(dst, i, (const char*)name);
        if (i != 1) {
            int sep = GetFieldByKey020e0434(c, 0x4273);
            AppendString02042058(dst, (const char*)sep);
        }
    }
}
