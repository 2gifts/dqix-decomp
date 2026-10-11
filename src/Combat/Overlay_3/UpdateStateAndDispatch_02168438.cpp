#include <globaldefs.h>

#if defined(jpn)
enum { kRegionValue4DC_4D8 = 0x4d8 };
#else
enum { kRegionValue4DC_4D8 = 0x4dc };
#endif


struct Struct4ec_02168438 { char pad[kRegionValue4DC_4D8]; void* field4dc; char pad2[0xc]; unsigned char field4ec; char pad3[0xb2]; unsigned char field59f; };

ARM void UpdateEntryAndField4ea_021694b8(void* obj, int id);
extern "C" ARM void func_ov003_021685dc(void* obj);
ARM void MaybeReset0216adbc(void* obj);
extern "C" void func_ov003_02168654(void* obj);
extern "C" void func_ov003_02168b50(void* obj);
ARM void SwitchSetField4ec_02168cc8(void* obj);
extern "C" void func_ov003_02168d3c(void* obj, void* arg, int val);
extern "C" ARM void func_ov003_02169430(void* obj);
extern "C" void func_ov003_0216aa28(void* obj);

// USA: func_ov003_02168438  (semantic: UpdateStateAndDispatch_02168438)
// JPN: func_ov003_021682c0
extern "C" ARM int func_ov003_02168438(struct Struct4ec_02168438* obj, void* arg) {
    obj->field4dc = arg;
    unsigned char state = obj->field4ec;
    if (state != 0 && state != 3 && state != 4) {
        unsigned char flags = obj->field59f;
        if (!(flags & 2) || (flags & 4)) {
            UpdateEntryAndField4ea_021694b8(obj, (int)arg);
        }
    }
    if (obj->field4ec != 0) {
        func_ov003_021685dc(obj);
    }
    unsigned char flags2 = obj->field59f;
    if ((flags2 & 2) && !(flags2 & 4)) {
        MaybeReset0216adbc(obj);
        return obj->field4ec == 6;
    }
    switch (obj->field4ec) {
        case 0: func_ov003_02168654(obj); break;
        case 1: func_ov003_02168b50(obj); break;
        case 2: SwitchSetField4ec_02168cc8(obj); break;
        case 3: func_ov003_02168d3c(obj, arg, 0x3f2); break;
        case 4: func_ov003_02168d3c(obj, arg, 0x3fc); break;
        case 5: func_ov003_02169430(obj); break;
        case 6: return 1;
        default: break;
    }
    func_ov003_0216aa28(obj);
    return 0;
}
