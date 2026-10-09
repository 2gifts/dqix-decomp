#include <globaldefs.h>

extern "C" void func_020891cc(void* obj);

struct Stats02048b0c {
    unsigned short w00;
    unsigned short w02;
    char pad02[0x10];
    unsigned int w14;
    char pad18[0xc];
    unsigned char b24;
};

struct Status02048b0c {
    unsigned int f0;
    unsigned short f4;
    unsigned short f6;
    unsigned char f8;
};

struct Owner02048b0c {
    char pad[0x130];
    struct Status02048b0c* status;
    unsigned int pad134;
    struct Stats02048b0c* stats;
};

// USA: func_02048b0c
extern "C" ARM void func_02048b0c(struct Owner02048b0c* self, int flag) {
    self->status->f4 = self->stats->w00;
    self->status->f6 = self->stats->w02;

    int count;
    count = self->stats->b24;
    count = count - 1;
    if (count < 0) {
        count = 0;
    }
    if (flag != 0)
        self->status->f8 = count;
    else
        self->status->f8 = 0;

    self->status->f0 = 0;

    if ((self->stats->w14 & 2) != 0) {
        self->status->f0 |= 2;
    }
    if ((self->stats->w14 & 1) != 0) {
        self->status->f0 = 1;
    }
    if ((self->stats->w14 & 4) != 0) {
        self->status->f0 |= 4;
    }

    func_020891cc(self->stats);
}