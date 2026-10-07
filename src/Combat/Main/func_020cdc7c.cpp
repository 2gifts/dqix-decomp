#include <globaldefs.h>

struct HistoryEntry020cdc7c {
    unsigned short first, second, state, flags;
};
struct HistoryContext020cdc7c {
    unsigned char padding[0x10];
    unsigned short current, count;
    HistoryEntry020cdc7c* entries;
    unsigned short capacity;
};
extern unsigned char data_021117b0;
static inline HistoryEntry020cdc7c* entries020cdc7c() {
    return ((HistoryContext020cdc7c*)&data_021117b0)->entries;
}
static inline unsigned short current020cdc7c() {
    return ((HistoryContext020cdc7c*)&data_021117b0)->current;
}

// Selects recent halfword values independently using the history entry's flag bits.
// The IPC receive interrupt writes the ring entries; full copies retain halfword read order.
// USA: func_020cdc7c
extern "C" ARM void func_020cdc7c(void* result) {
    int i;
    int current;
    HistoryEntry020cdc7c* entry;
    HistoryContext020cdc7c* context = (HistoryContext020cdc7c*)&data_021117b0;
    HistoryEntry020cdc7c* output = (HistoryEntry020cdc7c*)result;
    output->flags = 3;
    current = current020cdc7c();
    if (context->count == 1 || context->capacity == 1) {
        HistoryEntry020cdc7c* entries = entries020cdc7c();
        unsigned short first = ((const volatile HistoryEntry020cdc7c*)entries)[current].first;
        entry = &entries[current];
        const volatile HistoryEntry020cdc7c* values = entry;
        unsigned short second = values->second;
        output->first = first;
        output->second = second;
        unsigned short state = values->state;
        unsigned short flags = values->flags;
        output->state = state;
        output->flags = flags;
        return;
    }
    for (i = 0; i < context->count && i < context->capacity - 1; ++i) {
        int index = current - i;
        if (index < 0) index += context->capacity;
        entry = &context->entries[index];
        if (entry->state == 0) {
            const volatile HistoryEntry020cdc7c* values = entry;
            unsigned short first = values->first;
            unsigned short second = values->second;
            output->first = first;
            output->second = second;
            unsigned short state = values->state;
            unsigned short flags = values->flags;
            output->state = state;
            output->flags = flags;
            return;
        }
        if ((output->flags & 1) && !(entry->flags & 1)) {
            output->first = entry->first;
            if (i != 0) output->flags &= ~1; // The newest entry alone does not clear the search bit.
        }
        if ((output->flags & 2) && !(entry->flags & 2)) {
            output->second = entry->second;
            if (i != 0) output->flags &= ~2;
        }
        if (output->flags == 0) {
            output->state = 1;
            return;
        }
    }
    output->state = 1;
}
