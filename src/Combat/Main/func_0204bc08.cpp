#include <globaldefs.h>

void CleanInvalidateCacheRange(const void* p, unsigned int size);
typedef void (*CacheFn0204bc08)(void*, int, unsigned int);
extern CacheFn0204bc08 data_020f01b0[];

struct Obj0204bc08 { char pad0[0xc]; unsigned char field0c; char pad_d[0x1c - 0xc - 1]; unsigned char lo : 4; unsigned char hi : 4; };

// USA: func_0204bc08
extern "C" ARM void func_0204bc08(Obj0204bc08* obj, int idx, unsigned char mode, void* addr, unsigned int size) {
    unsigned char sel = obj->lo;
    CacheFn0204bc08 fn = obj->field0c ? data_020f01b0[sel] : data_020f01b0[sel];
    int shift = 5;
    if (obj->field0c != 0) {
        mode = 0xff;
        shift = 9;
    }
    int val = (idx & 0xf) << shift;
    val += (mode & 0xf) << 1;
    size &= ~1u;
    CleanInvalidateCacheRange(addr, size);
    fn(addr, val, size);
}
