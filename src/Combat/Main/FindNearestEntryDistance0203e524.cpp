#include <globaldefs.h>

#include "Combat/EntryGetterTypes.h"

struct EntryList_203dce4 {
    char pad[0xc];
    struct Entry_203dce4* entries[0x20];
};

extern struct Entry_203dce4* GetEntryUnlessFlag0x8000(struct EntryList_203dce4* list, int id);


extern void* GetField0xc02040538(struct S02040538* p);

struct Vec3s32_020c3030 { int x; int y; int z; };

extern "C" extern int Vector3fix_Distance(struct Vec3s32_020c3030* a, struct Vec3s32_020c3030* b);

struct Vec3_020406f8 {
    unsigned int v[3];
};

struct SrcA_020406f8 {
    char pad4[4];
    struct Vec3_020406f8 vec;
};

struct SrcB_020406f8 {
    char pad44[0x44];
    struct Vec3_020406f8 vec;
};

struct Node020406f8 {
    char pad[0x14];
    struct SrcA_020406f8* f14;
    struct SrcB_020406f8* f18;
    struct SrcB_020406f8* f1c;
};

extern void SelectVec3FromSources020406f8(struct Vec3_020406f8* dst, struct Node020406f8* n);

struct OutVec3s16_0203e524 {
    short x;
    short y;
    short z;
};

// USA: func_0203e524
ARM int FindNearestEntryDistance0203e524(struct EntryList_203dce4* list, struct Vec3s32_020c3030* pos, struct OutVec3s16_0203e524* out) {
    int minDist = 0x400000;
    int result = -1;
    int id;
    for (id = 0; id < 0x20; id++) {
        struct Entry_203dce4* entry = GetEntryUnlessFlag0x8000(list, id);
        if (entry == 0) continue;
        if (entry->flags & 0x8000) continue;
        void* field = GetField0xc02040538((struct S02040538*)entry);
        if (field == 0) continue;
        int dist = Vector3fix_Distance(pos, (struct Vec3s32_020c3030*)((char*)field + 0x10));
        if (dist >= minDist) continue;
        minDist = dist;
        {
            struct Vec3_020406f8 tmp;
            result = *(unsigned char*)field;
            SelectVec3FromSources020406f8(&tmp, (struct Node020406f8*)entry);
            out->x = (short)((int)tmp.v[0] >> 4);
            out->y = (short)((int)tmp.v[1] >> 4);
            out->z = (short)((int)tmp.v[2] >> 4);
        }
    }
    return result;
}
