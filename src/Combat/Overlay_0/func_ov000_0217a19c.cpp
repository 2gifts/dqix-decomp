#include <globaldefs.h>
#include "std_library_functions.h"

struct Container020e0310;
struct Struct_0205d81c;

struct StructA0205d5d0 {
    char unk_0[0xa0];
    short kind;
    short style;
    short x;
    short y;
    short width;
    short height;
    short unk_ac;
    short unk_ae;
    char unk_b0;
    unsigned char slot;
};

struct Entry02170cf8 {
    char unk_0[4];
    unsigned int textId : 12;
    unsigned int unk_4_12 : 20;
};

extern "C" int _Z26GetGlobalField0x1c020421a0v();
extern "C" struct Entry02170cf8* func_ov000_02170cf8(char* obj, int val);
extern "C" void _Z35NotifyLocalizedResourceLoad020dd040iPc(int len, char* buf);
extern "C" int _Z21GetFieldByKey020e0434P17Container020e0310i(struct Container020e0310* c, int key);
extern "C" void func_02046608(int g, int b, char* src, char* dst, int size, int f, int h);
extern "C" void* _Z23FindElementByC40205d81cP15Struct_0205d81ci(struct Struct_0205d81c* s, int key);
extern "C" int _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(struct StructA0205d5d0* a, int b, int c, int d, unsigned char e);
extern "C" void func_0205d304(void* a, void* b, int c, int d, int e, int f, int g, int h);

// USA: func_ov000_0217a19c
extern "C" ARM void func_ov000_0217a19c(char* obj, char* table) {
    struct StructA0205d5d0* window;
    char text[0x800];
    char* str = *(char**)(_Z26GetGlobalField0x1c020421a0v() + 0x5c);
    memset(str, 0, 0x960);
    signed char cursor = *(signed char*)(obj + 0x1d00 + 0x6d);
    struct Entry02170cf8* entry = func_ov000_02170cf8(table, *(unsigned short*)(obj + 0x10 + cursor * 2));
    if (entry != 0) {
        _Z35NotifyLocalizedResourceLoad020dd040iPc(entry->textId, str);
    } else {
        str = (char*)_Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310*)(obj + 0xb8), 0x20);
    }
    func_02046608(_Z26GetGlobalField0x1c020421a0v(), 0xa, str, text, 0x98, 0, 0);
    window = (struct StructA0205d5d0*)(obj + 0x188);
    str = text;
    if (_Z23FindElementByC40205d81cP15Struct_0205d81ci((struct Struct_0205d81c*)window, 0x18) != 0) {
        _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(window, 0x18, (int)str, 1, 0);
        return;
    }
    window->kind = 0x16;
    window->style = 7;
    window->x = 5;
    window->y = 0x18;
    window->width = 0xc;
    window->height = 8;
    window->unk_ac = 0xa;
    window->unk_ae = 0xe;
    window->slot = 0x18;
    func_0205d304(window, str, 0, 0, 0, 1, 0, 0);
}
