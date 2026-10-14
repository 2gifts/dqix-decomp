#include <globaldefs.h>
#if defined(jpn)
enum { kRegionec = 0xe8 };
enum { kRegionee = 0xea };
enum { kRegion130 = 0x13c };
enum { kRegion44000 = 0x4f000 };
#else
enum { kRegionec = 0xec };
enum { kRegionee = 0xee };
enum { kRegion130 = 0x130 };
enum { kRegion44000 = 0x44000 };
#endif

struct Obj02173bb0;
void* GetElementIfInRange_02173bb0(Obj02173bb0*, unsigned int);
extern "C" void func_0205ac40(void*, void*);

// USA: func_ov003_02173b4c  (semantic: SetElementFields_02173b4c)
extern "C" ARM void func_ov003_02173b4c(void* obj) {
    unsigned char* o = (unsigned char*)obj;
    unsigned int flag;
    void* elem;
    if (o[kRegionec] == 0) {
        return;
    }
    if (o[kRegionec] == 1) {
        if (o[kRegionee] < 2) {
            return;
        }
    }
#if defined(jpn)
    if (o[0] != 0) {
        elem = GetElementIfInRange_02173bb0((Obj02173bb0*)((char*)obj + kRegion130), 1);
    } else {
        elem = GetElementIfInRange_02173bb0((Obj02173bb0*)((char*)obj + kRegion130), 0);
    }
#else
    flag = 6;
    if (o[0] != 0) {
        flag = 7;
    }
    elem = GetElementIfInRange_02173bb0((Obj02173bb0*)((char*)obj + kRegion130), flag);
#endif
    if (elem == 0) {
        return;
    }
    *(int*)((char*)elem + 0x14) = kRegion44000;
    *(int*)((char*)elem + 0x18) = 0x5f000;
    func_0205ac40((char*)obj + kRegion130, elem);
}
