#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
#include <std_library_functions.h>

struct TableItem {
    unsigned short id : 9;
    unsigned short flag9 : 1;
    unsigned short special : 1;
    unsigned short flag11 : 1;
    unsigned short flag12 : 1;
    unsigned short reserved : 3;
};
struct GetTableByteOrFFData {
    unsigned char field_0x0[0xa8];
    TableItem* items;
    unsigned char bytes[0xcc];
};
struct PackedNibbleArray0206e120;
struct PackedNibbleArray0206e2dc;
struct MenuEntry {
    short index;
    unsigned short state : 2;
    unsigned short special : 1;
    unsigned short flag12 : 1;
    unsigned short flag9 : 1;
    unsigned short flag11 : 1;
    unsigned short reserved : 10;
    char name[4];
    int field_0x8;
};
struct MenuLists {
    MenuEntry* regular;
    MenuEntry* special;
    unsigned char field_0x8[0x28];
    SafeAllocator allocator;
    unsigned char field_0x44[4];
    short regularCount;
    short specialCount;
    short field_0x4c;
    short count;
};
int* GetGlobal02109418();
extern "C" void* func_0205ec34();
unsigned char GetTableByteOrFF(GetTableByteOrFFData*, unsigned char);
int GetPackedNibbleField(PackedNibbleArray0206e120*, int);
int GetPackedNibbleFlag0x8(PackedNibbleArray0206e2dc*, int);
int TestBitInByteArrayAt0x84(void*, int);
extern "C" void func_ov004_021660f4();
struct QuestWindowOwners {
#if defined(jpn)
    void** windowLists;
    MenuLists* main;
#else
    MenuLists* main;
    void** windowLists;
#endif
    MenuLists* GetMain() { return main; }
};
extern QuestWindowOwners data_ov004_0217101c;
#if defined(jpn)
extern char data_ov004_02170e54[];
#else
extern char data_ov004_021705a0[];
#endif

// USA: func_ov004_02166198
extern "C" ARM void func_ov004_02166198() {
    MenuEntry* regular;
    MenuEntry* special;
    TableItem* items;
    MenuLists* lists = data_ov004_0217101c.GetMain();
    short count = lists->count;
    GetTableByteOrFFData* table = (GetTableByteOrFFData*)(GetGlobal02109418());
    items = table->items;
    void* save = func_0205ec34();
    short regularCount = 0;
    short specialCount = 0;
    TableItem* firstItem;
    short firstIndex;
    for (firstIndex = 1; firstIndex <= count; firstIndex++) {
        int id = GetTableByteOrFF(table, (unsigned char)(firstIndex));
        firstItem = items;
        int j;
        for (j = 0; j < 0xcc; j++, firstItem++) {
            if (firstItem->id == id) break;
        }
        if (j == 0xcc) continue;
        if (firstItem->id == 0 || firstItem->id >= 0xff) continue;
        int state = GetPackedNibbleField((PackedNibbleArray0206e120*)(save), firstItem->id);
        if (firstItem->special) {
            if (GetPackedNibbleFlag0x8((PackedNibbleArray0206e2dc*)(save), firstItem->id)) specialCount++;
        } else {
            switch (state) {
            case 1:
                if (TestBitInByteArrayAt0x84(table, firstItem->id)) regularCount++;
                break;
            case 2:
            case 3:
                regularCount++;
                break;
#if !defined(jpn)
            case 0:
                if (TestBitInByteArrayAt0x84(table, firstItem->id)) regularCount++;
                break;
#endif
            }
        }
    }
    lists->regularCount = regularCount;
    lists->specialCount = specialCount;
    lists->regular = 0;
    lists->special = 0;
    lists->allocator.Reset();
    if (regularCount) lists->regular = (MenuEntry*)(lists->allocator.Allocate(regularCount * sizeof(MenuEntry)));
    if (specialCount) lists->special = (MenuEntry*)(lists->allocator.Allocate(specialCount * sizeof(MenuEntry)));
    short regularIndex = 0;
    short specialIndex = 0;
    regular = lists->regular;
    special = lists->special;
    for (short i = 1; i <= count; i++) {
        int state;
        int id = GetTableByteOrFF(table, (unsigned char)(i));
        TableItem* item = items;
        int j;
        for (j = 0; j < 0xcc; j++, item++) {
            if (item->id == id) break;
        }
        if (j == 0xcc) continue;
        if (item->id == 0 || item->id >= 0xff) continue;
        state = GetPackedNibbleField((PackedNibbleArray0206e120*)(save), item->id);
        bool include = false;
        if (item->special) {
            if (GetPackedNibbleFlag0x8((PackedNibbleArray0206e2dc*)(save), item->id)) {
                include = true;
                if (state == 1 && TestBitInByteArrayAt0x84(table, item->id)) state = 3;
            }
        } else {
            switch (state) {
            case 1:
                if (TestBitInByteArrayAt0x84(table, item->id)) { include = true; state = 3; }
                break;
            case 2:
            case 3:
                include = true;
                break;
#if !defined(jpn)
            case 0:
                if (TestBitInByteArrayAt0x84(table, item->id)) { include = true; state = 3; }
                break;
#endif
            }
        }
        if (!include) continue;
        short* index = &regularIndex;
        MenuEntry* entry = &regular[regularIndex];
        if (item->special) {
            index = &specialIndex;
            entry = &special[specialIndex];
        }
        entry->index = -1;
        entry->state = 0;
        entry->special = 0;
        entry->flag12 = 0;
        entry->flag9 = 0;
        entry->flag11 = 0;
        entry->field_0x8 = 0;
        memset(entry->name, 0, sizeof(entry->name));
        entry->index = i;
        entry->state = (unsigned short)(state);
        entry->special = item->special;
        entry->flag12 = item->flag12;
        entry->flag9 = item->flag9;
        entry->flag11 = item->flag11;
#if defined(jpn)
        sprintf(entry->name, data_ov004_02170e54, i);
#else
        sprintf(entry->name, data_ov004_021705a0, i);
#endif
        entry->field_0x8 = 0;
        (*index)++;
    }
    func_ov004_021660f4();
}
