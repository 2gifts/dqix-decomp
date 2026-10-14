#include "Combat/TryApplyElemFields.h"
#include <globaldefs.h>
#include "std_library_functions.h"

#if defined(jpn)
#define _Z35NotifyLocalizedResourceLoad020dd040iPc func_020dea34
#endif
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
#if defined(jpn)
extern "C" void func_0205d304(void*, void*, int, int, int, int, int);
#define APPLY_TEXT(s,k,t) TryApplyElemFields0205d5d0(s,k,(int)t,1)
#define DRAW_TEXT(s,t) func_0205d304(s,t,0,1,0,1,0)
enum { textOffset=0x28, textSize=0x800, cursorOffset=0x1fa5, style=6, y=0 };
#else
extern "C" void func_0205d304(void* a, void* b, int c, int d, int e, int f, int g, int h);
#define APPLY_TEXT(s,k,t) TryApplyElemFields0205d5d0(s,k,(int)t,1,0)
#define DRAW_TEXT(s,t) func_0205d304(s,t,0,0,0,1,0,0)
enum { textOffset=0x5c, textSize=0x960, cursorOffset=0x1d6d, style=7, y=0x18 };
#endif

// USA: func_ov000_0217a19c
extern "C" ARM void func_ov000_0217a19c(char* obj, char* table) {
    struct StructA0205d5d0* window;
#if !defined(jpn)
    char text[0x800];
#endif
    char* str = *(char**)(_Z26GetGlobalField0x1c020421a0v() + textOffset);
    memset(str, 0, textSize);
    signed char cursor = *(signed char*)(obj + cursorOffset);
    struct Entry02170cf8* entry = func_ov000_02170cf8(table, *(unsigned short*)(obj + 0x10 + cursor * 2));
    if (entry != 0) {
        _Z35NotifyLocalizedResourceLoad020dd040iPc(entry->textId, str);
    } else {
        str = (char*)_Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310*)(obj + 0xb8), 0x20);
    }
#if !defined(jpn)
    func_02046608(_Z26GetGlobalField0x1c020421a0v(), 0xa, str, text, 0x98, 0, 0);
#endif
    window = (struct StructA0205d5d0*)(obj + 0x188);
#if !defined(jpn)
    str = text;
#endif
    if (_Z23FindElementByC40205d81cP15Struct_0205d81ci((struct Struct_0205d81c*)window, 0x18) != 0) {
        APPLY_TEXT(window, 0x18, str);
        return;
    }
    window->kind = 0x16;
    window->style = style;
    window->x = 5;
    window->y = y;
    window->width = 0xc;
    window->height = 8;
    window->unk_ac = 0xa;
    window->unk_ae = 0xe;
    window->slot = 0x18;
    DRAW_TEXT(window, str);
}
