#include <globaldefs.h>

struct SearchStruct;
struct Obj_021bd3a4 { unsigned char pad0[2]; unsigned char f2; unsigned char f3; unsigned char pad1[0x96]; unsigned char f9a; };

struct F8Bits_021925e0 {
    unsigned int low27 : 27;
    unsigned int high5 : 5;
};

extern "C" char* func_ov017_0218b5b0(void);
extern "C" struct SearchStruct* func_0202ae18(void);
extern "C" int func_0202c540(struct SearchStruct* obj);
int HasFlag3orFlag2And9a_021bd3a4(struct Obj_021bd3a4* obj);

// JPN: func_ov017_021931a8
// USA: func_ov017_021925e0
extern "C" ARM int func_ov017_021925e0(void) {
#if defined(jpn)
 enum {regionalOffset0=0x524, regionalOffset1=0xfd, regionalOffset2=0xf4, regionalOffset3=0xfb, regionalOffset4=0xcb};
#else
 enum {regionalOffset0=0x734, regionalOffset1=0x101, regionalOffset2=0xf8, regionalOffset3=0xff, regionalOffset4=0xcf};
#endif
    char* base = func_ov017_0218b5b0();
    unsigned char* obj = *(unsigned char**)(base + 0x3000 + regionalOffset0);
    if (!func_0202c540(func_0202ae18())) {
        goto ret0;
    }
    if (HasFlag3orFlag2And9a_021bd3a4((struct Obj_021bd3a4*)obj)) {
        if (*(unsigned char*)(obj + regionalOffset1) == 0) {
            goto ret0;
        }
    } else {
        goto ret0;
    }
    if (*(unsigned char*)(obj + regionalOffset1) == 0) {
        goto skip;
    }
    if (((struct F8Bits_021925e0*)(obj + regionalOffset2))->low27 & 4) {
        goto ret0;
    }
skip:
    if (obj[regionalOffset3] != 0) {
        goto ret0;
    }
    if (obj[regionalOffset4] != 2) {
        return 1;
    }
ret0:
    return 0;
}
