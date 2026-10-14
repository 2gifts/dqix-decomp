#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c;

struct Entry0209bd94;
struct EntryTable0209bd94;
struct Entry0209bd94* FindEntryByHalfword0209bd94(struct EntryTable0209bd94* table, int key);

struct RingEntry0209ae9c {
    unsigned char raw[0x4c];
};

struct Inner0209ae9c {
    struct RingEntry0209ae9c entries[6];
    int count;
    int field1cc;
    int field1d0;
};

struct LocalStruct0209ae9c {
    struct Inner0209ae9c* field0;
    struct EntryTable0209bd94* field4;
    int field8;
};
extern struct LocalStruct0209ae9c* data_02109bac;

// USA: func_0209ae9c
ARM int PushHandleIntoRing0209ae9c(struct Variant02030b0c* param0) {
    data_02109bac->field8 = 0;

    int handle = ((Script::Parameter*)param0)->ToInt();
    if (FindEntryByHalfword0209bd94(data_02109bac->field4, handle) == NULL) {
        return 1;
    }

    struct Inner0209ae9c* inner = data_02109bac->field0;
    int newCount = ++inner->count;
    data_02109bac->field0->field1cc = 0;
    data_02109bac->field0->field1d0 = 0;
    *(short*)((char*)data_02109bac->field0 + newCount * 0x4c) = (short)handle;
    data_02109bac->field8 = 1;
    return 1;
}
