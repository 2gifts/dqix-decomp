#include <globaldefs.h>
#include "Combat/SearchEntry.h"

extern "C" void* func_0202ae18(void);
extern "C" int func_ov017_0218b5b0(void);
int CheckField0NonZero_0202b7d8(int* obj);
struct SearchStruct;
struct SearchStruct0202c1a4;
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);
struct Vec3s02030fc8 {
    signed short x;
    signed short y;
    signed short z;
};
struct Vector3s;
void Vector3fix16Copy(Vector3s*, Vector3s const*);

struct Vec3Int_020341e0 {
    int v[3];
};

struct FlagsByte0xc1_020341e0 {
    unsigned char lowBits2 : 2;
};

// USA: func_020341e0
extern "C" ARM void func_020341e0(Vec3Int_020341e0* dst, void* obj) {
    void* thing = func_0202ae18();
    func_ov017_0218b5b0();
    if (CheckField0NonZero_0202b7d8((int*)thing)) {
        short field4 = *(short*)((char*)obj + 4);
        if (GetEntryBySignedByteIndex_0202c178((struct SearchStruct*)thing, field4)) {
            field4 = *(short*)((char*)obj + 4);
            signed char cur = GetSearchStructCurrentArrEntry((struct SearchStruct0202c1a4*)thing);
            if (cur != field4) {
                FlagsByte0xc1_020341e0* flags = (FlagsByte0xc1_020341e0*)((char*)obj + 0xc1);
                if (flags->lowBits2 & 1) {
                    field4 = *(short*)((char*)obj + 4);
                    void* entry = GetEntryBySignedByteIndex_0202c178((struct SearchStruct*)thing, field4);
                    Vec3s02030fc8 tmp;
                    Vector3fix16Copy((Vector3s*)&tmp, (Vector3s const*)((char*)entry + 8));
                    Vec3Int_020341e0 scaled;
                    scaled.v[0] = tmp.x << 7;
                    scaled.v[1] = tmp.y << 7;
                    scaled.v[2] = tmp.z << 7;
                    *dst = scaled;
                    return;
                }
            }
        }
    }
    *dst = *(Vec3Int_020341e0*)((char*)obj + 0x44);
}
