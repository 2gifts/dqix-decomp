#include <globaldefs.h>

struct Battle020456d0 {
    #if defined(jpn)
    char pad0[0x870];
#else
    char pad0[0x9a0];
#endif
    int state;
    #if defined(jpn)
    char pad9a4[0x17de - 0x874];
#else
    char pad9a4[0x19ae - 0x9a4];
#endif
    signed char counter;
    unsigned char flag;
    #if defined(jpn)
    char pad19b0[0x17fb - 0x17e0];
#else
    char pad19b0[0x19ca - 0x19b0];
#endif
    unsigned char active;
};

// USA: func_020456d0
ARM void StepCounter020456d0(struct Battle020456d0* b) {
    if (b->state == 1 || b->state == 3 || b->state == 2) {
        if (b->active == 0) return;
        b->counter = b->counter + 1;
        b->counter = b->counter & 0x1f;
        b->flag = (b->counter > 0xf) ? 1 : 0;
    } else {
        b->counter = 0;
        b->flag = 0;
    }
}

// JPN: 0x02046340
