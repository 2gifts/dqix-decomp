#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

#if defined(jpn)
enum { kRegionValue3B4_3CC = 0x3cc };
#else
enum { kRegionValue3B4_3CC = 0x3b4 };
#endif


int IsAnimationActive0209ca2c(void* obj);
void* GetData02153637(void);

extern "C" void func_0205e944(void* data, int flag);
extern "C" void func_ov003_0215c800(void* self);

extern int data_02109bf4;
extern int data_02108760;

struct Self0215e3fc {
    char pad0[kRegionValue3B4_3CC];
    int* f3b4;
    unsigned char f3b8;
    char pad1[0x3bc - 0x3b9];
    unsigned char f3bc;
    char pad2[0x3ec - 0x3bd];
    unsigned char f3ec;
};

// USA: func_ov003_0215e3fc
// JPN: func_ov003_0215f6d4
ARM void ResetAnimStateIfIdle_0215e3fc(struct Self0215e3fc* self) {
    if (IsAnimationActive0209ca2c(&data_02109bf4) != 0) {
        return;
    }
    if (self->f3ec != 0) {
        return;
    }

    func_0205e944(&data_02108760, 0x7f);
    GetData02153637();

    if (self->f3b4 != NULL) {
        int x = (int)BackgroundLoader::GetInstance();
        ((BackgroundLoader*)(x))->MaybeFreeAllocations();
        int i;
#if defined(jpn)
        for (i = 0; i < 4; i++) {
#else
        for (i = 0; i < 3; i++) {
#endif
            ((BackgroundLoader*)(x))->RemoveTask((int)(self->f3b4[i]));
            self->f3b4[i] = -1;
        }
    }

    func_ov003_0215c800(self);
    self->f3bc = 5;
    self->f3b8 = 0;
}
