#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif

int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);
extern unsigned short data_02114e30;

struct Repeat02045740 {
    char pad0[IS_JPN ? 0x824 : 0x954];
    int counter954;      // 0x954
    char pad1[0x958 - 0x954 - 4];
    int poll958;         // 0x958
    char pad2[0x994 - 0x958 - 4];
    int out994;          // 0x994
    char pad3[0x9a4 - 0x994 - 4];
    int threshold9a4;    // 0x9a4
};

// JPN: 0x020463b0
// USA: func_02045740
ARM void HandleRepeatInput02045740(struct Repeat02045740* self) {
    int poll = self->poll958;
    self->poll958 = (poll + 1) & 0x1f;
    if (TestFlag0SetAndFlag1Clear(&data_02114e30, 0x40)) {
        int c = self->counter954 - 1;
        self->counter954 = c;
        if (c < 0) {
            self->counter954 = self->threshold9a4 - 1;
        }
        self->out994 = self->counter954;
        self->poll958 = 0;
        return;
    }
    if (!TestFlag0SetAndFlag1Clear(&data_02114e30, 0x80)) {
        return;
    }
    self->counter954 = self->counter954 + 1;
    if (self->counter954 >= self->threshold9a4) {
        self->counter954 = 0;
    }
    self->out994 = self->counter954;
    self->poll958 = 0;
}
