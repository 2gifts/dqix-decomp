#include <globaldefs.h>

#if defined(jpn)
#define AppendSizeTag func_02042428
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif

#if defined(jpn)
#define func_ov013_02185be0 func_ov013_02186db0
#endif

struct Container020e0310;
int AppendFrameTag02041c08(char* dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag(char* dst, int cursor);
extern "C" void* __clear(void* dst, int count);
#if defined(jpn)
extern "C"
#endif
int AppendSizeTag(char* dst, int size);
int GetFieldByKey020e0434(struct Container020e0310* c, int key);
int AppendString02042058(char* dst, const char* src);
int AppendNameTag(char* dst, int n, const char* name);

// USA: func_ov013_02185be0  (semantic: AppendCursorAndFieldNameTags02185be0)
extern "C" ARM void func_ov013_02185be0(void* base, char* dst) {
    unsigned char* b = (unsigned char*)base;
    char buf[0x20];
    int i;

    if (*(int*)(b + LOW_REGION(0x5d4, 0x648)) == 2) {
        AppendFrameTag02041c08(dst, *(int*)(b + LOW_REGION(0x5e8, 0x660)), 9, 3, 6, 2);
    }
    AppendCursorTag(dst, *(int*)(b + LOW_REGION(0x5e8, 0x660)));

    for (i = 0; i < 2; i++) {
        __clear(buf, 0x20);
        AppendSizeTag(buf, 0xc);
        AppendString02042058(buf, (const char*)GetFieldByKey020e0434((struct Container020e0310*)(b + LOW_REGION(0x5ac, 0x620)), (short)(i + 0xa)));
        AppendNameTag(dst, i, buf);
        if (i < 1) {
            AppendString02042058(dst, (const char*)GetFieldByKey020e0434((struct Container020e0310*)(b + LOW_REGION(0x5ac, 0x620)), 0));
        }
    }
}
