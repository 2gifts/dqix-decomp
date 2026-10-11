#include <globaldefs.h>

struct Field150Table02052e14 {
    char pad[0x488];
    short entries[1];
};
struct Field150Holder02052e14 {
#if defined(jpn)
    char pad[0x144];
#else
    char pad[0x150];
#endif
    struct Field150Table02052e14* table;
};

// USA: func_02052e14
ARM short* GetField150Ptr0x488(struct Field150Holder02052e14* obj) {
    struct Field150Table02052e14* table = obj->table;
    return table ? &table->entries[0] : NULL;
}
