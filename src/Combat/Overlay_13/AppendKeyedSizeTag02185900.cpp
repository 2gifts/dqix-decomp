#include <globaldefs.h>

#if defined(jpn)
#define AppendSizeTag func_02042428
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif

#if defined(jpn)
#define func_ov013_02185900 func_ov013_02186aec
#endif

#if defined(jpn)
extern "C"
#endif
int AppendSizeTag(char* dst, int size);
struct Container020e0310;
int GetFieldByKey020e0434(struct Container020e0310* c, int key);
int AppendString02042058(char* dst, const char* src);

// USA: func_ov013_02185900  (semantic: AppendKeyedSizeTag02185900)
extern "C" ARM void func_ov013_02185900(void* obj, char* dst) {
    AppendSizeTag(dst, 0xc);

    unsigned char tag = *(unsigned char*)((char*)obj + LOW_REGION(0x5c8, 0x63c));
    if (tag == 4) {
        AppendString02042058(dst, (const char*)GetFieldByKey020e0434((struct Container020e0310*)((char*)obj + LOW_REGION(0x5ac, 0x620)), LOW_REGION(0x7d0, 0x3e8)));
    } else if (tag == 3) {
        AppendString02042058(dst, (const char*)GetFieldByKey020e0434((struct Container020e0310*)((char*)obj + LOW_REGION(0x5ac, 0x620)), LOW_REGION(0x7d1, 0x3e9)));
    } else if (tag == 2) {
        AppendString02042058(dst, (const char*)GetFieldByKey020e0434((struct Container020e0310*)((char*)obj + LOW_REGION(0x5ac, 0x620)), LOW_REGION(0x7d2, 0x3ea)));
    }
}
