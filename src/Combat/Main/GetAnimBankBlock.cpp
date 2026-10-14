#include <globaldefs.h>

extern "C" void func_020aff0c(void*);

struct Hdr02b0288;
struct Entry02b0288;
struct Entry02b0288* FindChunkById_020b0288(struct Hdr02b0288*, unsigned int);

// USA: func_020afec4
ARM int GetAnimBankBlock_020afec4(void* file, void** out) {
    struct Entry02b0288* chunk = FindChunkById_020b0288((struct Hdr02b0288*)file, 0x41424e4b);
    if (chunk == 0) {
        *out = 0;
        return 0;
    }
    func_020aff0c((char*)chunk + 8);
    *out = (char*)chunk + 8;
    return 1;
}
