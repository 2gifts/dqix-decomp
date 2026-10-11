#include <globaldefs.h>

struct PacketNode022021d4 {
    char padding[8];
    unsigned char kind;
    char padding9[0x28 - 9];
    unsigned int counter;
};
struct Hdr022020e8;
struct Src022020e8;
struct Dst022020e8;
struct Header02201fac;
struct Src02201fac;
extern "C" void* func_ov031_02201e0c(void*, void*);
extern "C" void func_ov031_022020e8(Hdr022020e8*, Src022020e8*, Dst022020e8*);
extern "C" int func_ov031_02201fac(Header02201fac*, Src02201fac*, unsigned int, int);

// USA: func_ov031_022021d4
extern "C" ARM int func_ov031_022021d4(void* header, void* data, int length) {
    PacketNode022021d4* node = (PacketNode022021d4*)func_ov031_02201e0c(header, data);
    if (node != NULL) {
        if (node->kind == 1) {
            func_ov031_022020e8((Hdr022020e8*)header, (Src022020e8*)data, (Dst022020e8*)node);
        } else if ((unsigned char)(node->kind + 0xfd) <= 1) {
            --node->counter;
            func_ov031_022020e8((Hdr022020e8*)header, (Src022020e8*)data, (Dst022020e8*)node);
        } else {
            func_ov031_02201fac((Header02201fac*)header, (Src02201fac*)data, length, 0);
        }
        return 1;
    }
    return 0;
}
