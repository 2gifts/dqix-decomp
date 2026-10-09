#include <globaldefs.h>

struct MessageQueue021ed564 {
    unsigned short ids[0x10];
    short targets[0x10];
    short subjects[0x10];
    short serials[0x10];
    unsigned short extras[0x10];
    unsigned char types[0x10];
    int values[0x10];
    char pad_f0[0x60];
    unsigned char count;
};

// USA: func_ov025_021ed564
extern "C" ARM int func_ov025_021ed564(MessageQueue021ed564* queue, int id, int target, int type, int value, int subject) {
    if (type >= 6) return -1;
    if (id == 0) return -1;
    unsigned short* p = queue->ids;
    for (int i = 0; i < queue->count; i++, p++) {
        if (*p == id && target == queue->targets[i]) {
            int v = queue->values[i];
            if (v == value && subject == queue->subjects[i] && type == queue->types[i]) {
                return (short)i;
            }
        }
    }
    return -1;
}
