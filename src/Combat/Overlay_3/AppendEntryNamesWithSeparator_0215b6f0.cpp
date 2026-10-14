#include <globaldefs.h>

struct Container020e0310;
int AppendFrameTag02041c08(char* dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag_02041ea4(char* dst, int cursor);
int GetFieldByKey020e0434(struct Container020e0310* c, int key);
int AppendNameTag_02041b70(char* dst, int n, const char* name);
int AppendString02042058(char* dst, const char* src);

extern char data_ov003_0217fe7f;

// USA: func_ov003_0215b6f0  (semantic: AppendEntryNamesWithSeparator_0215b6f0)
extern "C" ARM void func_ov003_0215b6f0(char* base, char* dst, int flag) {
    if (dst == NULL) return;

    signed char cursor = *(signed char*)(base + 0x584);
    if (flag) {
        AppendFrameTag02041c08(dst, cursor, 8, 5, 5, 5);
    }
    AppendCursorTag_02041ea4(dst, cursor);

    struct Container020e0310* c = (struct Container020e0310*)(base + 0x64);
    int i = 0;
    while (i < *(unsigned char*)(base + 0x589)) {
        signed char key = *(signed char*)(base + i + 0x58a);
        int name = GetFieldByKey020e0434(c, key);
        AppendNameTag_02041b70(dst, i, (const char*)name);
        if (i != *(unsigned char*)(base + 0x589) - 1) {
            AppendString02042058(dst, &data_ov003_0217fe7f);
        }
        i++;
    }
}
