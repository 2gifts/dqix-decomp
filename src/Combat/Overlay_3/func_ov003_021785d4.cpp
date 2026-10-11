#include <globaldefs.h>

#if defined(jpn)
enum { kRegionValueFE4_F60 = 0xf60 };
enum { kRegionValue1000_F7C = 0xf7c };
enum { kRegionValue89C_818 = 0x818 };
enum { kRegionValueFF8_F74 = 0xf74 };
#else
enum { kRegionValueFE4_F60 = 0xfe4 };
enum { kRegionValue1000_F7C = 0x1000 };
enum { kRegionValue89C_818 = 0x89c };
enum { kRegionValueFF8_F74 = 0xff8 };
#endif


short FindMappedMemberId02080468(void* obj, int id);
extern "C" void func_ov003_02178548(void* self);
extern "C" void func_ov003_021767ec(void* self);
extern "C" void func_ov003_021769ec(void* self);
extern "C" void func_ov003_02176ed4(void* self);
extern "C" void func_ov003_02176f94(void* self);

// USA: func_ov003_021785d4  (semantic: AdjustMappedIndexAndRefresh_021785d4)
// JPN: func_ov003_021774b4
extern "C" ARM void func_ov003_021785d4(char* obj) {
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
        void* p89c = *(void**)(obj + kRegionValue89C_818);
        short id = FindMappedMemberId02080468(p89c, 3);
        *(short*)(*(void**)(obj + kRegionValueFF8_F74)) = id;
        func_ov003_02178548(obj);
        func_ov003_021767ec(obj);
        func_ov003_021769ec(obj);
        func_ov003_02176ed4(obj);
        func_ov003_02176f94(obj);
    }

    func_ov003_02178548(obj);
    if (*(short*)(obj + kRegionValue1000_F7C) == *(short*)(*(void**)(obj + kRegionValueFF8_F74))) {
        return;
    }
    func_ov003_021767ec(obj);
    func_ov003_021769ec(obj);
    func_ov003_02176ed4(obj);
    func_ov003_02176f94(obj);
}
