#include <globaldefs.h>

extern "C" void func_020b0108(void*);

struct Hdr02b0288;
struct Entry02b0288;
struct Entry02b0288* FindChunkById_020b0288(struct Hdr02b0288*, unsigned int);

// USA: func_020b00a4
ARM int GetCellBankBlock_020b00a4(void* file, void** out) {
    struct Entry02b0288* chunk = FindChunkById_020b0288((struct Hdr02b0288*)file, 0x4345424b);
    if (chunk == 0) {
        *out = 0;
        return 0;
    }
    func_020b0108((char*)chunk + 8);
    *out = (char*)chunk + 8;
    return 1;
}
