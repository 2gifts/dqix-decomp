#include <globaldefs.h>
#include "System/ProcessorContext.h"

struct PollEntry0220783c {
    void* socket;
    short requested;
    unsigned short ready;
};
extern "C" int func_ov031_02206fa4(void*);

// USA: func_ov031_0220783c
extern "C" ARM int func_ov031_0220783c(PollEntry0220783c* entries, unsigned int count, long long timeout) {
    bool finite = timeout != -1;
    PollEntry0220783c* entry;
    unsigned int i;
    int ready;
    do {
        entry = entries;
        i = ready = 0;
        if (i < count) {
            do {
                int requested = entry->requested | 0xe0;
                int events = requested & func_ov031_02206fa4(entry->socket);
                entry->ready = events;
                i++;
                entry++;
                if (events) ready++;
            } while (i < count);
        }
        if (ready > 0) break;
        if (finite && timeout <= 0) break;
        SleepCurrentContext(1);
        timeout -= 0x20b;
    } while (true);
    return ready;
}
