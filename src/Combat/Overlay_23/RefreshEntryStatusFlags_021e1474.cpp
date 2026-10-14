#include <globaldefs.h>

struct Pair020deb08;
short GetMaxOfHalfwords0And4(struct Pair020deb08* obj);

struct Container020dedd0;
struct Element020de650;
struct Element020de650* FindElementByKey020dedd0(struct Container020dedd0* c, int key);

extern "C" void* func_0205ec34(void);
int TestBitInByteArray_0206dfb0(int unused, unsigned char* arr, int index);

struct FoundElem_021e1474 {
    char pad0[0xc];
    int f0c;
};

struct Entry_021e1474 {
    char pad0[4];
    FoundElem_021e1474* found;
    short key;
    char pad2[0xe - 0xa];
    unsigned char flags;
    char pad3[0x10 - 0xf];
};

struct ObjStruct_021e1474 {
    int f0;
    Entry_021e1474* entries;
    short count;
};

// USA: func_ov023_021e1474
ARM void RefreshEntryStatusFlags_021e1474(ObjStruct_021e1474* obj, struct Container020dedd0* c) {
    if (!c) return;

    GetMaxOfHalfwords0And4((struct Pair020deb08*)c);

    Entry_021e1474* entry;
    Entry_021e1474* base = obj->entries;
    short count = obj->count;
    for (short i = 0; i < count; i++) {
        entry = &base[i];
        FoundElem_021e1474* found = (FoundElem_021e1474*)FindElementByKey020dedd0(c, entry->key);
        entry->found = found;
        if (!found) continue;

        int bits = (unsigned short)((unsigned int)(found->f0c << 9) >> 21);
        if (bits <= 0) continue;

        void* baseData = func_0205ec34();
        int index = bits + 0x76;
        unsigned char* arr = (unsigned char*)baseData + 0x8c;
        if (TestBitInByteArray_0206dfb0((int)baseData, arr, index + 0xc00)) {
            entry->flags |= 0x2;
        }
    }

    obj->f0 = 0;
}
