#include <globaldefs.h>
#include "Combat/SearchEntry.h"
#include "Graphics/Vector.h"
#include "World/Object3D.h"
#include "Resource/GameResources.h"

extern "C" void* func_0202ae18(void);
int CheckField0NonZero(int* obj);
extern "C" int func_0202c508(void* obj);
struct SearchStruct;
struct SearchStruct0202c1a4;
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);
struct FlagsByte0xc1_02034104 {
    unsigned char lowBits2 : 2;
};

// USA: func_02034104
extern "C" ARM Vector3fix func_02034104(void* obj) {
    Object3D* object = (Object3D*)obj;
    void* thing = func_0202ae18();
    func_ov017_0218b5b0();
    if (CheckField0NonZero((int*)thing)) {
        if (func_0202c508(thing)) {
            short field4 = object->unknown_4_;
            if (GetEntryBySignedByteIndex((struct SearchStruct*)thing, field4)) {
                field4 = object->unknown_4_;
                signed char cur = GetSearchStructCurrentArrEntry((struct SearchStruct0202c1a4*)thing);
                if (cur != field4) {
                    FlagsByte0xc1_02034104* flags = (FlagsByte0xc1_02034104*)((char*)obj + 0xc1);
                    if (flags->lowBits2 & 1) {
                        field4 = object->unknown_4_;
                        SearchEntry0202c178* entry = GetEntryBySignedByteIndex((struct SearchStruct*)thing, field4);
                        Vector3fix16 tmp;
#if defined(jpn)
                        tmp.x = entry->x;
                        tmp.y = entry->y;
                        tmp.z = entry->z;
#else
                        Vector3fix16Copy(&tmp, (const Vector3fix16*)&entry->x);
#endif
                        Vector3fix scaled;
                        scaled.x = tmp.x << 7;
                        scaled.y = tmp.y << 7;
                        scaled.z = tmp.z << 7;
                        return scaled;
                    }
                }
            }
        }
    }
    return object->position_;
}
