#include <globaldefs.h>

#if defined(jpn)
#define func_ov013_02185424 func_ov013_02186468
#define LOW_REGION(j,u) (j)
extern "C" int func_0204234c(char*, int);
extern "C" int func_020423d4(char*, int, int, int, int);
#else
#define LOW_REGION(j,u) (u)
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

#if defined(jpn)
    int length = 0x10;
    int x = 0x78 - (int)(((float)length / 4.0f) * 12.0f);
    int heading = GetFieldByKey020e0434((Container020e0310*)(o + 0x5ac), 0x2718);
    sprintf(buf, (const char*)heading, x);
    AppendString02042058(out, buf);
#else
    char* str = (char*)GetFieldByKey020e0434((struct Container020e0310*)(o + LOW_REGION(0x5ac,0x620)), 0x2718);
    int len = func_020420e8(str, 0);
    AppendXTag(buf, (0xf0 - len) >> 1);
    AppendString02042058(buf, str);
    AppendFormatted02041fac(out, (int)buf, 0x10);

#endif

    if (*(int*)(o + LOW_REGION(0x5d4,0x648)) == 2) {
        AppendFrameTag02041c08(out, *(int*)(o + LOW_REGION(0x5e4,0x65c)), 8, 3, 6, 2);
    }
    AppendCursorTag(out, *(int*)(o + LOW_REGION(0x5e4,0x65c)));

    for (unsigned char id = 0; id < 5; id++) {
        if ((o + id)[LOW_REGION(0x624,0x69c)] == 0) {
            AppendPaletteTag(out, 0xf);
        } else {
            AppendPaletteTag(out, 3);
        }
        int key = (short)((o + id)[LOW_REGION(0x631,0x6a9)] + 0x64);
        int v1 = GetFieldByKey020e0434((struct Container020e0310*)(o + LOW_REGION(0x5ac,0x620)), key);
        int fmt = GetFieldByKey020e0434((struct Container020e0310*)(o + LOW_REGION(0x5ac,0x620)), 0x2711);
        sprintf(buf, (const char*)fmt, id, v1);
        AppendString02042058(out, buf);
        if (id != 4) {
            int v3 = GetFieldByKey020e0434((struct Container020e0310*)(o + LOW_REGION(0x5ac,0x620)), 0);
            sprintf(buf, (const char*)v3);
        }
        AppendString02042058(out, buf);
    }

#if defined(jpn)
    func_020420e8(out, 0x15);
#else
    AppendYTag(out, 0x15);
#endif

#if defined(jpn)
    for (int i = 0; i < 5; i++) {
        int fmt;
        if ((o + i)[0x624] == 1) {
            fmt = GetFieldByKey020e0434((Container020e0310*)(o + 0x5ac), 0x2712);
            sprintf(buf, (const char*)fmt, i * 0xd + 0x16, ((int*)(o + 0x610))[i], ((int*)(o + 0x5fc))[i]);
        } else if (i == *(int*)(o + 0x5e4)) {
            if (((int*)(o + 0x610))[i] == 0x64) {
                fmt = GetFieldByKey020e0434((Container020e0310*)(o + 0x5ac), 0x2713);
                sprintf(buf, (const char*)fmt, i * 0xd + 0x16, i + 5, ((int*)(o + 0x610))[i], i + 0xa, ((int*)(o + 0x5fc))[i], ((int*)(o + 0x5fc))[i] + ((int*)(o + 0x610))[i]);
            }
            else if (((int*)(o + 0x610))[i] >= 0xa) {
                fmt = GetFieldByKey020e0434((Container020e0310*)(o + 0x5ac), 0x2713);
                sprintf(buf, (const char*)fmt, i * 0xd + 0x16, i + 5, ((int*)(o + 0x610))[i], i + 0xa, ((int*)(o + 0x5fc))[i], ((int*)(o + 0x5fc))[i] + ((int*)(o + 0x610))[i]);
            }
            else if (((int*)(o + 0x610))[i] != 0) {
                fmt = GetFieldByKey020e0434((Container020e0310*)(o + 0x5ac), 0x2713);
                sprintf(buf, (const char*)fmt, i * 0xd + 0x16, i + 5, ((int*)(o + 0x610))[i], i + 0xa, ((int*)(o + 0x5fc))[i], ((int*)(o + 0x5fc))[i] + ((int*)(o + 0x610))[i]);
            }
            else {
                fmt = GetFieldByKey020e0434((Container020e0310*)(o + 0x5ac), 0x2714);
                sprintf(buf, (const char*)fmt, i * 0xd + 0x16, i + 5, ((int*)(o + 0x610))[i], i + 0xa, ((int*)(o + 0x5fc))[i]);
            }
        } else {
            if (((int*)(o + 0x610))[i] == 0x64) {
                fmt = GetFieldByKey020e0434((Container020e0310*)(o + 0x5ac), 0x2715);
                sprintf(buf, (const char*)fmt, i * 0xd + 0x16, ((int*)(o + 0x610))[i], ((int*)(o + 0x5fc))[i], ((int*)(o + 0x5fc))[i] + ((int*)(o + 0x610))[i]);
            }
            else if (((int*)(o + 0x610))[i] >= 0xa) {
                fmt = GetFieldByKey020e0434((Container020e0310*)(o + 0x5ac), 0x2715);
                sprintf(buf, (const char*)fmt, i * 0xd + 0x16, ((int*)(o + 0x610))[i], ((int*)(o + 0x5fc))[i], ((int*)(o + 0x5fc))[i] + ((int*)(o + 0x610))[i]);
            }
            else if (((int*)(o + 0x610))[i] != 0) {
                fmt = GetFieldByKey020e0434((Container020e0310*)(o + 0x5ac), 0x2715);
                sprintf(buf, (const char*)fmt, i * 0xd + 0x16, ((int*)(o + 0x610))[i], ((int*)(o + 0x5fc))[i], ((int*)(o + 0x5fc))[i] + ((int*)(o + 0x610))[i]);
            }
            else {
                fmt = GetFieldByKey020e0434((Container020e0310*)(o + 0x5ac), 0x2716);
                sprintf(buf, (const char*)fmt, i * 0xd + 0x16, ((int*)(o + 0x610))[i], ((int*)(o + 0x5fc))[i]);
            }
        }
        AppendString02042058(out, buf);
        if (i != 4) {
            int v0 = GetFieldByKey020e0434((Container020e0310*)(o + 0x5ac), 0);
            AppendString02042058(out, (const char*)v0);
        }
    }

#else
    int n, i;
    for (i = 0; i < 5; i++) {
        n = i * 0xd;
        int v674 = ((int*)(o + LOW_REGION(0x5fc,0x674)))[i];
        int v688 = ((int*)(o + LOW_REGION(0x610,0x688)))[i];
        int fmt;
        if ((o + i)[LOW_REGION(0x624,0x69c)] == 1) {
            fmt = GetFieldByKey020e0434((struct Container020e0310*)(o + LOW_REGION(0x5ac,0x620)), 0x2712);
            sprintf(buf, (const char*)fmt, n + 0x16, v688, v674);
        } else if (i == *(int*)(o + LOW_REGION(0x5e4,0x65c))) {
            if (v688 == 0) {
                fmt = GetFieldByKey020e0434((struct Container020e0310*)(o + LOW_REGION(0x5ac,0x620)), 0x2714);
                sprintf(buf, (const char*)fmt, n + 0x16, 0xa, v688, 0xb, v674);
            } else {
                fmt = GetFieldByKey020e0434((struct Container020e0310*)(o + LOW_REGION(0x5ac,0x620)), 0x2713);
                sprintf(buf, (const char*)fmt, n + 0x16, 0xa, v688, 0xb, v674, v674 + v688);
            }
        } else {
            if (v688 == 0) {
                fmt = GetFieldByKey020e0434((struct Container020e0310*)(o + LOW_REGION(0x5ac,0x620)), 0x2716);
                sprintf(buf, (const char*)fmt, n + 0x16, v688, v674);
            } else {
                fmt = GetFieldByKey020e0434((struct Container020e0310*)(o + LOW_REGION(0x5ac,0x620)), 0x2715);
                sprintf(buf, (const char*)fmt, n + 0x16, v688, v674, v674 + v688);
            }
        }
        AppendString02042058(out, buf);
        if (i != 4) {
            int v0 = GetFieldByKey020e0434((struct Container020e0310*)(o + LOW_REGION(0x5ac,0x620)), 0);
            AppendString02042058(out, (const char*)v0);
        }
    }

#endif
#if defined(jpn)
    func_0204234c(out, 0x57);
    func_020423d4(out, 0x7fff, 0x4a, 0x10, 0x57);
#else
    AppendLineTag02041cc0(out, 0x57);
    AppendLineYTag02041d48(out, 0x7fff, 0x5a, 0x10, 0x57);
#endif

    int fmtEnd = GetFieldByKey020e0434((struct Container020e0310*)(o + LOW_REGION(0x5ac,0x620)), 0x2717);
    sprintf(buf, (const char*)fmtEnd, *(int*)(o + LOW_REGION(0x5f4,0x66c)));
    AppendString02042058(out, buf);
}
