#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c;

struct PairEntry0209a93c;
struct PairHolder0209a93c;
void AppendPairCapped0209a93c(struct PairHolder0209a93c* holder, struct PairEntry0209a93c* src);

extern struct PairHolder0209a93c* data_02109ba8;

struct Pair0209a77c {
    unsigned short a;
    unsigned short b;
};

// USA: func_0209a77c
ARM int AppendVariantPair0209a77c(void* arg) {
    struct Pair0209a77c pair;
    pair.a = (unsigned short)((Script::Parameter*)((struct Variant02030b0c*)arg))->ToInt();
    pair.b = (unsigned short)((Script::Parameter*)((struct Variant02030b0c*)((char*)arg + 8)))->ToInt();
    AppendPairCapped0209a93c(data_02109ba8, (struct PairEntry0209a93c*)&pair);
    return 1;
}
