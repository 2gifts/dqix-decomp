#include <globaldefs.h>

struct Outer020bec80;
void ClearInnerField14c020bec80(struct Outer020bec80* p);
extern "C" void func_020bf1a0(void* entry);

struct Entry020bee20 {
    unsigned char unknown0[0x110];
    int active : 1;
    unsigned char unknown114[0x12c - 0x114];
    void* resource;
    unsigned char unknown130[0x14c - 0x130];
    void** owner;
    int priority;
    unsigned char unknown154[0x174 - 0x154];
};
extern struct Entry020bee20 data_02110a4c[];

// USA: func_020bee20
ARM void* AttachOrRefreshEntry_020bee20(void** self, int index, int value) {
    if (*self != NULL) {
        ClearInnerField14c020bec80((struct Outer020bec80*)self);
    }
    Entry020bee20* entry = &data_02110a4c[index];
    if (entry->resource == NULL) {
        return NULL;
    }
    if (entry->active) {
        if (value < entry->priority) {
            return NULL;
        }
        func_020bf1a0(entry);
    }
    entry->priority = value;
    entry->active = 1;
    entry->owner = self;
    *self = entry;
    return entry;
}
