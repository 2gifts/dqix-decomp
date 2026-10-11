#include <globaldefs.h>

int StringLength(const char* s);
extern "C" void* memset(void* dst, int val, int n);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern char data_ov023_021fe144;

struct Src021f229c { int f0; int f4; int f8; };

struct Obj021f229c {
    int f0;
    int f4;
    int f8;
    char pad0xc[0x44 - 0xc];
#if defined(jpn)
    char buffer[0x118];
#else
    char buffer[0x200];
#endif
};

// JPN: func_ov023_021f1b6c
// USA: func_ov023_021f229c  (semantic: CopyHeaderAndFormatBuf_021f229c)
extern "C" ARM void func_ov023_021f229c(Obj021f229c* obj, Src021f229c* src) {
    if (src == 0) return;
    obj->f0 = src->f0;
    obj->f4 = src->f4;
    obj->f8 = src->f8;
    obj->f4 = (int)obj->buffer;
    int label = src->f4;
    if (label == 0) return;
#if defined(jpn)
    memset(obj->buffer, 0, 0x118);
#else
    memset(obj->buffer, 0, 0x200);
#endif
    sprintf(obj->buffer + StringLength(obj->buffer), &data_ov023_021fe144, label);
}
