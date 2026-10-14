#include <globaldefs.h>

extern "C" int func_020420e8(void* p, int flag);
int AppendXYTag_02041a90(char* dst, int x, int y);
int AppendString02042058(char* dst, const char* src);
int AppendSourceRectTag_02041bac(char* dst, int a, int b, int c, int d, int e);

#if defined(jpn)
extern "C" void __clear(void*, int);
extern "C" void func_02041f50(const char*, char*);
int StringLength_020d2ff0(const char*);
#endif

// USA: func_ov023_021ed254
extern "C" ARM void func_ov023_021ed254(char* obj, char* buf) {
    if (buf == 0) return;

    unsigned char idx = *(unsigned char*)(obj + 0x28);
    char* base = *(char**)(obj + 0x20);
#if defined(jpn)
    char* entry = base + idx * 0x15c;
    char converted[0x80];
    __clear(converted, 0x80);
    func_02041f50(entry + 0xc, converted);
    int len = StringLength_020d2ff0(converted);
    int half = (0x80 - (len / 2) * 12) / 2;
    int y = 6;
    if (len != StringLength_020d2ff0(entry + 0xc)) y = 8;
    AppendXYTag_02041a90(buf, half, y);
    AppendString02042058(buf, entry + 0xc);
#else
    char* entry = base + idx * 0x244 + 0xc;
    int val = func_020420e8(entry, 1);
    int diff = 0xa0 - val;
    int half = diff / 2;
    if (half < 0) half = 0;
    AppendXYTag_02041a90(buf, half, 6);

    if (entry != 0) {
        AppendString02042058(buf, entry);
    }

    #endif

    if (!(*(unsigned short*)(obj + 0x438) & 0x2)) {
        short score = *(short*)(obj + 0x448);
#if defined(jpn)
        short a = score - 0x1c;
        short b = 0x80 - a;
#else
        short a = score - 0xc;
        short b = 0xa0 - a;
#endif
        if (a > 0 && b > 0) {
            AppendSourceRectTag_02041bac(buf, 1, a, 1, b, 0x16);
        } else if (a <= 0) {
#if defined(jpn)
            AppendSourceRectTag_02041bac(buf, 1, 1, 1, 0x7e, 0x16);
#else
            AppendSourceRectTag_02041bac(buf, 1, 1, 1, 0x9e, 0x16);
#endif
        }
    }
    *(unsigned short*)(obj + 0x438) &= ~0x2;
}
