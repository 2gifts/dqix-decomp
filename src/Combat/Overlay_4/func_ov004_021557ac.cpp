#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

#if defined(jpn)
#define func_ov004_021557ac func_ov004_02156d2c
#endif

struct Entry021557ac {
    short kind;
    short subkind;
    unsigned char total;
    unsigned char matched;
};
struct Selection021557ac {
    Entry021557ac entries[2];
    unsigned short total;
    unsigned short matched;
    unsigned char state;
};
extern Selection021557ac* data_ov004_021707c4;
extern "C" void* func_ov011_021845f8(void*, int);
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
extern "C" int func_ov023_021f6f10(void*);
extern "C" void* func_0205ec34();
extern "C" int func_020deb58(void*, int, int, int, int);
extern "C" void* func_020dec30(void*, int, int, int, int, int);
int TestBitInByteArray(int, unsigned char*, int);
struct Record021557ac { unsigned int a, b, c, fieldC; };
extern "C" void func_ov004_021545f0(Entry021557ac*, int, short, short, unsigned char, unsigned char);
void ClearElements_021e1518(void*);
struct ObjStruct_021e1474;
struct Container020dedd0;
void RefreshEntryStatusFlags_021e1474(ObjStruct_021e1474*, Container020dedd0*);

class Node021557ac {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void v56(); virtual void v57();
    virtual Container020dedd0* Container();
    virtual ObjStruct_021e1474* Entries();
};

// USA: func_ov004_021557ac
extern "C" ARM int func_ov004_021557ac(void* self) {
    void* allocator = func_ov011_021845f8(self, 0);
    if (!allocator) return 0;
    Selection021557ac* selection = (Selection021557ac*)((SafeAllocator*)((char*)allocator + 4))->Allocate(0x12);
    data_ov004_021707c4 = selection;
    if (!selection) return 0;
    for (unsigned char i = 0; i < 2; ++i) {
        selection->entries[i].kind = -1;
        selection->entries[i].subkind = -1;
        selection->entries[i].total = 0;
        selection->entries[i].matched = 0;
    }
    selection->total = 0;
    selection->matched = 0;
    selection->state = 0;
    unsigned char index = 0;
    short category;
    Node021557ac* categoryNode;
    long j;
    short matched = 0;
    long total = 0;
    for (category = 8; category <= 9; ++category, ++index) {
        categoryNode = (Node021557ac*)func_ov023_021f6880(func_ov011_021849c8(self), 0x2d);
        if (categoryNode && func_ov023_021f6f10(categoryNode) == 0x11) {
            Container020dedd0* container = categoryNode->Container();
            void* flags = func_0205ec34();
            signed char kind = (signed char)category;
            total = func_020deb58(container, 0, -1, kind, -1);
            matched = 0;
            for (j = 0; j < total; j = (short)(j + 1)) {
                Record021557ac* record = (Record021557ac*)func_020dec30(container, j, 0, -1, kind, -1);
                if (record) {
                    int value = (record->fieldC << 9) >> 21;
                    value = (unsigned short)value;
                    if (value > 0 && TestBitInByteArray((int)flags, (unsigned char*)flags + 0x8c, value + 0xc76)) ++matched;
                }
            }
        }
        Selection021557ac* data = data_ov004_021707c4;
        data->entries[index].kind = category;
        data->entries[index].subkind = -1;
        data->entries[index].total = (unsigned char)total;
        data->entries[index].matched = (unsigned char)matched;
    }
    Selection021557ac* totals = data_ov004_021707c4;
    for (unsigned char i = 0; i < 2; ++i) {
        Entry021557ac& entry = totals->entries[i];
        totals->total += entry.total;
        totals->matched += entry.matched;
    }
    Node021557ac* node = (Node021557ac*)func_ov023_021f6880(func_ov011_021849c8(self), 0x2d);
    Node021557ac* list = (Node021557ac*)func_ov023_021f6880(func_ov011_021849c8(self), 0x39);
    if (node && list) {
        ObjStruct_021e1474* entries = list->Entries();
        if (entries) {
            ClearElements_021e1518(entries);
            RefreshEntryStatusFlags_021e1474(entries, node->Container());
        }
    }
    return 0;
}
