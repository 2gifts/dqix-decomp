#include <globaldefs.h>

struct Field150Table02052e2c {
    char pad[0x488];
    short entries[1];
};
struct Field150Holder02052e2c {
#if defined(jpn)
    char pad[0x144];
#else
    char pad[0x150];
#endif
    struct Field150Table02052e2c* table;
};

// USA: func_02052e2c
ARM short* GetField150Ptr0x488_02052e2c(struct Field150Holder02052e2c* obj) {
    struct Field150Table02052e2c* table = obj->table;
    return table ? &table->entries[0] : NULL;
}
