#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"
int GetShortAt0x0020dfbd4(short*);

struct Element020e0310 {
    int a;
    int b;
};

typedef int (*KeyFunc020e0310)(struct Element020e0310 *);

struct Element020e0310 *BinarySearch020e0310(struct Container020e0310 *c, int key, KeyFunc020e0310 fn);

// USA: func_020e0440
ARM int LookupFieldByKey020e0440(struct Container020e0310 *c, int key) {
    struct Element020e0310 *elem;
    if (c == NULL) return 0;
    elem = BinarySearch020e0310(c, key, (KeyFunc020e0310)GetShortAt0x0020dfbd4);
    if (elem != NULL) return elem->b;
    return 0;
}
