#include <globaldefs.h>

struct Record12 {
    unsigned short f0;
    unsigned short f2;
    int f4;
    unsigned short f8;
    unsigned short fa;
};

void CopyStructFields12_0209a530(struct Record12* dst, struct Record12* src);

struct RecordList0209a4f0 {
    struct Record12* items;
    int count;
};

// USA: func_0209a4f0
ARM void AppendRecord12Capped0209a4f0(struct RecordList0209a4f0* list, struct Record12* src) {
    struct Record12* items;
    int count;
    items = list->items;
    if (items == NULL) return;
    count = list->count;
    if (count >= 0x11f) return;
    list->count = count + 1;
    CopyStructFields12_0209a530(&list->items[count], src);
}
