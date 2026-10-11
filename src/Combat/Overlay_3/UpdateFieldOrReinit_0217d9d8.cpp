#include <globaldefs.h>

#if defined(jpn)
enum { kRegionValue998_868 = 0x868 };
enum { kRegionValue9AE_7DE = 0x7de };
enum { kRegionValue9A0_870 = 0x870 };
#else
enum { kRegionValue998_868 = 0x998 };
enum { kRegionValue9AE_7DE = 0x9ae };
enum { kRegionValue9A0_870 = 0x9a0 };
#endif


int GetGlobalField0x1c020421a0();
void SetupField0217dd10(char* obj, int key);
void ReinitController02043204(char* obj);

struct Obj0217d9d8 {
    char pad0[4];
    signed char field4;
    signed char field5;
};

// USA: func_ov003_0217d9d8  (semantic: UpdateFieldOrReinit_0217d9d8)
// JPN: func_ov003_0217c678
extern "C" ARM void func_ov003_0217d9d8(struct Obj0217d9d8* obj) {
    char* g = (char*)GetGlobalField0x1c020421a0();
    signed char b1 = obj->field5;

    if (b1 == 0) {
        SetupField0217dd10((char*)obj, 0x1869f);
        *(int*)(g + kRegionValue998_868) = 1;
        obj->field5 = 1;
        return;
    }

    if (b1 != 1) return;

    *(unsigned char*)(g + 0x1000 + kRegionValue9AE_7DE) = 0;
    if (*(int*)(g + kRegionValue9A0_870) != 0) return;

    ReinitController02043204(g);
    obj->field4 = 4;
    obj->field5 = 0;
}
