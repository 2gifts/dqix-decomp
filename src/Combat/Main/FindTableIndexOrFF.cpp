#include <globaldefs.h>

struct FindTableIndexOrFFData { unsigned char pad[0xac]; unsigned char tbl[0xcc]; };

#if defined(jpn)
#define FindTableIndexOrFF func_02098210
extern "C" ARM unsigned char FindTableIndexOrFF(struct FindTableIndexOrFFData* s, unsigned int val);
#endif

// USA: func_020965c0
ARM unsigned char FindTableIndexOrFF(struct FindTableIndexOrFFData *s, unsigned int val) {
    int i;
    if (val < 0xcc) {
        for (i = 0; i < 0xcc; i++) {
            if (s->tbl[i] == val) {
                return i;
            }
        }
    }
    return 0xff;
}
