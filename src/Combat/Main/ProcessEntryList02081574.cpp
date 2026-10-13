#include <globaldefs.h>

struct List0207f6ac;
extern void* FindEntryByShortId0207f6ac(struct List0207f6ac* list, int id);
extern "C" void func_0204fa0c(void* obj, short a, short b);

struct Entry02081574 {
    char pad0[0x6];
    short field6;
    short field8;
    char pad1[0x12 - 0xa];
    unsigned char field12;
    unsigned char field13nibble : 4;
    unsigned char field13rest : 4;
    char pad2[0x2a - 0x14];
    unsigned char field2a;
};

#if defined(jpn)
#define data_020e8a54 data_020e8b68
#define ProcessEntryList02081574 func_02081e78
extern "C" ARM void func_02081e78(void* obj, void* ctx, void* list);
enum { kSelectedIdOffset = 0x2a, kOriginOffset = 0x28 };
#else
enum { kSelectedIdOffset = 0x36, kOriginOffset = 0x34 };
#endif

struct EntryGroup02081574 {
    short* ids;
    char unknown4[0x13 - 4];
    unsigned char count;
};

struct List0207f6ac {
    Entry02081574* entries;
    short count;
};

struct ElementController02081574 {
    void* table;
    List0207f6ac entries;
    char unknownC[kOriginOffset - 0xc];
    short originX;
    short selectedId;
};

typedef void (ElementController02081574::*EntryHandler02081574)(void*, Entry02081574*);
extern EntryHandler02081574 data_020e8a54[];

// USA: func_02081574
ARM void ProcessEntryList02081574(void* obj, void* ctx, void* list) {
    ElementController02081574* controller = static_cast<ElementController02081574*>(obj);
    EntryGroup02081574* group = static_cast<EntryGroup02081574*>(list);
    struct Entry02081574* e;
    short id;
    unsigned char i;
    if (list == NULL) {
        return;
    }
    for (i = 0; i < group->count; i++) {
        id = group->ids[i];
        e = (struct Entry02081574*)FindEntryByShortId0207f6ac(&controller->entries, id);
        if (e != NULL) {
            if (controller->selectedId == id) {
                short val = e->field8;
                short diff = (short)(e->field6 - controller->originX);
                switch (e->field13nibble) {
                case 8:
                    val = (short)(val - 1);
                    break;
                case 0xc:
                    val = (short)(val + 1);
                    break;
                }
                func_0204fa0c(ctx, diff, val);
            }
            if (!(e->field2a & 1)) {
                (controller->*data_020e8a54[e->field12])(ctx, e);
            }
        }
    }
}
