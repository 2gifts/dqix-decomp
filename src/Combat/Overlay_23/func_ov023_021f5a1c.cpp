#include <globaldefs.h>

extern "C" void* func_0205ec34(void);
struct Variant02030b0c;
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);

struct PackedNibbleArray0206e2dc;
int GetPackedNibbleFlag0x8(struct PackedNibbleArray0206e2dc* obj, int index);
struct PackedNibbleArray0206e2a0;
void SetPackedNibbleFlag0x8(struct PackedNibbleArray0206e2a0* obj, int index);

void SetOrClearBitInArray(void* unused, unsigned char* array, int bit, int value);

struct Bits13At10c_021f5a1c {
    unsigned short low13 : 13;
    unsigned short hi3 : 3;
};
struct StructWithOffset10c_021f5a1c {
    char pad[0x10c];
    struct Bits13At10c_021f5a1c bits;
};
struct Data021fff08_021f5a1c {
    char pad2[0xc];
    struct StructWithOffset10c_021f5a1c* ptr;
};
extern struct Data021fff08_021f5a1c data_ov023_021fff08;

// USA: func_ov023_021f5a1c
extern "C" ARM int func_ov023_021f5a1c(struct Variant02030b0c* list, int count) {
    void* obj = func_0205ec34();
    for (int i = 0; i < count; i++) {
        int v = _ZNK6Script9Parameter5ToIntEv(list);
        list = (struct Variant02030b0c*)((char*)list + 8);
        int flag = GetPackedNibbleFlag0x8((struct PackedNibbleArray0206e2dc*)obj, v);
        if (flag == 0) {
            SetPackedNibbleFlag0x8((struct PackedNibbleArray0206e2a0*)obj, v);
            data_ov023_021fff08.ptr->bits.low13 |= 0x40;
            SetOrClearBitInArray(obj, (unsigned char*)((char*)obj + 0x8c), 0x797, 1);
        }
    }
    return 1;
}
