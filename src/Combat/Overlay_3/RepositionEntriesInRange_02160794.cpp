#include <globaldefs.h>

#if defined(jpn)
enum { kRegionValue470_298 = 0x298 };
enum { kRegionValue324_20C = 0x20c };
#else
enum { kRegionValue470_298 = 0x470 };
enum { kRegionValue324_20C = 0x324 };
#endif


extern short data_ov003_0217f420[3];

void GetEntryFieldsAt0x602080828(void* obj, int id, short* outX, short* outY);
void SetEntryFieldsAt0x602080854(void* obj, int id, int x, int y);

struct Parent809a0;
ARM void SetEntryPositionById(struct Parent809a0* obj, int id, short x, short y);

// USA: func_ov003_02160794  (semantic: RepositionEntriesInRange_02160794)
// JPN: func_ov003_02160930
extern "C" ARM void func_ov003_02160794(void* self) {
    short* base = *(short**)((char*)self + kRegionValue470_298);
    if (base == 0) {
        return;
    }
    void* list = *(void**)((char*)self + kRegionValue324_20C);
    for (int i = 0; i < 3; i++) {
        short* basePtr = *(short**)((char*)self + kRegionValue470_298);
        short id = data_ov003_0217f420[i];
        short baseVal = *basePtr;
        if (id > baseVal) {
            continue;
        }
        if (baseVal >= id + 4) {
            continue;
        }
        for (int j = 0; j < 4; j++) {
            short x, y;
            GetEntryFieldsAt0x602080828(list, id, &x, &y);
            SetEntryFieldsAt0x602080854(list, id, x, y);
            SetEntryPositionById((struct Parent809a0*)list, id, 0xd0, 0xa);
            id = (short)(id + 1);
        }
    }
}
