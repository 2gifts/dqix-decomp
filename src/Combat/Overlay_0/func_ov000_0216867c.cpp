#include <globaldefs.h>

struct TaskEntry0216867c {
    signed char id;
    unsigned char flags;
    short taskA;
    short taskB;

    signed char GetId() const { return id; }
};

struct TaskEntryOwner0216867c {
    char pad[0x77d6];
    TaskEntry0216867c entries[4];
    unsigned char count;
};

// USA: func_ov000_0216867c
extern "C" ARM void func_ov000_0216867c(TaskEntryOwner0216867c* owner, int id) {
    int removed = 0;
    int j = 0;
    for (int i = 0; i < owner->count; i++) {
        if (id == owner->entries[i].GetId()) {
            removed = 1;
        } else {
            owner->entries[j].id = owner->entries[i].id;
            owner->entries[j].flags = owner->entries[i].flags;
            owner->entries[j].taskA = owner->entries[i].taskA;
            owner->entries[j].taskB = owner->entries[i].taskB;
            j++;
        }
    }
    if (removed) {
        owner->count--;
    }
}
