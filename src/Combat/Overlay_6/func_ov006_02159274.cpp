#include <globaldefs.h>

struct AlchemyMenu {
    char unk_0[0x362];
    short categoryCursor_;
    short itemCursor_;
    char unk_366[0x22];
    unsigned char page_;
};

struct LookupByOffset0x362_021591ecStruct;

extern "C" short* _Z29GetArrEntry_0215919c_0215919cPv(void* self);
extern "C" unsigned char* _Z29GetArrEntry_021591c4_021591c4Pv(void* self);
extern "C" unsigned short _Z32LookupByOffset_021591ec_021591ecP34LookupByOffset0x362_021591ecStruct(LookupByOffset0x362_021591ecStruct* self);

// USA: func_ov006_02159274
extern "C" ARM void func_ov006_02159274(AlchemyMenu* self, unsigned char* category, short* item, unsigned char* count) {
    *category = 0;
    *item = -1;
    *count = 0;
    if (self->itemCursor_ < 0)
        return;
    short index = self->categoryCursor_ - 0x5b;
    short* items = _Z29GetArrEntry_0215919c_0215919cPv(self);
    unsigned char* counts = _Z29GetArrEntry_021591c4_021591c4Pv(self);
    unsigned short size = _Z32LookupByOffset_021591ec_021591ecP34LookupByOffset0x362_021591ecStruct((LookupByOffset0x362_021591ecStruct*)self);
    if (items != 0 && counts != 0 && size != 0) {
        unsigned short position = (unsigned short)(self->page_ * 8);
        position += self->itemCursor_ - 0x64;
        *category = index;
        *item = items[position];
        *count = counts[position];
    }
}
