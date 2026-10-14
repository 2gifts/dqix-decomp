#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c;

struct Holder0209a97c;
struct Pair0209a97c;
void AppendPairToSlot0209a97c(struct Holder0209a97c* h, int slot, struct Pair0209a97c* src);

extern struct Holder0209a97c* data_02109ba8;

struct PairLocal0209a7bc {
    unsigned short a;
    unsigned short b;
};

// USA: func_0209a7bc
ARM int SubmitVariantPairAtSlot0209a7bc(void* arg) {
    int slot = ((Script::Parameter*)((struct Variant02030b0c*)arg))->ToInt();
    struct PairLocal0209a7bc pair;
    pair.a = (unsigned short)((Script::Parameter*)((struct Variant02030b0c*)((char*)arg + 8)))->ToInt();
    pair.b = (unsigned short)((Script::Parameter*)((struct Variant02030b0c*)((char*)arg + 0x10)))->ToInt();
    AppendPairToSlot0209a97c(data_02109ba8, slot, (struct Pair0209a97c*)&pair);
    return 1;
}
