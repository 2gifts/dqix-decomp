#include <globaldefs.h>

struct Rec_021c90f8 { unsigned short a; short b; unsigned short c; unsigned short d; unsigned short e; unsigned char f; };
void CopyRec_021c90f8(Rec_021c90f8* dst, Rec_021c90f8* src);

struct Entry_021d45e0 {
    unsigned char flags;
    unsigned char pad1;
    unsigned short id;
    unsigned char pad2[14];
    Rec_021c90f8 data;
};

extern "C" ARM void func_ov017_021d46a4(Entry_021d45e0* arr, Entry_021d45e0* slot);

// USA: func_ov017_021d45e0
extern "C" ARM void func_ov017_021d45e0(Entry_021d45e0* arr, Rec_021c90f8* rec) {
    Entry_021d45e0* found = NULL;
    Entry_021d45e0* freeSlot = NULL;
    int i = 0;
    for (i = 0; i < 0x30; i++) {
        if (rec->a == arr[i].id) {
            found = &arr[i];
            break;
        }
        if (freeSlot == NULL && arr[i].flags == 0) {
            freeSlot = &arr[i];
        }
    }
    if (found != NULL) {
        CopyRec_021c90f8(&found->data, rec);
        found->id = rec->a;
        found->flags |= 0x2;
        func_ov017_021d46a4(arr, found);
        return;
    }
    if (freeSlot == NULL) {
        return;
    }
    CopyRec_021c90f8(&freeSlot->data, rec);
    freeSlot->id = rec->a;
    freeSlot->flags |= 0x2;
    func_ov017_021d46a4(arr, freeSlot);
}
