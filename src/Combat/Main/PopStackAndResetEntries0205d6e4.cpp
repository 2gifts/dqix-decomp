#include <globaldefs.h>

void ResetElem2081Entry_0204c804(void* obj);

struct Ctx0205d6e4 {
    char pad0[0x98];
    int f98;
    int f9c;
    char pad_a0[0xb0 - 0xa0];
    unsigned char fb0;
    char pad_b1[0xb4 - 0xb1];
    unsigned char fb4;
};

struct Elem0205d6e4 {
    char pad0[0xc2];
    unsigned short fc2;
    unsigned char fc4;
};

// USA: func_0205d6e4  (semantic: PopStackAndResetEntries0205d6e4)
extern "C" ARM void func_0205d6e4(Ctx0205d6e4* self, unsigned int count) {
    unsigned char i;

    if (self->f98 == 0) return;
    if (self->f9c == 0) return;
    if (self->fb4 == 0) return;

    for (i = 0; i < count; i++) {
        int idx1 = self->fb4 - 1;
        void* arr1 = (void*)self->f9c;
        Elem0205d6e4* e1 = (Elem0205d6e4*)((char*)arr1 + idx1 * 0xe0);
        e1->fc2 = 0;
        e1->fc4 = 0;
        ResetElem2081Entry_0204c804(e1);

        int newFb4 = self->fb4 - 1;
        self->fb4 = newFb4;
        int cnt2 = newFb4 & 0xff;
        if (cnt2 == 0) return;

        void* arr2 = (void*)self->f9c;
        int idx2 = cnt2 - 1;
        Elem0205d6e4* e2 = (Elem0205d6e4*)((char*)arr2 + idx2 * 0xe0);
        e2->fc2 = 0;

        int idx3 = self->fb4 - 1;
        void* arr3 = (void*)self->f9c;
        Elem0205d6e4* e3 = (Elem0205d6e4*)((char*)arr3 + idx3 * 0xe0);
        self->fb0 = e3->fc4;
    }
}
