#include <globaldefs.h>

#if defined(jpn)
enum { kRegionValueFE4_F60 = 0xf60 };
enum { kRegionValue1000_F7C = 0xf7c };
enum { kRegionValueFF8_F74 = 0xf74 };
#else
enum { kRegionValueFE4_F60 = 0xfe4 };
enum { kRegionValue1000_F7C = 0x1000 };
enum { kRegionValueFF8_F74 = 0xff8 };
#endif


extern "C" void func_ov003_02179ff0(void* obj);
extern "C" void func_ov003_02177dd4(void* obj);
extern "C" void func_ov003_021769ec(void* obj);

// USA: func_ov003_0217a14c
// JPN: func_ov003_02178f7c
extern "C" ARM void func_ov003_0217a14c(void* p) {
    char* obj = (char*)p;
    int flags = *(int*)(obj + kRegionValueFE4_F60);
    int delta = 0;
    if (flags & 0x10) {
        delta = 1;
    } else if (flags & 0x20) {
        delta -= 1;
    }

    *(short*)(obj + kRegionValue1000_F7C + 0x14) = *(short*)(obj + kRegionValue1000_F7C + 0x14) + delta;
    if (*(short*)(obj + kRegionValue1000_F7C + 0x16) <= *(short*)(obj + kRegionValue1000_F7C + 0x14)) {
        *(short*)(obj + kRegionValue1000_F7C + 0x14) = 0;
    }
    if (*(short*)(obj + kRegionValue1000_F7C + 0x14) < 0) {
        *(short*)(obj + kRegionValue1000_F7C + 0x14) = *(short*)(obj + kRegionValue1000_F7C + 0x16) - 1;
    }

    if (delta != 0) {
        func_ov003_02179ff0(obj);
        func_ov003_02177dd4(obj);
        if (*(short*)(obj + kRegionValue1000_F7C + 0xc) == 0x77) {
            func_ov003_021769ec(obj);
        }
    }
    func_ov003_02179ff0(obj);

    if (*(short*)(obj + kRegionValue1000_F7C) == **(short**)(obj + kRegionValueFF8_F74)) return;
    func_ov003_02177dd4(obj);
    if (*(short*)(obj + kRegionValue1000_F7C + 0xc) != 0x77) return;
    func_ov003_021769ec(obj);
}
