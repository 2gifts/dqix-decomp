#include <globaldefs.h>

struct Container020e0310;

extern "C" int _Z21GetFieldByKey020e0434P17Container020e0310i(struct Container020e0310* c, int key);
extern "C" int func_020420e8(const char* text, int large);
int IsField0x118Equal2(void* obj);
extern "C" int _Z22AppendFrameTag02041c08Pciiiii(char* dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag(char* dst, int cursor);
int AppendNameTag(char* dst, int n, const char* name);
extern "C" int _Z20AppendString02042058PcPKc(char* dst, const char* src);
int AppendXTag(char* dst, int x);

extern int data_ov000_021834e0[6];

// USA: func_ov000_02177ac8
extern "C" ARM void func_ov000_02177ac8(char* obj, char* dst) {
    if (dst == NULL) {
        return;
    }
    int maxWidth = 0;
    signed char cursor = *(signed char*)(obj + 0x1d6c);
    for (int i = 0; i < 3; i++) {
        const char* name = (const char*)_Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310*)(obj + 0xb8), (short)(i + 30014));
        int width = func_020420e8(name, 0);
        if (maxWidth < width) {
            maxWidth = width;
        }
    }
    if (IsField0x118Equal2(obj)) {
        _Z22AppendFrameTag02041c08Pciiiii(dst, cursor, 8, 5, 5, 5);
    }
    AppendCursorTag(dst, cursor);
    for (int i = 0; i < 6; i++) {
        int id = data_ov000_021834e0[i];
        AppendNameTag(dst, id, (const char*)_Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310*)(obj + 0xb8), (short)(id + 30014)));
        if (i == 5) {
            break;
        }
        int odd = i & 1;
        if (odd) {
            _Z20AppendString02042058PcPKc(dst, (const char*)_Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310*)(obj + 0xb8), 0));
        }
        if (!odd) {
            AppendXTag(dst, maxWidth + 0x20);
        }
    }
}
