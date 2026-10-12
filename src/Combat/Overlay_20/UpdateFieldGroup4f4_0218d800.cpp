#include <globaldefs.h>

#if defined(jpn)
enum { kSecondFadeOffset = 0x484 };
#else
enum { kSecondFadeOffset = 0x4f4 };
#endif


#if defined(jpn)
#define UpdateFieldGroup4f4_0218d800 func_ov020_0218e050
#endif

void EncodeSignFlaggedHalfword(short* out, int value);
int GetSignedField020c39c8(volatile unsigned short* p);

struct FieldGroup4f4_0218d800 {
    char pad[kSecondFadeOffset];
    float f4f4;
    int f4f8;
    int f4fc;
};

// USA: func_ov020_0218d800
#if defined(jpn)
extern "C"
#endif
ARM void UpdateFieldGroup4f4_0218d800(struct FieldGroup4f4_0218d800* obj, int a1, int a2) {
    if (a2 == 0) {
        EncodeSignFlaggedHalfword((short*)0x400106c, a1);
        obj->f4f4 = (float)a1;
        obj->f4f8 = a1;
        obj->f4fc = 0;
    } else {
        int v = GetSignedField020c39c8((volatile unsigned short*)0x400106c);
        obj->f4f4 = (float)v;
        obj->f4f8 = a1;
        obj->f4fc = a2;
    }
}
