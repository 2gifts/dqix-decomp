#include <globaldefs.h>

extern "C" void* func_0202ae18(void);
extern "C" int func_ov017_0218b5b0(void);
int CheckField0NonZero(int* obj);
extern "C" int func_0202c508(void* obj);
struct SearchStruct;
void* GetEntryBySignedByteIndex(struct SearchStruct* obj, int value);
struct SearchStruct0202c1a4;
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);
struct Vec3s02030fc8 {
    signed short x;
    signed short y;
    signed short z;
};
extern "C" void _Z16Vector3fix16CopyP8Vector3sPKS_(struct Vec3s02030fc8* dst, struct Vec3s02030fc8* src);

struct Vec3Int_02034104 {
    int v[3];
};

struct FlagsByte0xc1_02034104 {
    unsigned char lowBits2 : 2;
};

// USA: func_02034104
extern "C" ARM void func_02034104(Vec3Int_02034104* dst, void* obj) {
    void* thing = func_0202ae18();
    func_ov017_0218b5b0();
    if (CheckField0NonZero((int*)thing)) {
        if (func_0202c508(thing)) {
            short field4 = *(short*)((char*)obj + 4);
            if (GetEntryBySignedByteIndex((struct SearchStruct*)thing, field4)) {
                field4 = *(short*)((char*)obj + 4);
                signed char cur = GetSearchStructCurrentArrEntry((struct SearchStruct0202c1a4*)thing);
                if (cur != field4) {
                    FlagsByte0xc1_02034104* flags = (FlagsByte0xc1_02034104*)((char*)obj + 0xc1);
                    if (flags->lowBits2 & 1) {
                        field4 = *(short*)((char*)obj + 4);
                        void* entry = GetEntryBySignedByteIndex((struct SearchStruct*)thing, field4);
                        Vec3s02030fc8 tmp;
                        _Z16Vector3fix16CopyP8Vector3sPKS_(&tmp, (struct Vec3s02030fc8*)((char*)entry + 8));
                        Vec3Int_02034104 scaled;
                        scaled.v[0] = tmp.x << 7;
                        scaled.v[1] = tmp.y << 7;
                        scaled.v[2] = tmp.z << 7;
                        *dst = scaled;
                        return;
                    }
                }
            }
        }
    }
    *dst = *(Vec3Int_02034104*)((char*)obj + 0x44);
}