#include <globaldefs.h>

void EncodeSignFlaggedHalfword_020c39a0(short* out, int value);

struct Brightness0203b540 {
    char pad0[0xc];
    float fieldC;
    char pad1[0x18 - 0xc - 4];
    float field18;
};

// USA: func_0203b540
ARM void SetBrightnessRegisters0203b540(struct Brightness0203b540* obj) {
    EncodeSignFlaggedHalfword_020c39a0((short*)0x400006c, (int)obj->fieldC);
    EncodeSignFlaggedHalfword_020c39a0((short*)0x400106c, (int)obj->field18);
}
