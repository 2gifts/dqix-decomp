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

struct SearchStruct0202c1a4 {
    char pad[0x1038];
    signed char arr[16];
};
signed char GetSearchStructCurrentArrEntry(SearchStruct0202c1a4* obj);

struct Bytes020e303c {
    unsigned char f0;
    unsigned char f1;
    unsigned char f2;
    unsigned char f3;
};
void ClearFourBytes020e303c(Bytes020e303c* s);

// USA: func_020e3468
ARM void ClearEntryIfCurrentArrMatches020e3468(Entry020e3054* list, int key) {
    void* searchObj = func_0202ae18();
    if (!CheckField0NonZero_0202b7d8((int*)searchObj)) return;
    Entry020e3054* entry = FindEntryByField1(list, key);
    if (entry == NULL) return;
    signed char cur = GetSearchStructCurrentArrEntry((SearchStruct0202c1a4*)searchObj);
    if (entry->f0 != cur) return;
    ClearFourBytes020e303c((Bytes020e303c*)entry);
}
