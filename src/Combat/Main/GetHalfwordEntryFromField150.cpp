#include <globaldefs.h>

struct Field150Table02052df8 {
    char pad[0x488];
    short entries[1];
};
struct Field150Holder02052df8 {
#if defined(jpn)
    char pad[0x144];
#else
    char pad[0x150];
#endif
    struct Field150Table02052df8* table;
};

// USA: func_02052df8
ARM int GetHalfwordEntryFromField150(struct Field150Holder02052df8* obj, int index) {
    struct Field150Table02052df8* table = obj->table;
    return table ? table->entries[index] : -1;
}
