#include <globaldefs.h>
#if defined(jpn)
enum { kMiddlePadding = 0x184 };
#else
enum { kMiddlePadding = 0x190 };
#endif

int GetByte0x26c(char*);

struct Bytes02033b88;
int SetByte0xbeShiftPrev(struct Bytes02033b88* p, int val);

struct Obj020397cc {
    char pad0[0xc1];
    unsigned char field_c1 : 2;
    char pad1[kMiddlePadding];
    unsigned char byte_252;
    unsigned char byte_253;
};

// USA: func_020397cc
ARM void CancelPendingAction020397cc(struct Obj020397cc* obj, int arg1) {
    if (arg1 && obj->byte_252 && GetByte0x26c((char*)(obj)) == 0 && (obj->field_c1 & 2) == 0) {
        SetByte0xbeShiftPrev((struct Bytes02033b88*)obj, 0);
    }
    obj->byte_253 = 0;
    obj->byte_252 = 0;
}
