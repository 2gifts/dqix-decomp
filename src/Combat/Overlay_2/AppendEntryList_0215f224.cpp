#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct Container020e0310;
int GetFieldByKey020e0434(struct Container020e0310* c, int key);
int AppendFrameTag02041c08(char* dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag_02041ea4(char* dst, int cursor);
int AppendNameTag_02041b70(char* dst, int n, const char* name);
int AppendString02042058(char* dst, const char* src);
int AppendFormatted02041fac(char* buf, int a, int b);
int AppendXYTag_02041a90(char* dst, int x, int y);

struct UnkStruct0205c508;
void ComputeProductSums0205c508(struct UnkStruct0205c508* s, int* out1, int* out2);

struct List020a83b0;
struct Entry020a83b0;
struct Entry020a83b0* FindEntryByByteId020a83b0(struct List020a83b0* list, int id);

extern "C" int _s32_div_f(int a, int b);
extern "C" void __clear(void* buf, int n);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern "C" int func_020420e8(const char* str, int flags);

extern int data_ov002_0216d2a8;

// USA: func_ov002_0215f224
ARM void AppendEntryList_0215f224(char* p, char* dst, int flag2) {
    if (dst == NULL) {
        return;
    }
    if (*(int*)(p + 0x2474) == 0) {
        return;
    }

    int cursor = *(short*)(p + 0x1bfc) % 6;

    if (flag2) {
        AppendFrameTag02041c08(dst, cursor, 8, 5, 5, 5);
    }
    AppendCursorTag_02041ea4(dst, cursor);

    char* fld = p + 0x2c8 + 0xc00;
    int out1, out2;
    ComputeProductSums0205c508((struct UnkStruct0205c508*)(fld + 0x54), &out1, &out2);

    int fmtVal = GetFieldByKey020e0434((struct Container020e0310*)(p + 0x20), 0x578);
    AppendFormatted02041fac(dst, fmtVal, 0x10);

    int i;
    for (i = out1; i < out2; i++) {
        struct Entry020a83b0* entry = FindEntryByByteId020a83b0((struct List020a83b0*)(*(int*)(p + 0x2000 + 0x474)), (short)i);
        if (entry != NULL) {
            int rem = i % 6;
            AppendNameTag_02041b70(dst, rem, *(const char**)((char*)entry + 4));
            if (i != out2 - 1) {
                AppendString02042058(dst, *(char**)(p + 0x1000 + 0xbdc));
            }
        }
    }

    int n = *(int*)(fld + 0x58);
    if (n > 1) {
        int field68 = *(int*)(fld + 0x68);
        char buf[4];
        __clear(buf, 4);
        sprintf(buf, (const char*)&data_ov002_0216d2a8, field68 + 1, n);
        int width = func_020420e8(buf, 0);
        int rounded = width + (width & 1);
        int xoff = (0x78 - rounded) >> 1;
        AppendXYTag_02041a90(dst, xoff, 0x63);
        AppendString02042058(dst, buf);
    }
}
