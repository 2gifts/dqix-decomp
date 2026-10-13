#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct AllocationNode021557ac { unsigned int field_0; SafeAllocator allocator; };
struct Entry021557ac { short category; short index; unsigned char total; unsigned char matched; };
struct Table021557ac { Entry021557ac entries[2]; unsigned short total; unsigned short matched; unsigned char side; };
struct Container020dedd0;
struct ObjStruct_021e1474;
struct Save021557ac { unsigned char field_0[0x8c]; unsigned char bits[1]; };
struct Item021557ac { unsigned int field_0; unsigned int field_4; unsigned int field_8; unsigned int flags; };
extern "C" AllocationNode021557ac* func_ov011_021845f8(void*, int);
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
extern "C" int func_ov023_021f6f10(void*);
extern "C" Save021557ac* func_0205ec34();
extern "C" int func_020deb58(Container020dedd0*, int, int, int, int);
extern "C" Item021557ac* func_020dec30(Container020dedd0*, int, int, int, int, int);
int TestBitInByteArray(int, unsigned char*, int);
extern "C" void _Z22ClearElements_021e1518Pv(void*);
extern "C" void _Z32RefreshEntryStatusFlags_021e1474P18ObjStruct_021e1474P17Container020dedd0(ObjStruct_021e1474*, Container020dedd0*);
extern Table021557ac* data_ov004_021707c4;

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
    virtual Container020dedd0* GetContainer();
    virtual ObjStruct_021e1474* GetEntries();
};

// USA: func_ov004_021557ac
extern "C" ARM int func_ov004_021557ac(void* self) {
    AllocationNode021557ac* node = func_ov011_021845f8(self, 0);
    if (!node) return 0;
    Table021557ac* table = (Table021557ac*)node->allocator.Allocate(0x12);
    data_ov004_021707c4 = table;
    if (!table) return 0;
    for (unsigned char index = 0; index < 2; index++) {
        table->entries[index].category = -1;
        table->entries[index].index = -1;
        table->entries[index].total = 0;
        table->entries[index].matched = 0;
    }
    table->total = 0;
    table->matched = 0;
    table->side = 0;
    unsigned char index = 0;
    short category = 8;
    short i;
    short matched = 0;
    long total = 0;
    for (; category <= 9; category++, index++) {
        Node021557ac* source = (Node021557ac*)func_ov023_021f6880(func_ov011_021849c8(self), 0x2d);
        if (source && func_ov023_021f6f10(source) == 0x11) {
            Container020dedd0* container = source->GetContainer();
            Save021557ac* save = func_0205ec34();
            total = func_020deb58(container, 0, -1, (signed char)category, -1);
            matched = 0;
            for (i = 0; i < total; i++) {
                Item021557ac* item = func_020dec30(container, i, 0, -1, (signed char)category, -1);
                if (item) {
                    int id = (unsigned short)((item->flags << 9) >> 21);
                    if (id > 0 && TestBitInByteArray((int)save, save->bits, id + 0x76 + 0xc00)) matched++;
                }
            }
        }
        table = data_ov004_021707c4;
        table->entries[index].category = category;
        table->entries[index].index = -1;
        table->entries[index].total = total;
        table->entries[index].matched = matched;
    }
    Table021557ac* sumTable = data_ov004_021707c4;
    for (unsigned char j = 0; j < 2; j++) {
        Entry021557ac* entry = &sumTable->entries[j];
        sumTable->total += entry->total;
        sumTable->matched += entry->matched;
    }
    Node021557ac* source = (Node021557ac*)func_ov023_021f6880(func_ov011_021849c8(self), 0x2d);
    Node021557ac* destination = (Node021557ac*)func_ov023_021f6880(func_ov011_021849c8(self), 0x39);
    if (source && destination) {
        ObjStruct_021e1474* entries = destination->GetEntries();
        if (entries) {
            _Z22ClearElements_021e1518Pv(entries);
            _Z32RefreshEntryStatusFlags_021e1474P18ObjStruct_021e1474P17Container020dedd0(entries, source->GetContainer());
        }
    }
    return 0;
}
