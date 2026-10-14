#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c { int tag; int val; };

struct EntryTable0209bd94;
void SetEntryField0209be28(struct EntryTable0209bd94* table, int key, int* value);

struct Recorder0209bb0 {
    struct EntryTable0209bd94* table;
    unsigned char pad[0x10];
    int active;
    int key;
};
extern struct Recorder0209bb0* data_02109bb0;

// USA: func_0209ba2c
ARM int SetEntryFieldFromVariant0209ba2c(struct Variant02030b0c* variant) {
    if (data_02109bb0->active != 0) {
        int value = ((Script::Parameter*)variant)->ToInt();
        SetEntryField0209be28(data_02109bb0->table, data_02109bb0->key, &value);
    }
    return 1;
}
