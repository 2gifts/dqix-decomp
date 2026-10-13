#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"
#include "Combat/ScriptElementList.h"

struct Init0208d51c;
extern "C" void _Z19ResetStruct0208d51cP12Init0208d51c(struct Init0208d51c* p);

struct Elem0208d928 {
    short id;
    char* text4;
    char* text8;
    char** texts;
    char* text10;
    char* text14;
};

struct List0208d928;
extern "C" void _Z27AppendCappedElement0208d928P12List0208d928P12Elem0208d928(struct List0208d928* l, struct Elem0208d928* e);

extern const char data_020f1244[];

int StringLength(const char* s);

// USA: func_0208d594
extern "C" ARM int func_0208d594(Script::Parameter* p) {
    struct Elem0208d928 elem;
    unsigned short flags = data_02108fc0.header->flags;
    unsigned int mask;
    unsigned char i;
    unsigned char j;
    int found;
    const char* s;
    unsigned int len;
    Script::Parameter* q;
    char* buf;

    _Z19ResetStruct0208d51cP12Init0208d51c((struct Init0208d51c*)&elem);
    elem.id = (short)p->ToInt();
    if (data_02108fc0.header->selectedCount != 0) {
        const short* cur = data_02108fc0.header->selectedIds;
        short count = data_02108fc0.header->selectedCount;
        found = 0;
        for (short k = 0; k < count; k++) {
            if (elem.id == *cur) {
                found = 1;
            }
            cur++;
        }
        if (!found) {
            return 1;
        }
    }

    s = (p + 1)->ToString();
    if (flags & 1) {
        len = StringLength(s);
        if (len != 0) {
            elem.text4 = (char*)data_02108fc0.allocator->Allocate(len + 1);
            elem.text4[len] = 0;
            sprintf(elem.text4, data_020f1244, s);
        }
    }

    q = p + 2;
    p += 3;
    s = q->ToString();
    if (flags & 2) {
        len = StringLength(s);
        if (len != 0) {
            elem.text8 = (char*)data_02108fc0.allocator->Allocate(len + 1);
            elem.text8[len] = 0;
            sprintf(elem.text8, data_020f1244, s);
        }
    }

    if (flags & 0x3fc) {
        elem.texts = (char**)data_02108fc0.allocator->Allocate(0x20);
        for (j = 0; j < 8; j++) {
            elem.texts[j] = 0;
        }
    }

    mask = 4;
    for (i = 0; i < 8; i++) {
        s = p->ToString();
        p++;
        if (flags & mask) {
            len = StringLength(s);
            if (len != 0) {
                elem.texts[i] = (char*)data_02108fc0.allocator->Allocate(len + 1);
                buf = elem.texts[i];
                buf[len] = 0;
                sprintf(buf, data_020f1244, s);
            }
        }
        mask <<= 1;
    }

    s = p->ToString();
    if (flags & 0x400) {
        len = StringLength(s);
        if (len != 0) {
            elem.text10 = (char*)data_02108fc0.allocator->Allocate(len + 1);
            elem.text10[len] = 0;
            sprintf(elem.text10, data_020f1244, s);
        }
    }

    s = (p + 1)->ToString();
    if (flags & 0x800) {
        len = StringLength(s);
        if (len != 0) {
            elem.text14 = (char*)data_02108fc0.allocator->Allocate(len + 1);
            elem.text14[len] = 0;
            sprintf(elem.text14, data_020f1244, s);
        }
    }

    _Z27AppendCappedElement0208d928P12List0208d928P12Elem0208d928((struct List0208d928*)data_02108fc0.header, &elem);
    return 1;
}
