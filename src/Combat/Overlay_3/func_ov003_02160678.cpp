#include <globaldefs.h>

struct Obj2081;
int HasElementByByte0xc4(struct Obj2081* obj, int key);
extern "C" void _Z29GetLookAndTurnOffsets020809c4PviiPsS0_(void* obj, int id, int id2, short* out1, short* out2);
extern "C" void _Z23SetEntryFields_021604f4Pciish(char* obj, int valA, int valB, short index, unsigned char flag);

extern const short data_ov003_0217f400[];
extern const short data_ov003_0217f41a[];

struct Obj02160678 {
    char pad0[0x324];
    struct Obj2081* list;
    char pad328[0x468 - 0x328];
    unsigned char slots[4];
};

// USA: func_ov003_02160678
extern "C" ARM void func_ov003_02160678(struct Obj02160678* self) {
    struct Obj2081* list = self->list;
    if (list == NULL) {
        return;
    }
    long i = 0;
    int found = 0;
    while (data_ov003_0217f41a[i] >= 0) {
        if (HasElementByByte0xc4(list, data_ov003_0217f41a[i])) {
            found = 1;
            break;
        }
        i = (short)(i + 1);
    }
    if (!found) {
        return;
    }
    short id = data_ov003_0217f400[i];
    unsigned char flag = 3;
    for (unsigned char k = 0; k < 4; k++) {
        if (self->slots[k] != 0) {
            short x;
            short y;
            _Z29GetLookAndTurnOffsets020809c4PviiPsS0_(list, data_ov003_0217f41a[i], id, &x, &y);
            _Z23SetEntryFields_021604f4Pciish((char*)self, (short)(x + 0x38), (short)(y - 2), self->slots[k] + 8, flag++);
        }
        id++;
    }
}
