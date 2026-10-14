#include <globaldefs.h>

struct List02040468;
struct Element0203f370 {
    char pad0[0x10];
};
struct Element0203f370* GetValidElement02040468(struct List02040468* list, int index);

struct StrideEntry0203f370 {
    char pad0[0x10];
    unsigned int* field10;
};
void* GetElementStride0x14(unsigned char* obj, unsigned int index);

struct List_0203f354;
struct Entry0203f370 {
    char pad0[4];
    unsigned short count4;
    char pad1[2];
    void* records;
    int fieldC;
    int field10;
};
struct Entry0203f370* GetListElementByIndex(struct List_0203f354* list, unsigned int index);

int CancelVRAMStagingOperation(int value);
extern "C" int _Z17StageMemoryToVRAM13VRAMSubregionPKvjjbb(int a, int b, int c, int d, unsigned char e, unsigned char f);

struct Obj0203f370 {
    struct List02040468* list;
    char pad1[0x28 - 4];
    short field28;
    char pad2[0x30 - 0x2a];
    int field30;
    int field34;
    char pad3[0x44 - 0x38];
    int field44;
    int field48;
    int field4c;
    char pad4[0x58 - 0x50];
    short field58;
};

// USA: func_0203f370
extern "C" ARM void func_0203f370(struct Obj0203f370* self) {
    if (self->field34 == self->field48 && self->field30 == self->field44) return;

    struct Element0203f370* element = GetValidElement02040468(self->list, self->field28);
    if (element == 0) return;

    struct StrideEntry0203f370* stride = (struct StrideEntry0203f370*)GetElementStride0x14((unsigned char*)element + 0x10, self->field30);
    if (stride == 0) return;

    unsigned int idx2 = stride->field10[self->field34];
    struct Entry0203f370* entry = GetListElementByIndex((struct List_0203f354*)((char*)element + 0x10), idx2);
    if (entry == 0 || entry->records == 0 || entry->count4 == 0) return;

    CancelVRAMStagingOperation(self->field58);
    self->field58 = _Z17StageMemoryToVRAM13VRAMSubregionPKvjjbb(1, entry->field10, self->field4c, entry->fieldC, 0, 0);
    self->field44 = self->field30;
    self->field48 = self->field34;
}
