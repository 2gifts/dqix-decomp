#include <globaldefs.h>

struct Obj2081;

void ClearElementFlag0x20_02080c20(struct Obj2081* obj, int key);
void SetElementFlag0x20_02080c04(struct Obj2081* obj, int key);

struct Flags394Obj_0215e5f8 {
    char pad[0x394];
    unsigned short field394;
};

// USA: func_ov006_0215e5f8
ARM void ToggleElementFlagsAndByte_0215e5f8(struct Flags394Obj_0215e5f8* obj, struct Obj2081* target, int flag, unsigned char* outByte) {
    if (target == NULL) {
        return;
    }
    if (flag != 0) {
        obj->field394 |= 0x80;
        *outByte = 1;
        ClearElementFlag0x20_02080c20(target, 0xd);
        ClearElementFlag0x20_02080c20(target, 0xe);
        ClearElementFlag0x20_02080c20(target, 0xf);
        ClearElementFlag0x20_02080c20(target, 9);
    } else {
        obj->field394 &= ~0x80;
        *outByte = 0;
        SetElementFlag0x20_02080c04(target, 0xd);
        SetElementFlag0x20_02080c04(target, 0xe);
        SetElementFlag0x20_02080c04(target, 0xf);
        SetElementFlag0x20_02080c04(target, 9);
    }
}
