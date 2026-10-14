#include <globaldefs.h>

extern "C" void* func_0205ec34(void);
int TestBitInByteArray_0206dfb0(int unused, unsigned char* arr, int index);

extern int data_ov003_0217f304[];

static inline int GetId02156054(int i) {
    return data_ov003_0217f304[i];
}

struct Ctx02156054 {
    char pad0[0x20];
    int* entries;
};

// USA: func_ov003_02156054
extern "C" ARM void func_ov003_02156054(struct Ctx02156054* self) {
    unsigned char count = 0;
    for (unsigned char i = 1; i < 7; i++) {
        self->entries[count] = i;
        count++;
    }
    unsigned char* ctx = (unsigned char*)func_0205ec34();
    for (unsigned char j = 0; data_ov003_0217f304[j] != 0; j++) {
        int id = GetId02156054(j);
        if (TestBitInByteArray_0206dfb0((int)ctx, ctx + 0x8c, id + 0x113f)) {
            self->entries[count] = id;
            count++;
        }
    }
}
