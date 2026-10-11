#include <globaldefs.h>
#if defined(jpn)
enum { kRegiond8 = 0xd4 };
enum { kRegionef = 0xeb };
enum { kRegioncb = 0xc9 };
enum { kRegioned = 0xe9 };
enum { kRegionca = 0xc8 };
#else
enum { kRegiond8 = 0xd8 };
enum { kRegionef = 0xef };
enum { kRegioncb = 0xcb };
enum { kRegioned = 0xed };
enum { kRegionca = 0xca };
#endif


extern "C" void func_020a620c(void* obj);

// JPN: func_ov003_021725d4
// USA: func_ov003_02173788
ARM void UpdateStateFlags_02173788(unsigned char* obj) {
    func_020a620c(obj + kRegiond8);
    if (obj[kRegionef] != 0) {
        return;
    }
    if (obj[kRegioncb] != 0) {
        obj[kRegioncb] = 0;
        obj[kRegioned] = 3;
        obj[kRegionef] = 0;
    } else if (obj[kRegionca] != 0) {
        obj[kRegioned] = 4;
        obj[kRegionef] = 0;
    }
}
