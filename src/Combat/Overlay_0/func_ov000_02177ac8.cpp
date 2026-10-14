#include <globaldefs.h>

#if defined(jpn)
#define data_ov000_021834e0 data_ov000_02184560
#endif
struct Container020e0310;

int GetFieldByKey020e0434(struct Container020e0310* c, int key);
extern "C" int func_020420e8(const char* text, int large);
int IsField0x118Equal2(void* obj);
int AppendFrameTag02041c08(char* dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag(char* dst, int cursor);
int AppendNameTag(char* dst, int n, const char* name);
int AppendString02042058(char* dst, const char* src);
int AppendXTag(char* dst, int x);

extern int data_ov000_021834e0[6];

// USA: func_ov000_02177ac8
extern "C" ARM void func_ov000_02177ac8(char* obj, char* dst) {
    if (dst == NULL) {
        return;
    }
#if defined(jpn)
    enum { cursorOffset = 0x1fa4 };
    int maxWidth = 0x4d;
#else
    enum { cursorOffset = 0x1d6c };
    int maxWidth = 0;
#endif
    signed char cursor = *(signed char*)(obj + cursorOffset);
#if !defined(jpn)
    for (int i = 0; i < 3; i++) {
        const char* name = (const char*)GetFieldByKey020e0434((struct Container020e0310*)(obj + 0xb8), (short)(i + 30014));
        int width = func_020420e8(name, 0);
        if (maxWidth < width) {
            maxWidth = width;
        }
    }
#endif
    if (IsField0x118Equal2(obj)) {
        AppendFrameTag02041c08(dst, cursor, 8, 5, 5, 5);
    }
    AppendCursorTag(dst, cursor);
    for (int i = 0; i < 6; i++) {
        int id = data_ov000_021834e0[i];
        AppendNameTag(dst, id, (const char*)GetFieldByKey020e0434((struct Container020e0310*)(obj + 0xb8), (short)(id + 30014)));
        if (i == 5) {
            break;
        }
        int odd = i & 1;
        if (odd) {
            AppendString02042058(dst, (const char*)GetFieldByKey020e0434((struct Container020e0310*)(obj + 0xb8), 0));
        }
        if (!odd) {
            AppendXTag(dst, maxWidth + 0x20);
        }
    }
}
