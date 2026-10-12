#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

#if defined(jpn)
#define func_ov004_02154350 func_ov004_021559f8
#endif

struct Entry02154350 {
    short kind;
    short subkind;
    unsigned char total;
    unsigned char matched;
};
struct Selection02154350 {
    Entry02154350 entries[20];
    unsigned short total;
    unsigned short matched;
    unsigned char state;
};
extern Selection02154350* data_ov004_021707c0;
extern "C" void* func_ov011_021845f8(void*, int);
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
extern "C" void func_ov004_02153b6c(void*, int, int, int, short*, short*);
extern "C" void func_ov004_021545f0(Entry02154350*, int, short, short, unsigned char, unsigned char);
void ClearElements_021e1518(void*);
struct ObjStruct_021e1474;
struct Container020dedd0;
void RefreshEntryStatusFlags_021e1474(ObjStruct_021e1474*, Container020dedd0*);

class Node02154350 {
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

// USA: func_ov004_02154350
extern "C" ARM int func_ov004_02154350(void* self) {
    void* allocator = func_ov011_021845f8(self, 0);
    if (!allocator) return 0;
    Selection02154350* selection = (Selection02154350*)((SafeAllocator*)((char*)allocator + 4))->Allocate(0x7e);
    data_ov004_021707c0 = selection;
    if (!selection) return 0;
    for (unsigned char i = 0; i < 20; ++i) {
        selection->entries[i].kind = -1;
        selection->entries[i].subkind = -1;
        selection->entries[i].total = 0;
        selection->entries[i].matched = 0;
    }
    selection->total = 0;
    selection->matched = 0;
    selection->state = 0;
    unsigned char index = 0;
    short matched = 0;
    short total = 0;
    signed char category;
    for (category = 0; category <= 11; ++category, ++index) {
        func_ov004_02153b6c(self, -1, 0, category, &matched, &total);
        func_ov004_021545f0(data_ov004_021707c0->entries, index, 0, category, (unsigned char)total, (unsigned char)matched);
    }
    for (category = 1; category <= 6; ++category, ++index) {
        func_ov004_02153b6c(self, -1, category, -1, &matched, &total);
        func_ov004_021545f0(data_ov004_021707c0->entries, index, category, -1, (unsigned char)total, (unsigned char)matched);
    }
    func_ov004_02153b6c(self, -1, 7, -1, &matched, &total);
    func_ov004_021545f0(data_ov004_021707c0->entries, index, 7, -1, (unsigned char)total, (unsigned char)matched);
    Selection02154350* totals = data_ov004_021707c0;
    for (unsigned char i = 0; i < 20; ++i) {
        Entry02154350& entry = totals->entries[i];
        totals->total += entry.total;
        totals->matched += entry.matched;
    }
    Node02154350* node = (Node02154350*)func_ov023_021f6880(func_ov011_021849c8(self), 0x2d);
    Node02154350* list = (Node02154350*)func_ov023_021f6880(func_ov011_021849c8(self), 0x39);
    if (node && list) {
        ObjStruct_021e1474* entries = list->Entries();
        if (entries) {
            ClearElements_021e1518(entries);
            RefreshEntryStatusFlags_021e1474(entries, node->Container());
        }
    }
    return 0;
}
