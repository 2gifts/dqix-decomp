#include <globaldefs.h>

extern "C" void* func_0202ae18(void);
int CheckField0NonZero_0202b7d8(int* obj);

struct Entry020e3054 {
    unsigned char f0;
    unsigned char f1;
    unsigned char f2;
    unsigned char f3;
};
Entry020e3054* FindEntryByField1(Entry020e3054* list, int key);

struct Bytes020e303c {
    unsigned char f0;
    unsigned char f1;
    unsigned char f2;
    unsigned char f3;
};
void ClearFourBytes020e303c(Bytes020e303c* s);

struct CheckField0AndGlobalHalfStruct { int field0; };
extern "C" ARM int func_0202c540(CheckField0AndGlobalHalfStruct* obj);

struct SearchStruct0202c1a4 {
    char pad[0x1038];
    signed char arr[16];
};
signed char GetSearchStructCurrentArrEntry(SearchStruct0202c1a4* obj);

void EnqueueEventTag51_021ceae4(unsigned char a, unsigned char b, unsigned char c);

// USA: func_020e33b4  (semantic: ClearEntryAndEnqueue020e33b4)
extern "C" ARM void func_020e33b4(Entry020e3054* list, int key, int compareVal) {
    void* searchObj = func_0202ae18();
    if (!CheckField0NonZero_0202b7d8((int*)searchObj)) return;
    Entry020e3054* entry = FindEntryByField1(list, key);
    if (entry == NULL) return;
    if (entry->f0 != compareVal) return;
    ClearFourBytes020e303c((Bytes020e303c*)entry);
    if (!func_0202c540((CheckField0AndGlobalHalfStruct*)searchObj)) return;
    signed char cur = GetSearchStructCurrentArrEntry((SearchStruct0202c1a4*)searchObj);
    EnqueueEventTag51_021ceae4(0, (unsigned char)key, (unsigned char)cur);
}
