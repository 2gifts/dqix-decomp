#include <globaldefs.h>

struct Source0215d414 {
    unsigned char* data;
    unsigned short ids[3];
    unsigned short field_a;
    unsigned char counts[3];
};

struct Group0215d414 {
    unsigned short id;
    char pad2[0xa - 0x2];
    unsigned char total : 4;
    unsigned char matched : 4;
    char padb[0x18 - 0xb];
};

struct Unique0215d414 {
    unsigned char used;
    char pad1;
    unsigned short id;
    int field4;
};

struct Obj0215d414 {
    char pad0[0x81b0];
    unsigned char total;
    unsigned char counter : 4;
    unsigned char groupCount : 2;
    unsigned char uniqueCount : 2;
    unsigned short field_81b2;
    struct Group0215d414 groups[3];
    struct Unique0215d414 unique[3];
    char pad8214[0x8e18 - 0x8214];
    unsigned char* data;
    char pad8e1c[0x8e49 - 0x8e1c];
    unsigned char mode;
};

// USA: func_ov000_0215d414
extern "C" ARM void func_ov000_0215d414(struct Obj0215d414* obj, struct Source0215d414* src) {
    unsigned char numGroups = 0;
    unsigned char total = 0;
    unsigned char numUnique = 0;
    long i;

    obj->data = src->data;
    for (i = 0; i < 3; i++) {
        struct Group0215d414* group = &obj->groups[numGroups];
        if (src->counts[i] != 0) {
            int found = 0;
            int j;
            for (j = 0; j < numUnique; j++) {
                if (obj->unique[j].id == src->ids[i]) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                struct Unique0215d414* entry = &obj->unique[numUnique++];
                entry->id = src->ids[i];
                entry->used = 1;
                entry->field4 = 0;
            }
            group->id = src->ids[i];
            numGroups++;
            group->total = src->counts[i];
            group->matched = src->counts[i];
            total += group->total;
        }
    }
    obj->uniqueCount = numUnique;
    obj->total = total;
    obj->counter = total;
    obj->groupCount = numGroups;
    obj->field_81b2 = src->field_a;
    obj->mode = obj->data[0x35];
}
