#include <globaldefs.h>

#if defined(jpn)
#define func_ov013_02185424 func_ov013_02186468
#endif

struct Container020e0310;
int GetFieldByKey020e0434(struct Container020e0310* c, int key);
extern "C" void* __clear(void* dst, int count);
extern "C" int func_020420e8(char* str, int id);
int AppendXTag(char* dst, int x);
int AppendString02042058(char* dst, const char* src);
int AppendFormatted02041fac(char* buf, int a, int b);
int AppendFrameTag02041c08(char* dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag(char* dst, int cursor);
int AppendPaletteTag(char* dst, int palette);
int AppendYTag(char* dst, int y);
int AppendLineTag02041cc0(char* dst, int a1);
int AppendLineYTag02041d48(char* dst, int a1, int a2, int a3, int a4);
extern "C" int sprintf(char* dst, const char* fmt, ...);

// USA: func_ov013_02185424  (semantic: SetupBattleMessageBody02185424)
extern "C" ARM void func_ov013_02185424(void* obj, char* out) {
    unsigned char* o = (unsigned char*)obj;
    char buf[0x100];
    __clear(buf, 0x100);

    char* str = (char*)GetFieldByKey020e0434((struct Container020e0310*)(o + 0x620), 0x2718);
    int len = func_020420e8(str, 0);
    AppendXTag(buf, (0xf0 - len) >> 1);
    AppendString02042058(buf, str);
    AppendFormatted02041fac(out, (int)buf, 0x10);

    if (*(int*)(o + 0x648) == 2) {
        AppendFrameTag02041c08(out, *(int*)(o + 0x65c), 8, 3, 6, 2);
    }
    AppendCursorTag(out, *(int*)(o + 0x65c));

    for (unsigned char id = 0; id < 5; id++) {
        if ((o + id)[0x69c] == 0) {
            AppendPaletteTag(out, 0xf);
        } else {
            AppendPaletteTag(out, 3);
        }
        int key = (short)((o + id)[0x6a9] + 0x64);
        int v1 = GetFieldByKey020e0434((struct Container020e0310*)(o + 0x620), key);
        int fmt = GetFieldByKey020e0434((struct Container020e0310*)(o + 0x620), 0x2711);
        sprintf(buf, (const char*)fmt, id, v1);
        AppendString02042058(out, buf);
        if (id != 4) {
            int v3 = GetFieldByKey020e0434((struct Container020e0310*)(o + 0x620), 0);
            sprintf(buf, (const char*)v3);
        }
        AppendString02042058(out, buf);
    }

    AppendYTag(out, 0x15);

    int n, i;
    for (i = 0; i < 5; i++) {
        n = i * 0xd;
        int v674 = ((int*)(o + 0x674))[i];
        int v688 = ((int*)(o + 0x688))[i];
        int fmt;
        if ((o + i)[0x69c] == 1) {
            fmt = GetFieldByKey020e0434((struct Container020e0310*)(o + 0x620), 0x2712);
            sprintf(buf, (const char*)fmt, n + 0x16, v688, v674);
        } else if (i == *(int*)(o + 0x65c)) {
            if (v688 == 0) {
                fmt = GetFieldByKey020e0434((struct Container020e0310*)(o + 0x620), 0x2714);
                sprintf(buf, (const char*)fmt, n + 0x16, 0xa, v688, 0xb, v674);
            } else {
                fmt = GetFieldByKey020e0434((struct Container020e0310*)(o + 0x620), 0x2713);
                sprintf(buf, (const char*)fmt, n + 0x16, 0xa, v688, 0xb, v674, v674 + v688);
            }
        } else {
            if (v688 == 0) {
                fmt = GetFieldByKey020e0434((struct Container020e0310*)(o + 0x620), 0x2716);
                sprintf(buf, (const char*)fmt, n + 0x16, v688, v674);
            } else {
                fmt = GetFieldByKey020e0434((struct Container020e0310*)(o + 0x620), 0x2715);
                sprintf(buf, (const char*)fmt, n + 0x16, v688, v674, v674 + v688);
            }
        }
        AppendString02042058(out, buf);
        if (i != 4) {
            int v0 = GetFieldByKey020e0434((struct Container020e0310*)(o + 0x620), 0);
            AppendString02042058(out, (const char*)v0);
        }
    }

    AppendLineTag02041cc0(out, 0x57);
    AppendLineYTag02041d48(out, 0x7fff, 0x5a, 0x10, 0x57);

    int fmtEnd = GetFieldByKey020e0434((struct Container020e0310*)(o + 0x620), 0x2717);
    sprintf(buf, (const char*)fmtEnd, *(int*)(o + 0x66c));
    AppendString02042058(out, buf);
}
