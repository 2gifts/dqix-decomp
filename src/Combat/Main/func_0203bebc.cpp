#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct02020520 {
    int a;
    short b;
    short c;
    short d;
    short e;
};

struct S_b20c {
    int field0;
    int field4;
    unsigned char field8;
};

struct Glyph020425b4 {
    int pad;
    signed char width;
};

void ClearTwoWordsAndByte(struct S_b20c* obj);
extern "C" void _Z18SetField0_0205b220Pvi(void* obj, int value);
extern "C" void _Z29SetFieldsAt0x4And0x8_0205b228Pvih(void* obj, int value, unsigned char flag);
extern "C" void* _Z26GetGlobalField0x1c020421a0v(void);
extern "C" void* _Z23GetBoundedEntry020425b4ii(int idx, int tableIdx);
extern "C" int _Z22LookupKeyValue020425e4iii(int a, int b, int tableIdx);
extern "C" int _Z24GetWordFromTable02042648i(int idx);
extern "C" void _Z25CleanInvalidateCacheRangePKvj(const void* p, unsigned int len);
extern "C" void LoadToSubObjVRAM(const void* data, unsigned int offset, unsigned int length);
extern "C" int func_0205b36c(void* self, void* glyph, short a, int b, unsigned char c, unsigned char d);

// USA: func_0203bebc
extern "C" ARM void func_0203bebc(void* entry, void* buf, void* dest) {
    int limit;
    char* g = (char*)_Z26GetGlobalField0x1c020421a0v();
    void* fp = *(void**)(g + 0x60);
    memset(fp, 0, 0x400);

    struct Struct02020520 arr[4];
    int off = 0;
    int acc = 0;
    for (int i = 0; i < 4; i++) {
        struct Struct02020520* e = &arr[i];
        e->a = off;
        e->b = acc;
        e->c = 0;
        e->d = 0x20;
        e->e = 0x10;
        off += 0x100;
        acc += e->d;
    }

    struct S_b20c localObj;
    ClearTwoWordsAndByte(&localObj);
    _Z18SetField0_0205b220Pvi(&localObj, (int)fp);
    _Z29SetFieldsAt0x4And0x8_0205b228Pvih(&localObj, (int)arr, 4);

    *(short*)((char*)entry + 0x22) = (short)((unsigned int)dest >> 7);
    memset(entry, 0, 0x20);
    memcpy(entry, buf, ((unsigned char*)entry)[0x20]);

    int total = 0;
    limit = ((unsigned char*)entry)[0x20];
    int prev = 0xff;
    int font = _Z24GetWordFromTable02042648i(0);
    unsigned char ch;
    int cnt = 0;
    unsigned char* p = (unsigned char*)buf;
    for (; cnt < limit; cnt++) {
        ch = *p;
        if (ch == 0) break;
        int c = font;
        struct Glyph020425b4* gl = (struct Glyph020425b4*)_Z23GetBoundedEntry020425b4ii(ch, 0);
        if (gl != 0) {
            c = gl->width;
            func_0205b36c(&localObj, gl, (short)total, 0, 0xf, 0);
        }
        int w = total + _Z22LookupKeyValue020425e4iii(prev, ch, 0);
        total = w + (c + 1);
        prev = ch;
        p++;
    }

    _Z25CleanInvalidateCacheRangePKvj(fp, 0x400);
    LoadToSubObjVRAM(fp, (unsigned int)dest, 0x400);
    ((unsigned char*)entry)[0x21] = total - 1;
}