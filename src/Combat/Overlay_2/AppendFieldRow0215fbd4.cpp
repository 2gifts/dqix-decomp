#include <globaldefs.h>

struct Container020e0310;

extern "C" int func_020420e8(const char* str, int flags);
int AppendFrameTag02041c08(char* dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag_02041ea4(char* dst, int cursor);
int GetFieldByKey020e0434(struct Container020e0310* c, int key);
int AppendXTag_02041a28(char* dst, int x);
int AppendFormatted02041fac(char* buf, int a, int b);
int AppendNameTag_02041b70(char* dst, int n, const char* name);
int AppendString02042058(char* dst, const char* src);

// USA: func_ov002_0215fbd4
ARM void AppendFieldRow0215fbd4(char* obj, char* dst, int flag) {
    if (dst == NULL) return;

    int cursor = *(short*)(obj + 0x1c00 + 0x4);
    short key = 0x109c;

    if (flag) {
        AppendFrameTag02041c08(dst, cursor, 8, 5, 5, 5);
    }
    AppendCursorTag_02041ea4(dst, cursor);

    struct Container020e0310* c = (struct Container020e0310*)(obj + 0x20);
    cursor = GetFieldByKey020e0434(c, 0x109a);
    int width = func_020420e8((const char*)cursor, 0);
    AppendXTag_02041a28(dst, (0x78 - width) >> 1);
    AppendFormatted02041fac(dst, cursor, 0x10);

    char* ptr;
    int i;
    i = 0;
    ptr = obj + 0x1000;
    for (; i < 6; i++) {
        short oldKey = key;
        key++;
        int name = GetFieldByKey020e0434(c, oldKey);
        AppendNameTag_02041b70(dst, i, (const char*)name);
        if (i != 5) {
            AppendString02042058(dst, *(char**)(ptr + 0xbdc));
        }
    }
}
