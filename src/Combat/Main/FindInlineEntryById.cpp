#include <globaldefs.h>
#if defined(jpn)
enum { kPadding = 0x312 };
#else
enum { kPadding = 0x316 };
#endif

struct Entry_02028bd0 {
    unsigned short id;
    char unk[kPadding];
};

// USA: func_02028bd0
ARM struct Entry_02028bd0* FindInlineEntryById(struct Entry_02028bd0* base, int key) {
    int i;
    if (key < 0) {
        return 0;
    }
    for (i = 0; i < 4; i++) {
        if (key == base[i].id) {
            return &base[i];
        }
    }
    return 0;
}
