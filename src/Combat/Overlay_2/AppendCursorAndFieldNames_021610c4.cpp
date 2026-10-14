#include <globaldefs.h>

struct Container020e0310;
int GetFieldByKey020e0434(struct Container020e0310* c, int key);
int AppendFrameTag02041c08(char* dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag_02041ea4(char* dst, int cursor);
int AppendNameTag_02041b70(char* dst, int n, const char* name);
int AppendString02042058(char* dst, const char* src);

// USA: func_ov002_021610c4  (semantic: AppendCursorAndFieldNames_021610c4)
extern "C" ARM void func_ov002_021610c4(unsigned char* obj, char* dst, int flag) {
    if (dst == NULL) return;

    int cursor = *(short*)(obj + 0x1c12);
    short id = 0x26ad;

    if (flag) {
        AppendFrameTag02041c08(dst, cursor, 8, 5, 5, 5);
    }
    AppendCursorTag_02041ea4(dst, cursor);

    for (int i = 0; i < 2; i++) {
        int field = GetFieldByKey020e0434((Container020e0310*)(obj + 0x20), id++);
        AppendNameTag_02041b70(dst, i, (const char*)field);
        if (i != 1) {
            AppendString02042058(dst, *(char**)(obj + 0x1bdc));
        }
    }
}
