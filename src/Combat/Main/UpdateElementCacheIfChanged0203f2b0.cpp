#include <globaldefs.h>

struct Element02040468;
struct List02040468;
struct Element02040468* GetValidElement02040468(struct List02040468* list, int index);

void* GetElementStride0x14_0203f1c8(unsigned char* obj, unsigned int index);

struct StrideEntry0203f2b0 {
    char pad0[0x10];
    unsigned int* field10;
};

struct List_0203f354;
struct SubRecord0203f2b0 {
    char pad0[8];
    unsigned int len;
    void* where;
};
struct Entry0203f2b0 {
    char pad0[4];
    unsigned short count4;
    char pad1[2];
    struct SubRecord0203f2b0* records;
};
struct Entry0203f2b0* GetListElementByIndex(struct List_0203f354* list, unsigned int index);

void CleanInvalidateCacheRange(const void* where, unsigned int len);

struct Obj0203f2b0 {
    struct List02040468* list;
    char pad1[0x28 - 4];
    short field28;
    char pad2[0x30 - 0x2a];
    int field30;
    int field34;
    char pad3[0x44 - 0x38];
    int field44;
    int field48;
};

// USA: func_0203f2b0  (semantic: UpdateElementCacheIfChanged0203f2b0)
extern "C" ARM void func_0203f2b0(struct Obj0203f2b0* self) {
    int index = self->field28;
    if (index < 0) return;
    if (self->field34 == self->field48 && self->field30 == self->field44) return;

    struct Element02040468* element = GetValidElement02040468(self->list, index);
    if (element == 0) return;

    struct StrideEntry0203f2b0* stride = (struct StrideEntry0203f2b0*)GetElementStride0x14_0203f1c8((unsigned char*)element + 0x10, self->field30);
    if (stride == 0) return;

    unsigned int idx2 = stride->field10[self->field34];
    struct Entry0203f2b0* entry = GetListElementByIndex((struct List_0203f354*)((char*)element + 0x10), idx2);
    if (entry == 0 || entry->records == 0) return;

    struct SubRecord0203f2b0* rec = entry->records;
    int i;
    for (i = 0; i < entry->count4; i++, rec++) {
        CleanInvalidateCacheRange(rec->where, rec->len);
    }
}
