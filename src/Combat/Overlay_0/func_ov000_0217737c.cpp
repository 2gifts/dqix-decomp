#include <globaldefs.h>

void* CopyStaticData02174da4(int unused, void* dest);
int IsField0x118Equal2(void* obj);
int AppendFrameTag02041c08(char* dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag(char* dst, int cursor);
int AppendString02042058(char* dst, const char* src);
int AppendNameTag(char* dst, int n, const char* name);

struct Container020e0310;
int GetFieldByKey020e0434(struct Container020e0310* c, int key);
int CallFunc020e0434With02153694(int value);

extern short data_ov000_021834c4[4];

#if defined(jpn)
struct MenuLabels0217737c { char names[4][9]; };
extern const MenuLabels0217737c data_ov000_021845c6;
#endif

// USA: func_ov000_0217737c
extern "C" ARM void func_ov000_0217737c(void* objRaw, char* dst) {
    char* obj = (char*)objRaw;
    if (dst == 0) {
        return;
    }
    int localArr[4];
    CopyStaticData02174da4((int)obj, localArr);
#if defined(jpn)
    int nameIdx = 0;
    MenuLabels0217737c labels(data_ov000_021845c6);
    signed char cursorId = *(signed char*)(obj + 0x1fa1);
#else
    signed char cursorId = *(signed char*)(obj + 0x1d69);
#endif
#if !defined(jpn)
    int nameIdx = 0;
#endif
    if (IsField0x118Equal2(obj)) {
        AppendFrameTag02041c08(dst, cursorId, 8, 5, 5, 5);
    }
    AppendCursorTag(dst, cursorId);
    int keyArg = 0;
    for (int i = 0; i < 4; i++) {
        int v = localArr[i];
        if (v < 0) {
            continue;
        }
        if (nameIdx != 0) {
            int f = GetFieldByKey020e0434((struct Container020e0310*)(obj + 0xb8), keyArg);
            AppendString02042058(dst, (const char*)f);
        }
#if defined(jpn)
        char* r = labels.names[v];
#else
        int r = CallFunc020e0434With02153694(data_ov000_021834c4[v]);
#endif
        AppendNameTag(dst, nameIdx, (const char*)r);
        nameIdx++;
    }
}
