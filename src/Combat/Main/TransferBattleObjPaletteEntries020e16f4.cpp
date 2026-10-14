#include <globaldefs.h>
#include "GameState/GameState.h"
#include "System/Cache.h"

extern int GetWord0x0_0200fb8c(int* obj);
extern "C" extern int LoadToMainObjStandardPalette(int arg0, int arg1, unsigned int arg2);
extern "C" extern int LoadToSubObjStandardPalette(int arg0, int arg1, unsigned int arg2);

struct Inner020e1674 {
    char pad[0x3e];
    unsigned char flag;
};
struct Obj020e1674 {
    char pad[4];
    struct Inner020e1674* ptr;
};
extern void TransferObjPaletteEntry020e1674(struct Obj020e1674* obj, int idx, int sel);

// USA: func_020e16f4
ARM void TransferBattleObjPaletteEntries020e16f4(struct Obj020e1674* self) {
    int field2c;

    if (self->ptr == NULL) return;
    field2c = *(int*)(GetWord0x0_0200fb8c((int*)GameState::GetInstance()) + 0x2c);
    if (field2c == 0) return;
    CleanInvalidateCacheRange((void*)(field2c + 0xc), 0x20);
    if (self->ptr->flag == 0) {
        LoadToMainObjStandardPalette(field2c + 0xc, 0x1c0, 0x20);
    } else {
        LoadToSubObjStandardPalette(field2c + 0xc, 0x1c0, 0x20);
    }
    CleanCacheRange((void*)(field2c + 0xc), 0x20);
    TransferObjPaletteEntry020e1674(self, 9, 0);
    TransferObjPaletteEntry020e1674(self, 0xb, 0);
}
