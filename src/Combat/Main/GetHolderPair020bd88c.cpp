#include <globaldefs.h>

struct Holder020bd88c {
    char _pad[0x7c];
    int f7c;
    int f80;
    int GetF7c() const { return f7c; }
    int GetF80() const { return f80; }
};
extern struct Holder020bd88c* data_02110370;

struct OutPair020bd88c { int a; int b; };

// USA: func_020bd88c
ARM void GetHolderPair020bd88c(struct OutPair020bd88c* out) {
    struct Holder020bd88c* h = data_02110370;
    int a = h->GetF7c();
    int b = h->GetF80();
    out->a = a;
    out->b = b;
}
