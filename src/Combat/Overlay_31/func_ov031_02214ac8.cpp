#include <globaldefs.h>

extern "C" void* func_ov031_022133f8(unsigned int flags);

struct FlagPage_02214ac8 {
    char padding[0x16];
    unsigned short flags;
};

struct Handler_02214ac8 {
    char padding[0xd00];
    FlagPage_02214ac8 page;
};

// USA: func_ov031_02214ac8
extern "C" ARM void* func_ov031_02214ac8(unsigned short id) {
    unsigned int value = id;
    Handler_02214ac8* handler = (Handler_02214ac8*)func_ov031_022133f8(0x10);
    FlagPage_02214ac8* page = &handler->page;
    if (value > 13) value = 13;
    page->flags |= 1U << (value - 1);
    return page;
}
